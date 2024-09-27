#include <Arduino.h>
#include "dw3000_interface.h"
#include "dw3000.h"


void setup() {
    Serial.begin(115200);
    dw3000_interface_init();

    delay(1000);
}

void loop() { 

    uint32_t dev_id = dwt_readdevid();
    Serial.printf("DEV_ID: 0x%08X\n", dev_id);


    while(1);
    delay(1000);
}
