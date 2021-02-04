################################################################################
#
# Copyright (c) 2012, 2014, 2016 The Linux Foundation. All rights reserved.
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License version 2 as published by 
# the Free Software Foundation.
#
################################################################################

# Target module name
TARGET := hyfi-bridging

# Kernel directory - This works only for the host.
# The target kernel is different, and it can't be detected.
ifndef KERNELPATH
KERNELPATH := /lib/modules/$(shell uname -r)/build
endif

HYFI_NF := ./hyfi-netfilter
HYFI_MC := ./hyfi-multicast

# Include directories
INCLUDES := -I$(CURDIR) \
    -I$(KERNELPATH)/include/linux \
    -I$(KERNELPATH)/include/asm \
    -I$(KERNELPATH)/net/bridge \
    -I$(KBUILDPATH)/include/linux \
    -I$(KBUILDPATH)/include/asm \
    -I$(KBUILDPATH)/net/bridge \
    -I$(MDIR)/$(HYFI_NF) \
    -I$(MDIR)/$(HYFI_MC) \
    -I$(STAGING_DIR)/usr/include/qca-ssdk

export EXTRA_CFLAGS += $(INCLUDES)

# Module extra compilation flags
EXTRA_CFLAGS += -Werror -Wall -g $(QCACFLAGS)

ifeq ($(strip ${HYBRID_MC_MLD}),1)
ccflags-y+=-DHYBRID_MC_MLD
endif

ifeq ($(strip ${PLC_SUPPORT_NETFILTER}),1)
ccflags-y+=-DPLC_NF_ENABLE
endif

# #############################################################################
# Debug flags, set these to = 0 if you want to disable all debugging.
# By turning off debugs you gain maximum performance.
# #############################################################################
ccflags-y += -DHYFI_NF_DEBUG_LEVEL=1
ccflags-y += -DHYFI_MC_DEBUG_LEVEL=1

# Kernel module compilation - part 2
ifneq ($(KERNELRELEASE),)
obj-m += $(TARGET).o

# Target objects - add as many as required
$(TARGET)-objs := \
	$(HYFI_NF)/hyfi_main.o \
	$(HYFI_NF)/hyfi_bridge.o \
	$(HYFI_NF)/hyfi_netfilter.o \
	$(HYFI_NF)/hyfi_hatbl.o \
	$(HYFI_NF)/hyfi_hdtbl.o \
	$(HYFI_NF)/hyfi_netlink.o \
	$(HYFI_NF)/hyfi_fdb.o \
	$(HYFI_NF)/hyfi_notify.o \
	$(HYFI_NF)/hyfi_seamless.o \
	$(HYFI_NF)/hyfi_aggr.o \
	$(HYFI_NF)/hyfi_ecm.o \
	$(HYFI_MC)/mc_main.o \
	$(HYFI_MC)/mc_netlink.o \
	$(HYFI_MC)/mc_netfilter.o \
	$(HYFI_MC)/mc_snooping.o \
	$(HYFI_MC)/mc_forward.o \
	$(HYFI_MC)/mc_ecm.o

else 

# Makefile targets - part 1

all: build install

build:
	@$(MAKE) -C $(KERNELPATH) M=`pwd` modules MDIR=$(CURDIR)

install:
	@install -m 644 $(TARGET).ko $(MODULEPATH)
	@install -m 644 $(KERNELPATH)/net/bridge/bridge.ko $(MODULEPATH)
	@install -m 644 $(KERNELPATH)/net/llc/llc.ko $(MODULEPATH)
	@install -m 644 $(KERNELPATH)/net/802/stp.ko $(MODULEPATH)

uninstall:
	@find $(MODULEPATH) -name $(TARGET).ko | xargs rm -rf

clean:
	@$(MAKE) -C $(KERNELPATH) M=`pwd` clean
	@rm -f Module.symvers

endif
