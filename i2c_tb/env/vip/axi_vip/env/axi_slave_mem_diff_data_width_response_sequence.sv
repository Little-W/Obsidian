
/**
 * Abstract:
 * axi_slave_mem_diff_data_width_response_sequence extended from axi_slave_mem_response_sequence
   is used by test to provide information to the Slave agent present in the System Env.
 * This class defines a sequence in which a write is followed by read using the
   write_byte API and read_byte_API respectively.
 * 
 * Execution phase: main_phase
 * Sequencer: Slave agent sequencer
 */

`ifndef GUARD_AXI_SLAVE_MEM_DIFF_DATA_WIDTH_RESPONSE_SEQUENCE_SV
`define GUARD_AXI_SLAVE_MEM_DIFF_DATA_WIDTH_RESPONSE_SEQUENCE_SV

class axi_slave_mem_diff_data_width_response_sequence extends axi_slave_mem_response_sequence;

  svt_axi_slave_agent slave_agt;

  bit[`SVT_AXI_MAX_ADDR_WIDTH-1:0] addr_l;
  bit[7:0] data;

  /** UVM Object Utility macro */
  `uvm_object_utils(axi_slave_mem_diff_data_width_response_sequence)

  /** Class Constructor */
  function new(string name="axi_slave_mem_diff_data_width_response_sequence");
    super.new(name);
  endfunction

  virtual task body();

    `uvm_info("body", "Entered ...", UVM_LOW)

    $cast(slave_agt, p_sequencer.get_parent()); 
    
    //write using write_byte API. 
    for(int i=0;i<32;i++) begin
      addr_l=92000000+i; 
      data = i + 8;
      slave_agt.write_byte(addr_l, data); 
      `svt_xvm_debug("body", $sformatf("Writing to address %0h data is %0h using write_byte_API",addr_l,data));
    end

    //read using read_byte API. 
    for(int i=0;i<32;i++) begin
      addr_l=92000000+i; 
      slave_agt.read_byte(addr_l, data); 
      `svt_xvm_debug("body", $sformatf("Reading from address %0h data is %0h using read_byte_API",addr_l,data));
    end

    super.body(); 

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: axi_slave_mem_diff_data_width_response_sequence

`endif // GUARD_AXI_SLAVE_MEM_DIFF_DATA_WIDTH_RESPONSE_SEQUENCE_SV
