#
# Copyright (c) 2015, The Linux Foundation. All rights reserved.
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

include $(TOPDIR)/rules.mk

PKG_NAME:=gobinet
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)
PKG_RELEASE:=1

include $(INCLUDE_DIR)/local-development.mk
include $(INCLUDE_DIR)/package-version-override.mk

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/kernel.mk

define KernelPackage/$(PKG_NAME)
  SUBMENU:=USB Support
  DEPENDS:=@TARGET_ipq806x||TARGET_ipq_ipq40xx  +kmod-usb-net
  TITLE:=Kernel USB driver for GobiNet3000
  VARIANT:=gobinet
  FILES:= $(PKG_BUILD_DIR)/GobiNet/GobiNet.ko
  AUTOLOAD:=$(call AutoLoad,81,GobiNet)
endef

define KernelPackage/$(PKG_NAME)/description
  This package contains the QCA gobinet source
endef

define Package/charlietalk
   TITLE:=Qualcomm GobiNet Connection Manager
   SECTION:=utils
   CATEGORY:=Utilities
   DEPENDS:=@TARGET_ipq806x||TARGET_ipq_ipq40xx +libpthread +libc +librt +libstdcpp +libuci +kmod-qca-wifi-unified-profile +kmod-gobinet
   VARIANT:=charlietalk
endef

define Package/charlietalk/description
   Qualcomm GobiNet Connection Manager
endef

TARGET_CXXFLAGS += -lpthread -lrt -luci

define Build/Configure
	$(call Build/Compile/gobinet)
endef

define Build/Compile/gobinet
	$(MAKE) -C $(LINUX_DIR) \
                CROSS_COMPILE=$(TARGET_CROSS) \
                ARCH="$(LINUX_KARCH)" \
                SUBDIRS="$(PKG_BUILD_DIR)/GobiNet" \
                EXTRA_CFLAGS="$(EXTRA_CFLAGS)" \
                CXXFLAGS="$(TARGET_CXXFLAGS)" \
                modules
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/lib/modules/$(KERNEL_VERSION)
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/GobiNet/GobiNet.ko $(1)/lib/modules/$(KERNEL_VERSION)/
endef

define Package/charlietalk/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/lib/charlietalk
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DIR) $(1)/etc/hotplug.d/usb
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/GobiSampleCM/charlietalkd $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/GobiSampleCM/libgobicm.so $(1)/usr/lib/
	$(INSTALL_BIN) ./files/usr/bin/charlietalk $(1)/usr/bin/lte-cm
	$(INSTALL_DATA) ./files/etc/config/charlietalk $(1)/etc/config/
	$(INSTALL_DATA) ./files/usr/lib/charlietalk/lte_channel_table.txt $(1)/usr/lib/charlietalk/
	$(INSTALL_DATA) ./files/etc/hotplug.d/usb/10-usb_charlietalk $(1)/etc/hotplug.d/usb/
endef

$(eval $(call KernelPackage,$(PKG_NAME)))
$(eval $(call BuildPackage,charlietalk))
