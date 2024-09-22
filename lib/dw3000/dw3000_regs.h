#ifndef __DW3000_REGS_H__
#define __DW3000_REGS_H__

/******************************************************************************
* @brief Bit definitions for register 0 : GEN_CFG_AES
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







#endif // __DW3000_REGS_H__