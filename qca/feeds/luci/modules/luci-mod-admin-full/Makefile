#
# Copyright (C) 2008-2014 The LuCI Team <luci@lists.subsignal.org>
#
# This is free software, licensed under the Apache License, Version 2.0 .
#

include $(TOPDIR)/rules.mk

LUCI_TITLE:=LuCI Administration - full-featured for full control
LUCI_DEPENDS:=+luci-base

PKG_BUILD_DEPENDS:=iwinfo

TARGET_CFLAGS += -fpie
TARGET_LDFLAGS += -pie

include ../../luci.mk

# call BuildPackage - OpenWrt buildroot signature

