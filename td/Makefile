PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)as
TARGET_ARCH = -mcpu=cortex-m0plus 
LDSRC = ld_ram.lds
VPATH = ./bin ./include

### Set flags ###
CFLAGS = -Wall -Wextra -Werror -g -O1 -std=c99 -mthumb -nostdlib -MD
LDFLAGS = -g -nostdlib -T $(LDSRC)
ASFLAGS = -g -mcpu=cortex-m0plus

### Sources files ###
SRC = init.c led.c uart.c buttons.c irq.c matrix.c utils.c main.c
OBJSRC = $(patsubst %.c, %.o, $(SRC)) crt0.o image.o flash.o
OBJ = $(OBJSRC) clocks.o
DEPS := $(subst .o,.d, $(OBJ))
EXE = main

### Dependencies ###
all: $(EXE)
	@echo "--> Project built."

crt0.o irq.o init.o: $(LDSRC) 
-include $(DEPS)

### Building rules ###
$(EXE): $(OBJ)
	$(LINK.o) $^ -o $@

image.o : image.raw
	$(PREFIX)ld -r -b binary $< -o $@ 

### Personnal rules ###
startgdbserver: 
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

gdb:
	$(PREFIX)$@ $(EXE) 

clean:
	rm -rf $(EXE) $(OBJSRC) $(DEPS)
	@echo "--> Clean completed."

.PHONY: clean gdb startgdbserver
