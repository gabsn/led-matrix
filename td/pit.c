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

#define TIMES_PER_SEC 100 

// number of cycles to wait before triggering interrupt
uint32_t duration = 24e6/(8*TIMES_PER_SEC); 
uint8_t row = 0;
extern rgb_color * image_1, image_2;
extern uint8_t image_selector;

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

    // Set timer start value
    PIT_LDVAL0 = duration;
    duration /= 2;

    // Enable timer interrupt and timer0
    PIT_TCTRL0 |= 0x3;
    irq_enable(22);
}

void PIT_IRQHandler() {
    PIT_TFLG0 = 0x1;
    rgb_color * image_row; 
    if (image_selector == 1) 
        image_row = (rgb_color *) &image_2 + 8*row;
    else
        image_row = (rgb_color *) &image_1 + 8*row;
    mat_set_row(row, image_row);
    (row == 7) ? row = 0 : ++row;
}

