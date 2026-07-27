if {$argc != 4} {
  puts stderr \
    "usage: run_vivado.tcl BUILD_DIR PART PERIOD_NS JOBS"
  exit 2
}

set build_dir [file normalize [lindex $argv 0]]
set part_name [lindex $argv 1]
set period_ns [lindex $argv 2]
set jobs [lindex $argv 3]
if {[expr {abs(double($period_ns) - 10.0) > 1.0e-9}]} {
  puts stderr "ERROR: this flow is constrained to a 10.000 ns period"
  exit 2
}
set script_dir [file dirname [file normalize [info script]]]
set rtl_root [file normalize [file join $script_dir ../..]]
set top_name npu_single_core_top

file mkdir $build_dir
set_param general.maxThreads $jobs

proc write_memory_primitive_report {report_path stage_name} {
  set report_file [open $report_path w]
  set ramb36_cells [lsort [get_cells -hierarchical -filter {
    REF_NAME =~ RAMB36*
  }]]
  set ramb18_cells [lsort [get_cells -hierarchical -filter {
    REF_NAME =~ RAMB18*
  }]]
  set lutram_cells [lsort [get_cells -hierarchical -filter {
    REF_NAME =~ RAMD* || REF_NAME =~ RAMS*
  }]]

  puts $report_file "stage=$stage_name"
  puts $report_file "ramb36_primitive_count=[llength $ramb36_cells]"
  puts $report_file "ramb18_primitive_count=[llength $ramb18_cells]"
  puts $report_file "lutram_primitive_count=[llength $lutram_cells]"
  puts $report_file ""
  puts $report_file "\[RAMB36\]"
  foreach memory_cell $ramb36_cells {
    puts $report_file "$memory_cell ref_name=[get_property REF_NAME $memory_cell]"
  }
  puts $report_file ""
  puts $report_file "\[RAMB18\]"
  foreach memory_cell $ramb18_cells {
    puts $report_file "$memory_cell ref_name=[get_property REF_NAME $memory_cell]"
  }
  puts $report_file ""
  puts $report_file "\[LUTRAM\]"
  foreach memory_cell $lutram_cells {
    puts $report_file "$memory_cell ref_name=[get_property REF_NAME $memory_cell]"
  }
  close $report_file
}

set rtl_files [list \
  [file join $rtl_root npu_rtl_pkg.sv] \
  [file join $rtl_root engines npu_engine_pkg.sv]]
foreach subdir {control memory engines top} {
  foreach rtl_file [lsort [glob -nocomplain \
      [file join $rtl_root $subdir npu_*.sv]]] {
    if {[file tail $rtl_file] ne "npu_engine_pkg.sv"} {
      lappend rtl_files $rtl_file
    }
  }
}

puts "INFO: part=$part_name period_ns=$period_ns"
puts "INFO: rtl_file_count=[llength $rtl_files]"
read_verilog -sv $rtl_files

set xdc_file [file join $script_dir npu_single_core_100mhz.xdc]
read_xdc [list $xdc_file]

synth_design \
  -top $top_name \
  -part $part_name \
  -flatten_hierarchy rebuilt \
  -mode out_of_context

opt_design
write_checkpoint -force [file join $build_dir post_synth.dcp]
report_utilization -hierarchical \
  -file [file join $build_dir utilization_post_synth.rpt]
report_timing_summary \
  -delay_type max \
  -report_unconstrained \
  -max_paths 20 \
  -file [file join $build_dir timing_post_synth.rpt]
report_timing \
  -delay_type max \
  -path_type full \
  -max_paths 30 \
  -nworst 10 \
  -input_pins \
  -file [file join $build_dir critical_paths_post_synth.rpt]
write_memory_primitive_report \
  [file join $build_dir memory_primitives_post_synth.rpt] \
  post_synth

place_design
phys_opt_design
route_design
write_checkpoint -force [file join $build_dir post_route.dcp]
report_utilization -hierarchical \
  -file [file join $build_dir utilization_post_route.rpt]
report_timing_summary \
  -delay_type max \
  -report_unconstrained \
  -max_paths 20 \
  -file [file join $build_dir timing_post_route.rpt]
report_timing \
  -delay_type max \
  -path_type full \
  -max_paths 30 \
  -nworst 10 \
  -input_pins \
  -file [file join $build_dir critical_paths_post_route.rpt]
report_methodology \
  -file [file join $build_dir methodology_post_route.rpt]
write_memory_primitive_report \
  [file join $build_dir memory_primitives_post_route.rpt] \
  post_route

set setup_paths [get_timing_paths -setup -max_paths 1]
set hold_paths [get_timing_paths -hold -max_paths 1]
set summary_file [file join $build_dir summary.txt]
set summary [open $summary_file w]
puts $summary "top=$top_name"
puts $summary "part=$part_name"
puts $summary "target_period_ns=$period_ns"
puts $summary "target_frequency_mhz=[expr {1000.0 / $period_ns}]"
puts $summary "clock_uncertainty_ns=0.200"
puts $summary "io_delay_ns=1.000"
if {[llength $setup_paths] > 0} {
  set setup_path [lindex $setup_paths 0]
  puts $summary "worst_setup_slack_ns=[get_property SLACK $setup_path]"
  puts $summary \
    "worst_setup_startpoint=[get_property STARTPOINT_PIN $setup_path]"
  puts $summary \
    "worst_setup_endpoint=[get_property ENDPOINT_PIN $setup_path]"
  puts $summary \
    "worst_setup_logic_levels=[get_property LOGIC_LEVELS $setup_path]"
  puts $summary \
    "worst_setup_datapath_delay_ns=[get_property DATAPATH_DELAY $setup_path]"
}
if {[llength $hold_paths] > 0} {
  set hold_path [lindex $hold_paths 0]
  puts $summary "worst_hold_slack_ns=[get_property SLACK $hold_path]"
}
puts $summary "ramb36_primitive_count=[llength [get_cells -hierarchical -filter {
  REF_NAME =~ RAMB36*
}]]"
puts $summary "ramb18_primitive_count=[llength [get_cells -hierarchical -filter {
  REF_NAME =~ RAMB18*
}]]"
puts $summary "lutram_primitive_count=[llength [get_cells -hierarchical -filter {
  REF_NAME =~ RAMD* || REF_NAME =~ RAMS*
}]]"
close $summary

puts "INFO: reports=$build_dir"
exit
