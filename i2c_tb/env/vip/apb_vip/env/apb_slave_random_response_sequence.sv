

/**
 * Abstract:
 * class apb_slave_random_response_sequence defines a sequence class that the
 * testbench uses to provide slave response to the Slave agent present in the
 * System agent. The sequence receives a response object of type
 * svt_apb_slave_transaction, from slave sequencer. The sequence class then
 * randomizes the response with constraints and provides it to the slave driver
 * within the slave agent.
 */
`ifndef CUST_APB_SLAVE_RANDOM_RESPONSE_SEQUENCE_SV
`define CUST_APB_SLAVE_RANDOM_RESPONSE_SEQUENCE_SV

class apb_slave_random_response_sequence extends svt_apb_slave_base_sequence;

  /** UVM Object Utility macro */
  `uvm_object_utils(apb_slave_random_response_sequence)

  /** Class Constructor */
  function new(string name="apb_slave_random_response_sequence");
    super.new(name);
  endfunction

  virtual task body();
    `uvm_info("body", "Entered ...", UVM_LOW)

    forever begin
      p_sequencer.response_request_port.peek(req);
      if (req.cfg == null) begin
        req.cfg = cfg;
      end

      /**
       * Demonstration of response randomization with constraints.
       */
      `ifndef SVT_UVM_1800_2_2017_OR_HIGHER
        `uvm_rand_send_with(req, { pslverr_enable == 1'b0; })
      `else
        `uvm_rand_send(req,, { pslverr_enable == 1'b0; })
      `endif
    end

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body

endclass: apb_slave_random_response_sequence

class apb_slave_mem_response_sequence extends svt_apb_slave_base_sequence ;

  /** UVM Object Utility macro */
    svt_apb_slave_transaction req_resp;
    svt_apb_memory apb_slave_mem;
    //int max_addr_apb  ;
  `uvm_object_utils(apb_slave_mem_response_sequence)

  /** Class Constructor */
  function new(string name="apb_slave_mem_response_sequence");
    super.new(name);
  endfunction
 virtual function void create_apb_slave_mem();
    svt_apb_slave_agent slave_agent;

    if ($cast(slave_agent, p_sequencer.get_parent())) begin
        if (slave_agent.apb_slave_mem != null) begin
        apb_slave_mem = slave_agent.apb_slave_mem;
      end
      else begin
        apb_slave_mem = new("apb_slave_mem"   ,                // Memory name
                            cfg.sys_cfg.pdata_width,           // Data width
                            0,                                 // Address region
                            0,                                 // Lower address bound
                            ((1<<(cfg.sys_cfg.paddr_width+cfg.sys_cfg.enable_extra_physical_mem_region*2))-1)); // Upper address bound
        slave_agent.apb_slave_mem = apb_slave_mem;
      end

    end
    else begin
      `uvm_fatal("create_apb_slave_mem", "This sequence must be run by the sequencer contained by svt_apb_slave_agent.");
    end
  endfunction: create_apb_slave_mem

  virtual task body();
    `uvm_info("body", "Entered ...", UVM_LOW)
      create_apb_slave_mem();

    forever begin
      p_sequencer.response_request_port.peek(req_resp);
      if (req_resp.cfg == null) begin
        req_resp.cfg = cfg;
      end

      /**
       * Demonstration of response randomization with constraints.
       */
        req_resp.data.rand_mode(0);
        req_resp.pslverr_enable.rand_mode(0);
        req_resp.num_wait_cycles=0;
        if(req_resp.xact_type == svt_apb_slave_transaction::WRITE)begin
            apb_slave_mem.write(req_resp.address,req_resp.data);
            //req_resp.data = 32'hffff;
        end
        else begin
            req_resp.data = apb_slave_mem.read(req_resp.address);
        end

        $cast(req,req_resp);

        if(req.address == 'h188) req.num_wait_cycles = $urandom_range(0, 50);
        `uvm_send(req);
    end

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body


endclass: apb_slave_mem_response_sequence



class apb_ba_ack_delay_sequence extends svt_apb_slave_base_sequence ;

  /** UVM Object Utility macro */
    svt_apb_slave_transaction req_resp;
    svt_apb_memory apb_slave_mem;
    //int max_addr_apb  ;
  `uvm_object_utils(apb_ba_ack_delay_sequence)

  /** Class Constructor */
  function new(string name="apb_ba_ack_delay_sequence");
    super.new(name);
  endfunction
 virtual function void create_apb_slave_mem();
    svt_apb_slave_agent slave_agent;

    if ($cast(slave_agent, p_sequencer.get_parent())) begin
        if (slave_agent.apb_slave_mem != null) begin
        apb_slave_mem = slave_agent.apb_slave_mem;
      end
      else begin
        apb_slave_mem = new("apb_slave_mem"   ,                // Memory name
                            cfg.sys_cfg.pdata_width,           // Data width
                            0,                                 // Address region
                            0,                                 // Lower address bound
                            ((1<<(cfg.sys_cfg.paddr_width+cfg.sys_cfg.enable_extra_physical_mem_region*2))-1)); // Upper address bound
        slave_agent.apb_slave_mem = apb_slave_mem;
      end

    end
    else begin
      `uvm_fatal("create_apb_slave_mem", "This sequence must be run by the sequencer contained by svt_apb_slave_agent.");
    end
  endfunction: create_apb_slave_mem

  virtual task body();
    `uvm_info("body", "Entered ...", UVM_LOW)
      create_apb_slave_mem();

    forever begin
      p_sequencer.response_request_port.peek(req_resp);
      if (req_resp.cfg == null) begin
        req_resp.cfg = cfg;
      end

      /**
       * Demonstration of response randomization with constraints.
       */
        req_resp.data.rand_mode(0);
        req_resp.pslverr_enable.rand_mode(0);
        req_resp.num_wait_cycles=0;
        if(req_resp.xact_type == svt_apb_slave_transaction::WRITE)begin
            apb_slave_mem.write(req_resp.address,req_resp.data);
            //req_resp.data = 32'hffff;
        end
        else begin
            req_resp.data = apb_slave_mem.read(req_resp.address);
        end

        $cast(req,req_resp);

        if(req.address[11:0] == 'h188) begin
            req.num_wait_cycles = $urandom_range(200, 250);
        end
        `uvm_send(req);
    end

    `uvm_info("body", "Exiting...", UVM_LOW)
  endtask: body


endclass: apb_ba_ack_delay_sequence





`endif // GUARD_APB_SLAVE_RANDOM_RESPONSE_SEQUENCE_SV
