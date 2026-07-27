set script_dir [file dirname [file normalize [info script]]]
set report_dir [file join $script_dir reports baseline_400mhz]
set work_dir [file join $script_dir WORK_baseline_400mhz]
set top_name npu_single_core_top

file mkdir $report_dir
file mkdir $work_dir

set library_dir \
  /home/yusen/opt/xinyuan/syn_env/lib/FreePDK45/osu_soc/lib/files
set search_path [concat $search_path [list $library_dir $script_dir]]
set target_library [list gscl45nm.db]
set synthetic_library [list dw_foundation.sldb]
set link_library [concat * $target_library $synthetic_library]

define_design_lib WORK -path $work_dir
set_svf [file join $report_dir ${top_name}.svf]

set_app_var hdlin_auto_save_templates true
set_app_var hdlin_enable_rtldrc_info true
set_app_var hdlin_shorten_long_module_name true
set_app_var hdlin_module_name_limit 256
set_app_var verilogout_no_tri true
set_app_var verilogout_show_unconnected_pins true

set filelist_path [file join $script_dir filelist.f]
set filelist_fp [open $filelist_path r]
set rtl_files {}
while {[gets $filelist_fp file_line] >= 0} {
  set file_line [string trim $file_line]
  if {$file_line eq "" || [string index $file_line 0] eq "#"} {
    continue
  }
  lappend rtl_files [file normalize [file join $script_dir $file_line]]
}
close $filelist_fp

echo "NPU RTL files: [llength $rtl_files]"
if {![analyze -format sverilog $rtl_files]} {
  echo "ERROR: SystemVerilog analysis failed"
  exit 2
}
if {![elaborate $top_name]} {
  echo "ERROR: top-level elaboration failed"
  exit 2
}
current_design $top_name

set sram_designs [get_designs -quiet npu_l1_sram_bank_blackbox*]
if {[sizeof_collection $sram_designs] > 0} {
  if {[catch {
    set_black_box $sram_designs
  } black_box_error]} {
    echo "WARNING: set_black_box is unavailable: $black_box_error"
  }
  set_dont_touch $sram_designs
}

uniquify -force
if {![link]} {
  echo "ERROR: design link failed"
  exit 2
}

set sram_cells [get_cells -quiet -hierarchical \
  -filter "ref_name =~ npu_l1_sram_bank_blackbox*"]
if {[sizeof_collection $sram_cells] > 0} {
  set_dont_touch $sram_cells
}

if {[catch {
  source [file join $script_dir npu_single_core_400mhz.sdc]
} constraint_error]} {
  echo "ERROR: constraint setup failed: $constraint_error"
  exit 3
}
set_operating_conditions typical -library gscl45nm

set_fix_multiple_port_nets -all -buffer_constants
set_max_area 0

redirect [file join $report_dir ${top_name}_check_design_precompile.rpt] {
  check_design
}
redirect [file join $report_dir ${top_name}_check_timing_precompile.rpt] {
  check_timing
}

if {[catch {
  compile_ultra -no_autoungroup -no_boundary_optimization
} compile_error]} {
  echo "ERROR: compile_ultra failed: $compile_error"
  exit 4
}
change_names -rules verilog -hierarchy

redirect [file join $report_dir ${top_name}_check_design.rpt] {
  check_design
}
redirect [file join $report_dir ${top_name}_check_timing.rpt] {
  check_timing
}
redirect [file join $report_dir ${top_name}_timing_max.rpt] {
  report_timing -delay_type max -path full -nets -input -trans -cap \
    -nworst 5 -max_paths 20 -significant_digits 4
}
redirect [file join $report_dir ${top_name}_timing_min.rpt] {
  report_timing -delay_type min -path full -nets -input -trans -cap \
    -nworst 5 -max_paths 20 -significant_digits 4
}
redirect [file join $report_dir ${top_name}_qor.rpt] {
  report_qor
}
redirect [file join $report_dir ${top_name}_area.rpt] {
  report_area
  report_area -hierarchy
}
redirect [file join $report_dir ${top_name}_reference.rpt] {
  report_reference -hierarchy
}
redirect [file join $report_dir ${top_name}_constraints.rpt] {
  report_constraints -all_violators -verbose
}

write -format ddc -hierarchy \
  -output [file join $report_dir ${top_name}_syn.ddc]
write -format verilog -hierarchy \
  -output [file join $report_dir ${top_name}_syn.v]
write_sdc [file join $report_dir ${top_name}_syn.sdc]

set worst_paths [get_timing_paths -delay_type max -max_paths 1]
set summary_fp [open [file join $report_dir summary.txt] w]
puts $summary_fp "top=$top_name"
puts $summary_fp "target_period_ns=2.500"
puts $summary_fp "setup_uncertainty_ns=0.150"
puts $summary_fp "io_delay_ns=0.250"
puts $summary_fp "l1_organization=16x8192x64"
puts $summary_fp "l1_storage_bits=8388608"
puts $summary_fp "l1_macro_area_and_timing=in_external_db_not_in_this_run"
if {[sizeof_collection $worst_paths] > 0} {
  set worst_path [index_collection $worst_paths 0]
  puts $summary_fp "worst_setup_slack_ns=[get_attribute $worst_path slack]"
  puts $summary_fp \
    "worst_setup_startpoint=[get_object_name [get_attribute $worst_path startpoint]]"
  puts $summary_fp \
    "worst_setup_endpoint=[get_object_name [get_attribute $worst_path endpoint]]"
}
close $summary_fp

echo "NPU synthesis reports: $report_dir"
exit
