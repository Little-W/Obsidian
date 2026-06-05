
`ifndef GUARD_AXI_SLAVE_MEM_ERROR_RESPONSE_SEQUENCE_SV
`define GUARD_AXI_SLAVE_MEM_ERROR_RESPONSE_SEQUENCE_SV

class axi_slave_mem_error_response_sequence extends svt_axi_slave_base_sequence;

  svt_axi_slave_transaction req_resp;

  /** UVM Object Utility macro */
  `uvm_object_utils(axi_slave_mem_error_response_sequence)

  /** Class Constructor */
  function new(string name="axi_slave_mem_error_response_sequence");
    super.new(name);
  endfunction

  virtual task body();
    integer status;
    svt_configuration get_cfg;

    `uvm_info("body", "Entered ...", UVM_LOW)

    p_sequencer.get_cfg(get_cfg);
    if (!$cast(cfg, get_cfg)) begin
      `uvm_fatal("body", "Unable to $cast the configuration to a svt_axi_port_configuration class");
    end

    // consumes responses sent by driver
    sink_responses();
    $display("123");

    forever begin
      /**
       * Get the response request from the slave sequencer. The response request is
       * provided to the slave sequencer by the slave port monitor, through
       * TLM port.
       */
      p_sequencer.response_request_port.peek(req_resp);
    $display("123");

      /**
       * Randomize the response and delays
       */
      status=req_resp.randomize with {
        bresp == svt_axi_slave_transaction::SLVERR;
        foreach (rresp[index])  {
          rresp[index] == svt_axi_slave_transaction::SLVERR;
          }
       };
       if(!status)
        `uvm_fatal("body","Unable to randomize a response")

      /**
       * If write transaction, write data into slave built-in memory, else get
       * data from slave built-in memory
       */
      if(req_resp.get_transmitted_channel() == svt_axi_slave_transaction::WRITE) begin
        `protect
        put_write_transaction_data_to_mem(req_resp);
        `endprotect
      end
      else if (req_resp.get_transmitted_channel() == svt_axi_slave_transaction::READ) begin
        `protect
        get_read_data_from_mem_to_transaction(req_resp);
        `endprotect
      end

      $cast(req,req_resp);

      /**
       * send to driver
       */
      `uvm_send(req)

    end

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: axi_slave_mem_error_response_sequence



class axi_slave_one_error_response_sequence extends svt_axi_slave_base_sequence;

  svt_axi_slave_transaction req_resp;

  /** UVM Object Utility macro */
  `uvm_object_utils(axi_slave_one_error_response_sequence)

  /** Class Constructor */
  function new(string name="axi_slave_one_error_response_sequence");
    super.new(name);
  endfunction

  virtual task body();
    integer status;
    logic err_flag = 0;
    svt_configuration get_cfg;

    `uvm_info("body", "Entered ...", UVM_LOW)

    p_sequencer.get_cfg(get_cfg);
    if (!$cast(cfg, get_cfg)) begin
      `uvm_fatal("body", "Unable to $cast the configuration to a svt_axi_port_configuration class");
    end

    // consumes responses sent by driver
    sink_responses();

    forever begin
      /**
       * Get the response request from the slave sequencer. The response request is
       * provided to the slave sequencer by the slave port monitor, through
       * TLM port.
       */
      p_sequencer.response_request_port.peek(req_resp);

      /**
       * Randomize the response and delays
       */
       if( (!err_flag)  &&  ($urandom_range(0,20) == 1) )begin
      status=req_resp.randomize with {
        bresp inside { svt_axi_slave_transaction::SLVERR,  svt_axi_slave_transaction::DECERR} ;
        foreach (rresp[index])  {
          rresp[index]  inside { svt_axi_slave_transaction::SLVERR,  svt_axi_slave_transaction::DECERR};
          }
       };
       err_flag = 1;
        end
       else begin
      status=req_resp.randomize with {
        bresp == svt_axi_slave_transaction::OKAY;
        foreach (rresp[index])  {
          rresp[index] == svt_axi_slave_transaction::OKAY;
          }
       };
       end
       if(!status)
        `uvm_fatal("body","Unable to randomize a response")

      /**
       * If write transaction, write data into slave built-in memory, else get
       * data from slave built-in memory
       */
      if(req_resp.get_transmitted_channel() == svt_axi_slave_transaction::WRITE) begin
        `protect
        put_write_transaction_data_to_mem(req_resp);
        `endprotect
      end
      else if (req_resp.get_transmitted_channel() == svt_axi_slave_transaction::READ) begin
        `protect
        get_read_data_from_mem_to_transaction(req_resp);
        `endprotect
      end

      $cast(req,req_resp);

      /**
       * send to driver
       */
      `uvm_send(req)

    end

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass




`endif // GUARD_AXI_SLAVE_MEM_RESPONSE_SEQUENCE_SV
