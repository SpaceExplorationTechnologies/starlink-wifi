#
## Makefile for the Qualcomm Atheros ethernet edma driver
#

obj ?= .

obj-m += essedma.o

essedma-objs +=    edma_axi.o \
                   edma.o \
                   edma_stats.o \
                   edma_ethtool.o

ESSEDMA_INCLUDE = -I$(obj)

ccflags-y += $(ESSEDMA_INCLUDE)


