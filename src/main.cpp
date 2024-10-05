#include <Arduino.h>

#define TEST_SIMPLE 0
#define TEST_TWR 1

#define TAG 0
#define ANCHOR 1

/* Choose test mode */
// #define TEST_MODE TEST_SIMPLE
#define TEST_MODE TEST_TWR

/* Choose device mode */
#define UWB_MODE TAG
// #define UWB_MODE ANCHOR

#if (UWB_MODE == TAG)
#include "tag_main.h"
#elif (UWB_MODE == ANCHOR)
#include "anchor_main.h"
#endif

void setup() {
#if (TEST_MODE == TEST_TWR)
    #if (UWB_MODE == TAG)
        // tag_main();
        tag_twr_main();
    #elif (UWB_MODE == ANCHOR)
        anchor_main();
    #endif
#elif (TEST_MODE == TEST_SIMPLE)
    #if (UWB_MODE == TAG)
        tag_simple_tx_main();
    #elif (UWB_MODE == ANCHOR)
        anchor_simple_rx_main();
    #endif
#endif // Closing the outer conditional



}

void loop() {
    // Your loop code here if needed
}
