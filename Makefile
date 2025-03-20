# xiekangli
#
ROOT_DIR	?= ${shell pwd}
CXWM_DIR_NAME	?= cxwm
LVGL_DIR_NAME	?= lvgl
LVGL_DIR	?= $(ROOT_DIR)
BIN		?= wm
BUILD_DIR	?= $(ROOT_DIR)/build

CC	?= gcc
AR	?= ar

CFLAGS	?= -Wall -std=gnu99 -g #-Werror
LDFLAGS	?= -lSDL2

include $(LVGL_DIR)/$(LVGL_DIR_NAME)/lvgl.mk
include $(LVGL_DIR)/$(CXWM_DIR_NAME)/cxwm.mk

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
	@rm -rf $(BUILD_DIR)/cxwm

distclean:
	@rm -rf $(BUILD_DIR)

cscope:
	@${shell cscope -Rbkq}

run:
	@$(BUILD_DIR)/$(BIN)

debug:
	@gdb $(BUILD_DIR)/$(BIN)
