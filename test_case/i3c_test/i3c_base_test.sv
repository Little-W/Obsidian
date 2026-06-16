
`ifndef GUARD_I3C_BASE_TEST_SV
`define GUARD_I3C_BASE_TEST_SV

`include "cust_svt_mipi_i3c_transaction.sv"
`include "cust_svt_mipi_i3c_system_configuration.sv"
`include "i3c_basic_env.sv"
`include "i3c_vip_mst_write_sequence.sv"
`include "i3c_vip_mst_read_sequence.sv"
`include "i3c_vip_i2c_mst_read_sequence.sv"
`include "i3c_default_mst_sequence.sv"
`include "i3c_default_slv_sequence.sv"
`include "i3c_default_virtual_sequence.sv"
`include "i3c_vip_secmst_ibi_sequence.sv"
//`include "i3c_simple_reset_sequence.sv"
`include "cust_i3c_sequence_collection.sv"
`include "i3c_system_error_catcher.sv"
`include "i3c_vip_slv_write_sequence.sv"

/**
 * Abstract:
 * In the build_phase phase of the test we will set the necessary test related
 * information:
 * - Use type wide factory override to set cust_svt_mipi_i3c_transaction
 *   and cust_svt_mipi_i3c_transaction as the default transaction type
 * - Create a default configuration and set it to the i3c_basic_env instance
 *   using the configuration DB
 * - Create the i3c_basic_env instance (named env)
 * - Configure the i3c_default_virtual_sequence as the default
 *   sequence for the main phase of the I3C ENV virtual sequencer
 * - Configure the sequence length to 1
 * - Configure the i3c_simple_reset_sequence as the default sequence
 *   for the reset phase of the TB ENV virtual sequencer
 * .
 */
class i3c_base_test extends chip_noc_base_test;

  /** UVM component utility macro */
  `uvm_component_utils(i3c_base_test)

//  virtual svt_mipi_i3c_if m_mipi_i3c_if;

  /** Instance of the environment */
 // i3c_basic_env env;
 chip_soc_env m_soc_env;

  /** Instantiate the configuration for Master*/
  cust_svt_mipi_i3c_system_configuration cfg;

  /** Drain time for this test.*/
  time drain_time = 500;

  /** Variable to enable/disable coverage */
  bit i3c_coverage_on;

  /** Variable used to disable I3C VIP*/
  bit disable_vip;

  /**
   * Instance of i3c_system_error_catcher.
   */
  i3c_system_error_catcher error_catcher;

  virtual i3c_intf m_i3c_intf;
  //---------------------------------------------------------------------------
  extern virtual task noc_reg_write(bit [47:0] addr, bit [31:0] reg_data);
  extern virtual task i3c_block_init(input bit i3c_num, input bit isi2c_mode, input bit[6:0] static_addr, input bit[7:0] dynamic_addr, input bit[7:0] resp_buf_thld,input bit[7:0] tx_empty_buf_thld, input bit[7:0] tx_start_thld, input bit[7:0] rx_buf_thld =0);
  extern virtual task i3c_block_enable(input bit i3c_num);
  extern virtual task i3c_dma_enable(input bit i3c_num);
  extern virtual task i3c_set_daa_cmd(input bit i3c_num,input bit isdirect);
  extern virtual task i3c_set_short_data_arg(input bit i3c_num, output bit[7:0] tx_data_q[$]);
  extern virtual task i3c_set_transfer_arg(input bit i3c_num, input bit[15:0] data_len);
  extern virtual task i3c_set_transfer_cmd(input bit i3c_num, input bit[2:0] speed, input bit iscp, input bit[7:0] cmd,input bit isshortarg, input bit isread, input bit[3:0]tr_id, input bit isstop);
  extern virtual task i3c_check_resp_status(input bit i3c_num, output bit[31:0] rdata);
  extern virtual task i3c_wirte_data_to_txfifo(input bit i3c_num, input int data_lenth, input int tx_thld,output bit[7:0] tx_data_q[$]);
  extern virtual task i3c_read_data_from_rxfifo(input bit i3c_num, input int data_lenth, input int rx_thld, output bit[7:0] rx_data_q[$]);
  extern virtual task i3c_slave_rxdata_to_vip_master_post_tr(input bit i3c_num, input bit[7:0] rx_data_q[$]);
  extern virtual task i3c_slave_txdata_to_vip_master_pre_tr(input bit i3c_num, input bit[7:0] tx_data_q[$]);
  extern virtual task i3c_master_txdata_to_vip_slave_pre_tr(input bit slave_num, input bit[6:0] dev_addr, input bit[7:0] tx_data_q[$]);
  extern virtual task i3c_master_rxdata_to_vip_slave_post_tr(input bit[6:0] dev_addr, input bit[7:0] rx_data_q[$]);
  extern virtual task i3c_dma_write_config(input bit[31:0] src_addr,input bit[31:0] dst_addr,input bit[6:0]dst_per_num,input [8:0] arlengh,input [8:0] awlengh);
  extern virtual task i3c_dma_read_config(input bit[31:0] src_addr,input bit[31:0] dst_addr,input bit[6:0] src_per_num, input [8:0] arlengh,input [8:0] awlengh);
  extern virtual task i3c_fill_memory(input bit[39:0] mem_addr, input bit[31:0] wdata_arr[]);
  extern virtual task i3c_secmaster_txdata_to_vip_master_pre_tr(input bit i3c_num, input bit[7:0] tx_data_q[$]);
  extern virtual task i3c_set_scl_timing(input bit i3c_num, input bit[2:0] speed);
//  extern virtual task i3c_set_dev_addr_tbl();

   /** Class constructor */
  function new(string name = "i3c_base_test", uvm_component parent=null);
    super.new(name,parent);
  endfunction : new

  //---------------------------------------------------------------------------
  /** build() - Method to build various component */
  virtual function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    if(!$cast(m_soc_env, m_env))begin
        `uvm_fatal(get_type_name(), "Unable to $cast m_soc_env to m_env")
    end

    if(!($value$plusargs("svt_i2c_disable_vip=%0b",disable_vip)))
        disable_vip = 1'b0;

   `uvm_info("build_phase", "i3c_base_test BUILD-FLOW: Starting...",UVM_LOW)

    /** replace blueprint of svt_mipi_i3c_transaction with cust_svt_mipi_i3c_transaction using factories in UVM */
    set_type_override_by_type(svt_mipi_i3c_master_transaction::get_type(),cust_svt_mipi_i3c_transaction::get_type());

    /** Create the configuration object for Master agent */
    cfg = cust_svt_mipi_i3c_system_configuration::type_id::create("cfg");

    /** Configure Master and Slave configurations */
    if(!cfg.randomize() with {
                               num_masters            == 2;
                               num_slaves             == 2;
                               master_cfg[0].mst_type == svt_mipi_i3c_configuration::MAIN_MST;
                               master_cfg[1].mst_type == svt_mipi_i3c_configuration::SEC_MST;
                               slave_cfg[0].slv_type  == svt_mipi_i3c_configuration::I2C_LEGACY_SLV;
                               slave_cfg[1].slv_type  == svt_mipi_i3c_configuration::I3C_SLV;
                             }
      ) begin
      `svt_error("build_phase", "Randomization failure.");
    end

    /**** Configure Master and Slave configurations *****/

    // configuring master[0] / main master
    cfg.master_cfg[0].is_active = 1;
    cfg.master_cfg[0].device_subscriber_id = 'h01;
    cfg.master_cfg[0].device_dynamic_address = 'h30;
`ifdef ENABLE_RESP_PUT_GET
    cfg.master_cfg[0].enable_put_response_i3c = 1;
`endif

    // configuring master[1] / Sec. Master
    cfg.master_cfg[1].is_active = 0;
    cfg.master_cfg[1].device_static_address = 'h31;
    cfg.master_cfg[1].device_subscriber_id = 'h02;
    cfg.master_cfg[1].device_dynamic_address = 'h34;
`ifdef ENABLE_RESP_PUT_GET
    cfg.master_cfg[1].enable_put_response_i3c = 1;
`endif

    // configuring slave[0] / Legacy I2C Slave
    cfg.slave_cfg[0].is_active = 0;
    cfg.slave_cfg[0].device_static_address = `SVT_MIPI_I3C_DEFAULT_STATIC_ADDRESS;
    cfg.slave_cfg[0].legacy_i2c_slave_type = `SVT_MIPI_I3C_I2C_GENERIC;

    // configuring slave[1] / I3C Slave
    cfg.slave_cfg[1].is_active = 0;
    cfg.slave_cfg[1].device_static_address = 'h63;
    cfg.slave_cfg[1].device_subscriber_id = 'h03;
    cfg.slave_cfg[1].device_dynamic_address = 'h64;

    // Version 0.7r1, Section 5.1.4.2 : Notice that there is no possibility for two or
    // moredevices to have the same Characteristic Register on the same I3C
    // bus instantiation; at least the BCR shall be different. However, due
    // to various error conditions, there is a very slim possibility for
    // such coincidence to happen.
    //
    // Note that the above stated error condition is not supported by the
    // VIP, and hence the BCR and DCR for each device need to be
    // configured with unique values.
    cfg.master_cfg[0].bus_char_reg = 8'b0111_0011;
    cfg.master_cfg[1].bus_char_reg = 8'b0111_0110;
    cfg.master_cfg[1].device_char_reg = 8'b1101_0011;
    cfg.master_cfg[1].is_master = 1'b1;
    cfg.master_cfg[0].is_master = 1'b1;
    cfg.slave_cfg[0].legacy_i2c_device_char_reg = 8'b1101_0001;
    cfg.slave_cfg[0].is_master = 1'b0;
    cfg.slave_cfg[1].bus_char_reg = 8'b0011_0110;
    cfg.slave_cfg[1].device_char_reg = 8'b1101_0101;
    cfg.slave_cfg[1].is_master = 1'b0;
    cfg.slave_cfg[1].hdrcap_modes = 8'b0000_0111;


    cfg.master_cfg[0].enable_cov=1;
    cfg.slave_cfg[1].enable_cov=1;

    //enabling HDR-DDR flow control elements
    cfg.ddr_flow_control_enabled = 1;

`ifdef SVT_MIPI_I3C_OD_PP_ENABLE
    cfg.master_cfg[0].i3c_od_pp_bus_speed = 1;
    cfg.master_cfg[1].i3c_od_pp_bus_speed = 1;
    cfg.slave_cfg[1].i3c_od_pp_bus_speed = 1;
`endif
    // load the value of I3C coverage as on/off
    if ($value$plusargs("I3C_COVERAGE_ON=%0b", i3c_coverage_on)) begin
      foreach(cfg.master_cfg[i]) begin
        cfg.master_cfg[i].enable_cov=1;
        cfg.master_cfg[i].enable_chk_pass_cov=1;
        cfg.slave_cfg[i].enable_cov=1;
        cfg.master_cfg[i].enable_chk_pass_cov=1;
      end
      if(i3c_coverage_on == 1'b1)
        `svt_note("build_phase", "Coverage is Enabled for Transaction, Toggle, Register and State type");
      else
        `svt_note("build_phase", "Coverage is Disabled");
    end

`ifdef CUST_1
    cfg.slave_cfg[1].enable_parity_check  = 1;
    cfg.master_cfg[0].i3c_od_pp_bus_speed = 0;
    cfg.master_cfg[1].i3c_od_pp_bus_speed = 0;
    cfg.slave_cfg[1].i3c_od_pp_bus_speed  = 0;
`elsif CUST_2
    cfg.slave_cfg[1].enable_parity_check  = 1;
    cfg.master_cfg[0].i3c_od_pp_bus_speed = 1;
    cfg.master_cfg[1].i3c_od_pp_bus_speed = 1;
    cfg.slave_cfg[1].i3c_od_pp_bus_speed  = 1;
`endif
    foreach(cfg.slave_cfg[i]) begin
      cfg.slave_cfg[i].timing_cfg.i3c_push_pull_scl_low_time    = 47;
      cfg.slave_cfg[i].timing_cfg.i3c_push_pull_scl_fall_time   = 3;
      cfg.slave_cfg[i].timing_cfg.i3c_push_pull_scl_high_time   = 47;
      cfg.slave_cfg[i].timing_cfg.i3c_push_pull_scl_rise_time   = 3;
      cfg.slave_cfg[i].timing_cfg.i3c_open_drain_scl_low_time   = 206;
      cfg.slave_cfg[i].timing_cfg.i3c_open_drain_scl_fall_time  = 4;
      cfg.slave_cfg[i].timing_cfg.i3c_open_drain_scl_high_time  = 38;
      cfg.slave_cfg[i].timing_cfg.i3c_open_drain_scl_rise_time  = 3;
      cfg.slave_cfg[i].timing_cfg.i3c_open_drain_hd_sta_time = 40;
      cfg.slave_cfg[i].timing_cfg.i3c_push_pull_hd_sta_time = 40;
      cfg.slave_cfg[i].timing_cfg.i3c_open_drain_su_sto_time    = 38;
      cfg.slave_cfg[i].timing_cfg.i3c_push_pull_su_sto_time     = 38;
      cfg.slave_cfg[i].timing_cfg.i3c_open_drain_su_sta_time    = 38;
      cfg.slave_cfg[i].timing_cfg.i3c_push_pull_su_sta_time     = 38;
       cfg.slave_cfg[i].timing_cfg.min_i3c_open_drain_hd_sta_time = 39;
       cfg.slave_cfg[i].timing_cfg.min_i3c_push_pull_hd_sta_time = 39;
       cfg.slave_cfg[i].timing_cfg.min_i3c_push_pull_su_sto_time    = 38;
      cfg.slave_cfg[i].max_tbuf_time_fs = 2000000;
      cfg.slave_cfg[i].timing_cfg.min_i3c_open_drain_scl_high_time = 38;
      cfg.slave_cfg[i].timing_cfg.min_i3c_open_drain_scl_low_time = 206;
      cfg.slave_cfg[i].timing_cfg.max_i3c_open_drain_su_dat_time = 10000;
    end

    foreach(cfg.master_cfg[i]) begin
      cfg.master_cfg[i].timing_cfg.i3c_push_pull_scl_low_time    = 47;
      cfg.master_cfg[i].timing_cfg.i3c_push_pull_scl_fall_time   = 3;
      cfg.master_cfg[i].timing_cfg.i3c_push_pull_scl_high_time   = 47;
      cfg.master_cfg[i].timing_cfg.i3c_push_pull_scl_rise_time   = 3;
      cfg.master_cfg[i].timing_cfg.i3c_open_drain_scl_low_time   = 206;
      cfg.master_cfg[i].timing_cfg.i3c_open_drain_scl_fall_time  = 4;
      cfg.master_cfg[i].timing_cfg.i3c_open_drain_scl_high_time  = 38;
      cfg.master_cfg[i].timing_cfg.i3c_open_drain_scl_rise_time  = 3;
      cfg.master_cfg[i].timing_cfg.i3c_open_drain_hd_sta_time = 40;
      cfg.master_cfg[i].timing_cfg.i3c_push_pull_hd_sta_time = 40;
      cfg.master_cfg[i].timing_cfg.i3c_open_drain_su_sto_time    = 38;
      cfg.master_cfg[i].timing_cfg.i3c_push_pull_su_sto_time     = 38;
      cfg.master_cfg[i].timing_cfg.i3c_open_drain_su_sta_time    = 38;
      cfg.master_cfg[i].timing_cfg.i3c_push_pull_su_sta_time     = 38;
      cfg.master_cfg[i].timing_cfg.min_i3c_open_drain_hd_sta_time   = 39;
      cfg.master_cfg[i].timing_cfg.min_i3c_push_pull_hd_sta_time    = 39;
      cfg.master_cfg[i].timing_cfg.min_i3c_push_pull_su_sto_time    = 38;
      //cfg.master_cfg[i].max_tbuf_time_fs = 2000000;
      cfg.master_cfg[i].timing_cfg.min_i3c_open_drain_scl_high_time = 38;
      cfg.master_cfg[i].timing_cfg.min_i3c_open_drain_scl_low_time = 206;
      cfg.master_cfg[i].timing_cfg.max_i3c_open_drain_su_dat_time = 10000;
      cfg.master_cfg[i].max_tbuf_time_fs = 2000000;
    end


    /** Set Master configuration in environment */
    uvm_config_db#(cust_svt_mipi_i3c_system_configuration)::set(this,"m_env.i3c_env", "i3c_system_cfg", cfg);

    /** Create the environment */
    //env = i3c_basic_env::type_id::create("m_env.i3c_env", this);
    //hury +++++++s

    if(!uvm_config_db#(virtual i3c_intf)::get(this, "", "m_i3c_intf", m_i3c_intf))begin
        `uvm_fatal(get_type_name(), "Unable to get usb virtual interface!!!")
    end

    uvm_config_db#(virtual i3c_intf)::set(this, "m_env.i3c_env*", "vif", m_i3c_intf);
    //hury++++++++e

    /** Apply the default virtual sequence */
//    uvm_config_db#(uvm_object_wrapper)::set(this, "env.i3c_system_env.sequencer.main_phase", "default_sequence", i3c_default_virtual_sequence::type_id::get());

    /** Set the sequence 'length' to generate 1 transaction with constraints */
//    uvm_config_db#(int unsigned)::set(this, "env.i3c_system_env.sequencer.i3c_default_virtual_sequence", "sequence_length", 1);

    /** Apply the default reset sequence */
//    uvm_config_db#(uvm_object_wrapper)::set(this, "env.sequencer.reset_phase", "default_sequence", i3c_simple_reset_sequence::type_id::get());

    /** Set the env to different sequences.*/
    uvm_config_db#(i3c_basic_env)::set(this, "m_env.i3c_env.sequencer.*", "m_env.i3c_env", m_soc_env.i3c_env);
    uvm_config_db#(i3c_basic_env)::set(this, "m_env.i3c_env.i3c_system_env.sequencer.*", "m_env.i3c_env", m_soc_env.i3c_env);

    /** Set the cfg to different sequences.*/
    uvm_config_db#(cust_svt_mipi_i3c_system_configuration)::set(this, "m_env.i3c_env.sequencer.*", "i3c_cfg", cfg);
    uvm_config_db#(cust_svt_mipi_i3c_system_configuration)::set(this, "m_env.i3c_env.i3c_system_env.sequencer.*", "i3c_cfg", cfg);

    `uvm_info("build_phase", "i3c_base_test BUILD-FLOW: Finishing...",UVM_LOW)

    // Create the handle of i3c_system_error_catcher class.
    error_catcher = i3c_system_error_catcher::type_id::create("error_catcher");
 `ifdef SVT_UVM_TECHNOLOGY
    uvm_report_cb::add(null, error_catcher);
 `elsif SVT_OVM_TECHNOLOGY
    error_catcher.append();
 `endif

  endfunction : build_phase

  //---------------------------------------------------------------------------
  /** This is the pre_rest_phase */
  task pre_reset_phase(uvm_phase phase);
    super.pre_reset_phase(phase);
    if(disable_vip == 1'b0) begin
      m_soc_env.i3c_env.sb.reconfigure(cfg);
    end
  endtask

  //---------------------------------------------------------------------------
  /** This is the main_phase */
  task main_phase(uvm_phase phase);
      super.main_phase(phase);
      phase.raise_objection(this);
      `uvm_info(get_type_name(),$psprintf("[Hury] main_phase start!"), UVM_LOW)
      `uvm_info("main_phase",$sformatf("[HURYDEBUG1118] I3C_NUM_CTRL:0x%h", m_i3c_intf.i3c_num_ctrl), UVM_LOW);

      if(m_i3c_intf.i3c_num_ctrl ==0)begin
        iomux_mcu0_cfg(16, 0, 0);
        iomux_mcu0_cfg(17, 0, 0);
        // Enable the alternate I3C0 mux path as well for mux setting checks.
        iomux_mcu0_cfg(36, 1, 0);
        iomux_mcu0_cfg(37, 1, 0);
      end
      if(m_i3c_intf.i3c_num_ctrl ==1)begin
        iomux_mcu1_cfg(70, 0, 0);
        iomux_mcu1_cfg(71, 0, 0);
        // Enable the alternate I3C1 mux path as well for mux setting checks.
        iomux_mcu1_cfg(72, 1, 0);
        iomux_mcu1_cfg(73, 1, 0);
      end
      // i3c0 pad
      if(m_i3c_intf.i3c_num_ctrl ==2)begin
        iomux_mcu0_cfg(36, 1, 0);
        iomux_mcu0_cfg(37, 1, 0);
      end
      if(m_i3c_intf.i3c_num_ctrl ==5)begin
        iomux_mcu1_cfg(72, 1, 0);
        iomux_mcu1_cfg(73, 1, 0);
//        iomux_mcu0_cfg(28, 2, 0);
//        iomux_mcu1_cfg(29, 2, 0);
      end

       `uvm_info("main_phase","[HURYDEBUG1206] I3C PAD CFG DONE!!!!", UVM_LOW);


   `ifdef SVT_UVM_1800_2_2017_OR_HIGHER
      uvm_objection phase_over;
    `uvm_info("main_phase", " HURY0920 Entered ...",UVM_LOW)
    `uvm_info("main_phase", $sformatf("Setting the drain time in the main_phase of the base test to twice the configured IPG Length 200"), UVM_NONE)
      phase_over = phase.get_objection();
      phase_over.set_drain_time(this, (drain_time));
    `else
     `uvm_info("main_phase", "Entered ...",UVM_LOW)
     `uvm_info("main_phase", $sformatf("Setting the drain time in the main_phase of the base test to twice the configured IPG Length 200"), UVM_NONE)
      phase.phase_done.set_drain_time(this, (drain_time));
    `endif
    `uvm_info("main_phase", "[Hury]Exited ...",UVM_LOW)
     phase.drop_objection(this);
  endtask


  //---------------------------------------------------------------------------
  /**
   * Calculate the pass or fail status for the test in the final phase method of the
   * test. If a UVM_FATAL, UVM_ERROR, or a UVM_WARNING message has been generated the
   * test will fail.
   */
  function void final_phase(uvm_phase phase);
    uvm_report_server svr;

    super.final_phase(phase);

    `uvm_info("final_phase", "i3c_base_test FINAL-FLOW: Starting...",UVM_LOW)

    svr = uvm_report_server::get_server();

    if (svr.get_severity_count(UVM_FATAL) + svr.get_severity_count(UVM_ERROR) > 0) begin
      `uvm_info("final_phase", "\nSvtTestEpilog: Failed\n", UVM_LOW)
    end
    else begin
      `uvm_info("final_phase", "\nSvtTestEpilog: Passed\n", UVM_LOW)
    end

    `uvm_info("final_phase", "i3c_base_test FINAL-FLOW: Finishing...",UVM_LOW)
  endfunction : final_phase

endclass : i3c_base_test
//--------------------------------------------------------------------------------
task i3c_base_test::noc_reg_write(bit [47:0] addr, bit [31:0] reg_data);
  axi_master_directed_write_sequence axi_wr_seq;
  axi_wr_seq = new("axi_wr_seq");
  axi_wr_seq.enable_get_response = 1;
  axi_wr_seq.waddr = addr;
  axi_wr_seq.wdata = reg_data;
  axi_wr_seq.start(m_env.m_amba_sys_env.axi_system[0].master[0].sequencer);
endtask: noc_reg_write
//--------------------------------------------------------------------------------
task i3c_base_test::i3c_block_init(input bit i3c_num, input bit isi2c_mode, input bit[6:0] static_addr, input bit[7:0] dynamic_addr = 0, input bit[7:0] resp_buf_thld =0,input bit[7:0] tx_empty_buf_thld =0, input bit[7:0] tx_start_thld =0,input bit[7:0] rx_buf_thld =0 );
    bit[31:0] i3c_baddr;
    bit[31:0] wdata;
    bit[31:0] rdata;


    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;
    //0.set thld
    noc_reg_read(i3c_baddr+`QUEUE_THLD_CTRL, rdata );
    rdata[15:8] = resp_buf_thld; //resp buf thld
    noc_reg_write(i3c_baddr+`QUEUE_THLD_CTRL, rdata );

    noc_reg_read(i3c_baddr+`DATA_BUFFER_THLD_CTRL, rdata );
    rdata[2:0] = tx_empty_buf_thld; //'h0; //tx_empty_buf_thld
    rdata[10:8] = rx_buf_thld; //'h0;// rx_buf_thld
    rdata[18:16] = tx_start_thld ; //'h0; //tx_start_thld
    noc_reg_write(i3c_baddr+`DATA_BUFFER_THLD_CTRL, rdata );

    //1.set master
     wdata=32'h0;
     noc_reg_write(i3c_baddr+`DEVICE_CTRL_EXTENDED, wdata );
     //2. enable intr
     wdata = 32'hffff;
     noc_reg_write(i3c_baddr+`INTR_STATUS_EN, wdata );
     noc_reg_write(i3c_baddr+`INTR_SIGNAL_EN, wdata );

     //3. set dev_addr
     wdata =0;
     wdata[22:16]='h55;//dynamic_addr
     wdata[31]='h1;
     noc_reg_write(i3c_baddr+`DEVICE_ADDR, wdata);

     //4.set DAT
     wdata =0;
     if(isi2c_mode)begin
        wdata[31] = isi2c_mode;
        wdata[6:0]  = static_addr; //dev static addr
     end
     else begin
        wdata[23:16]= dynamic_addr;// dev dynamic_addr
        wdata[6:0]  = static_addr; //dev static addr
     end
     noc_reg_write(i3c_baddr+`DEV_ADDR_TABLE_LOC1, wdata);



endtask //i3c_block_init
//---------------------------------------------------------------------------
task i3c_base_test::i3c_block_enable(input bit i3c_num);
    bit[31:0] i3c_baddr;
    bit[31:0] rdata;

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;

     noc_reg_read(i3c_baddr+`DEVICE_CTRL, rdata );
     `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1112]  device ctrl data000 = 0x%h", rdata), UVM_LOW)
     rdata[31]=32'h1;
     `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1112]  device ctrl data111 = 0x%h", rdata), UVM_LOW)
     noc_reg_write(i3c_baddr+`DEVICE_CTRL, rdata );

endtask //i3c_block_enable
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
task i3c_base_test::i3c_dma_enable(input bit i3c_num);
    bit[31:0] i3c_baddr;
    bit[31:0] rdata;

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;

     noc_reg_read(i3c_baddr+`DEVICE_CTRL, rdata );
     rdata[28]='h1;

     noc_reg_write(i3c_baddr+`DEVICE_CTRL, rdata );

endtask //i3c_dma_enabl
task i3c_base_test::i3c_set_daa_cmd(input bit i3c_num,input bit isdirect);
    bit[31:0] i3c_baddr;
    bit[31:0] wdata;
    bit[7:0] dda_cmd;

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;

    if(isdirect)
        dda_cmd='h87;
    else
        dda_cmd='h7;

    wdata =0;
    wdata[2:0]='h3;
    wdata[6:3]='h5;
    wdata[14:7]=dda_cmd;
    wdata[20:16]='h0;
    wdata[25:21]='h1;
    wdata[26] = 'h1;
    wdata[30]='h1;
    noc_reg_write(i3c_baddr+`COMMAND_QUEUE_PORT, wdata );

endtask
//---------------------------------------------------------------------------
task i3c_base_test::i3c_set_short_data_arg(input bit i3c_num, output bit[7:0] tx_data_q[$]);

    bit[31:0] i3c_baddr;
    bit[31:0] wdata;

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;

    wdata=0;
    wdata[2:0]='h2;
    wdata[5:3]='h7;
    wdata[15:8]='h55;
    wdata[23:16]='haa;
    wdata[31:24]='hff;
    noc_reg_write(i3c_baddr+`COMMAND_QUEUE_PORT, wdata );

    tx_data_q.push_back(wdata[15:8]);
    tx_data_q.push_back(wdata[23:16]);
    tx_data_q.push_back(wdata[31:24]);

endtask
//---------------------------------------------------------------------------
task i3c_base_test::i3c_set_transfer_arg(input bit i3c_num,input bit[15:0] data_len);
    bit[31:0] i3c_baddr;
    bit[31:0] wdata;

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;

    wdata=0;
    wdata[2:0]='h1;
    wdata[15:8]='h0;
    wdata[31:16]=data_len;
    noc_reg_write(i3c_baddr+`COMMAND_QUEUE_PORT, wdata );
endtask
//---------------------------------------------------------------------------
task i3c_base_test::i3c_set_transfer_cmd(input bit i3c_num, input bit[2:0] speed, input bit iscp, input bit[7:0] cmd,input bit isshortarg, input bit isread, input bit[3:0]tr_id, input bit isstop);
    bit[31:0] i3c_baddr;
    bit[31:0] wdata;

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;

    wdata=0;
    wdata[2:0]=0;
    wdata[6:3]=tr_id;
    if(iscp)begin
        wdata[14:7]=cmd;
    end
    wdata[15]=iscp;
    wdata[20:16]=0;
    wdata[23:21]=speed;
    wdata[25]=0;
    wdata[26]=1;
    if(speed<=4)begin
        wdata[27]= isshortarg;
    end
    wdata[28]=isread;
    wdata[30]=1;
    if(speed<=4)begin
        wdata[31]=1;
    end

    noc_reg_write(i3c_baddr+`COMMAND_QUEUE_PORT, wdata );

endtask
//----------------------------------------------------------------------------
task i3c_base_test::i3c_check_resp_status(input bit i3c_num, output bit[31:0] rdata);
    bit[31:0] i3c_baddr;
    bit[31:0] rdata;

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;

    noc_reg_read(i3c_baddr+`INTR_STATUS, rdata);
    while(rdata[4] != 1'b1) begin
        noc_reg_read(i3c_baddr+`INTR_STATUS, rdata);
        `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1021] response queue port  data = 0x%0h", rdata), UVM_LOW)
    end
    noc_reg_read(i3c_baddr+`RESPONSE_QUEUE_PORT, rdata);

endtask
//----------------------------------------------------------------------------
 task i3c_base_test::i3c_wirte_data_to_txfifo(input bit i3c_num, input int data_lenth, input int tx_thld, output bit[7:0] tx_data_q[$]);
    bit[31:0] i3c_baddr;
//    bit[31:0] wdata[1] = {32'haa5599ff};
    bit[31:0] wdata[];
    bit[31:0] rdata;
    int data_lenth_num;
    data_lenth_num = data_lenth;


    wdata = new[data_lenth];
    for(int i =0; i < data_lenth; i++) begin
        wdata[i] = 32'h5a5a5a5a + i ;
        `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1121] array  data = 0x%0h", wdata[i]), UVM_LOW)
    end

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;

    while(data_lenth_num>0)begin
        $display("====enter while 1013====\n");
        noc_reg_read(i3c_baddr+`INTR_STATUS, rdata);
        while(rdata[0] != 1'b1) begin
            noc_reg_read(i3c_baddr+`INTR_STATUS, rdata);
        end
        $display("====exit  while 1013====\n");

        if(data_lenth_num/tx_thld>0)begin
            for(int i=0;i<tx_thld;i++) begin
                `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1014]111111 write into txfifo  data = 0x%0h", wdata[i]), UVM_LOW)
                noc_reg_write(i3c_baddr+`TX_DATA_PORT, wdata[i]);
                tx_data_q.push_back(wdata[i][7:0]);
                tx_data_q.push_back(wdata[i][15:8]);
                tx_data_q.push_back(wdata[i][23:16]);
                tx_data_q.push_back(wdata[i][31:24]);
            end
            data_lenth_num = data_lenth_num-tx_thld;
        end
        else begin
            int left_num = data_lenth_num%tx_thld;
            for(int j=0;j<left_num;j++) begin
                `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1014]22222 write into txfifo  data = 0x%0h", wdata[tx_thld + j]), UVM_LOW)
                noc_reg_write(i3c_baddr+`TX_DATA_PORT, wdata[tx_thld + j]);
                tx_data_q.push_back(wdata[tx_thld + j][7:0]);
                tx_data_q.push_back(wdata[tx_thld + j][15:8]);
                tx_data_q.push_back(wdata[tx_thld + j][23:16]);
                tx_data_q.push_back(wdata[tx_thld + j][31:24]);
            end
            data_lenth_num = data_lenth_num-left_num;
        end

    end
endtask

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
task i3c_base_test::i3c_read_data_from_rxfifo(input bit i3c_num, input int data_lenth, input int rx_thld, output bit[7:0] rx_data_q[$]);
    bit[31:0] i3c_baddr;
    bit[31:0] wdata;
    bit[31:0] rdata;
    bit[31:0] rxdata;

    `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1010]33333  ENTER INTO i3c_read_data_from_rxfifo TASK "), UVM_LOW)

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;


    while(data_lenth>0)begin
        $display("====enter while====\n");
        noc_reg_read(i3c_baddr+`INTR_STATUS, rdata);
        `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1010]33333 intr_status data = 0x%0h", rdata), UVM_LOW)
        while(rdata[1] != 1'b1) begin
            noc_reg_read(i3c_baddr+`INTR_STATUS, rdata);
            `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1010]44444 intr_status data = 0x%0h", rdata), UVM_LOW)
        end

        if(data_lenth/rx_thld>0)begin
            for(int i=0;i<rx_thld;i++) begin
                noc_reg_read(i3c_baddr+`RX_DATA_PORT, rxdata);
                `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1010]1111==rx fifo data[%0d] = 0x%0h==", i, rxdata), UVM_LOW)
                data_lenth = data_lenth-rx_thld;
                rx_data_q.push_back(rxdata[7:0]);
                rx_data_q.push_back(rxdata[15:8]);
                rx_data_q.push_back(rxdata[23:16]);
                rx_data_q.push_back(rxdata[31:24]);
            end
        end
        else begin
            int left_num = data_lenth%rx_thld;
            for(int j=0;j<left_num;j++) begin
                noc_reg_read(i3c_baddr+`RX_DATA_PORT, rxdata);
                `uvm_info(get_type_name(), $sformatf("[HURYDEBUG1010]2222==rx fifo data[%0d] = 0x%0h==", j, rxdata), UVM_LOW)
                data_lenth = data_lenth-left_num;
                rx_data_q.push_back(rxdata[7:0]);
                rx_data_q.push_back(rxdata[15:8]);
                rx_data_q.push_back(rxdata[23:16]);
                rx_data_q.push_back(rxdata[31:24]);

            end
        end

    end


endtask
//-------------------------------------------------------------------------------

task i3c_base_test::i3c_slave_rxdata_to_vip_master_post_tr(input bit i3c_num, input bit[7:0] rx_data_q[$]);
    svt_mipi_i3c_master_transaction   mst_tr_dummy;
    svt_mipi_i3c_master_transaction   mst_tr;
    mst_tr_dummy = new();
    mst_tr = new();
    //--------------------------------------------------------
    mst_tr_dummy.cmd = svt_mipi_i3c_master_transaction::WRITE;
    mst_tr_dummy.addr = 'h62;
    mst_tr_dummy.set_ccc = 0;
    mst_tr_dummy.data = new[1];
    mst_tr_dummy.data[0] = 'haa;
    m_soc_env.i3c_env.sb.write_master0_rx_observed_port(mst_tr_dummy);

    //--------------------------------------------
    mst_tr.cmd = svt_mipi_i3c_master_transaction::WRITE;
    mst_tr.addr = 'h31;
    mst_tr.set_ccc = 0;
//    mst_tr.data.size() = rx_data_q.size();
    mst_tr.data = new[rx_data_q.size()];
    foreach(rx_data_q[i]) begin
        mst_tr.data[i] = rx_data_q[i] ;
    end
    m_soc_env.i3c_env.sb.write_master0_rx_observed_port(mst_tr);
endtask
//----------------------------------------------------------------------------------

task i3c_base_test::i3c_slave_txdata_to_vip_master_pre_tr(input bit i3c_num, input bit[7:0] tx_data_q[$]);
    svt_mipi_i3c_master_transaction   mst_tr_dummy;
    svt_mipi_i3c_master_transaction   mst_tr;
    mst_tr_dummy = new();
    mst_tr = new();
    //--------------------------------------------------------
    mst_tr_dummy.cmd = svt_mipi_i3c_master_transaction::WRITE;
    mst_tr_dummy.addr = 'h62;
    mst_tr_dummy.set_ccc = 0;
    mst_tr_dummy.data = new[1];
    mst_tr_dummy.data[0] = 'haa;
    m_soc_env.i3c_env.sb.write_master0_tx_observed_port(mst_tr_dummy);

    //--------------------------------------------
    mst_tr.cmd = svt_mipi_i3c_master_transaction::READ;
    mst_tr.addr = 'h31;
    mst_tr.set_ccc = 0;
//    mst_tr.data.size() = rx_data_q.size();
    mst_tr.data = new[tx_data_q.size()];
    foreach(tx_data_q[i]) begin
        mst_tr.data[i] = tx_data_q[i] ;
    end
    m_soc_env.i3c_env.sb.write_master0_tx_observed_port(mst_tr);
endtask
//-------------------------------------------------------------------------

//----------------------------------------------------------------------------------

task i3c_base_test::i3c_master_txdata_to_vip_slave_pre_tr(input bit slave_num, input bit[6:0]dev_addr, input bit[7:0] tx_data_q[$]);
    svt_mipi_i3c_slave_transaction   slv_tr;
    slv_tr = new();

    //--------------------------------------------
    slv_tr.cmd = svt_mipi_i3c_slave_transaction::WRITE;
    slv_tr.addr = dev_addr;
    slv_tr.set_ccc = 0;
    slv_tr.data = new[tx_data_q.size()];
    foreach(tx_data_q[i]) begin
        slv_tr.data[i] = tx_data_q[i] ;
    end
    if(slave_num)
        m_soc_env.i3c_env.sb.write_slave1_tx_observed_port(slv_tr);
    else
        m_soc_env.i3c_env.sb.write_slave0_tx_observed_port(slv_tr);

endtask
//------------------------------------------------------------------------
task i3c_base_test::i3c_master_rxdata_to_vip_slave_post_tr(input bit[6:0] dev_addr, input bit[7:0] rx_data_q[$]);
    svt_mipi_i3c_slave_transaction   slv_tr;
    slv_tr = new();

    //--------------------------------------------
    slv_tr.cmd = svt_mipi_i3c_slave_transaction::WRITE;
    slv_tr.addr = dev_addr;
    slv_tr.set_ccc = 0;
    slv_tr.data = new[rx_data_q.size()];
    foreach(rx_data_q[i]) begin
        slv_tr.data[i] = rx_data_q[i] ;
    end
    m_soc_env.i3c_env.sb.write_slave1_rx_observed_port(slv_tr);

endtask
//-------------------------------------------------------------------------
task i3c_base_test::i3c_secmaster_txdata_to_vip_master_pre_tr(input bit i3c_num, input bit[7:0] tx_data_q[$]);
    svt_mipi_i3c_master_transaction   mst_tr_dummy;
    svt_mipi_i3c_master_transaction   mst_tr1;
    svt_mipi_i3c_master_transaction   mst_tr2;
    svt_mipi_i3c_master_transaction   mst_tr3;
    svt_mipi_i3c_master_transaction   mst_tr4;
    svt_mipi_i3c_master_transaction   mst_tr5;
    svt_mipi_i3c_master_transaction   mst_tr;
    mst_tr_dummy = new();
    mst_tr1 = new();
    mst_tr2 = new();
    mst_tr3 = new();
    mst_tr4 = new();
    mst_tr5 = new();
    mst_tr = new();

    //--------------------------------------------------------
    mst_tr_dummy.cmd = svt_mipi_i3c_master_transaction::WRITE;
    mst_tr_dummy.addr = 'h62;
    mst_tr_dummy.set_ccc = 0;
    mst_tr_dummy.ccc     ='h99;
    mst_tr_dummy.data = new[1];
    mst_tr_dummy.data[0] = 'haa;
    m_soc_env.i3c_env.sb.write_master0_tx_observed_port(mst_tr_dummy);
    //--------------------------1--------------------------
    mst_tr1.cmd = svt_mipi_i3c_master_transaction::WRITE;
    mst_tr1.addr = 'h7e;
    mst_tr1.set_ccc = 1;
    mst_tr1.ccc = 'h87;
    mst_tr1.data = new[3];
    mst_tr1.data[0] ='h31;
    mst_tr1.data[1] ='h34;
    mst_tr1.data[2] ='h63;
    m_soc_env.i3c_env.sb.write_master0_tx_observed_port(mst_tr1);
    //--------------------------2------------------------
    mst_tr2.cmd = svt_mipi_i3c_master_transaction::WRITE;
    mst_tr2.addr = 'h34;
    m_soc_env.i3c_env.sb.write_master0_tx_observed_port(mst_tr2);
    //--------------------------3-----------------------
    mst_tr3.cmd = svt_mipi_i3c_master_transaction::WRITE;
    mst_tr3.addr = 'h7e;
    mst_tr3.set_ccc = 1;
    mst_tr3.ccc  = 'h91;
    m_soc_env.i3c_env.sb.write_master0_tx_observed_port(mst_tr3);
    //--------------------------4-----------------------
    mst_tr4.cmd = svt_mipi_i3c_master_transaction::WRITE;
    mst_tr4.addr = 'h7e;
    mst_tr4.set_ccc = 1;
    mst_tr4.ccc  = 'h91;
    m_soc_env.i3c_env.sb.write_master0_tx_observed_port(mst_tr4);
    //--------------------------5-----------------------
    mst_tr5.cmd = svt_mipi_i3c_master_transaction::READ;
    mst_tr5.addr = 'h34;
    mst_tr5.set_ccc = 1;
    mst_tr5.ccc  = 'h91;
    m_soc_env.i3c_env.sb.write_master0_tx_observed_port(mst_tr5);
    //--------------------------------------------
    mst_tr.cmd = svt_mipi_i3c_master_transaction::WRITE;
    mst_tr.addr = 'h30;
    mst_tr.set_ccc = 0;
    mst_tr.ccc     ='h99;
    mst_tr.data = new[tx_data_q.size()];
    foreach(tx_data_q[i]) begin
        mst_tr.data[i] = tx_data_q[i] ;
    end
    m_soc_env.i3c_env.sb.write_master0_tx_observed_port(mst_tr);


endtask
//-------------------------------------------------------------------------

 task i3c_base_test::i3c_set_scl_timing(input bit i3c_num, input bit[2:0] speed);
    bit[31:0] i3c_baddr;
    bit[31:0] wdata ;
    bit[31:0] rdata ;
    bit[7:0]  i3c_pp_lcnt;
    bit[7:0]  i3c_pp_hcnt;
    bit[7:0]  i3c_od_lcnt;
    bit[7:0]  i3c_ext_lcnt_1;
    bit[7:0]  i3c_ext_lcnt_2;
    bit[7:0]  i3c_ext_lcnt_3;
    bit[7:0]  i3c_ext_lcnt_4;

    if(i3c_num)
        i3c_baddr=`I3C1_BASE;
    else
        i3c_baddr=`I3C0_BASE;


    case(speed)
        0:begin
        i3c_pp_lcnt = 'h7;
        i3c_pp_hcnt = 'h9;
        i3c_od_lcnt = 'h9;
        //1.SCL_I3C_OD_TIMING
        wdata[23:16]='ha;
        wdata[7:0]= i3c_od_lcnt;
        noc_reg_write(i3c_baddr+`SCL_I3C_OD_TIMING, wdata );

        //2.SCL_I3C_PP_TIMING
        wdata='h0;
        wdata[23:16]=i3c_pp_hcnt;
        wdata[7:0]=i3c_pp_lcnt;
        noc_reg_write(i3c_baddr+`SCL_I3C_PP_TIMING, wdata );
        end
        1:begin
        i3c_ext_lcnt_1 = 'hd;
        wdata='h0;
        wdata[7:0] =i3c_ext_lcnt_1;
        noc_reg_write(i3c_baddr+`SCL_EXT_LCNT_TIMING, wdata );

        end
        2:begin
        i3c_ext_lcnt_2 = 'h11;
        wdata='h0;
        wdata[15:8] =i3c_ext_lcnt_2;
        noc_reg_write(i3c_baddr+`SCL_EXT_LCNT_TIMING, wdata );
        end
        3:begin
        i3c_ext_lcnt_3 = 'h19;
        wdata='h0;
        wdata[23:16] =i3c_ext_lcnt_3;
        noc_reg_write(i3c_baddr+`SCL_EXT_LCNT_TIMING, wdata );
        end
        4:begin
        i3c_ext_lcnt_4 = 'h32;
        wdata='h0;
        wdata[31:24] =i3c_ext_lcnt_4;
        noc_reg_write(i3c_baddr+`SCL_EXT_LCNT_TIMING, wdata );
    end
    endcase


/*     //3.BUS_FREE_AVAIL_TIMING
     wdata='h0;
     wdata[15:0]='h;
     noc_reg_write(`I3C0_BASE+`BUS_FREE_AVAIL_TIMING, wdata );

     //4.SCL_I2C_FMP_TIMING
     wdata='h0;
     wdata[23:16]='h;
     wdata[15:0]='h;
     noc_reg_write(`I3C0_BASE+`SCL_I2C_FMP_TIMING, wdata );

     //5.SCL_I2C_FM_TIMING
     wdata='h0;
     wdata[31:16]='h;
     wdata[15:0]='h;
     noc_reg_write(`I3C0_BASE+`SCL_I2C_FM_TIMING, wdata );

     //6.BUS_IDLE_TIMING
     wdata='h0;
     wdata[19:0]='h;
     noc_reg_write(`I3C0_BASE+`BUS_IDLE_TIMING, wdata );


     //7.SCL_EXT_LCNT_TIMING
     wdata='h0;
     case(sdr_speed)
     1: wdata[7:0]='h;
     2: wdata[15:8]='h;
     3: wdata[23:16]='h;
     4: wdata[31:24]='h;
     default: ;
     endcase
     wdata[7:0]='h;
     wdata[15:8]='h;
     wdata[23:16]='h;
     wdata[31:24]='h;
     noc_reg_write(`I3C0_BASE+`SCL_EXT_LCNT_TIMING, wdata );

     //8.SCL_EXT_TERMN_LCNT_TIMING[I3C_EXT_TERMN_LCNT]
     wdata='h0;
     wdata[3:0]='h;
     noc_reg_write(`I3C0_BASE+`SCL_EXT_TERMN_LCNT_TIMING, wdata );

     //9.SCL_EXT_TERMN_LCNT_TIMING[I3C_TS_SKEW_CNT]
     noc_reg_read(`I3C0_BASE+`SCL_EXT_TERMN_LCNT_TIMING, rdata);
     rdata[19:16]='h;
     noc_reg_write(`I3C0_BASE+`SCL_EXT_TERMN_LCNT_TIMING, rdata );

     //10.SDA_HOLD_DLY_TIMING.SDA_TX_HOLD
     wdata='h0;
     wdata[18:16]='h;
     noc_reg_write(`I3C0_BASE+`SDA_HOLD_DLY_TIMING, wdata ); */

 endtask
//------------------------------------------------------------------------------------------------
/*  task i3c_base_test::i3c_set_dev_addr_tbl(input bit leg_i2c, input bit[6:0] dev_addr);
      bit[31:0] wdata;
      bit leg_i2c;
      bit[7:0] dev_dynamic_addr;
      bit[6:0] dev_static_addr;

      if(leg_i2c) wdata[31]=1'b1;
      wdata[6:0] = dev_static_addr;
      wdata[23:16] = dev_dynamic_addr;

      noc_reg_write(`I3C0_BASE+`DEV_ADDR_TABLE_LOC1, wdata );

  endtask
  */
 //----------------------------------------------------------------------------------------------
 task i3c_base_test::i3c_dma_write_config(bit[31:0] src_addr,bit[31:0] dst_addr,bit[6:0] dst_per_num,[8:0] arlengh,[8:0] awlengh);

 	mcu_dma_transfer_virt_sequence  i3c_dma_seq;
    i3c_dma_seq = mcu_dma_transfer_virt_sequence::type_id::create("i3c_dma_seq");
	i3c_dma_seq.is_init = 1'b1;

    i3c_dma_seq.randomize() with  {	src_addr == local::src_addr;
                               dst_addr == local::dst_addr;
                               sinc == 1'b0; // 1: Fixed Addr
                               dinc == 1'b1;
                               block_ts == 'h1; // 2 x 32-bit beats for current TX DMA data list
                               src_tr_width == 3'h2;//0 : 8bit  1 : 16bit  2 : 32bit   3 : 64bit
                               dst_tr_width == 3'h2;//0 : 8bit  1 : 16bit  2 : 32bit   3 : 64bit
                               src_msize == 4'h1;//source burst transaction total length
                               dst_msize == 4'h1; //destination burst transaction length
                               arlen == arlengh;// burst num
                               awlen == awlengh;
                               tt_fc == 3'h1; // 1: m2p 2:p2m
                               hs_sel_src == 1'b0; // 0: Hardware handshaking
                               hs_sel_dst == 1'b0;
							   src_per ==6'h0;
							   dst_per ==dst_per_num; // dma req num;
                              };

	i3c_dma_seq.start(m_env.v_sqr);

endtask:i3c_dma_write_config

//-----------------------------------------------------------------------
task i3c_base_test::i3c_dma_read_config(bit[31:0] src_addr,bit[31:0] dst_addr,bit[6:0] src_per_num,[8:0] arlengh,[8:0] awlengh);

 	mcu_dma_transfer_virt_sequence  i3c_dma_seq;
    i3c_dma_seq = mcu_dma_transfer_virt_sequence::type_id::create("i3c_dma_seq");
	i3c_dma_seq.is_init = 1'b1;
    i3c_dma_seq.randomize() with  {src_addr == local::src_addr;
                               dst_addr == local::dst_addr;
                               sinc == 1'b1; // 1: Fixed Addr
                               dinc == 1'b0;
                               block_ts == 64'h0;
                               src_tr_width == 3'h2;//0 : 8bit  1 : 16bit  2 : 32bit   3 : 64bit
                               dst_tr_width == 3'h2;//0 : 8bit  1 : 16bit  2 : 32bit   3 : 64bit
                               src_msize == 4'h0;//source burst transaction length
                               dst_msize == 4'h0; //destination burst transaction length
                               arlen == arlengh;
                               awlen == awlengh;
                               tt_fc == 3'h2; // 1: m2p 2:p2m
                               hs_sel_src == 1'b0; // 0: Hardware handshaking
                               hs_sel_dst == 1'b0;
							   src_per ==src_per_num ;//6'h1f;
							   dst_per ==6'h0;
                              };

	i3c_dma_seq.start(m_env.v_sqr);

endtask:i3c_dma_read_config
//------------------------------------------------------------------------
//------------------------------------------------------------------------
task i3c_base_test::i3c_fill_memory(input bit[39:0] mem_addr, input bit[31:0] wdata_arr[]);
    for(int i=0;i < wdata_arr.size(); i++)
    sram_wr32_bd(mem_addr + i*4, wdata_arr[i]);

endtask:i3c_fill_memory

`endif
