CC ?= cc
AR ?= ar

CPPFLAGS := -Iinclude -Isrc
CFLAGS := -std=c11 -O2 -Wall -Wextra -Wpedantic -Werror \
	-fno-fast-math -ffp-contract=off -fexcess-precision=standard
SAN_FLAGS := -O1 -g -fsanitize=address,undefined \
	-fno-omit-frame-pointer

BUILD_DIR := build
SAN_BUILD_DIR := build-sanitize
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC))
HDR := $(wildcard include/*.h) $(wildcard src/*.h)
TEST_SRC := $(wildcard tests/*.c)
TEST_HDR := $(wildcard tests/*.h tests/generated/*.h)
TEST_BIN := $(BUILD_DIR)/test_npu_cmodel
WIRE_E2E_BIN := $(BUILD_DIR)/test_wire_e2e
MODEL_INFER_BIN := $(BUILD_DIR)/model_infer
LIB := $(BUILD_DIR)/libnpu_cmodel.a
TEST_LDLIBS := -lm
MODEL ?= all
CONDA ?= conda
KERAS_CONDA_ENV ?= tf_2_18
KERAS_EXPORT_SCRIPT := tools/train_export_keras_mlp.py
KERAS_FIXTURE := tests/generated/keras_mlp_fixture.h
KERAS_SEQUENCE_EXPORT_SCRIPT := \
	tools/export_keras_sequence_fixtures.py
KERAS_SEQUENCE_FIXTURE := \
	tests/generated/keras_sequence_fixtures.h
MODEL_COMPILER_SCRIPT := tools/compile_keras_model.py
MODEL_COMPILER_OUTPUT_DIR ?= $(BUILD_DIR)/model-compiler

.PHONY: all test wire-e2e model-infer model-compile \
	model-compile-check keras-fixture keras-e2e sanitize clean

all: $(LIB) $(TEST_BIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: src/%.c $(HDR) | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJ)
	$(AR) rcs $@ $^

$(TEST_BIN): $(TEST_SRC) $(TEST_HDR) $(HDR) $(LIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(TEST_SRC) $(LIB) \
		$(TEST_LDLIBS) -o $@

test: $(TEST_BIN)
	$(TEST_BIN)

$(WIRE_E2E_BIN): tests/test_wire_e2e.c $(TEST_HDR) $(HDR) $(LIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) -DNPU_WIRE_E2E_STANDALONE \
		tests/test_wire_e2e.c $(LIB) -o $@

wire-e2e: $(WIRE_E2E_BIN)
	$(WIRE_E2E_BIN)

$(MODEL_INFER_BIN): tests/test_keras_sequence_inference.c \
		$(TEST_HDR) $(HDR) $(LIB)
	$(CC) $(CPPFLAGS) $(CFLAGS) \
		-DKSI_MODEL_INFER_STANDALONE \
		tests/test_keras_sequence_inference.c $(LIB) \
		$(TEST_LDLIBS) -o $@

model-infer: $(MODEL_INFER_BIN)
	$(MODEL_INFER_BIN) "$(MODEL)"

model-compile:
	$(CONDA) run -n $(KERAS_CONDA_ENV) python \
		$(MODEL_COMPILER_SCRIPT) --model "$(MODEL)" \
		--output-dir "$(MODEL_COMPILER_OUTPUT_DIR)"

model-compile-check:
	$(CONDA) run -n $(KERAS_CONDA_ENV) python \
		$(MODEL_COMPILER_SCRIPT) --model "$(MODEL)" \
		--output-dir "$(MODEL_COMPILER_OUTPUT_DIR)" --check

keras-fixture:
	$(CONDA) run -n $(KERAS_CONDA_ENV) python \
		$(KERAS_EXPORT_SCRIPT) --output $(KERAS_FIXTURE)
	$(CONDA) run -n $(KERAS_CONDA_ENV) python \
		$(KERAS_SEQUENCE_EXPORT_SCRIPT) \
		--output $(KERAS_SEQUENCE_FIXTURE)

keras-e2e: keras-fixture
	$(MAKE) BUILD_DIR=$(BUILD_DIR) test

sanitize:
	$(MAKE) BUILD_DIR=$(SAN_BUILD_DIR) clean
	$(MAKE) BUILD_DIR=$(SAN_BUILD_DIR) \
		CFLAGS='$(CFLAGS) $(SAN_FLAGS)' all
	ASAN_OPTIONS=detect_leaks=0 \
		$(SAN_BUILD_DIR)/test_npu_cmodel

clean:
	rm -rf $(BUILD_DIR) $(SAN_BUILD_DIR)
