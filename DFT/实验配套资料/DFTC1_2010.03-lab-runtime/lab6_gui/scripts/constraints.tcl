# Create user defined variables
set CLK_PORT [get_ports Clk]
set CLK_PERIOD 10.0
set WC_SKEW 0.25
set DRV_CELL bufbd1
set DRV_PIN "Z"
set OUTPUT_LOAD [load_of cb13fs120_tsmc_max/bufbd1/I]
set INPUT_DELAY 1.0
set OUTPUT_DELAY 1.0
set ALL_INS_EX_CLK  [remove_from_collection [all_inputs] [get_ports Clk]]



create_clock -period $CLK_PERIOD -name my_clk $CLK_PORT

set_clock_uncertainty $WC_SKEW [get_clocks my_clk]

set_driving_cell -lib_cell $DRV_CELL -pin $DRV_PIN $ALL_INS_EX_CLK

set_load $OUTPUT_LOAD [all_outputs]

set_input_delay $INPUT_DELAY -max -clock my_clk $ALL_INS_EX_CLK

set_output_delay $OUTPUT_DELAY -max -clock my_clk [all_outputs]
