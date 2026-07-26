typedef enum int {
  NPU_WLAST_NORMAL,
  NPU_WLAST_EARLY,
  NPU_WLAST_MISSING
} npu_axi_wlast_mode_e;

class npu_axi_wlast_fault_control;
  static npu_axi_wlast_mode_e mode = NPU_WLAST_NORMAL;
endclass

class npu_axi_master_write_sequence extends tvip_axi_master_write_sequence;
  constraint c_default_burst_type {
    soft burst_type == TVIP_AXI_FIXED_BURST;
  }

  `uvm_object_utils(npu_axi_master_write_sequence)

  function new(string name = "npu_axi_master_write_sequence");
    super.new(name);
  endfunction
endclass

class npu_axi_raw_write_sequence extends npu_axi_master_write_sequence;
  function new(string name = "npu_axi_raw_write_sequence");
    super.new(name);
  endfunction

  function void pre_randomize();
    super.pre_randomize();
    c_valid_burst_length.constraint_mode(0);
  endfunction

  `uvm_object_utils(npu_axi_raw_write_sequence)
endclass

class axi_tvip_npu_cmd_fifo_sequence extends tvip_axi_master_sequence_base;
  localparam tvip_axi_address CMD_FIFO_DATA   = 64'h0002_0000;
  localparam tvip_axi_address CMD_RSP_FIFO    = 64'h0002_0008;
  localparam tvip_axi_address CMD_FIFO_STATUS = 64'h0002_0010;

  localparam bit [63:0] STATUS_HALF_PENDING = 64'h0001_0000;
  localparam bit [63:0] STATUS_INGRESS_FULL = 64'h0002_0000;
  localparam bit [63:0] STATUS_RSP_FULL     = 64'h0004_0000;
  localparam bit [63:0] STATUS_PROTOCOL_ERR = 64'h0008_0000;

  tvip_axi_vif       axi_vif;
  npu_cmd_backend_vif backend_vif;

  bit backend_accept_enable;
  bit backend_response_enable;
  bit protocol_error_clear_request;
  bit awlock_request;
  bit arlock_request;

  bit [63:0] expected_cmd_words[$];
  tvip_axi_id expected_bid[$];
  tvip_axi_id expected_rid[$];

  int unsigned observed_cmd_beats;
  int unsigned observed_commands;
  int unsigned backend_rsp_handshakes;

  bit backend_have_low;
  bit backend_rsp_pending;
  bit [63:0] backend_low_word;
  bit [63:0] backend_rsp_word;

  function new(string name = "axi_tvip_npu_cmd_fifo_sequence");
    super.new(name);
    set_automatic_phase_objection(1);
  endfunction

  function automatic bit [63:0] make_low_word(
    input int unsigned command_id,
    input int unsigned tag
  );
    bit [63:0] word;
    word = 64'h0045_2301_89ab_cdef ^ (64'(tag) << 8);
    word[59:48] = command_id[11:0];
    return word;
  endfunction

  function automatic bit [63:0] make_high_word(
    input int unsigned command_id,
    input int unsigned tag
  );
    return 64'h9000_0000_0000_0000 ^
           (64'(command_id) << 20) ^ 64'(tag);
  endfunction

  function automatic bit [63:0] make_backend_response(
    input bit [63:0] low_word
  );
    bit [63:0] response;
    response = '0;
    response[11:0]  = low_word[59:48];
    response[19:12] = 8'h00;
    response[27:20] = 8'h08;
    return response;
  endfunction

  task body();
    bit test_done;

    if ((axi_vif == null) || (backend_vif == null)) begin
      `uvm_fatal("NPU_AXI", "AXI or NPU backend virtual interface is null")
    end

    backend_accept_enable        = 1'b1;
    backend_response_enable      = 1'b1;
    protocol_error_clear_request = 1'b0;
    awlock_request               = 1'b0;
    arlock_request               = 1'b0;
    npu_axi_wlast_fault_control::mode = NPU_WLAST_NORMAL;

    wait (axi_vif.areset_n === 1'b1);
    repeat (3) @(backend_vif.driver_cb);

    test_done = 1'b0;
    fork
      backend_model();
      axi_id_monitor();
      begin
        run_all_checks();
        test_done = 1'b1;
      end
    join_any
    disable fork;

    if (!test_done) begin
      `uvm_fatal("NPU_AXI", "support thread stopped before checks completed")
    end
  endtask

  task run_all_checks();
    bit [63:0] status;

    read_status(8'h12, status);
    check_status("reset value", status, 8'd16, 8'd0, 4'b0000);

    `uvm_info("NPU_AXI", "start: normal 1..8-command FIXED bursts", UVM_LOW)
    check_normal_fixed_bursts();
    `uvm_info("NPU_AXI", "done: normal 1..8-command FIXED bursts", UVM_LOW)
    `uvm_info("NPU_AXI", "start: staged low-word status", UVM_LOW)
    check_mid_burst_status();
    `uvm_info("NPU_AXI", "done: staged low-word status", UVM_LOW)
    `uvm_info("NPU_AXI", "start: ingress and response backpressure", UVM_LOW)
    check_ingress_and_response_backpressure();
    `uvm_info("NPU_AXI", "done: ingress and response backpressure", UVM_LOW)
    `uvm_info("NPU_AXI", "start: empty response FIFO read", UVM_LOW)
    check_empty_response_read_wait();
    `uvm_info("NPU_AXI", "done: empty response FIFO read", UVM_LOW)
    `uvm_info("NPU_AXI", "start: invalid command bursts", UVM_LOW)
    check_invalid_bursts();
    `uvm_info("NPU_AXI", "done: invalid command bursts", UVM_LOW)
    `uvm_info("NPU_AXI", "start: invalid read transactions", UVM_LOW)
    check_invalid_reads();
    `uvm_info("NPU_AXI", "done: invalid read transactions", UVM_LOW)
    `uvm_info("NPU_AXI", "start: reset cleanup", UVM_LOW)
    check_reset();
    `uvm_info("NPU_AXI", "done: reset cleanup", UVM_LOW)

    repeat (4) @(backend_vif.monitor_cb);
    if (expected_cmd_words.size() != 0) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "%0d expected command beats were not observed",
          expected_cmd_words.size()
        )
      )
    end
    if ((expected_bid.size() != 0) || (expected_rid.size() != 0)) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "unmatched AXI IDs remain: BID=%0d RID=%0d",
          expected_bid.size(), expected_rid.size()
        )
      )
    end

    `uvm_info(
      "NPU_AXI",
      $sformatf(
        "all command FIFO checks completed: command_beats=%0d commands=%0d responses=%0d",
        observed_cmd_beats, observed_commands, backend_rsp_handshakes
      ),
      UVM_LOW
    )
  endtask

  task backend_model();
    backend_vif.driver_cb.cmd_ready            <= 1'b0;
    backend_vif.driver_cb.cmd_rsp_valid        <= 1'b0;
    backend_vif.driver_cb.cmd_rsp_data         <= '0;
    backend_vif.driver_cb.protocol_error_clear <= 1'b0;
    backend_vif.driver_cb.awlock               <= 1'b0;
    backend_vif.driver_cb.arlock               <= 1'b0;

    forever begin
      bit cmd_handshake;
      bit rsp_handshake;
      bit [63:0] expected_word;

      @(backend_vif.driver_cb);
      if (backend_vif.reset_n !== 1'b1) begin
        backend_have_low    = 1'b0;
        backend_rsp_pending = 1'b0;
        backend_low_word    = '0;
        backend_rsp_word    = '0;
        backend_vif.driver_cb.cmd_ready            <= 1'b0;
        backend_vif.driver_cb.cmd_rsp_valid        <= 1'b0;
        backend_vif.driver_cb.cmd_rsp_data         <= '0;
        backend_vif.driver_cb.protocol_error_clear <= 1'b0;
        backend_vif.driver_cb.awlock               <= 1'b0;
        backend_vif.driver_cb.arlock               <= 1'b0;
        continue;
      end

      cmd_handshake =
        backend_vif.driver_cb.cmd_valid &&
        backend_vif.cmd_ready;
      rsp_handshake =
        backend_vif.cmd_rsp_valid &&
        backend_vif.driver_cb.cmd_rsp_ready;

      if (rsp_handshake) begin
        backend_rsp_pending = 1'b0;
        backend_rsp_handshakes++;
      end

      if (cmd_handshake) begin
        observed_cmd_beats++;
        if (expected_cmd_words.size() == 0) begin
          `uvm_error(
            "NPU_AXI",
            $sformatf(
              "DUT exposed an unexpected command beat: data=0x%016h first=%0b last=%0b",
              backend_vif.driver_cb.cmd_data,
              backend_vif.driver_cb.cmd_first,
              backend_vif.driver_cb.cmd_last
            )
          )
        end
        else begin
          expected_word = expected_cmd_words.pop_front();
          if (backend_vif.driver_cb.cmd_data !== expected_word) begin
            `uvm_error(
              "NPU_AXI",
              $sformatf(
                "command beat mismatch: expected=0x%016h actual=0x%016h",
                expected_word, backend_vif.driver_cb.cmd_data
              )
            )
          end
        end

        if (!backend_have_low) begin
          if ((backend_vif.driver_cb.cmd_first !== 1'b1) ||
              (backend_vif.driver_cb.cmd_last !== 1'b0)) begin
            `uvm_error("NPU_AXI", "low command beat has invalid first/last")
          end
          backend_low_word = backend_vif.driver_cb.cmd_data;
          backend_have_low = 1'b1;
        end
        else begin
          if ((backend_vif.driver_cb.cmd_first !== 1'b0) ||
              (backend_vif.driver_cb.cmd_last !== 1'b1)) begin
            `uvm_error("NPU_AXI", "high command beat has invalid first/last")
          end
          backend_rsp_word    = make_backend_response(backend_low_word);
          backend_rsp_pending = 1'b1;
          backend_have_low    = 1'b0;
          observed_commands++;
        end
      end

      backend_vif.driver_cb.cmd_ready <=
        backend_accept_enable && !backend_rsp_pending;
      backend_vif.driver_cb.cmd_rsp_valid <=
        backend_response_enable && backend_rsp_pending;
      backend_vif.driver_cb.cmd_rsp_data <= backend_rsp_word;
      backend_vif.driver_cb.protocol_error_clear <=
        protocol_error_clear_request;
      backend_vif.driver_cb.awlock <= awlock_request;
      backend_vif.driver_cb.arlock <= arlock_request;
    end
  endtask

  task axi_id_monitor();
    forever begin
      @(axi_vif.monitor_cb);
      if (axi_vif.monitor_cb.areset_n !== 1'b1) begin
        continue;
      end

      if (axi_vif.monitor_cb.bvalid &&
          axi_vif.monitor_cb.bready) begin
        tvip_axi_id id;
        if (expected_bid.size() == 0) begin
          `uvm_error(
            "NPU_AXI",
            $sformatf("unexpected BID 0x%0h", axi_vif.monitor_cb.bid)
          )
        end
        else begin
          id = expected_bid.pop_front();
          if (axi_vif.monitor_cb.bid[7:0] !== id[7:0]) begin
            `uvm_error(
              "NPU_AXI",
              $sformatf(
                "BID mismatch: expected=0x%02h actual=0x%02h",
                id[7:0], axi_vif.monitor_cb.bid[7:0]
              )
            )
          end
        end
      end

      if (axi_vif.monitor_cb.rvalid &&
          axi_vif.monitor_cb.rready) begin
        tvip_axi_id id;
        if (expected_rid.size() == 0) begin
          `uvm_error(
            "NPU_AXI",
            $sformatf("unexpected RID 0x%0h", axi_vif.monitor_cb.rid)
          )
        end
        else begin
          id = expected_rid.pop_front();
          if (axi_vif.monitor_cb.rid[7:0] !== id[7:0]) begin
            `uvm_error(
              "NPU_AXI",
              $sformatf(
                "RID mismatch: expected=0x%02h actual=0x%02h",
                id[7:0], axi_vif.monitor_cb.rid[7:0]
              )
            )
          end
          if (axi_vif.monitor_cb.rlast !== 1'b1) begin
            `uvm_error("NPU_AXI", "single-beat read response has RLAST=0")
          end
        end
      end
    end
  endtask

  task automatic build_valid_burst(
    input  int unsigned command_count,
    input  int unsigned first_command_id,
    output tvip_axi_data words[],
    output tvip_axi_strobe strobes[],
    output int beat_delays[]
  );
    int unsigned beat_count;

    beat_count  = 2 * command_count;
    words       = new[beat_count];
    strobes     = new[beat_count];
    beat_delays = new[beat_count];
    for (int unsigned i = 0; i < command_count; i++) begin
      words[2*i] = make_low_word(first_command_id + i, i);
      words[2*i+1] = make_high_word(first_command_id + i, i);
      strobes[2*i] = 8'hff;
      strobes[2*i+1] = 8'hff;
      beat_delays[2*i] = 0;
      beat_delays[2*i+1] = 0;
    end
  endtask

  task automatic queue_backend_words(ref tvip_axi_data words[]);
    foreach (words[i]) begin
      expected_cmd_words.push_back(words[i][63:0]);
    end
  endtask

  task automatic do_write(
    input tvip_axi_id id,
    input tvip_axi_address address,
    input tvip_axi_burst_type burst_type,
    ref tvip_axi_data words[],
    ref tvip_axi_strobe strobes[],
    ref int beat_delays[],
    input tvip_axi_response expected_response
  );
    npu_axi_master_write_sequence write_sequence;
    int beat_count;

    beat_count = words.size();
    expected_bid.push_back(id);
    `tue_do_with(write_sequence, {
      id           == local::id;
      address      == local::address;
      burst_length == local::beat_count;
      burst_size   == 8;
      burst_type   == local::burst_type;
      memory_type  == TVIP_AXI_DEVICE_NON_BUFFERABLE;
      protection   == '0;
      qos          == '0;
      data.size()  == local::beat_count;
      foreach (data[i]) {
        data[i] == local::words[i];
      }
      strobe.size() == local::beat_count;
      foreach (strobe[i]) {
        strobe[i] == local::strobes[i];
      }
      write_data_delay.size() == local::beat_count;
      foreach (write_data_delay[i]) {
        write_data_delay[i] == local::beat_delays[i];
      }
      response_ready_delay.size() == 1;
      response_ready_delay[0] == 0;
      start_delay == 0;
    })

    if (write_sequence.response.size() != 1) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "write at 0x%0h returned %0d B responses",
          address, write_sequence.response.size()
        )
      )
    end
    else if (write_sequence.response[0] != expected_response) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "write response mismatch at 0x%0h: expected=%0d actual=%0d",
          address, expected_response, write_sequence.response[0]
        )
      )
    end
  endtask

  task automatic do_read(
    input tvip_axi_id id,
    input tvip_axi_address address,
    output bit [63:0] read_data,
    input tvip_axi_response expected_response = TVIP_AXI_OKAY
  );
    tvip_axi_master_read_sequence read_sequence;

    expected_rid.push_back(id);
    `tue_do_with(read_sequence, {
      id           == local::id;
      address      == local::address;
      burst_length == 1;
      burst_size   == 8;
      burst_type   == TVIP_AXI_INCREMENTING_BURST;
      memory_type  == TVIP_AXI_DEVICE_NON_BUFFERABLE;
      protection   == '0;
      qos          == '0;
      response_ready_delay.size() == 1;
      response_ready_delay[0] == 0;
      start_delay == 0;
    })

    read_data = '0;
    if (read_sequence.response.size() != 1) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "read at 0x%0h returned %0d R responses",
          address, read_sequence.response.size()
        )
      )
    end
    else if (read_sequence.response[0] != expected_response) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "read response mismatch at 0x%0h: expected=%0d actual=%0d",
          address, expected_response, read_sequence.response[0]
        )
      )
    end
    else if (read_sequence.data.size() != 1) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "read at 0x%0h returned %0d data beats",
          address, read_sequence.data.size()
        )
      )
    end
    else begin
      read_data = read_sequence.data[0][63:0];
    end
  endtask

  task automatic read_status(
    input tvip_axi_id id,
    output bit [63:0] status
  );
    do_read(id, CMD_FIFO_STATUS, status);
  endtask

  task automatic read_and_check_response(
    input tvip_axi_id axi_id,
    input int unsigned command_id
  );
    bit [63:0] response;

    do_read(axi_id, CMD_RSP_FIFO, response);
    if (response[11:0] !== command_id[11:0]) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "command response ID mismatch: expected=0x%03h actual=0x%03h",
          command_id[11:0], response[11:0]
        )
      )
    end
    if (response[19:12] !== 8'h00) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "command 0x%03h returned status 0x%02h",
          command_id[11:0], response[19:12]
        )
      )
    end
    if (response[63:28] !== '0) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "command response reserved bits are nonzero: 0x%016h",
          response
        )
      )
    end
  endtask

  task automatic check_status(
    input string label,
    input bit [63:0] status,
    input bit [7:0] expected_free_beats,
    input bit [7:0] expected_response_count,
    input bit [3:0] expected_flags
  );
    bit [3:0] actual_flags;

    actual_flags = {
      status[19],
      status[18],
      status[17],
      status[16]
    };
    if (status[7:0] !== expected_free_beats) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "%s: free beat count mismatch, expected=%0d actual=%0d",
          label, expected_free_beats, status[7:0]
        )
      )
    end
    if (status[15:8] !== expected_response_count) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "%s: response count mismatch, expected=%0d actual=%0d",
          label, expected_response_count, status[15:8]
        )
      )
    end
    if (actual_flags !== expected_flags) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "%s: status flags mismatch, expected=%04b actual=%04b",
          label, expected_flags, actual_flags
        )
      )
    end
    if (status[63:20] !== '0) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf("%s: status reserved bits are nonzero: 0x%016h", label, status)
      )
    end
  endtask

  task automatic wait_for_command_count(
    input int unsigned target,
    input int unsigned timeout_cycles = 2000
  );
    for (int unsigned cycle = 0; cycle < timeout_cycles; cycle++) begin
      if (observed_commands >= target) begin
        return;
      end
      @(backend_vif.monitor_cb);
    end
    `uvm_fatal(
      "NPU_AXI",
      $sformatf(
        "timeout waiting for command count %0d, current=%0d",
        target, observed_commands
      )
    )
  endtask

  task automatic wait_for_backend_response_count(
    input int unsigned target,
    input int unsigned timeout_cycles = 2000
  );
    for (int unsigned cycle = 0; cycle < timeout_cycles; cycle++) begin
      if (backend_rsp_handshakes >= target) begin
        return;
      end
      @(backend_vif.monitor_cb);
    end
    `uvm_fatal(
      "NPU_AXI",
      $sformatf(
        "timeout waiting for backend response count %0d, current=%0d",
        target, backend_rsp_handshakes
      )
    )
  endtask

  task automatic wait_for_ingress_idle(
    input int unsigned timeout_cycles = 2000
  );
    for (int unsigned cycle = 0; cycle < timeout_cycles; cycle++) begin
      @(backend_vif.monitor_cb);
      if (backend_vif.monitor_cb.cmd_ingress_idle === 1'b1) begin
        return;
      end
    end
    `uvm_fatal("NPU_AXI", "timeout waiting for command ingress idle")
  endtask

  task check_normal_fixed_bursts();
    for (int unsigned command_count = 1;
         command_count <= 8; command_count++) begin
      tvip_axi_data words[];
      tvip_axi_strobe strobes[];
      int beat_delays[];
      bit [63:0] status;
      int unsigned first_id;
      int unsigned command_target;
      int unsigned response_target;
      tvip_axi_id axi_id;

      first_id       = 12'h100 + 16 * command_count;
      command_target = observed_commands + command_count;
      response_target = backend_rsp_handshakes + command_count;
      axi_id = (command_count[0]) ? 8'h12 : 8'ha5;

      build_valid_burst(
        command_count, first_id, words, strobes, beat_delays
      );
      queue_backend_words(words);
      do_write(
        axi_id, CMD_FIFO_DATA, TVIP_AXI_FIXED_BURST,
        words, strobes, beat_delays, TVIP_AXI_OKAY
      );

      wait_for_command_count(command_target);
      wait_for_backend_response_count(response_target);
      wait_for_ingress_idle();
      read_status(axi_id, status);
      check_status(
        $sformatf("%0d-command FIXED burst", command_count),
        status,
        8'd16,
        command_count[7:0],
        (command_count == 8) ? 4'b0100 : 4'b0000
      );

      for (int unsigned i = 0; i < command_count; i++) begin
        read_and_check_response(
          (i[0]) ? 8'ha5 : 8'h12, first_id + i
        );
      end
      read_status((axi_id == 8'h12) ? 8'ha5 : 8'h12, status);
      check_status("response FIFO drained", status, 8'd16, 8'd0, 4'b0000);
    end
  endtask

  task check_mid_burst_status();
    tvip_axi_data words[];
    tvip_axi_strobe strobes[];
    int beat_delays[];
    bit write_done;
    bit first_w_seen;
    bit [63:0] status;
    int unsigned response_target;

    build_valid_burst(1, 12'h280, words, strobes, beat_delays);
    beat_delays[1] = 20;
    queue_backend_words(words);
    backend_accept_enable = 1'b0;
    @(backend_vif.driver_cb);

    write_done   = 1'b0;
    first_w_seen = 1'b0;
    fork
      begin
        do_write(
          8'h12, CMD_FIFO_DATA, TVIP_AXI_FIXED_BURST,
          words, strobes, beat_delays, TVIP_AXI_OKAY
        );
        write_done = 1'b1;
      end
      begin
        forever begin
          @(axi_vif.monitor_cb);
          if (axi_vif.monitor_cb.wvalid &&
              axi_vif.monitor_cb.wready) begin
            first_w_seen = 1'b1;
            break;
          end
        end
      end
    join_none

    wait (first_w_seen);
    `uvm_info("NPU_AXI", "staged test: first W beat accepted", UVM_LOW)
    read_status(8'ha5, status);
    `uvm_info("NPU_AXI", "staged test: status read completed", UVM_LOW)
    check_status(
      "one low word staged", status, 8'd14, 8'd0, 4'b0001
    );
    if (backend_vif.monitor_cb.cmd_valid === 1'b1) begin
      `uvm_error("NPU_AXI", "command became visible before the burst completed")
    end

    for (int unsigned cycle = 0; cycle < 200; cycle++) begin
      if (write_done) begin
        break;
      end
      @(backend_vif.monitor_cb);
    end
    if (!write_done) begin
      `uvm_fatal("NPU_AXI", "delayed two-beat write did not finish")
    end
    `uvm_info("NPU_AXI", "staged test: delayed write completed", UVM_LOW)

    response_target = backend_rsp_handshakes + 1;
    backend_accept_enable = 1'b1;
    wait_for_backend_response_count(response_target);
    `uvm_info("NPU_AXI", "staged test: backend response accepted", UVM_LOW)
    read_and_check_response(8'ha5, 12'h280);
    wait_for_ingress_idle();
    read_status(8'h12, status);
    check_status("mid-burst check cleanup", status, 8'd16, 8'd0, 4'b0000);
  endtask

  task check_ingress_and_response_backpressure();
    tvip_axi_data words8[];
    tvip_axi_strobe strobes8[];
    int beat_delays8[];
    tvip_axi_data words1[];
    tvip_axi_strobe strobes1[];
    int beat_delays1[];
    bit second_write_done;
    bit aw_wait_seen;
    bit [63:0] status;
    int unsigned response_target;

    backend_accept_enable = 1'b0;
    @(backend_vif.driver_cb);

    build_valid_burst(8, 12'h300, words8, strobes8, beat_delays8);
    queue_backend_words(words8);
    do_write(
      8'h12, CMD_FIFO_DATA, TVIP_AXI_FIXED_BURST,
      words8, strobes8, beat_delays8, TVIP_AXI_OKAY
    );
    read_status(8'ha5, status);
    check_status("ingress full", status, 8'd0, 8'd0, 4'b0010);

    build_valid_burst(1, 12'h380, words1, strobes1, beat_delays1);
    queue_backend_words(words1);
    second_write_done = 1'b0;
    aw_wait_seen = 1'b0;
    fork
      begin
        do_write(
          8'ha5, CMD_FIFO_DATA, TVIP_AXI_FIXED_BURST,
          words1, strobes1, beat_delays1, TVIP_AXI_OKAY
        );
        second_write_done = 1'b1;
      end
      begin
        forever begin
          @(axi_vif.monitor_cb);
          if (axi_vif.monitor_cb.awvalid &&
              !axi_vif.monitor_cb.awready) begin
            aw_wait_seen = 1'b1;
            break;
          end
        end
      end
    join_none

    wait (aw_wait_seen);
    repeat (8) begin
      @(axi_vif.monitor_cb);
      if (axi_vif.monitor_cb.awready !== 1'b0) begin
        `uvm_error("NPU_AXI", "AWREADY rose while ingress had no space")
      end
    end

    response_target = backend_rsp_handshakes + 8;
    backend_accept_enable = 1'b1;
    for (int unsigned cycle = 0; cycle < 2000; cycle++) begin
      if (second_write_done) begin
        break;
      end
      @(backend_vif.monitor_cb);
    end
    if (!second_write_done) begin
      `uvm_fatal("NPU_AXI", "write did not resume after ingress space became available")
    end

    wait_for_backend_response_count(response_target);
    repeat (3) @(backend_vif.monitor_cb);
    read_status(8'h12, status);
    if ((status[15:8] !== 8'd8) ||
        (status & STATUS_RSP_FULL) == 0) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf("response FIFO did not report full: status=0x%016h", status)
      )
    end

    for (int unsigned i = 0; i < 8; i++) begin
      read_and_check_response(
        (i[0]) ? 8'ha5 : 8'h12, 12'h300 + i
      );
    end
    read_and_check_response(8'ha5, 12'h380);
    wait_for_backend_response_count(response_target + 1);
    wait_for_ingress_idle();
    read_status(8'h12, status);
    check_status("backpressure cleanup", status, 8'd16, 8'd0, 4'b0000);
  endtask

  task check_empty_response_read_wait();
    tvip_axi_data words[];
    tvip_axi_strobe strobes[];
    int beat_delays[];
    bit read_done;
    bit ar_seen;
    bit [63:0] response;
    bit [63:0] status;
    int unsigned command_target;
    int unsigned response_target;

    read_done = 1'b0;
    ar_seen   = 1'b0;
    fork
      begin
        do_read(8'ha5, CMD_RSP_FIFO, response);
        read_done = 1'b1;
      end
      begin
        forever begin
          @(axi_vif.monitor_cb);
          if (axi_vif.monitor_cb.arvalid &&
              axi_vif.monitor_cb.arready) begin
            ar_seen = 1'b1;
            break;
          end
        end
      end
    join_none

    wait (ar_seen);
    repeat (8) begin
      @(axi_vif.monitor_cb);
      if (axi_vif.monitor_cb.rvalid === 1'b1) begin
        `uvm_error("NPU_AXI", "empty response FIFO returned data")
      end
    end
    if (read_done) begin
      `uvm_error("NPU_AXI", "empty response FIFO read finished before a response existed")
    end

    build_valid_burst(1, 12'h390, words, strobes, beat_delays);
    queue_backend_words(words);
    command_target = observed_commands + 1;
    response_target = backend_rsp_handshakes + 1;
    do_write(
      8'h12, CMD_FIFO_DATA, TVIP_AXI_FIXED_BURST,
      words, strobes, beat_delays, TVIP_AXI_OKAY
    );
    wait_for_command_count(command_target);
    wait_for_backend_response_count(response_target);

    for (int unsigned cycle = 0; cycle < 1000; cycle++) begin
      if (read_done) begin
        break;
      end
      @(backend_vif.monitor_cb);
    end
    if (!read_done) begin
      `uvm_fatal("NPU_AXI", "response FIFO read did not finish after a response arrived")
    end
    if ((response[11:0] !== 12'h390) ||
        (response[19:12] !== 8'h00)) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf("empty-read wakeup returned 0x%016h", response)
      )
    end
    wait_for_ingress_idle();
    read_status(8'ha5, status);
    check_status("empty-read cleanup", status, 8'd16, 8'd0, 4'b0000);
  endtask

  task automatic check_discarded_group(
    input string label,
    input tvip_axi_id id,
    input tvip_axi_burst_type burst_type,
    ref tvip_axi_data words[],
    ref tvip_axi_strobe strobes[],
    ref int beat_delays[]
  );
    int unsigned beat_snapshot;
    bit [63:0] status;

    beat_snapshot = observed_cmd_beats;
    do_write(
      id, CMD_FIFO_DATA, burst_type,
      words, strobes, beat_delays, TVIP_AXI_SLAVE_ERROR
    );
    repeat (8) @(backend_vif.monitor_cb);
    if (observed_cmd_beats != beat_snapshot) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf("%s exposed one or more command beats", label)
      )
    end
    read_status((id == 8'h12) ? 8'ha5 : 8'h12, status);
    check_status(label, status, 8'd16, 8'd0, 4'b1000);
  endtask

  task check_invalid_bursts();
    tvip_axi_data words[];
    tvip_axi_strobe strobes[];
    int beat_delays[];
    bit [63:0] status;

    build_valid_burst(1, 12'h400, words, strobes, beat_delays);
    check_discarded_group(
      "INCR command burst", 8'h12, TVIP_AXI_INCREMENTING_BURST,
      words, strobes, beat_delays
    );

    words       = new[3];
    strobes     = new[3];
    beat_delays = new[3];
    foreach (words[i]) begin
      words[i]       = 64'h4100_0000_0000_0000 + i;
      strobes[i]     = 8'hff;
      beat_delays[i] = 0;
    end
    check_discarded_group(
      "odd command beat count", 8'ha5, TVIP_AXI_FIXED_BURST,
      words, strobes, beat_delays
    );

    build_valid_burst(2, 12'h420, words, strobes, beat_delays);
    strobes[1] = 8'h7f;
    check_discarded_group(
      "bad WSTRB group discard", 8'h12, TVIP_AXI_FIXED_BURST,
      words, strobes, beat_delays
    );

    build_valid_burst(1, 12'h430, words, strobes, beat_delays);
    npu_axi_wlast_fault_control::mode = NPU_WLAST_EARLY;
    check_discarded_group(
      "early WLAST group discard", 8'ha5, TVIP_AXI_FIXED_BURST,
      words, strobes, beat_delays
    );
    npu_axi_wlast_fault_control::mode = NPU_WLAST_NORMAL;

    build_valid_burst(1, 12'h440, words, strobes, beat_delays);
    npu_axi_wlast_fault_control::mode = NPU_WLAST_MISSING;
    check_discarded_group(
      "missing WLAST group discard", 8'h12, TVIP_AXI_FIXED_BURST,
      words, strobes, beat_delays
    );
    npu_axi_wlast_fault_control::mode = NPU_WLAST_NORMAL;

    protocol_error_clear_request = 1'b1;
    repeat (2) @(backend_vif.driver_cb);
    protocol_error_clear_request = 1'b0;
    repeat (2) @(backend_vif.driver_cb);
    read_status(8'ha5, status);
    check_status("protocol error clear", status, 8'd16, 8'd0, 4'b0000);

    words       = new[3];
    strobes     = new[3];
    beat_delays = new[3];
    foreach (words[i]) begin
      words[i]       = 64'h4500_0000_0000_0000 + i;
      strobes[i]     = 8'hff;
      beat_delays[i] = 0;
    end
    check_discarded_group(
      "sticky error before reset", 8'h12, TVIP_AXI_FIXED_BURST,
      words, strobes, beat_delays
    );
  endtask

  task check_invalid_reads();
    bit [63:0] read_data;
    bit [63:0] status;

    do_read(
      8'h61,
      CMD_FIFO_DATA,
      read_data,
      TVIP_AXI_SLAVE_ERROR
    );
    if (read_data !== 64'd0) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "write-only command FIFO read returned 0x%016h instead of zero",
          read_data
        )
      )
    end

    do_read(
      8'h62,
      CMD_FIFO_STATUS + 64'h8,
      read_data,
      TVIP_AXI_SLAVE_ERROR
    );
    if (read_data !== 64'd0) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "unassigned command register read returned 0x%016h instead of zero",
          read_data
        )
      )
    end

    arlock_request = 1'b1;
    repeat (2) @(backend_vif.driver_cb);
    do_read(
      8'h63,
      CMD_FIFO_STATUS,
      read_data,
      TVIP_AXI_SLAVE_ERROR
    );
    arlock_request = 1'b0;
    repeat (2) @(backend_vif.driver_cb);
    if (read_data !== 64'd0) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf(
          "locked command status read returned 0x%016h instead of zero",
          read_data
        )
      )
    end

    read_status(8'h64, status);
    check_status(
      "invalid reads preserve command FIFO state",
      status,
      8'd16,
      8'd0,
      4'b1000
    );
  endtask

  task check_reset();
    tvip_axi_data words_rsp[];
    tvip_axi_strobe strobes_rsp[];
    int beat_delays_rsp[];
    tvip_axi_data words_ingress[];
    tvip_axi_strobe strobes_ingress[];
    int beat_delays_ingress[];
    bit [63:0] status;
    int unsigned response_target;

    `uvm_info("NPU_AXI", "reset setup: queue one completed response", UVM_LOW)
    build_valid_burst(
      1, 12'h500, words_rsp, strobes_rsp, beat_delays_rsp
    );
    queue_backend_words(words_rsp);
    response_target = backend_rsp_handshakes + 1;
    do_write(
      8'ha5, CMD_FIFO_DATA, TVIP_AXI_FIXED_BURST,
      words_rsp, strobes_rsp, beat_delays_rsp, TVIP_AXI_OKAY
    );
    wait_for_backend_response_count(response_target);
    `uvm_info("NPU_AXI", "reset setup: completed response is queued", UVM_LOW)

    backend_accept_enable = 1'b0;
    @(backend_vif.driver_cb);
    `uvm_info("NPU_AXI", "reset setup: queue two commands in ingress", UVM_LOW)
    build_valid_burst(
      2, 12'h510, words_ingress, strobes_ingress, beat_delays_ingress
    );
    queue_backend_words(words_ingress);
    do_write(
      8'h12, CMD_FIFO_DATA, TVIP_AXI_FIXED_BURST,
      words_ingress, strobes_ingress, beat_delays_ingress, TVIP_AXI_OKAY
    );
    `uvm_info("NPU_AXI", "reset setup: ingress commands are queued", UVM_LOW)
    read_status(8'ha5, status);
    if ((status[15:8] !== 8'd1) ||
        (status & STATUS_PROTOCOL_ERR) == 0 ||
        (status[7:0] !== 8'd12)) begin
      `uvm_error(
        "NPU_AXI",
        $sformatf("unexpected state before reset: 0x%016h", status)
      )
    end

    `uvm_info("NPU_AXI", "reset action: drive reset_n low", UVM_LOW)
    if (!uvm_hdl_force("axi_tvip_tb.reset_n", 1'b0)) begin
      `uvm_fatal("NPU_AXI", "failed to force axi_tvip_tb.reset_n low")
    end
    repeat (6) @(posedge axi_vif.aclk);
    `uvm_info("NPU_AXI", "reset action: force reset_n high", UVM_LOW)
    if (!uvm_hdl_force("axi_tvip_tb.reset_n", 1'b1)) begin
      `uvm_fatal("NPU_AXI", "failed to force axi_tvip_tb.reset_n high")
    end
    wait (axi_vif.areset_n === 1'b1);
    repeat (6) @(backend_vif.driver_cb);
    `uvm_info("NPU_AXI", "reset action: reset_n is high again", UVM_LOW)

    expected_cmd_words.delete();
    backend_accept_enable = 1'b1;
    backend_response_enable = 1'b1;
    protocol_error_clear_request = 1'b0;
    npu_axi_wlast_fault_control::mode = NPU_WLAST_NORMAL;

    `uvm_info("NPU_AXI", "reset check: read status", UVM_LOW)
    read_status(8'h12, status);
    check_status("reset cleanup", status, 8'd16, 8'd0, 4'b0000);
    if (backend_vif.monitor_cb.cmd_ingress_idle !== 1'b1) begin
      `uvm_error("NPU_AXI", "command ingress is not idle after reset")
    end
    if (!uvm_hdl_release("axi_tvip_tb.reset_n")) begin
      `uvm_fatal("NPU_AXI", "failed to release axi_tvip_tb.reset_n")
    end
  endtask

  `uvm_object_utils(axi_tvip_npu_cmd_fifo_sequence)
endclass
