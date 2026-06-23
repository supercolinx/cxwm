# author: Colin X
# date: Thu Jan 15 19:34:29 CST 2026
# description:

MAJOR	= 0
MINOR	= 0
PATCH	= 1

STARGET	= liblvgl.so.$(MAJOR).$(MINOR).$(PATCH)
TARGET	= liblvgl.so
BUILDIR ?= .
INSTALL	?= .

CC	= $(CROSS_COMPILE)gcc
AR	= $(CROSS_COMPILE)ar

CMD_INSTALL = cp

CFLAGS	+= -fPIC
ifeq ($(CROSS_COMPILE),)
	LDFLAGS	+= -lSDL2
endif

CSRCS	= $(shell find ./src -type f -name '*.c')
OBJS	= $(CSRCS:.c=.o)

.PHONY: clean install uninstall

all: default

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$@"

default: $(OBJS)
	@$(CC) $(LDFLAGS) -shared $^ -o $(BUILDIR)/$(STARGET)
	@echo "LD	$(STARGET)"


uninstall:
	@rm -rf $(INSTALL)/$(TARGET)

install:
	@$(CMD_INSTALL) $(BUILDIR)/$(STARGET) $(INSTALL)/$(TARGET)

clean:
	@rm -rf $(OBJS) $(BUILDIR)/$(STARGET)
