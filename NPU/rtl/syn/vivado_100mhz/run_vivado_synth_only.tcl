if {$argc != 5} {
  puts stderr \
    "usage: run_vivado_synth_only.tcl RTL_ROOT XDC BUILD_DIR PART PERIOD_NS"
  exit 2
}

set rtl_root [file normalize [lindex $argv 0]]
set xdc_file [file normalize [lindex $argv 1]]
set build_dir [file normalize [lindex $argv 2]]
set part_name [lindex $argv 3]
set period_ns [lindex $argv 4]
if {[expr {abs(double($period_ns) - 10.0) > 1.0e-9}]} {
  puts stderr "ERROR: this flow is constrained to a 10.000 ns period"
  exit 2
}

file mkdir $build_dir
set_param general.maxThreads 1

set rtl_files [list \
  [file join $rtl_root npu_rtl_pkg.sv] \
  [file join $rtl_root engines npu_engine_pkg.sv]]
foreach rtl_file [lsort [glob -nocomplain \
    [file join $rtl_root dip dip_*.sv]]] {
  lappend rtl_files $rtl_file
}
foreach subdir {control memory engines top} {
  foreach rtl_file [lsort [glob -nocomplain \
      [file join $rtl_root $subdir npu_*.sv]]] {
    if {[file tail $rtl_file] ne "npu_engine_pkg.sv"} {
      lappend rtl_files $rtl_file
    }
  }
}

puts "INFO: part=$part_name period_ns=$period_ns"
puts "INFO: rtl_root=$rtl_root"
puts "INFO: rtl_file_count=[llength $rtl_files]"
read_verilog -sv $rtl_files
read_xdc [list $xdc_file]

synth_design \
  -top npu_single_core_top \
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

set setup_paths [get_timing_paths -setup -max_paths 1]
set summary_file [file join $build_dir summary.txt]
set summary [open $summary_file w]
puts $summary "top=npu_single_core_top"
puts $summary "part=$part_name"
puts $summary "target_period_ns=$period_ns"
if {[llength $setup_paths] > 0} {
  set setup_path [lindex $setup_paths 0]
  puts $summary "worst_setup_slack_ns=[get_property SLACK $setup_path]"
  puts $summary \
    "worst_setup_startpoint=[get_property STARTPOINT_PIN $setup_path]"
  puts $summary \
    "worst_setup_endpoint=[get_property ENDPOINT_PIN $setup_path]"
}
close $summary

puts "INFO: reports=$build_dir"
exit
