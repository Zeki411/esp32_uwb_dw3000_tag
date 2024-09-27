#include "dw3000.h"
#include "dw3000_regs.h"
#include "dw3000_interface.h"

static int dwt_read_full_addr(uint8_t base_addr, uint8_t sub_addr, uint8_t *data, uint16_t len)
{
    uint8_t header[2];
    uint8_t dummy_data[len] = {0};

    header[0] = ( (0x00 | 0x40) | (base_addr << 1) ) | ( ( sub_addr & 0x40 ) >> 7 ) ; // r bit + bit 1 + base address + 1 bit of sub address
    header[1] = sub_addr & 0x3F; // 6 bits of sub address

    dw3000_hw.SPI->readfromspi(2, header, len, data);

    return DWT_SUCCESS;
}

static int dwt_write_full_addr(uint8_t base_addr, uint8_t sub_addr, uint8_t *data, uint16_t len)
{
    uint8_t header[2];

    header[0] = (0x00 | 0x40) | (base_addr << 1) | ( ( sub_addr & 0x40 ) >> 7 ) ; // r bit + bit 1 + base address + 1 bit of sub address
    header[1] = sub_addr & 0x3F; // 6 bits of sub address

    dw3000_hw.SPI->writetospi(2, header, len, data);

    return DWT_SUCCESS;
}


int32_t dwt_apiversion(void)
{
    return DW3000_DRIVER_VERSION;
}

uint32_t dwt_readdevid(void)
{
    uint8_t data[4];

    dwt_read_full_addr(DW3000_REG_0_ADDR, DW3000_REG_0_DEV_ID_OFFSET, data, DW3000_REG_0_DEV_ID_BYTE_LEN);

    return ( (uint32_t)data[0] << 24 ) | ( (uint32_t)data[1] << 16 ) | ( (uint32_t)data[2] << 8 ) | (uint32_t)data[3];
}

void dwt_softreset(int reset_semaphore)
{
    //clear any AON configurations (this will leave the device at FOSC/4, thus we need low SPI rate)
    dwt_clearaonconfig();

    //make sure the new AON array config has been set
    dwlibutils.delayms(1);

    //need to make sure clock is not PLL as the PLL will be switched off as part of reset
    //TODO:
}


void dwt_clearaonconfig(void)
{
    uint8_t aon_dig_cfg_data[DW3000_REG_10_AON_DIG_CFG_BYTE_LEN] = {0x00};
    uint8_t aon_cfg_data[DW3000_REG_10_AON_CFG_BYTE_LEN] = {0x00};
    uint8_t aon_ctrl_data[DW3000_REG_10_AON_CTRL_BYTE_LEN] = {0x00};

    // Clear any AON auto download bits (as reset will trigger AON download)
    dwt_write_full_addr(DW3000_REG_10_ADDR, DW3000_REG_10_AON_DIG_CFG_OFFSET, aon_dig_cfg_data, DW3000_REG_10_AON_DIG_CFG_BYTE_LEN);
    // Clear the wake-up configuration
    dwt_write_full_addr(DW3000_REG_10_ADDR, DW3000_REG_10_AON_CFG_OFFSET, aon_cfg_data, DW3000_REG_10_AON_CFG_BYTE_LEN);
    // Clear the AON control register
    dwt_write_full_addr(DW3000_REG_10_ADDR, DW3000_REG_10_AON_CTRL_OFFSET, aon_ctrl_data, DW3000_REG_10_AON_CTRL_BYTE_LEN);
    // Set Save Bit in AON control register
    SET_FVAL(*(uint8_t *)aon_ctrl_data, DW3000_REG_10_AON_CTRL_SAVE_BIT_MASK, DW3000_REG_10_AON_CTRL_SAVE_BIT_OFFSET, 1);
    dwt_write_full_addr(DW3000_REG_10_ADDR, DW3000_REG_10_AON_CTRL_OFFSET, aon_ctrl_data, DW3000_REG_10_AON_CTRL_BYTE_LEN);
}



















