LOCAL_DIR := $(GET_LOCAL_DIR)

OBJS += \
	$(LOCAL_DIR)/init.o \
	$(LOCAL_DIR)/target_display.o

#Enable Splash Screen
CFLAGS += -DDISPLAY_SPLASH_SCREEN
