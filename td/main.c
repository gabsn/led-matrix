#include "include/clocks.h"
#include "include/led.h"
#include "include/uart.h"
#include "include/matrix.h"
#include "include/utils.h"
#include "include/irq.h"
#include "include/buttons.h"
#include "include/pit.h"

int main() {
    clocks_init();
    led_init();
    uart_init();
    matrix_init();
    irq_init();
    button_init();
    pit_init();
    set_brightness(30);

    return 0;
}
