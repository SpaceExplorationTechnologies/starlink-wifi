# Copyright (c) 2012 Qualcomm Atheros, Inc.
# All Rights Reserved.
# Qualcomm Atheros Confidential and Proprietary.
#
# Copyright (c) 2010 Atheros Communications Inc.
# All rights reserved.
# $ATH_LICENSE_TARGET_MK$
#
#############################################################
# Required variables for each makefile
# Discard this section from all parent makefiles
# Expected variables (with automatic defaults):
#   CSRCS (all "C" files in the dir)
#   SUBDIRS (all subdirs with a Makefile)
#   GEN_LIBS - list of libs to be generated ()
#   GEN_IMAGES - list of images to be generated ()
#   COMPONENTS_xxx - a list of libs/objs in the form
#     subdir/lib to be extracted and rolled up into
#     a generated lib/image xxx.a ()
#
ifndef PDIR

GEN_LIBS = libTLVCmdRsp.a

endif

DEFINES += -D_UTF_HOSTIF_TS_W_WMI


#############################################################
# Configuration i.e. compile options etc.
# Target specific stuff (defines etc.) goes in here!
# Generally values applying to a tree are captured in the
#   makefile at its root level - these are then overridden
#   for a subtree within the makefile rooted therein
#

DEFINES += -DEEPROM_PRESENT		\
	-DUSE_NEW_EEPROM_READ_LOCS_CMD	\
	-DMBOX_COMN			\
	-DMAUI				\
	-DDRAGON			\
	-DTHIN_CLIENT_BUILD		\
	-DMALLOC_ABSENT			\
	-DATH_TARGET			\
	-DATHOS				\
	-D_DEBUG			\

ifeq ($(FPGA_FLAG),1)
DEFINES += -DFPGA
endif

ifeq ($(DEBUG),1)
DEFINES += -D_DEBUG
endif


#############################################################
# Recursion Magic - Don't touch this!!
#
# Each subtree potentially has an include directory
#   corresponding to the common APIs applicable to modules
#   rooted at that subtree. Accordingly, the INCLUDE PATH
#   of a module can only contain the include directories up
#   its parent path, and not its siblings
#
# Required for each makefile to inherit from the parent
#
INCLUDES := $(INCLUDES) -I ../../../src/wlan/umac_unified/include

INCLUDES := $(INCLUDES) -I $(PDIR)include -I../../../src/wlan/wal/whal/include  -I../../../src/wlan/include -I../../../src/wlan/proto/include -I../include -I../../../../../../include/systemtools/common
INCLUDES := $(INCLUDES) -I../common/include
PDIR := ../$(PDIR)
sinclude $(PDIR)Makefile
