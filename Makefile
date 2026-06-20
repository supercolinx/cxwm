# author: Colin X
# date: Thu Jan 15 19:30:29 CST 2026
# description:

TARGET	= cwm

SUB_LVGL	= lvgl
SUB_LVDRIVERS	= lv_drivers
SUB_CUSTOM	= custom
SUB_UI		= ui

.PHONY: lvgl lv_drivers custom ui install uninstall clean distclean

ifeq ($(ARCH),arm)
export CROSS_COMPILE	=
else
LDFLAGS	= -lSDL2
endif
export CFLAGS	= -march=native -Wall -std=gnu99 -O2
export BUILDIR	= $(abspath ./build)

CC	= $(CROSS_COMPILE)gcc
AR	= $(CROSS_COMPILE)ar

all: prepare default

prepare:
	@mkdir -p $(BUILDIR)

default: main.c lvgl lv_drivers custom ui
	@$(CC) $< -I. $(CFLAGS) \
		$(BUILDIR)/libui.a \
		$(BUILDIR)/libcustom.a \
		$(BUILDIR)/liblv_drivers.a \
		$(BUILDIR)/liblvgl.a \
		$(LDFLAGS) -o $(BUILDIR)/$(TARGET)

lvgl: prepare
	@$(MAKE) -C $(SUB_LVGL)

lv_drivers: prepare
	@$(MAKE) -C $(SUB_LVDRIVERS)

custom: lvgl lv_drivers
	@$(MAKE) -C $(SUB_CUSTOM)

ui: lvgl lv_drivers custom
	@$(MAKE) -C $(SUB_UI)

uninstall:

intstall:

clean:
	@$(MAKE) -C $(SUB_UI) clean
	@$(MAKE) -C $(SUB_CUSTOM) clean
	@rm -f $(BUILDIR)/$(TARGET)

distclean: clean
	@$(MAKE) -C $(SUB_LVGL) clean
	@$(MAKE) -C $(SUB_LVDRIVERS) clean

run:
	@./build/$(TARGET)
