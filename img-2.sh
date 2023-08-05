#!/bin/sh

USED_LOOPBK=$(losetup -Pf --show kernel.img)

# new GPT table\n
# new partition\n
#   default\n
#   default\n
#   default\n
# type\n
# 1 (EFI)\n
# write\n
printf "g\nn\n\n\n\nt\n1\nw\n" | fdisk ${USED_LOOPBK}
sync

mkfs.vfat -F 32 ${USED_LOOPBK}p1
mount -o user ${USED_LOOPBK}p1 mnt
mkdir -p mnt/EFI/BOOT
cp -v $@ limine/limine-bios.sys mnt/
cp -v limine/BOOTX64.EFI limine/BOOTIA32.EFI mnt/EFI/BOOT/

sync
umount mnt
losetup -d ${USED_LOOPBK}

./limine/limine bios-install kernel.img
