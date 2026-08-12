# Revision 1.00 on 7/2004 
#       Published onto Solvit
#
# Revision 1.01 on 7/13/2004 by gboyer
#       correction with mkdir TMAX_CACHE
#
# Revision 1.02 on 7/21/2004 by gboyer
#       Corrected problem where script did not recognize some scan states
#       Added to -force option to allow processing of mapped verilog netlists
#       Added error catching for writing test protocol
#       Creates a tmax log file
#       Added error catching for writing verilog netlist
#
# Revision 1.03 on 8/04/2004 by gboyer
#       added support for test_dft_drc_ungate_clocks
#       Corrected type with $CACHE_TMA
#
# Revision 1.04 on 8/25/2004 by gboyer
#       moved the set bist command to inside the -lbist if statement
#       added -use_constant for lbist rules
#
# Revision 2.00 on 10/26/2004 by gboyer
#       Changed -force option to -ignore_errors
#       merged scripts for auto library generation
#       Changed shortcut from ddi to drci
#       Corrected some errors with the CACHE_TMAX variable 
#       Added -make_tmax_libs for automatic generation of lib files
#       Added support for set_test_assume
#       Added -hints section
#       Added -infer for existing scan chains.  Note: this is needed because
#	      2004.12 DFTC does not put the load_unload procedure in the spf file.
#
# Revision 2.01 on 01/06/2005 by gboyer
#       Added set pindata -shift_c S
#       Added set drc -store_setup -store_stability_patterns 
#       Changed script to use new licensing
#	Minor bug fixes
#
# Revision 2.02 on 01/06/2005 by gboyer
#       Minor bug fixes
#       sets verilogout_no_tri to false to resolve a DC issue
#
# Revision 2.03 on 02/14/2005 by gboyer
#       -ignore_errors issues warnings (instead of errors) when checking $test_simulation_library.
#
# Revision 2.04 on 03/21/2005 by gboyer
#       Checks version of DC before using -dft option
#       Fixed problem with report_test -state in XG
#
# Revision 3.00 on 04/11/2005 by gboyer
#       Automatic library generation without a special license
#
# Revision 3.01 on 04/26/2005 by gboyer
#       Automatic library generation without a special license
#       Changed script to use new licensing
#       Removes DFTC license IF it checked on out.
#
# Revision 3.03 on 05/04/2005 by gboyer
#       Fixed bug with auto lib generation for clock gate cells
#       Minor bug fixes
#
# Revision 3.08 on 06/07/2005 by gboyer
#       Minor bug fixes
#
# Revision 3.09 on 06/16/2005 by gboyer
#       changed echo statements to puts to fix bug
#
# Revision 3.10 on 06/17/2005 by gboyer
#       Disabled license checking with icc_shell 
#          because it is packaged with tool
#
# Revision 3.12 on 06/28/2005 by gboyer
#       Added support for running TMAX in TCL mode
#       changed puts -n to echo -n
#
# Revision 3.13 on 06/30/2005 by gboyer
#       Added support for set_test_assume in XG mode
#
# Revision 3.17 on 07/14/2005 by gboyer
#       made synopsys_program_name global
#       set_test_assume converion on by default (db and xg mode)
#       Fixed error with -no_set_test_assume
#       TMAX GUI now runs in background by default 
#           -background switch has no affect
#
# Revision 3.19 on 08/8/2005 by gboyer
#       Minor bug fixes
#
# Revision 3.20 on 08/19/2005 by gboyer
#       Fixed bug where drci would abort with no error message
#
# Revision 3.22 on 09/21/2005 by gboyer
#       Automatic library generation on by default
#	Verified script for 2005.09
#	Handles unwriteable tmax_cache directory
#	Fixed bug where script would abort for no reason
#	TMAX will now issue a B5 warning for most .lib black box cells
set REV "3.23"
# Revision 3.23 on 01/13/2006 by gboyer
#       Changed find commands to get_


set save_sh_new_variable_message $sh_new_variable_message
set sh_new_variable_message false
echo ""
echo "Loading TCL procedure"
echo "Creating alias drci for the lazy typist of the world."
echo ""
echo "Whats new for version $REV:"
echo "     - On-the-fly TMAX library generation is on by DEFAULT"
echo "     - Script verified for 2005.09"
echo "     - Corrected minor bugs."
echo ""
echo "Important recent updates:"
echo "     - Added -use_dftc_license which forces TMAX session to use a DFTC license"
echo "     - Support for set_test_assume is on by default for both DB and XG modes"
echo "     - Added support for running TMAX in TCL mode with -tcltmax option"
echo "     - Added existing scan chain extraction with -infer (DB-mode only)"
echo "     - Added -hints for debugging tips"
echo ""
alias drci dft_drc_interactive



proc dft_drc_interactive { args } {
    parse_proc_arguments -args $args results

    global synopsys_program_name 
    global sh_new_variable_message
    set save_sh_new_variable_message $sh_new_variable_message
    set sh_new_variable_message false
    global test_simulation_library
    global test_dft_drc_ungate_clocks
    global test_use_test_models
    global target_library
    global link_library
    global REV
    global CACHE_TMAX
    global verilogout_no_tri
    set DEBUG false
    set REGRESSION false
    
    # List current limitations
    if { [info exists results(-hints)] } {
        echo ""
        echo "Hints for resolving problems with dft_drc_interactive"
        echo "    - Always run change_names -rule verilog -h before running script"
        echo "    - For the warning about \$SYNOPSYS and \$SYNOPSYS_TMAX"
        echo "      try installing TMAX as an overlay to DC.  Then set"
        echo "      the variables equal to each other"
        echo "    - For undefined display variable try either:"
        echo "         a) Set display variable from inside DC:"
        echo "               dc_shell-t> setenv DISPLAY mydisp:0"
        echo "         b) Try running tmax from UNIX promp:"
        echo "               dc_shell-t> drci -back"
        echo "               UNIX> setenv DISPLAY mydisp:0"
        echo "               UNIX> tmax tmax_cache/tmax_script.cmd"
        echo "    - Unable to spawn TetraMAX session"
        echo "         Workaround is to use drci -back and then spawn TMAX from unix"
        echo "            UNIX> tmax tmax_cache/tmax_script.cmd"
        echo ""
        echo "         Degugging tips:"
        echo "         Make sure TetraMAX can run from unix prompt:"
        echo "               UNIX> tmax "
        echo "         Consider installing TetraMAX as an overlay in \$SYNOPSYS"
        echo "               UNIX> ls \$SYNOPSYS/bin/tmax"
        echo "         Make sure \$SYNOPSYS_TMAX is pointing to the path to tmax"
        echo "               dc_shell-t> getenv \$SYNOPSYS_TMAX"
        echo "               dc_shell-t> sh which tmax"
        echo "         Make sure TetraMAX can be spawned from DC"
        echo "               dc_shell-t> exec tmax"
        echo "               dc_shell-t> exec tmax &"
        echo ""
        return
    }

    # List current limitations
    if { [info exists results(-limitations)] } {
        echo ""
        echo "Limitations with revision $REV and DFT Compiler 2005.09:"
        echo "    - drci -make_tmax_libs must be used or "
        echo "        \$test_simulation_library must be set to all required libraries"
        echo "    - Does not parse \$search_path when resolving \$test_simulation_library."
        echo "    - No support for RTL.  Script will abort for unmapped netlists."
        echo "    - Sometimes the TMAX gui will not come up. See -hints option for workarounds."
        echo "    - HSS test models are not supported.  A pure HSS test model only has a"
        echo "      black box for the gates.  This black box would get passed to tmax.  "
        echo "      To resolve this either:"
        echo "        a) set test_use_test_models false ; # disabling HSS"
        echo "        b) give TMAX access to the gates using the -build_file option"
        echo "    - The -infer option mimics the behavior of dft_drc -infer."
        echo "      It will not recognize clocks/resets created with create_test_protocol -infer "
        echo "      It does not support initialization protocols (test_setup)."
        echo "    - set_scan_element false causes dft_drc to mask violations on the "
        echo "      selected cells and is not supported with dft_drc_interactive."
        echo ""
        return
    }

    
    #########################################
    # Begin initial setup checks
    #########################################

    # Check for use of obsolete switches
    if { [info exists results(-background)] } {
        error "The -background switch is no longer used.  Remove option."
    } elseif { [info exists results(-make_tmax_libs)] && $REGRESSION == false } {
        error "The -make_tmax_libs switch is on by default.  Use -nomake_tmax_libs to disable."
    }

    # Make a temporary directory within the user's run directory
    set CACHE_TMAX ./tmax_cache
    if [file exists $CACHE_TMAX] {
        echo "     Removing exisitng temporary cache directory: $CACHE_TMAX"
        redirect /dev/null {catch { sh /bin/rm -rf $CACHE_TMAX }}
        # check to see if it was really removed
        if [file exists $CACHE_TMAX] {
            echo "Warning: Could not delete $CACHE_TMAX.  Creating new directory."
            set CACHE_TMAX [format "%s_%s" $CACHE_TMAX [pid] ]
            echo "     Making temporary cache directory: $CACHE_TMAX"
            file mkdir $CACHE_TMAX
        } else {
            file mkdir $CACHE_TMAX
        }
    } else {
        echo "     Making temporary cache directory: $CACHE_TMAX"
        file mkdir $CACHE_TMAX
    }
    redirect $CACHE_TMAX/working_dir_for_dft_drc_interactive.tcl [echo "Working dir for dft_drc_interactive.tcl" ]

    # Check out a DFTC license and remember if we did
    redirect -variable status {list_licenses}
    if { [regexp "Test-Compiler" $status] == 1 || $synopsys_program_name == "icc_shell" } { 
        set remove_dftc_license_when_done false
    } elseif { [get_license "Test-Compiler" ] == 1 } { 
        set remove_dftc_license_when_done true
    } else {
        error "Unable to check out DFT Compiler license (Test-Compiler)"
    }

    # Check to see that design is mapped to gates
    if { ![get_attribute [current_design] is_mapped] &&
         ![info exists results(-ignore_errors)] } { 
        error "dft_drc_interactive currently only supports mapped designs.\n       Use dft_drc for RTL analysis or use -ignore_errors to override this message."

    }
    
    set enable_make_tmax_libs false 
    if { [info exists results(-nomake_tmax_libs)] } {
            set enable_make_tmax_libs false 
    } else {
        if { [info procs make_tmax_libs] == "make_tmax_libs" } { 
            set enable_make_tmax_libs true 
        } else {
            error "-make_tmax_libs not enabled for this site.  Check with your AC for make_tmax_libs procedure file"
        }
    }
    #echo status of $enable_make_tmax_libs

    if { [shell_is_in_xg_mode] && [info exists results(-infer_scan_structures)] } {
        echo ""
        error "-infer_scan_structures not needed in XG mode.  Exiting..." 
    }

    # Check to see that $test_simulation_library is set 
    if { [llength $test_simulation_library] == 0 &&
         ![info exists results(-ignore_errors)] && 
         !$enable_make_tmax_libs } { 
    	error "No simulation libraries specified.  Either use drci -make_tmax_libs or set the \$test_simulation_library variable to the paths to all required TetraMAX libraries."
    }

    #
    # Check for existance of all user supplied files
    #
    
    # Check for access to -build_file
    if { [info exists results(-build_file)] && ![file readable $results(-build_file)] } {
        echo ""
        error "No read access to -build_file file $results(-build_file)"
    }

    # Check for access to -drc_file
    if { [info exists results(-drc_file)] && ![file readable $results(-drc_file)] } {
        echo ""
        error "No read access to -drc_file file $results(-drc_file)"
    }

    # Convert set_test_assumes to add net connect
    # Make sure the pins exist
    if { ![info exists results(-no_set_test_assume)] } { 
        echo ""
        set assert false
        set set_test_assumes {}
            if { [shell_is_in_xg_mode] } {
                help report_test_assume > $CACHE_TMAX/asm_[pid]
                catch {sh cat $CACHE_TMAX/asm_[pid]} status
                file delete -force $CACHE_TMAX/asm_[pid]
                if { [regexp "No commands matched" $status] == 1 } { 
                    echo "drci and set_test_assume not supported with this version of DC/PC."
                    error "Either disable with drci -no_set_test_assume or try 2004.12-SP3 or later."
                } else {
                    redirect $CACHE_TMAX/drci_[pid] { report_test_assume }
                    set report_file [open $CACHE_TMAX/drci_[pid] r] 
                    while {[gets $report_file line] >= 0} {
                        if { [regexp {^\s*(\S+)\s+([01])} $line match cell_pin value] } { 
                            echo "    Checking set_test_assume pin: $cell_pin";
                            if { [get_object_name [get_pins $cell_pin]] != "" } { 
                                #echo "add net connect TIE$value $cell_pin -disconnect"
                                lappend set_test_assumes "add_net_connect TIE$value $cell_pin -disconnect"
                            }
                        }
                    }
                    close $report_file
                    file delete -force $CACHE_TMAX/drci_[pid]
                }
            } else {
                redirect $CACHE_TMAX/drci_[pid] {report_test -assert -nosplit}
                set report_file [open $CACHE_TMAX/drci_[pid] r] 
                while {[gets $report_file line] >= 0} {
                    [regexp {^Design\s+:\s+(\S+)} $line match design_name]
                    if { [regexp {Assertions:} $line] } { set assert true }
                    if { [regexp {^\s+(\S+):} $line match instance] } {
                        if { $instance == $design_name } { 
                            set instance "" 
                        } else {
                            set instance $instance/
                        }
                    }
                    if { $assert && [regexp {^\s+(\S+) pin assumed to be (\d+)} $line match cell_pin value] } { 
                        echo "    Checking set_test_assume pin: $instance$cell_pin";
                        if { [get_object_name [get_pins $instance$cell_pin]] != "" } { 
                            #echo "add net connect TIE$value $instance$cell_pin -disconnect"
                            lappend set_test_assumes "add_net_connect TIE$value $instance$cell_pin -disconnect"
                        }
                    }
                }
                close $report_file
                file delete -force $CACHE_TMAX/drci_[pid]
            }
    }

    # Check for access to -netlist_location
    if { [info exists results(-netlist_location)] && ![file readable $results(-netlist_location)] } {
        echo ""
        error "No read access to -netlist_location file $results(-netlist_location)"
    }

    # Check for read access on all items in $test_simulation_library
    foreach i $test_simulation_library {
        echo ""
        echo "     Checking \$test_simulation_library path $i"
        if { [info exists results(-ignore_errors)] } { 
          if { [catch {ls $i} errmsg] } { 
    	    echo "Warning: Unable to access file $i"
          } 
        } else {
          if { ![file readable [ lindex [ls $i] 0 ] ]} {
    	    # The ls command was able to expand $i
    	    error "No read access to file $i"
          } 
        }
    }

    # Make sure $SYNOPSYS_TMAX is set to path to tmax (bstar 9000049223 )
    # redirect -variable path_to_tmax {sh which tmax} sometimes caused drci to abort
    if { ![catch {sh which tmax} path_to_tmax ] } {
        regsub ".bin.tmax" [lrange $path_to_tmax 0 0] "" real_SYNOPSYS_TMAX 
        setenv SYNOPSYS_TMAX $real_SYNOPSYS_TMAX
    }

    #########################################
    # End Initial seteup checks
    #########################################
    
    echo ""
    echo "     Creating alias drci for the lazy typist of the world."
    echo ""
    alias drci dft_drc_interactive

    echo ""
    # Determine scan state for DRC rule checking
    if { [shell_is_in_xg_mode] } {
        redirect -variable status {report_scan_state };
    } else {
        redirect -variable status {report_test -state };
    }
    if { [info exists results(-pre_dft)] } {
        set pre_dft true
        echo "     Configuring for pre dft rule checking"
    } elseif { [regexp {existing scan circuitry} $status] ||
         [regexp {scan cells replaced and scan signals routed} $status] || 
         [info exists results(-post_dft)] } {
        echo "     Configuring for post dft rule checking"
        set pre_dft false
    } else {
        set pre_dft true
        echo "     Configuring for pre dft rule checking"
    }
    
    if { $pre_dft && [info exists results(-infer_scan_structures)] &&
         ![info exists results(-ignore_errors)] } { 
        echo ""
        error "Cannot infer scan structures for pre dft rule checking.  Exiting..." 
    } 

    echo ""
    echo "     Saving design and protocol information"
    echo ""
    
    set design_name [get_object_name [current_design]]
    
    if { ![info exists results(-infer_scan_structures)] } {
        if { ![write_test_protocol -output $CACHE_TMAX/interactive.stil] } {
            error "Unable to write test protocol.  Exiting..." 
        }
    }

    # Make tmax libraries on the fly if enabled
    if { $enable_make_tmax_libs }  {
        set tlibname [format "%s/libs_for_%s.vg" $CACHE_TMAX $design_name]
        make_tmax_libs -file $tlibname
    } 


    # Write out netlist
    if { ! [info exists results(-netlist_location)] } {
	# this is set to resolve a DC issue
	set save_verilogout_no_tri $verilogout_no_tri
	set verilogout_no_tri false
        if { ![write -format verilog -hier -output $CACHE_TMAX/$design_name.vg] } {
	    set verilogout_no_tri $save_verilogout_no_tri
            error "Unable to write verilog netlist.  Exiting..." 
        }
	set verilogout_no_tri $save_verilogout_no_tri
    }

    # Creating the Tmax run script file
    set filename [open $CACHE_TMAX/tmax_script.cmd w+] 
    
    puts $filename "set_messages -log $CACHE_TMAX/log -replace"
    puts $filename "set_commands noabort"
    puts $filename "read_netlist -delete"
    puts $filename "set_netlist -redefined_module first "
    puts $filename "set_rule N5 ignore"
    
    echo " "
    # Add $test_simulation_library to command file
    foreach i $test_simulation_library {
    	puts $filename "read_netlist $i"
    }
    
    # Add on-the-fly libraries to the command file
    if { $enable_make_tmax_libs }  {
        puts $filename "read_netlist $tlibname"
    } 

    # Add netlist read to command file
    if { [info exists results(-netlist_location)] } {
        set netlist_location $results(-netlist_location)
        puts $filename "read_netlist $results(-netlist_location)"
    } else {
        puts $filename "read_netlist $CACHE_TMAX/$design_name.vg"
    }

    puts $filename "set_rule b5 warn"
    puts $filename "set_rule b12 warn"
    puts $filename "set_rule b24 warn"
    puts $filename "set_rule b25 warn"
    puts $filename "set_rule b26 warn"
    puts $filename "set_rule n10 warn"
    puts $filename "set_rule n14 warn"
    puts $filename "set_rule n17 warn"
    puts $filename "set_rule n25 warn"
    puts $filename "set_rule n29 warn"
    puts $filename "set_rule v2 warn"
    puts $filename "set_rule v3 warn"
    puts $filename "set_rule v17 warn"
    puts $filename "set_rule v20 warn"
    puts $filename "set_rule v21 warn"
    puts $filename "set_rule v22 warn"
    puts $filename "set_rule c1 warn"
    puts $filename "set_rule c4 warn"
    puts $filename "set_rule c7 warn"
    puts $filename "set_rule c10 warn"
    puts $filename "set_rule c18 warn"
    puts $filename "set_rule c23 warn"
    puts $filename "set_rule c24 warn"
    puts $filename "set_rule s6 warn"
    puts $filename "set_rule s7 warn"
    puts $filename "set_rule s8 warn"
    puts $filename "set_rule s9 warn"
    puts $filename "set_rule s11 warn"
    puts $filename "set_rule s13 warn"
    puts $filename "set_rule s18 warn"
    puts $filename "set_rule s20 warn"
    puts $filename "set_rule s27 warn"
    puts $filename "set_rule s28 warn"
    puts $filename "set_rule z3 warn"
    puts $filename "set_rule z7 warn"
    puts $filename "set_rule z11 warn"
    puts $filename "set_rule z12 warn"
    #puts $filename "report_violations N"
    puts $filename "set_build -merge noequivalent_dlat_dff -merge flipflop_cell_from_dlat"
    puts $filename "set_build -merge notied_gates_with_pin_loss -merge nodlat_from_flipflop"

    # Support for test_dft_drc_ungate_clocks
    if { [info exists test_dft_drc_ungate_clocks ] } {
        if { $test_dft_drc_ungate_clocks } {
            puts $filename "set_build -ungate_clocks"
        }
    }
    
    puts $filename "set_build -nodelete_unused_gates"
    puts $filename "set_learning -max_feedback_sources 1000"

    # Insert the converted set_test_assumes into file
    if { ! [info exists results(-no_set_test_assume)] } {
        foreach i $set_test_assumes { puts $filename $i }
    }

    # Insert pre build script into file
    if { [info exists results(-build_file)] } {
        set build_file $results(-build_file)
        puts $filename "source $build_file"
    }
    puts $filename "run_build_model $design_name"
    #puts $filename "set_drc -report_constant_value_cell" ; #incompatible with tmax tcl
    puts $filename "set_drc -dlat_checking_type stable"
    puts $filename "set_drc -store_setup -store_stability_patterns"
    puts $filename "set_pindata -shift_c S"

    # Enable lbist rules
    if { [info exists results(-lbist_rules)] } {
         puts $filename "set_drc -type dft"
         puts $filename "set_bist -pi_assumed_scan -po_assumed_scan"
         puts $filename "set_bist -use_constant_value_cells"
    }



    set last1 ""
    if { [shell_is_in_xg_mode] } {
        redirect -variable status {report_dft_signal -view existing_dft};
        set signals {}
        foreach line $status { 
            if { [regexp {ScanEnable} $last1] } {
                # Make sure each signal is only added once
                if { [lsearch $signals $last2] == -1 } { 
                    puts $filename "add_scan_enable $line $last2"
                }
                lappend signals $last2
            }
            set last2 $last1
            set last1 $line
        }
    } else {
        redirect $CACHE_TMAX/drci_[pid] {report_test -port -assert -nosplit}
        set report_file [open $CACHE_TMAX/drci_[pid] r] 
        #test_si1          test_scan_in                          1                
        set si {}
        set so {}
        array unset a_si
        array unset a_so
        set num_clocks 0
        while {[gets $report_file line] >= 0} {
            if { [regexp {(\S+)\s+test_scan_enable_inverted} $line match port_name ] } {
                puts $filename "add_scan_enable 0 $port_name"
            } elseif { [regexp {(\S+)\s+test_scan_enable} $line match port_name ] } {
                puts $filename "add_scan_enable 1 $port_name"
            }
            if { [info exists results(-infer_scan_structures)] } {
                if { [regexp {(\S+)\s+test_scan_in\s+(\d+)} $line match port_name index] } {
                    lappend si $index $port_name
                } elseif { [regexp {(\S+)\s+test_scan_out\s+(\d+)} $line match port_name index] } {
                    lappend so $index $port_name
                } elseif { [regexp {(\S+)\s+([\.\d]+\s+([\.\d]+))\s+([\.\d]+)} $line match port_name rise fall period ] } {
                    incr num_clocks
                    if { $rise < $fall } {
                        puts $filename "add_clocks 0 $port_name -shift"
                    } else { 
                        puts $filename "add_clocks 1 $port_name -shift"
                    }
                } elseif { [regexp {(\S+)\s+port held to (\d)} $line match port_name value ] } {
                    puts $filename "add_pi_const $value $port_name"
                } elseif { [regexp {(\S+)\s+test_asynch_inverted} $line match port_name ] } {
                    puts $filename "add_clocks 1 $port_name"
                } elseif { [regexp {(\S+)\s+test_asynch} $line match port_name ] } {
                    puts $filename "add_clocks 0 $port_name"
                }
            }
        }
        close $report_file
        file delete -force $CACHE_TMAX/drci_[pid]
        if { $num_clocks == 0 && [info exists results(-infer_scan_structures)] &&
            ![info exists results(-ignore_errors)] } { 
            close $filename
            echo "Error: No clocks found with report_test -port."
            error "-infer_scan_structures requires explicit creation of clocks.  Exiting..."
        }

        if { [info exists results(-infer_scan_structures)] } {
            # Create an array of the SI ports and SO ports
            array set a_si $si
            array set a_so $so
            # Create a list of all port indexs for both $si and $so
            set indexes [lsort -uniq [concat [array names a_so] [array names a_si] ] ]
            # Print out only the SIs and SOs that have matching indexes
            foreach i $indexes {
                if { [info exists a_si($i)] && [info exists a_so($i)] } { 
                    puts $filename "add_scan_chain c$i $a_si($i) $a_so($i)"
                }
            }
        }



    }



    # Insert pre drc file into script
    if { [info exists results(-drc_file)] } {
        set drc_file $results(-drc_file)
        puts $filename "source $drc_file"
    }

    if { [regexp "2004.12" $path_to_tmax] == 1 || [regexp "2005" $path_to_tmax] == 1 || [regexp "2006" $path_to_tmax] == 1  } {
        set dashdft "-dft"
    } else {
        set dashdft ""
    }


    
    # Configure script for pre or post dft rule checks
    if { $pre_dft } {
        puts $filename "set_scan_ability on -all"
        puts $filename "set_drc $CACHE_TMAX/interactive.stil"
        puts $filename "alias dft_drc run_drc -prescan"
        puts $filename "run_drc -prescan"
        puts $filename "##"
        puts $filename "##Use dft_drc alias or run_drc -prescan to rerun DRC analysis"
    } else {
        # The -infer_scan_structures is required because 
             #a) DFTC DBmode does not put load_unload statements 
             #   into the spf even though set_signal_type was
             #   was used to delcare them.  
             #b) If TMAX get both a spf file and an add scan 
             #   chains it will ignore the add scan chains.  
             #   This behavior is consistent with TMAX docs.
        if { ![info exists results(-infer_scan_structures)] } {
            puts $filename "set_drc $CACHE_TMAX/interactive.stil"
        }
        puts $filename "alias dft_drc run_drc $dashdft"
        puts $filename "run_drc $dashdft"
        if { ![info exists results(-infer_scan_structures)] && ![shell_is_in_xg_mode] } {
            if { [info exists results(-tcltmax)] } {
                puts $filename "##############################################################################"
                puts $filename "## Warning: DRC rules set to Post-DFT.  If scan chains are not extracted in ##"
                puts $filename "##          TMAX, use dft_drc_interactive -infer_scan_structures            ##"
                puts $filename "##############################################################################"
            } else {
                puts $filename "//////////////////////////////////////////////////////////////////////////////"
                puts $filename "// Warning: DRC rules set to Post-DFT.  If scan chains are not extracted in //"
                puts $filename "//          TMAX, use dft_drc_interactive -infer_scan_structures            //"
                puts $filename "//////////////////////////////////////////////////////////////////////////////"
            }

        }
        if { [info exists results(-tcltmax)] } {
            puts $filename "##"
            puts $filename "##Use dft_drc alias or run drc to rerun DRC analysis"
        } else {
            puts $filename "//"
            puts $filename "//Use dft_drc alias or run drc to rerun DRC analysis"
        }
    } 
    if { $REGRESSION } {
        puts $filename "report_licenses"
        puts $filename "quit"
    }
    close $filename
    # End script generation

    # Check to for test_use_test_models
    if { $test_use_test_models } {
        echo "#############################################################################"
        echo " Warning: test_use_test_models is ENABLED.  dft_drc_interactive does not"
        echo "          natively support test models.   Results may differ from dft_drc "
        echo "          if the netlist contains black box gates with a test model attached."
        echo "          Only the black box is passed to tmax with dft_drc_interactive."
        echo "#############################################################################"
    }

    if { !$pre_dft && ![shell_is_in_xg_mode] && ![info exists results(-infer_scan_structures)] } {
        echo ""
        echo "#############################################################################"
        echo " Warning: DRC rules set to Post-DFT.  If scan chains are not extracted in "
        echo "          TMAX, use the -infer_scan_structurs option"
        echo "#############################################################################"
    }

    if { [info exists results(-use_dftc_license)] } {
        setenv TMAX_USE_DFT_LICENSE true
        echo ""
        echo "     Forcing TMAX to use DFT Compiler license for this entire DC/PC session"
    }

    # Invoke tmax interactively 
    echo ""
    echo "     Invoking TetraMAX"
    echo ""
    
    # Return license if drci explicity checked on out
    if { $remove_dftc_license_when_done } {
        remove_license Test-Compiler
    }

    set cmmd "exec tmax"
    if { [info exists results(-tcltmax)] } {
        set cmmd [concat $cmmd " -tcl " ]
    }
    if { $REGRESSION } {
        set cmmd [concat $cmmd " -shell " ]
    }
    set cmmd [concat $cmmd "$CACHE_TMAX/tmax_script.cmd" ]
    # TMAX GUI runs in background by default
    #if { [info exists results(-background)] } {
    #}
    set cmmd [concat $cmmd " &"]
    eval $cmmd

    # Since TMAX GUI runs in background, temp files can no longer be deleted
    # Delete files when complete
    #if { ![info exists results(-background)] } {
        #exec /bin/rm -rf $CACHE_TMAX
    #}
    unset CACHE_TMAX

    set sh_new_variable_message $save_sh_new_variable_message

    
}


define_proc_attributes dft_drc_interactive \
    -info "Spawns off an external TMAX session for DRC analysis (Rev $REV)." \
    -define_args {
        { -no_set_test_assume "Disables converting set_test_assumes to TMAX add net connects" "" boolean optional}
        { -background "Spawns TetraMAX GUI session into the background" "" boolean optional}
        { -build_file "This file will be sourced before running build" "<file_name>" string optional}
        { -drc_file "This file will be sourced before running drc" "<file_name>" string optional}
        { -hints "Lists hints for working around problems" "" boolean optional}
        { -ignore_errors "Ignores errors and attempts to proceed" "" boolean optional}
        { -infer_scan_structures "Mimicks dft_drc -infer.  See -limits for more detail" "" boolean optional}
        { -limitations "Lists current limitations and quits" "" boolean optional}
        { -lbist_rules "Enables checking of LBIST rules (Lxx)" "" boolean optional}
        { -make_tmax_libs "On by default (Generates TMAX libs on-the-fly)" "" boolean optional}
        { -netlist_location "Alternate netlist for DRC (disables netlist writing)" "<file_name>" string optional}
        { -nomake_tmax_libs "Disables generation of TMAX libs on-the-fly" "" boolean optional}
        { -post_dft "Runs pre-dft (post-scan) DRC rule checks" "" boolean optional}
        { -pre_dft "Runs pre-dft (pre-scan) DRC rule checks (DEFAULT)" "" boolean optional}
        { -tcltmax "Runs TetraMAX in TCL mode" "" boolean optional}
        { -use_dftc_license "Will force TMAX session to use a DFTC license" "" boolean optional}
    }


proc make_tmax_libs {args } {
parse_proc_arguments -args $args results

    global sh_new_variable_message
    set save_sh_new_variable_message $sh_new_variable_message
    set sh_new_variable_message false
    global current_design
    global test_enable_dft_drc
    set test_enable_dft_drc true
    set STATS false
    set DEBUG false
    set DEBUG2 false
    set DEBUG3 false
    set REGRESSION false
    set lastlina ""
    set macth ""
    set topdsn $current_design


    if { [info exists results(-file)] } {
        set LIBFILE $results(-file)
    }
    if { [file exists $LIBFILE] } { 
        echo "     Removing existing Library file: $LIBFILE"
    }
    file delete -force $LIBFILE
    catch {sh touch $LIBFILE } status
    set unsupportedxg { create test patterns rtl drc logs read init protocol tmax check dft save cache}
    if { ![file exists $LIBFILE] || ![file writable $LIBFILE] } {
        echo ""
        error "No write access to -file $results(-file)"
    }

    set OUTDIR ./mlib
    set start_time [cputime]
    echo ""
    echo "Beginning TMAX library generation."

    if {  [info exists results(-all)] } {
        echo "TMAX libraries will be saved in $LIBFILE"
    } 
    echo "This may take a few minutes."

    #echo "   ."

    set x1 [format %s_%s_%s [lrange $unsupportedxg 12 12 ] [lrange $unsupportedxg 9 9] [lrange $unsupportedxg 5 5 ] ]
    set x2 [format %s_%s_%s_%s [lrange $unsupportedxg 1 1 ] [lrange $unsupportedxg 11 11] [lrange $unsupportedxg 4 4 ] [lrange $unsupportedxg 13 13 ] ]
    set tdrc_force_scan_equivalence_checks false
    if [file exists $OUTDIR] { file delete -force $OUTDIR  }
    file mkdir $OUTDIR
    #if [file exists $OUTDIR] { catch { sh /bin/rm -rf $OUTDIR/* }  }
    if { $DEBUG } { echo ls of $OUTDIR }
    if { $DEBUG } { ls $OUTDIR }
    redirect -variable status {get_designs tmax_libs }
    if { [regexp "tmax_libs" $status ] } { redirect /dev/null { remove_design tmax_libs } }


    set logical_section false

    set alllibcells {}
    set allrptlibcells {}
    set index 0
    set lastline ""
    set black_box_cells {}
    redirect -variable list_libs { list_libs }
    set rptlib [format "%s/rptlib%s" $OUTDIR [pid]]
    file delete -force $rptlib
    foreach current_word $list_libs {
        if { [regexp -- "Logical" $current_word ] } { set logical_section true }
        if { [regexp -- "Physical" $current_word ] } { set logical_section false }
        # is this a real db file to check?
        if { [regexp -- "\.db$" $current_word ] && ! [regexp -- "sldb" $current_word ] && $logical_section && ! [regexp -- "gtech.db" $current_word ]} {

                # db name is current word and lib name is previous word
                set lib_name [lindex $list_libs [expr $index -1]]
                set db_name $current_word

                if { $DEBUG } { echo "Running report_lib on $db_name:$lib_name" }
                report_lib $db_name:$lib_name > $rptlib

                set cells_section 0 ; # flag for cells section at end of report_lib
                set total_cells 0 ; # total number of cells listed in $rptlib
                set black_boxes 0 ; # total number of black boxes listed in $rptlib

                set INFILE [open $rptlib ]
                while {[gets $INFILE line] >= 0} {

                    # the cells secion is after a -------- line and after Cell.*Attributes line
                    # must parse past both of these
                    if { [regexp -- {----------} $line] && [regexp -- {Cell.*Attributes} $lastline] } { 
                        set cells_section 1 ; 
                        if { $DEBUG2 } { echo "found cell section $lastline" }
                        if { $DEBUG2 } { echo "found cell section $line" }
                        set lastline $line
                        continue;

                    # This line is a regular cell
                    } elseif { [regexp {^\s+(\w+)[\s]} $lastline match cell] && $cells_section == 1 } { 
                        if { [lsearch $allrptlibcells $cell] == -1 } {
                            incr total_cells ; 
                            set libcell [format "%s:%s/%s"  $db_name  $lib_name  $cell]
                            lappend alllibcells $libcell
                            lappend allrptlibcells $cell
                            if { $DEBUG3 } { echo "Found cell $libcell" }
                        } else {
                            if { $DEBUG3 } { echo "Skipping duplicate $libcell" }
                        }

                             
                    }
                    set lastline $line
                }
                close $INFILE

        }
        incr index
    }
    file delete -force $rptlib
    

    global $x1 
    global $x2 
    set $x1 true
    set $x2 $OUTDIR
    if { $STATS } { echo Number of cells found in report_lib: [llength $allrptlibcells] }
    ###if { $STATS } { echo Number of black boxes: found [llength $black_box_cells] }
    ###if { $DEBUG2 } { echo Actual black boxes found $black_box_cells] }



    set cell_section 0
    set rpthiercells {}
    #set cell ""
    #set design ""
    
    if {  [info exists results(-all)] } {
        redirect $OUTDIR/drci_rpt_hier_[pid] {echo skipping }
    } else {
        redirect $OUTDIR/drci_rpt_hier_[pid] {report_hierarchy -nosplit}
    }
    set report_file [open $OUTDIR/drci_rpt_hier_[pid] r]
    while {[gets $report_file line] >= 0} {
        if { [regexp {Design : } $line] } {
            incr cell_section
        }
        if { [regexp {\*\*\*} $line] && $cell_section == 1 } {
            incr cell_section
            if { $DEBUG } { echo "Found cell section "; echo $line }
        }
        if { [regexp {^\s*(\S+)\s+\S+$} $line match cell] && $cell_section == 2 } { 
            if { [lsearch $rpthiercells $cell] == -1 } { 
                ###if { [lsearch $black_box_cells $cell] == -1 } { 
                    if { $DEBUG2 } { echo "Found cell: $cell" }
                    lappend rpthiercells $cell
                ###} else {
                ###    if { $DEBUG } { echo "Ignoring black box cell in report_hier: $cell" }
                ###}
 
            }
        }
                
    }
    close $report_file
    if { $STATS } { echo "Number of unique cells found in report_hier [llength $rpthiercells] "  }
    file delete -force $OUTDIR/drci_rpt_hier_[pid] 



    # Create template file
    set TEMPLATEFL $OUTDIR/template.v
    file delete -force $TEMPLATEFL
    set template [open $TEMPLATEFL w+] 

    puts $template "module tmax_libs ( inport, outport ); input inport; output outport; "

    set i 0
    if { [info exists results(-all)] } {
        set cell_list $allrptlibcells
    } else {
        set cell_list $rpthiercells
    }

    foreach cell $cell_list {

        # Special exception for lsi_10k/LSR2
        if { [regexp {LSR2} $cell] } { 
           if { $DEBUG } { echo found LSR2 $cell }
           continue 
        }

        set instance "Z$i"
        puts $template "  $cell Z$i (  );"
        incr i
    }
    puts $template "endmodule"
    close $template

    set lastlina [format %s_%s_%s [lrange $unsupportedxg 0 0 ] [lrange $unsupportedxg 1 1] [lrange $unsupportedxg 8 8 ] ]
    set macth [format %s_%s [lrange $unsupportedxg 11 11 ] [lrange $unsupportedxg 4 4] ]
    


    #End template generation

    # Dump out a status tic
    #echo -n "."


    redirect /dev/null {catch { read_verilog -netlist $TEMPLATEFL } status}
    redirect -variable status { current_design tmax_libs }
    redirect -variable status { link }
    if { [get_cells ] == {} } { 
        echo "Debug info:  Number of cells found in report_lib: [llength $allrptlibcells] "
        echo "Debug info:  Number of black boxes: found [llength $black_box_cells] "
        echo "Debug info:  Number of uniqe cells found in report_hier [llength $rpthiercells] " 
        error "No cells to translate.  Exiting"
    } 

    echo -n "   ."
    redirect -variable status { change_names -rules verilog -h }
    if { $DEBUG } { redirect -variable status { write -f verilog -h -out $OUTDIR/top.v } }


    # Dump out a status tic
    echo -n "."


    redirect -variable status1 $lastlina 

    # Dump out a status tic
    echo -n ","

    redirect -variable status2 $macth

    # Dump out a status tic
    echo -n "."


    set getls  [ls $OUTDIR/__tmax.v*]
    if { [llength $getls ] != 1} {
        ls $OUTDIR/__tmax.v*
        error "Incorrect number of libraries created during conversion.  Exiting..."
    }
    if { ! [file exists $getls] } { 
        echo  "Debug Info: No library file to parse"
        error "Internal error during lib generation.  Exiting..."
    } 

    set hasguts 0
    set modulebegin 0
    set black_box_list {}
    set infile [open $getls  r ]
    set outfile [open $LIBFILE w+] 
    while {[gets $infile line] >= 0} {
        if { [regexp {^\s*endmodule} $line match ] && $hasguts == 0 } { 
            if { $DEBUG } { echo "found black box $currentmod" }
            lappend black_box_list $currentmod
        }
        if { [regexp {^\s*endmodule} $line match ] } { 
            set hasguts 0
            set modulebegin 0
        }
        if { [regexp {^\s*module\s*([\w\d_]+)} $line match ] } { 
            set modulebegin 1
            set currentmod $match
            #echo "current module is $match"
        }
        if { [regexp {^\s*or} $line match ] || \
             [regexp {^\s*not} $line match ] || \
             [regexp {^\s*buf} $line match ] || \
             [regexp {^\s*xnor} $line match ] || \
             [regexp {^\s*xor} $line match ] || \
             [regexp {^\s*table} $line match ] || \
             [regexp {^\s*and} $line match ] } { 
            set hasguts 1
        }
    }
    close $infile
    close $outfile

    set infile [open $getls  r ]
    set outfile [open $LIBFILE w+] 
    set disable_printing 0
    while {[gets $infile line] >= 0} {
        if { [regexp -nocase {^\s*module\s+top} $line match ] } { 
            if { $DEBUG } { echo exiting file at: $line }
            break
        } elseif { [regexp {^\s*endmodule} $line match ] } { 
            if { $disable_printing == 0 } {
                puts $outfile $line
            }
            set disable_printing 0
        } elseif { [regexp {^\s*module\s+(\S+)} $line match modulename] } { 
            if { [lsearch $black_box_list $modulename] != -1 } {
                # return of -1 means search failed
                set disable_printing 1
            }
            if { $disable_printing == 0 } {
                puts $outfile $line
            }
        } elseif { $disable_printing == 0 } {
            puts $outfile $line
        } else {
        }
    }
    close $infile
    close $outfile
           
    echo "."
    if { $STATS } { echo Total cells converted: [sh grep -c endmodule $LIBFILE] }


    set delta_time  [expr [cputime] - $start_time]
    set delta_min [expr $delta_time /60.0]
    echo "It actually took " [format "%.1f" $delta_min] " minutes."

    if { [info exists results(-all)] } {
        echo ""
        echo "#################################################################################"
        echo "# Add the master library file to \$test_simulation_library                  "
        echo "#                                                                                "
        echo "# dc_shell> lappend test_simulation_library $LIBFILE                             "
        echo "#################################################################################"
    } elseif {  $delta_min >= 5 } { 
        echo "#################################################################################"
        echo "# To eliminate the possibility of long runtimes for library generation, consider " 
        echo "# generating a master library file with make_tmax_libs -all -file <libfile>      "
        echo "# Then add the master library file to \$test_simulation_library                  "
        echo "#                                                                                "
        echo "# dc_shell> lappend test_simulation_library <libfile>                            "
        echo "#################################################################################"
        echo ""
    } 

    if { ! ($DEBUG || $DEBUG2 || $DEBUG3 ) } {
        file delete -force $TEMPLATEFL
        redirect /dev/null { catch {sh /bin/rm -rf $OUTDIR  } }
        redirect -variable status { remove_design tmax_libs }
    }
    unset $x1
    unset $x2
    current_design $topdsn
    # ICC required link after current_design
    link
    #if { ! $REGRESSION } {
    #}

    set sh_new_variable_message $save_sh_new_variable_message

}


define_proc_attributes make_tmax_libs \
    -info "Creates libraries for TMAX." \
    -define_args {
        { -file "Name of TMAX library file" "<file_name>" string required}
        { -all "Converts all cells in \$link_library list" "" boolean optional}
}
 

redirect /dev/null {catch {set sh_new_variable_message $save_sh_new_variable_message} status}

