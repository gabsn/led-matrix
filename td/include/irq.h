#ifndef IRQ_H
#define IRQ_H

#define enable_irq() __asm__ volatile ("cpsie i")
#define disable_irq() __asm__ volatile ("cpsid i")

void irq_init();
void irq_enable(int);
void irq_disable(int);

#endif
