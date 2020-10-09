include $(TOPDIR)/rules.mk

PKG_NAME:=libb64
PKG_VERSION:=1.2.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).zip
PKG_SOURCE_URL:=https://sourceforge.net/projects/libb64/files/libb64/libb64/
PKG_MD5SUM:=8a5dc72eb7e32f074605260bc127c764

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libb64
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=ANSI C routines for en/decoding base64 format
endef

define Package/libb64/description
 libb64 is a library of ANSI C routines for fast encoding/decoding data
 into and from a base64-encoded format. C++ wrappers are included,
 as well as the source code for standalone encoding and decoding executables.
endef

TARGET_CFLAGS += $(FPIC)
TARGET_CFLAGS += -O3 -Werror -pedantic
CONFIGURE_ARGS += \
	--disable-log \
        --enable-static \
        --enable-shared

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -c $(PKG_BUILD_DIR)/src/cencode.c -o $(PKG_BUILD_DIR)/src/cencode.o -I$(PKG_BUILD_DIR)/include $(FPIC)
	$(TARGET_CC) $(TARGET_CFLAGS) -c $(PKG_BUILD_DIR)/src/cdecode.c -o $(PKG_BUILD_DIR)/src/cdecode.o -I$(PKG_BUILD_DIR)/include $(FPIC)
	$(TARGET_CROSS)gcc -shared -o $(PKG_BUILD_DIR)/libb64.so $(PKG_BUILD_DIR)/src/cencode.o $(PKG_BUILD_DIR)/src/cdecode.o
endef

#Dont call Make install in the package as it doesnt have one
Build/Install=true

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_DIR) $(1)/usr/include/b64
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/include/b64/* $(1)/usr/include/b64
endef

define Package/libb64/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/libb64*.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libb64))
