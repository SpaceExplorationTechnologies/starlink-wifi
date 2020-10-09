#
# Copyright (C) 2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ath10k-firmware
PKG_SOURCE_VERSION:=956e2609b7e42c8c710bba10ef925a5be1be5137
PKG_VERSION:=2017-03-29-$(PKG_SOURCE_VERSION)
PKG_RELEASE:=1

QCA988X_FIRMWARE_FILE:=firmware-5.bin_10.2.4-1.0-00029
QCA9887_FIRMWARE_FILE:=firmware-5.bin_10.2.4-1.0-00029
QCA9888_FIRMWARE_FILE:=firmware-5.bin_10.4-3.4-00082
QCA99X0_FIRMWARE_FILE:=firmware-5.bin_10.4.3.00063-1
QCA9984_FIRMWARE_FILE:=firmware-5.bin_10.4-3.4-00082
QCA4019_FIRMWARE_FILE:=firmware-5.bin_10.4-3.4-00082

PKG_SOURCE_PROTO:=git
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/kvalo/ath10k-firmware.git

PKG_MAINTAINER:=Felix Fietkau <nbd@openwrt.org>

include $(INCLUDE_DIR)/package.mk

WMENU:=Wireless Drivers

define Package/ath10k-firmware-default
  SECTION:=kernel
  CATEGORY:=Kernel modules
  SUBMENU:=$(WMENU)
  URL:=$(PKG_SOURCE_URL)
endef

define Package/ath10k-firmware-qca988x
$(Package/ath10k-firmware-default)
  TITLE:=ath10k firmware for QCA988x devices
endef

define Download/ath10k-firmware-qca988x
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA988X/hw2.0/10.2.4-1.0
  FILE:=$(QCA988X_FIRMWARE_FILE)
endef
$(eval $(call Download,ath10k-firmware-qca988x))

define Download/qca988x-board
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA988X/hw2.0
  FILE:=board.bin
endef
$(eval $(call Download,qca988x-board))

define Package/ath10k-firmware-qca9887
$(Package/ath10k-firmware-default)
  TITLE:=ath10k firmware for QCA9887 devices
endef

define Download/ath10k-firmware-qca9887
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA9887/hw1.0/10.2.4-1.0
  FILE:=$(QCA9887_FIRMWARE_FILE)
endef
$(eval $(call Download,ath10k-firmware-qca9887))

define Download/qca9887-board
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA9887/hw1.0
  FILE:=board.bin
endef
$(eval $(call Download,qca9887-board))

define Package/ath10k-firmware-qca9888
$(Package/ath10k-firmware-default)
  TITLE:=ath10k firmware for QCA9888 devices
endef

define Download/ath10k-firmware-qca9888
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA9888/hw2.0/3.4
  FILE:=$(QCA9888_FIRMWARE_FILE)
endef
$(eval $(call Download,ath10k-firmware-qca9888))

define Download/qca9888-board
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA9888/hw2.0
  FILE:=board-2.bin
endef
$(eval $(call Download,qca9888-board))

define Package/ath10k-firmware-qca99x0
$(Package/ath10k-firmware-default)
  TITLE:=ath10k firmware for QCA99x0 devices
endef

define Package/ath10k-firmware-qca6174
$(Package/ath10k-firmware-default)
  TITLE:=ath10k firmware for QCA6174 devices
endef

QCA99X0_BOARD_REV:=ddcec9efd245da9365c474f513a855a55f3ac7fe
QCA99X0_BOARD_FILE:=board-2.bin.$(QCA99X0_BOARD_REV)

define Download/qca99x0-board
  URL:=https://www.codeaurora.org/cgit/quic/qsdk/oss/firmware/ath10k-firmware/plain/ath10k/QCA99X0/hw2.0
  URL_FILE:=board-2.bin?id=ddcec9efd245da9365c474f513a855a55f3ac7fe
  FILE:=$(QCA99X0_BOARD_FILE)
  MD5SUM:=a2b3c653c2363a5641200051d6333d0a
endef
$(eval $(call Download,qca99x0-board))

define Package/ath10k-firmware-qca9984
$(Package/ath10k-firmware-default)
  TITLE:=ath10k firmware for QCA9984 devices
endef

define Download/ath10k-firmware-qca9984
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA9984/hw1.0/3.4
  FILE:=$(QCA9984_FIRMWARE_FILE)
endef
$(eval $(call Download,ath10k-firmware-qca9984))

define Download/qca9984-board
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA9984/hw1.0
  FILE:=board-2.bin
endef
$(eval $(call Download,qca9984-board))

define Package/ath10k-firmware-qca4019
$(Package/ath10k-firmware-default)
  TITLE:=ath10k firmware for QCA4019 devices
endef

define Download/ath10k-firmware-qca4019
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA4019/hw1.0/3.4
  FILE:=$(QCA4019_FIRMWARE_FILE)
endef
$(eval $(call Download,ath10k-firmware-qca4019))

define Download/qca4019-board
  URL:=https://github.com/kvalo/ath10k-firmware/tree/master/QCA4019/hw1.0
  FILE:=board-2.bin
endef
$(eval $(call Download,qca4019-board))

define Build/Compile

endef

define Package/ath10k-firmware-qca988x/install
	$(INSTALL_DIR) $(1)/lib/firmware/ath10k/QCA988X/hw2.0
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA988X/hw2.0/board.bin \
		$(1)/lib/firmware/ath10k/QCA988X/hw2.0/
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA988X/hw2.0/10.2.4-1.0/$(QCA988X_FIRMWARE_FILE) \
		$(1)/lib/firmware/ath10k/QCA988X/hw2.0/firmware-5.bin
endef

define Package/ath10k-firmware-qca9887/install
	$(INSTALL_DIR) $(1)/lib/firmware/ath10k/QCA9887/hw1.0
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA9887/hw1.0/board.bin \
		$(1)/lib/firmware/ath10k/QCA9887/hw1.0/
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA9887/hw1.0/10.2.4-1.0/$(QCA9887_FIRMWARE_FILE) \
		$(1)/lib/firmware/ath10k/QCA9887/hw1.0/firmware-5.bin
endef

define Package/ath10k-firmware-qca9888/install
	$(INSTALL_DIR) $(1)/lib/firmware/ath10k/QCA9888/hw2.0
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA9888/hw2.0/board-2.bin \
		$(1)/lib/firmware/ath10k/QCA9888/hw2.0/
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA9888/hw2.0/3.4/$(QCA9888_FIRMWARE_FILE) \
		$(1)/lib/firmware/ath10k/QCA9888/hw2.0/firmware-5.bin
endef

define Package/ath10k-firmware-qca9984/install
	$(INSTALL_DIR) $(1)/lib/firmware/ath10k/QCA9984/hw1.0
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA9984/hw1.0/board-2.bin \
		$(1)/lib/firmware/ath10k/QCA9984/hw1.0/
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA9984/hw1.0/3.4/$(QCA9984_FIRMWARE_FILE) \
		$(1)/lib/firmware/ath10k/QCA9984/hw1.0/firmware-5.bin
endef

define Package/ath10k-firmware-qca4019/install
	$(INSTALL_DIR) $(1)/lib/firmware/ath10k/QCA4019/hw1.0
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA4019/hw1.0/board-2.bin \
		$(1)/lib/firmware/ath10k/QCA4019/hw1.0/
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA4019/hw1.0/3.4/$(QCA4019_FIRMWARE_FILE) \
		$(1)/lib/firmware/ath10k/QCA4019/hw1.0/firmware-5.bin
endef

define Package/ath10k-firmware-qca6174/install
	$(INSTALL_DIR) $(1)/lib/firmware/ath10k
	$(CP) $(PKG_BUILD_DIR)/QCA6174 $(1)/lib/firmware/ath10k/
endef

define Package/ath10k-firmware-qca99x0/install
	$(INSTALL_DIR) $(1)/lib/firmware/ath10k/QCA99X0/hw2.0
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/$(QCA99X0_BOARD_FILE) \
		$(1)/lib/firmware/ath10k/QCA99X0/hw2.0/board-2.bin
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/QCA99X0/hw2.0/boardData_AR900B_CUS239_5G_v2_001.bin \
		$(1)/lib/firmware/ath10k/QCA99X0/hw2.0/board.bin
	$(INSTALL_DATA) \
		$(PKG_BUILD_DIR)/$(QCA99X0_FIRMWARE_FILE) \
		$(1)/lib/firmware/ath10k/QCA99X0/hw2.0/firmware-5.bin
endef

$(eval $(call BuildPackage,ath10k-firmware-qca988x))
$(eval $(call BuildPackage,ath10k-firmware-qca9887))
$(eval $(call BuildPackage,ath10k-firmware-qca9888))
$(eval $(call BuildPackage,ath10k-firmware-qca99x0))
$(eval $(call BuildPackage,ath10k-firmware-qca9984))
$(eval $(call BuildPackage,ath10k-firmware-qca6174))
$(eval $(call BuildPackage,ath10k-firmware-qca4019))
