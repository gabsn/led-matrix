ENTRY(_start)

MEMORY {
    flash_config (rx) : ORIGIN = 1K, LENGTH = 0x20
	flash (rx) : ORIGIN = 2K, LENGTH = 254K
	raml (!rx) : ORIGIN = 0x1fffe000, LENGTH = 8K
	ramh (!rx) : ORIGIN = 0x20000000, LENGTH = 24K
} 
    
_stack_top = ORIGIN(ramh);

SECTIONS {
    .flash_config : {
        *(.flash_config)
    } > flash_config

    .vtor : {
        irq.o(.vtor)
    } > ramh

    .text : {
        *(.text) 
        _etext = . ;
    } > ramh

    .rodata : { 
        _rodata = . ;
        *(.rodata) 
        _erodata = . ;
    } > ramh

    .data : { 
        _data = . ;
        *(.data) 
        _edata = . ;
    } > ramh
    
    .bss : { 
        _bstart = . ;
        *(.bss COMMON) 
        _bend = . ;
    } > ramh
}

