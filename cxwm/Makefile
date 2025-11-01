# xiekangli
#
VERSION_FILE	= cx_version.h
VERSION_MAJOR	= 1
VERSION_MINOR	= 0
VERSION_PATCH	= 0
VERSION_INFO	= \"\"

ROOT_DIR	= .
TARGET		= cxwm
BUILD_DIR	= $(ROOT_DIR)/../build/cxwm

CC	?= gcc

CFLAGS	= -Wall -std=gnu99 -O3 \
	  -I$(ROOT_DIR)
LDFLAGS = -L$(ROOT_DIR)/../build/lvgl -llvgl \
	  -Wl,-rpath=./lib

CSRCS	= ../main.c
CSRCS	+= $(shell find $(ROOT_DIR)/src -type f -name '*.c')

OBJS	= $(addprefix $(BUILD_DIR)/, $(patsubst $(ROOT_DIR)/%, %, $(CSRCS:.c=.o)))

.PHONY: clean
all: prepare default

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$<"

prepare:
	@cp $(ROOT_DIR)/../cx_conf.h $(ROOT_DIR)/src/cx_conf_internal.h
	@echo "#ifndef CX_VERSION_H" > $(VERSION_FILE)
	@echo "#define CX_VERSION_H" >> $(VERSION_FILE)
	@echo >> $(VERSION_FILE)
	@echo "#define CX_VERSION_MAJOR $(VERSION_MAJOR)" >> $(VERSION_FILE)
	@echo "#define CX_VERSION_MINOR $(VERSION_MINOR)" >> $(VERSION_FILE)
	@echo "#define CX_VERSION_PATCH $(VERSION_PATCH)" >> $(VERSION_FILE)
	@echo "#define CX_VERSION_INFO $(VERSION_INFO)" >> $(VERSION_FILE)
	@echo >> $(VERSION_FILE)
	@echo "#endif /* CX_VERSION_H */" >> $(VERSION_FILE)

default: $(OBJS)
	@$(CC) -o $(BUILD_DIR)/$(TARGET) $^ $(LDFLAGS)

clean:
	@rm -rf $(BUILD_DIR)/../main.o
	@rm -rf $(BUILD_DIR)
