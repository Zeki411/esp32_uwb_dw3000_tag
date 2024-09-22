#include <Arduino.h>
#include "dw3000.h"

DW3000 dw3000;

void test_dev_id_reg(){
    dw3000_reg_dev_id_t reg_data;
    dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_DEV_ID_OFFSET, (uint8_t*)&reg_data, DW3000_REG_0_DEV_ID_LEN);
    Serial.printf("Device ID: 0x%08X\n", reg_data.raw);
    Serial.printf("RIDTAG: 0x%04X\n", reg_data.fields.ridtag);
    Serial.printf("Model: 0x%02X\n", reg_data.fields.model);
    Serial.printf("Version: 0x%02X\n", reg_data.fields.ver);
    Serial.printf("Revision: 0x%02X\n", reg_data.fields.rev);
    Serial.println();
}

void test_panadr_reg(){
    dw3000_reg_panadr_t w_data = {0};
    dw3000_reg_panadr_t r_data = {0};
    w_data.fields.shortaddr = 0x1234;
    w_data.fields.pan_id = 0x5678;
    Serial.printf("Write to PANADR register\n");
    dw3000.write_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_PANADR_OFFSET, (uint8_t*)&w_data, DW3000_REG_0_PANADR_LEN);
    Serial.printf("Read from PANADR register\n");
    dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_PANADR_OFFSET, (uint8_t*)&r_data, DW3000_REG_0_PANADR_LEN);
    Serial.printf("Short Address: 0x%04X\n", r_data.fields.shortaddr);
    Serial.printf("PAN ID: 0x%04X\n", r_data.fields.pan_id);
    Serial.println();
}

void test_sys_cfg_reg() {
    dw3000_reg_sys_cfg_t w_data = {0};
    dw3000_reg_sys_cfg_t r_data = {0};
    Serial.println();
    w_data.fields.ffen = 0x00;
    w_data.fields.dis_fcs_tx = 0x00;
    w_data.fields.dis_fce = 0x00;
    w_data.fields.dis_drxb = 0x01;
    w_data.fields.phr_mode = 0x00;
    w_data.fields.phr_6m8 = 0x00;
    w_data.fields.spi_crcen = 0x00;
    w_data.fields.cia_ipatov = 0x01;
    w_data.fields.cia_sts = 0x01;
    w_data.fields.rxwtoe = 0x00;
    w_data.fields.rxautr = 0x00;
    w_data.fields.auto_ack = 0x00;
    w_data.fields.cp_spc = 0x00;
    w_data.fields.cp_sdc = 0x00;
    w_data.fields.pdoa_mode = 0x00;
    w_data.fields.fast_aat = 0x00;
    Serial.printf("Write to SYS_CFG register\n");
    dw3000.write_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_SYS_CFG_OFFSET, (uint8_t*)&w_data, DW3000_REG_0_SYS_CFG_LEN);
    delay(100);
    Serial.printf("Read from SYS_CFG register\n");
    dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_SYS_CFG_OFFSET, (uint8_t*)&r_data, DW3000_REG_0_SYS_CFG_LEN);
    Serial.printf("SYS_CFG: 0x%08X\n", r_data.raw);
    Serial.printf("FFEN: 0x%02X\n", r_data.fields.ffen);
    Serial.printf("DIS_FCS_TX: 0x%02X\n", r_data.fields.dis_fcs_tx);
    Serial.printf("DIS_FCE: 0x%02X\n", r_data.fields.dis_fce);
    Serial.printf("DIS_DRXB: 0x%02X\n", r_data.fields.dis_drxb);
    Serial.printf("PHR_MODE: 0x%02X\n", r_data.fields.phr_mode);
    Serial.printf("PHR_6M8: 0x%02X\n", r_data.fields.phr_6m8);
    Serial.printf("SPI_CRCEN: 0x%02X\n", r_data.fields.spi_crcen);
    Serial.printf("CIA_IPATOV: 0x%02X\n", r_data.fields.cia_ipatov);
    Serial.printf("CIA_STS: 0x%02X\n", r_data.fields.cia_sts);
    Serial.printf("RXWTOE: 0x%02X\n", r_data.fields.rxwtoe);
    Serial.printf("RXAUTR: 0x%02X\n", r_data.fields.rxautr);
    Serial.printf("AUTO_ACK: 0x%02X\n", r_data.fields.auto_ack);
    Serial.printf("CP_SPC: 0x%02X\n", r_data.fields.cp_spc);
    Serial.printf("CP_SDC: 0x%02X\n", r_data.fields.cp_sdc);
    Serial.printf("PDOA_MODE: 0x%02X\n", r_data.fields.pdoa_mode);
    Serial.printf("FAST_AAT: 0x%02X\n", r_data.fields.fast_aat);
    Serial.println();
}

void test_reg_ff_cfg(){
    dw3000_reg_ff_cfg_t r_data = {0};
    Serial.println();
    Serial.printf("Read from FF_CFG register\n");
    dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_FF_CFG_OFFSET, (uint8_t*)&r_data, DW3000_REG_0_FF_CFG_LEN);
    Serial.printf("FF_CFG: 0x%04X\n", r_data.raw);
    Serial.printf("FFAB: 0x%02X\n", r_data.fields.ffab);
    Serial.printf("FFAD: 0x%02X\n", r_data.fields.ffad);
    Serial.printf("FFAA: 0x%02X\n", r_data.fields.ffaa);
    Serial.printf("FFAM: 0x%02X\n", r_data.fields.ffam);
    Serial.printf("FFAR: 0x%02X\n", r_data.fields.ffar);
    Serial.printf("FFAMULTI: 0x%02X\n", r_data.fields.ffamulti);
    Serial.printf("FFAF: 0x%02X\n", r_data.fields.ffaf);
    Serial.printf("FFAE: 0x%02X\n", r_data.fields.ffae);
    Serial.printf("FFBC: 0x%02X\n", r_data.fields.ffbc);
    Serial.printf("FFIB: 0x%02X\n", r_data.fields.ffib);
    Serial.printf("LE0_PEND: 0x%02X\n", r_data.fields.le0_pend);
    Serial.printf("LE1_PEND: 0x%02X\n", r_data.fields.le1_pend);
    Serial.printf("LE2_PEND: 0x%02X\n", r_data.fields.le2_pend);
    Serial.printf("LE3_PEND: 0x%02X\n", r_data.fields.le3_pend);
    Serial.printf("SSADRAPE: 0x%02X\n", r_data.fields.ssadrape);
    Serial.printf("LSADRAPE: 0x%02X\n", r_data.fields.lsadrape);
}

void test_reg_tx_fctrl() {
    dw3000_reg_tx_fctrl_t r_data = {0};
    dw3000_reg_tx_fctrl_t w_data = {0};
    Serial.println();
    Serial.printf("Write to TX_FCTRL register\n");
    w_data.fields.txflen = 0x000C;
    w_data.fields.txbr = 0x01;
    w_data.fields.tr = 0x01;
    w_data.fields.txpsr = 0x01;
    w_data.fields.txb_offset = 0x03FF;
    w_data.fields.fine_plen = 0x00;
    dw3000.write_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_TX_FCTRL_OFFSET, (uint8_t*)&w_data.raw, DW3000_REG_0_TX_FCTRL_LEN);
    delay(100);
    Serial.printf("Read from TX_FCTRL register\n");
    dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_TX_FCTRL_OFFSET, (uint8_t*)&r_data.raw, DW3000_REG_0_TX_FCTRL_LEN);
    Serial.printf("TX_FCTRL: ");
    for(int i = 0; i < DW3000_REG_0_TX_FCTRL_LEN; i++){
        Serial.printf(" 0x%02X ", r_data.raw[i]);
    }
    Serial.println();

    Serial.printf("TXFLEN: 0x%04X\n", r_data.fields.txflen);
    Serial.printf("TXBR: 0x%02X\n", r_data.fields.txbr);
    Serial.printf("TR: 0x%02X\n", r_data.fields.tr);
    Serial.printf("TXPSR: 0x%02X\n", r_data.fields.txpsr);
    Serial.printf("TXB_OFFSET: 0x%04X\n", r_data.fields.txb_offset);
    Serial.printf("FINE_PLEN: 0x%02X\n", r_data.fields.fine_plen);
}

void test_reg_sys_enable(){
    dw3000_reg_sys_enable_t r_data = {0};
    Serial.println();
    Serial.printf("Read from SYS_ENABLE register\n");
    dw3000.read_full_address(DW3000_REG_0_ADDR, DW3000_REG_0_SYS_ENABLE_OFFSET, (uint8_t*)&r_data.raw, DW3000_REG_0_SYS_ENABLE_LEN);
    Serial.printf("SYS_ENABLE: ");
    for(int i = 0; i < DW3000_REG_0_SYS_ENABLE_LEN; i++){
        Serial.printf(" 0x%02X ", r_data.raw[i]);
    }

    //print fields with name in high case
    Serial.printf("CPLOCK_EN: 0x%02X\n", r_data.fields.cplock_en);
    Serial.printf("SPICRCE_EN: 0x%02X\n", r_data.fields.spicrce_en);
    Serial.printf("AAT_EN: 0x%02X\n", r_data.fields.aat_en);
    Serial.printf("TXFRB_EN: 0x%02X\n", r_data.fields.txfrb_en);
    Serial.printf("TXPRS_EN: 0x%02X\n", r_data.fields.txprs_en);
    Serial.printf("TXPHS_EN: 0x%02X\n", r_data.fields.txphs_en);
    Serial.printf("TXFRS_EN: 0x%02X\n", r_data.fields.txfrs_en);
    Serial.printf("RXPRD_EN: 0x%02X\n", r_data.fields.rxprd_en);
    Serial.printf("RXSFDD_EN: 0x%02X\n", r_data.fields.rxsfdd_en);
    Serial.printf("CIADONE_EN: 0x%02X\n", r_data.fields.ciadone_en);
    Serial.printf("RXPHD_EN: 0x%02X\n", r_data.fields.rxphd_en);
    Serial.printf("RXPHE_EN: 0x%02X\n", r_data.fields.rxphe_en);
    Serial.printf("RXFR_EN: 0x%02X\n", r_data.fields.rxfr_en);
    Serial.printf("RXFCG_EN: 0x%02X\n", r_data.fields.rxfcg_en);
    Serial.printf("RXFCE_EN: 0x%02X\n", r_data.fields.rxfce_en);
    Serial.printf("RXRFSL_EN: 0x%02X\n", r_data.fields.rxrfsl_en);
    Serial.printf("RXFTO_EN: 0x%02X\n", r_data.fields.rxfto_en);
    Serial.printf("CIAERR_EN: 0x%02X\n", r_data.fields.ciaerr_en);
    Serial.printf("VWARN_EN: 0x%02X\n", r_data.fields.vwarn_en);
    Serial.printf("RXOVRR_EN: 0x%02X\n", r_data.fields.rxovrr_en);
    Serial.printf("RXPTO_EN: 0x%02X\n", r_data.fields.rxpto_en);
    Serial.printf("SPIRDY_EN: 0x%02X\n", r_data.fields.spirdy_en);
    Serial.printf("RCINIT_EN: 0x%02X\n", r_data.fields.rcinit_en);
    Serial.printf("PLL_HILO_EN: 0x%02X\n", r_data.fields.pll_hilo_en);
    Serial.printf("RXSTO_EN: 0x%02X\n", r_data.fields.rxsto_en);
    Serial.printf("HPDWARN_EN: 0x%02X\n", r_data.fields.hpdwarn_en);
    Serial.printf("CPERR_EN: 0x%02X\n", r_data.fields.cperr_en);
    Serial.printf("ARFE_EN: 0x%02X\n", r_data.fields.arfe_en);
    Serial.printf("RXPREJ_EN: 0x%02X\n", r_data.fields.rxprej_en);
    Serial.printf("VT_DET_EN: 0x%02X\n", r_data.fields.vt_det_en);
    Serial.printf("GPIOIRON_EN: 0x%02X\n", r_data.fields.gpioiron_en);
    Serial.printf("AES_DONE_EN: 0x%02X\n", r_data.fields.aes_done_en);
    Serial.printf("AES_ERR_EN: 0x%02X\n", r_data.fields.aes_err_en);
    Serial.printf("CMD_ERR_EN: 0x%02X\n", r_data.fields.cmd_err_en);
    Serial.printf("SPI_OVR_EN: 0x%02X\n", r_data.fields.spi_ovr_en);
    Serial.printf("SPI_UNF_EN: 0x%02X\n", r_data.fields.spi_unf_en);
    Serial.printf("SPIERR_EN: 0x%02X\n", r_data.fields.spierr_en);
    Serial.printf("CCA_FAIL_EN: 0x%02X\n", r_data.fields.cca_fail_en);

    Serial.println();
}


void setup() {
    Serial.begin(115200);
    dw3000.init();

    delay(1000);
}

void loop() { 

    test_reg_sys_enable();

    while(1);
    delay(1000);
}
