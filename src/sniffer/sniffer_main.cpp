#include "sniffer_main.h"
#include <esp_log.h>
#include <Arduino.h>
#include "dw3000.h"
#include "DW3000Mac.h"
#include "DW3000Ranging.h"

#define SNIFFER_LOG_TAG "SNIFFER"
#define SNIFFER_LOG_LEVEL ESP_LOG_INFO

// connection pins
const uint8_t PIN_RST = 27; // reset pin
const uint8_t PIN_IRQ = 34; // irq pin
const uint8_t PIN_SS = 4;   // spi select pin

/* Default communication configuration. We use default non-STS DW mode. */
static dwt_config_t config = {
    5,                /* Channel number. */
    DWT_PLEN_128,     /* Preamble length. Used in TX only. */
    DWT_PAC8,         /* Preamble acquisition chunk size. Used in RX only. */
    9,                /* TX preamble code. Used in TX only. */
    9,                /* RX preamble code. Used in RX only. */
    1,                /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
    DWT_BR_6M8,       /* Data rate. */
    DWT_PHRMODE_STD,  /* PHY header mode. */
    DWT_PHRRATE_STD,  /* PHY header rate. */
    (129 + 8 - 8),    /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
    DWT_STS_MODE_OFF, /* STS disabled */
    DWT_STS_LEN_64,   /* STS length see allowed values in Enum dwt_sts_lengths_e */
    DWT_PDOA_M0       /* PDOA mode off */
};

/* Buffer to store received frame. See NOTE 1 below. */
static uint8_t sniffer_rx_buffer[FRAME_LEN_MAX];

/* Hold copy of status register state here for reference so that it can be examined at a debug breakpoint. */
uint32_t sniffer_status_reg;
/* Hold copy of frame length of frame received (if good) so that it can be examined at a debug breakpoint. */
uint16_t sniffer_rx_frame_len;

static int16_t detect_message_type(uint8_t datas[]);

void sniffer_main(void) {

    esp_log_level_set(SNIFFER_LOG_TAG, SNIFFER_LOG_LEVEL);

    /* Configure SPI rate, DW3000 supports up to 38 MHz */
    /* Reset DW IC */
    spiBegin(PIN_IRQ, PIN_RST);
    spiSelect(PIN_SS);

    while (!dwt_checkidlerc()) // Need to make sure DW IC is in IDLE_RC before proceeding
    {
        ESP_LOGE(SNIFFER_LOG_TAG, "IDLE FAILED");
        while (1) ;
    }
    
    dwt_softreset();
    delay(200);
    
    if (dwt_initialise(DWT_DW_INIT) == DWT_ERROR)
    {
        ESP_LOGE(SNIFFER_LOG_TAG, "INIT FAILED");
        while (1) ;
    }
    
    // Enabling LEDs here for debug so that for each TX the D1 LED will flash on DW3000 red eval-shield boards.
    dwt_setleds(DWT_LEDS_ENABLE | DWT_LEDS_INIT_BLINK);
    
    // Configure DW IC. See NOTE 5 below.
    if (dwt_configure(&config)) // if the dwt_configure returns DWT_ERROR either the PLL or RX calibration has failed the host should reset the device
    {
        ESP_LOGE(SNIFFER_LOG_TAG, "CONFIG FAILED");
        while (1) ;
    }

    ESP_LOGI(SNIFFER_LOG_TAG, "Sniffer Initialization complete");

    while(1) {

        memset(sniffer_rx_buffer, 0, sizeof(sniffer_rx_buffer));

        /* Activate reception immediately. See NOTE 2 below. */
        dwt_rxenable(DWT_START_RX_IMMEDIATE);

        /* Poll until a frame is properly received or an error/timeout occurs. See NOTE 3 below.
         * STATUS register is 5 bytes long but, as the event we are looking at is in the first byte of the register, we can use this simplest API
         * function to access it. */
        while (!((sniffer_status_reg = dwt_read32bitreg(SYS_STATUS_ID)) & (SYS_STATUS_RXFCG_BIT_MASK | SYS_STATUS_ALL_RX_ERR)))
        {};
        if (sniffer_status_reg & SYS_STATUS_RXFCG_BIT_MASK)
        {
            /* A frame has been received, copy it to our local buffer. */
            sniffer_rx_frame_len = dwt_read32bitreg(RX_FINFO_ID) & RX_FINFO_RXFLEN_BIT_MASK;
            if (sniffer_rx_frame_len <= FRAME_LEN_MAX) {
                dwt_readrxdata(sniffer_rx_buffer, sniffer_rx_frame_len - FCS_LEN, 0); /* No need to read the FCS/CRC. */
            }

            /* Clear good RX frame event in the DW IC status register. */
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_RXFCG_BIT_MASK);

            /* Detect the message type */
            int16_t messageType = detect_message_type(sniffer_rx_buffer);
            if(messageType == TWR_BLINK) {
                ESP_LOGI(SNIFFER_LOG_TAG, "Blink message detected");
            }
            else if(messageType == TWR_POLL) {
                ESP_LOGI(SNIFFER_LOG_TAG, "Poll message detected");
            }
            else if(messageType == TWR_POLL_ACK) {
                ESP_LOGI(SNIFFER_LOG_TAG, "Poll Ack message detected");
            }
            else if(messageType == TWR_RANGE) {
                ESP_LOGI(SNIFFER_LOG_TAG, "Range message detected");
            }
            else if(messageType == TWR_RANGE_REPORT) {
                ESP_LOGI(SNIFFER_LOG_TAG, "Range Report message detected");
            }
            else if(messageType == TWR_RANGE_FAILED) {
                ESP_LOGI(SNIFFER_LOG_TAG, "Range Failed message detected");
            }
            else if(messageType == TWR_RANGING_INIT) {
                ESP_LOGI(SNIFFER_LOG_TAG, "Ranging Init message detected");
            }
            else {
                ESP_LOGI(SNIFFER_LOG_TAG, "Unknown message detected");
            }



        }
        else
        {
            /* Clear RX error events in the DW IC status register. */
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_ERR);
        }
    }
}


static int16_t detect_message_type(uint8_t datas[]) {
	if(datas[0] == FC_1_BLINK) {
		return TWR_BLINK;
	}
	else if(datas[0] == FC_1 && datas[1] == FC_2) {
		//we have a long MAC frame message (ranging init)
		return datas[LONG_MAC_LEN];
	}
	else if(datas[0] == FC_1 && datas[1] == FC_2_SHORT) {
		//we have a short mac frame message (poll, range, range report, etc..)
		return datas[SHORT_MAC_LEN];
	}
}