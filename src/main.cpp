#include <Arduino.h>
#include "dw3000.h"

DW3000 dw3000;

void setup() {
    Serial.begin(115200);

    if (dw3000.init() != DW3000_RET_OK) {
        Serial.println("DW3000 init failed");
        while(1);
    }

}

void loop() { 
    uint8_t pan_id[2] = {0};
    uint8_t short_addr[2] = {0};

    uint8_t pan_id_set[2] = {0x01, 0x02};
    uint8_t short_addr_set[2] = {0x03, 0x04};

    dw3000.set_network_id(pan_id_set, short_addr_set);
    dw3000.get_network_id(pan_id, short_addr);

    for (int i = 0; i < 2; i++) {
        Serial.print(pan_id[i], HEX);
        Serial.print(" ");
    }
    Serial.print('-');
    for (int i = 0; i < 2; i++) {
        Serial.print(short_addr[i], HEX);
        Serial.print(" ");
    }

    Serial.println();




    delay(1000);
}
