ENTRY(_start)

_stack_top = 0x20000000;

MEMORY {
	rom (rx) : ORIGIN = 0, LENGTH = 256K
	raml (!rx) : ORIGIN =  0x1fffe000, LENGTH = 8K
	ramh (!rx) : ORIGIN =  0x20000000, LENGTH = 24K
} 

SECTIONS {
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

