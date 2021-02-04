
export TOPDIR=$(PWD)/
export TOOLPATH=$(TOPDIR)/../../build/gcc-4.3.3/build_mips/staging_dir/usr/
export KERNELPATH=$(TOPDIR)/../../linux/kernels/mips-linux-2.6.15
export UTILPATH=$(TOPDIR)/../utils/bin
export PATH:=$(TOPDIR)/tools:$(TOOLPATH)/bin:$(TOPDIR)/src:${PATH}

PRJ_NAME = rombootdrv

######## CONFIGURATION #########
ifeq ($(BOARD_TYPE),board955x-offload-target) # {
	ifneq (,$(filter _ap136_bootrom,$(BUILD_CONFIG))) # {
		CFLAGS += -DROMBOOTDRV_SUPPORT_GMAC_1000M=1
		CFLAGS += -DAP136_BOOTROM_TGT
		LOADADDR = 0xbd003000
	else # }{
		LOADADDR = 0xbd004000
	endif # }
else # }{
	LOADADDR = 0xbd004000
endif # } board955x-offload-target

CROSS_COMPILE = mips-linux-uclibc-

ifndef CHIP
ifneq ($(MAKECMDGOALS),clean)
$(error Unknown chip type. Please set 'CHIP')
endif
endif

OBJS = drv_main.o lowlevel_init-$(CHIP).o meminit.o gmac_fwd.o rom.addrs-$(CHIP).o tap-$(CHIP).o pci.o

######## END OF CONFIGURATION #########
ifneq ($(V),)
Q =
else
Q = @
endif

.S.s:
	@echo $(abspath $(TOOLPATH)/bin/$(CPP)) $(AFLAGS) $< -o $*.s > .$*.s.cmd
	@echo '[CPP] ' $<
	$(Q)$(CPP) $(AFLAGS) $< -o $*.s

.S.o:
	@echo $(abspath $(TOOLPATH)/bin/$(CC)) $(AFLAGS) -c $< -o $*.o > .$*.o.cmd
	@echo '[CC] ' $<
	$(Q)$(CC) $(AFLAGS) -c $< -o $*.o

.c.o:
	@echo $(abspath $(TOOLPATH)/bin/$(CC)) $(CFLAGS) -c $< -o $*.o > .$*.o.cmd
	@echo '[CC] ' $<
	$(Q)$(CC) $(CFLAGS) -c $< -o $*.o

CC =       $(CROSS_COMPILE)gcc
LD =       $(CROSS_COMPILE)ld
OBJCOPY =  $(CROSS_COMPILE)objcopy
OBJDUMP =  $(CROSS_COMPILE)objdump

AFLAGS = -Wa,-gstabs -D__ASSEMBLY__ -g  -Os   -D__KERNEL__ -DTEXT_BASE=$(LOADADDR) -I$(TOPDIR) -I$(TOPDIR)/include -fno-builtin -ffreestanding -nostdinc -pipe  -DCONFIG_MIPS -D__MIPS__  -march=mips32r2 -mno-abicalls -fno-pic -Werror
CFLAGS = -Wall -Wa,-gstabs -g  -Os   -D__KERNEL__ -I$(TOPDIR) -I$(TOPDIR)/include -fno-builtin -ffreestanding -nostdinc -pipe  -DCONFIG_MIPS -D__MIPS__  -march=mips32r2 -mno-abicalls -fno-pic -Werror

ifeq ($(emu),1)
$(info "Building for emulation")
AFLAGS += -DCONFIG_ATH_EMULATION=1
CFLAGS += -DCONFIG_ATH_EMULATION=1
endif

ifdef BOOT_FROM_NAND
AFLAGS += -DCONFIG_ATH_NAND_SUPPORT=1
endif

ifeq ($(CHIP),955x)
ifdef pll
flags955	= -Dcfg_pll_freq=$(pll)
else
flags955	= -Dcfg_pll_freq=CFG_PLL_720_600_200
endif
flags955 += -DCONFIG_MACH_AR944x=1 -DCONFIG_MACH_QCA955x=1

CFLAGS += $(flags955)
AFLAGS += $(flags955)

endif

ifeq ($(BOARD_TYPE),board955x-offload-target)
ifneq (,$(filter _tb627 _ap138,$(BUILD_CONFIG)))
CFLAGS += -DATH_SGMII_DOWNLOAD=1
else
ifneq (,$(filter _ap136_bootrom,$(BUILD_CONFIG)))
CFLAGS += -DROMBOOTDRV_SUPPORT_GMAC_1000M=1
CFLAGS += -DAP136_BOOTROM_TGT
endif
endif
endif # board955x-offload-target

ifneq ($(findstring $(BOARD_TYPE), ap136_offld_slave),0)
CFG_BOARD_TYPE=ap136
CFLAGS += -DAP136_BOOTROM_TGT
endif

ifeq ($(BOARD_TYPE),tb627-offld-slave)
CFLAGS += -DATH_SGMII_DOWNLOAD=1
endif

CFLAGS += -DCHIP=$(CHIP) -D__CHIP__=\"$(CHIP)\"

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
	$(UTILPATH)/array2bin fwu_$(PRJ_NAME).c ath_tgt_fw1.fw

clean:
	rm -f *~ *.o $(PRJ_NAME).elf $(PRJ_NAME).srec $(PRJ_NAME).bin fwu_$(PRJ_NAME).c
