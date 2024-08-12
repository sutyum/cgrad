# Compiler settings
CC := gcc

# Project structure
BUILD_DIR := build
SRC_DIR := ./

BUILD_TYPE ?= debug
TARGET ?= cgrad

ifeq ($(BUILD_TYPE),debug)
	CFLAGS := -g -O0 -Wall -Werror
else ifeq ($(BUILD_TYPE),release)
	CFLAGS := -O3 -Wall -Werror
else
	$(error "Invalid BUILD_TYPE: $(BUILD_TYPE)")
endif

# Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Targets
EXECUTABLE := $(BUILD_DIR)/$(TARGET)-$(BUILD_TYPE)

# Phony targets
.PHONY: all clean debug release

all: $(EXECUTABLE)

debug:
	$(MAKE) BUILD_TYPE=debug

release:
	$(MAKE) BUILD_TYPE=release

$(EXECUTABLE): $(OBJ_FILES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

# Debug target
print-%:
	@echo $* = $($*)
