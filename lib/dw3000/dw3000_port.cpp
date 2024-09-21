#include <stdint.h>
#include <esp32-hal-gpio.h> 
#include <SPI.h>    // SPI library
#include "dw3000_port.h"

const SPISettings spi_setting = SPISettings(8000000L, SPI_MSBFIRST, SPI_MODE0);

void DW3000Port::init() {

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

void DW3000Port::io_rst_high() {
    digitalWrite(DW3000_HW_IO_RST, HIGH);
}

void DW3000Port::io_rst_low() {
    digitalWrite(DW3000_HW_IO_RST, LOW);
}

void DW3000Port::io_cs_high() {
    digitalWrite(DW3000_HW_SPI_CS, HIGH);
}

void DW3000Port::io_cs_low() {
    digitalWrite(DW3000_HW_SPI_CS, LOW);
}


void DW3000Port::spi_transceive(uint8_t *ptx, uint16_t tx_len, uint8_t *prx, uint16_t rx_len) {
    io_cs_low();
    SPI.beginTransaction(spi_setting);
    for (int i = 0; i < tx_len; i++) {
        prx[i] = SPI.transfer(ptx[i]);
    }
    SPI.endTransaction();
    io_cs_high();
}

void DW3000Port::delay_ms(uint32_t ms) {
    delay(ms);
}


