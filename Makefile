# xiekangli
#
ROOT_DIR	= $(shell pwd)
SUB_LVGL	= lvgl
SUB_WM		= wm
BUILD_DIR	= $(ROOT_DIR)/build
INSTALL_PREFIX	= $(ROOT_DIR)/install

CC	= gcc
AR	= ar

.PHONY: lvgl clean install uninstall

all: prepare default

prepare:

lvgl:
	@$(MAKE) -C $(SUB_LVGL) CC=$(CC)

default: lvgl
	@$(MAKE) -C $(SUB_WM) CC=$(CC)

clean:
	@$(MAKE) -C $(SUB_WM) clean

distclean: clean
	@$(MAKE) -C $(SUB_LVGL) clean
	@rm -rf $(BUILD_DIR)

install: uninstall
	@mkdir -p $(INSTALL_PREFIX)/{lib,bin,share/cxwm}
	-@cp $(BUILD_DIR)/lvgl/liblvgl.so $(INSTALL_PREFIX)/lib/
	-@cp $(BUILD_DIR)/wm/cwm $(INSTALL_PREFIX)/bin/
	-@cp -r $(ROOT_DIR)/resources/* $(INSTALL_PREFIX)/share/cxwm/

uninstall:
	@rm -rf $(INSTALL_PREFIX)

run: install
	@cd $(INSTALL_PREFIX) && ./bin/cwm #800 1280
