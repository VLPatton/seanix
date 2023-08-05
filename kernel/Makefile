
ARCH?=

CFLAGS:=-ffreestanding -Wall -Wextra -std=gnu11 -mabi=sysv -march=$(ARCH) -fPIE -fno-stack-protector
CC:=gcc

CPPFLAGS:=-I$(PWD)/include

FILES:=$(shell find -L . -type f -name '*.c')
OBJ:=$(FILES:.c=.c.o)

.PHONY: all clean

all: $(OBJ)

%.c.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(shell find -L . -type f -name '*.c.o')
