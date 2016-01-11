#ifndef UART_H
#define UART_H

void uart_init();
void uart_putchar(char c);
unsigned char uart_getchar();
void uart_puts(const char *s);
void uart_gets(char *s, int size);

#endif
