# FIFO UVM Testbench

## Directory

- `rtl/sync_fifo.sv`: synchronous FIFO DUT for verification bring-up.
- `tb/fifo_if.sv`: FIFO virtual interface.
- `env/agent`: item, sequencer, driver, monitor and agent.
- `env/fifo_scoreboard.sv`: reference queue scoreboard.
- `env/fifo_coverage.sv`: basic operation, level and flag coverage.
- `seq_lib/fifo_seq`: directed, random and boundary sequences.
- `vcs_com`: filelists and VCS option template matching the i2c_tb style.

## Tests

- smoke: `+UVM_TESTNAME=fifo_smoke_test +SEQ=fifo_basic_seq`
- random: `+UVM_TESTNAME=fifo_smoke_test +SEQ=fifo_random_seq +ITEM_NUM=200`
- boundary: `+UVM_TESTNAME=fifo_smoke_test +SEQ=fifo_boundary_seq`
