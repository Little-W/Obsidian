# Package order matters for SystemVerilog analysis.
rtl_snapshot/npu_rtl_pkg.sv
rtl_snapshot/engines/npu_engine_pkg.sv

rtl_snapshot/control/npu_inline_desc_decode.sv
rtl_snapshot/control/npu_cmd_frontend.sv
rtl_snapshot/control/npu_task_scheduler.sv
rtl_snapshot/control/npu_descriptor_fetch.sv
rtl_snapshot/control/npu_lsc.sv
rtl_snapshot/control/npu_wdt.sv
rtl_snapshot/control/npu_crg.sv

rtl_snapshot/engines/npu_dma_engine.sv
rtl_snapshot/engines/npu_matrix_engine.sv
rtl_snapshot/engines/npu_vector_engine.sv
rtl_snapshot/engines/npu_complex_convert.sv
rtl_snapshot/engines/npu_complex_math_core.sv
rtl_snapshot/engines/npu_complex_engine.sv

rtl_snapshot/memory/npu_tbu.sv
rtl_snapshot/memory/npu_axi_mif_master.sv
rtl_snapshot/top/npu_mif_arbiter.sv
rtl_snapshot/top/npu_axi_slave_frontend.sv

# The synthesizable timing wrapper replaces the behavioral 1 MiB array.
npu_l1buf_timing_wrapper.sv
rtl_snapshot/top/npu_single_core_top.sv
