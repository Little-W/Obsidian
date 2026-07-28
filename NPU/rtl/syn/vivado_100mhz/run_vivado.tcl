if {($argc != 4) && ($argc != 5)} {
  puts stderr \
    "usage: run_vivado.tcl BUILD_DIR PART PERIOD_NS JOBS ?start_mode?"
  exit 2
}

set build_dir [file normalize [lindex $argv 0]]
set part_name [lindex $argv 1]
set period_ns [lindex $argv 2]
set jobs [lindex $argv 3]
set start_mode full
if {$argc == 5} {
  set start_mode [lindex $argv 4]
  if {($start_mode ne "resume_post_synth") &&
      ($start_mode ne "post_synth_only")} {
    puts stderr "ERROR: unsupported start mode: $start_mode"
    exit 2
  }
}
set required_part xc7a200tfbg484-3

if {$part_name ne $required_part} {
  puts stderr \
    "ERROR: this acceptance flow is fixed to part $required_part"
  exit 2
}
if {[expr {abs(double($period_ns) - 10.0) > 1.0e-9}]} {
  puts stderr "ERROR: this acceptance flow is fixed to a 10.000 ns period"
  exit 2
}
if {![string is integer -strict $jobs] || ($jobs != 1)} {
  puts stderr "ERROR: this acceptance flow requires JOBS=1"
  exit 2
}

set script_dir [file dirname [file normalize [info script]]]
set rtl_root [file normalize [file join $script_dir ../..]]
set top_name npu_single_core_top
set timing_path_count 200

file mkdir $build_dir
set_param general.maxThreads 1
set_msg_config -id {Timing 38-242} -new_severity ERROR
set_msg_config -id {Route 35-197} -new_severity ERROR

proc unique_normalized_files {file_list} {
  set unique_files [list]
  set seen [dict create]
  foreach input_file $file_list {
    set normalized_file [file normalize $input_file]
    if {![dict exists $seen $normalized_file]} {
      dict set seen $normalized_file 1
      lappend unique_files $normalized_file
    }
  }
  return $unique_files
}

proc assert_clock_source_constraints {} {
  foreach {port_name site_name} {
    core_clk_i BUFGCTRL_X0Y0
  } {
    set clock_port [get_ports -quiet $port_name]
    if {[llength $clock_port] != 1} {
      error "clock-source check failed: expected one port named $port_name"
    }
    if {[llength [get_sites -quiet $site_name]] != 1} {
      error "clock-source check failed: site $site_name is not present on the selected part"
    }
    set applied_site [get_property HD.CLK_SRC $clock_port]
    if {$applied_site ne $site_name} {
      error "clock-source check failed: $port_name HD.CLK_SRC is '$applied_site', expected '$site_name'"
    }
    puts "INFO: clock-source check passed: $port_name HD.CLK_SRC=$applied_site"
  }
}

proc get_memory_cells {scope_pattern ref_filter} {
  return [lsort [get_cells -quiet -hierarchical -filter \
    "NAME =~ $scope_pattern && ($ref_filter)"]]
}

proc write_cell_list {report_file section_name cells} {
  puts $report_file ""
  puts $report_file "\[$section_name\]"
  foreach memory_cell $cells {
    puts $report_file \
      "$memory_cell ref_name=[get_property REF_NAME $memory_cell]"
  }
}

proc memory_counts {} {
  set all_scope "*"
  set l1_scope "*u_l1buf/*"
  set ramb36_filter {REF_NAME =~ RAMB36*}
  set ramb18_filter {REF_NAME =~ RAMB18*}
  set lutram_filter {
    REF_NAME =~ RAMD* ||
    REF_NAME =~ RAMS* ||
    REF_NAME =~ RAM32* ||
    REF_NAME =~ RAM64* ||
    REF_NAME =~ RAM128* ||
    REF_NAME =~ RAM256*
  }
  set ff_filter {REF_NAME =~ FD*}

  set all_ramb36 [get_memory_cells $all_scope $ramb36_filter]
  set all_ramb18 [get_memory_cells $all_scope $ramb18_filter]
  set all_lutram [get_memory_cells $all_scope $lutram_filter]
  set l1_ramb36 [get_memory_cells $l1_scope $ramb36_filter]
  set l1_ramb18 [get_memory_cells $l1_scope $ramb18_filter]
  set l1_lutram [get_memory_cells $l1_scope $lutram_filter]
  set l1_ff [get_memory_cells $l1_scope $ff_filter]
  set l1_memory_ff [get_memory_cells \
    "*u_l1buf/*memory_q*" $ff_filter]

  return [dict create \
    all_ramb36 $all_ramb36 \
    all_ramb18 $all_ramb18 \
    all_lutram $all_lutram \
    l1_ramb36 $l1_ramb36 \
    l1_ramb18 $l1_ramb18 \
    l1_lutram $l1_lutram \
    l1_ff $l1_ff \
    l1_memory_ff $l1_memory_ff]
}

proc write_memory_primitive_report {report_path stage_name} {
  set counts [memory_counts]
  set report_file [open $report_path w]

  puts $report_file "stage=$stage_name"
  foreach count_name {
    all_ramb36 all_ramb18 all_lutram
    l1_ramb36 l1_ramb18 l1_lutram l1_ff l1_memory_ff
  } {
    puts $report_file \
      "${count_name}_primitive_count=[llength [dict get $counts $count_name]]"
  }
  puts $report_file \
    "l1_mapping_expected=256_RAMB36_0_RAMB18_0_LUTRAM_0_memory_named_FF"

  write_cell_list $report_file RAMB36 [dict get $counts all_ramb36]
  write_cell_list $report_file RAMB18 [dict get $counts all_ramb18]
  write_cell_list $report_file LUTRAM [dict get $counts all_lutram]
  write_cell_list $report_file L1_RAMB36 [dict get $counts l1_ramb36]
  write_cell_list $report_file L1_RAMB18 [dict get $counts l1_ramb18]
  write_cell_list $report_file L1_LUTRAM [dict get $counts l1_lutram]
  write_cell_list $report_file L1_FF [dict get $counts l1_ff]
  write_cell_list \
    $report_file L1_MEMORY_NAMED_FF [dict get $counts l1_memory_ff]
  close $report_file
}

proc assert_l1_mapping {stage_name} {
  set counts [memory_counts]
  set l1_ramb36_count [llength [dict get $counts l1_ramb36]]
  set l1_ramb18_count [llength [dict get $counts l1_ramb18]]
  set l1_lutram_count [llength [dict get $counts l1_lutram]]
  set l1_memory_ff_count [llength [dict get $counts l1_memory_ff]]

  if {
    ($l1_ramb36_count != 256) ||
    ($l1_ramb18_count != 0) ||
    ($l1_lutram_count != 0) ||
    ($l1_memory_ff_count != 0)
  } {
    error \
      "L1 mapping check failed at $stage_name: RAMB36=$l1_ramb36_count RAMB18=$l1_ramb18_count LUTRAM=$l1_lutram_count memory_named_FF=$l1_memory_ff_count"
  }
  puts \
    "INFO: L1 mapping check passed at $stage_name: 256 RAMB36, no RAMB18/LUTRAM/memory-named FF"
}

proc timing_violation_metrics {check_type} {
  if {$check_type eq "setup"} {
    set worst_paths [get_timing_paths -quiet -setup -max_paths 1]
    set failing_paths [get_timing_paths -quiet -setup \
      -max_paths 1000000 -nworst 1 -slack_lesser_than 0.0]
  } elseif {$check_type eq "hold"} {
    set worst_paths [get_timing_paths -quiet -hold -max_paths 1]
    set failing_paths [get_timing_paths -quiet -hold \
      -max_paths 1000000 -nworst 1 -slack_lesser_than 0.0]
  } else {
    error "unsupported timing check type: $check_type"
  }

  set worst_slack NA
  set worst_startpoint NA
  set worst_endpoint NA
  set worst_logic_levels NA
  set worst_datapath_delay NA
  if {[llength $worst_paths] > 0} {
    set worst_path [lindex $worst_paths 0]
    set worst_slack [get_property SLACK $worst_path]
    set worst_startpoint [get_property STARTPOINT_PIN $worst_path]
    set worst_endpoint [get_property ENDPOINT_PIN $worst_path]
    set worst_logic_levels [get_property LOGIC_LEVELS $worst_path]
    set worst_datapath_delay [get_property DATAPATH_DELAY $worst_path]
  }

  set total_negative_slack 0.0
  foreach timing_path $failing_paths {
    set path_slack [get_property SLACK $timing_path]
    if {$path_slack < 0.0} {
      set total_negative_slack \
        [expr {$total_negative_slack + double($path_slack)}]
    }
  }

  return [dict create \
    worst_slack $worst_slack \
    total_negative_slack [format %.3f $total_negative_slack] \
    failing_endpoints [llength $failing_paths] \
    worst_startpoint $worst_startpoint \
    worst_endpoint $worst_endpoint \
    worst_logic_levels $worst_logic_levels \
    worst_datapath_delay $worst_datapath_delay]
}

proc write_stage_reports {
  build_dir stage_name timing_path_count part_name period_ns
} {
  report_utilization \
    -file [file join $build_dir utilization_${stage_name}.rpt]
  report_utilization -hierarchical \
    -file [file join $build_dir utilization_hierarchical_${stage_name}.rpt]
  if {[llength [info commands report_ram_utilization]] > 0} {
    report_ram_utilization -include_lutram \
      -file [file join $build_dir ram_utilization_${stage_name}.rpt]
  }

  report_timing_summary \
    -delay_type min_max \
    -no_detailed_paths \
    -report_unconstrained \
    -file [file join $build_dir timing_summary_${stage_name}.rpt]
  report_timing \
    -delay_type max \
    -path_type full \
    -max_paths $timing_path_count \
    -nworst 1 \
    -input_pins \
    -routable_nets \
    -file [file join $build_dir timing_paths_setup_${stage_name}.rpt]
  report_timing \
    -delay_type min \
    -path_type full \
    -max_paths $timing_path_count \
    -nworst 1 \
    -input_pins \
    -routable_nets \
    -file [file join $build_dir timing_paths_hold_${stage_name}.rpt]

  write_memory_primitive_report \
    [file join $build_dir memory_primitives_${stage_name}.rpt] \
    $stage_name
  assert_l1_mapping $stage_name

  set setup_metrics [timing_violation_metrics setup]
  set hold_metrics [timing_violation_metrics hold]
  set counts [memory_counts]
  set summary_path [file join $build_dir summary_${stage_name}.txt]
  set summary [open $summary_path w]
  puts $summary "stage=$stage_name"
  puts $summary "top=npu_single_core_top"
  puts $summary "part=$part_name"
  puts $summary "target_period_ns=$period_ns"
  puts $summary "target_frequency_mhz=[expr {1000.0 / $period_ns}]"
  puts $summary "clock_uncertainty_ns=0.200"
  puts $summary "io_delay_ns=1.000"
  puts $summary \
    "WNS_ns=[dict get $setup_metrics worst_slack]"
  puts $summary \
    "TNS_ns=[dict get $setup_metrics total_negative_slack]"
  puts $summary \
    "setup_failing_endpoints=[dict get $setup_metrics failing_endpoints]"
  puts $summary \
    "WHS_ns=[dict get $hold_metrics worst_slack]"
  puts $summary \
    "THS_ns=[dict get $hold_metrics total_negative_slack]"
  puts $summary \
    "hold_failing_endpoints=[dict get $hold_metrics failing_endpoints]"
  puts $summary \
    "worst_setup_startpoint=[dict get $setup_metrics worst_startpoint]"
  puts $summary \
    "worst_setup_endpoint=[dict get $setup_metrics worst_endpoint]"
  puts $summary \
    "worst_setup_logic_levels=[dict get $setup_metrics worst_logic_levels]"
  puts $summary \
    "worst_setup_datapath_delay_ns=[dict get $setup_metrics worst_datapath_delay]"
  puts $summary \
    "worst_hold_startpoint=[dict get $hold_metrics worst_startpoint]"
  puts $summary \
    "worst_hold_endpoint=[dict get $hold_metrics worst_endpoint]"
  foreach count_name {
    all_ramb36 all_ramb18 all_lutram
    l1_ramb36 l1_ramb18 l1_lutram l1_ff l1_memory_ff
  } {
    puts $summary \
      "${count_name}_primitive_count=[llength [dict get $counts $count_name]]"
  }
  close $summary

  return [dict create setup $setup_metrics hold $hold_metrics]
}

if {$start_mode ne "resume_post_synth"} {
  set rtl_candidates [list \
    [file join $rtl_root npu_rtl_pkg.sv] \
    [file join $rtl_root engines npu_engine_pkg.sv]]
  foreach rtl_file [lsort [glob -nocomplain \
      [file join $rtl_root dip dip_*.sv]]] {
    lappend rtl_candidates $rtl_file
  }
  foreach subdir {control memory engines top} {
    foreach rtl_file [lsort [glob -nocomplain \
        [file join $rtl_root $subdir npu_*.sv]]] {
      if {[file tail $rtl_file] ne "npu_engine_pkg.sv"} {
        lappend rtl_candidates $rtl_file
      }
    }
  }
  set rtl_files [unique_normalized_files $rtl_candidates]

  puts "INFO: part=$part_name period_ns=$period_ns jobs=$jobs"
  puts \
    "INFO: rtl_input_count=[llength $rtl_candidates] unique_rtl_file_count=[llength $rtl_files]"
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
} else {
  set resume_checkpoint [file join $build_dir post_synth.dcp]
  if {![file exists $resume_checkpoint]} {
    puts stderr "ERROR: resume checkpoint not found: $resume_checkpoint"
    exit 2
  }
  puts "INFO: resuming implementation from $resume_checkpoint"
  open_checkpoint $resume_checkpoint
}
assert_clock_source_constraints
set post_synth_metrics \
  [write_stage_reports \
    $build_dir post_synth $timing_path_count $part_name $period_ns]

if {$start_mode eq "post_synth_only"} {
  puts "INFO: post-synthesis reports=$build_dir"
  exit
}

place_design
phys_opt_design
route_design
write_checkpoint -force [file join $build_dir post_route.dcp]
report_route_status \
  -file [file join $build_dir route_status_post_route.rpt]
report_methodology \
  -file [file join $build_dir methodology_post_route.rpt]
set post_route_metrics \
  [write_stage_reports \
    $build_dir post_route $timing_path_count $part_name $period_ns]

set final_summary_path [file join $build_dir summary.txt]
set final_summary [open $final_summary_path w]
puts $final_summary "top=$top_name"
puts $final_summary "part=$part_name"
puts $final_summary "target_period_ns=$period_ns"
puts $final_summary "target_frequency_mhz=[expr {1000.0 / $period_ns}]"
puts $final_summary "jobs=$jobs"
foreach stage_name {post_synth post_route} stage_metrics \
    [list $post_synth_metrics $post_route_metrics] {
  set setup_metrics [dict get $stage_metrics setup]
  set hold_metrics [dict get $stage_metrics hold]
  puts $final_summary \
    "${stage_name}_WNS_ns=[dict get $setup_metrics worst_slack]"
  puts $final_summary \
    "${stage_name}_TNS_ns=[dict get $setup_metrics total_negative_slack]"
  puts $final_summary \
    "${stage_name}_WHS_ns=[dict get $hold_metrics worst_slack]"
  puts $final_summary \
    "${stage_name}_THS_ns=[dict get $hold_metrics total_negative_slack]"
}
set final_counts [memory_counts]
foreach count_name {
  all_ramb36 all_ramb18 all_lutram
  l1_ramb36 l1_ramb18 l1_lutram l1_ff l1_memory_ff
} {
  puts $final_summary \
    "post_route_${count_name}_primitive_count=[llength [dict get $final_counts $count_name]]"
}
puts $final_summary "l1_mapping_check=PASS"
close $final_summary

puts "INFO: reports=$build_dir"
exit
