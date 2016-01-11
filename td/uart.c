#include <stdint.h>

#define SIM_SOPT2 (*(volatile uint32_t * const) 0x40048004) 
#define SIM_SOPT5 (*(volatile uint32_t * const) 0x40048010) 
#define SIM_SCGC4 (*(volatile uint32_t * const) 0x40048034) 
#define SIM_SCGC5 (*(volatile uint32_t * const) 0x40048038) 

#define UART0_C1 (*(volatile uint8_t * const) 0x4006a002)
#define UART0_C2 (*(volatile uint8_t * const) 0x4006a003)
#define UART0_C4 (*(volatile uint8_t * const) 0x4006a00a) 
#define UART0_BDH (*(volatile uint8_t * const) 0x4006a000) 
#define UART0_BDL (*(volatile uint8_t * const) 0x4006a001) 
#define UART0_S1 (*(volatile uint8_t * const) 0x4006a004) 
#define UART0_D (*(volatile uint8_t * const) 0x4006a007) 

#define PORTA_PCR1 (*(volatile uint32_t * const) 0x40049004)
#define PORTA_PCR2 (*(volatile uint32_t * const) 0x40049008)

void uart_init() {
    // Select the clock source for the UART0
    SIM_SOPT2 |= 0x4000000;
    SIM_SCGC4 |= 0x400;

    // Set clock to 24MHz
    SIM_SOPT2 |= 1 << 16;

    // Disable UART0
    UART0_C2 &= ~0xC;
    
    // Enable portA's clock 
    SIM_SCGC5 |= 0x200;

    // Set mux to RX et TX
    PORTA_PCR1 |= 0x200; 
    PORTA_PCR2 |= 0x200;  

    // Set oversampling to 29 times
    UART0_C4 |= 29;

    // Set baud rate
    UART0_BDL = 7;
    UART0_BDH = 0; 

    UART0_BDH = 0; 
    // Set UART to 8 bits + disable parity
    UART0_C1 &= 0xed;
    UART0_C4 &= 0xdf;

    // Active RX and TX
    SIM_SOPT5 &= 0xfffffff8; 

    // Enable UART0
    UART0_C2 |= 0xc;
}


void uart_putchar(char c) {
    while (!(UART0_S1 & (1 << 7)) || !(UART0_S1 & (1 << 6))) {}
    UART0_D = c;
}

unsigned char uart_getchar() {
    while (!(UART0_S1 & 0x20)) {}
    return UART0_D;
}

void uart_puts(const char *s) {
    while(*s) {
        uart_putchar(*s++);
    }
}

void uart_gets(char *s, int size) {
    int i;
    unsigned char c;
    for (i=0; i<size; ++i) {
        c = uart_getchar();
        if (c == '\n' || c == '\0')
            return;
        else
            *s++ = c;
    }
    return;
}


