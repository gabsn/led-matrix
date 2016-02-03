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
    uart_init2();
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

    //char s[5];
    //uart_gets(s,5);
    //uart_puts(s);

    //while (1) {
    //    int size = (int) uart_getchar();
    //    wait_for(500);
    //    char s[size];
    //    uart_gets(s, size); 
    //    wait_for(1000);
    //    uart_puts(s);
    //}

    return 0;
}
