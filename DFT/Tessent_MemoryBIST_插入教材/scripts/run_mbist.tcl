# Entry: tessent -shell -dofile scripts/run_mbist.tcl
# Requires a project-specific scripts/site_local.tcl and licensed Tessent.
set ROOT [file normalize [file join [file dirname [info script]] ..]]
set LOCAL [file join $ROOT scripts site_local.tcl]
if {![file isfile $LOCAL]} {
    error "Create scripts/site_local.tcl from site_setup.tcl; real RTL and libraries are required."
}
source $LOCAL
proc require_file {path} {
    if {![file isfile $path]} {error "Missing file: $path"}
}
proc require_config {path} {
    set n [get_config_elements $path -count]
    if {$n != 1} {error "Expected one config object; found $n: $path"}
}
proc ensure_wrapper {path} {
    set n [get_config_elements $path -count]
    if {$n == 0} {add_config_element $path}
    require_config $path
}
foreach list_name {TESSENT_CELL_LIBS RTL_FILES MEMORY_TCD_FILES} {
    if {[llength [set $list_name]] == 0} {error "$list_name must not be empty"}
    foreach f [set $list_name] {require_file $f}
}
if {$RUN_STAGE ni {plan insert patterns simulate}} {error "Invalid RUN_STAGE"}
if {$ALGO_MODE ni {preserve builtin_default builtin_extra uda_default uda_extra soft}} {
    error "Invalid ALGO_MODE"
}
set OUT [file join $ROOT work]
if {[info exists ::env(MBIST_WORK)]} {set OUT [file normalize $::env(MBIST_WORK)]}
if {[file exists [file join $OUT tsdb]]} {
    error "Existing TSDB found. Select a fresh MBIST_WORK directory; do not overwrite a prior run."
}
file mkdir [file join $OUT reports]

set_context dft -rtl
set_tsdb_output_directory [file join $OUT tsdb]
foreach f $TESSENT_CELL_LIBS {read_cell_library $f}
foreach f $MEMORY_TCD_FILES {read_core_descriptions $f}
if {$ALGO_MODE in {uda_default uda_extra}} {
    read_core_descriptions [file join $ROOT algorithms lab_march_cminus.tcd_mem_lib]
}
foreach f $RTL_FILES {read_verilog $f}
set_current_design $TOP
set_design_level $DESIGN_LEVEL
set_dft_specification_requirements -memory_test on
foreach item $CLOCKS {
    if {[llength $item] != 3} {error "CLOCKS entries must be {port period label}"}
    lassign $item port period label
    add_clocks $port -period $period -label $label
}
if {$POWER_UPF ne ""} {require_file $POWER_UPF; read_upf $POWER_UPF}
if {$FLOORPLAN_DEF ne ""} {require_file $FLOORPLAN_DEF; read_def $FLOORPLAN_DEF}
if {$PHYSICAL_CLUSTER_RATIO ne ""} {
    if {$FLOORPLAN_DEF eq ""} {error "This example requires a DEF for physical clustering"}
    set_memory_instance_options -physical_cluster_size_ratio $PHYSICAL_CLUSTER_RATIO
}
source [file join $ROOT scripts grouping_defaults.tcl]
if {$GROUPING_TAGS ne ""} {require_file $GROUPING_TAGS; source $GROUPING_TAGS}
if {$SITE_EXTRA_SETUP ne ""} {require_file $SITE_EXTRA_SETUP; source $SITE_EXTRA_SETUP}
report_memory_instances
check_design_rules

# Exact import bypasses automatic specification creation in this fresh session.
if {$MANUAL_DFT_SPEC eq ""} {
    set spec [create_dft_specification]
} else {
    require_file $MANUAL_DFT_SPEC
    read_config_data $MANUAL_DFT_SPEC
    set spec [get_config_elements DftSpecification]
    require_config $spec
}
write_config_data [file join $OUT reports 00_initial.dft_spec] -wrappers $spec

if {$ALGO_MODE ne "preserve"} {
    foreach cid $CONTROLLERS {
        set ctl "${spec}/MemoryBist/Controller($cid)"
        require_config $ctl
        if {$ALGO_MODE eq "soft"} {
            ensure_wrapper "${ctl}/AlgorithmResourceOptions"
            set_config_value soft_instruction_count \
                -in_wrapper "${ctl}/AlgorithmResourceOptions" $SOFT_INSTRUCTIONS
            # The waveform operation set still has to exist in generated hardware.
            ensure_wrapper "${ctl}/AdvancedOptions"
            set_config_value extra_operation_sets \
                -in_wrapper "${ctl}/AdvancedOptions" $OPERATION_SET
        } else {
            ensure_wrapper "${ctl}/AdvancedOptions"
            if {$ALGO_MODE in {builtin_default uda_default}} {
                set_config_value algorithm -in_wrapper "${ctl}/AdvancedOptions" $ALGORITHM
                set_config_value operation_set -in_wrapper "${ctl}/AdvancedOptions" $OPERATION_SET
            } else {
                set_config_value extra_algorithms -in_wrapper "${ctl}/AdvancedOptions" $ALGORITHM
                set_config_value extra_operation_sets -in_wrapper "${ctl}/AdvancedOptions" $OPERATION_SET
            }
        }
    }
}
report_config_data "${spec}/MemoryBist" -show_unspecified
write_config_data [file join $OUT reports 01_final.dft_spec] -wrappers $spec
process_dft_specification -validate_only
if {$RUN_STAGE eq "plan"} {exit}

process_dft_specification
extract_icl
if {$RUN_STAGE eq "insert"} {exit}
if {$ALGO_MODE eq "soft"} {
    read_core_descriptions [file join $ROOT algorithms lab_march_cminus.tcd_mem_lib]
}
set pat_spec [create_patterns_specification]
write_config_data [file join $OUT reports 02_initial.pat_spec] -wrappers $pat_spec
if {$FULL_ADDRESS_TEST} {
    if {[llength $PATTERN_MBIST_SCOPES] == 0} {error "Explicit pattern MemoryBist scopes are required"}
    foreach relative $PATTERN_MBIST_SCOPES {
        set mb "${pat_spec}/$relative"
        require_config $mb
        set_config_value reduced_address_count -in_wrapper $mb off
    }
}
if {$ALGO_MODE ne "preserve"} {
    if {[llength $PATTERN_CONTROLLER_TARGETS] == 0} {
        error "Inspect 02_initial.pat_spec, set PATTERN_CONTROLLER_TARGETS, then rerun in a fresh work directory."
    }
    foreach relative $PATTERN_CONTROLLER_TARGETS {
        set pc "${pat_spec}/$relative"
        require_config $pc
        ensure_wrapper "${pc}/AdvancedOptions"
        set_config_value apply_algorithm -in_wrapper "${pc}/AdvancedOptions" $ALGORITHM
        set_config_value apply_operation_set -in_wrapper "${pc}/AdvancedOptions" $OPERATION_SET
    }
}
write_config_data [file join $OUT reports 03_final.pat_spec] -wrappers $pat_spec
report_config_data $pat_spec
process_patterns_specification
if {$RUN_STAGE eq "patterns"} {exit}

if {[llength $SIM_VERILOG_FILES] == 0} {error "Provide simulation models before simulation"}
set cmd [list set_simulation_library_sources]
foreach f $SIM_VERILOG_FILES {require_file $f; lappend cmd -v $f}
{*}$cmd
if {$SITE_SIM_SETUP ne ""} {require_file $SITE_SIM_SETUP; source $SITE_SIM_SETUP}
run_testbench_simulations
check_testbench_simulations
exit
