# author: Colin X
# date: Thu Jan 15 19:30:29 CST 2026
# description:

TARGET	= cwm

SUBUSER	= custom ui
SUBDIRS	= lvgl lv_drivers $(SUBUSER)
SUBLIBS	= $(addprefix -l,$(SUBDIRS))

.PHONY: $(SUBDIRS) install uninstall clean distclean

ifeq ($(ARCH),arm)
export CROSS_COMPILE	=
endif
export CFLAGS	= -march=native -Wall -std=gnu99 -O2
export BUILDIR	= $(abspath ./build)
export INSTALL	= $(abspath ./install)

CC	= $(CROSS_COMPILE)gcc
AR	= $(CROSS_COMPILE)ar

all: prepare default

prepare:

default: $(SUBDIRS)
	@mkdir -p $(BUILDIR)
	@$(foreach sub,$(SUBDIRS),$(MAKE) -C $(sub);)

uninstall:
	@$(foreach sub,$(SUBDIRS),$(MAKE) -C $(sub) uninstall;)
	@rm -rf $(INSTALL)/$(TARGET)

install: main.c
	@mkdir -p $(INSTALL)
	@$(foreach sub,$(SUBDIRS),$(MAKE) -C $(sub) install;)
	@$(CC) $< -I. $(CFLAGS) -L$(INSTALL) $(SUBLIBS) -o $(INSTALL)/$(TARGET)

clean:
	@$(foreach sub,$(SUBUSER),$(MAKE) -C $(sub) clean;)
	@rm -f $(BUILDIR)/$(TARGET)

distclean:
	@$(foreach sub,$(SUBDIRS),$(MAKE) -C $(sub) clean;)
	@rm -rf $(BUILDIR)

run: install
	@LD_LIBRARY_PATH=./install $(INSTALL)/$(TARGET)
