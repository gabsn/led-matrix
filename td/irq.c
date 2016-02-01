#include <stdint.h>

#include "include/irq.h"

#define VTOR (*(volatile void **) 0xe000ed08)
#define NVIC_ISER (*(volatile uint32_t *) 0xe000e100)
#define NVIC_ICER (*(volatile uint32_t *) 0xe000e180)

#define MAKE_DEFAULT_HANDLER(name) void __attribute__((weak)) name() {\
    disable_irq();\
    while (1) {}\
}

extern uint8_t _stack_top, _start;

MAKE_DEFAULT_HANDLER(NMI_Handler);      
MAKE_DEFAULT_HANDLER(HardFault_Handler);      
MAKE_DEFAULT_HANDLER(SVC_Handler);      
MAKE_DEFAULT_HANDLER(PendSV_Handler);      
MAKE_DEFAULT_HANDLER(SysTick_Handler);      

MAKE_DEFAULT_HANDLER(DMA0_IRQHandler);      
MAKE_DEFAULT_HANDLER(DMA1_IRQHandler);      
MAKE_DEFAULT_HANDLER(DMA2_IRQHandler);      
MAKE_DEFAULT_HANDLER(DMA3_IRQHandler);      
MAKE_DEFAULT_HANDLER(Default_IRQHandler);   
MAKE_DEFAULT_HANDLER(FTFA_IRQHandler);      
MAKE_DEFAULT_HANDLER(PMC_IRSHandler);       
MAKE_DEFAULT_HANDLER(LLWU_IRQHandler);      
MAKE_DEFAULT_HANDLER(I2C0_IRQHandler);      
MAKE_DEFAULT_HANDLER(I2C1_IRQHandler);      
MAKE_DEFAULT_HANDLER(SPI0_IRQHandler);      
MAKE_DEFAULT_HANDLER(SPI1_IRQHandler);      
MAKE_DEFAULT_HANDLER(UART0_IRQHandler);     
MAKE_DEFAULT_HANDLER(UART1_IRQHandler);     
MAKE_DEFAULT_HANDLER(UART2_IRQHandler);     
MAKE_DEFAULT_HANDLER(ADC0_IRQHandler);      
MAKE_DEFAULT_HANDLER(CMP0_IRQHandler);      
MAKE_DEFAULT_HANDLER(TPM0_IRQHandler);      
MAKE_DEFAULT_HANDLER(TPM1_IRQHandler);      
MAKE_DEFAULT_HANDLER(TPM2_IRQHandler);      
MAKE_DEFAULT_HANDLER(RTCAlarm_IRQHandler);  
MAKE_DEFAULT_HANDLER(RTCSeconds_IRQHandler);
MAKE_DEFAULT_HANDLER(PIT_IRQHandler);       
MAKE_DEFAULT_HANDLER(I2S0_IRQHandler);      
MAKE_DEFAULT_HANDLER(USBOTG_IRQHandler);    
MAKE_DEFAULT_HANDLER(DAC0_IRQHandler);      
MAKE_DEFAULT_HANDLER(TSI0_IRQHandler);      
MAKE_DEFAULT_HANDLER(MCG_IRQHandler);       
MAKE_DEFAULT_HANDLER(LPTMR0_IRQHandler);    
MAKE_DEFAULT_HANDLER(SLCD_IRQHandler);      
MAKE_DEFAULT_HANDLER(PCMA_IRQHandler);      
MAKE_DEFAULT_HANDLER(PCMC_IRQHandler);      

void * vector_table[] __attribute__ (( section (".vtor"))) = {
    // Stack and Reset Handler
    &_stack_top,                /* Top of stack */
    &_start,                 /* Reset handler */

    // ARM internal exceptions
    NMI_Handler,            /* NMI handler */
    HardFault_Handler,      /* Hard Fault handler */
    0,                      /* Reserved */
    0,                      /* Reserved */
    0,                      /* Reserved */
    0,                      /* Reserved */
    0,                      /* Reserved */
    0,                      /* Reserved */
    0,                      /* Reserved */
    SVC_Handler,            /* SVC handler */
    0,                      /* Reserved */
    0,                      /* Reserved */
    PendSV_Handler,         /* Pending SVC handler */
    SysTick_Handler,        /* SysTick hanlder */

    // KL46 External interrupts
    DMA0_IRQHandler,        /* DMA0 interrupt */
    DMA1_IRQHandler,        /* DMA1 interrupt */
    DMA2_IRQHandler,        /* DMA2 interrupt */
    DMA3_IRQHandler,        /* DMA3 interupt */
    Default_IRQHandler,     /* Reserved */
    FTFA_IRQHandler,        /* FTFA interrupt */
    PMC_IRSHandler,         /* PMC interrupt */
    LLWU_IRQHandler,        /* LLWU interrupt */
    I2C0_IRQHandler,        /* I2C0 interrupt */
    I2C1_IRQHandler,        /* I2C1 interrupt */
    SPI0_IRQHandler,        /* SPI0 interrupt */
    SPI1_IRQHandler,        /* SPI1 interrupt */
    UART0_IRQHandler,       /* UART0 interrupt */
    UART1_IRQHandler,       /* UART1 interrupt */
    UART2_IRQHandler,       /* UART2 interrupt */
    ADC0_IRQHandler,        /* ADC0 interrupt */
    CMP0_IRQHandler,        /* CMP0 interrupt */
    TPM0_IRQHandler,        /* TPM0 interrupt */
    TPM1_IRQHandler,        /* TPM1 interrupt */
    TPM2_IRQHandler,        /* TPM2 interrupt */
    RTCAlarm_IRQHandler,    /* RTCAlarm interrupt */
    RTCSeconds_IRQHandler,  /* RTCSeconds interrupt */
    PIT_IRQHandler,         /* PIT interrupt */
    I2S0_IRQHandler,        /* I2S0 interrupt */
    USBOTG_IRQHandler,      /* USBOTG interrupt */
    DAC0_IRQHandler,        /* DAC0 interrupt */
    TSI0_IRQHandler,        /* TSI0 interrupt */
    MCG_IRQHandler,         /* MCG interrupt */
    LPTMR0_IRQHandler,      /* LPTMR0 interrupt */
    SLCD_IRQHandler,        /* SLCD interrupt */
    PCMA_IRQHandler,        /* PCMA interrupt */
    PCMC_IRQHandler,        /* PCMC interrupt */
};

void irq_init() {
    VTOR = &vector_table;
}

// irq_number between 0 and 31
void irq_enable(int irq_number) {
    NVIC_ISER = 1 << irq_number;
}

// irq_number between 0 and 31
void irq_disable(int irq_number) {
    NVIC_ICER = 1 << irq_number;
}
