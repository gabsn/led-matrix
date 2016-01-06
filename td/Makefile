PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)as
CWARNINGS = -Wall -Wextra -Werror
CFLAGS = $(CWARNINGS) -g -O1 -mcpu=cortex-m0plus -mthumb -nostdlib
LDSRC = ld_ram.lds
LDFLAGS = -g -nostdlib -T $(LDSRC)
ASFLAGS = -g -mcpu=cortex-m0plus
VPATH = ./include ./bin

SRC = $(wildcard *.c) 
OBJSRC = $(patsubst %.c, %.o, $(SRC)) crt0.o
OBJ = $(OBJSRC) clocks.o
EXE = main

all: $(EXE)

$(EXE): $(OBJ)
	$(LINK.o) $^ -o $@

-include $(subst .c,.d, $(SRC))

%d: %.c
	$(CC) $(CFLAGS) -MM -MF $@ -MP $<

crt0.o : ld_ram.lds

startgdbserver: 
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

gdb:
	$(PREFIX)$@ $(EXE) 

clean:
	rm -rf $(OBJSRC) $(EXE) 



