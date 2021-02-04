#Makefile to generate appsboot.mbn

ifeq ($(BOOTLOADER_OUT),.)
APPSBOOTOUT_DIR  := $(BUILDDIR)
else
APPSBOOTOUT_DIR  := $(BOOTLOADER_OUT)/../..
endif

APPSBOOTHEADER: appsboot.mbn

appsboot.mbn: $(OUTELF_STRIP)
	$(hide) cp -f $(OUTELF) $(APPSBOOTOUT_DIR)/appsboot.mbn
