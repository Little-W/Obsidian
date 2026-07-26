CC ?= cc
PYTHON ?= conda run -n tf_2_18 python

ifndef EXAMPLE_KIND
$(error EXAMPLE_KIND must be set before including common/example.mk)
endif

COMMON_DIR := ../common
CMODEL_DIR := ../..
NPU_DIR := ../../..
COMPILER_DIR := $(NPU_DIR)/compiler
DRIVER_DIR := $(NPU_DIR)/driver
BACKEND_DIR := $(COMMON_DIR)

BUILD_DIR ?= build
GENERATED_DIR := $(BUILD_DIR)/generated
MODEL := $(BUILD_DIR)/model.keras
GRAPH := $(BUILD_DIR)/model.json
FIXTURE := $(GENERATED_DIR)/model_fixture.h
REPORT := $(GENERATED_DIR)/model_report.json
MODEL_STAMP := $(BUILD_DIR)/.model.stamp
COMPILE_STAMP := $(BUILD_DIR)/.compile.stamp
GENERATED_HEADER := $(GENERATED_DIR)/model_model.h
GENERATED_SOURCE := $(GENERATED_DIR)/model_model.c
MANIFEST := $(GENERATED_DIR)/model.manifest.json
RUNNER := $(BUILD_DIR)/model_infer

ifeq ($(EXAMPLE_KIND),cnn)
COMPILER_INPUT := $(MODEL)
GRAPH_ARGUMENT :=
else
COMPILER_INPUT := $(GRAPH)
GRAPH_ARGUMENT := --graph $(GRAPH)
endif

MODEL_BUILDER := build_model.py
MODEL_SUPPORT := $(COMMON_DIR)/build_keras_example.py
MODEL_RUNNER := $(COMMON_DIR)/model_runner.c
MODEL_COMPILER := $(COMPILER_DIR)/npu_model_compiler.py
MODEL_ARTIFACTS := $(COMPILER_DIR)/model_artifacts.py
ASSEMBLER := $(COMPILER_DIR)/npu_assembler.py
CONV_LOWERING := $(COMPILER_DIR)/conv_lowering.py
FRONTEND_SOURCES := $(wildcard $(COMPILER_DIR)/frontends/*.py)
DRIVER_LIB := $(DRIVER_DIR)/build/libnpu_driver.a
CMODEL_LIB := $(CMODEL_DIR)/build/libnpu_cmodel.a
DRIVER_SOURCES := $(DRIVER_DIR)/Makefile \
	$(wildcard $(DRIVER_DIR)/include/*.h) \
	$(wildcard $(DRIVER_DIR)/src/*.c)
CMODEL_SOURCES := $(CMODEL_DIR)/Makefile \
	$(wildcard $(CMODEL_DIR)/include/*.h) \
	$(wildcard $(CMODEL_DIR)/src/*.c)

CPPFLAGS := -I$(DRIVER_DIR)/include -I$(CMODEL_DIR)/include \
	-I$(BACKEND_DIR) -I$(GENERATED_DIR)
CFLAGS ?= -std=c11 -O2 -g -Wall -Wextra -Werror -Wpedantic \
	-fno-fast-math -ffp-contract=off -fexcess-precision=standard
LDFLAGS ?= -no-pie
LDLIBS ?= -lm
SANITIZER_FLAGS := -O1 -fsanitize=address,undefined \
	-fno-omit-frame-pointer

.PHONY: all model compile check test test-gcc test-clang \
	test-sanitize regress clean

all: $(RUNNER)

$(BUILD_DIR):
	mkdir -p $@

$(GENERATED_DIR):
	mkdir -p $@

$(MODEL_STAMP): $(MODEL_BUILDER) $(MODEL_SUPPORT) | \
	$(BUILD_DIR) $(GENERATED_DIR)
	$(PYTHON) $(MODEL_BUILDER) \
		--model $(MODEL) $(GRAPH_ARGUMENT) \
		--fixture $(FIXTURE) \
		--report $(REPORT)
	touch $@

$(MODEL) $(FIXTURE) $(REPORT): $(MODEL_STAMP)

ifneq ($(EXAMPLE_KIND),cnn)
$(GRAPH): $(MODEL_STAMP)
endif

$(COMPILE_STAMP): $(COMPILER_INPUT) $(MODEL_COMPILER) \
	$(MODEL_ARTIFACTS) $(ASSEMBLER) $(CONV_LOWERING) \
	$(FRONTEND_SOURCES) | $(GENERATED_DIR)
	$(PYTHON) $(MODEL_COMPILER) $(COMPILER_INPUT) \
		--output-dir $(GENERATED_DIR) \
		--model-dtype int8 --fraction-bits 5 \
		--task-entries 8
	touch $@

$(GENERATED_HEADER) $(GENERATED_SOURCE) $(MANIFEST): $(COMPILE_STAMP)

$(DRIVER_LIB): $(DRIVER_SOURCES)
	$(MAKE) -C $(DRIVER_DIR) build/libnpu_driver.a

$(CMODEL_LIB): $(CMODEL_SOURCES)
	$(MAKE) -C $(CMODEL_DIR) build/libnpu_cmodel.a

$(RUNNER): $(MODEL_RUNNER) $(BACKEND_DIR)/cmodel_driver_backend.c \
	$(BACKEND_DIR)/cmodel_driver_backend.h $(FIXTURE) \
	$(GENERATED_HEADER) $(GENERATED_SOURCE) $(DRIVER_LIB) $(CMODEL_LIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) \
		$(MODEL_RUNNER) \
		$(BACKEND_DIR)/cmodel_driver_backend.c \
		$(GENERATED_SOURCE) \
		$(DRIVER_LIB) $(CMODEL_LIB) \
		$(LDFLAGS) $(LDLIBS) -o $@

model: $(MODEL) $(FIXTURE) $(REPORT)

compile: $(GENERATED_HEADER) $(GENERATED_SOURCE) $(MANIFEST)

check: compile
	$(PYTHON) $(MODEL_COMPILER) $(COMPILER_INPUT) \
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
