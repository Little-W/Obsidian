
`ifndef GUARD_AXI_UNALIGNED_WRITE_READ_SEQUENCE_SV
`define GUARD_AXI_UNALIGNED_WRITE_READ_SEQUENCE_SV

class axi_unaligned_write_read_sequence extends axi_master_wr_rd_sequence;

  svt_axi_slave_agent slave_agt;
  /** Parameter that controls the number of transactions that will be generated */
  rand int unsigned sequence_length = 10;
  bit [`SVT_AXI_MAX_ADDR_WIDTH-1:0] temp_addr,addr;

  /** Constrain the sequence length to a reasonable value */
  constraint reasonable_sequence_length {
    sequence_length <= 10;
  }

  /** UVM Object Utility macro */
  `uvm_object_utils(axi_unaligned_write_read_sequence)

  /** Class Constructor */
  function new(string name="axi_unaligned_write_read_sequence");
    super.new(name);
  endfunction
        
  virtual task body();
    bit status;
    bit[7:0] data;

    `uvm_info("body", "Entered ...", UVM_LOW)

    status = uvm_config_db #(int unsigned)::get(null, get_full_name(), "sequence_length", sequence_length);
    `uvm_info("body", $sformatf("sequence_length is %0d as a result of %0s.", sequence_length, status ? "config DB" : "randomization"), UVM_LOW);

    fork
    forever begin
      get_response(rsp);
    end
    join_none
    
    repeat (sequence_length) begin
      `ifndef SVT_UVM_1800_2_2017_OR_HIGHER
        `uvm_do_with(req, 
        { 
          addr == 'h2823d79222bac025;
          xact_type == svt_axi_transaction::WRITE;
          burst_type == svt_axi_transaction::INCR;
          burst_size == svt_axi_transaction::BURST_SIZE_256BIT;
          burst_length == 8;
        })
      `else
        `uvm_do(req,,, 
        { 
          addr == 'h2823d79222bac025;
          xact_type == svt_axi_transaction::WRITE;
          burst_type == svt_axi_transaction::INCR;
          burst_size == svt_axi_transaction::BURST_SIZE_256BIT;
          burst_length == 8;
        })
      `endif
      wait (`SVT_AXI_XACT_STATUS_ENDED(req))
      `ifndef SVT_UVM_1800_2_2017_OR_HIGHER
        `uvm_do_with(req, 
        {
          addr == 'h2823d79222bac025;
          xact_type == svt_axi_transaction::READ;
          burst_type == svt_axi_transaction::INCR;
          burst_size == svt_axi_transaction::BURST_SIZE_256BIT;
          burst_length == 8;
         })
      `else
        `uvm_do(req,,, 
        {
          addr == 'h2823d79222bac025;
          xact_type == svt_axi_transaction::READ;
          burst_type == svt_axi_transaction::INCR;
          burst_size == svt_axi_transaction::BURST_SIZE_256BIT;
          burst_length == 8;
         })
      `endif
    end
    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: axi_unaligned_write_read_sequence
`endif//GUARD_AXI_UNALIGNED_WRITE_READ_SEQUENCE_SV
