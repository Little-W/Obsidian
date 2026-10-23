# Run inside the installed Tessent Shell. Keep this log with the run.
foreach command {
    set_context read_cell_library read_core_descriptions
    set_dft_specification_requirements set_design_level add_clocks
    set_defaults_value set_memory_instance_options read_def read_upf
    create_dft_specification report_config_data get_config_elements
    set_config_value read_config_data write_config_data
    process_dft_specification extract_icl create_patterns_specification
    process_patterns_specification run_testbench_simulations
    check_testbench_simulations
} {
    puts "\n=== $command ==="
    if {[llength [info commands $command]] == 0} {
        puts "COMMAND NOT AVAILABLE IN THIS CONTEXT"
    } else {
        help $command
    }
}
report_config_syntax DefaultsSpecification/DftSpecification/MemoryBist
