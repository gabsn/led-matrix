#include "include/clocks.h"

#include "include/led.h"
#include "include/uart.h"
#include "include/matrix.h"
#include "include/utils.h"

int main() {
    clocks_init();
    uart_init();
    matrix_init();
    set_luminance(10);

    test_pixels();

    return 0;
}
