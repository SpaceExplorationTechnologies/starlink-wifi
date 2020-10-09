
ARCH:=aarch64
CPU_TYPE:=cortex-a53
SUBTARGET:=ipq807x_64
BOARDNAME:=QCA IPQ807x(64bit) based boards
KERNELNAME:=Image dtbs

DEFAULT_PACKAGES += \
	sysupgrade-helper kmod-usb-phy-ipq807x

define Target/Description
        Build images for IPQ807x 64 bit system.
endef
