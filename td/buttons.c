#include <stdint.h>

#include "include/irq.h"
#include "include/led.h"

// set clock
#define SIM_SCGC5 (*(volatile uint32_t *) 0x40048038)
// pin controller
#define PORTC_PCR3 (*(volatile uint32_t *) 0x4004b00c)
// set input/output
#define GPIO_PDDR (*(volatile uint32_t *) 0x400ff094)


void button_init() {
    // activation of C port's clock
    SIM_SCGC5 |= (1 << 11);

    // set pc3 on GPIO
    PORTC_PCR3 = (1 << 8);
    PORTC_PCR3 &= ~((1 << 9) | (1 << 10));
    
    // set pc3 on input
    GPIO_PDDR &= ~(1 << 3);

    // set pc3 on pullup
    PORTC_PCR3 |= ((1 << 1) | 1);

    // configure interrupt on falling edge
    PORTC_PCR3 |= ((1 << 17) | (1 << 19));

    // activate interrupt on Port C
    irq_enable(31);
}

void PCMC_IRQHandler() {
   PORTC_PCR3 |= (1 << 24); 
   led_red_toggle();
}



