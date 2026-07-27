SHELL := /bin/bash
.SHELLFLAGS := -o pipefail -c

VIVADO ?= /home/yusen/opt/Xilinx/Vivado/2024.2/bin/vivado
PYTHON ?= python3
BUILD_DIR ?= build
PART ?= xc7a200tfbg484-3
PERIOD_NS ?= 10.000
JOBS ?= 1

.PHONY: syn timing-dedup clean

syn:
	mkdir -p "$(BUILD_DIR)"
	cd "$(BUILD_DIR)" && \
	"$(VIVADO)" -mode batch -notrace \
		-journal vivado.jou \
		-log vivado_internal.log \
		-source "$(abspath run_vivado.tcl)" \
		-tclargs "." "$(PART)" "$(PERIOD_NS)" "$(JOBS)" \
		2>&1 | tee vivado.log
	$(MAKE) --no-print-directory timing-dedup \
		BUILD_DIR="$(BUILD_DIR)" PYTHON="$(PYTHON)"

timing-dedup:
	"$(PYTHON)" "$(abspath dedup_vivado_timing_paths.py)" \
		--key-mode structural --top 100 \
		"$(BUILD_DIR)/timing_paths_setup_post_synth.rpt" \
		"$(BUILD_DIR)/timing_paths_hold_post_synth.rpt" \
		"$(BUILD_DIR)/timing_paths_setup_post_route.rpt" \
		"$(BUILD_DIR)/timing_paths_hold_post_route.rpt"

clean:
	rm -rf "$(BUILD_DIR)"
	rm -rf .Xil
	rm -f vivado.jou vivado.log vivado_*.backup.jou \
		vivado_*.backup.log vivado_pid*.str
