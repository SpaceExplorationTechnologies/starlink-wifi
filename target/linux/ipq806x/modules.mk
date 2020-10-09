define KernelPackage/usb-phy-qcom-dwc3
  TITLE:=DWC3 USB QCOM PHY driver
  DEPENDS:=@TARGET_ipq806x
  KCONFIG:= CONFIG_PHY_QCOM_DWC3
  FILES:= $(LINUX_DIR)/drivers/phy/phy-qcom-dwc3.ko
  AUTOLOAD:=$(call AutoLoad,45,phy-qcom-dwc3,1)
  $(call AddDepends/usb)
endef

define KernelPackage/usb-phy-qcom-dwc3/description
 This driver provides support for the integrated DesignWare
 USB3 IP Core within the QCOM SoCs.
endef

$(eval $(call KernelPackage,usb-phy-qcom-dwc3))

define KernelPackage/usb-dwc3-of-simple
  TITLE:=DWC3 USB simple OF driver
  DEPENDS:=+kmod-usb-dwc3
  KCONFIG:= CONFIG_USB_DWC3_OF_SIMPLE
  FILES:= $(LINUX_DIR)/drivers/usb/dwc3/dwc3-of-simple.ko
  AUTOLOAD:=$(call AutoLoad,53,dwc3-of-simple,1)
  $(call AddDepends/usb)
endef

define KernelPackage/usb-dwc3-of-simple/description
  This driver provides generic platform glue for the integrated DesignWare USB3 IP Core.
endef

$(eval $(call KernelPackage,usb-dwc3-of-simple))

define KernelPackage/usb-dwc3-qcom
  TITLE:=DWC3 USB QCOM controller driver
  DEPENDS:=@TARGET_ipq806x +kmod-usb-dwc3 +kmod-usb-phy-dwc3-qcom
  KCONFIG:= CONFIG_USB_DWC3_QCOM
  FILES:= $(LINUX_DIR)/drivers/usb/dwc3/dwc3-qcom.ko
  AUTOLOAD:=$(call AutoLoad,53,dwc3-qcom,1)
  $(call AddDepends/usb)
endef

define KernelPackage/usb-dwc3-qcom/description
 This driver provides support for the integrated DesignWare
 USB3 IP Core within the QCOM SoCs.
endef

$(eval $(call KernelPackage,usb-dwc3-qcom))

define KernelPackage/usb-dwc3-ipq40xx
  TITLE:=DWC3 USB IPQ40XX controller driver
  DEPENDS:=@TARGET_ipq806x +kmod-usb-dwc3 +kmod-usb-phy-dwc3-ipq40xx
  KCONFIG:= CONFIG_USB_DWC3_IPQ40XX
  FILES:= $(LINUX_DIR)/drivers/usb/dwc3/dwc3-ipq40xx.ko
  AUTOLOAD:=$(call AutoLoad,53,dwc3-ipq40xx,1)
  $(call AddDepends/usb)
endef

define KernelPackage/usb-dwc3-ipq40xx/description
 This driver provides support for the integrated DesignWare
 USB3 IP Core within the IPQ40xx SoCs.
endef

$(eval $(call KernelPackage,usb-dwc3-ipq40xx))

define KernelPackage/usb-phy-dwc3-qcom
  TITLE:=DWC3 USB QCOM PHY driver
  DEPENDS:=@TARGET_ipq806x
  KCONFIG:= CONFIG_USB_QCOM_DWC3_PHY
  FILES:= \
	$(LINUX_DIR)/drivers/usb/phy/phy-qcom-hsusb.ko \
	$(LINUX_DIR)/drivers/usb/phy/phy-qcom-ssusb.ko
  AUTOLOAD:=$(call AutoLoad,45,phy-qcom-hsusb phy-qcom-ssusb,1)
  $(call AddDepends/usb)
endef

define KernelPackage/usb-phy-dwc3-qcom/description
 This driver provides support for the integrated DesignWare
 USB3 IP Core within the QCOM SoCs.
endef

$(eval $(call KernelPackage,usb-phy-dwc3-qcom))

define KernelPackage/usb-phy-dwc3-ipq40xx
  TITLE:=DWC3 USB IPQ40xx PHY driver
  DEPENDS:=@TARGET_ipq806x
  KCONFIG:= CONFIG_USB_IPQ40XX_PHY
  FILES:= \
	$(LINUX_DIR)/drivers/usb/phy/phy-qca-baldur.ko \
	$(LINUX_DIR)/drivers/usb/phy/phy-qca-uniphy.ko
  AUTOLOAD:=$(call AutoLoad,45,phy-qca-baldur phy-qca-uniphy,1)
  $(call AddDepends/usb)
endef

define KernelPackage/usb-phy-dwc3-ipq40xx/description
 This driver provides support for the integrated DesignWare
 USB3 IP Core within the IPQ40xx SoCs.
endef

$(eval $(call KernelPackage,usb-phy-dwc3-ipq40xx))

define KernelPackage/usb-phy-dwc3-ipq4019
  TITLE:=DWC3 USB IPQ4019 PHY driver
  DEPENDS:=@TARGET_ipq806x +kmod-usb-dwc3-of-simple
  KCONFIG:= CONFIG_PHY_IPQ_BALDUR_USB \
                CONFIG_PHY_IPQ_UNIPHY_USB
  FILES:= \
        $(LINUX_DIR)/drivers/phy/phy-qca-baldur.ko \
        $(LINUX_DIR)/drivers/phy/phy-qca-uniphy.ko
  AUTOLOAD:=$(call AutoLoad,45,phy-qca-baldur phy-qca-uniphy,1)
  $(call AddDepends/usb)
endef

define KernelPackage/usb-phy-dwc3-ipq4019/description
 This driver provides support for the integrated DesignWare
 USB3 IP Core within the IPQ4019 SoCs.
endef

$(eval $(call KernelPackage,usb-phy-dwc3-ipq4019))

define KernelPackage/usb-phy-ipq807x
  TITLE:=DWC3 USB QCOM PHY driver for IPQ807x
  DEPENDS:=@TARGET_ipq806x +kmod-usb-dwc3-of-simple
  KCONFIG:= \
	CONFIG_USB_QCOM_QUSB_PHY \
	CONFIG_USB_QCOM_QMP_PHY
  FILES:= \
	$(LINUX_DIR)/drivers/usb/phy/phy-msm-qusb.ko \
	$(LINUX_DIR)/drivers/usb/phy/phy-msm-ssusb-qmp.ko
  AUTOLOAD:=$(call AutoLoad,45,phy-msm-qusb phy-msm-ssusb-qmp,1)
  $(call AddDepends/usb)
endef

define KernelPackage/usb-phy-ipq807x/description
 This driver provides support for the USB PHY drivers
 within the IPQ807x SoCs.
endef

$(eval $(call KernelPackage,usb-phy-ipq807x))
