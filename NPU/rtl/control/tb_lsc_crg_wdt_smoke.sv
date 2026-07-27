module tb_lsc_crg_wdt_smoke;
  import npu_rtl_pkg::*;

  logic clk;
  logic noc_clk;
  logic reset_n;
  logic sync_reset_n;

  logic reg_req_valid;
  logic reg_req_ready;
  logic reg_req_write;
  logic [15:0] reg_req_addr;
  logic [63:0] reg_req_wdata;
  logic [7:0] reg_req_wstrb;
  logic reg_rsp_valid;
  logic [63:0] reg_rsp_rdata;
  logic [1:0] reg_rsp_status;

  logic accept_new_cmd;
  logic power_down_ack;
  logic cfe_quiesce;
  logic ts_quiesce;
  logic [3:0] eng_abort;
  logic single_step_pulse;
  logic soft_reset_req;
  logic internal_soft_reset_done;
  logic soft_reset_done;
  logic internal_soft_reset_pulse;
  logic lsc_core_idle;
  logic task_terminal_valid;
  logic task_terminal_ready;
  logic [11:0] task_command_id;
  logic [3:0] task_engine;
  logic [7:0] task_opcode;
  logic [7:0] task_status;
  logic [47:0] task_fault_addr;
  logic irq_error;
  logic interface_error_clear;
  logic lsc_wdt_enable;
  logic [31:0] lsc_wdt_timeout_cycles;
  logic lsc_wdt_kick;
  logic irq_done;
  logic irq_exception;
  logic [47:0] input_base;
  logic [47:0] weight_base;
  logic [47:0] work_base;
  logic [47:0] output_base;
  logic [47:0] kv_base;
  logic [47:0] m_axi_addr_base;
  logic [47:0] m_axi_addr_limit;
  logic [19:0] param_l1_base;
  logic [19:0] param_l1_limit;
  logic param_lock;
  logic l1_host_access_enable;
  logic [7:0] lsc_module_clk_enable;

  logic wdt_enable;
  logic [31:0] wdt_timeout_cycles;
  logic wdt_kick;
  logic wdt_progress;
  logic wdt_timeout;
  logic wdt_reset_req;

  logic dvfs_req;
  logic dvfs_ack;
  logic [7:0] module_clk_en;
  logic [7:0] module_idle;
  logic [7:0] module_clk_active;
  logic core_reset_n;
  logic noc_reset_n;
  logic core_clk_gated;
  logic noc_clk_gated;

  always #5 clk = ~clk;
  always #7 noc_clk = ~noc_clk;

  npu_lsc u_lsc (
    .clk_i(clk),
    .reset_n(sync_reset_n),
    .reg_req_valid_i(reg_req_valid),
    .reg_req_ready_o(reg_req_ready),
    .reg_req_write_i(reg_req_write),
    .reg_req_space_i(1'b0),
    .reg_req_addr_i(reg_req_addr),
    .reg_req_wdata_i(reg_req_wdata),
    .reg_req_wstrb_i(reg_req_wstrb),
    .reg_rsp_valid_o(reg_rsp_valid),
    .reg_rsp_ready_i(1'b1),
    .reg_rsp_rdata_o(reg_rsp_rdata),
    .reg_rsp_status_o(reg_rsp_status),
    .cmd_ingress_idle_i(1'b1),
    .cfe_idle_i(1'b1),
    .ts_idle_i(1'b1),
    .ts_quiescent_i(1'b1),
    .eng_quiescent_i(4'hf),
    .l1_idle_i(1'b1),
    .l1_write_idle_i(1'b1),
    .mif_idle_i(1'b1),
    .s_axi_idle_i(1'b1),
    .soft_reset_req_i(soft_reset_req),
    .internal_soft_reset_done_i(internal_soft_reset_done),
    .power_down_req_i(1'b0),
    .soft_reset_done_o(soft_reset_done),
    .power_down_ack_o(power_down_ack),
    .accept_new_cmd_o(accept_new_cmd),
    .cfe_quiesce_o(cfe_quiesce),
    .ts_quiesce_o(ts_quiesce),
    .eng_abort_o(eng_abort),
    .single_step_pulse_o(single_step_pulse),
    .internal_soft_reset_pulse_o(internal_soft_reset_pulse),
    .core_idle_o(lsc_core_idle),
    .task_terminal_valid_i(task_terminal_valid),
    .task_terminal_ready_o(task_terminal_ready),
    .task_command_id_i(task_command_id),
    .task_engine_i(task_engine),
    .task_opcode_i(task_opcode),
    .task_status_i(task_status),
    .task_fault_addr_i(task_fault_addr),
    .task_irq_on_success_i(1'b0),
    .task_irq_on_error_i(1'b1),
    .interface_error_valid_i(1'b0),
    .interface_error_status_i(NPU_STATUS_BAD_DESC),
    .interface_error_addr_i(48'd0),
    .interface_error_clear_o(interface_error_clear),
    .wdt_timeout_i(1'b0),
    .wdt_enable_o(lsc_wdt_enable),
    .wdt_timeout_cycles_o(lsc_wdt_timeout_cycles),
    .wdt_kick_o(lsc_wdt_kick),
    .irq_done_o(irq_done),
    .irq_exception_o(irq_exception),
    .irq_error_o(irq_error),
    .input_base_o(input_base),
    .weight_base_o(weight_base),
    .work_base_o(work_base),
    .output_base_o(output_base),
    .kv_base_o(kv_base),
    .m_axi_addr_base_o(m_axi_addr_base),
    .m_axi_addr_limit_o(m_axi_addr_limit),
    .param_l1_base_o(param_l1_base),
    .param_l1_limit_o(param_l1_limit),
    .param_lock_o(param_lock),
    .l1_host_access_enable_o(l1_host_access_enable),
    .module_clk_enable_o(lsc_module_clk_enable)
  );

  npu_wdt u_wdt (
    .clk_i(clk),
    .reset_n(sync_reset_n),
    .wdt_enable_i(wdt_enable),
    .wdt_timeout_cycles_i(wdt_timeout_cycles),
    .wdt_kick_i(wdt_kick),
    .wdt_core_progress_i(wdt_progress),
    .wdt_timeout_o(wdt_timeout),
    .wdt_reset_req_o(wdt_reset_req)
  );

  npu_crg u_crg (
    .core_clk_i(clk),
    .noc_clk_i(noc_clk),
    .reset_n(reset_n),
    .dvfs_prepare_req_i(dvfs_req),
    .dvfs_prepare_ack_o(dvfs_ack),
    .core_idle_i(1'b1),
    .axi_idle_i(1'b1),
    .module_clk_en_i(module_clk_en),
    .module_idle_i(module_idle),
    .module_clk_active_o(module_clk_active),
    .core_clk_gated_o(core_clk_gated),
    .noc_clk_gated_o(noc_clk_gated),
    .core_reset_n_o(core_reset_n),
    .noc_reset_n_o(noc_reset_n)
  );

  task automatic csr_access(
    input logic write_access,
    input logic [15:0] address,
    input logic [63:0] write_data,
    output logic [63:0] read_data,
    output logic [1:0] response_status
  );
    begin
      @(negedge clk);
      reg_req_write = write_access;
      reg_req_addr  = address;
      reg_req_wdata = write_data;
      reg_req_wstrb = 8'hff;
      reg_req_valid = 1'b1;
      while (!reg_req_ready) @(negedge clk);
      @(posedge clk);
      @(negedge clk);
      reg_req_valid  = 1'b0;
      reg_req_write  = 1'b0;
      reg_req_addr   = 16'd0;
      reg_req_wdata  = 64'd0;
      wait (reg_rsp_valid);
      read_data       = reg_rsp_rdata;
      response_status = reg_rsp_status;
      @(posedge clk);
      @(negedge clk);
    end
  endtask

  initial begin
    logic [63:0] read_data;
    logic [1:0] response_status;

    clk                      = 1'b0;
    noc_clk                  = 1'b0;
    reset_n                  = 1'b0;
    sync_reset_n             = 1'b0;
    reg_req_valid            = 1'b0;
    reg_req_write            = 1'b0;
    reg_req_addr             = 16'd0;
    reg_req_wdata            = 64'd0;
    reg_req_wstrb            = 8'd0;
    soft_reset_req           = 1'b0;
    internal_soft_reset_done = 1'b0;
    task_terminal_valid      = 1'b0;
    task_command_id          = 12'd0;
    task_engine              = 4'd0;
    task_opcode              = 8'd0;
    task_status              = NPU_STATUS_SUCCESS;
    task_fault_addr          = 48'd0;
    wdt_enable               = 1'b0;
    wdt_timeout_cycles       = 32'd0;
    wdt_kick                 = 1'b0;
    wdt_progress             = 1'b0;
    dvfs_req                 = 1'b0;
    module_clk_en            = 8'd0;
    module_idle              = 8'hff;

    repeat (4) @(posedge clk);
    reset_n = 1'b1;
    sync_reset_n = 1'b1;
    repeat (4) @(posedge clk);

    if (!core_reset_n || !noc_reset_n
        || (module_clk_active != 8'd0)) begin
      $fatal(1, "CRG reset release or idle clock selection failed");
    end
    dvfs_req = 1'b1;
    #1;
    if (!dvfs_ack) begin
      $fatal(1, "CRG did not acknowledge an idle DVFS request");
    end
    dvfs_req = 1'b0;

    csr_access(1'b1, 16'h0058, 64'h0000_0000_0000_1000,
               read_data, response_status);
    if ((response_status != 2'b00) || (input_base != 48'h1000)) begin
      $fatal(1, "LSC input base write failed");
    end
    csr_access(1'b0, 16'h0058, 64'd0, read_data, response_status);
    if ((response_status != 2'b00)
        || (read_data != 64'h0000_0000_0000_1000)) begin
      $fatal(1, "LSC input base readback failed");
    end
    csr_access(1'b1, 16'h0058, 64'h0000_0100_0000_0000,
               read_data, response_status);
    if ((response_status != 2'b10) || (input_base != 48'h1000)) begin
      $fatal(1, "LSC accepted a physical base address with bit 40 set");
    end
    if (m_axi_addr_limit != 48'h00ff_ffff_fff8) begin
      $fatal(1, "LSC physical address limit reset value is incorrect");
    end
    csr_access(1'b1, 16'h0090, 64'hdead_beef_cafe_5a5a,
               read_data, response_status);
    if ((response_status != 2'b00)
        || (input_base != 48'h1000)
        || (m_axi_addr_base != 48'd0)
        || (m_axi_addr_limit != 48'h00ff_ffff_fff8)) begin
      $fatal(1, "LSC reserved CSR 0x0090 write changed state");
    end
    csr_access(1'b0, 16'h0090, 64'd0, read_data, response_status);
    if ((response_status != 2'b00) || (read_data != 64'd0)) begin
      $fatal(1, "LSC reserved CSR 0x0090 read behavior is incorrect");
    end

    csr_access(1'b1, 16'h0040, 64'h1, read_data, response_status);
    if ((response_status != 2'b00) || !accept_new_cmd) begin
      $fatal(1, "LSC start control failed");
    end
    csr_access(1'b1, 16'h00a8, 64'h0, read_data, response_status);

    @(negedge clk);
    task_command_id     = 12'h033;
    task_engine         = NPU_ENGINE_MATRIX;
    task_opcode         = NPU_OPCODE_GEMM;
    task_status         = NPU_STATUS_BAD_DESC;
    task_fault_addr     = 48'h0000_0000_4440;
    task_terminal_valid = 1'b1;
    @(posedge clk);
    @(negedge clk);
    task_terminal_valid = 1'b0;
    if (!irq_error) begin
      $fatal(1, "LSC did not raise an unmasked task-error interrupt");
    end

    csr_access(1'b0, 16'h00b0, 64'd0, read_data, response_status);
    if (read_data[11:0] != 12'h033) begin
      $fatal(1, "LSC first-fault command ID mismatch");
    end
    csr_access(1'b0, 16'h00b8, 64'd0, read_data, response_status);
    if (read_data[47:0] != 48'h0000_0000_4440) begin
      $fatal(1, "LSC first-fault address mismatch");
    end
    csr_access(1'b0, 16'h00c0, 64'd0, read_data, response_status);
    if ((read_data[7:0] != NPU_STATUS_BAD_DESC)
        || (read_data[11:8] != NPU_ENGINE_MATRIX)
        || (read_data[19:12] != NPU_OPCODE_GEMM)) begin
      $fatal(1, "LSC first-fault metadata mismatch");
    end

    wdt_timeout_cycles = 32'd3;
    wdt_enable = 1'b1;
    repeat (3) @(posedge clk);
    #1;
    if (!wdt_timeout) begin
      $fatal(1, "WDT did not assert after three idle cycles");
    end
    @(negedge clk);
    wdt_progress = 1'b1;
    @(posedge clk);
    @(negedge clk);
    wdt_progress = 1'b0;
    if (wdt_timeout) begin
      $fatal(1, "WDT progress did not clear the timeout");
    end

    soft_reset_req = 1'b1;
    wait (internal_soft_reset_pulse);
    @(negedge clk);
    internal_soft_reset_done = 1'b1;
    @(posedge clk);
    @(negedge clk);
    internal_soft_reset_done = 1'b0;
    wait (soft_reset_done);
    soft_reset_req = 1'b0;
    repeat (2) @(posedge clk);
    if (accept_new_cmd) begin
      $fatal(1, "controlled reset did not return LSC to stopped state");
    end

    $display(
      "PASS: LSC registers/fault/reset, CRG and WDT signature=%0b",
      ^{
        power_down_ack, cfe_quiesce, ts_quiesce, eng_abort,
        single_step_pulse, lsc_core_idle, task_terminal_ready,
        interface_error_clear, lsc_wdt_enable, lsc_wdt_timeout_cycles,
        lsc_wdt_kick, irq_done, irq_exception,
        weight_base, work_base, output_base, kv_base,
        m_axi_addr_base, m_axi_addr_limit,
        param_l1_base, param_l1_limit, param_lock,
        l1_host_access_enable, lsc_module_clk_enable,
        wdt_reset_req, core_clk_gated, noc_clk_gated
      }
    );
    $finish;
  end

  initial begin
    #100000;
    $fatal(1, "LSC/CRG/WDT smoke test timeout");
  end

endmodule
