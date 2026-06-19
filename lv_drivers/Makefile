# author: Colin X
# date: Sat Jan 17 20:24:36 CST 2026
# description:

TARGET	= liblv_drivers.a

CC	= $(CROSS_COMPILE)gcc
AR	= $(CROSS_COMPILE)ar
CFLAGS	+= -I..

CSRCS	= $(shell find ./sdl -type f -name '*.c')
OBJS	= $(CSRCS:.c=.o)

.PHONY: clean

all: prepare default

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$<"

prepare:

default: $(OBJS)
	@$(AR) rcs $(BUILDIR)/$(TARGET) $^
	@echo "AR	$(TARGET)"

clean:
	@rm -rf $(OBJS) $(BUILDIR)/$(TARGET)
