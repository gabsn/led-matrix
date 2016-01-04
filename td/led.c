#include <stdint.h>

// set clock
#define SIM_SG5 (*(volatile uint32_t *) 0x40048038)

// set pin controller register
#define PORTD_PCR5 (*(volatile uint32_t *) 0x4004c014)
#define PORTE_PCR29 (*(volatile uint32_t *) 0x4004d074)

// set input/output
#define GPIOD_PDDR (*(volatile uint32_t *) 0x400ff0d4)
#define GPIOE_PDDR (*(volatile uint32_t *) 0x400ff114)

// set output register
#define GPIOD_PSOR (*(volatile uint32_t *) 0x400ff0c4)
#define GPIOE_PSOR (*(volatile uint32_t *) 0x400ff104)

// clear output register
#define GPIOD_PCOR (*(volatile uint32_t *) 0x400ff0c8)
#define GPIOE_PCOR (*(volatile uint32_t *) 0x400ff108)

void led_init() {
    // activation of D et E ports' clocks
    SIM_SG5 = 0x00003182;

    // pins into gpio mode
    PORTD_PCR5 = 0x00000100;
    PORTE_PCR29 = 0x00000100;

    // pins into output mode
    GPIOD_PDDR = 1;
    GPIOE_PDDR = 1;

    // light the leds
    GPIOD_PSOR = 1;
    GPIOE_PSOR = 1;
}
    
