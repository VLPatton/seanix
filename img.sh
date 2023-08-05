#!/bin/sh

IMAGE_NAME=kernel.img

dd if=/dev/zero of=$IMAGE_NAME bs=1M count=1024

ELF_FILES=$(find -L ./arch -type f -name "*.elf")
CFG_FILES=$(find -L ./sysroot/boot -type f -name "*.cfg")
TAR_FILES=$(find -L ./sysroot/boot -type f -name "*.tar")

# next section requires root access
mkdir -p mnt
su -c "./img-2.sh ${ELF_FILES} ${CFG_FILES} ${TAR_FILES}"
