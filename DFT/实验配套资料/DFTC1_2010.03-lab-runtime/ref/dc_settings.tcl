# This file needs to be sourced from within the .synopsys_dc.setup file
# 
puts "\nExecuting common setup file 'ref/dc_settings.tcl' ..."


# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Other setup
#   - This could go into the .synopsys_dc.setup file in your home 
#     directory, so it is available no matter where the tool is launched
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Uncomment to disable tracking and reporting of when new variables are created
# set sh_new_variable_message false
# Enable command-line editing in dc_shell-t/psyn_shell
set sh_enable_line_editing true
# emacs is the default line-editing mode. The other mode is vi
set sh_line_editing_mode emacs
# Disable more-like page mode
set enable_page_mode false

# Custom Procedure
# Get command results/reports in separate graphical tk window
# This expects view.tk to be in the path, which is the other half
# of this procedure!
# Examples: view man compile,  view report_timing -max_paths 20
#======================================================  
proc view {args} {
    redirect tmpfile1212 {uplevel $args}
    # Without redirect, exec echos the PID of the new process to the screen
    redirect /dev/null {exec ../ref/tools/view.tk tmpfile1212 "$args" &}
}

# Some aliases to make use of view nicer
alias v view
alias vman "view man"
alias rt "report_timing -nosplit"
alias rtm "report_timing -nosplit -delay min"
alias rc "report_constraint -all_violators"
alias rq "report_qor"

# Increase history buffer
history keep 200
alias h history

# The following lines create a cmd and log file in the logs directory
set timestamp [pid].[clock format [clock scan now] -format "%Y-%m-%d_%H-%M"]
set sh_output_log_file "./logs/${synopsys_program_name}.log.$timestamp"
set sh_command_log_file "./logs/${synopsys_program_name}.cmd.$timestamp"
