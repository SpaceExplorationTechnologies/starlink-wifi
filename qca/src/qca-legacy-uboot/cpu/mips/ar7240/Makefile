#
# Copyright (c) 2014 Qualcomm Atheros, Inc.
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
#

include $(TOPDIR)/config.mk

LIB	= lib$(SOC).a

START	=
#OBJS	= ar7240_serial.o ag7240.o ar7240_flash.o meminit.o

OBJS	= meminit.o 

ifeq ($(BOARD), ap121)
OBJS	+= hornet_serial.o
SOBJS	+= hornet_ddr_init.o
else
OBJS	+= ar7240_serial.o
endif

ifneq ($(BUILD_EMU), )
OBJS    += hornet_ag7240.o
else
ifneq ($(findstring db12x,$(BOARD)),)
OBJS    += ag934x.o
else
ifneq ($(findstring reh132,$(BOARD)),)
OBJS    += ag934x.o
else
ifneq ($(findstring dhp,$(BOARD)),)
OBJS    += ag934x.o
else
ifneq ($(findstring aph,$(BOARD)),)
OBJS    += ag934x.o
else
ifneq ($(findstring ap123,$(BOARD)),)
OBJS    += ag934x.o
else
ifneq ($(findstring ap120,$(BOARD)),)
OBJS    += ag934x.o
else
OBJS    += ag7240.o
endif
endif
endif
endif
endif
endif
endif

SOBJS	+= 

all:	.depend $(START) $(LIB)

$(LIB):	$(OBJS) $(SOBJS) $(OBJS-0)
	$(AR) crv $@ $(OBJS) $(SOBJS)

#########################################################################

.depend:	Makefile $(START:.o=.S) $(OBJS:.o=.c)
		$(CC) -M $(CFLAGS) $(START:.o=.S) $(OBJS:.o=.c) > $@

sinclude .depend

#########################################################################
