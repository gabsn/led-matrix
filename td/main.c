#include "include/clocks.h"
#include "include/led.h"
#include "include/uart.h"

int main() {
    clocks_init();
    uart_init();
    //uart_putchar(uart_getchar());
    const int size = 5;
    char str[size];
    uart_gets(str,size);
    uart_puts(str);

    return 0;
}
