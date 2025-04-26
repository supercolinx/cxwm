WM_PATH ?= ${shell pwd}/wm

CSRCS += $(shell find $(WM_PATH)/src -type f -name '*.c')

CFLAGS += "-I$(WM_PATH)"
