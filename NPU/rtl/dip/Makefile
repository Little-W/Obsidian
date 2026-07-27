VERILATOR ?= verilator
PYTHON ?= python3
OBJ_ROOT ?= /tmp/dip_verilator
VECTOR_FILE ?= /tmp/dip_random_vectors_n2.txt
VECTOR_SEED ?= 20250727
TILES_PER_MODE ?= 2

VFLAGS := --binary --sv --timing --assert -Wall \
	--timescale 1ns/1ps

ARITH_SRCS := \
	dip_base_mul4.sv \
	dip_base_add4.sv \
	dip_simd_dot_product.sv \
	dip_segmented_adder64.sv

RTL_SRCS := \
	$(ARITH_SRCS) \
	dip_pe.sv \
	dip_systolic_array.sv \
	dip_data_preprocess.sv \
	dip_gemm_core.sv

.PHONY: all test random-vectors pe-test preprocess-test gemm-test \
	n1-test lint clean

all: test

test: pe-test preprocess-test gemm-test n1-test

pe-test:
	mkdir -p $(OBJ_ROOT)/pe
	$(VERILATOR) $(VFLAGS) \
		--top-module tb_dip_pe \
		--Mdir $(OBJ_ROOT)/pe \
		$(ARITH_SRCS) dip_pe.sv tb/tb_dip_pe.sv
	$(OBJ_ROOT)/pe/Vtb_dip_pe

preprocess-test:
	mkdir -p $(OBJ_ROOT)/preprocess
	$(VERILATOR) $(VFLAGS) \
		--top-module tb_dip_data_preprocess \
		--Mdir $(OBJ_ROOT)/preprocess \
		dip_data_preprocess.sv tb/tb_dip_data_preprocess.sv
	$(OBJ_ROOT)/preprocess/Vtb_dip_data_preprocess

random-vectors:
	$(PYTHON) tb/gen_random_vectors.py \
		--array-n 2 \
		--tiles-per-mode $(TILES_PER_MODE) \
		--seed $(VECTOR_SEED) \
		--output $(VECTOR_FILE)

gemm-test: random-vectors
	mkdir -p $(OBJ_ROOT)/gemm
	$(VERILATOR) $(VFLAGS) \
		--top-module tb_dip_gemm_core \
		--Mdir $(OBJ_ROOT)/gemm \
		$(RTL_SRCS) tb/tb_dip_gemm_core.sv
	$(OBJ_ROOT)/gemm/Vtb_dip_gemm_core \
		+VECTOR_FILE=$(VECTOR_FILE)

n1-test:
	mkdir -p $(OBJ_ROOT)/n1
	$(VERILATOR) $(VFLAGS) \
		--top-module tb_dip_gemm_n1 \
		--Mdir $(OBJ_ROOT)/n1 \
		$(RTL_SRCS) tb/tb_dip_gemm_n1.sv
	$(OBJ_ROOT)/n1/Vtb_dip_gemm_n1

lint:
	$(VERILATOR) --lint-only --sv --timing --assert \
		-Wall --timescale 1ns/1ps \
		--top-module dip_gemm_core \
		$(RTL_SRCS)

clean:
	rm -rf $(OBJ_ROOT)
