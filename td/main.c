#include "include/clocks.h"

#include "include/led.h"
#include "include/uart.h"
#include "include/matrix.h"
#include "include/utils.h"

extern uint8_t _binary___bin_image_raw_start;

int main() {
    clocks_init();
    uart_init();
    matrix_init();
    set_luminance(10);

    while(1) {
        display_image(&_binary___bin_image_raw_start); 
    }

    return 0;
}
