#ifndef __DW3000_TYPES_H__
#define __DW3000_TYPES_H__

#include <stdint.h>
#include <dw3000_regs.h>

typedef enum {
    DW3000_RET_OK = 0,
    DW3000_RET_NOT_OK = 1,
} dw3000_ret_t;

typedef enum {
    DW3000_SW_ON = 1,
    DW3000_SW_OFF = 0,
} dw3000_sw_t;

typedef enum {
    DW3000_RF_CHANNEL_5 = 0,
    DW3000_RF_CHANNEL_9 = 1,
} dw3000_rf_channel_t;

typedef enum {
    DW3000_PREAMBLE_16MHZ_PRF_CODE_3 = 0,
    DW3000_PREAMBLE_16MHZ_PRF_CODE_4 = 1,
    DW3000_PREAMBLE_64MHZ_PRF_CODE_9 = 2,
    DW3000_PREAMBLE_64MHZ_PRF_CODE_10 = 3,
    DW3000_PREAMBLE_64MHZ_PRF_CODE_11 = 4,
    DW3000_PREAMBLE_64MHZ_PRF_CODE_12 = 5,
} dw3000_preamble_code_t;

typedef enum {
    DW3000_DATA_RATE_850KBPS = 0,
    DW3000_DATA_RATE_6810KBPS = 1,
} dw3000_data_rate_t;

typedef enum {
    DW3000_PHR_MODE_STD = 0,
    DW3000_PHR_MODE_EXT = 1,
} dw3000_phr_mode_t;

typedef enum {
    DW3000_SPC_SP0 = 0,
    DW3000_SPC_SP1 = 1,
    DW3000_SPC_SP2 = 2,
    DW3000_SPC_SP3 = 3,
} dw3000_sts_pkt_cfg_t;

typedef enum {
    DW3000_PDOA_MODE_NONE = 0x00,
    DW3000_PDOA_MODE_1 = 0x01,
    DW3000_PDOA_MODE_RSV = 0x02,
    DW3000_PDOA_MODE_3 = 0x03,
} dw3000_pdoa_mode_t;



/////////////////////////////////////


typedef union {
    uint32_t raw;
    struct {
        uint8_t rev:4;      // Bits 0-3: REV
        uint8_t ver:4;      // Bits 4-7: VER
        uint8_t model:8;    // Bits 8-15: MODEL
        uint16_t ridtag:16; // Bits 16-31: RIDTAG
    } __attribute__((packed)) fields;
} dw3000_reg_dev_id_t;


typedef union {
    uint32_t raw;
    struct {
        uint16_t shortaddr;  // Bits 0-15: SHORTADDR
        uint16_t pan_id;     // Bits 16-31: PAN_ID
    } __attribute__((packed)) fields;
} dw3000_reg_panadr_t;

typedef uint64_t dw3000_reg_eui_64_t;

typedef union {
    uint32_t raw;
    struct {
        uint8_t ffen:1;         // Bit 0
        uint8_t dis_fcs_tx:1;   // Bit 1
        uint8_t dis_fce:1;      // Bit 2
        uint8_t dis_drxb:1;     // Bit 3
        uint8_t phr_mode:1;     // Bit 4
        uint8_t phr_6m8:1;      // Bit 5
        uint8_t spi_crcen:1;    // Bit 6
        uint8_t cia_ipatov:1;   // Bit 7
        uint8_t cia_sts:1;      // Bit 8
        uint8_t rxwtoe:1;       // Bit 9
        uint8_t rxautr:1;       // Bit 10
        uint8_t auto_ack:1;     // Bit 11
        uint8_t cp_spc:2;       // Bits 12-13
        uint8_t :1;             // Bit 14 (Reserved)
        uint8_t cp_sdc:1;       // Bit 15
        uint8_t pdoa_mode:2;    // Bits 16-17
        uint8_t fast_aat:1;     // Bit 18
        uint16_t :13;           // Bits 19-31 (Reserved) - Changed to uint16_t
    } __attribute__((packed)) fields;
} dw3000_reg_sys_cfg_t;



typedef union {
    uint16_t raw;
    struct {
        uint8_t ffab:1;      // Bit 0
        uint8_t ffad:1;     // Bit 1
        uint8_t ffaa:1;     // Bit 2
        uint8_t ffam:1;     // Bit 3
        uint8_t ffar:1;     // Bit 4
        uint8_t ffamulti:1; // Bit 5
        uint8_t ffaf:1;     // Bit 6
        uint8_t ffae:1;     // Bit 7
        uint8_t ffbc:1;     // Bit 8
        uint8_t ffib:1;     // Bit 9
        uint8_t le0_pend:1; // Bit 10
        uint8_t le1_pend:1; // Bit 11
        uint8_t le2_pend:1; // Bit 12
        uint8_t le3_pend:1; // Bit 13
        uint8_t ssadrape:1; // Bit 14
        uint8_t lsadrape:1; // Bit 15
    } __attribute__((packed)) fields;
} dw3000_reg_ff_cfg_t;


typedef uint8_t dw3000_reg_spi_rd_crc_t;

typedef uint32_t dw3000_reg_sys_time_t;


typedef union {
    struct {
        // Octets 0 to 3 (32 bits)
        uint16_t txflen:10;     // Bits 0-9: TXFLEN
        uint8_t txbr:1;         // Bit 10: TXBR
        uint8_t tr:1;           // Bit 11: TR
        uint8_t txpsr:4;        // Bits 12-15: TXPSR
        uint16_t txb_offset:10; // Bits 16-25: TXB_OFFSET
        uint16_t :14;           // Bits 26-31 + next Bits 0-7 (Reserved)
        uint8_t fine_plen:8;    // next Bits 8-15: FINE_LEN
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_0_TX_FCTRL_LEN];
} dw3000_reg_tx_fctrl_t;

//TODO: Check if this is correct
typedef union {
    uint8_t raw[DW3000_REG_0_DX_TIME_LEN];
} dw3000_reg_dx_time_t;

//TODO: Check if this is correct
typedef union {
    uint8_t raw[DW3000_REG_0_DREF_TIME_LEN];
} dw3000_reg_dref_time_t;

//TODO: Check if this is correct
typedef union {
    uint8_t raw[DW3000_REG_0_RX_FWTO_LEN];
} dw3000_reg_rx_fwto_t;

//TODO: Check if this is correct
typedef union {
    uint8_t raw[DW3000_REG_0_SYS_CTRL_LEN];
} dw3000_reg_sys_ctrl_t;

//TODO: Check if this is correct
typedef union {
    struct {
        uint16_t :1;                     // Bit 0 (Reserved)
        uint16_t cplock_en:1;            // Bit 1
        uint16_t spicrce_en:1;           // Bit 2
        uint16_t aat_en:1;               // Bit 3
        uint16_t txfrb_en:1;             // Bit 4
        uint16_t txprs_en:1;             // Bit 5
        uint16_t txphs_en:1;             // Bit 6
        uint16_t txfrs_en:1;             // Bit 7
        uint16_t rxprd_en:1;             // Bit 8
        uint16_t rxsfdd_en:1;            // Bit 9
        uint16_t ciadone_en:1;           // Bit 10
        uint16_t rxphd_en:1;             // Bit 11
        uint16_t rxphe_en:1;             // Bit 12
        uint16_t rxfr_en:1;              // Bit 13
        uint16_t rxfcg_en:1;             // Bit 14
        uint16_t rxfce_en:1;             // Bit 15
        uint16_t rxrfsl_en:1;            // Bit 16
        uint16_t rxfto_en:1;             // Bit 17
        uint16_t ciaerr_en:1;            // Bit 18
        uint16_t vwarn_en:1;             // Bit 19
        uint16_t rxovrr_en:1;            // Bit 20
        uint16_t rxpto_en:1;             // Bit 21
        uint16_t :1;                     // Bit 22 (Reserved)
        uint16_t spirdy_en:1;            // Bit 23
        uint16_t rcinit_en:1;            // Bit 24
        uint16_t pll_hilo_en:1;          // Bit 25
        uint16_t rxsto_en:1;             // Bit 26
        uint16_t hpdwarn_en:1;           // Bit 27
        uint16_t cperr_en:1;             // Bit 28
        uint16_t arfe_en:1;              // Bit 29
        uint16_t :3;                     // Bits 30-31 + next Bit 0 (Reserved)
        uint16_t rxprej_en:1;            // next Bit 1
        uint16_t :2;                     // next Bits 2-3 (Reserved)
        uint16_t vt_det_en:1;            // next Bit 4
        uint16_t gpioiron_en:1;          // next Bit 5
        uint16_t aes_done_en:1;          // next Bit 6
        uint16_t aes_err_en:1;           // next Bit 7
        uint16_t cmd_err_en:1;           // next Bit 8
        uint16_t spi_ovr_en:1;           // next Bit 9
        uint16_t spi_unf_en:1;           // next Bit 10
        uint16_t spierr_en:1;            // next Bit 11
        uint16_t cca_fail_en:1;          // next Bit 12
        uint16_t :3;                     // next Bits 13-15 (not used)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_0_SYS_ENABLE_LEN];
} dw3000_reg_sys_enable_t;


typedef union {
    struct {
        uint16_t irqs       : 1;  // Bit 0
        uint16_t cplock     : 1;  // Bit 1
        uint16_t spicrce    : 1;  // Bit 2
        uint16_t aat        : 1;  // Bit 3
        uint16_t txfrb      : 1;  // Bit 4
        uint16_t txprs      : 1;  // Bit 5
        uint16_t txphs      : 1;  // Bit 6
        uint16_t txfrs      : 1;  // Bit 7
        uint16_t rxprd      : 1;  // Bit 8
        uint16_t rxsfdd     : 1;  // Bit 9
        uint16_t ciadone    : 1;  // Bit 10
        uint16_t rxphd      : 1;  // Bit 11
        uint16_t rxphe      : 1;  // Bit 12
        uint16_t rxfr       : 1;  // Bit 13
        uint16_t rxfcg      : 1;  // Bit 14
        uint16_t rxfce      : 1;  // Bit 15
        uint16_t rxrfsl     : 1;  // Bit 16
        uint16_t rxfto      : 1;  // Bit 17
        uint16_t ciaerr     : 1;  // Bit 18
        uint16_t vwarn      : 1;  // Bit 19
        uint16_t rxovrr     : 1;  // Bit 20
        uint16_t rxpto      : 1;  // Bit 21
        uint16_t            : 1;  // Bit 22  
        uint16_t spirdy     : 1;  // Bit 23
        uint16_t rcinit     : 1;  // Bit 24
        uint16_t pllhilo    : 1;  // Bit 25
        uint16_t rxsto      : 1;  // Bit 26
        uint16_t hpdwarn    : 1;  // Bit 27
        uint16_t cperr      : 1;  // Bit 28
        uint16_t arfe       : 1;  // Bit 29
        uint16_t            : 3;  // Bits 30-31 + next Bit 0 (Reserved)
        uint16_t rxprej     : 1;  // next Bit 1
        uint16_t            : 2;  // next Bits 2-3 (Reserved)
        uint16_t vt_det     : 1;  // next Bit 4
        uint16_t gpioirq    : 1;  // next Bit 5
        uint16_t aes_done   : 1;  // next Bit 6
        uint16_t aes_err    : 1;  // next Bit 7
        uint16_t cmd_err    : 1;  // next Bit 8
        uint16_t spi_ovr    : 1;  // next Bit 9
        uint16_t spi_unf    : 1;  // next Bit 10
        uint16_t spierr     : 1;  // next Bit 11
        uint16_t cca_fail   : 1;  // next Bit 12
        uint16_t            : 3;  // next Bits 13-15 (not used)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_0_SYS_STATUS_LEN]; 
} dw3000_reg_sys_status_t;


typedef union {
    struct {
        uint16_t rxflen:10; // Bits 0-9
        uint8_t :1;         // Bit 10 (Reserved)
        uint8_t rxnspl:2;   // Bits 11-12
        uint8_t rxbr:1;     // Bit 13
        uint8_t :1;         // Bit 14 (Reserved)
        uint8_t rng:1;      // Bit 15
        uint8_t rxprf:2;    // Bits 16-17
        uint8_t rxpsr:2;    // Bits 18-19
        uint16_t rxpacc:12; // Bits 20-31
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_0_RX_FINFO_LEN]; 
} dw3000_reg_rx_finfo_t;


typedef union {
    struct {
        uint64_t rx_stamp:40; // p1 Bits 0-31 + p2 Bits 0-7
        uint32_t :24;         // p2 Bits 8-31 (not used)
        uint32_t rx_rawst:32; // p3 Bits 0-31
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_0_RX_TIME_LEN]; 
} dw3000_reg_rx_time_t;

typedef union {
    struct {
        uint64_t tx_stamp:40; // p1 Bits 0-31 + p2 Bits 0-7
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_0_TX_TIME_LEN]; 
} dw3000_reg_tx_time_t;


typedef uint32_t dw3000_reg_tx_rawst_t;

typedef uint16_t dw3000_reg_tx_antd_t;

typedef union {
    struct {
        uint32_t w4r_tim:20; // Bits 0-19
        uint8_t :4;          // Bits 20-23 (Reserved)
        uint8_t ack_tim:8;   // Bits 24-31
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_ACK_RESP_T_LEN]; 
} dw3000_reg_ack_resp_t_t;

typedef union {
    struct {
        uint8_t data_pwr:8; // Bits 0-7
        uint8_t phr_pwr:8;  // Bits 8-15
        uint8_t shr_pwr:8;  // Bits 16-23
        uint8_t sts_pwr:8;  // Bits 24-31
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_TX_POWER_LEN]; 
} dw3000_reg_tx_power_t;

typedef union {
    struct {
        uint8_t rf_chan:1;  // Bit 0
        uint8_t sfd_type:2; // Bits 1-2
        uint8_t tx_pcode:5; // Bits 3-7
        uint8_t rx_pcode:5; // Bits 8-12
        uint8_t :3;         // Bits 13-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_CHAN_CTRL_LEN]; 
} dw3000_reg_chan_ctrl_t;


typedef union {
    struct {
        uint16_t le_addr0:16; // Bits 0-15
        uint16_t le_addr1:16; // Bits 16-31
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_LE_PEND_01_LEN]; 
} dw3000_reg_le_pend_01_t;


typedef union {
    struct {
        uint16_t le_addr2:16; // Bits 0-15
        uint16_t le_addr3:16; // Bits 16-31
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_LE_PEND_23_LEN]; 
} dw3000_reg_le_pend_23_t;


typedef union {
    struct {
        uint8_t spi_collision:5; // Bits 0-4
        uint8_t :3;              // Bits 5-7 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_SPI_COLLISION_LEN]; 
} dw3000_reg_spi_collision_t;


typedef union {
    struct {
        uint8_t rxfcg0:1;   // Bit 0
        uint8_t rxfr0:1;    // Bit 1
        uint8_t ciadone0:1; // Bit 2
        uint8_t cp_err0:1;  // Bit 3
        uint8_t rxfcg1:1;   // Bit 4
        uint8_t rxfr1:1;    // Bit 5
        uint8_t ciadone1:1; // Bit 6
        uint8_t cp_err1:1;  // Bit 7
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_RDB_STATUS_LEN]; 
} dw3000_reg_rdb_status_t;


typedef union {
    struct {
        uint8_t rdb_dmode:3; // Bits 0-2
        uint8_t :5;          // Bits 3-7 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_RDB_DIAG_LEN]; 
} dw3000_reg_rdb_diag_t;


typedef union {
    struct {
        uint8_t mode:1;     // Bit 0
        uint8_t key_size:2; // Bits 1-2
        uint8_t key_addr:3; // Bits 3-5
        uint8_t key_load:1; // Bit 6
        uint8_t key_src:1;  // Bit 7
        uint8_t tag_size:3; // Bits 8-10
        uint8_t core_sel:1; // Bit 11
        uint8_t key_otp:1;  // Bit 12
        uint8_t :3;         // Bits 13-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_AES_CFG_LEN]; 
} dw3000_reg_aes_cfg_t;

typedef uint8_t dw3000_reg_aes_iv0_t[DW3000_REG_1_AES_IV0_LEN];
typedef uint8_t dw3000_reg_aes_iv1_t[DW3000_REG_1_AES_IV1_LEN];
typedef uint8_t dw3000_reg_aes_iv2_t[DW3000_REG_1_AES_IV2_LEN];
typedef uint8_t dw3000_reg_aes_iv3_t[DW3000_REG_1_AES_IV3_LEN];
typedef uint8_t dw3000_reg_aes_iv4_t[DW3000_REG_1_AES_IV4_LEN];

typedef union {
    struct {
        uint8_t src_port:3;         // p1 Bits 0-2
        uint16_t src_addr:10;       // p1 Bits 3-12
        uint8_t dst_port:3;         // p1 Bits 13-15
        uint16_t dst_addr:10;       // p1 Bits 16-25
        uint8_t cp_end_sel:1;       // p1 Bit 26
        uint8_t :5;                 // p1 Bits 27-31 (Reserved)
        uint8_t hdr_size:7;         // p2 Bits 0-6
        uint16_t pyld_size:10;      // p2 Bits 7-16
        uint8_t :7;                 // p2 Bits 17-23 (Reserved)
        uint8_t :8;                 // p2 Bits 24-31 (Not used)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_DMA_CFG_LEN]; 
} dw3000_reg_dma_cfg_t;

typedef union {
    struct {
        uint8_t aes_start:1; //Bit 0
        uint8_t :7;          //Bits 1-7 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_AES_START_LEN];
} dw3000_reg_aes_start_t;

typedef union {
    struct {
        uint8_t aes_done:1;     //Bit 0
        uint8_t auth_err:1;     //Bit 1
        uint8_t trans_err:1;    //Bit 2
        uint8_t mem_conf:1;     //Bit 3
        uint8_t ram_empty:1;    //Bit 4
        uint8_t ram_full:1;     //Bit 5
        uint8_t :2;             //Bits 6-7 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_1_AES_STS_LEN];
} dw3000_reg_aes_sts_t;

typedef uint8_t dw3000_reg_aes_key_t[DW3000_REG_1_AES_KEY_LEN];


typedef union {
    struct {
        uint8_t cps_len:8; // Bits 0-7
        uint8_t :8;        // Bits 8-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_2_STS_CFG_LEN];
} dw3000_reg_sts_cfg_t;

typedef union {
    struct {
        uint8_t load_iv:1;  // Bit 0
        uint8_t rst_last:1; // Bit 1
        uint8_t :6;         // Bits 2-7 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_2_STS_CTRL_LEN];
} dw3000_reg_sts_ctrl_t;

typedef union {
    struct {
        uint16_t acc_qual:12; // Bits 0-11
        uint8_t :4;           // Bits 12-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_2_STS_STS_LEN];
} dw3000_reg_sts_sts_t;

typedef uint8_t dw3000_reg_sts_key_t[DW3000_REG_2_STS_KEY_LEN];

typedef uint8_t dw3000_reg_sts_iv_t[DW3000_REG_2_STS_IV_LEN];

/******************************************************************************
 * @brief Bit definitions for register page 0x03: RX_TUNE
**/

typedef union {
    struct {
       uint16_t rx_tune:1; // Bit 0
       uint16_t :8;        // Bits 1-8 (Reserved)
       uint16_t thr_64:6;  // Bits 9-14
       uint16_t :1;        // Bit 15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_3_DCG_CFG_LEN];
} dw3000_reg_dcg_cfg_t;

typedef uint8_t dw3000_reg_dgc_cfg0_t[DW3000_REG_3_DGC_CFG0_LEN];
typedef uint8_t dw3000_reg_dgc_cfg1_t[DW3000_REG_3_DGC_CFG1_LEN];

typedef uint8_t dw3000_reg_dgc_lut_0_t[DW3000_REG_3_DGC_LUT_0_LEN];
typedef uint8_t dw3000_reg_dgc_lut_1_t[DW3000_REG_3_DGC_LUT_1_LEN];
typedef uint8_t dw3000_reg_dgc_lut_2_t[DW3000_REG_3_DGC_LUT_2_LEN];
typedef uint8_t dw3000_reg_dgc_lut_3_t[DW3000_REG_3_DGC_LUT_3_LEN];
typedef uint8_t dw3000_reg_dgc_lut_4_t[DW3000_REG_3_DGC_LUT_4_LEN];
typedef uint8_t dw3000_reg_dgc_lut_5_t[DW3000_REG_3_DGC_LUT_5_LEN];
typedef uint8_t dw3000_reg_dgc_lut_6_t[DW3000_REG_3_DGC_LUT_6_LEN];


typedef union {
    struct {
        uint32_t :28;               // Bits 0-27 (Reserved)
        uint8_t dcg_decision:3;     // Bits 28-30
        uint8_t :1;                 // Bit 31 (Not used)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_3_DCG_DBG_LEN];
} dw3000_reg_dcg_dbg_t;


/******************************************************************************
 * @brief Bit definitions for register page 0x04: EXT_SYNC
 * @brief External sync control and RX calibration
**/

typedef union {
    struct {
        uint16_t :3;             // Bits 0-2 (Reserved)
        uint16_t osts_wait:8;    // Bits 3-10
        uint16_t ostr_mode:1;    // Bit 11
        uint32_t :20;               // Bits 12-31 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_4_EC_CTRL_LEN];
} dw3000_reg_ec_ctrl_t;


typedef union {
    struct {
        uint8_t cal_mode:2; // Bits 0-1
        uint8_t :2;         // Bits 2-3 (Reserved)
        uint8_t cal_en:1;   // Bit 4
        uint16_t :11;       // Bits 5-15 (Reserved)
        uint8_t comp_dly:4; // Bits 16-19
        uint16_t :12;       // Bits 20-31 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_4_RX_CAL_LEN];
} dw3000_reg_rx_cal_t;


typedef uint8_t dw3000_reg_rx_cal_resi_t[DW3000_REG_4_RX_CAL_RESI_LEN];
typedef uint8_t dw3000_reg_rx_cal_resq_t[DW3000_REG_4_RX_CAL_RESQ_LEN];
typedef uint8_t dw3000_reg_rx_cal_sts_t[DW3000_REG_4_RX_CAL_STS_LEN];

/******************************************************************************
 * @brief Bit definitions for register page 0x05: GPIO_CTRL
 * @brief GPIO control and status
**/

typedef union {
    struct {
        uint16_t msgp0:3; // Bits 0-2
        uint16_t msgp1:3; // Bits 3-5
        uint16_t msgp2:3; // Bits 6-8
        uint16_t msgp3:3; // Bits 9-11
        uint16_t msgp4:3; // Bits 12-14
        uint16_t msgp5:3; // Bits 15-17
        uint16_t msgp6:3; // Bits 18-20
        uint16_t msgp7:3; // Bits 21-23
        uint16_t msgp8:3; // Bits 24-26
        uint16_t :5;      // Bits 27-31 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_MODE_LEN];
} dw3000_reg_gpio_mode_t;

typedef union {
    struct {
        uint8_t gpen0:1; // Bit 0
        uint8_t gpen1:1; // Bit 1
        uint8_t gpen2:1; // Bit 2
        uint8_t gpen3:1; // Bit 3
        uint8_t gpen4:1; // Bit 4
        uint8_t gpen5:1; // Bit 5
        uint8_t gpen6:1; // Bit 6
        uint8_t gpen7:1; // Bit 7
        uint8_t gpen8:1; // Bit 8
        uint8_t :7;         // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_PULL_EN_LEN];
} dw3000_reg_gpio_pull_en_t;

typedef union {
    struct {
        uint8_t gdp0:1; // Bit 0
        uint8_t gdp1:1; // Bit 1
        uint8_t gdp2:1; // Bit 2
        uint8_t gdp3:1; // Bit 3
        uint8_t gdp4:1; // Bit 4
        uint8_t gdp5:1; // Bit 5
        uint8_t gdp6:1; // Bit 6
        uint8_t gdp7:1; // Bit 7
        uint8_t gdp8:1; // Bit 8
        uint8_t :7;     // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_DIR_LEN];
} dw3000_reg_gpio_dir_t;

typedef union {
    struct {
        uint8_t gop0:1; // Bit 0
        uint8_t gop1:1; // Bit 1
        uint8_t gop2:1; // Bit 2
        uint8_t gop3:1; // Bit 3
        uint8_t gop4:1; // Bit 4
        uint8_t gop5:1; // Bit 5
        uint8_t gop6:1; // Bit 6
        uint8_t gop7:1; // Bit 7
        uint8_t gop8:1; // Bit 8
        uint8_t :7;     // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_OUT_LEN];
} dw3000_reg_gpio_out_t;

typedef union {
    struct {
        uint8_t girqe0:1; // Bit 0
        uint8_t girqe1:1; // Bit 1
        uint8_t girqe2:1; // Bit 2
        uint8_t girqe3:1; // Bit 3
        uint8_t girqe4:1; // Bit 4
        uint8_t girqe5:1; // Bit 5
        uint8_t girqe6:1; // Bit 6
        uint8_t girqe7:1; // Bit 7
        uint8_t girqe8:1; // Bit 8
        uint8_t :7;    // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_IRQE_LEN];
} dw3000_reg_gpio_irqe_t;

typedef union {
    struct {
        uint8_t gists0:1; // Bit 0
        uint8_t gists1:1; // Bit 1
        uint8_t gists2:1; // Bit 2
        uint8_t gists3:1; // Bit 3
        uint8_t gists4:1; // Bit 4
        uint8_t gists5:1; // Bit 5
        uint8_t gists6:1; // Bit 6
        uint8_t gists7:1; // Bit 7
        uint8_t gists8:1; // Bit 8
        uint8_t :7;    // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_ISTS_LEN];
} dw3000_reg_gpio_ists_t;

typedef union {
    struct {
        uint8_t gisen0:1; // Bit 0
        uint8_t gisen1:1; // Bit 1
        uint8_t gisen2:1; // Bit 2
        uint8_t gisen3:1; // Bit 3
        uint8_t gisen4:1; // Bit 4
        uint8_t gisen5:1; // Bit 5
        uint8_t gisen6:1; // Bit 6
        uint8_t gisen7:1; // Bit 7
        uint8_t gisen8:1; // Bit 8
        uint8_t :7;       // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_ISEN_LEN];
} dw3000_reg_gpio_isen_t;

typedef union {
    struct {
        uint8_t gimod0:1; // Bit 0
        uint8_t gimod1:1; // Bit 1
        uint8_t gimod2:1; // Bit 2
        uint8_t gimod3:1; // Bit 3
        uint8_t gimod4:1; // Bit 4
        uint8_t gimod5:1; // Bit 5
        uint8_t gimod6:1; // Bit 6
        uint8_t gimod7:1; // Bit 7
        uint8_t gimod8:1; // Bit 8
        uint8_t :7;       // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_IMODE_LEN];
} dw3000_reg_gpio_imode_t;

typedef union {
    struct {
        uint8_t gibes0:1; // Bit 0
        uint8_t gibes1:1; // Bit 1
        uint8_t gibes2:1; // Bit 2
        uint8_t gibes3:1; // Bit 3
        uint8_t gibes4:1; // Bit 4
        uint8_t gibes5:1; // Bit 5
        uint8_t gibes6:1; // Bit 6
        uint8_t gibes7:1; // Bit 7
        uint8_t gibes8:1; // Bit 8
        uint8_t :7;       // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_IBES_LEN];
} dw3000_reg_gpio_ibes_t;

typedef union {
    struct {
        uint8_t giclr0:1; // Bit 0
        uint8_t giclr1:1; // Bit 1
        uint8_t giclr2:1; // Bit 2
        uint8_t giclr3:1; // Bit 3
        uint8_t giclr4:1; // Bit 4
        uint8_t giclr5:1; // Bit 5
        uint8_t giclr6:1; // Bit 6
        uint8_t giclr7:1; // Bit 7
        uint8_t giclr8:1; // Bit 8
        uint8_t :7;       // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_ICLR_LEN];
} dw3000_reg_gpio_iclr_t;

typedef union {
    struct {
        uint8_t gidbe0:1; // Bit 0
        uint8_t gidbe1:1; // Bit 1
        uint8_t gidbe2:1; // Bit 2
        uint8_t gidbe3:1; // Bit 3
        uint8_t gidbe4:1; // Bit 4
        uint8_t gidbe5:1; // Bit 5
        uint8_t gidbe6:1; // Bit 6
        uint8_t gidbe7:1; // Bit 7
        uint8_t gidbe8:1; // Bit 8
        uint8_t :7;       // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_IDBE_LEN];
} dw3000_reg_gpio_idbe_t;

typedef union {
    struct {
        uint8_t grawp0:1; // Bit 0
        uint8_t grawp1:1; // Bit 1
        uint8_t grawp2:1; // Bit 2
        uint8_t grawp3:1; // Bit 3
        uint8_t grawp4:1; // Bit 4
        uint8_t grawp5:1; // Bit 5
        uint8_t grawp6:1; // Bit 6
        uint8_t grawp7:1; // Bit 7
        uint8_t grawp8:1; // Bit 8
        uint8_t :7;       // Bits 9-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_5_GPIO_RAW_LEN];
} dw3000_reg_gpio_raw_t;


/******************************************************************************
 * @brief Bit definitions for register page 0x06: DRX_CONF
 * @brief Digital receiver configuration
**/

typedef union {
    struct {
        uint8_t pac:2;       // Bits 0-1
        uint8_t :2;          // Bits 2-3 (Reserved)
        uint8_t dt0b4:1;     // Bit 4
        uint16_t :11;        // Bits 5-15 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_6_DTUNE0_LEN];
} dw3000_reg_dtune0_t;

typedef uint8_t dw3000_reg_rx_sfd_toc_t[DW3000_REG_6_RX_SFD_TOC_LEN];

typedef uint8_t dw3000_reg_pre_toc_t[DW3000_REG_6_PRE_TOC_LEN];

typedef uint8_t dw3000_reg_dtune3_t[DW3000_REG_6_DTUNE3_LEN];

typedef uint8_t dw3000_reg_dtune_5_t[DW3000_REG_6_DTUNE_5_LEN];

typedef uint8_t dw3000_reg_drx_car_int_t[DW3000_REG_6_DRX_CAR_INT_LEN];


/******************************************************************************
 * @brief Bit definitions for register page 0x07: RF_CONF
 * @brief Analog RF configuration block
**/

typedef uint8_t dw3000_reg_rf_enable_t[DW3000_REG_7_RF_ENABLE_LEN];

typedef uint8_t dw3000_reg_rf_ctrl_mask_t[DW3000_REG_7_RF_CTRL_MASK_LEN];

typedef union {
    struct {
        uint8_t antswnotoggle:1; // Bit 0
        uint8_t antswpdoaport:1; // Bit 1
        uint8_t :6;              // Bits 2-7 (Reserved)
        uint8_t antswen:1;       // Bit 8
        uint8_t :3;              // Bits 9-11 (Reserved)
        uint8_t antswctrl:3;     // Bits 12-14
        uint8_t :1;              // Bit 15 (Reserved)
        uint8_t trxswen:1;       // Bit 16
        uint8_t :7;              // Bits 17-23 (Reserved)
        uint8_t trxswctrl:6;     // Bits 24-29
        uint8_t :2;              // Bits 30-31 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_7_RF_SWITCH_LEN];
} dw3000_reg_rf_switch_t;

typedef uint8_t dw3000_reg_rf_tx_ctrl_1_t[DW3000_REG_7_RF_TX_CTRL_1_LEN];

typedef union {
    struct {
        uint8_t pg_delay:6; // Bits 0-5
        uint32_t :26;       // Bits 6-31 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_7_RF_TX_CTRL_2_LEN];
} dw3000_reg_rf_tx_ctrl_2_t;

typedef union {
    struct {
        uint8_t tx_entest:4; // Bits 0-3
        uint8_t :4;          // Bits 4-7 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_7_TX_TEST_LEN];
} dw3000_reg_tx_test_t;

typedef union {
    struct {
        uint8_t :2;          // Bits 0-1 (Reserved)
        uint8_t sar_rden:1;  // Bit 2
        uint8_t :5;          // Bits 3-7 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_7_SAR_TEST_LEN];
} dw3000_reg_sar_test_t;

typedef union {
    struct {
        uint64_t ldo_tune:60; // p1 Bits 0-31 + p2 Bits 0-27
        uint32_t :4;          // p2 Bits 28-31 (Reserved)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_7_LDO_TUNE_LEN];
} dw3000_reg_ldo_tune_t;































































#endif // __DW3000_TYPES_H__