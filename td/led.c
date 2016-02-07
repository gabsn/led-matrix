#include <stdint.h>

#include "include/utils.h"
#include "include/led.h"

// set clock
#define SIM_SCGC5 (*(volatile uint32_t *) 0x40048038)

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

// set toggle
#define GPIOD_PTOR (*(volatile uint32_t *) 0x400ff0cc)
#define GPIOE_PTOR (*(volatile uint32_t *) 0x400ff10c)

// declare constants
#define c5 (0x1 << 5)
#define c29 (0x1 << 29)

void led_init() {
    // activation of D et E ports' clocks
    SIM_SCGC5 |= 0x3000;

    // pins into gpio mode
    PORTD_PCR5 = 0x100;
    PORTE_PCR29 = 0x100;

    // pins into output mode
    GPIOD_PDDR |= c5;
    GPIOE_PDDR |= c29;

    // light on the leds
    led_green_on();
    led_red_on();
}
    
void led_green_on() {
    GPIOD_PCOR = c5;
}

void led_red_on() {
    GPIOE_PCOR = c29;
}

void led_green_off() {
    GPIOD_PSOR = c5;
}

void led_red_off() {
    GPIOE_PSOR = c29;
}

void led_green_toggle() {
    GPIOD_PTOR = c5; 
}

void led_red_toggle() {
    GPIOE_PTOR = c29;
}

