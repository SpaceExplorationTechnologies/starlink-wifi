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

SUBDIRS = common

ifeq ($(TARGET),AR9888) # {
SUBDIRS += AR9888
endif # } ifeq ($(TARGET),AR9888)

ifeq ($(TARGET),AR6320) # {
SUBDIRS += AR6320
endif # } ifeq ($(TARGET),AR6320)

ifeq ($(TARGET),AR900B) # {
SUBDIRS += AR900B
endif # } ifeq ($(TARGET),AR900B)

ifeq ($(TARGET),QCA9984) # {
SUBDIRS += AR900B
endif # } ifeq ($(TARGET),AR900B)

ifeq ($(TARGET),QCA9888) # {
SUBDIRS += AR900B
endif # } 

ifeq ($(TARGET),IPQ4019) # {
SUBDIRS += AR900B
endif # } ifeq ($(TARGET),IPQ4019)
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

INCLUDES := $(INCLUDES) -I $(PDIR)include 

PDIR := ../$(PDIR)
sinclude $(PDIR)Makefile
