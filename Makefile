

ARCH:=x86-64

.PHONY: kernel arch all clean seanix limine

all: kernel arch limine

export KOBJ:=$(shell find -L $(PWD)/kernel -type f -name '*.o') \
$(shell find -L $(PWD)/arch -type f -name '*.o') \


seanix: all
	cd arch && make kernel.elf ARCH=$(ARCH)

kernel:
	cd kernel && make ARCH=$(ARCH)

arch:
	cd arch && make ARCH=$(ARCH) LIMINE_PATH=$(PWD)/limine

limine:
	cd limine && make

clean:
	cd kernel && make clean
	cd arch && make clean
