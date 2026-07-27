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
	"$(VIVADO)" -mode batch -notrace \
		-source run_vivado.tcl \
		-tclargs "$(BUILD_DIR)" "$(PART)" "$(PERIOD_NS)" "$(JOBS)" \
		2>&1 | tee "$(BUILD_DIR)/vivado.log"

clean:
	rm -rf "$(BUILD_DIR)"
	rm -f vivado.jou vivado.log vivado_pid*.str

