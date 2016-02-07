target ext :2331
mon endian little
mon halt

# User interface with asm, regs and cmd windows
define split
    layout split
    layout asm
    layout src
    layout regs
    focus cmd
end

# Define macro to reset the cpu
define flash
    mon reset
    mon reset
    mon reset
    load
    b UART0_IRQHandler
end
