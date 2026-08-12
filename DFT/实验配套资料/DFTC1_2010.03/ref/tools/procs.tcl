# Synopsys Customer Education Services
# Physical Compiler 1 Workshop
#
# Tcl procedures to simplify life...

puts "\#\#\# Processing procs.tcl..."

proc puts_proc_info {name} {
    puts "Defining custom procedure \"$name\""
}


puts_proc_info "GUI - starts or ends GUI"
proc GUI {} {
        uplevel {
                if {$in_gui_session == false} {
                        gui_start
                } else {
                        gui_stop
                }
        }
}


puts_proc_info "ASYNC_DOMAIN"
proc ASYNC_DOMAIN {args} {
	parse_proc_arguments -args $args procargs
	set clk1 $procargs(clock1)
	set clk2 $procargs(clock2)
    set_false_path -from [get_clocks $clk1] -to [get_clocks $clk2]
    set_false_path -from [get_clocks $clk2] -to [get_clocks $clk1]
}
define_proc_attributes ASYNC_DOMAIN \
	-info "set false paths between 2 clocks in both directions" \
	-define_args {
		{clock1 "First clock name" clock1}
		{clock2 "Second clock name" clock2}
	}

# Generates statistics on the current session:
#   hostname
#   uname -a
#   date
#   location of current exec
puts_proc_info "HOST_STATS"
proc HOST_STATS {} {
	uplevel {
	puts "##### Session information:"
	puts "hostname:  [exec hostname]"
	puts "uname -a:  [exec uname -a]"
	puts "date:      [date]"
	puts "bin path:  $bin_path"
	puts "##### End session information\n"
	}
}


# Generates timing, constraint and qor reports in the "reports/" directory
# under the current dir.
puts_proc_info "GEN_REPORTS <args> (see help!)"
proc GEN_REPORTS {args} {
	
	# Defaults:
	set procargs(-verbose) false
	set procargs(-dir) "./reports"

	parse_proc_arguments -args $args procargs
	set verbose $procargs(-verbose)
	set prefix $procargs(-prefix)
	set dir $procargs(-dir)

	file mkdir $dir
	update_timing
	if ($verbose) { puts "##### Writing $dir/$prefix.constraint" }
	redirect $dir/$prefix.constraint {report_constraint -nosplit -all} 
	if ($verbose) { puts "##### Writing $dir/$prefix.timing" }
	redirect $dir/$prefix.timing {report_timing -nosplit}
	if ($verbose) { puts "##### Writing $dir/$prefix.min.timing" }
	redirect $dir/$prefix.min.timing {report_timing -delay min -nosplit}
	if ($verbose) { puts "##### Writing $dir/$prefix.qor" }
	redirect $dir/$prefix.qor {report_qor}
}

define_proc_attributes GEN_REPORTS \
	-info "Generates min/max timing, constraint and qor reports" \
	-dont_abbrev \
	-define_args {
		{-prefix "Prefix for report files" "<name>" string required}
		{-verbose "Be verbose!" "" boolean optional}
		{-dir "Destination directory. Default: ./reports" "lib_list" string optional}
	}

puts_proc_info "RESET_TIMER <timer_name>"
proc RESET_TIMER {timer_name} {
    global $timer_name
    redirect /dev/null {set $timer_name [clock seconds]}
}

puts_proc_info "REPORT_TIMER <timer_name> <message>"
proc REPORT_TIMER {timer_name message} {
    upvar $timer_name time

    set mins [expr ([clock seconds] - $time) / 60]
    set secs [expr ([clock seconds] - $time) % 60]
    echo [format "####----#### Runtime: %3d:%02d minutes for \"$message\"" $mins $secs]
}

puts_proc_info "MEASURE_TIME <command> <option> <option> ..."
proc MEASURE_TIME {args} {
    set time [clock seconds]
	set command [join $args]
    echo "##### Started timer for command \"$command\""
    uplevel $args
    set mins [expr ([clock seconds] - $time) / 60]
    set secs [expr ([clock seconds] - $time) % 60]
    echo [format "####----#### Runtime: %3d:%02d minutes for command \"$command\"" $mins $secs]
}
