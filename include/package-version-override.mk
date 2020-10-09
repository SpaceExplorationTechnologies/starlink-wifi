# Copyright (c) 2013 The Linux Foundation. All rights reserved.
# remember the provided package version
PKG_VERSION_ORGINAL:=$(PKG_VERSION)

# in case that another version is provided, overwrite the original
ifeq ($(CONFIG_$(PKG_NAME)_USE_CUSTOM_VERSION),y)
PKG_VERSION:=$(call qstrip,$(CONFIG_$(PKG_NAME)_CUSTOM_VERSION))
PKG_SOURCE:=$(subst $(PKG_VERSION_ORGINAL),$(PKG_VERSION),$(PKG_SOURCE))
PKG_BUILD_DIR:=$(subst $(PKG_VERSION_ORGINAL),$(PKG_VERSION),$(PKG_BUILD_DIR))
PKG_MD5SUM:=
endif

# package specific configuration
# if includeded the package version can be overwritten within the .config file (instead of changing the package specific Makefile)
# $(1): package name
# $(2): list of selected versions. if missing, will use an input string
define Package/$(PKG_NAME)/override_version
	menu "overwrite package version"
		depends on PACKAGE_$(1)
	config $(PKG_NAME)_USE_CUSTOM_VERSION
		depends on PACKAGE_$(1)
		bool "Use custom package version"
		default n
$(if $(2),
	choice
		prompt "select version"
		depends on $(PKG_NAME)_USE_CUSTOM_VERSION
	$(foreach version,$(2),
		config $(1)_VERSION_$(version)
			bool "$(version)")
	endchoice
	config $(PKG_NAME)_CUSTOM_VERSION
		string
	$(foreach version,$(2),
		default "$(version)" if $(1)_VERSION_$(version))
,
	config $(PKG_NAME)_CUSTOM_VERSION
		depends on $(PKG_NAME)_USE_CUSTOM_VERSION
		string "$(PKG_NAME) version as string (default version: $(PKG_VERSION_ORGINAL))"
		default "$(PKG_VERSION_ORGINAL)"
)
	endmenu
endef

# in case that an customer source path is provided, set the acc. default variable
ifeq ($(CONFIG_$(PKG_NAME)_USE_CUSTOM_SOURCE_DIR),y)
PKG_DEFAULT_CUSTOM_SOURCE_DIR:= $(call qstrip,$(CONFIG_$(PKG_NAME)_CUSTOM_SOURCE_DIR))
endif

# package specific configuration
# if includeded the package source path can be overwritten within the .config file (instead of changing the package specific Makefile)
# instead of using a source ball (eg tar.gz) the specified path will point to the location of the sources
define Package/$(PKG_NAME)/override_source_path
	menu "custom source directory"
		depends on PACKAGE_$(1)
	config $(PKG_NAME)_USE_CUSTOM_SOURCE_DIR
		depends on PACKAGE_$(1)
		bool "Use custom source directory"
		default n
	config $(PKG_NAME)_CUSTOM_SOURCE_DIR
		depends on $(PKG_NAME)_USE_CUSTOM_SOURCE_DIR
		string "Custom source directory"
		default "$(PKG_DEFAULT_CUSTOM_SOURCE_DIR)"
	endmenu
endef

# default:
# include both configurations as long this file is included before package.mk
# in case that you're defining your own onfiguration within the package Makefile just include the stuff by yourself
define Package/$(PKG_NAME)/config
   $(call Package/$(PKG_NAME)/override_version,$(PKG_NAME))
   $(call Package/$(PKG_NAME)/override_source_path,$(PKG_NAME))
endef

define KernelPackage/$(PKG_NAME)/config
   $(call Package/$(PKG_NAME)/override_version,kmod-$(PKG_NAME))
   $(call Package/$(PKG_NAME)/override_source_path,kmod-$(PKG_NAME))
endef

# hook for custom source path
# in case that the specified path is valid a link to the PKG_SOURCE_DIR is created
# otherwise the make is stopped
define prepare_custom_source_directory
	if [ -d $(CONFIG_$(PKG_NAME)_CUSTOM_SOURCE_DIR) ]; then \
		rm -Rf $(PKG_BUILD_DIR); \
		echo "Preparing Custom Source Directory link: $(CONFIG_$(PKG_NAME)_CUSTOM_SOURCE_DIR)"; \
		ln -snf $(CONFIG_$(PKG_NAME)_CUSTOM_SOURCE_DIR) $(PKG_BUILD_DIR); \
	else \
		echo "Custom Source Directory $(CONFIG_$(PKG_NAME)_CUSTOM_SOURCE_DIR) is invalid"; \
		false; \
	fi
endef

