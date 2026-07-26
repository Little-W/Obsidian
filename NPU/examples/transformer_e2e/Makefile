CC ?= cc
PYTHON ?= python3

ROOT := ../..
ASSEMBLER := $(ROOT)/compiler/npu_assembler.py
DRIVER_DIR := $(ROOT)/driver
CMODEL_DIR := $(ROOT)/cmodel
BUILD_DIR := build
GENERATED_DIR := $(BUILD_DIR)/generated
MODEL := transformer_block.json
GENERATED_HEADER := $(GENERATED_DIR)/transformer_block.npu.h
DRIVER_LIB := $(DRIVER_DIR)/build/libnpu_driver.a
CMODEL_LIB := $(CMODEL_DIR)/build/libnpu_cmodel.a
RUNNER := $(BUILD_DIR)/transformer_runner

CPPFLAGS := -I$(DRIVER_DIR)/include -I$(CMODEL_DIR)/include \
	-I$(GENERATED_DIR)
CFLAGS := -std=c11 -O2 -g -Wall -Wextra -Werror -Wpedantic \
	-fno-fast-math -ffp-contract=off -fexcess-precision=standard
LDFLAGS := -no-pie
LDLIBS := -lm
SANITIZER_FLAGS := -O1 -fsanitize=address,undefined \
	-fno-omit-frame-pointer

.PHONY: all compile check test test-gcc test-clang \
	test-sanitize regress clean

all: $(RUNNER)

$(GENERATED_DIR):
	mkdir -p $@

$(GENERATED_HEADER): $(MODEL) $(ASSEMBLER) | $(GENERATED_DIR)
	$(PYTHON) $(ASSEMBLER) $(MODEL) \
		--output-dir $(GENERATED_DIR) --emit-c-header

$(DRIVER_LIB):
	$(MAKE) -C $(DRIVER_DIR) build/libnpu_driver.a

$(CMODEL_LIB):
	$(MAKE) -C $(CMODEL_DIR) build/libnpu_cmodel.a

$(RUNNER): transformer_runner.c cmodel_driver_backend.c \
	cmodel_driver_backend.h $(GENERATED_HEADER) \
	$(DRIVER_LIB) $(CMODEL_LIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) \
		transformer_runner.c cmodel_driver_backend.c \
		$(DRIVER_LIB) $(CMODEL_LIB) $(LDFLAGS) $(LDLIBS) -o $@

compile: $(GENERATED_HEADER)

check: $(GENERATED_HEADER)
	$(PYTHON) $(ASSEMBLER) $(MODEL) \
		--output-dir $(GENERATED_DIR) --emit-c-header --check

test: check $(RUNNER)
	$(RUNNER)

test-gcc:
	$(MAKE) clean
	$(MAKE) CC=gcc test

test-clang:
	$(MAKE) clean
	$(MAKE) CC=clang test

test-sanitize:
	$(MAKE) clean
	ASAN_OPTIONS=detect_leaks=0:halt_on_error=1 \
	UBSAN_OPTIONS=halt_on_error=1:print_stacktrace=1 \
	$(MAKE) CC=clang \
		CFLAGS="$(CFLAGS) $(SANITIZER_FLAGS)" \
		LDLIBS="$(LDLIBS) -fsanitize=address,undefined" test

regress:
	$(MAKE) test-gcc
	$(MAKE) test-clang
	$(MAKE) test-sanitize

clean:
	rm -rf $(BUILD_DIR)
