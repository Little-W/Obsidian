`ifndef I3C0_TRANS_TXFIFO_TO_MEM_WITHDMA_TEST__SV
`define I3C0_TRANS_TXFIFO_TO_MEM_WITHDMA_TEST__SV
class i3c0_trans_txfifo_to_mem_withdma_test extends i3c_base_test;
   `uvm_component_utils(i3c0_trans_txfifo_to_mem_withdma_test)

   extern function new(string name = "i3c0_trans_txfifo_to_mem_withdma_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

endclass: i3c0_trans_txfifo_to_mem_withdma_test
//-------------------------------------------------------------------------
function i3c0_trans_txfifo_to_mem_withdma_test::new(string name = "i3c0_trans_txfifo_to_mem_withdma_test", uvm_component parent = null);
    super.new(name, parent);
       
endfunction: new
//-------------------------------------------------------------------------
function void i3c0_trans_txfifo_to_mem_withdma_test::build_phase(uvm_phase phase);
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
task i3c0_trans_txfifo_to_mem_withdma_test::main_phase(uvm_phase phase);
    bit[31:0] wdata_arr[2];
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0] tx_data_q[$];
    bit [6:0] dev_addr = 7'h63;
    phase.raise_objection(this);
    super.main_phase(phase);
    
    // write data to mem
    wdata_arr = {32'haa5599ff, 32'h5a5a5a5a};
    tx_data_q.push_back(wdata_arr[0][7:0]);
    tx_data_q.push_back(wdata_arr[0][15:8]);
    tx_data_q.push_back(wdata_arr[0][23:16]);
    tx_data_q.push_back(wdata_arr[0][31:24]);
    tx_data_q.push_back(wdata_arr[1][7:0]);
    tx_data_q.push_back(wdata_arr[1][15:8]);
    tx_data_q.push_back(wdata_arr[1][23:16]);
    tx_data_q.push_back(wdata_arr[1][31:24]);
    i3c_fill_memory(`MCU_SUB_SRAM_BASE_ADDR+32'h4000, wdata_arr);

    wdata=0;
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_STAT, wdata ); 

    // 0. set i3c_pp_timing
    i3c_set_scl_timing(0, 0);

    // 1.init i3c
    i3c_block_init(0,0,dev_addr, 8'h64);

    //dma en
    i3c_dma_enable(0);
    
    //2.enable i3c
    i3c_block_enable(0);
    i3c_set_daa_cmd(0,1);

    //dma cfg
    i3c_dma_write_config(`MCU_SUB_SRAM_BASE_ADDR+32'h4000, `I3C0_BASE+`TX_DATA_PORT,7'h1e,1,1);

    //5.set transfer arg [@--0:i3c_num 1:data_lenth --@]
    noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    end
    
    i3c_set_transfer_arg(0,8);

   //5.1
   noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    while(rdata[3] != 1'b1) begin
        noc_reg_read(`I3C0_BASE+`INTR_STATUS, rdata);
    end
    //6.set transfer command  ( 0:i3c_num, 1:bit[2:0] speed, 2:bit iscp, 3:bit[7:0] cmd, 4: bit isshortarg, 5: bit isread)
    i3c_set_transfer_cmd(0,0,0,0,0,0,2,1);//speed:sdr0:0
      
    //@0:slave_num
    i3c_master_txdata_to_vip_slave_pre_tr(1, dev_addr,tx_data_q);
 
    #10us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
`endif //I3C0_TRANS_TXFIFO_TO_MEM_WITHDMA_TEST__SV
