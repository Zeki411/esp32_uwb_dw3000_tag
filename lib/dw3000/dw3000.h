#ifndef __DW3000_H__
#define __DW3000_H__

#include "dw3000_regs.h"
#include "dw3000_types.h"
#include "dw3000_port.h"

#define DW3000_DEV_ID_VAL 0xDECA0302u

// typedef struct {
//     uint8_t pan_id[2];
//     uint8_t short_addr[2];
// } dw3000_network_id_t;





class DW3000{
public:

    dw3000_ret_t init();

    void hard_reset();
    void get_dev_id(uint32_t *data);

    void set_network_id(uint8_t *pan_id, uint8_t *short_addr);
    void get_network_id(uint8_t *pan_id, uint8_t *short_addr);

    
    //TODO:private
    void write_fast_cmd(uint8_t cmd);

    // void read_short_address(uint8_t base_addr, uint8_t *data, uint16_t len);
    void read_full_address(uint8_t base_addr, uint8_t sub_addr, uint8_t *data, uint16_t len);
    // void write_short_address(uint8_t base_addr, uint8_t *data, uint16_t len);
    void write_full_address(uint8_t base_addr, uint8_t sub_addr, uint8_t *data, uint16_t len);


private:
    DW3000Port *port;
};


#endif // __DW3000_H__