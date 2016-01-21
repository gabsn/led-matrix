#include <stdint.h>

#include "include/utils.h"

// Define useful macro to set/clear register
#define SB(x) ((x == 0) ? GPIOB_PCOR |= 1 : GPIOB_PSOR |= 1) 
#define LAT(x) ((x == 0) ? GPIOB_PCOR |= (1 << 1) : GPIOB_PSOR |= (1 << 1)) 
#define RST(x) ((x == 0) ? GPIOB_PCOR |= (1 << 2) : GPIOB_PSOR |= (1 << 2)) 
#define SCK(x) ((x == 0) ? GPIOC_PCOR |= (1 << 8) : GPIOC_PSOR |= (1 << 8)) 
#define SDA(x) ((x == 0) ? GPIOC_PCOR |= (1 << 9) : GPIOC_PSOR |= (1 << 9)) 
#define ROW0(x) ((x == 0) ? GPIOA_PCOR |= (1 << 13) : GPIOA_PSOR |= (1 << 13)) 
#define ROW1(x) ((x == 0) ? GPIOD_PCOR |= (1 << 2) : GPIOD_PSOR |= (1 << 2)) 
#define ROW2(x) ((x == 0) ? GPIOD_PCOR |= (1 << 4) : GPIOD_PSOR |= (1 << 4)) 
#define ROW3(x) ((x == 0) ? GPIOD_PCOR |= (1 << 6) : GPIOD_PSOR |= (1 << 6)) 
#define ROW4(x) ((x == 0) ? GPIOD_PCOR |= (1 << 7) : GPIOD_PSOR |= (1 << 7)) 
#define ROW5(x) ((x == 0) ? GPIOD_PCOR |= (1 << 7) : GPIOD_PSOR |= (1 << 7)) 
#define ROW6(x) ((x == 0) ? GPIOA_PCOR |= (1 << 12) : GPIOA_PSOR |= (1 << 12)) 
#define ROW7(x) ((x == 0) ? GPIOA_PCOR |= (1 << 4) : GPIOA_PSOR |= (1 << 4)) 

// Clocks register
#define SIM_SCGC5 (*(volatile uint32_t * const) 0x40048038)

// PORTx_PCRx
#define PA4 (*(volatile uint32_t * const) 0x40049010)
#define PA12 (*(volatile uint32_t * const) 0x40049030)
#define PA13 (*(volatile uint32_t * const) 0x40049034)
#define PB0 (*(volatile uint32_t * const) 0x4004a000)
#define PB1 (*(volatile uint32_t * const) 0x4004a004)
#define PB2 (*(volatile uint32_t * const) 0x4004a008)
#define PC8 (*(volatile uint32_t * const) 0x4004b020)
#define PC9 (*(volatile uint32_t * const) 0x4004b024)
#define PD2 (*(volatile uint32_t * const) 0x4004c008)
#define PD4 (*(volatile uint32_t * const) 0x4004c010)
#define PD5 (*(volatile uint32_t * const) 0x4004c014)
#define PD6 (*(volatile uint32_t * const) 0x4004c018)
#define PD7 (*(volatile uint32_t * const) 0x4004c01C)

// GPIO registers
#define GPIOA_PDDR (*(volatile uint32_t * const) 0x400ff014)
#define GPIOB_PDDR (*(volatile uint32_t * const) 0x400ff054)
#define GPIOC_PDDR (*(volatile uint32_t * const) 0x400ff094)
#define GPIOD_PDDR (*(volatile uint32_t * const) 0x400ff0d4)

// Set Output registers
#define GPIOA_PSOR (*(volatile uint32_t * const) 0x400ff004)
#define GPIOB_PSOR (*(volatile uint32_t * const) 0x400ff044)
#define GPIOC_PSOR (*(volatile uint32_t * const) 0x400ff084)
#define GPIOD_PSOR (*(volatile uint32_t * const) 0x400ff0c4)

// Clear Output registers
#define GPIOA_PCOR (*(volatile uint32_t *) 0x400ff008)
#define GPIOB_PCOR (*(volatile uint32_t *) 0x400ff048)
#define GPIOC_PCOR (*(volatile uint32_t *) 0x400ff088)
#define GPIOD_PCOR (*(volatile uint32_t *) 0x400ff0c8)

void matrix_init() {
    // Set clock for port A, B, C and D
    SIM_SCGC5 |= 0x1e00;

    // Set mux to GPIO
    PA4 |= 0x100;
    PA12 |= 0x100;
    PA13 |= 0x100;
    PB0 |= 0x100;
    PB1 |= 0x100;
    PB2 |= 0x100;
    PC8 |= 0x100;
    PC9 |= 0x100;
    PD2 |= 0x100;
    PD4 |= 0x100;
    PD5 |= 0x100;
    PD6 |= 0x100;
    PD7 |= 0x100;

    // Set Port Data Direction Register
    GPIOA_PDDR |= 0x3010;
    GPIOB_PDDR |= 0x7;
    GPIOC_PDDR |= 0x300;
    GPIOD_PDDR |= 0xf4;

    // Initializing
    RST(0);
    LAT(1);
    // Selection of BANK1
    SB(1);
    SCK(0);
    SDA(0);
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);

    // Wait 500ms then continue
    wait_for(500);
    RST(1);
}

void pulse_SCK() {
    SCK(0);
    // We need to wait at least 2ns in low state
    wait_for(1);
    SCK(1);
    //We need to wait at least 2ns in high state
    wait_for(1);
    SCK(0);
}
