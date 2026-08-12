#
# This file contains Tcl procedures that can be very useful in DC/PT/PC
#

proc puts_proc_info {name} {
    puts "Defining custom procedure \"$name\""
}

puts_proc_info rename_test_designs
proc rename_test_designs {top_design} {
    set orig [current_design]
    current_design $top_design
    link

    foreach_in_collection cell [get_cells -filter "is_hierarchical == true"] {
	set ref_name [get_attribute $cell ref_name]
	echo "Processing $ref_name"
	if [regexp {(.+)_test_1} $ref_name foo orig_design_name] {

	    #echo "Will rename '$ref_name' into '$orig_design_name'"
	    #Rename!!
	    rename_design $ref_name $orig_design_name
	    change_link [get_object_name $cell] $orig_design_name
	}
    }

    current_design $orig
    link
}

puts_proc_info async_domain
proc async_domain {clk1 clk2} {
    set_false_path -from [get_clocks $clk1] -to [get_clocks $clk2]
    set_false_path -from [get_clocks $clk2] -to [get_clocks $clk1]
}

puts_proc_info echo_col
proc echo_col {col} {
    set i 1
    foreach_in_collection elem $col {
	echo "$i.\t[get_attribute $elem full_name]"
	incr i
    }
}

puts_proc_info flatten_block
proc flatten_block {block} {
    set c [current_design]
    current_design $block
    ungroup -flatten -simple -all
    current_design $c
}

puts_proc_info zero_io_nets
proc zero_io_nets {} {
    foreach_in_collection port [get_ports *] {
	set net [get_nets -of_object $port]
	set_resistance 0 $net
	set_load 0 $net
    }
}

# 
#
# Description: This Primetime prints the fastest and slowest endpoints on a clock 
#              tree (under max conditions). It also can print the same under
#              min condition timing.
#
# Usage: pt_shell> source report_clock_endpoint_skew.proc
#        pt_shell> report_clock_endpoint_skew -all -v  > clock_skew.rpt
#
# version:  $Id: procs.tcl,v 1.1 2002/06/19 02:08:11 cvs Exp $
# change history:
# 5/21/98 tobrien added -from $targetClock on get_timing_path command
#          this is to eliminate ambuguity for registers with multiple
#          clock sources on the transitive fanin of the clock pin.
#
# 8/10/98 updated for 1998.04 and did quick check
#
# 8/25/98 major overhaul. faster. removed option to dump to a file. no transistion info reported.
#         added verbose reporting
#
# 8/26/98 changed algorithm to find fastest and slowest paths.
#         assumes rising edge clocked devices
#         Now with endpoint dumping

puts_proc_info report_clock_endpoint_skew
proc report_clock_endpoint_skew { args } {
    #   redirect /dev/null { set rcs_string {$Id: procs.tcl,v 1.1 2002/06/19 02:08:11 cvs Exp $} }
    #   set version [lindex $rcs_string 2]
    #   echo "Info: Procedure version $version"



    set results(-clock) NULL
    set results(-verbose) false

    parse_proc_arguments -args $args results

    set targetClock $results(-clock)
    set verbose $results(-verbose)

    if { $targetClock!="ALL" } {
	redirect /dev/null {set clockList [get_clocks $targetClock] }
	redirect /dev/null {add_to_collection clockList [get_generated_clocks $targetClock] }
    } else {
	redirect /dev/null { set clockList [all_clocks] }
	redirect /dev/null { add_to_collection clockList [get_generated_clock *] }
    }
    foreach_in_collection currentClock $clockList {
	set ClockName [get_attribute $currentClock full_name]
	echo "Info: Reporting clock skew to all sequentials clocked by $ClockName"
	# setup
	set printEndPoints true
	set FastestAtMax 1000
	set SlowestAtMax -1000
	set FastestAtMin 1000
	set SlowestAtMin -1000
	set regCount 0
	set SlowestEndpoint "-NA-"
	set FastestEndpoint "-NA-"

	#set tmpRegisterPins [all_registers -clock $ClockName -clock_pins]
	set allRegisterPins [all_registers -clock $ClockName -clock_pins]
	#   set allRegisterPins [remove_from_collection $tmpRegisterPins [all_registers -clock $ClockName -async]]
	if "[sizeof_collection $allRegisterPins] < 1" {
	    echo "Skip this clock since it has no registers attached.\n\n"
	} else {
	    set regCount [sizeof_collection $allRegisterPins]
	    echo "Info: There are $regCount registers on clock $ClockName."

	    echo "Info:   looking for the slowest clock path to these registers..."
	    set SlowPath [get_timing_path -from $ClockName -to $allRegisterPins -delay_type max_rise]
	    set SlowestAtMax [get_attribute $SlowPath arrival]
	    set tmpEndpoint [get_attribute $SlowPath endpoint]
	    set SlowestEndpoint [get_attribute $tmpEndpoint full_name]
	    echo "Info:   $SlowestAtMax (max delay to $SlowestEndpoint)."

	    set tmpPath [get_timing_path -from $ClockName -to $SlowestEndpoint -delay_type min_rise]
	    set SlowestAtMin [get_attribute $tmpPath arrival]
	    echo "Info:   $SlowestAtMin (min delay to $SlowestEndpoint)."


	    echo "Info:   looking for the fastest clock path to these registers..."
	    #
	    #
	    # This gets a bit tricky. Look for the min endpoint using delay_type "min" and
	    # then find the worst case delay to that same point using delay_type "max". This
	    # is assumed to be the fastest worst case delay on the tree.

	    set MinPath [get_timing_path -from $ClockName -to $allRegisterPins -delay_type min_rise]
	    set tmpEndpoint [get_attribute $MinPath endpoint]
	    set FastestAtMin [get_attribute $MinPath arrival]
	    set FastestEndpoint [get_attribute $tmpEndpoint full_name]
	    echo "Info:   $FastestAtMin  (min delay to $FastestEndpoint)."
	    set FastPath [get_timing_path -from $ClockName -to $FastestEndpoint -delay_type max_rise]
	    set FastestAtMax [get_attribute $FastPath arrival]
	    echo "Info:   $FastestAtMax  (max delay to $FastestEndpoint)."

	    echo [format  "\n"]
	    echo [format  "   Endpoint rising edge skew report for %s" $ClockName]
	    echo [format  "   -------------------------------------------------"]
	    echo [format  "   %s     endpoints :   %-6d" $ClockName $regCount]
	    echo [format  "   %s    skew @ max :   %-4.3f" $ClockName [expr $SlowestAtMax - $FastestAtMax]]
	    echo [format  "   %s slowest @ max :   %-4.3f   (%s)" $ClockName $SlowestAtMax $SlowestEndpoint]
	    echo [format  "   %s fastest @ max :   %-4.3f   (%s)" $ClockName $FastestAtMax $FastestEndpoint]
	    echo [format  "\n"]
	    echo [format  "   %s    skew @ min :   %-4.3f" $ClockName [expr $SlowestAtMin - $FastestAtMin]]
	    echo [format  "   %s slowest @ min :   %-4.3f   (%s)" $ClockName $SlowestAtMin $SlowestEndpoint]
	    echo [format  "   %s fastest @ min :   %-4.3f   (%s)" $ClockName $FastestAtMin $FastestEndpoint]
	    echo [format  "\n"]
	    echo [format  "\n"]

	    echo "Detailed path report for $ClockName tree..."
	    echo "    To rising edge at $SlowestEndpoint"
	    echo "    -----------------------------------------------------------------"
	    foreach_in_collection current_point [get_attribute $SlowPath points] {
		echo [format "     arrival at point %-50s : %-4.3f"  [get_attribute [get_attribute $current_point object] full_name]  [get_attribute $current_point arrival]] 
	    }
	    echo " "
	    echo "    To rising edge at $FastestEndpoint"
	    echo "    -----------------------------------------------------------------"
	    foreach_in_collection current_point [get_attribute $FastPath points] {
		echo [format "     arrival at point %-50s : %-4.3f"  [get_attribute [get_attribute $current_point object] full_name]  [get_attribute $current_point arrival]] 
	    }
	    echo " "
	    echo " "
	} 

	if { $verbose==1 } {
	    report_timing -path end -max 40000 -from $ClockName -to $allRegisterPins -nosplit
	} else {
            echo "     (use -v as the last argument to get a more verbose report)"

	}
    }
}


define_proc_attributes report_clock_endpoint_skew -info "Analyze the Tpd to various clock endpoints"  -define_args  {
	{-verbose "see detailed endpoint data" "" boolean optional}
	{-clock "name of the clock to analyze (value ALL will analyze all clocks)" "clock_name" string required }
    }

