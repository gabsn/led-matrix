#include "include/clocks.h"
#include "include/led.h"
#include "include/uart.h"

#define size 10

char s[size];

int main() {
    clocks_init();
    uart_init();

    //uart_putchar(uart_getchar());
    uart_gets(s,size);
    uart_puts(s);

    return 0;
}
