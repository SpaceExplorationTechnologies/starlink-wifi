# ROM version
ifdef BOOT_FROM_NAND #{
ifeq ($(COMPRESSED_UBOOT),1) #{
TEXT_BASE = 0x80010000
BOOTSTRAP_TEXT_BASE = 0xa0100000
else #}{
TEXT_BASE = 0xa0100000
endif #}
else #}{
ifeq ($(COMPRESSED_UBOOT),1) #{
TEXT_BASE = 0x80010000
BOOTSTRAP_TEXT_BASE = 0x9f000000
else #}{
TEXT_BASE = 0x9f000000
endif #}
endif #}
# TEXT_BASE = 0xbf000000

# SDRAM version
# TEXT_BASE = 0x80000000

# RAM version
# TEXT_BASE = 0x83fc0000
# TEXT_BASE = 0x80100000

export BOARD_EXTRA_OBJS_tmp =

BOARD_EXTRA_OBJS_tmp += $(TOPDIR)/board/$(BOARDDIR)/extra.o
ifeq ($(BOOT_FROM_NAND),1)
BOARD_EXTRA_OBJS_tmp += $(TOPDIR)/board/$(VENDOR)/common/ath_nand.o $(TOPDIR)/drivers/nand/nand_ids.o
endif

ifeq ($(COMPRESSED_UBOOT),1) #{
BOARD_EXTRA_OBJS = $(BOARD_EXTRA_OBJS_tmp)
endif
