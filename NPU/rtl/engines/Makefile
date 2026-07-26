VERILATOR ?= verilator
OBJ_ROOT ?= /tmp/npu_engine_verilator
VFLAGS := --binary --timing -Wall --Wno-fatal --timescale 1ns/1ps
export OBJCACHE :=

PKG := npu_engine_pkg.sv
MEM := tb/npu_single_beat_memory_model.sv

.PHONY: all test lint dma matrix vector complex clean

all: test

test: dma matrix vector complex

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
		$(PKG) npu_matrix_engine.sv $(MEM) tb/tb_npu_matrix_engine.sv
	$(OBJ_ROOT)/matrix/Vtb_npu_matrix_engine

vector:
	mkdir -p $(OBJ_ROOT)
	$(VERILATOR) $(VFLAGS) --top-module tb_npu_vector_engine \
		--Mdir $(OBJ_ROOT)/vector \
		$(PKG) npu_vector_engine.sv $(MEM) tb/tb_npu_vector_engine.sv
	$(OBJ_ROOT)/vector/Vtb_npu_vector_engine

complex:
	mkdir -p $(OBJ_ROOT)
	$(VERILATOR) $(VFLAGS) --top-module tb_npu_complex_engine \
		--Mdir $(OBJ_ROOT)/complex \
		$(PKG) npu_complex_convert.sv npu_complex_math_core.sv \
		npu_complex_engine.sv \
		$(MEM) tb/tb_npu_complex_engine.sv
	$(OBJ_ROOT)/complex/Vtb_npu_complex_engine

lint:
	$(VERILATOR) --lint-only -Wall --Wno-fatal \
		$(PKG) npu_dma_engine.sv npu_matrix_engine.sv \
		npu_vector_engine.sv npu_complex_convert.sv \
		npu_complex_math_core.sv npu_complex_engine.sv

clean:
	rm -rf $(OBJ_ROOT)
