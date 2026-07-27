SHELL := /bin/bash
.SHELLFLAGS := -o pipefail -c

DC_SHELL ?= dc_shell
SOURCE_RTL ?= /home/yusen/Obsidian Vault/NPU/rtl
SYN_ENV_ROOT ?= /home/yusen/opt/xinyuan/syn_env
NPU_SYN_DIR ?= $(SYN_ENV_ROOT)/npu

.PHONY: vivado-syn vivado-clean sync syn clean

vivado-syn:
	$(MAKE) -C vivado_100mhz syn

vivado-clean:
	$(MAKE) -C vivado_100mhz clean

sync:
	mkdir -p "$(NPU_SYN_DIR)"
	cp -a filelist.f npu_l1buf_timing_wrapper.sv \
		npu_single_core_400mhz.sdc run_dc.tcl Makefile README.md .gitignore \
		"$(NPU_SYN_DIR)/"
	mkdir -p "$(NPU_SYN_DIR)/rtl_snapshot/control"
	mkdir -p "$(NPU_SYN_DIR)/rtl_snapshot/engines"
	mkdir -p "$(NPU_SYN_DIR)/rtl_snapshot/memory"
	mkdir -p "$(NPU_SYN_DIR)/rtl_snapshot/top"
	cp -a "$(SOURCE_RTL)/npu_rtl_pkg.sv" \
		"$(NPU_SYN_DIR)/rtl_snapshot/"
	cp -a "$(SOURCE_RTL)"/control/npu_*.sv \
		"$(NPU_SYN_DIR)/rtl_snapshot/control/"
	cp -a "$(SOURCE_RTL)"/engines/npu_*.sv \
		"$(NPU_SYN_DIR)/rtl_snapshot/engines/"
	cp -a "$(SOURCE_RTL)"/memory/npu_axi_mif_master.sv \
		"$(SOURCE_RTL)"/memory/npu_tbu.sv \
		"$(NPU_SYN_DIR)/rtl_snapshot/memory/"
	cp -a "$(SOURCE_RTL)"/top/npu_*.sv \
		"$(NPU_SYN_DIR)/rtl_snapshot/top/"

syn:
	mkdir -p reports/baseline_400mhz
	$(DC_SHELL) -f run_dc.tcl | tee reports/baseline_400mhz/dc.log

clean:
	rm -rf WORK_baseline_400mhz alib-52 reports/baseline_400mhz
	rm -f command.log default.svf filenames.log
