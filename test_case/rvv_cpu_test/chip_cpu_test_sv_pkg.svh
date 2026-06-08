

`ifndef CHIP_CPU_TEST_SV_PKG_SV
`define CHIP_CPU_TEST_SV_PKG_SV

package chip_cpu_test_sv_pkg;

`ifdef CPU_SV_TEST
    `include "uvm_macros.svh"
    import uvm_pkg::*;
    import reset_pkg::*;
    import svt_uvm_pkg::*;
    import chip_top_seq_pkg::*;
    import chip_top_env_pkg::*;
    import chip_top_test_pkg::*;
    `include "./cpu_intr_connection_test/intr_macros.sv"
    `include "./npu_intr_connection_test/npu_intr_macros.sv"
    `include "./cpu_event_connection_test/event_macros.sv"
    `include "./demo_sram_scan_test/demo_sram_scan_test.sv"
    `include "./cpu_intr_connection_test/cpu_intr_connection_test.sv"
    `include "./npu_intr_connection_test/npu_intr_connection_test.sv"
    `include "./cpu_event_connection_test/cpu_event_connection_test.sv"

`endif

endpackage

`endif
