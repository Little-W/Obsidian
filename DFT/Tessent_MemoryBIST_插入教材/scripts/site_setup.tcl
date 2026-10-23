# Copy to site_local.tcl and fill real project inputs. No foundry IP is included.
set TOP mbist_lab
set DESIGN_LEVEL physical_block
set TESSENT_CELL_LIBS {}
set RTL_FILES {}
set MEMORY_TCD_FILES {}
set SIM_VERILOG_FILES {}
set CLOCKS {{CLK 10ns clka}}
set FLOORPLAN_DEF ""
set POWER_UPF ""
set SITE_EXTRA_SETUP ""
set SITE_SIM_SETUP ""

# plan | insert | patterns | simulate
set RUN_STAGE plan
# preserve | builtin_default | builtin_extra | uda_default | uda_extra | soft
set ALGO_MODE preserve
set ALGORITHM LabMarchCMinus
set OPERATION_SET SyncWR
set CONTROLLERS {c1}
set SOFT_INSTRUCTIONS 16

# Empty = automatic planning. Full exported DftSpecification = exact-plan import.
set MANUAL_DFT_SPEC ""
set GROUPING_TAGS ""
set PHYSICAL_CLUSTER_RATIO ""

# Read names from the generated pattern specification, not from this example.
set PATTERN_MBIST_SCOPES {
    Patterns(MemoryBist_P1)/TestStep(run_time_prog)/MemoryBist
}
set PATTERN_CONTROLLER_TARGETS {}
# Example only; replace with the real generated instance path:
# set PATTERN_CONTROLLER_TARGETS {
#   Patterns(MemoryBist_P1)/TestStep(run_time_prog)/MemoryBist/Controller(mbist_lab_rtl_tessent_mbist_c1_controller_inst)
# }
set FULL_ADDRESS_TEST 1
