CC ?= cc
PYTHON ?= conda run -n tf_2_18 python

NPU_ROOT := ../../..
MODEL_COMPILER := $(NPU_ROOT)/compiler/npu_model_compiler.py
MODEL_ARTIFACTS := $(NPU_ROOT)/compiler/model_artifacts.py
ASSEMBLER := $(NPU_ROOT)/compiler/npu_assembler.py
CONV_LOWERING := $(NPU_ROOT)/compiler/conv_lowering.py
FRONTEND_SOURCES := $(wildcard $(NPU_ROOT)/compiler/frontends/*.py)
DRIVER_DIR := $(NPU_ROOT)/driver
CMODEL_DIR := ../..
BACKEND_DIR := ../common

BUILD_DIR := build
GENERATED_DIR := $(BUILD_DIR)/generated
MODEL := $(GENERATED_DIR)/keras_transformer.keras
TEST_HEADER := $(GENERATED_DIR)/keras_transformer_test_data.h
KERAS_REPORT := $(GENERATED_DIR)/keras_transformer_report.json
MODEL_STAMP := $(GENERATED_DIR)/.keras-model.stamp
COMPILE_STAMP := $(GENERATED_DIR)/.npu-package.stamp
GENERATED_HEADER := $(GENERATED_DIR)/keras_transformer_model.h
GENERATED_SOURCE := $(GENERATED_DIR)/keras_transformer_model.c
MANIFEST := $(GENERATED_DIR)/keras_transformer.manifest.json
DRIVER_LIB := $(DRIVER_DIR)/build/libnpu_driver.a
CMODEL_LIB := $(CMODEL_DIR)/build/libnpu_cmodel.a
DRIVER_SOURCES := $(DRIVER_DIR)/Makefile \
	$(wildcard $(DRIVER_DIR)/include/*.h) \
	$(wildcard $(DRIVER_DIR)/src/*.c)
CMODEL_SOURCES := $(CMODEL_DIR)/Makefile \
	$(wildcard $(CMODEL_DIR)/include/*.h) \
	$(wildcard $(CMODEL_DIR)/src/*.c)
RUNNER := $(BUILD_DIR)/transformer_runner

CPPFLAGS := -I$(DRIVER_DIR)/include -I$(CMODEL_DIR)/include \
	-I$(BACKEND_DIR) -I$(GENERATED_DIR)
CFLAGS := -std=c11 -O2 -g -Wall -Wextra -Werror -Wpedantic \
	-fno-fast-math -ffp-contract=off -fexcess-precision=standard
LDFLAGS := -no-pie
LDLIBS := -lm
SANITIZER_FLAGS := -O1 -fsanitize=address,undefined \
	-fno-omit-frame-pointer

.PHONY: all model compile check test test-gcc test-clang \
	test-sanitize regress clean

all: $(RUNNER)

$(GENERATED_DIR):
	mkdir -p $@

$(MODEL_STAMP): build_model.py | $(GENERATED_DIR)
	$(PYTHON) build_model.py \
		--model $(MODEL) \
		--test-header $(TEST_HEADER) \
		--report $(KERAS_REPORT)
	touch $@

$(MODEL) $(TEST_HEADER) $(KERAS_REPORT): $(MODEL_STAMP)

$(COMPILE_STAMP): $(MODEL) Makefile $(MODEL_COMPILER) $(MODEL_ARTIFACTS) \
	$(ASSEMBLER) $(CONV_LOWERING) $(FRONTEND_SOURCES)
	$(PYTHON) $(MODEL_COMPILER) $(MODEL) \
		--output-dir $(GENERATED_DIR) \
		--model-dtype int8 --fraction-bits 5 \
		--task-entries 8
	touch $@

$(GENERATED_HEADER) $(GENERATED_SOURCE) $(MANIFEST): $(COMPILE_STAMP)

$(DRIVER_LIB): $(DRIVER_SOURCES)
	$(MAKE) -C $(DRIVER_DIR) build/libnpu_driver.a

$(CMODEL_LIB): $(CMODEL_SOURCES)
	$(MAKE) -C $(CMODEL_DIR) build/libnpu_cmodel.a

$(RUNNER): model_runner.c \
	$(BACKEND_DIR)/cmodel_driver_backend.c \
	$(BACKEND_DIR)/cmodel_driver_backend.h \
	$(TEST_HEADER) $(GENERATED_HEADER) $(GENERATED_SOURCE) \
	$(DRIVER_LIB) $(CMODEL_LIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) \
		model_runner.c \
		$(BACKEND_DIR)/cmodel_driver_backend.c \
		$(GENERATED_SOURCE) \
		$(DRIVER_LIB) $(CMODEL_LIB) \
		$(LDFLAGS) $(LDLIBS) -o $@

model: $(MODEL) $(TEST_HEADER) $(KERAS_REPORT)

compile: $(GENERATED_HEADER) $(GENERATED_SOURCE) $(MANIFEST)

check: compile
	$(PYTHON) $(MODEL_COMPILER) $(MODEL) \
		--output-dir $(GENERATED_DIR) \
		--model-dtype int8 --fraction-bits 5 \
		--task-entries 8 --check
	test -s $(GENERATED_HEADER)
	test -s $(GENERATED_SOURCE)
	test -s $(MANIFEST)
	$(CC) $(CPPFLAGS) $(CFLAGS) -fsyntax-only $(GENERATED_SOURCE)

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
