#include <stdint.h>

extern uint8_t _etext, _data, _edata, _rodata, _erodata, _bstart, _bend;

void init_bss() {
    uint8_t *dst;

    for (dst = &_bstart; dst < &_bend; dst++) 
        *dst = 0;
}
