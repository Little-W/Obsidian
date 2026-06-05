
`ifndef GUARD_I2C_SLV_DIRECTED_SEQUENCE_UVM_SV
`define GUARD_I2C_SLV_DIRECTED_SEQUENCE_UVM_SV

/** This slave directed sequence shows, the way user can control the subset of
 *  the svt_i2c_slave_transaction transaction class members are assigned
 *  values here.
 *  It shows the creation of transaction, assigning the fields directly.
 *  For full set of transaction class members and their complete description
 *  refer "I2C Verification IP UVM Class Reference Manual".
 */

class i2c_slv_directed_sequence extends uvm_sequence #(svt_i2c_slave_transaction); 

  svt_i2c_slave_transaction  tx_xacts_s;
  rand int unsigned sequence_length = 8;

  /** I2C configuration handle */ 
  svt_i2c_configuration i2c_cfg;

  /** UVM object utility macro */
  `uvm_object_utils(i2c_slv_directed_sequence)

  /** This macro is used to declare a variable p_sequencer whose type is svt_i2c_master_transaction_sequencer */
  `uvm_declare_p_sequencer(svt_i2c_slave_transaction_sequencer)

  /** Class constructor */
  function new (string name = "i2c_directed_sequence");
    super.new(name);
  endfunction : new

  /** Raise an objection if this is the parent sequence */
  virtual task pre_body();
    uvm_phase phase;
    super.pre_body();
`ifdef SVT_UVM_12_OR_HIGHER
    phase = get_starting_phase();
`else
    phase = starting_phase;
`endif
    if (phase!=null) begin
      phase.raise_objection(this);
    end
  endtask: pre_body
  
  /** Drop an objection if this is the parent sequence */
  virtual task post_body();
    uvm_phase phase;
    super.post_body();
`ifdef SVT_UVM_12_OR_HIGHER
    phase = get_starting_phase();
`else
    phase = starting_phase;
`endif
    if (phase!=null) begin
      phase.drop_objection(this);
    end
  endtask: post_body
  
  /** Define task body() */
  virtual task body();
    /** SVT configuration handle */ 
    svt_configuration cfg;
    bit status;
    `uvm_info("body", "Entering...", UVM_DEBUG)

    /** Get the SVT configuration */
    p_sequencer.get_cfg(cfg);
    
    /** Cast the SVT configuration handle on the local I2C configuration handle */
    if (!$cast(i2c_cfg, cfg)) begin
      `uvm_fatal("body", "Unable to cast the configuration to a svt_i2c_configuration class")
    end

    status = uvm_config_db#(int unsigned)::get(null, get_full_name(), "sequence_length", sequence_length);
    `uvm_info("I2C_SLV_RSP",
              $sformatf("sequence_length=%0d from %s", sequence_length, status ? "config_db" : "default"),
              UVM_LOW)

    for (int rsp_idx = 0; rsp_idx < sequence_length; rsp_idx++) begin
      `uvm_create(tx_xacts_s)
        tx_xacts_s.nack_addr = 0;
        tx_xacts_s.nack_addr_count = 0;
        tx_xacts_s.nack_data = 0;
        tx_xacts_s.clk_stretch_time_after_byte = 0;
        tx_xacts_s.clk_stretch_time_addr_byte = 0;
        tx_xacts_s.clk_stretch_time_data_byte = 0;
        tx_xacts_s.enable_random_clk_stretch_time_after_byte = 0;
        tx_xacts_s.enable_random_clk_stretch_time_addr_byte = 0;
        tx_xacts_s.enable_random_clk_stretch_time_data_byte = 0;
        tx_xacts_s.data = new[16];
        if ((rsp_idx > 0) && $test$plusargs("I2C_VIP_WAIT_FIRST_WRITE") &&
            !i2c_vip_reg_model::write_seen) begin
          `uvm_info("I2C_SLV_RSP", "waiting for first DUT write before supplying read data", UVM_LOW)
          wait (i2c_vip_reg_model::write_seen);
        end
        foreach (tx_xacts_s.data[i]) begin
          tx_xacts_s.data[i] = (rsp_idx == 0) ? 8'h00 : i2c_vip_reg_model::read_next();
        end
        `uvm_info("I2C_SLV_RSP",
                  $sformatf("response[%0d]: nack_addr=%0d nack_addr_count=%0d nack_data=%0d data_size=%0d data0=0x%02h data1=0x%02h data2=0x%02h",
                            rsp_idx, tx_xacts_s.nack_addr, tx_xacts_s.nack_addr_count,
                            tx_xacts_s.nack_data, tx_xacts_s.data.size(), tx_xacts_s.data[0],
                            tx_xacts_s.data[1], tx_xacts_s.data[2]),
                  UVM_LOW)
      `uvm_send(tx_xacts_s)

      /** 
       * Call get_response only if configuration attribute,
       * enable_put_response is set 1.
       */
      if(i2c_cfg.enable_put_response == 1)
        get_response(rsp);
    end

    `uvm_info("body", "Exiting...", UVM_DEBUG)
  endtask : body

endclass : i2c_slv_directed_sequence 

`endif // GUARD_I2C_DIRECTED_SEQUENCE_UVM_SV
