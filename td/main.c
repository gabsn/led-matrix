#include "include/clocks.h"
#include "include/led.h"
#include "include/uart.h"
#include "include/matrix.h"
#include "include/utils.h"
#include "include/irq.h"
#include "include/buttons.h"

extern uint8_t _binary___bin_image_raw_start;

int main() {
    clocks_init();
    led_init();
    uart_init();
    matrix_init();
    irq_init();
    button_init();
    set_luminance(10);

    //while (1) {
    //    display_image((rgb_color *) &_binary___bin_image_raw_start);
    //}

    while (1) {
        uart_putchar(uart_getchar());
    }

    return 0;
}
