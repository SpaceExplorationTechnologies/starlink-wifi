include $(TOPDIR)/rules.mk

PKG_NAME:=libweave
PKG_VERSION:=1.4
PKG_RELEASE=$(PKG_SOURCE_VERSION)
PKG_USE_MIPS16:=0

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=git://codeaurora.org/quic/qsdk/oss/upstream/libweave
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=eae016cab6044d22b150afdf6f3f3cb5cc1c79fd
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz

BUILD_MODE:=Release

include $(INCLUDE_DIR)/package.mk

define Package/libweave
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Google Weave library
  DEPENDS:= +libexpat +libopenssl +libpthread \
	    +libevent2 +libcurl +libavahi-client \
	    +googletest +libevhtp
  URL:=https://weave.googlesource.com/weave/libweave
endef

define Package/libweave/description
	libWeave is the library to with device side implementation of
	Weave protocol.
endef

TARGET_BUILD_ARGS= \
		   -D__linux__ -D__mips__ \
		   -DWORDS_BIGENDIAN \
		   -D_GLIBCXX_USE_C99=1 \
		   -D_GLIBCXX_USE_C99_CHECK=1 \
		   -D_GLIBCXX_USE_C99_DYNAMIC=1 \
		   -D_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC=1 \
		   -fPIC \
		   -I$(STAGING_DIR)/usr/include/libevent \
		   -I$(STAGING_DIR)/usr/include/evhtp \
		   -L$(STAGING_DIR)/usr/lib/libevent \
		   -L$(STAGING_DIR)/usr/lib/gtest \
		   -L$(STAGING_DIR)/usr/lib/gmock \
		   -L$(STAGING_DIR)/usr/lib/libweave

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)/ \
		BUILD_MODE=$(BUILD_MODE) \
		CC="$(TARGET_CC) $(TARGET_BUILD_ARGS)" \
		CFLAGS="$(TARGET_CFLAGS) $(TARGET_CPPFLAGS)" \
		CXX="$(TARGET_CXX) $(TARGET_BUILD_ARGS)" \
		CXXFLAGS="$(TARGET_CXXFLAGS) $(EXTRA_CFLAGS)" \
		LINK="$(TARGET_CROSS)g++ $(TARGET_BUILD_ARGS)" \
		LDFLAGS="$(TARGET_LDFLAGS)" \
		AR="$(TARGET_CROSS)ar"
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/libweave
	$(INSTALL_DIR) $(1)/usr/lib/libweave
	$(INSTALL_DIR) $(1)/usr/sbin
	$(CP) $(PKG_BUILD_DIR)/out/$(BUILD_MODE)/*.so $(1)/usr/lib/libweave
#	$(INSTALL_BIN) $(PKG_BUILD_DIR)/out/$(BUILD_MODE)/*testrunner $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/out/$(BUILD_MODE)/weave_daemon* $(1)/usr/sbin
endef

define Package/libweave/install
	$(INSTALL_DIR) $(1)/lib
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_DIR) $(1)/etc/ssl/certs
	$(CP) $(PKG_BUILD_DIR)/out/$(BUILD_MODE)/*.so $(1)/lib
#	$(INSTALL_BIN) $(PKG_BUILD_DIR)/out/$(BUILD_MODE)/*testrunner $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/out/$(BUILD_MODE)/weave_daemon* $(1)/usr/sbin
	$(INSTALL_DATA) ./files/ca-certificates.crt $(1)/etc/ssl/certs
endef

$(eval $(call BuildPackage,libweave))
