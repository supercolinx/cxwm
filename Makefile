# xiekangli
#
ROOT_DIR	?= $(shell pwd)
WM_DIR_NAME	?= wm
LVGL_DIR_NAME	?= lvgl
BIN		?= cwm
BUILD_DIR	?= $(ROOT_DIR)/build

CC	?= gcc
AR	?= ar

CFLAGS	?= -Wall -std=gnu99 -g #-Werror
LDFLAGS	?= -lSDL2

include $(ROOT_DIR)/$(LVGL_DIR_NAME)/lvgl.mk
include $(ROOT_DIR)/$(WM_DIR_NAME)/wm.mk

CSRCS += main.c

AOBJS	= $(ASRCS:.S=.o)
COBJS	= $(CSRCS:.c=.o)

TARGET	= $(addprefix $(BUILD_DIR)/, $(patsubst $(ROOT_DIR)/%, %, $(COBJS)))

all: default

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$<"

$(BUILD_DIR)/%.o: %.S
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$<"

default: $(TARGET)
	@mkdir -p $(dir $(BUILD_DIR)/)
	@$(CC) -o $(BUILD_DIR)/$(BIN) $(TARGET) $(LDFLAGS)

clean:
	@rm -rf $(BUILD_DIR)/cwm

distclean:
	@rm -rf $(BUILD_DIR)

run:
	@$(BUILD_DIR)/$(BIN)

debug:
	@gdb $(BUILD_DIR)/$(BIN)
