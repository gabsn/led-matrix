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

    .vtor ORIGIN(ramh) : {
        irq.o(.vtor)
    } > ramh

    .text : {
        *(.text) 
    } > ramh

    .rodata : { 
        *(.rodata) 
    } > ramh

    .data : { 
        *(.data) 
    } > ramh
    
    .bss : { 
        _bstart = . ;
        *(.bss COMMON) 
        _bend = . ;
    } > ramh
}

