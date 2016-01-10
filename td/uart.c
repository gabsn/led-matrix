#include <stdint.h>

#define SIM_SOPT2 *((volatile uint32_t *) 0x40048004) 

void uart_init() {
    // Select the clock source for the UART0
    SIM_SOPT2 = SIM_SOPT2 | (1 << 26);

    
}
