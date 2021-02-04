LOADADDR = 0xa0000100

CROSS_COMPILE = mips-openwrt-linux-

.S.s:
	$(CPP) $(CFLAGS) $< -o $*.s
.S.o:
	$(CC) $(CFLAGS) -c $< -o $*.o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $*.o

CC =       $(CROSS_COMPILE)gcc
LD =       $(CROSS_COMPILE)ld
OBJCOPY =  $(CROSS_COMPILE)objcopy
OBJDUMP =  $(CROSS_COMPILE)objdump

CFLAGS = -O -g -G 0 -mno-abicalls -fno-pic -Wall -DKERNEL -D__ASSEMBLY_ -I../../include

# Drop some uninteresting sections in the kernel.
# This is only relevant for ELF kernels but doesn't hurt a.out
drop-sections   = .reginfo .mdebug
strip-flags     = $(addprefix --remove-section=,$(drop-sections))

all : elf bin fulldump

elf : prog_free.elf
bin : prog_free.bin
fulldump : prog_free.objdump

prog_free.elf : start.o spi_prog.o reg.o
	$(LD) -o prog_free.elf -N -Tspi_prog.lds -Ttext $(LOADADDR) $^

prog_free.objdump:	prog_free.elf
	$(OBJDUMP) -Dlxs $< > $@

prog_free.bin : prog_free.elf
	$(OBJCOPY) -S -O binary $(strip-flags) prog_free.elf prog_free.bin

clean:
	rm -f *.o prog_free.elf prog_free.bin prog_free.objdump
