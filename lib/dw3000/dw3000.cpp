#include "dw3000.h"



#define DW3000_TXRX_BUF_MAX_LEN 1024



void DW3000::read_full_address(uint8_t base_addr, uint8_t sub_addr, uint8_t *data, uint16_t len) {
    uint8_t tx_buf[DW3000_TXRX_BUF_MAX_LEN] = {0};
    uint8_t rx_buf[DW3000_TXRX_BUF_MAX_LEN] = {0};

    // prepare header
    tx_buf[0] = ( (0x00 | 0x40) | (base_addr << 1) ) | ( ( sub_addr & 0x40 ) >> 7 ) ; // r bit + bit 1 + base address + 1 bit of sub address
    tx_buf[1] = ( sub_addr & 0x7F ) << 2; // 7 bits of sub address + last 2 bits of mode

    for (int i = 0; i < len; i++) {
        tx_buf[i+2] = 0x00; // dummy data
    }

    port->spi_transceive(tx_buf, len+2, rx_buf, len+2);

    for (int i = 0; i < len; i++) {
        data[i] = rx_buf[i+2];
    }
}


void DW3000::write_full_address(uint8_t base_addr, uint8_t sub_addr, uint8_t *data, uint16_t len) {
    uint8_t tx_buf[DW3000_TXRX_BUF_MAX_LEN] = {0};
    uint8_t rx_buf[DW3000_TXRX_BUF_MAX_LEN] = {0};

    // prepare header
    tx_buf[0] = ( 0x80 | 0x40 | (base_addr << 1) ) | ( ( sub_addr & 0x40 ) >> 7 ) ; // w bit + bit 1 + base address + 1 bit of sub address
    tx_buf[1] = ( sub_addr & 0x7F ) << 2; // 7 bits of sub address + last 2 bits of mode

    for (int i = 0; i < len; i++) {
        tx_buf[i+2] = data[i];
    }

    port->spi_transceive(tx_buf, len+2, rx_buf, len+2);
}


dw3000_ret_t DW3000::init() {
    port = new DW3000Port();
    port->init();

    port->delay_ms(100); // wait for the DW3000 to boot up (section 2.5.1.2 of the user manual)

    // Check if the DW3000 is connected
    uint32_t dev_id = 0;
    get_dev_id(&dev_id);
    if (dev_id != DW3000_DEV_ID_VAL) {
        return DW3000_RET_NOT_OK;
    }

    return DW3000_RET_OK;
}

void DW3000::hard_reset() {
    port->io_rst_low();
    port->delay_ms(10);
    port->io_rst_high();
    port->delay_ms(10);
}


void DW3000::get_dev_id(uint32_t *dev_id) {
    uint8_t rx_buf[4] = {0};
    read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_DEV_ID_OFFSET,\
                        rx_buf, DW3000_REG_0_DEV_ID_LEN);
    *dev_id = (rx_buf[3] << 24) | (rx_buf[2] << 16) | (rx_buf[1] << 8) | rx_buf[0];
}

// void DW3000::get_eui(uint8_t *eui) {
//     read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_EUI_OFFSET, eui, 8);
// }

void DW3000::set_network_id(uint8_t *pan_id, uint8_t *short_addr) {
    uint8_t tx_buf[4] = {0};
    tx_buf[0] = pan_id[0];
    tx_buf[1] = pan_id[1];
    tx_buf[2] = short_addr[0];
    tx_buf[3] = short_addr[1];
    write_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_PANADR_OFFSET,\
                        tx_buf, DW3000_REG_0_PANADR_LEN);
}

void DW3000::get_network_id(uint8_t *pan_id, uint8_t *short_addr){
    uint8_t rx_buf[4] = {0};
    read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_PANADR_OFFSET,\
                        rx_buf, DW3000_REG_0_PANADR_LEN);
    pan_id[0] = rx_buf[0];
    pan_id[1] = rx_buf[1];
    short_addr[0] = rx_buf[2];
    short_addr[1] = rx_buf[3];
}


// void DW3000::set_eui(uint8_t *eui) {
//     //TODO: implement
// }

// void DW3000::write_sys_cfg(){

// }






