#ifndef __DW3000_REGS_H__
#define __DW3000_REGS_H__

/******************************************************************************
* @brief Bit definitions for register page 0x00 : GEN_CFG_AES LOW
**/
#define DW3000_REG_0_ADDR                                 0x00

#define DW3000_REG_0_DEV_ID_OFFSET                        0x00   
#define DW3000_REG_0_DEV_ID_LEN                           4

#define DW3000_REG_0_EUI_64_OFFSET                        0x04
#define DW3000_REG_0_EUI_64_LEN                           8

#define DW3000_REG_0_PANADR_OFFSET                        0x0C
#define DW3000_REG_0_PANADR_LEN                           4

#define DW3000_REG_0_SYS_CFG_OFFSET                       0x10
#define DW3000_REG_0_SYS_CFG_LEN                          4

#define DW3000_REG_0_FF_CFG_OFFSET                        0x14
#define DW3000_REG_0_FF_CFG_LEN                           4

#define DW3000_REG_0_SPI_RD_CRC_OFFSET                    0x18
#define DW3000_REG_0_SPI_RD_CRC_LEN                       1

#define DW3000_REG_0_SYS_TIME_OFFSET                      0x1C
#define DW3000_REG_0_SYS_TIME_LEN                         4

#define DW3000_REG_0_TX_FCTRL_OFFSET                      0x24
#define DW3000_REG_0_TX_FCTRL_LEN                         6

#define DW3000_REG_0_DX_TIME_OFFSET                       0x2C
#define DW3000_REG_0_DX_TIME_LEN                          4

#define DW3000_REG_0_DREF_TIME_OFFSET                     0x30
#define DW3000_REG_0_DREF_TIME_LEN                        4

#define DW3000_REG_0_RX_FWTO_OFFSET                       0x34
#define DW3000_REG_0_RX_FWTO_LEN                          3

#define DW3000_REG_0_SYS_CTRL_OFFSET                      0x38
#define DW3000_REG_0_SYS_CTRL_LEN                         1

#define DW3000_REG_0_SYS_ENABLE_OFFSET                    0x3C
#define DW3000_REG_0_SYS_ENABLE_LEN                       6

#define DW3000_REG_0_SYS_STATUS_OFFSET                    0x44
#define DW3000_REG_0_SYS_STATUS_LEN                       6

#define DW3000_REG_0_RX_FINFO_OFFSET                      0x4C
#define DW3000_REG_0_RX_FINFO_LEN                         4

#define DW3000_REG_0_RX_TIME_OFFSET                       0x64
#define DW3000_REG_0_RX_TIME_LEN                          16

#define DW3000_REG_0_TX_TIME_OFFSET                       0x74
#define DW3000_REG_0_TX_TIME_LEN                          5

/******************************************************************************
* @brief Bit definitions for register page 0x01 : GEN_CFG_AES HIGH
**/
#define DW3000_REG_1_ADDR                                 0x01

#define DW3000_REG_1_TX_RAWST_OFFSET                      0x00
#define DW3000_REG_1_TX_RAWST_LEN                         4

#define DW3000_REG_1_TX_ANTD_OFFSET                       0x04
#define DW3000_REG_1_TX_ANTD_LEN                          2

#define DW3000_REG_1_ACK_RESP_T_OFFSET                    0x08
#define DW3000_REG_1_ACK_RESP_T_LEN                       4

#define DW3000_REG_1_TX_POWER_OFFSET                      0x0C
#define DW3000_REG_1_TX_POWER_LEN                         4

#define DW3000_REG_1_CHAN_CTRL_OFFSET                     0x14
#define DW3000_REG_1_CHAN_CTRL_LEN                        2

#define DW3000_REG_1_LE_PEND_01_OFFSET                    0x18
#define DW3000_REG_1_LE_PEND_01_LEN                       4

#define DW3000_REG_1_LE_PEND_23_OFFSET                    0x1C
#define DW3000_REG_1_LE_PEND_23_LEN                       4

#define DW3000_REG_1_SPI_COLLISION_OFFSET                 0x20
#define DW3000_REG_1_SPI_COLLISION_LEN                    1

#define DW3000_REG_1_RDB_STATUS_OFFSET                    0x24
#define DW3000_REG_1_RDB_STATUS_LEN                       1

#define DW3000_REG_1_RDB_DIAG_OFFSET                      0x28
#define DW3000_REG_1_RDB_DIAG_LEN                         1

#define DW3000_REG_1_AES_CFG_OFFSET                       0x30
#define DW3000_REG_1_AES_CFG_LEN                          2

#define DW3000_REG_1_AES_IV0_OFFSET                       0x34
#define DW3000_REG_1_AES_IV0_LEN                          4

#define DW3000_REG_1_AES_IV1_OFFSET                       0x38
#define DW3000_REG_1_AES_IV1_LEN                          4

#define DW3000_REG_1_AES_IV2_OFFSET                       0x3C
#define DW3000_REG_1_AES_IV2_LEN                          4

#define DW3000_REG_1_AES_IV3_OFFSET                       0x40
#define DW3000_REG_1_AES_IV3_LEN                          2

#define DW3000_REG_1_AES_IV4_OFFSET                       0x42
#define DW3000_REG_1_AES_IV4_LEN                          2

#define DW3000_REG_1_DMA_CFG_OFFSET                       0x44
#define DW3000_REG_1_DMA_CFG_LEN                          8

#define DW3000_REG_1_AES_START_OFFSET                     0x4C
#define DW3000_REG_1_AES_START_LEN                        1

#define DW3000_REG_1_AES_STS_OFFSET                       0x50
#define DW3000_REG_1_AES_STS_LEN                          4

#define DW3000_REG_1_AES_KEY_OFFSET                       0x54
#define DW3000_REG_1_AES_KEY_LEN                          16

/******************************************************************************
* @brief Bit definitions for register page 0x02: STS_CONFIG
**/

#define DW3000_REG_2_ADDR                                 0x02

#define DW3000_REG_2_STS_CFG_OFFSET                       0x00
#define DW3000_REG_2_STS_CFG_LEN                          2

#define DW3000_REG_2_STS_CTRL_OFFSET                      0x04
#define DW3000_REG_2_STS_CTRL_LEN                         1

#define DW3000_REG_2_STS_STS_OFFSET                       0x08
#define DW3000_REG_2_STS_STS_LEN                          2

#define DW3000_REG_2_STS_KEY_OFFSET                       0x0C
#define DW3000_REG_2_STS_KEY_LEN                          16

#define DW3000_REG_2_STS_IV_OFFSET                        0x1C
#define DW3000_REG_2_STS_IV_LEN                           16


/******************************************************************************
* @brief Bit definitions for register page 0x03: RX_TUNE
**/




















#endif // __DW3000_REGS_H__