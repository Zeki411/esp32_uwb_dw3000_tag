#ifndef __DW3000_TYPES_H__
#define __DW3000_TYPES_H__

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


typedef struct {
    dw3000_sw_t frame_filter_en;
    dw3000_sw_t auto_frame_check_seq_en;
    dw3000_sw_t frame_check_err_en;
    dw3000_sw_t double_rx_buf_en;
    dw3000_phr_mode_t phr_mode;
    dw3000_sw_t phr_6m8_en;
    dw3000_sw_t spi_crc_en;
    dw3000_sw_t cia_ipatov_en;
    dw3000_sw_t cia_sts;
    dw3000_sw_t rx_wait_timeout_en;
    dw3000_sw_t rx_auto_reenable_en;
    dw3000_sw_t auto_ack_en;
    dw3000_sts_pkt_cfg_t sts_pkt_cfg;
    dw3000_sw_t super_det_code_en;
    dw3000_pdoa_mode_t pdoa_mode;
    dw3000_sw_t fast_rx_to_tx_en;
} dw3000_sys_cfg_t;

typedef struct {
    dw3000_sw_t ff_allow_beacon_rx_en;
    dw3000_sw_t ff_allow_data_rx_en;
    dw3000_sw_t ff_allow_ack_rx_en;
    dw3000_sw_t ff_allow_mac_cmd_rx_en;
    dw3000_sw_t ff_allow_reserved_rx_en;
    dw3000_sw_t ff_allow_mu
} dw3000_frame_filter_cfg_t;






typedef struct {
    dw3000_rf_channel_t rf_channel;
    dw3000_preamble_code_t preamble_code;
    dw3000_data_rate_t data_rate;
} dw3000_tx_cfg_t;

typedef struct {
    dw3000_rf_channel_t rf_channel;
    dw3000_preamble_code_t preamble_code;
    dw3000_data_rate_t data_rate;
} dw3000_rx_cfg_t;



#endif // __DW3000_TYPES_H__