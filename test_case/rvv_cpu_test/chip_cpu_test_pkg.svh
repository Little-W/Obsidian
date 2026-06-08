

`ifndef CHIP_CPU_TEST_PKG_SV
`define CHIP_CPU_TEST_PKG_SV

package chip_cpu_test_pkg;

`ifdef CPU_TEST
    `include "uvm_macros.svh"
    import uvm_pkg::*;
    import reset_pkg::*;
    import svt_uvm_pkg::*;
    import svt_amba_uvm_pkg::*;
    import chip_top_seq_pkg::*;
    import chip_top_env_pkg::*;
    import chip_top_test_pkg::*;

//`ifndef CPU_SP_MODE_TEST
    `include "./chip_cpu_base_test.sv"
    `include "./cpu_intr_connection_test/intr_macros.sv"
    `include "./cpu_ilm_boot_test/cpu_ilm_boot_test.sv"
    `include "./cpu_rom_boot_test/cpu_rom_boot_test.sv"
    `include "./cpu_clk_test/cpu_clk_test.sv"
    `include "./cpu_systemreq_reset_test/cpu_systemreq_reset_test.sv"
    `include "./cpu_reset_bypass_test/cpu_reset_bypass_test.sv"
    `include "./cpu_clkgate_bypass_test/cpu_clkgate_bypass_test.sv"
    `include "./cpu_sram_boot_test/cpu_sram_boot_test.sv"
    `include "./cpu_dual_core_boot_test/cpu_dual_core_boot_test.sv"
    `include "./cpu_addw_instr_test/cpu_addw_instr_test.sv"
    `include "./cpu_muldiv_instr_test/cpu_muldiv_instr_test.sv"
    `include "./cpu_fp_instr_test/cpu_fp_instr_test.sv"
    `include "./cpu_dsp_instr_test/cpu_dsp_instr_test.sv"
    `include "./cpu_disable_cache_test/cpu_disable_cache_test.sv"
    `include "./cpu_wfi_test/cpu_wfi_test.sv"
    `include "./cpu_wfe_test/cpu_wfe_test.sv"
    `include "./cpu_enable_mmu_test/cpu_enable_mmu_test.sv"
    `include "./cpu_int_msg_test/cpu_int_msg_test.sv"
    `include "./cpu_int_msg1_test/cpu_int_msg1_test.sv"
    `include "./cpu_int_msg2_test/cpu_int_msg2_test.sv"
    `include "./cpu_int_msg3_test/cpu_int_msg3_test.sv"
    `include "./cpu_int_plic_test/cpu_int_plic_test.sv"
    `include "./cpu_int_plic1_test/cpu_int_plic1_test.sv"
    `include "./cpu_int_eclic_test/cpu_int_eclic_test.sv"
    `include "./cpu_int_eclic1_test/cpu_int_eclic1_test.sv"
    `include "./cpu_int_eclic2_test/cpu_int_eclic2_test.sv"
    `include "./cpu_int_eclic3_test/cpu_int_eclic3_test.sv"
    `include "./cpu_reg_feature_test/cpu_reg_feature_test.sv"
    `include "./cpu_access_clm_test/cpu_access_clm_test.sv"
    `include "./cpu_int_mailbox_test/cpu_int_mailbox_test.sv"
    `include "./cpu_pmp_region_test/cpu_pmp_region_test.sv"
    `include "./demo_cache_test/demo_cache_test.sv"
    `include "./demo_eclic_test/demo_eclic_test.sv"
    `include "./demo_timer_test/demo_timer_test.sv"
    `include "./demo_coremark_test/demo_coremark_test.sv"
    `include "./demo_dhrystone_test/demo_dhrystone_test.sv"
    `include "./demo_clint_timer_test/demo_clint_timer_test.sv"
    `include "./demo_pma_test/demo_pma_test.sv"
    `include "./demo_pmp_test/demo_pmp_test.sv"

    `include "./cpu_cov_test/cpu_cov_test.sv"
    `include "./cpu_core1_wfi_test/cpu_core1_wfi_test.sv"
    `include "./cpu_core1_wfe_test/cpu_core1_wfe_test.sv"
    `include "./cpu_wfi_deep_test/cpu_wfi_deep_test.sv"
    `include "./cpu_atb_axi_test/cpu_atb_axi_test.sv"
    `include "./cpu_atb_axi_sram_low_test/cpu_atb_axi_sram_low_test.sv"
    `include "./cpu_atb_axi_sram_mid_test/cpu_atb_axi_sram_mid_test.sv"
    `include "./cpu_atb_axi_sram_high_test/cpu_atb_axi_sram_high_test.sv"
    `include "./cpu_atb_axi_ddr_high_test/cpu_atb_axi_ddr_high_test.sv"
    `include "./cpu_atb_axi_ddr_mid_test/cpu_atb_axi_ddr_mid_test.sv"
    `include "./cpu_atb_axi_ddr_low_test/cpu_atb_axi_ddr_low_test.sv"
    `include "./cpu_core1_wfi_deep_test/cpu_core1_wfi_deep_test.sv"

    `include "./cpu_reg_feature_test/cpu_reg_feature_test.sv"
    `include "./cpu_reg_feature_test_ddr0_noc/cpu_reg_feature_test_ddr0_noc.sv"
    `include "./cpu_reg_feature_test_ddr1_noc/cpu_reg_feature_test_ddr1_noc.sv"
    `include "./cpu_reg_feature_test_ddr2_noc/cpu_reg_feature_test_ddr2_noc.sv"
    `include "./cpu_reg_feature_test_ddr3_noc/cpu_reg_feature_test_ddr3_noc.sv"

    `include "./cpu_reg_feature_test_efu_mcu0/cpu_reg_feature_test_efu_mcu0.sv"
    `include "./cpu_reg_feature_test_tcu_iomux/cpu_reg_feature_test_tcu_iomux.sv"
    `include "./cpu_reg_feature_test_usb_eth/cpu_reg_feature_test_usb_eth.sv"
	`include "./cpu_reg_feature_test_pcie/cpu_reg_feature_test_pcie.sv"
	`include "./cpu_reg_feature_test_ddrctr_atb/cpu_reg_feature_test_ddrctr_atb.sv"
    `include "./cpu_memmap_test/cpu_memmap_test.sv"
    `include "./cpu_memmap2_test/cpu_memmap2_test.sv"
    `include "./cpu_memmap3_test/cpu_memmap3_test.sv"
    `include "./cpu_memmap4_test/cpu_memmap4_test.sv"
    `include "./cpu_memmap5_test/cpu_memmap5_test.sv"
    `include "./cpu_mem_rresp_test/cpu_mem_rresp_test.sv"
    `include "./cpu_core1_vector_test/cpu_core1_vector_test.sv"

//`endif // CPU_SP_MODE_TEST

   // `include "./cpu_sp_mode_test/cpu_sp_mode_test.sv"

`endif

endpackage

`endif
