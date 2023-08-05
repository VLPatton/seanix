
ARCH?=

CFLAGS:=-ffreestanding -Wall -Wextra -std=gnu11 -mabi=sysv -march=$(ARCH) -fPIE -fno-stack-protector
CC:=gcc

FILES:=$(shell find -L . -type f -name '*.c')
OBJ:=$(FILES:.c=.c.o)

CPPFLAGS:=-I$(ARCH)/include -I$(LIMINE_PATH) -I$(PWD)/../kernel/include

.PHONY: all clean

all: $(OBJ)

kernel.elf: $(KOBJ)
	$(CC) -T $(ARCH)/linker.ld -o $@ -ffreestanding -O2 -nostdlib $(KOBJ) -lgcc

%.c.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(shell find -L . -type f -name '*.c.o')
	rm -f kernel.elf
