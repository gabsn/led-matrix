PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
CWARNINGS = -Wall -Wextra -Werror
CFLAGS = -g -O1 -mcpu=cortex-m0plus -mthumb
LDSRC = ld_ram.lds
LDFLAGS = -nostdlib -T $(LDSRC)

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
EXE = main

$(EXE): $(OBJ)
	$(LINK.o) $^ -o $@

startgdbserver: 
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

gdb:
	$(PREFIX)$@ $(EXE) 

clean:
	rm -rf $(OBJ) $(EXE) 



