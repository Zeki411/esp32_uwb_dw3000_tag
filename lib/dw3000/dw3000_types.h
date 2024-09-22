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


typedef union {
    struct {
        uint8_t :1;                     // Bit 0 (Reserved)
        uint8_t cplock_en:1;            // Bit 1
        uint8_t spicrce_en:1;           // Bit 2
        uint8_t aat_en:1;               // Bit 3
        uint8_t txfrb_en:1;             // Bit 4
        uint8_t txprs_en:1;             // Bit 5
        uint8_t txphs_en:1;             // Bit 6
        uint8_t txfrs_en:1;             // Bit 7
        uint8_t rxprd_en:1;             // Bit 8
        uint8_t rxsfdd_en:1;            // Bit 9
        uint8_t ciadone_en:1;           // Bit 10
        uint8_t rxphd_en:1;             // Bit 11
        uint8_t rxphe_en:1;             // Bit 12
        uint8_t rxfr_en:1;              // Bit 13
        uint8_t rxfcg_en:1;             // Bit 14
        uint8_t rxfce_en:1;             // Bit 15
        uint8_t rxrfsl_en:1;            // Bit 16
        uint8_t rxfto_en:1;             // Bit 17
        uint8_t ciaerr_en:1;            // Bit 18
        uint8_t vwarn_en:1;             // Bit 19
        uint8_t rxovrr_en:1;            // Bit 20
        uint8_t rxpto_en:1;             // Bit 21
        uint8_t :1;                     // Bit 22 (Reserved)
        uint8_t spirdy_en:1;            // Bit 23
        uint8_t rcinit_en:1;            // Bit 24
        uint8_t pll_hilo_en:1;          // Bit 25
        uint8_t rxsto_en:1;             // Bit 26
        uint8_t hpdwarn_en:1;           // Bit 27
        uint8_t cperr_en:1;             // Bit 28
        uint8_t arfe_en:1;              // Bit 29
        uint8_t :3;                     // Bits 30-31 + next Bit 0 (Reserved)
        uint8_t rxprej_en:1;            // next Bit 1
        uint8_t :2;                     // next Bits 2-3 (Reserved)
        uint8_t vt_det_en:1;            // next Bit 4
        uint8_t gpioiron_en:1;          // next Bit 5
        uint8_t aes_done_en:1;          // next Bit 6
        uint8_t aes_err_en:1;           // next Bit 7
        uint8_t cmd_err_en:1;           // next Bit 8
        uint8_t spi_ovr_en:1;           // next Bit 9
        uint8_t spi_unf_en:1;           // next Bit 10
        uint8_t spierr_en:1;            // next Bit 11
        uint8_t cca_fail_en:1;          // next Bit 12
        uint8_t :3;                     // next Bits 13-15 (not used)
    } __attribute__((packed)) fields;
    uint8_t raw[DW3000_REG_0_SYS_ENABLE_LEN];
} dw3000_reg_sys_enable_t;


typedef union {
    struct {
        uint8_t irqs       : 1;  // Bit 0
        uint8_t cplock     : 1;  // Bit 1
        uint8_t spicrce    : 1;  // Bit 2
        uint8_t aat        : 1;  // Bit 3
        uint8_t txfrb      : 1;  // Bit 4
        uint8_t txprs      : 1;  // Bit 5
        uint8_t txphs      : 1;  // Bit 6
        uint8_t txfrs      : 1;  // Bit 7
        uint8_t rxprd      : 1;  // Bit 8
        uint8_t rxsfdd     : 1;  // Bit 9
        uint8_t ciadone    : 1;  // Bit 10
        uint8_t rxphd      : 1;  // Bit 11
        uint8_t rxphe      : 1;  // Bit 12
        uint8_t rxfr       : 1;  // Bit 13
        uint8_t rxfcg      : 1;  // Bit 14
        uint8_t rxfce      : 1;  // Bit 15
        uint8_t rxrfsl     : 1;  // Bit 16
        uint8_t rxfto      : 1;  // Bit 17
        uint8_t ciaerr     : 1;  // Bit 18
        uint8_t vwarn      : 1;  // Bit 19
        uint8_t rxovrr     : 1;  // Bit 20
        uint8_t rxpto      : 1;  // Bit 21
        uint8_t            : 1;  // Bit 22  
        uint8_t spirdy     : 1;  // Bit 23
        uint8_t rcinit     : 1;  // Bit 24
        uint8_t pllhilo    : 1;  // Bit 25
        uint8_t rxsto      : 1;  // Bit 26
        uint8_t hpdwarn    : 1;  // Bit 27
        uint8_t cperr      : 1;  // Bit 28
        uint8_t arfe       : 1;  // Bit 29
        uint8_t            : 3;  // Bits 30-31 + next Bit 0 (Reserved)
        uint8_t rxprej     : 1;  // next Bit 1
        uint8_t            : 2;  // next Bits 2-3 (Reserved)
        uint8_t vt_det     : 1;  // next Bit 4
        uint8_t gpioirq    : 1;  // next Bit 5
        uint8_t aes_done   : 1;  // next Bit 6
        uint8_t aes_err    : 1;  // next Bit 7
        uint8_t cmd_err    : 1;  // next Bit 8
        uint8_t spi_ovr    : 1;  // next Bit 9
        uint8_t spi_unf    : 1;  // next Bit 10
        uint8_t spierr     : 1;  // next Bit 11
        uint8_t cca_fail   : 1;  // next Bit 12
        uint8_t            : 3;  // next Bits 13-15 (not used)
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
        uint8_t src_port:3;     // p1 Bits 0-2
        uint8_t src_addr:10;    // p1 Bits 3-12
        uint8_t dst_port:3;     // p1 Bits 13-15
        uint8_t dst_addr:10;    // p1 Bits 16-25
        uint8_t cp_end_sel:1;   // p1 Bit 26
        uint8_t :5;             // p1 Bits 27-31 (Reserved)
        uint8_t hdr_size:7;     // p2 Bits 0-6
        uint8_t pyld_size:10;   // p2 Bits 7-16
        uint8_t :7;             // p2 Bits 17-23 (Reserved)
        uint8_t :8;             // p2 Bits 24-31 (Not used)
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














































#endif // __DW3000_TYPES_H__