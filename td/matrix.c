#include "include/utils.h"
#include <stdint.h>

// Clocks register
#define SIM_SCGC5 (*(volatile uint32_t * const) 0x40048038)

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
#define GPIOA_PSOR (*(volatile uint32_t *) 0x400ff004)
#define GPIOB_PSOR (*(volatile uint32_t *) 0x400ff044)
#define GPIOC_PSOR (*(volatile uint32_t *) 0x400ff084)
#define GPIOD_PSOR (*(volatile uint32_t *) 0x400ff0c4)

// Clear Output registers
#define GPIOA_PCOR (*(volatile uint32_t *) 0x400ff008)
#define GPIOB_PCOR (*(volatile uint32_t *) 0x400ff048)
#define GPIOC_PCOR (*(volatile uint32_t *) 0x400ff088)
#define GPIOD_PCOR (*(volatile uint32_t *) 0x400ff0c8)

// Define useful macro to set/clear register
#define SB(x) ((x == 0) ? GPIOB_PCOR |= 1 : GPIOB_PSOR |= 1) 
#define LAT(x) ((x == 0) ? GPIOB_PCOR |= (1 << 1) : GPIOB_PSOR |= (1 << 1)) 
#define RST(x) ((x == 0) ? GPIOB_PCOR |= (1 << 2) : GPIOB_PSOR |= (1 << 2)) 
#define SCK(x) ((x == 0) ? GPIOC_PCOR |= (1 << 8) : GPIOC_PSOR |= (1 << 8)) 
#define SDA(x) ((x == 0) ? GPIOC_PCOR |= (1 << 9) : GPIOC_PSOR |= (1 << 9)) 
#define C0(x) ((x == 0) ? GPIOA_PCOR |= (1 << 13) : GPIOA_PSOR |= (1 << 13)) 
#define C1(x) ((x == 0) ? GPIOD_PCOR |= (1 << 2) : GPIOD_PSOR |= (1 << 2)) 
#define C2(x) ((x == 0) ? GPIOD_PCOR |= (1 << 4) : GPIOD_PSOR |= (1 << 4)) 
#define C3(x) ((x == 0) ? GPIOD_PCOR |= (1 << 6) : GPIOD_PSOR |= (1 << 6)) 
#define C4(x) ((x == 0) ? GPIOD_PCOR |= (1 << 7) : GPIOD_PSOR |= (1 << 7)) 
#define C5(x) ((x == 0) ? GPIOD_PCOR |= (1 << 7) : GPIOD_PSOR |= (1 << 7)) 
#define C6(x) ((x == 0) ? GPIOA_PCOR |= (1 << 12) : GPIOA_PSOR |= (1 << 12)) 
#define C7(x) ((x == 0) ? GPIOA_PCOR |= (1 << 4) : GPIOA_PSOR |= (1 << 4)) 

void matrix_init() {
    // Set clock for port A, B, C and D
    SIM_SCGC5 |= 0x1e00;

    // Set mux to GPIO
    PA13 |= 0x100;
    PD2 |= 0x100;
    PD4 |= 0x100;
    PD6 |= 0x100;
    PD7 |= 0x100;
    PD5 |= 0x100;
    PA12 |= 0x100;
    PA4 |= 0x100;
    PB0 |= 0x100;
    PB1 |= 0x100;
    PB2 |= 0x100;
    PC9 |= 0x100;
/* TODO PC8 */

    // Set Port Data Direction Register
    GPIOA_PDDR |= 0x3010;
    GPIOB_PDDR |= 0x7;
    GPIOC_PDDR |= 0x300;
    GPIOD_PDDR |= 0xf4;

    // Initializing
    RST(0);
    LAT(1);
    SB(1);
    SCK(0);
    SDA(0);
    C0(0);
    C1(0);
    C2(0);
    C3(0);
    C4(0);
    C5(0);
    C6(0);
    C7(0);

    // Wait 500ms then continue
    wait_for(500);
    RST(1);
