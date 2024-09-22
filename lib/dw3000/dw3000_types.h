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
    uint8_t raw[6]; // Full 6-byte raw data
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
    uint8_t raw[DW3000_REG_0_SYS_ENABLE_LEN]; // Full 6-byte raw data
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
    uint8_t raw[DW3000_REG_0_SYS_STATUS_LEN]; // Full 6-byte raw data
} dw3000_reg_sys_status_t;


















#endif // __DW3000_TYPES_H__