`ifndef GUARD_I2C_VIP_REG_MODEL_SV
`define GUARD_I2C_VIP_REG_MODEL_SV

`uvm_analysis_imp_decl(_i2c_vip_reg_slave)

class i2c_vip_reg_model extends uvm_component;
  `uvm_component_utils(i2c_vip_reg_model)

  uvm_analysis_imp_i2c_vip_reg_slave #(svt_i2c_slave_transaction, i2c_vip_reg_model) slave_obs_export;

  static byte unsigned reg_mem[256];
  static bit           reg_valid[256];
  static byte unsigned read_ptr;
  static bit           write_seen;

  function new(string name = "i2c_vip_reg_model", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  virtual function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    slave_obs_export = new("slave_obs_export", this);
    reset_model();
  endfunction

  virtual function void write_i2c_vip_reg_slave(svt_i2c_slave_transaction tr);
    if (tr == null) begin
      return;
    end

    `uvm_info("I2C_VIP_REG_OBS",
              $sformatf("cmd=0x%0h addr=0x%0h data_size=%0d stop=%0d rep_start=%0d",
                        tr.cmd, tr.addr, tr.data.size(),
                        tr.stop_detected, tr.rep_start_detected),
              UVM_MEDIUM)

    if (tr.cmd == I2C_WRITE) begin
      update_from_write(tr);
    end
  endfunction

  static function void reset_model();
    foreach (reg_mem[i]) begin
      reg_mem[i] = 8'h00;
      reg_valid[i] = 1'b0;
    end
    read_ptr = 8'h00;
    write_seen = 1'b0;
  endfunction

  static function void update_from_write(svt_i2c_slave_transaction tr);
    byte unsigned reg_addr;

    if ((tr == null) || (tr.data.size() == 0)) begin
      return;
    end

    reg_addr = tr.data[0];
    read_ptr = reg_addr;
    write_seen = 1'b1;

    if (tr.data.size() == 1) begin
      uvm_root::get().uvm_report_info("I2C_VIP_REG_PTR",
                                      $sformatf("set read_ptr=0x%02h by address-only write", read_ptr),
                                      UVM_LOW, `__FILE__, `__LINE__);
      return;
    end

    for (int i = 1; i < tr.data.size(); i++) begin
      byte unsigned wr_addr;

      wr_addr = byte'(reg_addr + i - 1);
      reg_mem[wr_addr] = tr.data[i];
      reg_valid[wr_addr] = 1'b1;
      if (!$test$plusargs("I2C_VIP_REG_QUIET")) begin
        uvm_root::get().uvm_report_info("I2C_VIP_REG_WRITE",
                                        $sformatf("reg[0x%02h] <= 0x%02h", wr_addr, tr.data[i]),
                                        UVM_LOW, `__FILE__, `__LINE__);
      end
    end
  endfunction

  static function byte unsigned read_next();
    byte unsigned data;

    data = reg_valid[read_ptr] ? reg_mem[read_ptr] : 8'h00;
    if (!$test$plusargs("I2C_VIP_REG_QUIET")) begin
      uvm_root::get().uvm_report_info("I2C_VIP_REG_READ",
                                      $sformatf("reg[0x%02h] => 0x%02h valid=%0d", read_ptr, data, reg_valid[read_ptr]),
                                      UVM_LOW, `__FILE__, `__LINE__);
    end
    read_ptr++;
    return data;
  endfunction

endclass

`endif
