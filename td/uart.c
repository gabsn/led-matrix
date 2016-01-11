#include <stdint.h>

#define SIM_SOPT2 *((volatile uint32_t *) 0x40048004) 
#define SIM_SOPT5 *((volatile uint32_t *) 0x40048010) 
#define SIM_SCGC4 *((volatile uint32_t *) 0x40048034) 
#define UART0_C1 *((volatile uint8_t *) 0x4006a002)
#define UART0_C4 *((volatile uint8_t *) 0x4006a00a) 
#define UART0_BDH *((volatile uint8_t *) 0x4006a000) 
#define UART0_BDL *((volatile uint8_t *) 0x4006a001) 
#define PORTA_PCR1 *((volatile uint32_t *) 0x40049004)
#define PORTA_PCR2 *((volatile uint32_t *) 0x40049008)


void uart_init() {
    // Select the clock source for the UART0
    SIM_SOPT2 |= 1 << 26;
    SIM_SCGC4 |= 1 << 10;

    // Set oversampling to 28 times
    UART0_C4 |= 28;

    // Set UART to 8 bits
    UART0_C4 &= 0 << 5;
    UART0_C1 &= 0 << 4;

    // Set baud rate
    UART0_BDH &= 0xe0;
    UART0_BDL = 7;

    // Disable parity
    UART0_C1 &= 0 << 1;

    // Set one bit stop
    UART0_BDH &= 0 << 5;

    // Enable portA's clock 
    SIM_SCGC5 |= 1 << 9;

    // Set mux to RX et TX
    PORTA_PCR1 |= 2 << 8; 
    PORTA_PCR2 |= 2 << 8;  

    // Active RX and TX
    SIM_SOPT5 &= ~7; 
}


