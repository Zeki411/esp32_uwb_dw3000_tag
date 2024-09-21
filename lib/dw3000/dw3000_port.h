#ifndef __DW3000_PORT_H__
#define __DW3000_PORT_H__

#include <stdint.h>

#define DW3000_HW_SPI_MISO 19
#define DW3000_HW_SPI_MOSI 23
#define DW3000_HW_SPI_SCK 18
#define DW3000_HW_SPI_CS 4

#define DW3000_HW_IO_IRQ 34
#define DW3000_HW_IO_RST 27


class DW3000Port {
public:
    void init();
    void io_rst_high();
    void io_rst_low();
    void io_cs_high();
    void io_cs_low();
    void spi_transceive(uint8_t *ptx, uint16_t tx_len, uint8_t *prx, uint16_t rx_len);

    void delay_ms(uint32_t ms);
};



#endif // __DW3000_CFG_H__
