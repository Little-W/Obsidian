`ifndef I3C1_MASTER_TRANSMIT_WITHTXFIFO_TEST__SV
`define I3C1_MASTER_TRANSMIT_WITHTXFIFO_TEST__SV
class i3c1_master_transmit_withtxfifo_test extends i3c_base_test;
   `uvm_component_utils(i3c1_master_transmit_withtxfifo_test)


   extern function new(string name = "i3c1_master_transmit_withtxfifo_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i3c1_master_transmit_withtxfifo_test
//-------------------------------------------------------------------------
function i3c1_master_transmit_withtxfifo_test::new(string name = "i3c1_master_transmit_withtxfifo_test", uvm_component parent = null);
    super.new(name, parent);

endfunction: new
//-------------------------------------------------------------------------
function void i3c1_master_transmit_withtxfifo_test::build_phase(uvm_phase phase);
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
task i3c1_master_transmit_withtxfifo_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0] tx_data_q[$];
    bit [6:0] dev_addr = 7'h63;
    phase.raise_objection(this);
    super.main_phase(phase);

    wdata=0;
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C1_STAT, wdata );

    // 1.init i3c
    i3c_block_init(1,0,dev_addr, 8'he3);

    //2.enable i3c
    i3c_block_enable(1);

    //3.set transfer arg [@--0:i3c_num 1:data_lenth --@]
    noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);
    end
    //4.
    i3c_set_transfer_arg(1,4);

    //5.
    noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C1_BASE+`INTR_STATUS, rdata);
    end
    //6.set transfer command  ( 0:i3c_num, 1:bit[2:0] speed, 2:bit iscp, 3:bit[7:0] cmd, 4: bit isshortarg, 5: bit isread)
    i3c_set_transfer_cmd(1,0,0,0,0,0,2,1);//cmd invalid

    //7.write data to txffifo
    // @@@### 0: i3c_num, 1:data_lenth, 2:tx_thld ###
    i3c_wirte_data_to_txfifo(1, 1, 1, tx_data_q);
    i3c_master_txdata_to_vip_slave_pre_tr(1, dev_addr,tx_data_q);
    #10us;
    // reset
       uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_1.core_rst_n",1'b0);
       uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_1.presetn",1'b0);
       #20;
       uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_1.core_rst_n",1'b1);
       uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_1.presetn",1'b1);
    #5us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
`endif //I3C1_MASTER_TRANSMIT_WITHTXFIFO_TEST__SV
