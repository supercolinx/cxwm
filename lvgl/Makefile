# author: Colin X
# date: Thu Jan 15 19:34:29 CST 2026
# description:

TARGET	= liblvgl.a

CC	= $(CROSS_COMPILE)gcc
AR	= $(CROSS_COMPILE)ar
CFLAGS	+=

CSRCS	= $(shell find ./src -type f -name '*.c')
OBJS	= $(CSRCS:.c=.o)

.PHONY: clean

all: prepare default

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$@"

prepare:

default: $(OBJS)
	@$(AR) rcs $(BUILDIR)/$(TARGET) $^
	@echo "AR	$(TARGET)"

clean:
	@rm -rf $(OBJS) $(BUILDIR)/$(TARGET)
