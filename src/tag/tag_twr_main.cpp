#include "tag_main.h"
#include "DW3000Ranging.h"

#define TAG_TWR_LOG_TAG "TAG"
#define TAG_TWR_LOG_LEVEL ESP_LOG_INFO

#define TAG_ADDRESS_STR "7D:01:22:EA:82:60:3B:9C"

// connection pins
const uint8_t PIN_RST = 27; // reset pin
const uint8_t PIN_IRQ = 34; // irq pin
const uint8_t PIN_SS = 4; // spi select pin

/* Default communication configuration. We use default non-STS DW mode. */
static dwt_config_t config = {
        5,               /* Channel number. */
        DWT_PLEN_128,    /* Preamble length. Used in TX only. */
        DWT_PAC8,        /* Preamble acquisition chunk size. Used in RX only. */
        9,               /* TX preamble code. Used in TX only. */
        9,               /* RX preamble code. Used in RX only. */
        1,               /* 0 to use standard 8 symbol SFD, 1 to use non-standard 8 symbol, 2 for non-standard 16 symbol SFD and 3 for 4z 8 symbol SDF type */
        DWT_BR_6M8,      /* Data rate. */
        DWT_PHRMODE_STD, /* PHY header mode. */
        DWT_PHRRATE_STD, /* PHY header rate. */
        (129 + 8 - 8),   /* SFD timeout (preamble length + 1 + SFD length - PAC size). Used in RX only. */
        DWT_STS_MODE_OFF, /* STS disabled */
        DWT_STS_LEN_64,/* STS length see allowed values in Enum dwt_sts_lengths_e */
        DWT_PDOA_M0      /* PDOA mode off */
};


void tag_twr_main(void){

    esp_log_level_set(TAG_TWR_LOG_TAG, TAG_TWR_LOG_LEVEL);

    dw3000ranging.initCommunication(PIN_RST, PIN_SS, PIN_IRQ);
    // dw3000ranging.startAsTag((char *)TAG_ADDRESS_STR, config, true);

    ESP_LOGI(TAG_TWR_LOG_TAG, "Tag TWR Initialization complete");


    while(1) {
        delay(1000);
    }
}