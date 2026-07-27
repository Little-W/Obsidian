VERILATOR ?= verilator
BUILD_DIR ?= /tmp/npu_rtl_verilator
GEN_DIR ?= build_npu_rtl_verilator_gen

# Do not use the host-wide ccache here.  A full or read-only cache makes an
# otherwise valid RTL build fail before the generated model is linked.
# GCC has also been observed to crash while compiling a large generated
# translation unit with Verilator's precompiled header forced in.  The header
# is still generated as a normal dependency, but it is not injected into each
# translation unit.
VERILATOR_MAKE_FLAGS := \
	OBJCACHE= \
	VK_PCH_I_FAST= \
	VK_PCH_I_SLOW=

# Historical local debug outputs created in this RTL directory.  Keep this
# list explicit so clean cannot match unrelated directories outside NPU/rtl.
LOCAL_DEBUG_DIRS := \
	build_npu_rtl_verilator_gen \
	build_top_assert_split_b33a \
	build_top_env_ccache_7b12 \
	build_top_main_2stage_91e4 \
	build_top_main_new_c821 \
	build_top_nassert_split_6be0 \
	build_top_only_91af \
	build_top_only_noinline_d9f0 \
	build_top_only_o0_a2d8 \
	build_top_only_small_21d4 \
	engines/build_rtl_engines_fp32

PKG_SRCS := \
	npu_rtl_pkg.sv \
	engines/npu_engine_pkg.sv

CONTROL_SRCS := $(filter-out control/tb_%.sv,$(wildcard control/*.sv))
MEMORY_SRCS  := $(filter-out memory/tb_%.sv,$(wildcard memory/*.sv))
ENGINE_SRCS  := $(filter-out engines/npu_engine_pkg.sv,$(wildcard engines/*.sv))
TOP_SRCS     := $(wildcard top/*.sv)

RTL_SRCS := $(PKG_SRCS) \
	$(CONTROL_SRCS) $(MEMORY_SRCS) $(ENGINE_SRCS) $(TOP_SRCS)

VERILATOR_COMMON := \
	--sv \
	--timing \
	--assert \
	-Wall \
	-Wno-fatal \
	-Wno-DECLFILENAME \
	-Wno-TIMESCALEMOD \
	-I. \
	-Icontrol \
	-Imemory \
	-Iengines \
	-Itop

VERILATOR_SIM := $(VERILATOR_COMMON) \
	--x-initial 0 \
	--output-split 10000 \
	--output-split-cfuncs 5000

# The model-only build excludes the default smoke-test initial block. Its
# shared declarations remain in the source so both modes use the same AXI
# tasks and DUT wiring.
VERILATOR_TRANSFORMER := $(VERILATOR_SIM) \
	-Wno-UNUSEDSIGNAL \
	-Wno-UNUSEDPARAM

.PHONY: all lint control-test memory-test math-reference-test frontend-test \
	engine-test module-test system-test transformer-e2e test clean

all: test

lint:
	$(VERILATOR) --lint-only $(VERILATOR_COMMON) --top-module npu_single_core_top $(RTL_SRCS)

control-test:
	mkdir -p $(GEN_DIR)/control_cmd_dfu
	$(VERILATOR) --cc --exe --main $(VERILATOR_SIM) \
		--top-module tb_cmd_dfu_smoke \
		-Mdir $(GEN_DIR)/control_cmd_dfu \
		-o Vtb_cmd_dfu_smoke \
		npu_rtl_pkg.sv \
		control/npu_cmd_frontend.sv \
		control/npu_descriptor_fetch.sv \
		control/tb_cmd_dfu_smoke.sv
	mkdir -p $(BUILD_DIR)/control_cmd_dfu
	cp -a $(GEN_DIR)/control_cmd_dfu/. $(BUILD_DIR)/control_cmd_dfu/
	$(MAKE) -C $(BUILD_DIR)/control_cmd_dfu \
		-f Vtb_cmd_dfu_smoke.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	$(BUILD_DIR)/control_cmd_dfu/Vtb_cmd_dfu_smoke
	mkdir -p $(GEN_DIR)/control_lsc_crg_wdt
	$(VERILATOR) --cc --exe --main $(VERILATOR_SIM) \
		--top-module tb_lsc_crg_wdt_smoke \
		-Mdir $(GEN_DIR)/control_lsc_crg_wdt \
		-o Vtb_lsc_crg_wdt_smoke \
		npu_rtl_pkg.sv \
		control/npu_lsc.sv \
		control/npu_crg.sv \
		control/npu_wdt.sv \
		control/tb_lsc_crg_wdt_smoke.sv
	mkdir -p $(BUILD_DIR)/control_lsc_crg_wdt
	cp -a $(GEN_DIR)/control_lsc_crg_wdt/. \
		$(BUILD_DIR)/control_lsc_crg_wdt/
	$(MAKE) -C $(BUILD_DIR)/control_lsc_crg_wdt \
		-f Vtb_lsc_crg_wdt_smoke.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	$(BUILD_DIR)/control_lsc_crg_wdt/Vtb_lsc_crg_wdt_smoke
	mkdir -p $(GEN_DIR)/control_scheduler
	$(VERILATOR) --cc --exe --main $(VERILATOR_SIM) \
		--top-module tb_scheduler_ctl_smoke \
		-Mdir $(GEN_DIR)/control_scheduler \
		-o Vtb_scheduler_ctl_smoke \
		npu_rtl_pkg.sv \
		control/npu_inline_desc_decode.sv \
		control/npu_task_scheduler.sv \
		control/tb_scheduler_ctl_smoke.sv
	mkdir -p $(BUILD_DIR)/control_scheduler
	cp -a $(GEN_DIR)/control_scheduler/. $(BUILD_DIR)/control_scheduler/
	$(MAKE) -C $(BUILD_DIR)/control_scheduler \
		-f Vtb_scheduler_ctl_smoke.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	$(BUILD_DIR)/control_scheduler/Vtb_scheduler_ctl_smoke
	mkdir -p $(GEN_DIR)/control_inline_scheduler
	$(VERILATOR) --cc --exe --main $(VERILATOR_SIM) \
		--top-module tb_inline_scheduler_smoke \
		-Mdir $(GEN_DIR)/control_inline_scheduler \
		-o Vtb_inline_scheduler_smoke \
		npu_rtl_pkg.sv \
		control/npu_inline_desc_decode.sv \
		control/npu_task_scheduler.sv \
		control/tb_inline_scheduler_smoke.sv
	mkdir -p $(BUILD_DIR)/control_inline_scheduler
	cp -a $(GEN_DIR)/control_inline_scheduler/. \
		$(BUILD_DIR)/control_inline_scheduler/
	$(MAKE) -C $(BUILD_DIR)/control_inline_scheduler \
		-f Vtb_inline_scheduler_smoke.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	$(BUILD_DIR)/control_inline_scheduler/Vtb_inline_scheduler_smoke

memory-test:
	mkdir -p $(GEN_DIR)/memory_smoke
	$(VERILATOR) --cc --exe --main $(VERILATOR_SIM) \
		--top-module tb_memory_smoke \
		-Mdir $(GEN_DIR)/memory_smoke \
		-o Vtb_memory_smoke \
		npu_rtl_pkg.sv \
		memory/npu_l1buf.sv \
		memory/npu_tbu.sv \
		memory/npu_axi_mif_master.sv \
		memory/tb_memory_smoke.sv
	mkdir -p $(BUILD_DIR)/memory_smoke
	cp -a $(GEN_DIR)/memory_smoke/. $(BUILD_DIR)/memory_smoke/
	$(MAKE) -C $(BUILD_DIR)/memory_smoke \
		-f Vtb_memory_smoke.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	$(BUILD_DIR)/memory_smoke/Vtb_memory_smoke

math-reference-test:
	mkdir -p $(GEN_DIR)/math_reference
	$(VERILATOR) --cc --exe --main $(VERILATOR_SIM) \
		-Wno-UNUSEDPARAM \
		--top-module tb_npu_math_reference \
		--Mdir $(GEN_DIR)/math_reference \
		-o Vtb_npu_math_reference \
		engines/npu_engine_pkg.sv \
		engines/npu_complex_math_core.sv \
		tb/tb_npu_math_reference.sv
	mkdir -p $(BUILD_DIR)/math_reference
	cp -a $(GEN_DIR)/math_reference/. $(BUILD_DIR)/math_reference/
	$(MAKE) -C $(BUILD_DIR)/math_reference \
		-f Vtb_npu_math_reference.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	$(BUILD_DIR)/math_reference/Vtb_npu_math_reference

frontend-test:
	mkdir -p $(GEN_DIR)/module_frontend
	$(VERILATOR) --cc --exe --main $(VERILATOR_SIM) \
		--top-module tb_npu_axi_slave_frontend \
		-Mdir $(GEN_DIR)/module_frontend \
		-o Vtb_npu_axi_slave_frontend \
		top/npu_axi_slave_frontend.sv \
		tb/tb_npu_axi_slave_frontend.sv
	mkdir -p $(BUILD_DIR)/module_frontend
	cp -a $(GEN_DIR)/module_frontend/. $(BUILD_DIR)/module_frontend/
	$(MAKE) -C $(BUILD_DIR)/module_frontend \
		-f Vtb_npu_axi_slave_frontend.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	$(BUILD_DIR)/module_frontend/Vtb_npu_axi_slave_frontend

engine-test:
	mkdir -p $(GEN_DIR)/module_engines
	$(VERILATOR) --cc --exe --main $(VERILATOR_SIM) \
		--top-module tb_npu_engines \
		-Mdir $(GEN_DIR)/module_engines \
		-o Vtb_npu_engines \
		npu_rtl_pkg.sv \
		engines/npu_engine_pkg.sv \
		memory/npu_l1buf.sv \
		engines/npu_complex_math_core.sv \
		engines/npu_dma_engine.sv \
		engines/npu_matrix_engine.sv \
		engines/npu_vector_engine.sv \
		engines/npu_complex_convert.sv \
		engines/npu_complex_engine.sv \
		tb/tb_npu_engines.sv
	mkdir -p $(BUILD_DIR)/module_engines
	cp -a $(GEN_DIR)/module_engines/. $(BUILD_DIR)/module_engines/
	$(MAKE) -C $(BUILD_DIR)/module_engines \
		-f Vtb_npu_engines.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	$(BUILD_DIR)/module_engines/Vtb_npu_engines

module-test: control-test memory-test math-reference-test frontend-test engine-test

system-test:
	mkdir -p $(GEN_DIR)/system
	$(VERILATOR) --cc --exe --main $(VERILATOR_SIM) \
		--top-module tb_npu_single_core \
		-Mdir $(GEN_DIR)/system \
		-o Vtb_npu_single_core \
		$(RTL_SRCS) \
		tb/tb_axi_memory_model.sv \
		tb/tb_npu_single_core.sv
	mkdir -p $(BUILD_DIR)/system
	cp -a $(GEN_DIR)/system/. $(BUILD_DIR)/system/
	$(MAKE) -C $(BUILD_DIR)/system \
		-f Vtb_npu_single_core.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	$(BUILD_DIR)/system/Vtb_npu_single_core

transformer-e2e:
	mkdir -p $(GEN_DIR)/transformer_e2e_data
	python3 tb/models/generate_transformer_e2e.py \
		--model tb/models/transformer_e2e_model.json \
		--output-dir $(GEN_DIR)/transformer_e2e_data
	mkdir -p $(GEN_DIR)/transformer_e2e
	$(VERILATOR) --cc --exe --main $(VERILATOR_TRANSFORMER) \
		-DNPU_TRANSFORMER_E2E \
		--top-module tb_npu_single_core \
		-Mdir $(GEN_DIR)/transformer_e2e \
		-o Vtb_npu_transformer_e2e \
		$(RTL_SRCS) \
		tb/tb_axi_memory_model.sv \
		tb/tb_npu_single_core.sv
	mkdir -p $(BUILD_DIR)/transformer_e2e
	cp -a $(GEN_DIR)/transformer_e2e/. $(BUILD_DIR)/transformer_e2e/
	$(MAKE) -C $(BUILD_DIR)/transformer_e2e \
		-f Vtb_npu_single_core.mk -j1 \
		$(VERILATOR_MAKE_FLAGS)
	python3 tb/models/generate_transformer_e2e.py \
		--model tb/models/transformer_e2e_model.json \
		--output-dir $(GEN_DIR)/transformer_e2e_data \
		--run $(BUILD_DIR)/transformer_e2e/Vtb_npu_transformer_e2e

test: lint module-test system-test transformer-e2e

clean:
	rm -rf $(BUILD_DIR) $(GEN_DIR) $(LOCAL_DEBUG_DIRS)
