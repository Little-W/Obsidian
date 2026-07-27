VERILATOR ?= verilator
OBJ_ROOT ?= /tmp/npu_engine_verilator
VFLAGS := --binary --timing -Wall --Wno-fatal --Wno-UNUSEDPARAM \
	--timescale 1ns/1ps
export OBJCACHE :=

PKG := npu_engine_pkg.sv
MEM := tb/npu_single_beat_memory_model.sv
DIP_SRCS := \
	../dip/dip_base_mul4.sv \
	../dip/dip_base_add4.sv \
	../dip/dip_simd_dot_product.sv \
	../dip/dip_segmented_adder64.sv \
	../dip/dip_pe.sv \
	../dip/dip_systolic_array.sv \
	../dip/dip_data_preprocess.sv \
	../dip/dip_gemm_core.sv
MATRIX_SRCS := \
	$(DIP_SRCS) \
	npu_matrix_scalar_engine.sv \
	npu_matrix_dip_engine.sv \
	npu_matrix_engine.sv

.PHONY: all test lint dma matrix vector vector-fast complex clean

all: test

test: dma matrix vector vector-fast complex

dma:
	mkdir -p $(OBJ_ROOT)
	$(VERILATOR) $(VFLAGS) --top-module tb_npu_dma_engine \
		--Mdir $(OBJ_ROOT)/dma \
		$(PKG) npu_dma_engine.sv $(MEM) tb/tb_npu_dma_engine.sv
	$(OBJ_ROOT)/dma/Vtb_npu_dma_engine

matrix:
	mkdir -p $(OBJ_ROOT)
	$(VERILATOR) $(VFLAGS) --top-module tb_npu_matrix_engine \
		--Mdir $(OBJ_ROOT)/matrix \
		$(PKG) $(MATRIX_SRCS) $(MEM) tb/tb_npu_matrix_engine.sv
	$(OBJ_ROOT)/matrix/Vtb_npu_matrix_engine

vector:
	mkdir -p $(OBJ_ROOT)
	$(VERILATOR) $(VFLAGS) --top-module tb_npu_vector_engine \
		--Mdir $(OBJ_ROOT)/vector \
		$(PKG) ../dip/dip_base_mul4.sv npu_vector_packed_mul.sv \
		npu_vector_engine.sv $(MEM) tb/tb_npu_vector_engine.sv
	$(OBJ_ROOT)/vector/Vtb_npu_vector_engine

vector-fast:
	mkdir -p $(OBJ_ROOT)
	$(VERILATOR) $(VFLAGS) --top-module tb_npu_vector_fast_mul \
		--Mdir $(OBJ_ROOT)/vector-fast \
		$(PKG) ../dip/dip_base_mul4.sv npu_vector_packed_mul.sv \
		npu_vector_engine.sv $(MEM) tb/tb_npu_vector_fast_mul.sv
	$(OBJ_ROOT)/vector-fast/Vtb_npu_vector_fast_mul

complex:
	mkdir -p $(OBJ_ROOT)
	$(VERILATOR) $(VFLAGS) --top-module tb_npu_complex_engine \
		--Mdir $(OBJ_ROOT)/complex \
		$(PKG) npu_fp32_alu_seq.sv npu_complex_math_seq.sv \
		npu_complex_engine.sv \
		$(MEM) tb/tb_npu_complex_engine.sv
	$(OBJ_ROOT)/complex/Vtb_npu_complex_engine

lint:
	$(VERILATOR) --lint-only -Wall --Wno-fatal --Wno-UNUSEDPARAM \
		--top-module npu_dma_engine \
		$(PKG) npu_dma_engine.sv
	$(VERILATOR) --lint-only -Wall --Wno-fatal --Wno-UNUSEDPARAM \
		--top-module npu_matrix_engine \
		$(PKG) $(MATRIX_SRCS)
	$(VERILATOR) --lint-only -Wall --Wno-fatal --Wno-UNUSEDPARAM \
		--top-module npu_vector_engine \
		$(PKG) ../dip/dip_base_mul4.sv npu_vector_packed_mul.sv \
		npu_vector_engine.sv
	$(VERILATOR) --lint-only -Wall --Wno-fatal --Wno-UNUSEDPARAM \
		--top-module npu_complex_engine \
		$(PKG) npu_fp32_alu_seq.sv npu_complex_math_seq.sv \
		npu_complex_engine.sv

clean:
	rm -rf $(OBJ_ROOT)
