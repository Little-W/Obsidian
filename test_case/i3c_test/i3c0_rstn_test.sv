`ifndef I3C0_RSTN_TEST__SV
`define I3C0_RSTN_TEST__SV
class i3c0_rstn_test extends i3c_base_test;
   `uvm_component_utils(i3c0_rstn_test)
   rand int delay;

   extern function new(string name = "i3c0_rstn_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

   extern virtual task rst_cfg();

endclass: i3c0_rstn_test
//-------------------------------------------------------------------------
function i3c0_rstn_test::new(string name = "i3c0_rstn_test", uvm_component parent = null);
    super.new(name, parent);

endfunction: new
//-------------------------------------------------------------------------
function void i3c0_rstn_test::build_phase(uvm_phase phase);
    super.build_phase(phase);

    cfg.master_cfg[0].is_active = 0;
    cfg.master_cfg[1].is_active = 0;
    cfg.slave_cfg[0].is_active = 0;
    cfg.slave_cfg[1].is_active = 1;
    cfg.slave_cfg[1].device_static_addr_en =1;
    m_i3c_intf.i3c_scb_ctrl = 3'h5;
    m_i3c_intf.i3c_num_ctrl = 0;

endfunction: build_phase
//-------------------------------------------------------------------------
task i3c0_rstn_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0] tx_data_q[$];
    bit [6:0] dev_addr = 7'h63;
    phase.raise_objection(this);
    super.main_phase(phase);

    rst_cfg();

    // =======recfg ===============================================
    wdata=0;
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_STAT, wdata );

    // 0. set i3c_pp_timing
    i3c_set_scl_timing(0, 0);

    // 1.init i3c
    i3c_block_init(0,0,dev_addr, 8'h64);

    //2.enable i3c
    i3c_block_enable(0);
    i3c_set_daa_cmd(0,1);

    //3.set transfer arg [@--0:i3c_num 1:data_lenth --@]
    noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    end
    //4.
    i3c_set_transfer_arg(0,4);

    //5.
    noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    end
    //6.set transfer command  ( 0:i3c_num, 1:bit[2:0] speed, 2:bit iscp, 3:bit[7:0] cmd, 4: bit isshortarg, 5: bit isread)
    i3c_set_transfer_cmd(0,0,0,0,0,0,2,1);//speed:sdr0:0

    //7.write data to txffifo
    // @@@### 0: i3c_num, 1:data_lenth, 2:tx_thld ###
    i3c_wirte_data_to_txfifo(0, 1, 1, tx_data_q);
    i3c_master_txdata_to_vip_slave_pre_tr(1, dev_addr,tx_data_q);

    #10us;
    phase.drop_objection(this);
endtask: main_phase

//-------------------------------------------------------------------------
 task i3c0_rstn_test::rst_cfg();
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0] tx_data_q[$];
    bit [6:0] dev_addr = 7'h63;
    logic     presetn;

    $display("===Enter rst cfg===\n");
    begin
        wdata=0;
        noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_STAT, wdata );

        // 0.2 set i3c_pp_timing
        i3c_set_scl_timing(0, 0);
        //reset
         `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1031] ==reset clk=="), UVM_LOW)
      noc_reg_read(`MCU_CRG_BASE_ADDR+`MCU_CRG_RST_ENABLE1, rdata);
      rdata[13] = 'h1;
      noc_reg_write(`MCU_CRG_BASE_ADDR+`MCU_CRG_RST_ENABLE1, rdata);
      #20;
      do begin      
       uvm_hdl_read("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.presetn",presetn);
      end while(presetn !=1'b0); 
      
      `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1206] ==reset done11111 =="), UVM_LOW)
      noc_reg_read(`MCU_CRG_BASE_ADDR+`MCU_CRG_RST_ENABLE1, rdata);
      rdata[13] = 'h0;
      noc_reg_write(`MCU_CRG_BASE_ADDR+`MCU_CRG_RST_ENABLE1, rdata);
      `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1206] ==reset done 22222=="), UVM_LOW)

    end

 endtask

`endif //I3C0_RSTN_TEST__SV
