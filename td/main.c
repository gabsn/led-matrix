#include "include/led.h"
#include "include/clocks.h"

int main() {
    clocks_init();
    led_init();

    return 0;
}
