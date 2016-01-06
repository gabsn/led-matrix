.thumb
.global _start
_start:
    ldr r0, =_stack_top 
    mov sp, r0
    bl init_bss
    bl led_init
toggle:    
    bl led_toggle
    b toggle
end:
    b end
    

