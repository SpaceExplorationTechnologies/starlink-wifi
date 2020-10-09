
SUBTARGET:=ipq807x
BOARDNAME:=QCA IPQ807x(32bit) based boards
CPU_TYPE:=cortex-a7

DEFAULT_PACKAGES += \
	uboot-2016-ipq807x sysupgrade-helper kmod-usb-phy-ipq807x

define Target/Description
	Build firmware image for IPQ807x SoC devices.
endef
