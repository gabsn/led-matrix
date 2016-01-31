CC = arm-none-eabi-gcc
CFLAGS = -Wall -Werror -g -O2 -mthumb
LDLIBS = -lm -L/opt/mylibs
VPATH = libs

SOURCES = main.c t1.c t2.c stubs.c
OBJS := $(patsubst %.c, %.o, $(SOURCES))

hello : $(OBJS)
	$(LINK.o) $^ $(LDLIBS) -o $@

stubs.o : CFLAGS = -g -O2 -mthumb

clean:
	rm -rf *.o hello
