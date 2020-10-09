include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/version.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=lk-af
PKG_BUILD_DIR:=$(KERNEL_BUILD_DIR)/$(PKG_NAME)-$(BUILD_VARIANT)/$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_PROTO:=git
PKG_BRANCH:=master
PKG_RELEASE:=1
include $(INCLUDE_DIR)/local-development.mk

PKG_SOURCE_VERSION:=$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/lk-ipq806x
  SECTION:=boot
  CATEGORY:=Boot Loaders
  DEPENDS:=@TARGET_ipq806x||TARGET_ipq
  TITLE:=lk bootloader for IPQ806x based platforms
  URL:=
  VARIANT:=ipq806x
endef

define Package/lk-ipq40xx
  SECTION:=boot
  CATEGORY:=Boot Loaders
  DEPENDS:=@TARGET_ipq806x||TARGET_ipq
  TITLE:=lk bootloader for IPQ40xx based platforms
  URL:=
  VARIANT:=ipq40xx
endef

define Package/lk-ipq807x
  SECTION:=boot
  CATEGORY:=Boot Loaders
  DEPENDS:=@TARGET_ipq807x||TARGET_ipq
  TITLE:=lk bootloader for IPQ807x based platforms
  URL:=
  VARIANT:=ipq807x
endef

define Build/Compile
	VERSION_CODE='$(VERSION_NICK) $(VERSION_NUMBER)' \
	REVISION='$(REVISION)' \
	$(MAKE) -C $(PKG_BUILD_DIR) HOSTCC=$(TARGET_CC) \
		ARCH="$(LINUX_KARCH)" QSDK_CFLAGS="$(TARGET_CFLAGS)" \
		QSDK_LDFLAGS="$(TARGET_LDFLAGS)" PROJECT=$(BUILD_VARIANT) \
		TOOLCHAIN_PREFIX="$(TARGET_CROSS)"
endef

define Package/lk-ipq806x/install
	$(INSTALL_DIR) $(1)
	$(CP) $(PKG_BUILD_DIR)/build-ipq806x/appsboot.mbn $(BIN_DIR)/openwrt-$(BUILD_VARIANT)-lkboot.mbn
	$(CP) $(PKG_BUILD_DIR)/build-ipq806x/appsboot.raw $(BIN_DIR)/openwrt-$(BUILD_VARIANT)-lkboot.elf
endef

define Package/lk-ipq40xx/install
	$(INSTALL_DIR) $(1)
	$(CP) $(PKG_BUILD_DIR)/build-ipq40xx/appsboot.mbn $(BIN_DIR)/openwrt-$(BUILD_VARIANT)-lkboot.mbn
	$(STRIP) $(BIN_DIR)/openwrt-$(BUILD_VARIANT)-lkboot.mbn
	$(CP) $(PKG_BUILD_DIR)/build-ipq40xx/lk $(BIN_DIR)/openwrt-$(BUILD_VARIANT)-lkboot.elf
	$(CP) $(PKG_BUILD_DIR)/build-ipq40xx/lk $(BIN_DIR)/openwrt-$(BUILD_VARIANT)-lkboot-stripped.elf
	$(STRIP) $(BIN_DIR)/openwrt-$(BUILD_VARIANT)-lkboot-stripped.elf
endef

define Package/lk-ipq807x/install
	$(INSTALL_DIR) $(1)
	$(CP) $(PKG_BUILD_DIR)/build-ipq807x/lk $(BIN_DIR)/openwrt-$(BUILD_VARIANT)-lkboot.elf
endef

$(eval $(call BuildPackage,lk-ipq40xx))
$(eval $(call BuildPackage,lk-ipq806x))
$(eval $(call BuildPackage,lk-ipq807x))
