if {$argc != 2} {
  puts "ERROR: usage: report_hierarchy_timing.tcl <checkpoint> <output_dir>"
  exit 2
}

set checkpoint [file normalize [lindex $argv 0]]
set output_dir [file normalize [lindex $argv 1]]
file mkdir $output_dir
open_checkpoint $checkpoint

set groups {
  scheduler u_task_scheduler/*
  axi_slave u_axi_slave_frontend/*
  command_frontend u_cmd_frontend/*
  dma u_dma_engine/*
  matrix u_matrix_engine/*
  vector u_vector_engine/*
  complex u_complex_engine/*
  l1 u_l1buf/*
}

foreach {group_name cell_pattern} $groups {
  set start_cells [get_cells -quiet -hierarchical \
    -filter "NAME =~ $cell_pattern && IS_SEQUENTIAL"]
  if {[llength $start_cells] == 0} {
    puts "WARNING: no sequential cells for $group_name"
    continue
  }
  report_timing -delay_type max -path_type full \
    -from $start_cells -max_paths 20 -nworst 1 \
    -input_pins -routable_nets \
    -file [file join $output_dir timing_${group_name}.rpt]
}

exit
