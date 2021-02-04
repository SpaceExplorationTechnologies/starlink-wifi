# ###################################################
# # Makefile for the NSS driver
# ###################################################

NSS_CRYPTO_MOD_NAME=qca-nss-crypto

#ccflags-y += -DNSS_CRYPTO_DBG
ccflags-y += -DNSS_CRYPTO_DEBUG_LEVEL=2
ccflags-y += -Werror
ccflags-y += -DNSS_CRYPTO_BUILD_ID=\"'Build_ID - $(shell date +'%m/%d/%y, %H:%M:%S') SoC=$(SoC)'\"

obj-m += $(NSS_CRYPTO_MOD_NAME).o
$(NSS_CRYPTO_MOD_NAME)-objs += nss_crypto_ctrl.o
$(NSS_CRYPTO_MOD_NAME)-objs += nss_crypto_debugfs.o
$(NSS_CRYPTO_MOD_NAME)-objs += engines/nss_crypto_eip197.o
$(NSS_CRYPTO_MOD_NAME)-objs += engines/nss_crypto_eip197_data.o
$(NSS_CRYPTO_MOD_NAME)-objs += nss_crypto_transform.o

obj ?= .
ccflags-y += -I$(obj)/include -I$(obj)/
