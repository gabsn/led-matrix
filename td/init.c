#include <stdint.h>

extern uint8_t _etext, _data, _edata, _rodata, _erodata, _bstart, _bend;

uint8_t *dst;

void init_bss() {
    for (dst = &_bstart; dst < &_bend; dst++) 
        *dst = 0;
}
