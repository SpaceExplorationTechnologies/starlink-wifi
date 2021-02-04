# top level project rules for the ipq806x project
#
LOCAL_DIR := $(GET_LOCAL_DIR)

TARGET := ipq806x

MODULES += app/shell app/aboot

ifeq ($(TARGET_BUILD_VARIANT),user)
DEBUG := 0
else
DEBUG := 1
endif

#DEFINES += WITH_DEBUG_DCC=1
DEFINES += WITH_DEBUG_UART=1
#DEFINES += WITH_DEBUG_FBCON=1
DEFINES += DEVICE_TREE=1

ENABLE_THUMB := false
DEFINES += CRYPTO_BAM_SUPPORT=1
