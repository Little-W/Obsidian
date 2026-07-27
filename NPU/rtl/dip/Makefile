VERILATOR ?= verilator
OBJ_ROOT ?= /tmp/dip_verilator

VFLAGS := --binary --sv --timing --assert -Wall \
	--timescale 1ns/1ps

RTL_SRCS := \
	dip_pe.sv \
	dip_systolic_array.sv \
	dip_data_preprocess.sv \
	dip_gemm_core.sv

.PHONY: all test pe-test preprocess-test gemm-test n1-test lint clean

all: test

test: pe-test preprocess-test gemm-test n1-test

pe-test:
	mkdir -p $(OBJ_ROOT)/pe
	$(VERILATOR) $(VFLAGS) \
		--top-module tb_dip_pe \
		--Mdir $(OBJ_ROOT)/pe \
		dip_pe.sv tb/tb_dip_pe.sv
	$(OBJ_ROOT)/pe/Vtb_dip_pe

preprocess-test:
	mkdir -p $(OBJ_ROOT)/preprocess
	$(VERILATOR) $(VFLAGS) \
		--top-module tb_dip_data_preprocess \
		--Mdir $(OBJ_ROOT)/preprocess \
		dip_data_preprocess.sv tb/tb_dip_data_preprocess.sv
	$(OBJ_ROOT)/preprocess/Vtb_dip_data_preprocess

gemm-test:
	mkdir -p $(OBJ_ROOT)/gemm
	$(VERILATOR) $(VFLAGS) \
		--top-module tb_dip_gemm_core \
		--Mdir $(OBJ_ROOT)/gemm \
		$(RTL_SRCS) tb/tb_dip_gemm_core.sv
	$(OBJ_ROOT)/gemm/Vtb_dip_gemm_core

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
