################################################################################
#
# QCA HyFi QDISC for rising priority of local managed protocol.
# Copyright (c) 2013 The Linux Foundation. All rights reserved.- modified from net/sched/sch_generic.c.
#
#		This program is free software; you can redistribute it and/or
#		modify it under the terms of the GNU General Public License
#		and version 2 as published by the Free Software Foundation.
#
################################################################################

# Target module name
TARGET := hyfi_qdisc

# Kernel directory - This works only for the host.
# The target kernel is different, and it can't be detected.
ifndef KERNELPATH
KERNELPATH := /lib/modules/$(shell uname -r)/build
endif

# Include directories
INCLUDES := -I$(CURDIR) \
    -I$(KERNELPATH)/include/linux \
    -I$(KERNELPATH)/include/asm

export EXTRA_CFLAGS += $(INCLUDES)

# Module extra compilation flags
EXTRA_CFLAGS += -Werror -Wall -g

# Kernel module compilation - part 2
ifneq ($(KERNELRELEASE),)
obj-m += $(TARGET).o

# Target objects - add as many as required
$(TARGET)-objs := \
	hyfi_qdisc_main.o

else 

# Makefile targets - part 1

all: build install

build:
	@$(MAKE) -C $(KERNELPATH) M=`pwd` modules

install:
	@install -m 644 $(TARGET).ko $(MODULEPATH)

uninstall:
	@find $(MODULEPATH) -name $(TARGET).ko | xargs rm -rf

clean:
	@$(MAKE) -C $(KERNELPATH) M=`pwd` clean
	@rm -f Module.symvers

endif
