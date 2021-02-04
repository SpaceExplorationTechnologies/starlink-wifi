include $(TOPDIR)/rules.mk

PKG_NAME:=googletest
PKG_VERSION:=1.7.0
PKG_RELEASE=$(PKG_SOURCE_VERSION)

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/google/googletest.git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=71a26ac68b28c61686b8941730a6b2577912e239
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz

include $(INCLUDE_DIR)/package.mk

define Package/googletest
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Google's C++ test framework
  DEPENDS:= +libstdcpp
  URL:=https://github.com/google/googletest.git
endef

define Package/googletest/description
	**Google Mock** is an extension to Google Test for writing and using
	C++ mock classes. See the separate [Google Mock documentation]
	(googlemock/README.md).

	More detailed documentation for googletest (including build instructions)
	are in its interior [googletest/README.md] (googletest/README.md) file.
endef

CONFIGURE_ARGS += \
		 --disable-shared

CONFIGURE_VARS += \
		  CC="$(TARGET_CC)" \
		  CXX="$(TARGET_CXX)"

GTEST_DIR = $(PKG_BUILD_DIR)/googletest
GMOCK_DIR = $(PKG_BUILD_DIR)/googlemock

define GoogletestConfigure
	(cd $(PKG_BUILD_DIR)/$(1); \
		autoreconf -fvi; \
		$(CONFIGURE_VARS) \
		./configure $(CONFIGURE_ARGS)\
	);
endef

define Build/Configure
	$(call GoogletestConfigure,googletest)
	$(call GoogletestConfigure,googlemock)
endef

define Build/Compile
	$(MAKE) -C $(GTEST_DIR)
	$(MAKE) -C $(GMOCK_DIR)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/gtest
	$(INSTALL_DIR) $(1)/usr/include/gmock
	$(CP) $(GTEST_DIR)/include/gtest/* $(1)/usr/include/gtest/
	$(CP) $(GMOCK_DIR)/include/gmock/* $(1)/usr/include/gmock/
	$(INSTALL_DIR) $(1)/usr/lib/gtest
	$(INSTALL_DIR) $(1)/usr/lib/gmock
	$(CP) $(GTEST_DIR)/lib/.libs/*.a $(1)/usr/lib/gtest
	$(CP) $(GMOCK_DIR)/lib/.libs/*.a $(1)/usr/lib/gmock
endef

define Package/googletest/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(GTEST_DIR)/lib/.libs/*.a $(1)/usr/lib
	$(CP) $(GMOCK_DIR)/lib/.libs/*.a $(1)/usr/lib
endef

$(eval $(call BuildPackage,googletest))
