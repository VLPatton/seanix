# Seanix
### Zeanix 2.0 pretty much
This is my second attempt at creating any sort of "usable" kernel. This one is
much better organized and I'm coming at it with more knowledge.

## Features
- x86_64 out of the box, with planned support for i686, RISC-V 64, and AArch64.
- `liballoc` basic memory allocator
- Serial output on x86_64 (requires legacy serial port)

## Licensing
Copyright (C) 2023 VLPatton

This software is licensed under the GNU Lesser General Public License version 3.
See `COPYING.md` and `COPYING.LESSER.md` for details.

## Make dependencies
- GCC for x86_64 freestanding (Linux amd64 desktops should work fine with
packaged GCC)
- GNU Make
- fdisk
- root access (`su -c` is used for making a bootable disk image)
- dosfstools (`mkfs.vfat`)
- GNU coreutils (`find`, `dd`, etc)
- Limine bootloader (this comes as a git submodule, there is no need to install)

## Make instructions
- Clone this repo initialize submodules
  - `git clone [url] && cd seanix`
  - `git submodule init`
- Make sure PWD is the Seanix repo
- Run GNU Make to build kernel
  - `make clean && make`
    - This builds the object code
  - `make seanix`
    - This finds the object code and links it into a single ELF file
- Run `img.sh` to generate a bootable disk image
  - `./img.sh`

## Emulation with QEMU
This should work out of the box with `qemu-system-x86_86`

## Contributions
I'm waiting on myself to write guidelines and a style guide, so not yet, though
PRs and forks are welcome.
