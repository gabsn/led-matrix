.thumb
.global _start
_start:
    ldr r0, =_stack_top 
    mov sp, r0
    bl init_bss
    bl init_led
end:
    b end
    

