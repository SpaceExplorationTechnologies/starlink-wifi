#
# Copyright (c) 2014 The Linux Foundation. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
# 
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

include $(TOPDIR)/config.mk

LIB	= lib$(BOARD).a

OBJS	=			\
	$(BOARD).o		\
	flash.o			\
	../common/init-953x.o	\
	../common/serial.o	\
	../common/ath_pci.o	\
	../common/qca-eth-953x.o

#
# The files included in EXTRA_OBJS use some functions that are not
# available in the `bootstrap' portion of tuboot.bin resulting in
# compile/link errors. Hence have them separate (i.e. don't include
# into lib$(BOARD).a and include them only in `u-boot' portion of
# tuboot.bin.
#

ifeq ($(strip $(COMPRESSED_UBOOT)),0) #{
OBJS	+= $(BOARD_EXTRA_OBJS_tmp)
else
EXTRA_OBJS = $(BOARD_EXTRA_OBJS_tmp)
endif #}

ifeq ($(ATH_DUAL_FLASH),1)
OBJS	+= ../../../drivers/nand/nand_ids.o
ifeq ($(ATH_SPI_NAND),1)
OBJS	+= ../common/ath_spi_nand.o
else
OBJS	+= ../common/ath_nand.o
endif
endif

ifndef BOOT_FROM_NAND
OBJS	+= ../common/ath_flash.o
endif

ifeq ($(ATH_RGMII_CAL),1)
OBJS	+= ../common/rgmii-cal-953x.o	
OBJS	+= ../common/athrs17_lpbk.o
endif

ifeq ($(ETH_CONFIG), _f1e)
OBJS	+= ../common/athrsf1_phy.o
endif

ifeq ($(ETH_CONFIG), _vir)
OBJS	+= ../common/athrs_vir_phy.o
endif

ifeq ($(ETH_CONFIG2), _vir)
OBJS	+= ../common/athrs_vir_phy.o
endif

ifeq ($(ETH_CONFIG), _s27)
OBJS	+= ../common/athr_s27_phy.o
endif

SOBJS	= ../common/953x.o ../common/tap-953x.o

$(LIB):	.depend $(OBJS) $(SOBJS) $(EXTRA_OBJS)
	$(AR) crv $@ $(OBJS) $(SOBJS)

#########################################################################

.depend:	Makefile $(SOBJS:.o=.S) $(OBJS:.o=.c)
		$(CC) -M $(CFLAGS) $(SOBJS:.o=.S) $(OBJS:.o=.c) > $@

sinclude .depend

#########################################################################
