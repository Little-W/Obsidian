`ifndef I3C1_MASTER_SETAASA_TEST__SV
`define I3C1_MASTER_SETAASA_TEST__SV
class i3c1_master_setaasa_test extends i3c_base_test;
   `uvm_component_utils(i3c1_master_setaasa_test)

   i3c_default_slv_sequence i3c_vip_slv_seq ;

   extern function new(string name = "i3c1_master_setaasa_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i3c1_master_setaasa_test
//-------------------------------------------------------------------------
function i3c1_master_setaasa_test::new(string name = "i3c1_master_setaasa_test", uvm_component parent = null);
    super.new(name, parent);
       
endfunction: new
//-------------------------------------------------------------------------
function void i3c1_master_setaasa_test::build_phase(uvm_phase phase);
    super.build_phase(phase);
    
    cfg.master_cfg[0].is_active = 0;
    cfg.master_cfg[1].is_active = 0;
    cfg.slave_cfg[0].is_active = 0;
    cfg.slave_cfg[1].is_active = 1;
    cfg.slave_cfg[1].device_static_addr_en =1;
    m_i3c_intf.i3c_scb_ctrl = 3'h5;
    m_i3c_intf.i3c_num_ctrl = 1;
   
endfunction: build_phase
//-------------------------------------------------------------------------
task i3c1_master_setaasa_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
      bit[7:0] tx_data_q[$];
    bit [6:0] dev_addr = 7'h63;
    phase.raise_objection(this);
    super.main_phase(phase);
fork 
  begin 
    wdata=0;
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C1_STAT, wdata ); 

    // 1.init i3c
    i3c_block_init(1,0,dev_addr, 8'he3);

    //2.enable i3c
    i3c_block_enable(1);
    //3.setaasa
    i3c_set_transfer_cmd(1,0,1,8'h29,0,0,1,1);

    i3c_check_resp_status(1, rdata);
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1020][**CMD RESP**] response queue port  data = 0x%0h", rdata), UVM_LOW)
    noc_reg_read(`I3C1_BASE+`DEV_ADDR_TABLE_LOC1, rdata);
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1024][**dyn addr**] dynamic addr = 0x%0h", rdata), UVM_LOW)
    //4.recfg dynamic addr
    noc_reg_write(`I3C1_BASE+`DEV_ADDR_TABLE_LOC1, rdata);
    rdata[23:16]=8'he3 ;// dev dynamic_addr 
    noc_reg_write(`I3C1_BASE+`DEV_ADDR_TABLE_LOC1, rdata); 
 
    //5.0set transfer arg [@--0:i3c_num 1:data_lenth --@]
    noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);
    end
    
    i3c_set_transfer_arg(1,4);

   //5.1=================================================
    noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);
    end
    //6.set transfer command  ( 0:i3c_num, 1:bit[2:0] speed, 2:bit iscp, 3:bit[7:0] cmd, 4: bit isshortarg, 5: bit isread)
    i3c_set_transfer_cmd(1,0,0,0,0,0,2,1);//cmd invalid

    //7.write data to txffifo
    // @@@### 0: i3c_num, 1:data_lenth, 2:tx_thld ###
    i3c_wirte_data_to_txfifo(1, 1, 1, tx_data_q); 
    i3c_master_txdata_to_vip_slave_pre_tr(0, dev_addr,tx_data_q);
    
   end
   
   begin 

    #10us;
    i3c_vip_slv_seq = new("i3c_vip_slv_seq");
    $display("[HURYDEBUG1022] -----start slave seq-----\n"); 
    i3c_vip_slv_seq.start(m_soc_env.i3c_env.sequencer.slave_sequencer[1]);
    $display("[HURYDEBUG] -----start slave seq end-----\n");
   end  
   
 join

    #10us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
`endif //I3C1_MASTER_SETAASA_TEST__SV
