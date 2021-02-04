# All DTBs
dtb-$(CONFIG_ATH79)			+= ar9132_tl_wr1043nd_v1.dtb ath79_ap152.dtb ath79_ap152_dual.dtb \
						ath79_ap151.dtb ath79_ap147.dtb ath79_ap143.dtb ath79_ap137.dtb \
						ath79_ap136.dtb ath79_ap135.dtb ath79_ap152_8M.dtb ath79_ap151_8M.dtb \
						ath79_ap147_8M.dtb ath79_ap143_8M.dtb ath79_ap151_v2.dtb ath79_ap147_v2.dtb \
						ath79_ap135_nand.dtb ath79_db120_8M.dtb ath79_db120.dtb ath79_apjet01.dtb \
						ath79_apjet01_32M.dtb ath79_apjet01_dual.dtb

# Select a DTB to build in the kernel
obj-$(CONFIG_DTB_TL_WR1043ND_V1)	+= ar9132_tl_wr1043nd_v1.dtb.o

# Force kbuild to make empty built-in.o if necessary
obj-				+= dummy.o

always				:= $(dtb-y)
clean-files			:= *.dtb *.dtb.S
