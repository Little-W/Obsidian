SHELL := /bin/bash
.SHELLFLAGS := -o pipefail -c

VIVADO ?= /home/yusen/opt/Xilinx/Vivado/2024.2/bin/vivado
BUILD_DIR ?= build
PART ?= xc7a200tfbg484-3
PERIOD_NS ?= 10.000
JOBS ?= 8

.PHONY: syn clean

syn:
	mkdir -p "$(BUILD_DIR)"
	cd "$(BUILD_DIR)" && \
	"$(VIVADO)" -mode batch -notrace \
		-journal vivado.jou \
		-log vivado_internal.log \
		-source "$(abspath run_vivado.tcl)" \
		-tclargs "." "$(PART)" "$(PERIOD_NS)" "$(JOBS)" \
		2>&1 | tee vivado.log

clean:
	rm -rf "$(BUILD_DIR)"
	rm -rf .Xil
	rm -f vivado.jou vivado.log vivado_*.backup.jou \
		vivado_*.backup.log vivado_pid*.str
