#include "include/clocks.h"
#include "include/led.h"
#include "include/uart.h"

int main() {
    clocks_init();
    uart_init();
    //uart_putchar(uart_getchar());
    char *str = "";
    uart_gets(str,5);
    uart_puts(str);

    return 0;
}
