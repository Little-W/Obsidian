`ifndef I3C0_MASTER_MODE_HDR_DDR_RATE_TEST__SV
`define I3C0_MASTER_MODE_HDR_DDR_RATE_TEST__SV
class i3c0_master_mode_hdr_ddr_rate_test extends i3c_base_test;
   `uvm_component_utils(i3c0_master_mode_hdr_ddr_rate_test)

   extern function new(string name = "i3c0_master_mode_hdr_ddr_rate_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i3c0_master_mode_hdr_ddr_rate_test
//-------------------------------------------------------------------------
function i3c0_master_mode_hdr_ddr_rate_test::new(string name = "i3c0_master_mode_hdr_ddr_rate_test", uvm_component parent = null);
    super.new(name, parent);
       
endfunction: new
//-------------------------------------------------------------------------
function void i3c0_master_mode_hdr_ddr_rate_test::build_phase(uvm_phase phase);
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
task i3c0_master_mode_hdr_ddr_rate_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0] tx_data_q[$];
    bit[7:0] exp_data_q[$];
    bit [6:0] dev_addr = 7'h63;
    phase.raise_objection(this);
    super.main_phase(phase);
 
    wdata=0;
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_STAT, wdata ); 

    // 1.init i3c
    i3c_block_init(0,0,dev_addr, 8'he3);

    //2.enable i3c
    i3c_block_enable(0);
     
    //3.set transfer arg [@--0:i3c_num 1:data_lenth --@]
    noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    end
    //4.
    i3c_set_transfer_arg(0,4);

    //5.1
    noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    end
    //6.set transfer command  ( 0:i3c_num, 1:bit[2:0] speed, 2:bit iscp, 3:bit[7:0] cmd, 4: bit isshortarg, 5: bit isread, 6:tid, 7:is sstop)
    exp_data_q.push_back(8'h5a);
    exp_data_q.push_back(8'h5a);
    exp_data_q.push_back(8'h5a);
    exp_data_q.push_back(8'h5a);

    fork
      begin
        i3c_check_hdr_slave_payload(1, exp_data_q, 20us);
      end
      begin
        i3c_set_transfer_cmd(0,6,1,'h20,0,0,2,1);//speed:hdr_ddr:6

        //7.write data to txffifo
        // @@@### 0: i3c_num, 1:data_lenth, 2:tx_thld ###
        i3c_wirte_data_to_txfifo(0, 1, 1, tx_data_q);
      end
    join

    if(tx_data_q.size() != exp_data_q.size()) begin
        `uvm_error(get_type_name(), $sformatf("[I3C_HDR_CHECK] tx_data_q size mismatch: act=%0d exp=%0d", tx_data_q.size(), exp_data_q.size()))
    end
    foreach(exp_data_q[i]) begin
        if((i < tx_data_q.size()) && (tx_data_q[i] != exp_data_q[i])) begin
            `uvm_error(get_type_name(), $sformatf("[I3C_HDR_CHECK] tx_data_q[%0d] mismatch: act=0x%02h exp=0x%02h", i, tx_data_q[i], exp_data_q[i]))
        end
    end
    i3c_master_txdata_to_vip_slave_pre_tr(1, dev_addr,tx_data_q);
 
    #10us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
`endif //I3C0_MASTER_MODE_HDR_DDR_RATE_TEST__SV
