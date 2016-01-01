ENTRY(main)

MEMORY {
	rom (rx) : ORIGIN = 0, LENGTH = 256K
	raml (!rx) : ORIGIN =  0x1fffe000, LENGTH = 8K
	ramh (!rx) : ORIGIN =  0x20000000, LENGTH = 24K
} 

SECTIONS {
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
        *(.bss COMMON) 
    } > ramh
}

