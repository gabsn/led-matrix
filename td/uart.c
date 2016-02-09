#include <stdint.h>

#include "include/irq.h"
#include "include/matrix.h"

#define SIM_SOPT2 (*(volatile uint32_t * const) 0x40048004) 
#define SIM_SOPT5 (*(volatile uint32_t * const) 0x40048010) 
#define SIM_SCGC4 (*(volatile uint32_t * const) 0x40048034) 
#define SIM_SCGC5 (*(volatile uint32_t * const) 0x40048038) 

#define UART0_C1 (*(volatile uint8_t * const) 0x4006a002)
#define UART0_C2 (*(volatile uint8_t * const) 0x4006a003)
#define UART0_C3 (*(volatile uint8_t * const) 0x4006a006)
#define UART0_C4 (*(volatile uint8_t * const) 0x4006a00a) 
#define UART0_BDH (*(volatile uint8_t * const) 0x4006a000) 
#define UART0_BDL (*(volatile uint8_t * const) 0x4006a001) 
#define UART0_S1 (*(volatile uint8_t * const) 0x4006a004) 
#define UART0_S2 (*(volatile uint8_t * const) 0x4006a005) 
#define UART0_D (*(volatile uint8_t * const) 0x4006a007) 

#define PORTA_PCR1 (*(volatile uint32_t * const) 0x40049004)
#define PORTA_PCR2 (*(volatile uint32_t * const) 0x40049008)

rgb_color * image_1[64];
rgb_color * image_2[64];
uint8_t * current_byte = (uint8_t *) &image_1;
uint8_t byte_counter = 0;
uint8_t error = 0;
uint8_t image_selector = 1; // points on the image being received

void uart_init() {
    // Select the clock source for the UART0
    SIM_SOPT2 |= 0x4000000;
    SIM_SCGC4 |= 0x400;

    // Set clock to 24MHz
    SIM_SOPT2 |= 1 << 16;

    // Enable portA's clock 
    SIM_SCGC5 |= 0x200;

    // Set mux to RX et TX
    PORTA_PCR1 = 0x200; 
    PORTA_PCR2 = 0x200;  

    // Disable UART0
    UART0_C2 = 0;

    // Set oversampling to 24
    UART0_C4 = 24;

    // Set baud rate (BDL = 25)
    UART0_BDL = 25;
    UART0_BDH = 0; 

    // Clear all flags
    UART0_S1 = 0x1f;
    UART0_S2 = 0xc0;
    UART0_C1 = 0;
    UART0_C3 = 0;

    // Clear receive data register buffer
    UART0_D;

    // Set receive and transmit data source respectively on UART0_RX and UART0_TX pin 
    SIM_SOPT5 &= 0xfffffff8; 

    // Enable UART0
    UART0_C2 = ((1 << 2) | (1 << 3));

    // Enable overrun interrupt and framing error interrupt
    UART0_C3 |= ((1 << 1) | (1 << 3)); 

    // Enable reciever interrupt
    UART0_C2 |= (1 << 5);
    irq_enable(12);
}

void uart_putchar(char c) {
    while(!(UART0_S1 & (1 << 6))) {}
    UART0_D = c;
}

unsigned char uart_getchar() {
    UART0_S1 = 0x1f;
    while (!(UART0_S1 & (1 << 5))) {}
    // Detect framing and overrun errors
    if ((UART0_S1 & (1 << 1)) || (UART0_S1 & (1 << 3)))
        error = 1;
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
    for (i=0; i<size-1; ++i) {
        c = uart_getchar();
        if (c == '\r') {
            *s = '\0';
            return;
        } else {
            *s++ = c;
        }
    }
    *s = '\0';
    return;
}

// The idea is to alternate between 2 images in memory in order to use one of them as buffer
void UART0_IRQHandler() {
    unsigned char c = uart_getchar();
    if (byte_counter == 0 && c != 0xff) {
        error = 1;
    } else if (byte_counter == 0 && c == 0xff) {
        byte_counter++;
    } else if (byte_counter == 192) {
        *current_byte = c;
        byte_counter = 0;
        if (image_selector == 1) {
            if (!error) { 
                image_selector = 2;
                current_byte = (uint8_t *) &image_2;
            } else {
                error = 0;
                current_byte = (uint8_t *) &image_1;
            }
        } else {
            if (!error) {
                image_selector = 1;
                current_byte = (uint8_t *) &image_1;
            } else {
                error = 0;
                current_byte = (uint8_t *) &image_2;
            }
        }
    } else {
        *current_byte++ = c;
        byte_counter++;
    }
}
