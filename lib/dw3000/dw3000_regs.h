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

#define DW3000_REG_3_ADDR                                 0x03

#define DW3000_REG_3_DCG_CFG_OFFSET                       0x18
#define DW3000_REG_3_DCG_CFG_LEN                          2

#define DW3000_REG_3_DGC_CFG0_OFFSET                      0x1C
#define DW3000_REG_3_DGC_CFG0_LEN                         4

#define DW3000_REG_3_DGC_CFG1_OFFSET                      0x20
#define DW3000_REG_3_DGC_CFG1_LEN                         4

#define DW3000_REG_3_DGC_LUT_0_OFFSET                     0x38
#define DW3000_REG_3_DGC_LUT_0_LEN                        4

#define DW3000_REG_3_DGC_LUT_1_OFFSET                     0x3C
#define DW3000_REG_3_DGC_LUT_1_LEN                        4

#define DW3000_REG_3_DGC_LUT_2_OFFSET                     0x40
#define DW3000_REG_3_DGC_LUT_2_LEN                        4

#define DW3000_REG_3_DGC_LUT_3_OFFSET                     0x44
#define DW3000_REG_3_DGC_LUT_3_LEN                        4

#define DW3000_REG_3_DGC_LUT_4_OFFSET                     0x48
#define DW3000_REG_3_DGC_LUT_4_LEN                        4

#define DW3000_REG_3_DGC_LUT_5_OFFSET                     0x4C
#define DW3000_REG_3_DGC_LUT_5_LEN                        4

#define DW3000_REG_3_DGC_LUT_6_OFFSET                     0x50
#define DW3000_REG_3_DGC_LUT_6_LEN                        4

#define DW3000_REG_3_DCG_DBG_OFFSET                       0x60
#define DW3000_REG_3_DCG_DBG_LEN                          4

/******************************************************************************
 * @brief Bit definitions for register page 0x04: EXT_SYNC
 * @brief External sync control and RX calibration
**/

#define DW3000_REG_4_ADDR                                 0x04

#define DW3000_REG_4_EC_CTRL_OFFSET                       0x00
#define DW3000_REG_4_EC_CTRL_LEN                          4

#define DW3000_REG_4_RX_CAL_OFFSET                        0x0C
#define DW3000_REG_4_RX_CAL_LEN                           4

#define DW3000_REG_4_RX_CAL_RESI_OFFSET                   0x14
#define DW3000_REG_4_RX_CAL_RESI_LEN                      4

#define DW3000_REG_4_RX_CAL_RESQ_OFFSET                   0x1C
#define DW3000_REG_4_RX_CAL_RESQ_LEN                      4

#define DW3000_REG_4_RX_CAL_STS_OFFSET                    0x20
#define DW3000_REG_4_RX_CAL_STS_LEN                       1


/******************************************************************************
 * @brief Bit definitions for register page 0x05: GPIO_CTRL
 * @brief GPIO control and status
**/

#define DW3000_REG_5_ADDR                                 0x05

#define DW3000_REG_5_GPIO_MODE_OFFSET                     0x00
#define DW3000_REG_5_GPIO_MODE_LEN                        4

#define DW3000_REG_5_GPIO_PULL_EN_OFFSET                  0x04
#define DW3000_REG_5_GPIO_PULL_EN_LEN                     2

#define DW3000_REG_5_GPIO_DIR_OFFSET                      0x08
#define DW3000_REG_5_GPIO_DIR_LEN                         2

#define DW3000_REG_5_GPIO_OUT_OFFSET                      0x0C
#define DW3000_REG_5_GPIO_OUT_LEN                         2

#define DW3000_REG_5_GPIO_IRQE_OFFSET                     0x10
#define DW3000_REG_5_GPIO_IRQE_LEN                        2

#define DW3000_REG_5_GPIO_ISTS_OFFSET                     0x14
#define DW3000_REG_5_GPIO_ISTS_LEN                        2

#define DW3000_REG_5_GPIO_ISEN_OFFSET                     0x18
#define DW3000_REG_5_GPIO_ISEN_LEN                        2

#define DW3000_REG_5_GPIO_IMODE_OFFSET                    0x1C
#define DW3000_REG_5_GPIO_IMODE_LEN                       2

#define DW3000_REG_5_GPIO_IBES_OFFSET                     0x20
#define DW3000_REG_5_GPIO_IBES_LEN                        2

#define DW3000_REG_5_GPIO_ICLR_OFFSET                     0x24
#define DW3000_REG_5_GPIO_ICLR_LEN                        2

#define DW3000_REG_5_GPIO_IDBE_OFFSET                     0x28
#define DW3000_REG_5_GPIO_IDBE_LEN                        2

#define DW3000_REG_5_GPIO_RAW_OFFSET                      0x2C
#define DW3000_REG_5_GPIO_RAW_LEN                         2

/******************************************************************************
 * @brief Bit definitions for register page 0x06: DRX_CONF
 * @brief Digital receiver configuration
**/

#define DW3000_REG_6_ADDR                                 0x06

#define DW3000_REG_6_DTUNE0_OFFSET                        0x00
#define DW3000_REG_6_DTUNE0_LEN                           2

#define DW3000_REG_6_RX_SFD_TOC_OFFSET                    0x02
#define DW3000_REG_6_RX_SFD_TOC_LEN                       2

#define DW3000_REG_6_PRE_TOC_OFFSET                       0x04
#define DW3000_REG_6_PRE_TOC_LEN                          2

#define DW3000_REG_6_DTUNE3_OFFSET                        0x0C
#define DW3000_REG_6_DTUNE3_LEN                           4

#define DW3000_REG_6_DTUNE_5_OFFSET                       0x14
#define DW3000_REG_6_DTUNE_5_LEN                          4

#define DW3000_REG_6_DRX_CAR_INT_OFFSET                   0x29
#define DW3000_REG_6_DRX_CAR_INT_LEN                      3


/******************************************************************************
 * @brief Bit definitions for register page 0x07: RF_CONF
 * @brief Analog RF configuration block
**/

#define DW3000_REG_7_ADDR                                 0x07

#define DW3000_REG_7_RF_ENABLE_OFFSET                     0x00
#define DW3000_REG_7_RF_ENABLE_LEN                        4

#define DW3000_REG_7_RF_CTRL_MASK_OFFSET                  0x04
#define DW3000_REG_7_RF_CTRL_MASK_LEN                     4

#define DW3000_REG_7_RF_SWITCH_OFFSET                     0x14
#define DW3000_REG_7_RF_SWITCH_LEN                        4

#define DW3000_REG_7_RF_TX_CTRL_1_OFFSET                  0x1A
#define DW3000_REG_7_RF_TX_CTRL_1_LEN                     1

#define DW3000_REG_7_RF_TX_CTRL_2_OFFSET                  0x1C
#define DW3000_REG_7_RF_TX_CTRL_2_LEN                     4

#define DW3000_REG_7_TX_TEST_OFFSET                       0x28
#define DW3000_REG_7_TX_TEST_LEN                          1

#define DW3000_REG_7_SAR_TEST_OFFSET                      0x34
#define DW3000_REG_7_SAR_TEST_LEN                         1

#define DW3000_REG_7_LDO_TUNE_OFFSET                      0x40
#define DW3000_REG_7_LDO_TUNE_LEN                         8

#define DW3000_REG_7_LDO_CTRL_OFFSET                      0x48
#define DW3000_REG_7_LDO_CTRL_LEN                         4

#define DW3000_REG_7_LDO_RLOAD_OFFSET                     0x51
#define DW3000_REG_7_LDO_RLOAD_LEN                        1


/******************************************************************************
 * @brief Bit definitions for register page 0x08: TX_CAL
 * @brief Transmitter calibration block
**/

#define DW3000_REG_8_ADDR                                 0x08

#define DW3000_REG_8_SAR_CTRL_OFFSET                      0x00
#define DW3000_REG_8_SAR_CTRL_LEN                         1

#define DW3000_REG_8_SAR_STATUS_OFFSET                    0x04
#define DW3000_REG_8_SAR_STATUS_LEN                       1

#define DW3000_REG_8_SAR_READING_OFFSET                   0x08
#define DW3000_REG_8_SAR_READING_LEN                      3

#define DW3000_REG_8_SAR_WAKE_RD_OFFSET                   0x0C
#define DW3000_REG_8_SAR_WAKE_RD_LEN                      2















#endif // __DW3000_REGS_H__