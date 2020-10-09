include $(TOPDIR)/rules.mk

PKG_NAME:=wireless-regdb

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://git.kernel.org/pub/scm/linux/kernel/git/sforshee/wireless-regdb.git
PKG_SOURCE_DATE:=2017-12-23
PKG_SOURCE_VERSION:=1c1aec3fb727ed9885b9d2dc0485522bb3c4f71f
#PKG_MIRROR_HASH:=5f5b669f32ae36cb65b1d99efbbbfd42c2983cda32f6448346e3e54ffaba3889

PKG_MAINTAINER:=Felix Fietkau <nbd@nbd.name>

include $(INCLUDE_DIR)/package.mk

define Package/wireless-regdb
  SECTION:=firmware
  CATEGORY:=Firmware
  URL:=$(patsubst pub/scm,cgit,$(PKG_SOURCE_URL))
  TITLE:=Wireless Regulatory Database
endef

define Build/Compile
	git clone https://source.codeaurora.org/quic/qsdk/oss/system/feeds/wlan-open -b coconut $(PKG_BUILD_DIR)/tmp
	cp $(PKG_BUILD_DIR)/db.txt $(PKG_BUILD_DIR)/regdb.txt
	python $(PKG_BUILD_DIR)/db2fw.py $(PKG_BUILD_DIR)/regulatory.db $(PKG_BUILD_DIR)/regdb.txt
endef

define Package/wireless-regdb/install
	$(INSTALL_DIR) $(1)/lib/firmware
	$(CP) $(PKG_BUILD_DIR)/regulatory.db $(1)/lib/firmware/
endef

$(eval $(call BuildPackage,wireless-regdb))
