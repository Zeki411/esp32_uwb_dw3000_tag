// #include "dw3000.h"

// void test_reg_dev_id(){
//     uint8_t rdata[DW3000_REG_0_DEV_ID_BYTE_LEN] = {0};
//     dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_DEV_ID_OFFSET, rdata, DW3000_REG_0_DEV_ID_BYTE_LEN);
//     Serial.printf("DEV_ID: 0x%08X\n", *(uint32_t *)rdata);
//     Serial.printf("RIDTAG: 0x%04X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_DEV_ID_RIDTAG_BIT_MASK, DW3000_REG_0_DEV_ID_RIDTAG_BIT_OFFSET));
//     Serial.printf("MODEL: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_DEV_ID_MODEL_BIT_MASK, DW3000_REG_0_DEV_ID_MODEL_BIT_OFFSET));
//     Serial.printf("VER: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_DEV_ID_VER_BIT_MASK, DW3000_REG_0_DEV_ID_VER_BIT_OFFSET));
//     Serial.printf("REV: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_DEV_ID_REV_BIT_MASK, DW3000_REG_0_DEV_ID_REV_BIT_OFFSET));
// }

// void test_reg_panadr(){
//     uint8_t rdata[DW3000_REG_0_PANADR_BYTE_LEN] = {0};
//     uint8_t wdata[DW3000_REG_0_PANADR_BYTE_LEN] = {0};
//     Serial.printf("Write PANADR\n");
//     SET_FVAL(*(uint32_t *)wdata, DW3000_REG_0_PANADR_PAN_ID_BIT_MASK, DW3000_REG_0_PANADR_PAN_ID_BIT_OFFSET, 0x1234);
//     SET_FVAL(*(uint32_t *)wdata, DW3000_REG_0_PANADR_SHORT_ADDR_BIT_MASK, DW3000_REG_0_PANADR_SHORT_ADDR_BIT_OFFSET, 0x5678);
//     dw3000.write_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_PANADR_OFFSET, wdata, DW3000_REG_0_PANADR_BYTE_LEN);
//     delay(100);
//     Serial.printf("Read PANADR\n");
//     dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_PANADR_OFFSET, rdata, DW3000_REG_0_PANADR_BYTE_LEN);
//     Serial.printf("PANADR: 0x%08X\n", *(uint32_t *)rdata);
//     Serial.printf("PAN_ID: 0x%04X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_PANADR_PAN_ID_BIT_MASK, DW3000_REG_0_PANADR_PAN_ID_BIT_OFFSET));
//     Serial.printf("SHORT_ADDR: 0x%04X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_PANADR_SHORT_ADDR_BIT_MASK, DW3000_REG_0_PANADR_SHORT_ADDR_BIT_OFFSET));
// }

// void test_reg_sys_cfg(){
//     uint8_t rdata[DW3000_REG_0_SYS_CFG_BYTE_LEN] = {0};
//     dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_SYS_CFG_OFFSET, rdata, DW3000_REG_0_SYS_CFG_BYTE_LEN);
//     Serial.printf("SYS_CFG: 0x%08X\n", *(uint32_t *)rdata);
//     Serial.printf("FFEN: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_FFEN_BIT_MASK, DW3000_REG_0_SYS_CFG_FFEN_BIT_OFFSET));
//     Serial.printf("DIS_FCS_TX: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_DIS_FCS_TX_BIT_MASK, DW3000_REG_0_SYS_CFG_DIS_FCS_TX_BIT_OFFSET));
//     Serial.printf("DIS_FCE: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_DIS_FCE_BIT_MASK, DW3000_REG_0_SYS_CFG_DIS_FCE_BIT_OFFSET));
//     Serial.printf("DIS_DRXB: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_DIS_DRXB_BIT_MASK, DW3000_REG_0_SYS_CFG_DIS_DRXB_BIT_OFFSET));
//     Serial.printf("PHR_MODE: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_PHR_MODE_BIT_MASK, DW3000_REG_0_SYS_CFG_PHR_MODE_BIT_OFFSET));
//     Serial.printf("PHR_6M8: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_PHR_6M8_BIT_MASK, DW3000_REG_0_SYS_CFG_PHR_6M8_BIT_OFFSET));
//     Serial.printf("SPI_CRCEN: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_SPI_CRCEN_BIT_MASK, DW3000_REG_0_SYS_CFG_SPI_CRCEN_BIT_OFFSET));
//     Serial.printf("CIA_IPATOV: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_CIA_IPATOV_BIT_MASK, DW3000_REG_0_SYS_CFG_CIA_IPATOV_BIT_OFFSET));
//     Serial.printf("CIA_STS: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_CIA_STS_BIT_MASK, DW3000_REG_0_SYS_CFG_CIA_STS_BIT_OFFSET));
//     Serial.printf("RXWTOE: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_RXWTOE_BIT_MASK, DW3000_REG_0_SYS_CFG_RXWTOE_BIT_OFFSET));
//     Serial.printf("RXAUTR: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_RXAUTR_BIT_MASK, DW3000_REG_0_SYS_CFG_RXAUTR_BIT_OFFSET));
//     Serial.printf("AUTO_ACK: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_AUTO_ACK_BIT_MASK, DW3000_REG_0_SYS_CFG_AUTO_ACK_BIT_OFFSET));
//     Serial.printf("CP_SPC: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_CP_SPC_BIT_MASK, DW3000_REG_0_SYS_CFG_CP_SPC_BIT_OFFSET));
//     Serial.printf("CP_SDC: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_CP_SDC_BIT_MASK, DW3000_REG_0_SYS_CFG_CP_SDC_BIT_OFFSET));
//     Serial.printf("PDOA_MODE: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_PDOA_MODE_BIT_MASK, DW3000_REG_0_SYS_CFG_PDOA_MODE_BIT_OFFSET));
//     Serial.printf("FAST_AAT: 0x%02X\n", GET_FVAL(*(uint32_t *)rdata, DW3000_REG_0_SYS_CFG_FAST_AAT_BIT_MASK, DW3000_REG_0_SYS_CFG_FAST_AAT_BIT_OFFSET));
// }

// void test_reg_tx_fctrl(){
//     uint8_t rdata[DW3000_REG_0_TX_FCTRL_BYTE_LEN] = {0};
//     dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_TX_FCTRL_OFFSET, rdata, DW3000_REG_0_TX_FCTRL_BYTE_LEN);
//     Serial.printf("TX_FCTRL_P1: 0x%08X\n", *(uint32_t *)(rdata+DW3000_REG_0_TX_FCTRL_P0_BYTE_OFFSET));
//     Serial.printf("TXFLEN: 0x%04X\n", GET_FVAL(*(uint32_t *)(rdata+DW3000_REG_0_TX_FCTRL_P0_BYTE_OFFSET),\
//                                                                 DW3000_REG_0_TX_FCTRL_P0_TXFLEN_BIT_MASK,\
//                                                                 DW3000_REG_0_TX_FCTRL_P0_TXFLEN_BIT_OFFSET));
//     Serial.printf("TXBR: 0x%02X\n", GET_FVAL(*(uint32_t *)(rdata+DW3000_REG_0_TX_FCTRL_P0_BYTE_OFFSET),\
//                                                                 DW3000_REG_0_TX_FCTRL_P0_TXBR_BIT_MASK,\
//                                                                 DW3000_REG_0_TX_FCTRL_P0_TXBR_BIT_OFFSET));
//     Serial.printf("TXPSR: 0x%02X\n", GET_FVAL(*(uint32_t *)(rdata+DW3000_REG_0_TX_FCTRL_P0_BYTE_OFFSET),\
//                                                                 DW3000_REG_0_TX_FCTRL_P0_TXPSR_BIT_MASK,\
//                                                                 DW3000_REG_0_TX_FCTRL_P0_TXPSR_BIT_OFFSET));
//     Serial.printf("TX_BOFFS: 0x%02X\n", GET_FVAL(*(uint32_t *)(rdata+DW3000_REG_0_TX_FCTRL_P0_BYTE_OFFSET),\
//                                                                 DW3000_REG_0_TX_FCTRL_P0_TXB_OFFSET_BIT_MASK,\
//                                                                 DW3000_REG_0_TX_FCTRL_P0_TXB_OFFSET_BIT_OFFSET));

//     Serial.printf("TX_FCTRL_P2: 0x%04X\n", *(uint16_t *)(rdata+DW3000_REG_0_TX_FCTRL_P1_BYTE_OFFSET));
//     Serial.printf("FINE_LEN: 0x%02X\n", GET_FVAL(*(uint16_t *)(rdata+DW3000_REG_0_TX_FCTRL_P1_BYTE_OFFSET),\
//                                                                 DW3000_REG_0_TX_FCTRL_P1_FINE_PLEN_BIT_MASK,\
//                                                                 DW3000_REG_0_TX_FCTRL_P1_FINE_PLEN_BIT_OFFSET));
// }
