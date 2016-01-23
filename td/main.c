#include "include/clocks.h"

#include "include/led.h"
#include "include/uart.h"
#include "include/matrix.h"
#include "include/utils.h"

#define size 10

char s[size];

int main() {
    clocks_init();
    uart_init();
    matrix_init();

    test_pixels();

    return 0;
}
