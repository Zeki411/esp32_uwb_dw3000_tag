#ifndef __DW3000_REGS_H__
#define __DW3000_REGS_H__

// Macro to extract a specific field value from a register using its mask and offset
#define GET_FVAL(reg_val, mask, offset)       (((reg_val) & (mask)) >> (offset))
// Macro to set a specific field value in a register using its mask and offset
#define SET_FVAL(reg_val, mask, offset, value)  ((reg_val) = (((reg_val) & ~(mask)) | (((value) << (offset)) & (mask))))

/******************************************************************************
* @brief Bit definitions for register page 0x00 : GEN_CFG_AES LOW
**/
#define DW3000_REG_0_ADDR                                 0x00

/* Register: DEV_ID (0x00) */
#define DW3000_REG_0_DEV_ID_OFFSET                        0x00   
#define DW3000_REG_0_DEV_ID_BYTE_LEN                      (4U)
/* Fields */
#define DW3000_REG_0_DEV_ID_REV_BIT_OFFSET                (0U)
#define DW3000_REG_0_DEV_ID_REV_BIT_MASK                  (0xFU)
#define DW3000_REG_0_DEV_ID_VER_BIT_OFFSET                (4U)
#define DW3000_REG_0_DEV_ID_VER_BIT_MASK                  (0xF0U)
#define DW3000_REG_0_DEV_ID_MODEL_BIT_OFFSET              (8U)
#define DW3000_REG_0_DEV_ID_MODEL_BIT_MASK                (0xFF00U)
#define DW3000_REG_0_DEV_ID_RIDTAG_BIT_OFFSET             (16U)
#define DW3000_REG_0_DEV_ID_RIDTAG_BIT_MASK               (0xFFFF0000UL)

/* Register: EUI_64 (0x04) */
#define DW3000_REG_0_EUI_64_OFFSET                        0x04
#define DW3000_REG_0_EUI_64_BYTE_LEN                      (8U)
//TODO: add more info

/* Register: PANADR (0x0A) */
#define DW3000_REG_0_PANADR_OFFSET                        0x0C
#define DW3000_REG_0_PANADR_BYTE_LEN                      (4U)
/* Fields */
#define DW3000_REG_0_PANADR_SHORT_ADDR_BIT_OFFSET         (0U)
#define DW3000_REG_0_PANADR_SHORT_ADDR_BIT_MASK           (0xFFFFU)
#define DW3000_REG_0_PANADR_PAN_ID_BIT_OFFSET             (16U)
#define DW3000_REG_0_PANADR_PAN_ID_BIT_MASK               (0xFFFF0000UL)

/* Register: SYS_CFG (0x0E) */
#define DW3000_REG_0_SYS_CFG_OFFSET                       0x10
#define DW3000_REG_0_SYS_CFG_BYTE_LEN                     (4U)
/* Fields */
#define DW3000_REG_0_SYS_CFG_FFEN_BIT_OFFSET              (0U)
#define DW3000_REG_0_SYS_CFG_FFEN_BIT_MASK                (0x1U)
#define DW3000_REG_0_SYS_CFG_DIS_FCS_TX_BIT_OFFSET        (1U)
#define DW3000_REG_0_SYS_CFG_DIS_FCS_TX_BIT_MASK          (0x2U)
#define DW3000_REG_0_SYS_CFG_DIS_FCE_BIT_OFFSET           (2U)
#define DW3000_REG_0_SYS_CFG_DIS_FCE_BIT_MASK             (0x4U)
#define DW3000_REG_0_SYS_CFG_DIS_DRXB_BIT_OFFSET          (3U)
#define DW3000_REG_0_SYS_CFG_DIS_DRXB_BIT_MASK            (0x8U)
#define DW3000_REG_0_SYS_CFG_PHR_MODE_BIT_OFFSET          (4U)
#define DW3000_REG_0_SYS_CFG_PHR_MODE_BIT_MASK            (0x10U)
#define DW3000_REG_0_SYS_CFG_PHR_6M8_BIT_OFFSET           (5U)
#define DW3000_REG_0_SYS_CFG_PHR_6M8_BIT_MASK             (0x20U)
#define DW3000_REG_0_SYS_CFG_SPI_CRCEN_BIT_OFFSET         (6U)
#define DW3000_REG_0_SYS_CFG_SPI_CRCEN_BIT_MASK           (0x40U)
#define DW3000_REG_0_SYS_CFG_CIA_IPATOV_BIT_OFFSET        (7U)
#define DW3000_REG_0_SYS_CFG_CIA_IPATOV_BIT_MASK          (0x80U)
#define DW3000_REG_0_SYS_CFG_CIA_STS_BIT_OFFSET           (8U)
#define DW3000_REG_0_SYS_CFG_CIA_STS_BIT_MASK             (0x100U)
#define DW3000_REG_0_SYS_CFG_RXWTOE_BIT_OFFSET            (9U)
#define DW3000_REG_0_SYS_CFG_RXWTOE_BIT_MASK              (0x200U)
#define DW3000_REG_0_SYS_CFG_RXAUTR_BIT_OFFSET            (10U)
#define DW3000_REG_0_SYS_CFG_RXAUTR_BIT_MASK              (0x400U)
#define DW3000_REG_0_SYS_CFG_AUTO_ACK_BIT_OFFSET          (11U)
#define DW3000_REG_0_SYS_CFG_AUTO_ACK_BIT_MASK            (0x800U)
#define DW3000_REG_0_SYS_CFG_CP_SPC_BIT_OFFSET            (12U)
#define DW3000_REG_0_SYS_CFG_CP_SPC_BIT_MASK              (0x3000U)
#define DW3000_REG_0_SYS_CFG_CP_SDC_BIT_OFFSET            (15U)
#define DW3000_REG_0_SYS_CFG_CP_SDC_BIT_MASK              (0x8000U)
#define DW3000_REG_0_SYS_CFG_PDOA_MODE_BIT_OFFSET         (16U)
#define DW3000_REG_0_SYS_CFG_PDOA_MODE_BIT_MASK           (0x30000U)
#define DW3000_REG_0_SYS_CFG_FAST_AAT_BIT_OFFSET          (18U)
#define DW3000_REG_0_SYS_CFG_FAST_AAT_BIT_MASK            (0x40000U)

/* Register: FF_CFG (0x12) */
#define DW3000_REG_0_FF_CFG_OFFSET                         0x14
#define DW3000_REG_0_FF_CFG_BYTE_LEN                       (2U)
/* Fields */
#define DW3000_REG_0_FF_CFG_FFAB_BIT_OFFSET                (0U)
#define DW3000_REG_0_FF_CFG_FFAB_BIT_MASK                  (0x1U)
#define DW3000_REG_0_FF_CFG_FFAD_BIT_OFFSET                (1U)
#define DW3000_REG_0_FF_CFG_FFAD_BIT_MASK                  (0x2U)
#define DW3000_REG_0_FF_CFG_FFAA_BIT_OFFSET                (2U)
#define DW3000_REG_0_FF_CFG_FFAA_BIT_MASK                  (0x4U)
#define DW3000_REG_0_FF_CFG_FFAM_BIT_OFFSET                (3U)
#define DW3000_REG_0_FF_CFG_FFAM_BIT_MASK                  (0x8U)
#define DW3000_REG_0_FF_CFG_FFAR_BIT_OFFSET                (4U)
#define DW3000_REG_0_FF_CFG_FFAR_BIT_MASK                  (0x10U)
#define DW3000_REG_0_FF_CFG_FFAMULTI_BIT_OFFSET            (5U)
#define DW3000_REG_0_FF_CFG_FFAMULTI_BIT_MASK              (0x20U)
#define DW3000_REG_0_FF_CFG_FFAF_BIT_OFFSET                (6U)
#define DW3000_REG_0_FF_CFG_FFAF_BIT_MASK                  (0x40U)
#define DW3000_REG_0_FF_CFG_FFAE_BIT_OFFSET                (7U)
#define DW3000_REG_0_FF_CFG_FFAE_BIT_MASK                  (0x80U)
#define DW3000_REG_0_FF_CFG_FFBC_BIT_OFFSET                (8U)
#define DW3000_REG_0_FF_CFG_FFBC_BIT_MASK                  (0x100U)
#define DW3000_REG_0_FF_CFG_FFIB_BIT_OFFSET                (9U)
#define DW3000_REG_0_FF_CFG_FFIB_BIT_MASK                  (0x200U)
#define DW3000_REG_0_FF_CFG_LE0_PEND_BIT_OFFSET            (10U)
#define DW3000_REG_0_FF_CFG_LE0_PEND_BIT_MASK              (0x400U)
#define DW3000_REG_0_FF_CFG_LE1_PEND_BIT_OFFSET            (11U)
#define DW3000_REG_0_FF_CFG_LE1_PEND_BIT_MASK              (0x800U)
#define DW3000_REG_0_FF_CFG_LE2_PEND_BIT_OFFSET            (12U)
#define DW3000_REG_0_FF_CFG_LE2_PEND_BIT_MASK              (0x1000U)
#define DW3000_REG_0_FF_CFG_LE3_PEND_BIT_OFFSET            (13U)
#define DW3000_REG_0_FF_CFG_LE3_PEND_BIT_MASK              (0x2000U)
#define DW3000_REG_0_FF_CFG_SSADRAPE_BIT_OFFSET            (14U)
#define DW3000_REG_0_FF_CFG_SSADRAPE_BIT_MASK              (0x4000U)
#define DW3000_REG_0_FF_CFG_LSADRAPE_BIT_OFFSET            (15U)
#define DW3000_REG_0_FF_CFG_LSADRAPE_BIT_MASK              (0x8000U)

/* Register: SPI_RD_CRC (0x18) */
#define DW3000_REG_0_SPI_RD_CRC_OFFSET                     0x18
#define DW3000_REG_0_SPI_RD_CRC_BYTE_LEN                   (1U)

/* Register: SYS_TIME (0x1C) */
#define DW3000_REG_0_SYS_TIME_OFFSET                       0x1C
#define DW3000_REG_0_SYS_TIME_BYTE_LEN                     (4U)

/* Register: TX_FCTRL (0x24) */
#define DW3000_REG_0_TX_FCTRL_OFFSET                       0x24
#define DW3000_REG_0_TX_FCTRL_BYTE_LEN                     (6U)
#define DW3000_REG_0_TX_FCTRL_P0_BYTE_OFFSET               (0U)
#define DW3000_REG_0_TX_FCTRL_P1_BYTE_OFFSET               (4U)
/* Fields */
// P1
#define DW3000_REG_0_TX_FCTRL_P0_TXFLEN_BIT_OFFSET         (0U)
#define DW3000_REG_0_TX_FCTRL_P0_TXFLEN_BIT_MASK           (0x3FFU)     
#define DW3000_REG_0_TX_FCTRL_P0_TXBR_BIT_OFFSET           (10U)
#define DW3000_REG_0_TX_FCTRL_P0_TXBR_BIT_MASK             (0x400U)     
#define DW3000_REG_0_TX_FCTRL_P0_TR_BIT_OFFSET             (11U)
#define DW3000_REG_0_TX_FCTRL_P0_TR_BIT_MASK               (0x800U)     
#define DW3000_REG_0_TX_FCTRL_P0_TXPSR_BIT_OFFSET          (12U)
#define DW3000_REG_0_TX_FCTRL_P0_TXPSR_BIT_MASK            (0xF000U)    
#define DW3000_REG_0_TX_FCTRL_P0_TXB_OFFSET_BIT_OFFSET     (16U)
#define DW3000_REG_0_TX_FCTRL_P0_TXB_OFFSET_BIT_MASK       (0x3FF0000U) 
// P2
#define DW3000_REG_0_TX_FCTRL_P1_FINE_PLEN_BIT_OFFSET      (8U)
#define DW3000_REG_0_TX_FCTRL_P1_FINE_PLEN_BIT_MASK        (0xFF00U)   

/* Register: DX_TIME (0x2C) */
#define DW3000_REG_0_DX_TIME_OFFSET                        0x2C
#define DW3000_REG_0_DX_TIME_BYTE_LEN                      (4U)

/* Register: DREF_TIME (0x30) */
#define DW3000_REG_0_DREF_TIME_OFFSET                      0x30
#define DW3000_REG_0_DREF_TIME_BYTE_LEN                    (4U)

/* Register: RX_FWTO (0x34) */
#define DW3000_REG_0_RX_FWTO_OFFSET                        0x34
#define DW3000_REG_0_RX_FWTO_BYTE_LEN                      (3U)

/* Register: SYS_CTRL (0x38) */
#define DW3000_REG_0_SYS_CTRL_OFFSET                       0x38
#define DW3000_REG_0_SYS_CTRL_BYTE_LEN                     (1U)

/* Register: SYS_ENABLE (0x3C) */
#define DW3000_REG_0_SYS_ENABLE_OFFSET                     0x3C
#define DW3000_REG_0_SYS_ENABLE_BYTE_LEN                   (6U)
#define DW3000_REG_0_SYS_ENABLE_P0_BYTE_OFFSET             (0U)
#define DW3000_REG_0_SYS_ENABLE_P1_BYTE_OFFSET             (4U)
/* Fields */
// P0
#define DW3000_REG_0_SYS_ENABLE_P0_CPLOCK_EN_BIT_OFFSET    (1U)
#define DW3000_REG_0_SYS_ENABLE_P0_CPLOCK_EN_BIT_MASK      (0x2U)
#define DW3000_REG_0_SYS_ENABLE_P0_SPICRCE_EN_BIT_OFFSET   (2U)
#define DW3000_REG_0_SYS_ENABLE_P0_SPICRCE_EN_BIT_MASK     (0x4U)
#define DW3000_REG_0_SYS_ENABLE_P0_AAT_EN_BIT_OFFSET       (3U)
#define DW3000_REG_0_SYS_ENABLE_P0_AAT_EN_BIT_MASK         (0x8U)
#define DW3000_REG_0_SYS_ENABLE_P0_TXFRB_EN_BIT_OFFSET     (4U)
#define DW3000_REG_0_SYS_ENABLE_P0_TXFRB_EN_BIT_MASK       (0x10U)
#define DW3000_REG_0_SYS_ENABLE_P0_TXPRS_EN_BIT_OFFSET     (5U)
#define DW3000_REG_0_SYS_ENABLE_P0_TXPRS_EN_BIT_MASK       (0x20U)
#define DW3000_REG_0_SYS_ENABLE_P0_TXPHS_EN_BIT_OFFSET     (6U)
#define DW3000_REG_0_SYS_ENABLE_P0_TXPHS_EN_BIT_MASK       (0x40U)
#define DW3000_REG_0_SYS_ENABLE_P0_TXFRS_EN_BIT_OFFSET     (7U)
#define DW3000_REG_0_SYS_ENABLE_P0_TXFRS_EN_BIT_MASK       (0x80U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXPRD_EN_BIT_OFFSET     (8U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXPRD_EN_BIT_MASK       (0x100U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXSFDD_EN_BIT_OFFSET    (9U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXSFDD_EN_BIT_MASK      (0x200U)
#define DW3000_REG_0_SYS_ENABLE_P0_CIADONE_EN_BIT_OFFSET   (10U)
#define DW3000_REG_0_SYS_ENABLE_P0_CIADONE_EN_BIT_MASK     (0x400U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXPHD_EN_BIT_OFFSET     (11U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXPHD_EN_BIT_MASK       (0x800U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXPHE_EN_BIT_OFFSET     (12U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXPHE_EN_BIT_MASK       (0x1000U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXFR_EN_BIT_OFFSET      (13U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXFR_EN_BIT_MASK        (0x2000U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXFCG_EN_BIT_OFFSET     (14U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXFCG_EN_BIT_MASK       (0x4000U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXFCE_EN_BIT_OFFSET     (15U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXFCE_EN_BIT_MASK       (0x8000U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXRFSL_EN_BIT_OFFSET    (16U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXRFSL_EN_BIT_MASK      (0x10000U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXFTO_EN_BIT_OFFSET     (17U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXFTO_EN_BIT_MASK       (0x20000U)
#define DW3000_REG_0_SYS_ENABLE_P0_CIAERR_EN_BIT_OFFSET    (18U)
#define DW3000_REG_0_SYS_ENABLE_P0_CIAERR_EN_BIT_MASK      (0x40000U)
#define DW3000_REG_0_SYS_ENABLE_P0_VWARN_EN_BIT_OFFSET     (19U)
#define DW3000_REG_0_SYS_ENABLE_P0_VWARN_EN_BIT_MASK       (0x80000U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXOVRR_EN_BIT_OFFSET    (20U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXOVRR_EN_BIT_MASK      (0x100000U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXPTO_EN_BIT_OFFSET     (21U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXPTO_EN_BIT_MASK       (0x200000U)
#define DW3000_REG_0_SYS_ENABLE_P0_SPIRDY_EN_BIT_OFFSET    (23U)
#define DW3000_REG_0_SYS_ENABLE_P0_SPIRDY_EN_BIT_MASK      (0x800000U)
#define DW3000_REG_0_SYS_ENABLE_P0_RCINIT_EN_BIT_OFFSET    (24U)
#define DW3000_REG_0_SYS_ENABLE_P0_RCINIT_EN_BIT_MASK      (0x1000000U)
#define DW3000_REG_0_SYS_ENABLE_P0_PLL_HILO_EN_BIT_OFFSET  (25U)
#define DW3000_REG_0_SYS_ENABLE_P0_PLL_HILO_EN_BIT_MASK    (0x2000000U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXSTO_EN_BIT_OFFSET     (26U)
#define DW3000_REG_0_SYS_ENABLE_P0_RXSTO_EN_BIT_MASK       (0x4000000U)
#define DW3000_REG_0_SYS_ENABLE_P0_HPDWARN_EN_BIT_OFFSET   (27U)
#define DW3000_REG_0_SYS_ENABLE_P0_HPDWARN_EN_BIT_MASK     (0x8000000U)
#define DW3000_REG_0_SYS_ENABLE_P0_CPERR_EN_BIT_OFFSET     (28U)
#define DW3000_REG_0_SYS_ENABLE_P0_CPERR_EN_BIT_MASK       (0x10000000U)
#define DW3000_REG_0_SYS_ENABLE_P0_ARFE_EN_BIT_OFFSET      (29U)
#define DW3000_REG_0_SYS_ENABLE_P0_ARFE_EN_BIT_MASK        (0x20000000U)
// P1
#define DW3000_REG_0_SYS_ENABLE_P1_RXPREJ_EN_BIT_OFFSET    (1U)
#define DW3000_REG_0_SYS_ENABLE_P1_RXPREJ_EN_BIT_MASK      (0x2U)
#define DW3000_REG_0_SYS_ENABLE_P1_VT_DET_EN_BIT_OFFSET    (4U)
#define DW3000_REG_0_SYS_ENABLE_P1_VT_DET_EN_BIT_MASK      (0x10U)
#define DW3000_REG_0_SYS_ENABLE_P1_GPIOIRQ_EN_BIT_OFFSET   (5U)
#define DW3000_REG_0_SYS_ENABLE_P1_GPIOIRQ_EN_BIT_MASK     (0x20U)
#define DW3000_REG_0_SYS_ENABLE_P1_AES_DONE_EN_BIT_OFFSET  (6U)
#define DW3000_REG_0_SYS_ENABLE_P1_AES_DONE_EN_BIT_MASK    (0x40U)
#define DW3000_REG_0_SYS_ENABLE_P1_AES_ERR_EN_BIT_OFFSET   (7U)
#define DW3000_REG_0_SYS_ENABLE_P1_AES_ERR_EN_BIT_MASK     (0x80U)
#define DW3000_REG_0_SYS_ENABLE_P1_CMD_ERR_EN_BIT_OFFSET   (8U)
#define DW3000_REG_0_SYS_ENABLE_P1_CMD_ERR_EN_BIT_MASK     (0x100U)
#define DW3000_REG_0_SYS_ENABLE_P1_SPI_OVF_EN_BIT_OFFSET   (9U)
#define DW3000_REG_0_SYS_ENABLE_P1_SPI_OVF_EN_BIT_MASK     (0x200U)
#define DW3000_REG_0_SYS_ENABLE_P1_SPI_UNF_EN_BIT_OFFSET   (10U)
#define DW3000_REG_0_SYS_ENABLE_P1_SPI_UNF_EN_BIT_MASK     (0x400U)
#define DW3000_REG_0_SYS_ENABLE_P1_SPIERR_EN_BIT_OFFSET    (11U)
#define DW3000_REG_0_SYS_ENABLE_P1_SPIERR_EN_BIT_MASK      (0x800U)
#define DW3000_REG_0_SYS_ENABLE_P1_CCA_FAIL_EN_BIT_OFFSET  (12U)
#define DW3000_REG_0_SYS_ENABLE_P1_CCA_FAIL_EN_BIT_MASK    (0x1000U)

/* Register: SYS_STATUS (0x44) */
#define DW3000_REG_0_SYS_STATUS_OFFSET                     0x44
#define DW3000_REG_0_SYS_STATUS_BYTE_LEN                   (6U)
#define DW3000_REG_0_SYS_STATUS_P0_BYTE_OFFSET             (0U)
#define DW3000_REG_0_SYS_STATUS_P1_BYTE_OFFSET             (4U)
/* Fields */
// P0
#define DW3000_REG_0_SYS_STATUS_P0_IRQS_BIT_OFFSET         (0U)
#define DW3000_REG_0_SYS_STATUS_P0_IRQS_BIT_MASK           (0x1U)
#define DW3000_REG_0_SYS_STATUS_P0_CPLOCK_BIT_OFFSET       (1U)
#define DW3000_REG_0_SYS_STATUS_P0_CPLOCK_BIT_MASK         (0x2U)
#define DW3000_REG_0_SYS_STATUS_P0_SPICRCE_BIT_OFFSET      (2U)
#define DW3000_REG_0_SYS_STATUS_P0_SPICRCE_BIT_MASK        (0x4U)
#define DW3000_REG_0_SYS_STATUS_P0_AAT_BIT_OFFSET          (3U)
#define DW3000_REG_0_SYS_STATUS_P0_AAT_BIT_MASK            (0x8U)
#define DW3000_REG_0_SYS_STATUS_P0_TXFRB_BIT_OFFSET        (4U)
#define DW3000_REG_0_SYS_STATUS_P0_TXFRB_BIT_MASK          (0x10U)
#define DW3000_REG_0_SYS_STATUS_P0_TXPRS_BIT_OFFSET        (5U)
#define DW3000_REG_0_SYS_STATUS_P0_TXPRS_BIT_MASK          (0x20U)
#define DW3000_REG_0_SYS_STATUS_P0_TXPHS_BIT_OFFSET        (6U)
#define DW3000_REG_0_SYS_STATUS_P0_TXPHS_BIT_MASK          (0x40U)
#define DW3000_REG_0_SYS_STATUS_P0_TXFRS_BIT_OFFSET        (7U)
#define DW3000_REG_0_SYS_STATUS_P0_TXFRS_BIT_MASK          (0x80U)
#define DW3000_REG_0_SYS_STATUS_P0_RXPRD_BIT_OFFSET        (8U)
#define DW3000_REG_0_SYS_STATUS_P0_RXPRD_BIT_MASK          (0x100U)
#define DW3000_REG_0_SYS_STATUS_P0_RXSFDD_BIT_OFFSET       (9U)
#define DW3000_REG_0_SYS_STATUS_P0_RXSFDD_BIT_MASK         (0x200U)
#define DW3000_REG_0_SYS_STATUS_P0_CIADONE_BIT_OFFSET      (10U)
#define DW3000_REG_0_SYS_STATUS_P0_CIADONE_BIT_MASK        (0x400U)
#define DW3000_REG_0_SYS_STATUS_P0_RXPHD_BIT_OFFSET        (11U)
#define DW3000_REG_0_SYS_STATUS_P0_RXPHD_BIT_MASK          (0x800U)
#define DW3000_REG_0_SYS_STATUS_P0_RXPHE_BIT_OFFSET        (12U)
#define DW3000_REG_0_SYS_STATUS_P0_RXPHE_BIT_MASK          (0x1000U)
#define DW3000_REG_0_SYS_STATUS_P0_RXFR_BIT_OFFSET         (13U)
#define DW3000_REG_0_SYS_STATUS_P0_RXFR_BIT_MASK           (0x2000U)
#define DW3000_REG_0_SYS_STATUS_P0_RXFCG_BIT_OFFSET        (14U)
#define DW3000_REG_0_SYS_STATUS_P0_RXFCG_BIT_MASK          (0x4000U)
#define DW3000_REG_0_SYS_STATUS_P0_RXFCE_BIT_OFFSET        (15U)
#define DW3000_REG_0_SYS_STATUS_P0_RXFCE_BIT_MASK          (0x8000U)
#define DW3000_REG_0_SYS_STATUS_P0_RXRFSL_BIT_OFFSET       (16U)
#define DW3000_REG_0_SYS_STATUS_P0_RXRFSL_BIT_MASK         (0x10000U)
#define DW3000_REG_0_SYS_STATUS_P0_RXFTO_BIT_OFFSET        (17U)
#define DW3000_REG_0_SYS_STATUS_P0_RXFTO_BIT_MASK          (0x20000U)
#define DW3000_REG_0_SYS_STATUS_P0_CIAERR_BIT_OFFSET       (18U)
#define DW3000_REG_0_SYS_STATUS_P0_CIAERR_BIT_MASK         (0x40000U)
#define DW3000_REG_0_SYS_STATUS_P0_VWARN_BIT_OFFSET        (19U)
#define DW3000_REG_0_SYS_STATUS_P0_VWARN_BIT_MASK          (0x80000U)
#define DW3000_REG_0_SYS_STATUS_P0_RXOVRR_BIT_OFFSET       (20U)
#define DW3000_REG_0_SYS_STATUS_P0_RXOVRR_BIT_MASK         (0x100000U)
#define DW3000_REG_0_SYS_STATUS_P0_RXPTO_BIT_OFFSET        (21U)
#define DW3000_REG_0_SYS_STATUS_P0_RXPTO_BIT_MASK          (0x200000U)
#define DW3000_REG_0_SYS_STATUS_P0_SPIRDY_BIT_OFFSET       (23U)
#define DW3000_REG_0_SYS_STATUS_P0_SPIRDY_BIT_MASK         (0x800000U)
#define DW3000_REG_0_SYS_STATUS_P0_RCINIT_BIT_OFFSET       (24U)
#define DW3000_REG_0_SYS_STATUS_P0_RCINIT_BIT_MASK         (0x1000000U)
#define DW3000_REG_0_SYS_STATUS_P0_PLLHILO_BIT_OFFSET      (25U)
#define DW3000_REG_0_SYS_STATUS_P0_PLLHILO_BIT_MASK        (0x2000000U)
#define DW3000_REG_0_SYS_STATUS_P0_RXSTO_BIT_OFFSET        (26U)
#define DW3000_REG_0_SYS_STATUS_P0_RXSTO_BIT_MASK          (0x4000000U)
#define DW3000_REG_0_SYS_STATUS_P0_HPDWARN_BIT_OFFSET      (27U)
#define DW3000_REG_0_SYS_STATUS_P0_HPDWARN_BIT_MASK        (0x8000000U)
#define DW3000_REG_0_SYS_STATUS_P0_CPERR_BIT_OFFSET        (28U)
#define DW3000_REG_0_SYS_STATUS_P0_CPERR_BIT_MASK          (0x10000000U)
#define DW3000_REG_0_SYS_STATUS_P0_ARFE_BIT_OFFSET         (29U)
#define DW3000_REG_0_SYS_STATUS_P0_ARFE_BIT_MASK           (0x20000000U)
// P1
#define DW3000_REG_0_SYS_STATUS_P1_RXPREJ_BIT_OFFSET       (1U)
#define DW3000_REG_0_SYS_STATUS_P1_RXPREJ_BIT_MASK         (0x2U)
#define DW3000_REG_0_SYS_STATUS_P1_VT_DET_BIT_OFFSET       (4U)
#define DW3000_REG_0_SYS_STATUS_P1_VT_DET_BIT_MASK         (0x10U)
#define DW3000_REG_0_SYS_STATUS_P1_GPIOIRQ_BIT_OFFSET      (5U)
#define DW3000_REG_0_SYS_STATUS_P1_GPIOIRQ_BIT_MASK        (0x20U)
#define DW3000_REG_0_SYS_STATUS_P1_AES_DONE_BIT_OFFSET     (6U)
#define DW3000_REG_0_SYS_STATUS_P1_AES_DONE_BIT_MASK       (0x40U)
#define DW3000_REG_0_SYS_STATUS_P1_AES_ERR_BIT_OFFSET      (7U)
#define DW3000_REG_0_SYS_STATUS_P1_AES_ERR_BIT_MASK        (0x80U)
#define DW3000_REG_0_SYS_STATUS_P1_CMD_ERR_BIT_OFFSET      (8U)
#define DW3000_REG_0_SYS_STATUS_P1_CMD_ERR_BIT_MASK        (0x100U)
#define DW3000_REG_0_SYS_STATUS_P1_SPI_OVR_BIT_OFFSET      (9U)
#define DW3000_REG_0_SYS_STATUS_P1_SPI_OVR_BIT_MASK        (0x200U)
#define DW3000_REG_0_SYS_STATUS_P1_SPI_UNF_BIT_OFFSET      (10U)
#define DW3000_REG_0_SYS_STATUS_P1_SPI_UNF_BIT_MASK        (0x400U)
#define DW3000_REG_0_SYS_STATUS_P1_SPIERR_BIT_OFFSET       (11U)
#define DW3000_REG_0_SYS_STATUS_P1_SPIERR_BIT_MASK         (0x800U)
#define DW3000_REG_0_SYS_STATUS_P1_CCA_FAIL_BIT_OFFSET     (12U)
#define DW3000_REG_0_SYS_STATUS_P1_CCA_FAIL_BIT_MASK       (0x1000U)

/* Register: RX_FINFO (0x4C) */
#define DW3000_REG_0_RX_FINFO_OFFSET                        0x4C
#define DW3000_REG_0_RX_FINFO_BYTE_LEN                      (4U)
/* Fields */
#define DW3000_REG_0_RX_FINFO_RXFLEN_BIT_OFFSET             (0U)
#define DW3000_REG_0_RX_FINFO_RXFLEN_BIT_MASK               (0x3FFU)
#define DW3000_REG_0_RX_FINFO_RXNSPL_BIT_OFFSET             (11U)
#define DW3000_REG_0_RX_FINFO_RXNSPL_BIT_MASK               (0x1800U)
#define DW3000_REG_0_RX_FINFO_RXBR_BIT_OFFSET               (13U)
#define DW3000_REG_0_RX_FINFO_RXBR_BIT_MASK                 (0x2000U)
#define DW3000_REG_0_RX_FINFO_RNG_BIT_OFFSET                (15U)
#define DW3000_REG_0_RX_FINFO_RNG_BIT_MASK                  (0x8000U)
#define DW3000_REG_0_RX_FINFO_RXPRF_BIT_OFFSET              (16U)
#define DW3000_REG_0_RX_FINFO_RXPRF_BIT_MASK                (0x30000U)
#define DW3000_REG_0_RX_FINFO_RXPSR_BIT_OFFSET              (18U)
#define DW3000_REG_0_RX_FINFO_RXPSR_BIT_MASK                (0xC0000U)
#define DW3000_REG_0_RX_FINFO_RXPACC_BIT_OFFSET             (20U)
#define DW3000_REG_0_RX_FINFO_RXPACC_BIT_MASK               (0xFFF00000U)

/* Register: RX_TIME (0x64) */
#define DW3000_REG_0_RX_TIME_OFFSET                         0x64
#define DW3000_REG_0_RX_TIME_BYTE_LEN                       (16U)
#define DW3000_REG_0_RX_TIME_P0_BYTE_OFFSET                 (0U)
#define DW3000_REG_0_RX_TIME_P1_BYTE_OFFSET                 (4U)
#define DW3000_REG_0_RX_TIME_P2_BYTE_OFFSET                 (8U)
/* Fields */
// P0
#define DW3000_REG_0_RX_TIME_P0_RX_STAMP_BIT_OFFSET         (0U)
#define DW3000_REG_0_RX_TIME_P0_RX_STAMP_BIT_MASK           (0xFFFFFFFFUL)
// P1
#define DW3000_REG_0_RX_TIME_P1_RX_STAMP_BIT_OFFSET         (0U)
#define DW3000_REG_0_RX_TIME_P1_RX_STAMP_BIT_MASK           (0xFFU)
// P2
#define DW3000_REG_0_RX_TIME_P2_RX_RAWST_BIT_OFFSET         (0U)
#define DW3000_REG_0_RX_TIME_P2_RX_RAWST_BIT_MASK           (0xFFFFFFFFUL)

/* Register: TX_TIME (0x74) */
#define DW3000_REG_0_TX_TIME_OFFSET                         0x74
#define DW3000_REG_0_TX_TIME_BYTE_LEN                       (5U)
#define DW3000_REG_0_TX_TIME_P0_BYTE_OFFSET                 (0U)
#define DW3000_REG_0_TX_TIME_P1_BYTE_OFFSET                 (4U)
/* Fields */
// P0
#define DW3000_REG_0_TX_TIME_P0_TX_STAMP_BIT_OFFSET         (0U)
#define DW3000_REG_0_TX_TIME_P0_TX_STAMP_BIT_MASK           (0xFFFFFFFFUL)
// P1
#define DW3000_REG_0_TX_TIME_P1_TX_STAMP_BIT_OFFSET         (0U)
#define DW3000_REG_0_TX_TIME_P1_TX_STAMP_BIT_MASK           (0xFFU)

/******************************************************************************
* @brief Bit definitions for register page 0x01 : GEN_CFG_AES HIGH
**/
#define DW3000_REG_1_ADDR                                 0x01

/* Register: TX_RAWST (0x00) */
#define DW3000_REG_1_TX_RAWST_OFFSET                        0x00
#define DW3000_REG_1_TX_RAWST_BYTE_LEN                      (4U)

/* Register: TX_ANTD (0x04) */
#define DW3000_REG_1_TX_ANTD_OFFSET                         0x04
#define DW3000_REG_1_TX_ANTD_BYTE_LEN                       (2U)

/* Register: ACK_RESP_T (0x08) */
#define DW3000_REG_1_ACK_RESP_T_OFFSET                      0x08
#define DW3000_REG_1_ACK_RESP_T_BYTE_LEN                    (4U)
/* Fields */
#define DW3000_REG_1_ACK_RESP_T_W4R_TIM_BIT_OFFSET          (0U)
#define DW3000_REG_1_ACK_RESP_T_W4R_TIM_BIT_MASK            (0xFFFFFU)
#define DW3000_REG_1_ACK_RESP_T_ACK_TIM_BIT_OFFSET          (24U)
#define DW3000_REG_1_ACK_RESP_T_ACK_TIM_BIT_MASK            (0xFF000000U)

/* Register: TX_POWER (0x0C) */
#define DW3000_REG_1_TX_POWER_OFFSET                        0x0C
#define DW3000_REG_1_TX_POWER_BYTE_LEN                      (4U)
/* Fields */
#define DW3000_REG_1_TX_POWER_DATA_PWR_BIT_OFFSET           (0U)
#define DW3000_REG_1_TX_POWER_DATA_PWR_BIT_MASK             (0xFFU)
#define DW3000_REG_1_TX_POWER_PHR_PWR_BIT_OFFSET            (8U)
#define DW3000_REG_1_TX_POWER_PHR_PWR_BIT_MASK              (0xFF00U)
#define DW3000_REG_1_TX_POWER_SHR_PWR_BIT_OFFSET            (16U)
#define DW3000_REG_1_TX_POWER_SHR_PWR_BIT_MASK              (0xFF0000U)
#define DW3000_REG_1_TX_POWER_STS_PWR_BIT_OFFSET            (24U)
#define DW3000_REG_1_TX_POWER_STS_PWR_BIT_MASK              (0xFF000000U)

/* Register: CHAN_CTRL (0x14) */
#define DW3000_REG_1_CHAN_CTRL_OFFSET                       0x14
#define DW3000_REG_1_CHAN_CTRL_BYTE_LEN                     (2U)
/* Fields */
#define DW3000_REG_1_CHAN_CTRL_RF_CHAN_BIT_OFFSET           (0U)
#define DW3000_REG_1_CHAN_CTRL_RF_CHAN_BIT_MASK             (0x1U)
#define DW3000_REG_1_CHAN_CTRL_SFD_TYPE_BIT_OFFSET          (1U)
#define DW3000_REG_1_CHAN_CTRL_SFD_TYPE_BIT_MASK            (0x6U)
#define DW3000_REG_1_CHAN_CTRL_TX_PCODE_OFFSET              (3U)
#define DW3000_REG_1_CHAN_CTRL_TX_PCODE_BIT_MASK            (0xF8U)
#define DW3000_REG_1_CHAN_CTRL_RX_PCODE_OFFSET              (8U)
#define DW3000_REG_1_CHAN_CTRL_RX_PCODE_BIT_MASK            (0x1F00U)

/* Register: LE_PEND_01 (0x18) */
#define DW3000_REG_1_LE_PEND_01_OFFSET                      0x18
#define DW3000_REG_1_LE_PEND_01_BYTE_LEN                    (4U)
/* Fields */
#define DW3000_REG_1_LE_PEND_01_LE_ADDR0_BIT_OFFSET         (0U)
#define DW3000_REG_1_LE_PEND_01_LE_ADDR0_BIT_MASK           (0xFFFFU)
#define DW3000_REG_1_LE_PEND_01_LE_ADDR1_BIT_OFFSET         (16U)
#define DW3000_REG_1_LE_PEND_01_LE_ADDR1_BIT_MASK           (0xFFFF0000UL)

/* Register: LE_PEND_23 (0x1C) */
#define DW3000_REG_1_LE_PEND_23_OFFSET                      0x1C
#define DW3000_REG_1_LE_PEND_23_BYTE_LEN                    (4U)
/* Fields */
#define DW3000_REG_1_LE_PEND_23_LE_ADDR2_BIT_OFFSET         (0U)
#define DW3000_REG_1_LE_PEND_23_LE_ADDR2_BIT_MASK           (0xFFFFU)
#define DW3000_REG_1_LE_PEND_23_LE_ADDR3_BIT_OFFSET         (16U)
#define DW3000_REG_1_LE_PEND_23_LE_ADDR3_BIT_MASK           (0xFFFF0000UL)

/* Register: SPI_COLLISION (0x20) */
#define DW3000_REG_1_SPI_COLLISION_OFFSET                   0x20
#define DW3000_REG_1_SPI_COLLISION_BYTE_LEN                 (1U)
/* Fields */
#define DW3000_REG_1_SPI_COLLISION_SPI_COLLISION_BIT_OFFSET (0U)
#define DW3000_REG_1_SPI_COLLISION_SPI_COLLISION_BIT_MASK   (0x1FU)

/* Register: RDB_STATUS (0x24) */
#define DW3000_REG_1_RDB_STATUS_OFFSET                      0x24
#define DW3000_REG_1_RDB_STATUS_BYTE_LEN                    (1U)
/* Fields */
#define DW3000_REG_1_RDB_STATUS_RXFCG0_BIT_OFFSET           (0U)
#define DW3000_REG_1_RDB_STATUS_RXFCG0_BIT_MASK             (0x1U)
#define DW3000_REG_1_RDB_STATUS_RXFR0_BIT_OFFSET            (1U)
#define DW3000_REG_1_RDB_STATUS_RXFR0_BIT_MASK              (0x2U)
#define DW3000_REG_1_RDB_STATUS_CIADONE0_BIT_OFFSET         (2U)
#define DW3000_REG_1_RDB_STATUS_CIADONE0_BIT_MASK           (0x4U)
#define DW3000_REG_1_RDB_STATUS_CP_ERR0_BIT_OFFSET          (3U)
#define DW3000_REG_1_RDB_STATUS_CP_ERR0_BIT_MASK            (0x8U)
#define DW3000_REG_1_RDB_STATUS_RXFCG1_BIT_OFFSET           (4U)
#define DW3000_REG_1_RDB_STATUS_RXFCG1_BIT_MASK             (0x10U)
#define DW3000_REG_1_RDB_STATUS_RXFR1_BIT_OFFSET            (5U)
#define DW3000_REG_1_RDB_STATUS_RXFR1_BIT_MASK              (0x20U)
#define DW3000_REG_1_RDB_STATUS_CIADONE1_BIT_OFFSET         (6U)
#define DW3000_REG_1_RDB_STATUS_CIADONE1_BIT_MASK           (0x40U)
#define DW3000_REG_1_RDB_STATUS_CP_ERR1_BIT_OFFSET          (7U)
#define DW3000_REG_1_RDB_STATUS_CP_ERR1_BIT_MASK            (0x80U)

/* Register: RDB_DIAG (0x28) */
#define DW3000_REG_1_RDB_DIAG_OFFSET                        0x28
#define DW3000_REG_1_RDB_DIAG_BYTE_LEN                      (1U)
/* Fields */
#define DW3000_REG_1_RDB_DIAG_RDB_DMODE_BIT_OFFSET          (0U)
#define DW3000_REG_1_RDB_DIAG_RDB_DMODE_BIT_MASK            (0x3U)

/* Register: AES_CFG (0x30) */
#define DW3000_REG_1_AES_CFG_OFFSET                         0x30
#define DW3000_REG_1_AES_CFG_BYTE_LEN                       (2U)
/* Fields */
#define DW3000_REG_1_AES_CFG_MODE_BIT_OFFSET                (0U)
#define DW3000_REG_1_AES_CFG_MODE_BIT_MASK                  (0x1U)
#define DW3000_REG_1_AES_CFG_KEY_SIZE_BIT_OFFSET            (1U)
#define DW3000_REG_1_AES_CFG_KEY_SIZE_BIT_MASK              (0x6U)
#define DW3000_REG_1_AES_CFG_KEY_ADDR_BIT_OFFSET            (3U)
#define DW3000_REG_1_AES_CFG_KEY_ADDR_BIT_MASK              (0x38U)
#define DW3000_REG_1_AES_CFG_KEY_LOAD_BIT_OFFSET            (6U)
#define DW3000_REG_1_AES_CFG_KEY_LOAD_BIT_MASK              (0x40U)
#define DW3000_REG_1_AES_CFG_KEY_SRC_BIT_OFFSET             (7U)
#define DW3000_REG_1_AES_CFG_KEY_SRC_BIT_MASK               (0x80U)
#define DW3000_REG_1_AES_CFG_TAG_SIZE_BIT_OFFSET            (8U)
#define DW3000_REG_1_AES_CFG_TAG_SIZE_BIT_MASK              (0x700U)
#define DW3000_REG_1_AES_CFG_CORE_SEL_BIT_OFFSET            (11U)
#define DW3000_REG_1_AES_CFG_CORE_SEL_BIT_MASK              (0x800U)
#define DW3000_REG_1_AES_CFG_KEY_OTP_BIT_OFFSET             (12U)
#define DW3000_REG_1_AES_CFG_KEY_OTP_BIT_MASK               (0x1000U)

/* Register: AES_IV0 (0x34) */
#define DW3000_REG_1_AES_IV0_OFFSET                         0x34
#define DW3000_REG_1_AES_IV0_BYTE_LEN                       (4U)

/* Register: AES_IV1 (0x38) */
#define DW3000_REG_1_AES_IV1_OFFSET                         0x38
#define DW3000_REG_1_AES_IV1_BYTE_LEN                       (4U)

/* Register: AES_IV2 (0x3C) */
#define DW3000_REG_1_AES_IV2_OFFSET                         0x3C
#define DW3000_REG_1_AES_IV2_BYTE_LEN                       (4U)

/* Register: AES_IV3 (0x40) */
#define DW3000_REG_1_AES_IV3_OFFSET                         0x40
#define DW3000_REG_1_AES_IV3_BYTE_LEN                       (2U)

/* Register: AES_IV4 (0x42) */
#define DW3000_REG_1_AES_IV4_OFFSET                         0x42
#define DW3000_REG_1_AES_IV4_BYTE_LEN                       (2U)

/* Register: DMA_CFG (0x44) */
#define DW3000_REG_1_DMA_CFG_OFFSET                         0x44
#define DW3000_REG_1_DMA_CFG_BYTE_LEN                       (8U)
#define DW3000_REG_1_DMA_CFG_P0_BYTE_OFFSET                 (0U)
#define DW3000_REG_1_DMA_CFG_P1_BYTE_OFFSET                 (4U)
/* Fields */
// P0
#define DW3000_REG_1_P0_DMA_CFG_SRC_PORT_BIT_OFFSET         (0U)
#define DW3000_REG_1_P0_DMA_CFG_SRC_PORT_BIT_MASK           (0x7U)          
#define DW3000_REG_1_P0_DMA_CFG_SRC_ADDR_BIT_OFFSET         (3U)
#define DW3000_REG_1_P0_DMA_CFG_SRC_ADDR_BIT_MASK           (0x1FF8U)       
#define DW3000_REG_1_P0_DMA_CFG_DST_PORT_BIT_OFFSET         (13U)
#define DW3000_REG_1_P0_DMA_CFG_DST_PORT_BIT_MASK           (0xE000U)       
#define DW3000_REG_1_P0_DMA_CFG_DST_ADDR_BIT_OFFSET         (16U)
#define DW3000_REG_1_P0_DMA_CFG_DST_ADDR_BIT_MASK           (0x3FF0000U)    
#define DW3000_REG_1_P0_DMA_CFG_CP_END_SEL_BIT_OFFSET       (26U)
#define DW3000_REG_1_P0_DMA_CFG_CP_END_SEL_BIT_MASK         (0x4000000U)    
// P1
#define DW3000_REG_1_P1_DMA_CFG_HDR_SIZE_BIT_OFFSET         (0U)
#define DW3000_REG_1_P1_DMA_CFG_HDR_SIZE_BIT_MASK           (0x7FU)
#define DW3000_REG_1_P1_DMA_CFG_PYLD_SIZE_BIT_OFFSET        (7U)
#define DW3000_REG_1_P1_DMA_CFG_PYLD_SIZE_BIT_MASK          (0x1FF80U)

/* Register: AES_START (0x4C) */
#define DW3000_REG_1_AES_START_OFFSET                       0x4C
#define DW3000_REG_1_AES_START_BYTE_LEN                     (1U)
/* Fields */
#define DW3000_REG_1_AES_START_AES_START_BIT_OFFSET         (0U)
#define DW3000_REG_1_AES_START_AES_START_BIT_MASK           (0x1U)

/* Register: AES_STS (0x50) */
#define DW3000_REG_1_AES_STS_OFFSET                         0x50
#define DW3000_REG_1_AES_STS_BYTE_LEN                       (4U)
/* Fields */
#define DW3000_REG_1_AES_STS_AES_DONE_BIT_OFFSET            (0U)
#define DW3000_REG_1_AES_STS_AES_DONE_BIT_MASK              (0x1U)
#define DW3000_REG_1_AES_STS_AUTH_ERR_BIT_OFFSET            (1U)
#define DW3000_REG_1_AES_STS_AUTH_ERR_BIT_MASK              (0x2U)
#define DW3000_REG_1_AES_STS_TRANS_ERR_BIT_OFFSET           (2U)
#define DW3000_REG_1_AES_STS_TRANS_ERR_BIT_MASK             (0x4U)
#define DW3000_REG_1_AES_STS_MEM_CONF_BIT_OFFSET            (3U)
#define DW3000_REG_1_AES_STS_MEM_CONF_BIT_MASK              (0x8U)
#define DW3000_REG_1_AES_STS_RAM_EMPTY_BIT_OFFSET           (4U)
#define DW3000_REG_1_AES_STS_RAM_EMPTY_BIT_MASK             (0x10U)
#define DW3000_REG_1_AES_STS_RAM_FULL_BIT_OFFSET            (5U)
#define DW3000_REG_1_AES_STS_RAM_FULL_BIT_MASK              (0x20U)

/* Register: AES_KEY (0x54) */
#define DW3000_REG_1_AES_KEY_OFFSET                         0x54
#define DW3000_REG_1_AES_KEY_BYTE_LEN                       (16U)

/******************************************************************************
* @brief Bit definitions for register page 0x02 : STS_CONFIG
* @note  Scrambled Timestamp Sequence configuration and status registers
**/
#define DW3000_REG_2_ADDR                                 0x02

/* Register: STS_CFG (0x00) */
#define DW3000_REG_2_STS_CFG_OFFSET                         0x00
#define DW3000_REG_2_STS_CFG_BYTE_LEN                       (2U)
/* Fields */
#define DW3000_REG_2_STS_CFG_STS_CPS_LEN_BIT_OFFSET         (0U)
#define DW3000_REG_2_STS_CFG_STS_CPS_LEN_BIT_MASK           (0xFFU)

/* Register: STS_CTRL (0x04) */
#define DW3000_REG_2_STS_CTRL_OFFSET                        0x04
#define DW3000_REG_2_STS_CTRL_BYTE_LEN                      (1U)
/* Fields */
#define DW3000_REG_2_STS_CTRL_STS_LOAD_IV_BIT_OFFSET        (0U)
#define DW3000_REG_2_STS_CTRL_STS_LOAD_IV_BIT_MASK          (0x1U)
#define DW3000_REG_2_STS_CTRL_STS_RST_LAST_BIT_OFFSET       (1U)
#define DW3000_REG_2_STS_CTRL_STS_RST_LAST_BIT_MASK         (0x2U)

/* Register: STS_STS (0x08) */
#define DW3000_REG_2_STS_STS_OFFSET                         0x08
#define DW3000_REG_2_STS_STS_BYTE_LEN                       (2U)
/* Fields */
#define DW3000_REG_2_STS_STS_ACC_QUAL_BIT_OFFSET            (0U)
#define DW3000_REG_2_STS_STS_ACC_QUAL_BIT_MASK              (0xFFFU)

/* Register: STS_KEY (0x0C) */
#define DW3000_REG_2_STS_KEY_OFFSET                         0x0C
#define DW3000_REG_2_STS_KEY_BYTE_LEN                       (16U)

/* Register: STS_IV (0x1C) */
#define DW3000_REG_2_STS_IV_OFFSET                          0x1C
#define DW3000_REG_2_STS_IV_BYTE_LEN                        (16U)

/******************************************************************************
* @brief Bit definitions for register page 0x03 : RX_TUNE
* @note  Receiver tuning parameters
**/
#define DW3000_REG_3_ADDR                                   0x03

/* Register: DGC_CFG (0x00) */
#define DW3000_REG_3_DGC_CFG_OFFSET                         0x00
#define DW3000_REG_3_DGC_CFG_BYTE_LEN                       (2U)
/* Fields */
#define DW3000_REG_3_DGC_CFG_RX_TUNE_EN_BIT_OFFSET          (0U)
#define DW3000_REG_3_DGC_CFG_RX_TUNE_EN_BIT_MASK            (0x1U)
#define DW3000_REG_3_DGC_CFG_THR_64_BIT_OFFSET              (9U)
#define DW3000_REG_3_DGC_CFG_THR_64_BIT_MASK                (0x7E00U)

/* Register: DGC_CFG0 (0x1C) */
#define DW3000_REG_3_DGC_CFG0_OFFSET                        0x1C
#define DW3000_REG_3_DGC_CFG0_BYTE_LEN                      (4U)

/* Register: DGC_CFG1 (0x20) */
#define DW3000_REG_3_DGC_CFG1_OFFSET                        0x20
#define DW3000_REG_3_DGC_CFG1_BYTE_LEN                      (4U)

/* Register: DGC_LUT_0 (0x38) */
#define DW3000_REG_3_DGC_LUT_0_OFFSET                       0x38
#define DW3000_REG_3_DGC_LUT_0_BYTE_LEN                     (4U)

/* Register: DGC_LUT_1 (0x3C) */
#define DW3000_REG_3_DGC_LUT_1_OFFSET                       0x3C
#define DW3000_REG_3_DGC_LUT_1_BYTE_LEN                     (4U)

/* Register: DGC_LUT_2 (0x40) */
#define DW3000_REG_3_DGC_LUT_2_OFFSET                       0x40
#define DW3000_REG_3_DGC_LUT_2_BYTE_LEN                     (4U)

/* Register: DGC_LUT_3 (0x44) */
#define DW3000_REG_3_DGC_LUT_3_OFFSET                       0x44
#define DW3000_REG_3_DGC_LUT_3_BYTE_LEN                     (4U)

/* Register: DGC_LUT_4 (0x48) */
#define DW3000_REG_3_DGC_LUT_4_OFFSET                       0x48
#define DW3000_REG_3_DGC_LUT_4_BYTE_LEN                     (4U)

/* Register: DGC_LUT_5 (0x4C) */
#define DW3000_REG_3_DGC_LUT_5_OFFSET                       0x4C
#define DW3000_REG_3_DGC_LUT_5_BYTE_LEN                     (4U)

/* Register: DGC_LUT_6 (0x50) */
#define DW3000_REG_3_DGC_LUT_6_OFFSET                       0x50
#define DW3000_REG_3_DGC_LUT_6_BYTE_LEN                     (4U)

/* Register: DGC_DBG (0x60) */
#define DW3000_REG_3_DGC_DBG_OFFSET                         0x60
#define DW3000_REG_3_DGC_DBG_BYTE_LEN                       (4U)
/* Fields */
#define DW3000_REG_3_DGC_DBG_DGC_DECISION_BIT_OFFSET        (28U)
#define DW3000_REG_3_DGC_DBG_DGC_DECISION_BIT_MASK          (0x70000000U)

/******************************************************************************
* @brief Bit definitions for register page 0x04 : EXT_SYNC
* @note  External synchronisation control and RX calibration
**/
#define DW3000_REG_4_ADDR                                   0x04

/* Register: EC_CTRL (0x00) */
#define DW3000_REG_4_EC_CTRL_OFFSET                         0x00
#define DW3000_REG_4_EC_CTRL_BYTE_LEN                       (4U)
/* Fields */
#define DW3000_REG_4_EC_CTRL_OSTS_WAIT_BIT_OFFSET           (3U)
#define DW3000_REG_4_EC_CTRL_OSTS_WAIT_BIT_MASK             (0x7F8U)
#define DW3000_REG_4_EC_CTRL_OSTR_MODE_BIT_OFFSET           (11U)
#define DW3000_REG_4_EC_CTRL_OSTR_MODE_BIT_MASK             (0x800U)

/* Register: RX_CAL (0x0C) */
#define DW3000_REG_4_RX_CAL_OFFSET                          0x0C
#define DW3000_REG_4_RX_CAL_BYTE_LEN                        (4U)
/* Fields */
#define DW3000_REG_4_RX_CAL_CAL_MODE_BIT_OFFSET             (0U)
#define DW3000_REG_4_RX_CAL_CAL_MODE_BIT_MASK               (0x3U)
#define DW3000_REG_4_RX_CAL_CAL_EN_BIT_OFFSET               (4U)
#define DW3000_REG_4_RX_CAL_CAL_EN_BIT_MASK                 (0x10U)
#define DW3000_REG_4_RX_CAL_COMP_DLY_BIT_OFFSET             (16U)
#define DW3000_REG_4_RX_CAL_COMP_DLY_BIT_MASK               (0xF0000U)

/* Register: RX_CAL_RESI (0x14) */
#define DW3000_REG_4_RX_CAL_RESI_OFFSET                     0x14
#define DW3000_REG_4_RX_CAL_RESI_BYTE_LEN                   (4U)

/* Register: RX_CAL_RESQ (0x1C) */
#define DW3000_REG_4_RX_CAL_RESQ_OFFSET                     0x1C
#define DW3000_REG_4_RX_CAL_RESQ_BYTE_LEN                   (4U)

/* Register: RX_CAL_STS (0x20) */
#define DW3000_REG_4_RX_CAL_STS_OFFSET                      0x20
#define DW3000_REG_4_RX_CAL_STS_BYTE_LEN                    (1U)

/******************************************************************************
* @brief Bit definitions for register page 0x05 : GPIO_CTRL
* @note  General Purpose Input-Output control registers
**/
#define DW3000_REG_5_ADDR                                   0x05

//TODO: Add GPIO control registers

/******************************************************************************
* @brief Bit definitions for register page 0x06 : DRX_CONF
* @note  Digital receiver configuration
**/
#define DW3000_REG_6_ADDR                                   0x06

/* Register: DTUNE (0x00) */
#define DW3000_REG_6_DTUNE_OFFSET                           0x00
#define DW3000_REG_6_DTUNE_BYTE_LEN                         (2U)
/* Fields */
#define DW3000_REG_6_DTUNE_PAC_BIT_OFFSET                   (0U)
#define DW3000_REG_6_DTUNE_PAC_BIT_MASK                     (0x3U)
#define DW3000_REG_6_DTUNE_DT0B4_BIT_OFFSET                 (4U)
#define DW3000_REG_6_DTUNE_DT0B4_BIT_MASK                   (0x10U)

/* Register: RX_SFD_TOC (0x02) */
#define DW3000_REG_6_RX_SFD_TOC_OFFSET                      0x02
#define DW3000_REG_6_RX_SFD_TOC_BYTE_LEN                    (2U)

/* Register: PRE_TOC (0x04) */
#define DW3000_REG_6_PRE_TOC_OFFSET                         0x04
#define DW3000_REG_6_PRE_TOC_BYTE_LEN                       (2U)

/* Register: DTUNE3 (0x0C) */
#define DW3000_REG_6_DTUNE3_OFFSET                          0x0C
#define DW3000_REG_6_DTUNE3_BYTE_LEN                        (4U)

/* Register: DTUNE_5 (0x14) */
#define DW3000_REG_6_DTUNE_5_OFFSET                         0x14
#define DW3000_REG_6_DTUNE_5_BYTE_LEN                       (4U)

/* Register: DRX_CAR_INT (0x29) */
#define DW3000_REG_6_DRX_CAR_INT_OFFSET                     0x29
#define DW3000_REG_6_DRX_CAR_INT_BYTE_LEN                   (3U)

/******************************************************************************
* @brief Bit definitions for register page 0x07 : RF_CONF
* @note  Analog RF configuration
**/
#define DW3000_REG_7_ADDR                                   0x07

/* Register: RF_ENABLE (0x00) */
#define DW3000_REG_7_RF_ENABLE_OFFSET                       0x00
#define DW3000_REG_7_RF_ENABLE_BYTE_LEN                     (4U)

/* Register: RF_CTRL_MASK (0x04) */
#define DW3000_REG_7_RF_CTRL_MASK_OFFSET                    0x04
#define DW3000_REG_7_RF_CTRL_MASK_BYTE_LEN                  (4U)

/* Register: RF_SWITCH (0x14) */
#define DW3000_REG_7_RF_SWITCH_OFFSET                       0x14
#define DW3000_REG_7_RF_SWITCH_BYTE_LEN                     (4U)
/* Fields */
#define DW3000_REG_7_RF_SWITCH_ANTSWNOTOGGLE_BIT_OFFSET     (0U)
#define DW3000_REG_7_RF_SWITCH_ANTSWNOTOGGLE_BIT_MASK       (0x1U)
#define DW3000_REG_7_RF_SWITCH_ANTSWPDOAPORT_BIT_OFFSET     (1U)
#define DW3000_REG_7_RF_SWITCH_ANTSWPDOAPORT_BIT_MASK       (0x2U)
#define DW3000_REG_7_RF_SWITCH_ANTSWEN_BIT_OFFSET           (8U)
#define DW3000_REG_7_RF_SWITCH_ANTSWEN_BIT_MASK             (0x100U)
#define DW3000_REG_7_RF_SWITCH_ANTSWCTRL_BIT_OFFSET         (12U)
#define DW3000_REG_7_RF_SWITCH_ANTSWCTRL_BIT_MASK           (0x7000U)
#define DW3000_REG_7_RF_SWITCH_TRXSWEN_BIT_OFFSET           (16U)
#define DW3000_REG_7_RF_SWITCH_TRXSWEN_BIT_MASK             (0x10000U)
#define DW3000_REG_7_RF_SWITCH_TRXSWCTRL_BIT_OFFSET         (24U)
#define DW3000_REG_7_RF_SWITCH_TRXSWCTRL_BIT_MASK           (0x3F000000U)

/* Register: RF_TX_CTRL_1 (0x1A) */
#define DW3000_REG_7_RF_TX_CTRL_1_OFFSET                    0x1A
#define DW3000_REG_7_RF_TX_CTRL_1_BYTE_LEN                  (1U)

/* Register: RF_TX_CTRL_2 (0x1C) */
#define DW3000_REG_7_RF_TX_CTRL_2_OFFSET                    0x1C
#define DW3000_REG_7_RF_TX_CTRL_2_BYTE_LEN                  (4U)
/* Fields */
#define DW3000_REG_7_RF_TX_CTRL_2_PG_DELAY_BIT_OFFSET       (0U)
#define DW3000_REG_7_RF_TX_CTRL_2_PG_DELAY_BIT_MASK         (0x3FU)

/* Register: TX_TEST (0x28) */
#define DW3000_REG_7_TX_TEST_OFFSET                         0x28
#define DW3000_REG_7_TX_TEST_BYTE_LEN                       (1U)
/* Fields */
#define DW3000_REG_7_TX_TEST_TX_ENTEST_BIT_OFFSET           (0U)
#define DW3000_REG_7_TX_TEST_TX_ENTEST_BIT_MASK             (0xFU)

/* Register: SAR_TEST (0x34) */
#define DW3000_REG_7_SAR_TEST_OFFSET                        0x34
#define DW3000_REG_7_SAR_TEST_BYTE_LEN                      (1U)
/* Fields */
#define DW3000_REG_7_SAR_TEST_SAR_RDEN_BIT_OFFSET           (2U)
#define DW3000_REG_7_SAR_TEST_SAR_RDEN_BIT_MASK             (0x4U)

/* Register: LDO_TUNE (0x40) */
#define DW3000_REG_7_LDO_TUNE_OFFSET                        0x40
#define DW3000_REG_7_LDO_TUNE_BYTE_LEN                      (8U)
#define DW3000_REG_7_LDO_TUNE_P0_BYTE_OFFSET                (0U)
#define DW3000_REG_7_LDO_TUNE_P1_BYTE_OFFSET                (4U)
/* Fields */
// P0
#define DW3000_REG_7_LDO_TUNE_P0_LDO_TUNE_BIT_OFFSET        (0U)
#define DW3000_REG_7_LDO_TUNE_P0_LDO_TUNE_BIT_MASK          (0xFFFFFFFFU)
// P1
#define DW3000_REG_7_LDO_TUNE_P1_LDO_TUNE_BIT_OFFSET        (0U)
#define DW3000_REG_7_LDO_TUNE_P1_LDO_TUNE_BIT_MASK          (0xFFFFFFFU)

/* Register: LDO_CTRL (0x48) */
#define DW3000_REG_7_LDO_CTRL_OFFSET                        0x48
#define DW3000_REG_7_LDO_CTRL_BYTE_LEN                      (4U)

/* Register: LDO_RLOAD (0x51) */
#define DW3000_REG_7_LDO_RLOAD_OFFSET                       0x51
#define DW3000_REG_7_LDO_RLOAD_BYTE_LEN                     (1U)

/******************************************************************************
* @brief Bit definitions for register page 0x08 : TX_CAL
* @note  Transmitter calibration block
**/
#define DW3000_REG_8_ADDR                                   0x08

/* Register: SAR_CTRL (0x00) */
#define DW3000_REG_8_SAR_CTRL_OFFSET                        0x00
#define DW3000_REG_8_SAR_CTRL_BYTE_LEN                      (1U)
/* Fields */
#define DW3000_REG_8_SAR_CTRL_SAR_START_BIT_OFFSET          (0U)
#define DW3000_REG_8_SAR_CTRL_SAR_START_BIT_MASK            (0x1U)

/* Register: SAR_STATUS (0x04) */
#define DW3000_REG_8_SAR_STATUS_OFFSET                      0x04
#define DW3000_REG_8_SAR_STATUS_BYTE_LEN                    (1U)
/* Fields */
#define DW3000_REG_8_SAR_STATUS_SAR_DONE_BIT_OFFSET         (0U)
#define DW3000_REG_8_SAR_STATUS_SAR_DONE_BIT_MASK           (0x1U)

/* Register: SAR_READING (0x08) */
#define DW3000_REG_8_SAR_READING_OFFSET                     0x08
#define DW3000_REG_8_SAR_READING_BYTE_LEN                   (3U)
/* Fields */
#define DW3000_REG_8_SAR_READING_SAR_LVBAT_BIT_OFFSET       (0U)
#define DW3000_REG_8_SAR_READING_SAR_LVBAT_BIT_MASK         (0xFFU)
#define DW3000_REG_8_SAR_READING_SAR_LTEMP_BIT_OFFSET       (8U)
#define DW3000_REG_8_SAR_READING_SAR_LTEMP_BIT_MASK         (0xFF00U)

/* Register: SAR_WAKE_RD (0x0C) */
#define DW3000_REG_8_SAR_WAKE_RD_OFFSET                     0x0C
#define DW3000_REG_8_SAR_WAKE_RD_BYTE_LEN                   (2U)
/* Fields */
#define DW3000_REG_8_SAR_WAKE_RD_SAR_WVBAT_BIT_OFFSET       (0U)
#define DW3000_REG_8_SAR_WAKE_RD_SAR_WVBAT_BIT_MASK         (0xFFU)
#define DW3000_REG_8_SAR_WAKE_RD_SAR_WTEMP_BIT_OFFSET       (8U)
#define DW3000_REG_8_SAR_WAKE_RD_SAR_WTEMP_BIT_MASK         (0xFF00U)

/* Register: PGC_CTRL (0x10) */
#define DW3000_REG_8_PGC_CTRL_OFFSET                        0x10
#define DW3000_REG_8_PGC_CTRL_BYTE_LEN                      (2U)
/* Fields */
#define DW3000_REG_8_PGC_CTRL_PGC_START_BIT_OFFSET          (0U)
#define DW3000_REG_8_PGC_CTRL_PGC_START_BIT_MASK            (0x1U)
#define DW3000_REG_8_PGC_CTRL_PGC_AUTO_CAL_BIT_OFFSET       (1U)
#define DW3000_REG_8_PGC_CTRL_PGC_AUTO_CAL_BIT_MASK         (0x2U)
#define DW3000_REG_8_PGC_CTRL_PGC_TMEAS_BIT_OFFSET          (2U)
#define DW3000_REG_8_PGC_CTRL_PGC_TMEAS_BIT_MASK            (0x3CU)

/* Register: PGC_STATUS (0x14) */
#define DW3000_REG_8_PGC_STATUS_OFFSET                      0x14
#define DW3000_REG_8_PGC_STATUS_BYTE_LEN                    (2U)
/* Fields */
#define DW3000_REG_8_PGC_STATUS_PG_DELAY_CNT_BIT_OFFSET     (0U)
#define DW3000_REG_8_PGC_STATUS_PG_DELAY_CNT_BIT_MASK       (0xFFFU)
#define DW3000_REG_8_PGC_STATUS_PAUTOCAL_DONE_BIT_OFFSET    (12U)
#define DW3000_REG_8_PGC_STATUS_PAUTOCAL_DONE_BIT_MASK      (0x1000U)

/* Register: PG_TEST (0x18) */
#define DW3000_REG_8_PG_TEST_OFFSET                         0x18
#define DW3000_REG_8_PG_TEST_BYTE_LEN                       (2U)

/* Register: PG_CAL_TARGET (0x1C) */
#define DW3000_REG_8_PG_CAL_TARGET_OFFSET                   0x1C
#define DW3000_REG_8_PG_CAL_TARGET_BYTE_LEN                 (2U)
/* Fields */
#define DW3000_REG_8_PG_CAL_TARGET_PG_TARGET_BIT_OFFSET     (0U)
#define DW3000_REG_8_PG_CAL_TARGET_PG_TARGET_BIT_MASK       (0xFFFU)

/******************************************************************************
* @brief Bit definitions for register page 0x09 : FS_CTRL
* @note  Frequency synthesiser control block
**/
#define DW3000_REG_9_ADDR                                   0x09

/* Register: PLL_CFG (0x00) */
#define DW3000_REG_9_PLL_CFG_OFFSET                         0x00
#define DW3000_REG_9_PLL_CFG_BYTE_LEN                       (2U)

/* Register: PLL_CC (0x04) */
#define DW3000_REG_9_PLL_CC_OFFSET                          0x04
#define DW3000_REG_9_PLL_CC_BYTE_LEN                        (1U)
/* Fields */
#define DW3000_REG_9_PLL_CC_CH9_CODE_BIT_OFFSET             (0U)
#define DW3000_REG_9_PLL_CC_CH9_CODE_BIT_MASK               (0xFFU)
#define DW3000_REG_9_PLL_CC_CH5_CODE_BIT_OFFSET             (8U)
#define DW3000_REG_9_PLL_CC_CH5_CODE_BIT_MASK               (0x3FFF00U)

/* Register: PLL_CAL (0x08) */
#define DW3000_REG_9_PLL_CAL_OFFSET                         0x08
#define DW3000_REG_9_PLL_CAL_BYTE_LEN                       (2U)
/* Fields */
#define DW3000_REG_9_PLL_CAL_USE_OLD_BIT_OFFSET             (1U)
#define DW3000_REG_9_PLL_CAL_USE_OLD_BIT_MASK               (0x2U)
#define DW3000_REG_9_PLL_CAL_PLL_CFG_LD_BIT_OFFSET          (4U)
#define DW3000_REG_9_PLL_CAL_PLL_CFG_LD_BIT_MASK            (0xF0U)
#define DW3000_REG_9_PLL_CAL_CAL_EN_BIT_OFFSET              (8U)
#define DW3000_REG_9_PLL_CAL_CAL_EN_BIT_MASK                (0x100U)

/* Register: XTAL (0x14) */
#define DW3000_REG_9_XTAL_OFFSET                            0x14
#define DW3000_REG_9_XTAL_BYTE_LEN                          (1U)
/* Fields */
#define DW3000_REG_9_XTAL_XTAL_TRIM_BIT_OFFSET              (0U)
#define DW3000_REG_9_XTAL_XTAL_TRIM_BIT_MASK                (0x3FU)









#endif // __DW3000_REGS_H__



