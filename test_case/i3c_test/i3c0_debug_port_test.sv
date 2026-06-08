`ifndef I3C0_DEBUG_PORT_TEST__SV
`define I3C0_DEBUG_PORT_TEST__SV


class i3c0_debug_port_test extends i3c_base_test;
   `uvm_component_utils(i3c0_debug_port_test)

   extern function new(string name = "i3c0_debug_port_test", uvm_component parent = null);
   extern virtual function void build_phase(uvm_phase phase);
   extern virtual task main_phase(uvm_phase phase);

   extern virtual task i3c0_force_debug_port_sig_1();
   extern virtual task i3c0_force_debug_port_sig_0();
   extern virtual task check_data(input bit[31:0] rdata_h, input bit[31:0] rdata_l, bit is1);

endclass: i3c0_debug_port_test
//-------------------------------------------------------------------------
function i3c0_debug_port_test::new(string name = "i3c0_debug_port_test", uvm_component parent = null);
    super.new(name, parent);

endfunction: new
//-------------------------------------------------------------------------
function void i3c0_debug_port_test::build_phase(uvm_phase phase);
    super.build_phase(phase);
    m_i3c_intf.i3c_num_ctrl = 0;

endfunction: build_phase
//-------------------------------------------------------------------------
task i3c0_debug_port_test::i3c0_force_debug_port_sig_1();

  //force sig 
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_bus_owner", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_scl_pp_od", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_sda_pp_od", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_scl_signal_level", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_sda_signal_level", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_cmd_queue_full", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_cmd_queue_empty", 1'b1);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_resp_queue_full", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_resp_queue_empty", 1'b1);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_ibi_queue_full", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_ibi_queue_empty", 1'b1);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_tx_buf_full", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_tx_buf_empty", 1'b1);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_rx_buf_full", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_rx_buf_empty", 1'b1);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mst_trfr[5:0]", 6'b111111);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mst_trfr_st[5:0]", 6'b111111);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mst_trfr_cmd_tid[3:0]", 4'b1111);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_master_idle", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_ctrl_enable", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mtc_ppcs_cmd_in_prog_reg", 1'b1);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mtc_slot_tick_p", 1'b1);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_slv_trfr_st[4:0]", 5'b11111);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_slv_trfr_cmd_tid[3:0]", 4'b1111);
endtask

task i3c0_debug_port_test::i3c0_force_debug_port_sig_0();

  //force sig 
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_bus_owner", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_scl_pp_od", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_sda_pp_od", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_scl_signal_level", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_sda_signal_level", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_cmd_queue_full", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_cmd_queue_empty", 1'b0);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_resp_queue_full", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_resp_queue_empty", 1'b0);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_ibi_queue_full", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_ibi_queue_empty", 1'b0);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_tx_buf_full", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_tx_buf_empty", 1'b0);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_rx_buf_full", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_rx_buf_empty", 1'b0);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mst_trfr[5:0]", 6'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mst_trfr_st[5:0]", 6'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mst_trfr_cmd_tid[3:0]", 4'b0);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_master_idle", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_ctrl_enable", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mtc_ppcs_cmd_in_prog_reg", 1'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_mtc_slot_tick_p", 1'b0);

  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_slv_trfr_st[4:0]", 5'b0);
  uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_I3C_WRAPPER_0.U_MCU_DWC_mipi_i3c.dbg_slv_trfr_cmd_tid[3:0]", 4'b0);
endtask

task i3c0_debug_port_test::check_data(input bit[31:0] rdata_h, input bit[31:0] rdata_l, bit is1);

    if(is1)begin
        if(rdata_h == 12'hfff && rdata_l == 32'hffffffff)

            `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 1 Check Pass !!!**]debug port  data_h = 0x%0h, data_l = 0x%0h",rdata_h, rdata_l), UVM_LOW)
        else
            `uvm_error(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 1 Check Fail !!!**]debug port  data_h = 0x%0h, data_l = 0x%0h",rdata_h, rdata_l))
    end
    else begin
         if(rdata_h == 12'h0 && rdata_l == 32'h0)

            `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 0 Check Pass !!!**]debug port  data_h = 0x%0h, data_l = 0x%0h",rdata_h, rdata_l), UVM_LOW)
        else
            `uvm_error(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 0 Check Fail !!!**]debug port  data_h = 0x%0h, data_l = 0x%0h",rdata_h, rdata_l))
    end


endtask
 //---------------------------------------------------------------------------------------------
task i3c0_debug_port_test::main_phase(uvm_phase phase);
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[31:0] rdata_h ;
    bit[31:0] rdata_l ;
    phase.raise_objection(this);
    super.main_phase(phase);

      // force all sig 0
    i3c0_force_debug_port_sig_0();

    noc_reg_read(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_DBG_PORT_H, rdata_h );
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 0**]debug port H12bit data_h = 0x%0h", rdata_h), UVM_LOW)

    noc_reg_read(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_DBG_PORT_L, rdata_l );
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 0**]debug port L32bit data_l = 0x%0h", rdata_l), UVM_LOW)
    //check data
    check_data(rdata_h, rdata_l,0);

    // force all sig 1
    i3c0_force_debug_port_sig_1();

    noc_reg_read(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_DBG_PORT_H, rdata_h );
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 1**]debug port H12bit data_h = 0x%0h", rdata_h), UVM_LOW)

    noc_reg_read(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_DBG_PORT_L, rdata_l );
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 1**]debug port L32bit data_l = 0x%0h", rdata_l), UVM_LOW)
    //check data
    check_data(rdata_h, rdata_l,1);

    // force all sig 0
    i3c0_force_debug_port_sig_0();

    noc_reg_read(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_DBG_PORT_H, rdata_h );
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 0**]debug port H12bit data_h = 0x%0h", rdata_h), UVM_LOW)

    noc_reg_read(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_DBG_PORT_L, rdata_l );
    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1018] [**force 0**]debug port L32bit data_l = 0x%0h", rdata_l), UVM_LOW)
    //check data
    check_data(rdata_h, rdata_l,0);

     //mcu scu reg
    rdata=0;
    noc_reg_read(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_STAT, rdata );
    rdata[24:23] = 2'h3;
    rdata[22:19] = 4'hf;
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_STAT, rdata );
    #100;
    rdata[24:23] = 2'h0;
    rdata[22:19] = 4'h0;
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_STAT, rdata );

    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_PID_H, 'hffff );
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_PID_H, 'h0 );
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_PID_L, 'hffffffff );
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_PID_L, 'h0 );
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_DCR,   'hffffffff );
    noc_reg_write(`MCU_SUB_SCU_BASE_ADDR+`MCUSS_I3C0_SVL_DCR,   'h0 );

    #10us;
    phase.drop_objection(this);
endtask: main_phase
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------


`endif //I3C0_DEBUG_PORT_TEST__SV
