#
# Copyright (c) 2013 The Linux Foundation. All rights reserved.
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk
include ${INCLUDE_DIR}/host.mk

PKG_NAME:=iozone3
PKG_VERSION:=420
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)_$(PKG_VERSION)
PKG_SOURCE_URL:=http://www.iozone.org/src/current
PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar
PKG_MD5SUM:=5205cd571c6e68440772f7e0af0712d6
PKG_ASLR_PIE:=0

include $(INCLUDE_DIR)/package.mk

MAKE_PATH:=src/current
ifeq ($(ARCH),aarch64)
MAKE_FLAGS += linux-arm
else
MAKE_FLAGS += linux-$(ARCH)
endif

PKG_BUILD_BIN:=$(PKG_BUILD_DIR)/$(MAKE_PATH)

define Package/iozone
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=IOzone file system benchmark tool
  DEPENDS:=+librt +libpthread
  URL:=http://www.iozone.org/
  MENU:=1
endef

define Package/iozone/description
  IOzone is a filesystem benchmark tool. The benchmark generates and measures a variety of file operations.\
  The benchmark tests file, I/O performance for the operations like Read, write, re-read, re-write,\
  read backwards, read strided, fread, fwrite, random read, pread ,mmap, aio_read, aio_write.
endef

define Package/iozone/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_BIN)/iozone $(1)/usr/sbin/
endef

$(eval $(call BuildPackage,iozone))
