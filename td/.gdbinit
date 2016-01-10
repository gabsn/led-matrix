target ext :2331
mon endian little
mon halt

# User interface with asm, regs and cmd windows
define split
    layout split
    layout asm
    layout regs
    focus cmd
end

# Define macro to reset the cpu
define flash
    dont-repeat
    mon halt
    mon reset
    mon reset
    load
    b main
    cont
end
