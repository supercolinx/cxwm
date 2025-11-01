# xiekangli
#
ROOT_DIR	= $(shell pwd)
SUB_LVGL	= lvgl
SUB_CXWM	= cxwm
BUILD_DIR	= $(ROOT_DIR)/build
INSTALL_PREFIX	= $(ROOT_DIR)/install

CROSS_COMPILE	=
CC	= $(CROSS_COMPILE)gcc
AR	= $(CROSS_COMPILE)ar

.PHONY: lvgl clean install uninstall

all: prepare default

prepare:

lvgl:
	@$(MAKE) -C $(SUB_LVGL) CC=$(CC)

default: lvgl
	@$(MAKE) -C $(SUB_CXWM) CC=$(CC)

clean:
	@$(MAKE) -C $(SUB_CXWM) clean

distclean: clean
	@$(MAKE) -C $(SUB_LVGL) clean
	@rm -rf $(BUILD_DIR)

uninstall:
	@rm -rf $(INSTALL_PREFIX)

install: uninstall
	@mkdir -p $(INSTALL_PREFIX)/lib
	@mkdir -p $(INSTALL_PREFIX)/bin
	@mkdir -p $(INSTALL_PREFIX)/share/
	-@cp $(BUILD_DIR)/lvgl/liblvgl.so $(INSTALL_PREFIX)/lib/
	-@cp $(BUILD_DIR)/cxwm/cxwm $(INSTALL_PREFIX)/bin/
	-@cp -r $(ROOT_DIR)/resources/* $(INSTALL_PREFIX)/share/

run: install
	@cd $(INSTALL_PREFIX) && taskset -c 1 ./bin/cxwm 1920 1080
