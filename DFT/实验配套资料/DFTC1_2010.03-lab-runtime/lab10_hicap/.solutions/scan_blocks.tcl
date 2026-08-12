# bottom up scan insertion flow
# scan replace the sub-blocks

set test_default_delay 0
set test_default_bidir_delay 0
set test_default_strobe 40


set designs {BLENDER RESET_BLOCK PCI_WFIFO PCI_CORE PARSER PCI_RFIFO RISC_CORE \
		 CONTEXT_MEM SD_W_MUX SDRAM_WFIFO SDRAM_IF SDRAM_RFIFO PCI_W_MUX}

foreach design $designs {
    
    # read in the mapped scan-replaced sub-block (no scan chains yet)

    read_ddc mapped/${design}.ddc
    current_design ${design}

    # Recommended scan settings for blocks

    set_dft_configuration  -fix_bus disable
    set_scan_configuration -clock_mix no_mix
    set_scan_configuration -create_dedicated_scan_out_ports true
    set_scan_configuration -max_length 100

    # Specify terminal lockup latches (except for SDRAM_IF)

    if { $design != "SDRAM_IF" } {
      set_scan_configuration -insert_terminal_lockup true
    }

    # Specify block-level clocks

    set clk_ports [get_ports "*clk fifo_clk*" -quiet]
    if { [sizeof_collection $clk_ports] > 0 } {
      set_dft_signal -view exist -type ScanClock -port $clk_ports -timing {45 55}
    }

    # Specify block-level Resets

    set clk_ports [filter_collection [all_inputs] "full_name=~*rst_n||full_name=~*reset_n"]
    if { [sizeof_collection $clk_ports] > 0 } {
      set_dft_signal -view exist -type Reset -active 0 -port $clk_ports
    }

    # test_mode exists on some blocks

    set tm_ports [get_ports "test_mode" -quiet]
    if { [sizeof_collection $tm_ports] > 0 } {
      set_dft_signal -view exist -type Constant -active 1 -port test_mode
    }

    # Create test protocol

    create_test_protocol

    # Perform gate-level DFT checks

    redirect -tee reports/${design}_dft_drc.rpt {dft_drc}

    # Preview the block-level scan chains

    redirect -tee reports/${design}_preview_dft.rpt {preview_dft -show scan_clocks}

    # Insert the block-level scan structures

    set_dft_insertion_configuration -synthesis none -preserve_design true
    insert_dft

    # Obtain block-level estimate of test coverage

    redirect -tee reports/${design}_coverage.rpt {dft_drc -coverage_estimate}

    # Document what happened during scan insertion

    report_dft_signal -view spec  > reports/${design}_test.rpt
    report_dft_signal -view exist >> reports/${design}_test.rpt
    report_dft_configuration >> reports/${design}_test.rpt
    report_scan_state >> reports/${design}_test.rpt
    report_scan_path -view exist > reports/${design}_scan_path.rpt

    # Handoff the block

    # Avoid naming issues between tools

    change_names -rule verilog -hierarchy

    # Save out the gate-level scan netlist for the block

    write -f verilog -h -o tmax/${design}_gates.v

    # It is good practice to to save the .ddc file, too
    # For example, tools such as PT and PC would prefer this format

    write -format ddc -hierarchy -output mapped_scan/${design}.ddc

    # Save the Test Model HERE

    write_test_model -format ddc -output test_models/${design}.ddc

    # Save the updated protocol

    set test_stil_netlist_format verilog
    write_test_protocol -o tmax/${design}.spf

    # Everything has been saved, remove current design and free up memory

    remove_design -designs
}
