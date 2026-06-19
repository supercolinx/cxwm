# author: Colin X
# date: Mon Apr 20 20:54:10 CST 2026
# description:

TARGET	= libcustom.a

CC	= $(CROSS_COMPILE)gcc
AR	= $(CROSS_COMPILE)ar
CFLAGS	+= -I..

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
