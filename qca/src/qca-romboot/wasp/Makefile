
export TOPDIR=$(PWD)/
export TOOLPATH=$(TOPDIR)/../../build/gcc-4.3.3/build_mips/staging_dir/usr/
export KERNELPATH=$(TOPDIR)/../../linux/kernels/mips-linux-2.6.15
export UTILPATH=$(TOPDIR)/../utils/bin
export PATH:=$(TOPDIR)/tools:$(TOOLPATH)/bin:$(TOPDIR)/src:${PATH}

PRJ_NAME = rombootdrv

######## CONFIGURATION #########
ifeq ($(BOARD_TYPE),db12x-offload-gmac) # {
LOADADDR = 0xbd003000
else
LOADADDR = 0xbd004000
endif

CROSS_COMPILE = mips-linux-uclibc-

OBJS = drv_main.o lowlevel_init_934x.o lowlevel_init_934x-nand.o lowlevel_init_934x-1.1.o meminit.o gmac_fwd.o rom.addrs.o pci.o

ifeq ($(ROMBOOTDRV_SUPPORT_USB_FWD),1)
OBJS += usb_fwd.o
endif

######## END OF CONFIGURATION #########

.S.s:
	$(CPP) $(AFLAGS) $< -o $*.s
.S.o:
	$(CC) $(AFLAGS) -c $< -o $*.o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $*.o

CC =       $(CROSS_COMPILE)gcc
LD =       $(CROSS_COMPILE)ld
OBJCOPY =  $(CROSS_COMPILE)objcopy
OBJDUMP =  $(CROSS_COMPILE)objdump

AFLAGS = -Wa,-gstabs -D__ASSEMBLY__ -g  -Os   -D__KERNEL__ -DTEXT_BASE=$(LOADADDR) -I$(TOPDIR) -I$(TOPDIR)/include -fno-builtin -ffreestanding -nostdinc -isystem $(TOPDIR)/../../build/gcc-3.4.4-2.16.1/build_mips_nofpu/bin-ccache/../lib/gcc/mips-linux-uclibc/3.4.4/include -pipe  -DCONFIG_MIPS -D__MIPS__  -march=mips32r2 -mno-abicalls -fno-pic
CFLAGS = -Wall -Wa,-gstabs -g  -Os   -D__KERNEL__ -I$(TOPDIR) -I$(TOPDIR)/include -fno-builtin -ffreestanding -nostdinc -isystem $(TOPDIR)/../../build/gcc-3.4.4-2.16.1/build_mips_nofpu/bin-ccache/../lib/gcc/mips-linux-uclibc/3.4.4/include -pipe  -DCONFIG_MIPS -D__MIPS__  -march=mips32r2 -mno-abicalls -fno-pic

ifdef BOOT_FROM_NAND
AFLAGS += -DCONFIG_ATH_NAND_SUPPORT=1
CFLAGS += -DCONFIG_ATH_NAND_SUPPORT=1
endif

ifeq ($(ROMBOOTDRV_SUPPORT_GMAC_1000M),1)
CFLAGS += -DROMBOOTDRV_SUPPORT_GMAC_1000M=1
else
CFLAGS += -DROMBOOTDRV_SUPPORT_GMAC_1000M=0
endif

ifeq ($(ROMBOOTDRV_SUPPORT_USB_FWD),1)
CFLAGS += -DROMBOOTDRV_SUPPORT_USB_FWD
endif

ifeq ($(ROMBOOTDRV_DISABLE_PCIE),1)
CFLAGS += -DROMBOOTDRV_DISABLE_PCIE
endif

ifeq ($(ROMBOOTDRV_DOWNLOAD_LED_TOGGLE),1)
CFLAGS += -DROMBOOTDRV_DOWNLOAD_LED_TOGGLE
endif

ifneq ($(strip $(ROMBOOTDRV_CFG_PLL_FREQ)),)
AFLAGS += -DCFG_PLL_FREQ=$(ROMBOOTDRV_CFG_PLL_FREQ)
CFLAGS += -DCFG_PLL_FREQ=$(ROMBOOTDRV_CFG_PLL_FREQ)
endif

ifeq ($(UB124_STANDALONE), 1)
CFLAGS+= -DUB124_STANDALONE=1
endif

# Drop some uninteresting sections in the kernel.
# This is only relevant for ELF kernels but doesn't hurt a.out
drop-sections   = .reginfo .mdebug
strip-flags     = $(addprefix --remove-section=,$(drop-sections))

all :	elf srec bin

srec : $(PRJ_NAME).srec
elf : $(PRJ_NAME).elf
bin : $(PRJ_NAME).bin

$(PRJ_NAME).elf : $(OBJS)
	$(LD) -o $(PRJ_NAME).elf -N -Tlinker.lds -Ttext $(LOADADDR) $^
	$(OBJDUMP) -Dlxs $^ > $(PRJ_NAME).objdump

$(PRJ_NAME).srec : $(PRJ_NAME).elf
	$(OBJCOPY) -S -O srec $(strip-flags) $(PRJ_NAME).elf $(PRJ_NAME).srec

$(PRJ_NAME).bin : $(PRJ_NAME).elf
	$(OBJCOPY) -S -O binary $(strip-flags) $(PRJ_NAME).elf $(PRJ_NAME).bin
	$(UTILPATH)/bin2hex $(PRJ_NAME).bin fwu_$(PRJ_NAME).c 0 usb waspRomInitFw

clean:
	rm -f *~ *.o $(PRJ_NAME).elf $(PRJ_NAME).srec $(PRJ_NAME).bin fwu_$(PRJ_NAME).c
