# xiekangli
#
VERSION_FILE	= lv_version.h
VERSION_MAJOR	= 9
VERSION_MINOR	= 2
VERSION_PATCH	= 0
VERSION_INFO	= \"\"

ROOT_DIR	= .
TARGET		= liblvgl.so
BUILD_DIR	= $(ROOT_DIR)/../build/lvgl

CC	?= gcc

CFLAGS	= -Wall -std=gnu99 -O3 -fPIC \
	  -I$(ROOT_DIR) \
	  -I/usr/include/freetype2
LDFLAGS	= -lfreetype -lpthread -lSDL2

CSRCS	= $(shell find $(ROOT_DIR)/src -type f -name '*.c')

OBJS	= $(addprefix $(BUILD_DIR)/, $(patsubst $(ROOT_DIR)/%, %, $(CSRCS:.c=.o)))

.PHONY: clean
all: prepare default

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$<"

prepare:
	@echo "#ifndef LVGL_VERSION_H" > $(VERSION_FILE)
	@echo "#define LVGL_VERSION_H" >> $(VERSION_FILE)
	@echo >> $(VERSION_FILE)
	@echo "#define LVGL_VERSION_MAJOR $(VERSION_MAJOR)" >> $(VERSION_FILE)
	@echo "#define LVGL_VERSION_MINOR $(VERSION_MINOR)" >> $(VERSION_FILE)
	@echo "#define LVGL_VERSION_PATCH $(VERSION_PATCH)" >> $(VERSION_FILE)
	@echo "#define LVGL_VERSION_INFO $(VERSION_INFO)" >> $(VERSION_FILE)
	@echo >> $(VERSION_FILE)
	@echo "#endif /* LVGL_VERSION_H */" >> $(VERSION_FILE)

default: $(OBJS)
	@$(CC) -shared -o $(BUILD_DIR)/$(TARGET) $^ $(LDFLAGS)

clean:
	@rm -rf $(BUILD_DIR)
