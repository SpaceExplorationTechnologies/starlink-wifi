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

SUBDIRS = commonUTF device tcmd_utf testScriptIF wmiHostIF utf_cal

endif

# Keep things simple -- no special flags
LDEFS =


#############################################################
# Configuration i.e. compile options etc.
# Target specific stuff (defines etc.) goes in here!
# Generally values applying to a tree are captured in the
#   makefile at its root level - these are then overridden
#   for a subtree within the makefile rooted therein
#


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

PROTOCOL_INC_DIR := $(PROTOCOL_COMPONENT_DIR)/include
MAC_CORE_SRC_DIR := $(MAC_CORE_COMPONENT_DIR)/src
HALPHY_INC_DIR := $(HALPHY_COMPONENT_DIR)/include
HALPHY_TOOLS_COMMON_DIR := $(HALPHY_TOOLS_COMPONENT_DIR)/common

INCLUDES := $(INCLUDES) -I $(PDIR)include 
INCLUDES := $(INCLUDES) -I $(HALPHY_INC_DIR) -I $(HALPHY_TOOLS_COMPONENT_DIR)/include/tlv1 -I $(HALPHY_TOOLS_COMMON_DIR)/tlv2p0/include
INCLUDES := $(INCLUDES) -I $(PROTOCOL_INC_DIR)/include -I $(PROTOCOL_INC_DIR)/src/include
INCLUDES := $(INCLUDES) -I $(MAC_CORE_SRC_DIR)/wal/include -I $(MAC_CORE_SRC_DIR)/wal/whal/include 
INCLUDES := $(INCLUDES) -I $(MAC_CORE_SRC_DIR)/wal/AR/include -I $(MAC_CORE_SRC_DIR)/wal/AR/tx -I $(MAC_CORE_SRC_DIR)/wal/AR/rx

PDIR := ../$(PDIR)
sinclude $(PDIR)Makefile
