#include <stdint.h>

#include "include/irq.h"
#include "include/led.h"
#include "include/matrix.h"

#define SIM_SCGC6 (*(volatile uint32_t *) 0x4004803c)
#define PIT_MCR (*(volatile uint32_t *) 0x40037000)
#define PIT_LTMR64H (*(volatile uint32_t *) 0x400370e0)
#define PIT_LTMR64L (*(volatile uint32_t *) 0x400370e4)
#define PIT_LDVAL0 (*(volatile uint32_t *) 0x40037100)
#define PIT_CVAL0 (*(volatile uint32_t *) 0x40037104)
#define PIT_TCTRL0 (*(volatile uint32_t *) 0x40037108)
#define PIT_TFLG0 (*(volatile uint32_t *) 0x4003710c)

extern uint8_t _binary___bin_image_raw_start;

void pit_init() {
    // Enable PIT's clock
    SIM_SCGC6 |= (1 << 23);

    // Reset all registers
    PIT_LTMR64H = 0;
    PIT_LTMR64L = 0;
    PIT_CVAL0 = 0;
    PIT_TCTRL0 = 0;
    PIT_TFLG0 = 0x1;

    // Turn on PIT
    PIT_MCR = 0;

    // Set timer start value to 1s
    PIT_LDVAL0 = 24e6/13;

    // Enable timer interrupt and timer0
    PIT_TCTRL0 |= 0x3;
    irq_enable(22);
}

void PIT_IRQHandler() {
    PIT_TFLG0 = 0x1;
    led_red_toggle();
    //display_image((rgb_color *) &_binary___bin_image_raw_start);
}
