
SUBTARGET:=ipq806x
BOARDNAME:=QCA IPQ806x based boards
CPU_TYPE:=cortex-a7

DEFAULT_PACKAGES += \
	uboot-ipq806x uboot-ipq806x-fwupgrade-tools lk-ipq806x \
	kmod-usb-dwc3-qcom kmod-usb-phy-qcom-dwc3 kmod-usb-dwc3-of-simple \
	uboot-2016-ipq806x uboot-2016-ipq806x_standard

define Target/Description
	Build firmware image for IPQ806x SoC devices.
endef
