

/**
 * Abstract:
 * class axi_slave_random_response_sequence defines a sequence class that the
 * testbench uses to provide slave response to the Slave agent present in the
 * System agent. The sequence receives a response object of type
 * svt_axi_slave_transaction, from slave sequencer. The sequence class then
 * randomizes the response with constraints and provides it to the slave driver
 * within the slave agent.
 */
`ifndef GUARD_AXI_SLAVE_RANDOM_RESPONSE_SEQUENCE_SV
`define GUARD_AXI_SLAVE_RANDOM_RESPONSE_SEQUENCE_SV

class axi_slave_random_response_sequence extends svt_axi_slave_base_sequence;

  svt_axi_slave_transaction resp_req;

  /** UVM Object Utility macro */
  `uvm_object_utils(axi_slave_random_response_sequence)

  /** Class Constructor */
  function new(string name="axi_slave_random_response_sequence");
    super.new(name);
  endfunction

  virtual task body();
    `uvm_info("body", "Entered ...", UVM_LOW)

    // consumes responses sent by driver
    sink_responses();

    forever begin
      p_sequencer.response_request_port.peek(resp_req);

      $cast(req,resp_req);

      /** 
       * Demonstration of response randomization with constraints.
       */
      `ifndef SVT_UVM_1800_2_2017_OR_HIGHER
        `uvm_rand_send_with(req,
         {
           foreach(rresp[i]) {
             rresp[i] inside { svt_axi_transaction::SLVERR, svt_axi_transaction::OKAY };
           }
           bresp inside { svt_axi_transaction::SLVERR,svt_axi_transaction::OKAY };
         })
      `else
        `uvm_rand_send(req,,
        {
          foreach(rresp[i]) {
            rresp[i] inside { svt_axi_transaction::SLVERR, svt_axi_transaction::OKAY };
          }
          bresp inside { svt_axi_transaction::SLVERR,svt_axi_transaction::OKAY };
        })
      `endif
    end

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: axi_slave_random_response_sequence

`endif // GUARD_AXI_SLAVE_RANDOM_RESPONSE_SEQUENCE_SV
