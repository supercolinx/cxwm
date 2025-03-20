CXWM_PATH ?= ${shell pwd}/cxwm

CSRCS += $(shell find $(CXWM_PATH)/src -type f -name '*.c')

CFLAGS += "-I$(CXWM_PATH)"
