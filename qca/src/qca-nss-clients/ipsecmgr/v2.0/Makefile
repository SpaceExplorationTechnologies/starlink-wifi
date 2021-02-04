# Makefile for the ipsecmgr v2.0 client

ccflags-y := -I$(obj)/../.. -I$(obj)/../../exports
ccflags-y += -DNSS_CLIENT_BUILD_ID="$(BUILD_ID)"
ccflags-y += -Werror

obj-m += qca-nss-ipsecmgr.o
qca-nss-ipsecmgr-objs := nss_ipsecmgr_dev.o
qca-nss-ipsecmgr-objs += nss_ipsecmgr_flow.o
qca-nss-ipsecmgr-objs += nss_ipsecmgr_sa.o
ccflags-y += -DNSS_IPSECMGR_DEBUG_LEVEL=3
