CC ?= cc
AR ?= ar

CPPFLAGS ?=
CFLAGS ?= -std=c11 -O2 -g -Wall -Wextra -Werror -Wpedantic
LDFLAGS ?=
TEST_ENV ?=

BUILD_DIR ?= build
INCLUDES := -Iinclude
LIB := $(BUILD_DIR)/libnpu_driver.a
SOURCES := \
	src/npu_driver_command.c \
	src/npu_driver_descriptor.c \
	src/npu_driver_device.c \
	src/npu_driver_memory.c \
	src/npu_driver_runtime.c
OBJECTS := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
PUBLIC_HEADERS := include/npu_driver.h
PRIVATE_HEADERS := src/npu_driver_internal.h
TEST := $(BUILD_DIR)/test_npu_driver
EXAMPLE := $(BUILD_DIR)/build_int16_gemm
SANITIZER_FLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer

.PHONY: all test example regress test-gcc test-clang \
	test-sanitize-gcc test-sanitize-clang clean

all: $(LIB)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: src/%.c $(PUBLIC_HEADERS) $(PRIVATE_HEADERS) | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIB): $(OBJECTS)
	$(AR) rcs $@ $^

$(TEST): tests/test_npu_driver.c $(LIB) $(PUBLIC_HEADERS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) $< $(LIB) $(LDFLAGS) -o $@

$(EXAMPLE): examples/build_int16_gemm.c $(LIB) $(PUBLIC_HEADERS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) $< $(LIB) $(LDFLAGS) -o $@

test: $(TEST)
	$(TEST_ENV) $(TEST)

example: $(EXAMPLE)
	$(EXAMPLE)

test-gcc:
	$(MAKE) BUILD_DIR=$(BUILD_DIR)/gcc CC=gcc test

test-clang:
	$(MAKE) BUILD_DIR=$(BUILD_DIR)/clang CC=clang test

test-sanitize-gcc:
	$(MAKE) BUILD_DIR=$(BUILD_DIR)/sanitize-gcc CC=gcc \
		CFLAGS="$(CFLAGS) $(SANITIZER_FLAGS)" \
		LDFLAGS="$(LDFLAGS) $(SANITIZER_FLAGS)" \
		TEST_ENV="ASAN_OPTIONS=detect_leaks=0:halt_on_error=1 UBSAN_OPTIONS=halt_on_error=1:print_stacktrace=1" \
		test

test-sanitize-clang:
	$(MAKE) BUILD_DIR=$(BUILD_DIR)/sanitize-clang CC=clang \
		CFLAGS="$(CFLAGS) $(SANITIZER_FLAGS)" \
		LDFLAGS="$(LDFLAGS) $(SANITIZER_FLAGS)" \
		TEST_ENV="ASAN_OPTIONS=detect_leaks=0:halt_on_error=1 UBSAN_OPTIONS=halt_on_error=1:print_stacktrace=1" \
		test

regress: test-gcc test-clang test-sanitize-gcc test-sanitize-clang

clean:
	rm -rf $(BUILD_DIR)
