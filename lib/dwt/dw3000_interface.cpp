#include <stdint.h>
#include <esp32-hal-gpio.h> 
#include <SPI.h>    // SPI library
#include "dw3000.h"
#include "dw3000_interface.h"

#define DW3000_HW_SPI_MISO 19
#define DW3000_HW_SPI_MOSI 23
#define DW3000_HW_SPI_SCK 18
#define DW3000_HW_SPI_CS 4

#define DW3000_HW_IO_IRQ 34
#define DW3000_HW_IO_RST 27

#define DW3000_HW_SPI_FAST_FREQ 8000000
#define DW3000_HW_SPI_SLOW_FREQ 1000000

static int dw3000_readfromspi(uint16_t headerLength, uint8_t *headerBuffer, uint16_t readlength, uint8_t *readBuffer);
static int dw3000_writetospi(uint16_t headerLength, const uint8_t *headerBuffer, uint16_t bodyLength, const uint8_t *bodyBuffer);
static int dw3000_writetospiwithcrc(uint16_t headerLength, const uint8_t *headerBuffer, uint16_t bodyLength, const uint8_t *bodyBuffer, uint8_t crc8);
static void dw3000_setslowrate(void);
static void dw3000_setfastrate(void);

struct dwt_spi_s dw3000_spi = {
    .readfromspi = dw3000_readfromspi,
    .writetospi = dw3000_writetospi,
    .writetospiwithcrc = dw3000_writetospiwithcrc,
    .setslowrate = dw3000_setslowrate,
    .setfastrate = dw3000_setfastrate
};

struct dwchip_s dw3000_hw = {
    .SPI = &dw3000_spi
};

struct dwlibutils_s dwlibutils = {
    .delayms = dwlib_sleepms
};

SPISettings dw3000_current_spi_settings = SPISettings(DW3000_HW_SPI_FAST_FREQ, SPI_MSBFIRST, SPI_MODE0);

void dw3000_interface_init(void) {
    // Initialize SPI
    SPI.begin(
        DW3000_HW_SPI_SCK,\
        DW3000_HW_SPI_MISO,\
        DW3000_HW_SPI_MOSI,\
        DW3000_HW_SPI_CS\
    );


    pinMode(DW3000_HW_IO_IRQ, INPUT);
    pinMode(DW3000_HW_IO_RST, OUTPUT);
    pinMode(DW3000_HW_SPI_CS, OUTPUT);

    digitalWrite(DW3000_HW_IO_RST, HIGH);
    digitalWrite(DW3000_HW_SPI_CS, HIGH);
}

int dw3000_readfromspi(uint16_t headerLength, uint8_t *headerBuffer, uint16_t readlength, uint8_t *readBuffer) {
    //TODO: Check error handling
    digitalWrite(DW3000_HW_SPI_CS, LOW);
    SPI.beginTransaction(dw3000_current_spi_settings);
    for (int i = 0; i < headerLength; i++) {
        SPI.transfer(headerBuffer[i]);
    }
    for (int i = 0; i < readlength; i++) {
        readBuffer[i] = SPI.transfer(0x00);
    }
    SPI.endTransaction();
    digitalWrite(DW3000_HW_SPI_CS, HIGH);

    return DWT_SUCCESS;
}

int dw3000_writetospi(uint16_t headerLength, const uint8_t *headerBuffer, uint16_t bodyLength, const uint8_t *bodyBuffer) {
    //TODO: Check error handling
    digitalWrite(DW3000_HW_SPI_CS, LOW);
    SPI.beginTransaction(dw3000_current_spi_settings);
    for (int i = 0; i < headerLength; i++) {
        SPI.transfer(headerBuffer[i]);
    }
    for (int i = 0; i < bodyLength; i++) {
        SPI.transfer(bodyBuffer[i]);
    }
    SPI.endTransaction();
    digitalWrite(DW3000_HW_SPI_CS, HIGH);

    return DWT_SUCCESS;
}

int dw3000_writetospiwithcrc(uint16_t headerLength, const uint8_t *headerBuffer, uint16_t bodyLength, const uint8_t *bodyBuffer, uint8_t crc8) {
    digitalWrite(DW3000_HW_SPI_CS, LOW);
    SPI.beginTransaction(dw3000_current_spi_settings);
    for (int i = 0; i < headerLength; i++) {
        SPI.transfer(headerBuffer[i]);
    }
    for (int i = 0; i < bodyLength; i++) {
        SPI.transfer(bodyBuffer[i]);
    }
    SPI.transfer(crc8);
    SPI.endTransaction();
    digitalWrite(DW3000_HW_SPI_CS, HIGH);

    return DWT_SUCCESS;
}

void dw3000_setslowrate(void) {
    dw3000_current_spi_settings = SPISettings(DW3000_HW_SPI_SLOW_FREQ, SPI_MSBFIRST, SPI_MODE0);
}

void dw3000_setfastrate(void) {
    dw3000_current_spi_settings = SPISettings(DW3000_HW_SPI_FAST_FREQ, SPI_MSBFIRST, SPI_MODE0);
}

void dwlib_sleepms(uint32_t time_ms) {
    delay(time_ms);
}



