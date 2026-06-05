`timescale 1ns/1ps
`include "connect/connect_modes.svh"

module i2c_tb;
  import uvm_pkg::*;
`include "uvm_macros.svh"
`ifdef BMS_USE_SVT_VIP
  import svt_uvm_pkg::*;
  import svt_mem_uvm_pkg::*;
  import svt_axi_uvm_pkg::*;
  import svt_ahb_uvm_pkg::*;
  import svt_apb_uvm_pkg::*;
`endif
  import base_test_pkg::*;
`ifdef BMS_USE_SVT_VIP
  import svt_i2c_uvm_pkg::*;
  import svt_i2c_enum_pkg::*;
`endif

  logic clk;
  logic pclk;
  logic ic_clk;
  bit i2c_ref_clk;
  i2c_if tb_if(clk);
  int connect_scene;
  int i2c_oe_active_low = -1;
  bit i2c_oe_learned = 1'b0;
  logic i2c_scl_release_oe = 1'b1;
  logic i2c_sda_release_oe = 1'b1;
  wire i2c_dut_scl_drive_low;
  wire i2c_dut_sda_drive_low;
  localparam bit i2c_dut_pad_ack_bridge_drive_low = 1'b0;

  function automatic bit i2c_oe_is_known(logic oe);
    return ((oe === 1'b0) || (oe === 1'b1));
  endfunction

  function automatic bit i2c_oe_drives_low(logic oe, logic release_oe);
    if (!i2c_oe_is_known(oe)) begin
      return 1'b0;
    end
    if (i2c_oe_active_low < 0) begin
      return (i2c_oe_learned && (oe !== release_oe));
    end
    return (i2c_oe_active_low != 0) ? (oe === 1'b0) : (oe === 1'b1);
  endfunction

`ifdef BMS_USE_SVT_VIP
  svt_i2c_if i2c_vif(i2c_ref_clk);
  svt_i2c_master_wrapper i2c_vip_master_wrapper(i2c_vif);
  svt_i2c_slave_wrapper i2c_vip_slave_wrapper(i2c_vif);

  svt_apb_if apb_dut_master_if();
  virtual svt_apb_if apb_dut_master_vif;

  svt_apb_if apb_dut_slave_if();
  virtual svt_apb_if apb_dut_slave_vif;

  svt_axi_if axi_dut_if();
  virtual svt_axi_if axi_dut_vif;

  svt_ahb_if ahb_dut_if();
  virtual svt_ahb_if ahb_dut_vif;

  uvm_sequencer_base apb_vip_sqr_m0;
  uvm_sequencer_base ahb_vip_sqr_m0;
  uvm_sequencer_base axi_vip_sqr_m0;
  uvm_sequencer_base i2c_vip_slv_sqr0;
  uvm_sequencer_base i2c_vip_mst_sqr0;
`endif

`ifdef BMS_USE_SVT_VIP
  assign i2c_vif.RST = ~tb_if.ic_rst_n;
  assign tb_if.ic_clk_in_a  = (i2c_vif.SCL === 1'b0) ? 1'b0 : 1'b1;
  assign tb_if.ic_data_in_a = (i2c_vif.SDA === 1'b0) ? 1'b0 : 1'b1;
  assign i2c_vif.SCL = i2c_dut_scl_drive_low ? 1'b0 : 1'bz;
  assign i2c_vif.SDA = i2c_dut_sda_drive_low ? 1'b0 : 1'bz;
`else
  wire ic_scl_bus;
  wire ic_sda_bus;
  pullup(ic_scl_bus);
  pullup(ic_sda_bus);
  assign ic_scl_bus = i2c_dut_scl_drive_low ? 1'b0 : 1'bz;
  assign ic_sda_bus = i2c_dut_sda_drive_low ? 1'b0 : 1'bz;
  assign tb_if.ic_clk_in_a  = (ic_scl_bus === 1'b0) ? 1'b0 : 1'b1;
  assign tb_if.ic_data_in_a = (ic_sda_bus === 1'b0) ? 1'b0 : 1'b1;
`endif

  assign i2c_dut_scl_drive_low = (tb_if.ic_rst_n === 1'b1) &&
                                 i2c_oe_drives_low(tb_if.ic_clk_oe, i2c_scl_release_oe);
  assign i2c_dut_sda_drive_low = (tb_if.ic_rst_n === 1'b1) &&
                                 i2c_oe_drives_low(tb_if.ic_data_oe, i2c_sda_release_oe);

  MCU_I2C_WRAPPER u_dut (
`ifdef BMS_USE_SVT_VIP
    .pclk             (apb_dut_master_if.pclk),
    .presetn          (apb_dut_master_if.presetn),
    .psel             (apb_dut_master_if.psel),
    .penable          (apb_dut_master_if.penable),
    .pprot            (apb_dut_master_if.pprot),
    .pstrb            (apb_dut_master_if.pstrb),
    .pready           (apb_dut_master_if.pready[0]),
    .pslverr          (apb_dut_master_if.pslverr[0]),
    .prdata           (apb_dut_master_if.prdata[0]),
    .pwrite           (apb_dut_master_if.pwrite),
    .paddr            (apb_dut_master_if.paddr),
    .pwdata           (apb_dut_master_if.pwdata),
`else
    .pclk             (tb_if.pclk),
    .presetn          (tb_if.presetn),
    .psel             (tb_if.psel),
    .penable          (tb_if.penable),
    .pprot            (tb_if.pprot),
    .pstrb            (tb_if.pstrb),
    .pready           (tb_if.pready),
    .pslverr          (tb_if.pslverr),
    .prdata           (tb_if.prdata),
    .pwrite           (tb_if.pwrite),
    .paddr            (tb_if.paddr),
    .pwdata           (tb_if.pwdata),
`endif
    .ic_clk           (tb_if.ic_clk),
    .ic_rst_n         (tb_if.ic_rst_n),
    .ic_current_src_en(tb_if.ic_current_src_en),
    .ic_clk_in_a      (tb_if.ic_clk_in_a),
    .ic_clk_oe        (tb_if.ic_clk_oe),
    .ic_data_in_a     (tb_if.ic_data_in_a),
    .ic_data_oe       (tb_if.ic_data_oe),
    .ic_intr          (tb_if.ic_intr),
    .ic_en            (tb_if.ic_en)
  );

`include "connect/connect_apply.svh"

  initial begin
    clk = 1'b0;
    forever #5 clk = ~clk;
  end

  initial begin
    pclk = 1'b0;
    forever #(tb_if.pclk_half_period_ns) pclk = ~pclk;
  end

  initial begin
    ic_clk = 1'b0;
    forever #(tb_if.ic_clk_half_period_ns) ic_clk = ~ic_clk;
  end

  initial begin
    #0.5;
    i2c_ref_clk = 1'b0;
    forever #0.5 i2c_ref_clk = ~i2c_ref_clk;
  end

  initial begin
    tb_if.rst_n = 1'b0;
    tb_if.presetn = 1'b0;
    tb_if.pprot = '0;
    tb_if.pstrb = 4'hf;
    tb_if.ic_rst_n = 1'b0;
    repeat (5) @(posedge clk);
    tb_if.rst_n = 1'b1;
    tb_if.presetn = 1'b1;
    tb_if.ic_rst_n = 1'b1;
  end

  assign tb_if.pclk = pclk;
  assign tb_if.ic_clk = ic_clk;

`ifdef BMS_USE_SVT_VIP
  assign apb_dut_master_if.pclk = pclk;
  assign apb_dut_master_if.presetn = tb_if.presetn;
`endif

  initial begin
`ifdef BMS_USE_SVT_VIP
    $display("[TB_I2C_BRIDGE] t=%0t compile_guard BMS_USE_SVT_VIP=1 top=%m", $time);
`else
    $display("[TB_I2C_BRIDGE] t=%0t compile_guard BMS_USE_SVT_VIP=0 top=%m", $time);
`endif
  end

  initial begin
    connect_scene = CONNECT_SCENE_DIRECT;
    i2c_oe_active_low = -1;
    void'($value$plusargs("CONNECT_SCENE=%d", connect_scene));
    void'($value$plusargs("I2C_OE_ACTIVE_LOW=%d", i2c_oe_active_low));
    $display("[TB] CONNECT_SCENE=%0d", connect_scene);
    if (i2c_oe_active_low < 0) begin
      $display("[TB] I2C_OE_ACTIVE_LOW=auto");
    end else begin
      i2c_scl_release_oe = (i2c_oe_active_low != 0) ? 1'b1 : 1'b0;
      i2c_sda_release_oe = (i2c_oe_active_low != 0) ? 1'b1 : 1'b0;
      i2c_oe_learned = 1'b1;
      $display("[TB] I2C_OE_ACTIVE_LOW=%0d release_oe=%0b",
               i2c_oe_active_low, i2c_scl_release_oe);
    end
`ifdef BMS_USE_SVT_VIP
    i2c_vif.enable_pullup_resistor = 1'b1;
    $display("[TB] I2C SVT reference clock period is 1ns, pullup=%0b",
             i2c_vif.enable_pullup_resistor);
`endif
    if (i2c_oe_active_low < 0) begin
      wait (tb_if.ic_rst_n === 1'b1);
      wait (i2c_oe_is_known(tb_if.ic_clk_oe) && i2c_oe_is_known(tb_if.ic_data_oe));
      #1;
      i2c_scl_release_oe = tb_if.ic_clk_oe;
      i2c_sda_release_oe = tb_if.ic_data_oe;
      i2c_oe_learned = 1'b1;
      $display("[TB_I2C_BRIDGE] t=%0t learned idle release OE: scl=%0b sda=%0b",
               $time, i2c_scl_release_oe, i2c_sda_release_oe);
    end
  end

`ifdef BMS_USE_SVT_VIP
  initial begin
    int sample_count;
    $display("[TB_I2C_BRIDGE] t=%0t boot compiled with BMS_USE_SVT_VIP, ic_rst_n=%b SCL=%b SDA=%b pullup=%0b",
             $time, tb_if.ic_rst_n, i2c_vif.SCL, i2c_vif.SDA, i2c_vif.enable_pullup_resistor);
    repeat (4) begin
      @(posedge i2c_ref_clk);
      $display("[TB_I2C_BRIDGE] t=%0t pre_reset_sample oe_active_low=%0d oe_learned=%0b release_scl=%b release_sda=%b ic_rst_n=%b ic_clk_oe=%b ic_data_oe=%b drive_scl_low=%b drive_sda_low=%b i2c_vif.SCL=%b i2c_vif.SDA=%b pullup=%0b",
               $time, i2c_oe_active_low, i2c_oe_learned, i2c_scl_release_oe, i2c_sda_release_oe,
               tb_if.ic_rst_n, tb_if.ic_clk_oe, tb_if.ic_data_oe,
               i2c_dut_scl_drive_low, i2c_dut_sda_drive_low,
               i2c_vif.SCL, i2c_vif.SDA, i2c_vif.enable_pullup_resistor);
    end
    wait (tb_if.ic_rst_n === 1'b1);
    $display("[TB_I2C_BRIDGE] t=%0t reset_done oe_active_low=%0d oe_learned=%0b release_scl=%b release_sda=%b ic_rst_n=%b ic_clk_oe=%b ic_data_oe=%b drive_scl_low=%b drive_sda_low=%b i2c_vif.SCL=%b i2c_vif.SDA=%b pullup=%0b",
             $time, i2c_oe_active_low, i2c_oe_learned, i2c_scl_release_oe, i2c_sda_release_oe,
             tb_if.ic_rst_n, tb_if.ic_clk_oe, tb_if.ic_data_oe,
             i2c_dut_scl_drive_low, i2c_dut_sda_drive_low,
             i2c_vif.SCL, i2c_vif.SDA, i2c_vif.enable_pullup_resistor);
    if ($test$plusargs("I2C_BRIDGE_TRACE")) begin
      forever begin
        fork
          @(tb_if.ic_clk_oe or tb_if.ic_data_oe or i2c_vif.SCL or i2c_vif.SDA);
          repeat (100) @(posedge i2c_ref_clk);
        join_any
        disable fork;
        if (sample_count < 32) begin
          $display("[TB_I2C_BRIDGE] t=%0t ref_clk=%b oe_active_low=%0d oe_learned=%0b release_scl=%b release_sda=%b ic_clk_oe=%b ic_data_oe=%b drive_scl_low=%b drive_sda_low=%b i2c_vif.SCL=%b i2c_vif.SDA=%b pullup=%0b",
                   $time, i2c_ref_clk, i2c_oe_active_low, i2c_oe_learned,
                   i2c_scl_release_oe, i2c_sda_release_oe, tb_if.ic_clk_oe, tb_if.ic_data_oe,
                   i2c_dut_scl_drive_low, i2c_dut_sda_drive_low,
                   i2c_vif.SCL, i2c_vif.SDA, i2c_vif.enable_pullup_resistor);
          sample_count++;
        end
      end
    end else begin
      $display("[TB_I2C_BRIDGE] t=%0t periodic bridge trace disabled; use +I2C_BRIDGE_TRACE to enable it",
               $time);
    end
  end
`endif

`ifdef BMS_USE_SVT_VIP
  initial begin
    int trace_count;
    int max_traces;
    int ack_trace_events;
    int ack_event_count;
    int ack_high_event_count;
    bit [7:0] addr_byte;
    bit [7:0] dut_addr_byte;
    bit ack_bit;
    bit detail_trace;
    string ack_text;

    if ($test$plusargs("I2C_ADDR_TRACE")) begin
      max_traces = 8;
      ack_trace_events = 32;
      void'($value$plusargs("I2C_ADDR_TRACE_MAX=%d", max_traces));
      void'($value$plusargs("I2C_ACK_TRACE_EVENTS=%d", ack_trace_events));
      detail_trace = $test$plusargs("I2C_ADDR_TRACE_DETAIL");
      wait (tb_if.ic_rst_n === 1'b1);
      forever begin
        @(negedge i2c_vif.SDA);
        if (i2c_vif.SCL !== 1'b1) begin
          continue;
        end
        #0;
        if (detail_trace) begin
          $display("[TB_I2C_ADDR_START] t=%0t SCL=%b SDA=%b dut_scl_in=%b dut_sda_in=%b ic_en=%b ic_clk_oe=%b ic_data_oe=%b drive_scl_low=%b drive_sda_low=%b ack_bridge=%b",
                   $time, i2c_vif.SCL, i2c_vif.SDA, tb_if.ic_clk_in_a,
                   tb_if.ic_data_in_a, tb_if.ic_en, tb_if.ic_clk_oe,
                   tb_if.ic_data_oe, i2c_dut_scl_drive_low,
                   i2c_dut_sda_drive_low,
                   i2c_dut_pad_ack_bridge_drive_low);
        end

        for (int bit_idx = 7; bit_idx >= 0; bit_idx--) begin
          @(posedge i2c_vif.SCL);
          #0;
          addr_byte[bit_idx] = (i2c_vif.SDA === 1'b0) ? 1'b0 : 1'b1;
          dut_addr_byte[bit_idx] = (tb_if.ic_data_in_a === 1'b0) ? 1'b0 : 1'b1;
          if (detail_trace) begin
            $display("[TB_I2C_ADDR_BIT] t=%0t bit=%0d bus_sda=%b dut_sda_in=%b SCL=%b dut_scl_in=%b ic_data_oe=%b drive_sda_low=%b ack_bridge=%b",
                     $time, bit_idx, i2c_vif.SDA, tb_if.ic_data_in_a,
                     i2c_vif.SCL, tb_if.ic_clk_in_a, tb_if.ic_data_oe,
                     i2c_dut_sda_drive_low,
                     i2c_dut_pad_ack_bridge_drive_low);
          end
        end

        @(negedge i2c_vif.SCL);
        #0;
        if (detail_trace) begin
          ack_event_count = 0;
          $display("[TB_I2C_ACK_LOW_BEGIN] t=%0t addr_byte=0x%02h dut_addr_byte=0x%02h SCL=%b SDA=%b dut_sda_in=%b ic_data_oe=%b drive_sda_low=%b ack_bridge=%b",
                   $time, addr_byte, dut_addr_byte, i2c_vif.SCL,
                   i2c_vif.SDA, tb_if.ic_data_in_a, tb_if.ic_data_oe,
                   i2c_dut_sda_drive_low,
                   i2c_dut_pad_ack_bridge_drive_low);
          fork
            begin
              @(posedge i2c_vif.SCL);
            end
            begin
              forever begin
                @(tb_if.ic_data_oe or i2c_dut_sda_drive_low or
                  i2c_vif.SDA or tb_if.ic_data_in_a);
                #0;
                if (ack_event_count < ack_trace_events) begin
                  $display("[TB_I2C_ACK_LOW_EVT] t=%0t event=%0d SCL=%b SDA=%b dut_sda_in=%b ic_data_oe=%b drive_sda_low=%b ack_bridge=%b release_sda=%b oe_active_low=%0d",
                           $time, ack_event_count, i2c_vif.SCL, i2c_vif.SDA,
                           tb_if.ic_data_in_a, tb_if.ic_data_oe,
                           i2c_dut_sda_drive_low,
                           i2c_dut_pad_ack_bridge_drive_low,
                           i2c_sda_release_oe,
                           i2c_oe_active_low);
                  ack_event_count++;
                end
              end
            end
          join_any
          disable fork;
        end else begin
          @(posedge i2c_vif.SCL);
        end
        #0;
        ack_bit = (i2c_vif.SDA === 1'b0) ? 1'b0 : 1'b1;
        ack_text = (ack_bit === 1'b0) ? "ACK" : "NACK";
        $display("[TB_I2C_ADDR_TRACE] t=%0t addr_byte=0x%02h addr7=0x%02h rw=%0b dut_addr_byte=0x%02h dut_addr7=0x%02h dut_rw=%0b ack_sda=%0b %s ic_en=%b ic_clk_oe=%b ic_data_oe=%b drive_sda_low=%b ack_bridge=%b SCL=%b SDA=%b dut_sda_in=%b",
                 $time, addr_byte, addr_byte[7:1], addr_byte[0],
                 dut_addr_byte, dut_addr_byte[7:1], dut_addr_byte[0],
                 ack_bit, ack_text, tb_if.ic_en, tb_if.ic_clk_oe,
                 tb_if.ic_data_oe, i2c_dut_sda_drive_low,
                 i2c_dut_pad_ack_bridge_drive_low, i2c_vif.SCL, i2c_vif.SDA,
                 tb_if.ic_data_in_a);
        if (detail_trace) begin
          fork
            begin
              @(negedge i2c_vif.SCL);
            end
            begin
              ack_high_event_count = 0;
              forever begin
                @(tb_if.ic_data_oe or i2c_dut_sda_drive_low or
                  i2c_vif.SDA or tb_if.ic_data_in_a);
                #0;
                if (ack_high_event_count < ack_trace_events) begin
                  $display("[TB_I2C_ACK_HIGH_EVT] t=%0t event=%0d SCL=%b SDA=%b dut_sda_in=%b ic_data_oe=%b drive_sda_low=%b ack_bridge=%b release_sda=%b oe_active_low=%0d",
                           $time, ack_high_event_count, i2c_vif.SCL,
                           i2c_vif.SDA, tb_if.ic_data_in_a, tb_if.ic_data_oe,
                           i2c_dut_sda_drive_low,
                           i2c_dut_pad_ack_bridge_drive_low,
                           i2c_sda_release_oe,
                           i2c_oe_active_low);
                  ack_high_event_count++;
                end
              end
            end
          join_any
          disable fork;
        end

        trace_count++;
        if (trace_count >= max_traces) begin
          break;
        end
      end
    end
  end
`endif

  initial begin
    uvm_config_db#(virtual i2c_if)::set(null, "uvm_test_top", "vif", tb_if);
`ifdef BMS_USE_SVT_VIP
    apb_dut_master_vif = apb_dut_master_if;
    apb_dut_slave_vif = apb_dut_slave_if;
    ahb_dut_vif = ahb_dut_if;
    axi_dut_vif = axi_dut_if;

    uvm_config_db#(svt_ahb_vif)::set(uvm_root::get(), "uvm_test_top.ahb_env.ahb_system_env", "vif", ahb_dut_vif);
    uvm_config_db#(svt_apb_vif)::set(uvm_root::get(), "uvm_test_top.apb_env.apb_master_env", "vif", apb_dut_master_vif);
    uvm_config_db#(svt_apb_vif)::set(uvm_root::get(), "uvm_test_top.apb_env.apb_slave_env", "vif", apb_dut_slave_vif);
    uvm_config_db#(svt_axi_vif)::set(uvm_root::get(), "uvm_test_top.axi_env.axi_system_env", "vif", axi_dut_vif);

    uvm_config_db#(virtual svt_i2c_if)::set(uvm_root::get(), "uvm_test_top.i2c_vip_env", "vif", i2c_vif);
    uvm_config_db#(uvm_sequencer_base)::set(null, "uvm_test_top", "apb_vip_sqr_m0", apb_vip_sqr_m0);
    uvm_config_db#(uvm_sequencer_base)::set(null, "uvm_test_top", "ahb_vip_sqr_m0", ahb_vip_sqr_m0);
    uvm_config_db#(uvm_sequencer_base)::set(null, "uvm_test_top", "axi_vip_sqr_m0", axi_vip_sqr_m0);
    uvm_config_db#(uvm_sequencer_base)::set(null, "uvm_test_top", "i2c_vip_slv_sqr0", i2c_vip_slv_sqr0);
    uvm_config_db#(uvm_sequencer_base)::set(null, "uvm_test_top", "i2c_vip_mst_sqr0", i2c_vip_mst_sqr0);
`endif
    run_test();
  end
endmodule
