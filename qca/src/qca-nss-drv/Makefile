# ###################################################
# # Makefile for the NSS driver
# ###################################################

obj-m += qca-nss-drv.o

#
# List the files that belong to the driver in alphabetical order.
#
qca-nss-drv-objs := \
			nss_bridge.o \
			nss_c2c_tx.o \
			nss_c2c_tx_stats.o \
			nss_c2c_rx.o \
			nss_c2c_rx_stats.o \
			nss_capwap.o \
			nss_capwap_stats.o \
			nss_cmn.o \
			nss_core.o \
			nss_coredump.o \
			nss_dynamic_interface.o \
			nss_edma.o \
			nss_edma_stats.o \
			nss_eth_rx.o \
			nss_eth_rx_stats.o \
			nss_gre.o \
			nss_gre_stats.o \
			nss_gre_redir.o \
			nss_gre_redir_lag_ds.o \
			nss_gre_redir_lag_ds_stats.o \
			nss_gre_redir_lag_us.o \
			nss_gre_redir_lag_us_stats.o \
			nss_gre_redir_stats.o \
			nss_gre_tunnel.o \
			nss_gre_tunnel_stats.o \
			nss_if.o \
			nss_init.o \
			nss_ipsec.o \
			nss_ipv4.o \
			nss_ipv4_stats.o \
			nss_ipv4_log.o \
			nss_ipv4_reasm.o \
			nss_ipv4_reasm_stats.o \
			nss_ipv6.o \
			nss_ipv6_stats.o \
			nss_ipv6_log.o \
			nss_ipv6_reasm.o \
			nss_ipv6_reasm_stats.o \
			nss_l2tpv2.o \
			nss_l2tpv2_stats.o \
			nss_lag.o \
			nss_log.o \
			nss_lso_rx.o \
			nss_lso_rx_stats.o \
			nss_map_t.o \
			nss_map_t_stats.o \
			nss_n2h.o \
			nss_n2h_stats.o \
			nss_oam.o \
			nss_phys_if.o \
			nss_pm.o \
			nss_profiler.o \
			nss_project.o \
			nss_portid.o \
			nss_portid_stats.o \
			nss_ppe.o \
			nss_ppe_stats.o \
			nss_pppoe.o \
			nss_pppoe_stats.o \
			nss_pptp.o \
			nss_pptp_stats.o \
			nss_rps.o \
			nss_qrfs.o \
			nss_qrfs_stats.o \
			nss_shaper.o \
			nss_sjack.o \
			nss_sjack_stats.o \
			nss_stats.o \
			nss_tstamp.o \
			nss_tun6rd.o \
			nss_trustsec_tx.o \
			nss_trustsec_tx_stats.o \
			nss_tunipip6.o \
			nss_virt_if.o \
			nss_virt_if_stats.o \
			nss_vlan.o \
			nss_tstamp.o \
			nss_wifi.o \
			nss_wifi_stats.o \
			nss_wifi_vdev.o \
			nss_wifi_if.o \
			nss_wifi_if_stats.o \
			nss_wifili.o \
			nss_wifili_stats.o

#
# TODO: Deprecated files should be removed before merge
#
qca-nss-drv-objs += nss_tx_rx_virt_if.o \
			nss_tx_rx_virt_if_stats.o

# Base NSS data plane/HAL support
qca-nss-drv-objs += nss_data_plane/nss_data_plane.o
qca-nss-drv-objs += nss_hal/nss_hal.o

ifeq ($(SoC),$(filter $(SoC),ipq806x ipq40xx))
qca-nss-drv-objs += nss_data_plane/nss_data_plane_gmac.o \
		    nss_hal/ipq806x/nss_hal_pvt.o \
		    nss_dtls.o \
		    nss_dtls_stats.o \
		    nss_crypto.o
ccflags-y += -I$(obj)/nss_hal/ipq806x -DNSS_HAL_IPQ806X_SUPPORT
endif

ifeq ($(SoC),$(filter $(SoC),ipq807x ipq807x_64))
qca-nss-drv-objs += nss_data_plane/nss_data_plane_edma.o \
		    nss_hal/ipq807x/nss_hal_pvt.o \
		    nss_dtls_cmn.o \
		    nss_crypto_cmn.o
ccflags-y += -I$(obj)/nss_hal/ipq807x -DNSS_HAL_IPQ807x_SUPPORT
endif

ccflags-y += -I$(obj)/nss_hal/include -I$(obj)/nss_data_plane/include -I$(obj)/exports -DNSS_DEBUG_LEVEL=0 -DNSS_PKT_STATS_ENABLED=1

ccflags-y += -DNSS_PM_DEBUG_LEVEL=0 -DNSS_SKB_RECYCLE_SUPPORT=1
ifneq ($(findstring 4.4, $(KERNELVERSION)),)
ccflags-y += -DNSS_CACHED_RING=1
else
ccflags-y += -DNSS_CACHED_RING=0
endif
ccflags-y += -Werror

ifneq ($(findstring 3.4, $(KERNELVERSION)),)
NSS_CCFLAGS = -DNSS_DT_SUPPORT=0 -DNSS_FW_DBG_SUPPORT=1 -DNSS_PM_SUPPORT=1 -DNSS_EMPTY_BUFFER_SIZE=1984
else
NSS_CCFLAGS = -DNSS_DT_SUPPORT=1 -DNSS_FW_DBG_SUPPORT=0 -DNSS_PM_SUPPORT=0 -DNSS_EMPTY_BUFFER_SIZE=1984

ccflags-y += -I$(obj)
endif

# Fabric scaling is supported in 3.14 and 4.4 only
ifneq ($(findstring 3.14, $(KERNELVERSION)),)
NSS_CCFLAGS += -DNSS_FABRIC_SCALING_SUPPORT=1
else ifneq ($(findstring 4.4, $(KERNELVERSION)),)
NSS_CCFLAGS += -DNSS_FABRIC_SCALING_SUPPORT=1
else
NSS_CCFLAGS += -DNSS_FABRIC_SCALING_SUPPORT=0
endif

# Disable Frequency scaling
ifeq "$(NSS_FREQ_SCALE_DISABLE)" "y"
ccflags-y += -DNSS_FREQ_SCALE_SUPPORT=0
else
qca-nss-drv-objs += nss_freq.o
ccflags-y += -DNSS_FREQ_SCALE_SUPPORT=1
endif

ccflags-y += $(NSS_CCFLAGS)

export NSS_CCFLAGS

obj ?= .
