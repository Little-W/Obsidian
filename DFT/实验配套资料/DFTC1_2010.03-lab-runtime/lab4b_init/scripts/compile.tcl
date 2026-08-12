#
# Read RTL
#

# Read the design
set hdlin_enable_presto_for_vhdl true
set acs_hdl_source {../ref/rtl/ORCA_init/vhdl}
acs_read_hdl -f vhdl ORCA

# DC will add generic info to the name of the design!! UGLY... fix:
rename_design [get_designs SDRAM_RFIFO*] SDRAM_RFIFO
rename_design [get_designs SDRAM_WFIFO*] SDRAM_WFIFO
rename_design [get_designs PCI_RFIFO*] PCI_RFIFO
rename_design [get_designs PCI_WFIFO*] PCI_WFIFO
rename_design [get_designs SDRAM_IF*] SDRAM_IF
rename_design [get_designs PCI_CORE*] PCI_CORE
rename_design [get_designs ORCA_TOP*] ORCA_TOP

current_design ORCA
link
#write -f ddc -hier -o unmapped/ORCA.ddc

#
# Setup for compile
#

suppress_message {UID-401 TIM-111 TIM-103 OPT-1006 DDB-74 DDB-72}

source -echo -verbose scripts/constraints.tcl;# apply non test constraints to the design

# Make all reset signals ideal
set_ideal_network -no_propagate [get_nets I_ORCA_TOP/pci_rst_n]
set_ideal_network -no_propagate [get_nets I_ORCA_TOP/sdram_rst_n]
set_ideal_network -no_propagate [get_nets I_ORCA_TOP/sys_rst_n]
set_ideal_network -no_propagate [get_nets I_ORCA_TOP/sys_2x_rst_n]

set_dont_touch [get_cells *_iopad*]
set_dont_touch [get_cells I_CLK_SOURCE*]
set_ideal_network [get_pins I_CLK_SOURCE*/Z]

#set_dont_touch [get_cells I_RST_SOURCE*]

group_path -name INS -from [all_inputs]
group_path -name OUTS -to [all_outputs]

# Freeze all SDRAM DDR output muxes
set_dont_touch [get_cells I_ORCA_TOP/I_SDRAM_IF/sd_mux*]
# I WANT only the mux on the SDRAM outputs!!
# Note: STA will not see the port cap!!
set_ideal_network [get_pins I_ORCA_TOP/I_SDRAM_IF/sd_mux*/Z]

# Prevent DC from writing out assign or tran statements in final verilog netlist.
set_fix_multiple_port_nets -all -buffer_constants [get_designs *]
set_auto_disable_drc_nets -all

# Using compile instead of compile_ultra to avoid unexpected optimizations on the init_regs
compile -scan
#compile_ultra -scan

# Simplify design hierarchy:
ungroup -all -simple -start_level 3

# In bottom-up HSS flow, something below causes problems at top-level insertion

set_critical_range 2.0 [current_design]
set_fix_multiple_port_nets -all -buffer_constants [get_designs *]

compile -scan -incremental
#compile_ultra -scan -incremental

#remove_unconnected_ports -blast [get_cells -h *]

change_names -rules verilog -hierarchy

write -format ddc -hier -o mapped/ORCA.ddc

#report_constraint -all > reports/constraint.rpt
#report_timing > reports/timing.rpt

exit