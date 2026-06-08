`ifndef I3C1_REG_TEST__SV
`define I3C1_REG_TEST__SV
class i3c1_reg_test extends i3c_base_test;
   `uvm_component_utils(i3c1_reg_test)
   rand bit[31:0] r_wdata;

   extern function new(string name = "i3c1_reg_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

   extern virtual task default_val_chk(RegTypeDef_t reg_struct[], bit[31:0] base_addr);
  extern virtual task reset_dev_regs(RegTypeDef_t reg_struct[], bit[31:0] base_addr);
   extern virtual task write_reg_chk(RegTypeDef_t reg_struct[], bit[31:0] base_addr, bit[31:0] val);

endclass: i3c1_reg_test
//-------------------------------------------------------------------------
function i3c1_reg_test::new(string name = "i3c1_reg_test", uvm_component parent = null);
    super.new(name, parent);
       
endfunction: new
//-------------------------------------------------------------------------
function void i3c1_reg_test::build_phase(uvm_phase phase);
    super.build_phase(phase);
   
endfunction: build_phase

task i3c1_reg_test::default_val_chk(RegTypeDef_t reg_struct[], bit[31:0] base_addr);
  logic [31:0] rdata;
  for(int i = 0; i < reg_struct.size; i++) begin
    noc_reg_read(base_addr + reg_struct[i].OFFSET, rdata);
    if(rdata != reg_struct[i].RES_VAL) begin
      `uvm_error(get_name(), $sformatf("[i3c1_default_value_test]: reg_name:%s, addr=0x%0h, default_value=0x%0h, act_value=0x%0h", reg_struct[i].reg_name, base_addr + reg_struct[i].OFFSET, reg_struct[i].RES_VAL, rdata))
    end
  end
endtask
//-------------------------------------------------------------------------
task i3c1_reg_test::reset_dev_regs(RegTypeDef_t reg_struct[], bit[31:0] base_addr);
  logic [31:0] rdata;
  for(int i = 0; i < reg_struct.size; i++) begin
    noc_reg_write(base_addr + reg_struct[i].OFFSET, 32'h0);
  end
endtask

task i3c1_reg_test::write_reg_chk(RegTypeDef_t reg_struct[], bit[31:0] base_addr, bit[31:0] val);
  logic [31:0] rdata, rdata_old, rdata_exp;
  for(int i = 0; i < reg_struct.size; i++) begin
      if(reg_struct[i].OFFSET != 32'h3c && reg_struct[i].OFFSET != 32'h0 && reg_struct[i].OFFSET != 32'h4 ) begin
        noc_reg_read(base_addr + reg_struct[i].OFFSET, rdata_old);
        noc_reg_write(base_addr + reg_struct[i].OFFSET, val);
        noc_reg_read(base_addr + reg_struct[i].OFFSET, rdata);
        rdata_exp = (val & reg_struct[i].RW_MASK) | (rdata_old & (~reg_struct[i].RW_MASK));
        if(rdata !== rdata_exp) begin
          `uvm_error(get_name(), $sformatf("[i3c0_wr_reg_test]: reg_name:%s, addr=0x%0h, rdata_old=0x%0h, wdata=0x%0h, exp=0x%0h, act=0x%0h", reg_struct[i].reg_name, base_addr + reg_struct[i].OFFSET, rdata_old, val, rdata_exp, rdata))
        end  
      end

  end
endtask

//-------------------------------------------------------------------------
task i3c1_reg_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    phase.raise_objection(this);
    super.main_phase(phase);

    `uvm_info(get_type_name(),$psprintf("[Hury i3c_reg_test] main_phase start!"), UVM_LOW)
    default_val_chk(i3c_reg_chk_rst, `I3C1_BASE);
    reset_dev_regs(i3c_reg_no_init, `I3C1_BASE);
    write_reg_chk(i3c_reg, `I3C1_BASE, 32'h55555555);
    write_reg_chk(i3c_reg, `I3C1_BASE, 32'haaaaaaaa);
    write_reg_chk(i3c_reg, `I3C1_BASE, 32'h55aa55aa);
    write_reg_chk(i3c_reg, `I3C1_BASE, 32'haa55aa55);
    write_reg_chk(i3c_reg, `I3C1_BASE, 32'h0);
    write_reg_chk(i3c_reg, `I3C1_BASE, 32'hffffffff);
    //random 
    if(!std::randomize(r_wdata)) begin
        `uvm_error(get_type_name(),$sformatf("Rand Data Error !!!"));
    end
    $display("[Debug1205]rand data:%0h\n",r_wdata);
    write_reg_chk(i3c_reg, `I3C1_BASE, r_wdata);
    #20us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------


`endif //I3C1_REG_TEST__SV

