#include "include/clocks.h"
#include "include/led.h"
#include "include/uart.h"

int main() {
    clocks_init();
    uart_init();
    uart_putchar('b');

    return 0;
}
