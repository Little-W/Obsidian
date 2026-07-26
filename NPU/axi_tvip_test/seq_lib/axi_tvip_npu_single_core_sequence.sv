class npu_single_core_write_sequence extends tvip_axi_master_write_sequence;
  constraint c_default_burst_type {
    soft burst_type == TVIP_AXI_INCREMENTING_BURST;
  }

  `uvm_object_utils(npu_single_core_write_sequence)

  function new(string name = "npu_single_core_write_sequence");
    super.new(name);
  endfunction
endclass

class axi_tvip_npu_single_core_sequence
    extends tvip_axi_master_sequence_base;
  localparam tvip_axi_address CSR_CORE_CONTROL =
      64'h0000_0040;
  localparam tvip_axi_address CSR_L1_EXTERNAL_CONTROL =
      64'h0000_00f0;
  localparam tvip_axi_address CMD_FIFO_DATA =
      64'h0002_0000;
  localparam tvip_axi_address CMD_RSP_FIFO =
      64'h0002_0008;
  localparam tvip_axi_address CTL_ARG0 =
      64'h0002_0020;
  localparam tvip_axi_address CTL_ARG1 =
      64'h0002_0028;
  localparam tvip_axi_address CTL_START =
      64'h0002_0030;
  localparam tvip_axi_address CTL_STATUS =
      64'h0002_0038;
  localparam tvip_axi_address CTL_RESULT =
      64'h0002_0040;
  localparam tvip_axi_address CTL_CANCEL =
      64'h0002_0048;
  localparam tvip_axi_address L1_AXI_BASE =
      64'h0010_0000;

  localparam bit [3:0] ENGINE_DMA     = 4'h1;
  localparam bit [3:0] ENGINE_MATRIX  = 4'h2;
  localparam bit [3:0] ENGINE_VECTOR  = 4'h3;
  localparam bit [3:0] ENGINE_COMPLEX = 4'h4;

  localparam bit [7:0] OPCODE_DMA_COPY_1D = 8'h20;
  localparam bit [7:0] OPCODE_GEMM        = 8'h40;
  localparam bit [7:0] OPCODE_VADD_I      = 8'h60;
  localparam bit [7:0] OPCODE_VACT_I      = 8'h80;

  localparam bit [1:0] CTL_WAIT  = 2'd1;
  localparam bit [1:0] CTL_QUERY = 2'd2;
  localparam bit [1:0] CTL_FENCE = 2'd3;

  localparam bit [11:0] EVENT_NONE = 12'hfff;

  localparam bit [7:0] STATUS_SUCCESS   = 8'h00;
  localparam bit [7:0] STATUS_BAD_DESC  = 8'h02;
  localparam bit [7:0] STATUS_ABORTED   = 8'h0a;
  localparam bit [7:0] STATUS_NOT_FOUND = 8'h81;

  localparam bit [2:0] EVENT_SUCCESS = 3'd2;

  tvip_axi_vif axi_vif;
  npu_single_core_system_vif system_vif;

  int unsigned next_axi_id;
  bit [127:0] command_words [0:7];

  function new(string name = "axi_tvip_npu_single_core_sequence");
    super.new(name);
    set_automatic_phase_objection(1);
  endfunction

  task body();
    if ((axi_vif == null) || (system_vif == null)) begin
      `uvm_fatal(
        "NPU_CORE",
        "AXI or single-core system virtual interface is null"
      )
    end

    wait (axi_vif.areset_n === 1'b1);
    repeat (4) @(system_vif.monitor_cb);
    if (system_vif.monitor_cb.full_core_mode !== 1'b1) begin
      `uvm_fatal(
        "NPU_CORE",
        "single-core testcase requires +NPU_SINGLE_CORE"
      )
    end

    next_axi_id = 8'h20;
    system_vif.system_memory_backpressure_enable = 1'b1;
    system_vif.clear_memory();
    foreach (command_words[index]) begin
      command_words[index] = 128'd0;
    end

    run_all_checks();
  endtask

  task automatic check_equal64(
      input string label,
      input bit [63:0] actual,
      input bit [63:0] expected
  );
    if (actual !== expected) begin
      `uvm_error(
        "NPU_CORE",
        $sformatf(
          "%s mismatch: expected=0x%016h actual=0x%016h",
          label,
          expected,
          actual
        )
      )
    end
  endtask

  task automatic check_true(
      input string label,
      input bit condition
  );
    if (!condition) begin
      `uvm_error("NPU_CORE", label)
    end
  endtask

  function automatic bit [127:0] make_command(
      input bit [47:0] descriptor_address,
      input bit [11:0] command_id,
      input bit [3:0] engine,
      input bit [7:0] opcode,
      input bit [11:0] wait0,
      input bit [11:0] wait1,
      input bit [11:0] signal_event
  );
    bit [63:0] low_word;
    bit [63:0] high_word;

    low_word = 64'd0;
    low_word[47:0] = descriptor_address;
    low_word[59:48] = command_id;
    low_word[63:60] = engine;

    high_word = 64'd0;
    high_word[7:0] = opcode;
    high_word[31:20] = wait0;
    high_word[43:32] = wait1;
    high_word[55:44] = signal_event;
    high_word[63:56] = 8'h01;

    return {high_word, low_word};
  endfunction

  function automatic void put_u8(
      ref bit [2047:0] descriptor,
      input int unsigned offset,
      input bit [7:0] value
  );
    descriptor[offset*8 +: 8] = value;
  endfunction

  function automatic void put_u16(
      ref bit [2047:0] descriptor,
      input int unsigned offset,
      input bit [15:0] value
  );
    descriptor[offset*8 +: 16] = value;
  endfunction

  function automatic void put_u32(
      ref bit [2047:0] descriptor,
      input int unsigned offset,
      input bit [31:0] value
  );
    descriptor[offset*8 +: 32] = value;
  endfunction

  function automatic void put_u64(
      ref bit [2047:0] descriptor,
      input int unsigned offset,
      input bit [63:0] value
  );
    descriptor[offset*8 +: 64] = value;
  endfunction

  function automatic void init_common(
      ref bit [2047:0] descriptor,
      input bit [7:0] engine,
      input bit [15:0] descriptor_bytes,
      input bit [63:0] src0,
      input bit [63:0] src1,
      input bit [63:0] src2,
      input bit [63:0] dst,
      input bit [31:0] numeric
  );
    descriptor = '0;
    put_u8(descriptor, 16'h00, 8'h01);
    put_u8(descriptor, 16'h01, engine);
    put_u16(descriptor, 16'h02, descriptor_bytes);
    put_u64(descriptor, 16'h08, src0);
    put_u64(descriptor, 16'h10, src1);
    put_u64(descriptor, 16'h18, src2);
    put_u64(descriptor, 16'h20, dst);
    put_u32(descriptor, 16'h38, numeric);
  endfunction

  task automatic store_descriptor(
      input longint unsigned address,
      input bit [2047:0] descriptor,
      input int unsigned descriptor_bytes
  );
    for (int unsigned index = 0;
         index < descriptor_bytes;
         index++) begin
      system_vif.write_byte(
        address + index,
        descriptor[index*8 +: 8]
      );
    end
  endtask

  task automatic do_write(
      input tvip_axi_address address,
      input tvip_axi_burst_type burst_type,
      ref tvip_axi_data words[],
      ref tvip_axi_strobe strobes[]
  );
    npu_single_core_write_sequence write_sequence;
    int beat_count;
    tvip_axi_id transaction_id;

    beat_count = words.size();
    transaction_id = tvip_axi_id'(next_axi_id[7:0]);
    next_axi_id++;
    `tue_do_with(write_sequence, {
      id           == local::transaction_id;
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
        write_data_delay[i] inside {[0:2]};
      }
      response_ready_delay.size() == 1;
      response_ready_delay[0] inside {[0:2]};
      start_delay inside {[0:2]};
    })

    if (write_sequence.response.size() != 1) begin
      `uvm_error(
        "NPU_CORE",
        $sformatf(
          "write at 0x%0h returned %0d responses",
          address,
          write_sequence.response.size()
        )
      )
    end
    else if (write_sequence.response[0] != TVIP_AXI_OKAY) begin
      `uvm_error(
        "NPU_CORE",
        $sformatf(
          "write at 0x%0h returned response %0d",
          address,
          write_sequence.response[0]
        )
      )
    end
  endtask

  task automatic write_word(
      input tvip_axi_address address,
      input bit [63:0] value,
      input bit [7:0] strobe = 8'hff
  );
    tvip_axi_data words[];
    tvip_axi_strobe strobes[];

    words = new[1];
    strobes = new[1];
    words[0] = tvip_axi_data'(value);
    strobes[0] = tvip_axi_strobe'(strobe);
    do_write(
      address,
      TVIP_AXI_INCREMENTING_BURST,
      words,
      strobes
    );
  endtask

  task automatic do_read(
      input tvip_axi_address address,
      output bit [63:0] value
  );
    tvip_axi_master_read_sequence read_sequence;
    tvip_axi_id transaction_id;

    transaction_id = tvip_axi_id'(next_axi_id[7:0]);
    next_axi_id++;
    `tue_do_with(read_sequence, {
      id           == local::transaction_id;
      address      == local::address;
      burst_length == 1;
      burst_size   == 8;
      burst_type   == TVIP_AXI_INCREMENTING_BURST;
      memory_type  == TVIP_AXI_DEVICE_NON_BUFFERABLE;
      protection   == '0;
      qos          == '0;
      response_ready_delay.size() == 1;
      response_ready_delay[0] inside {[0:2]};
      start_delay inside {[0:2]};
    })

    value = 64'd0;
    if ((read_sequence.response.size() != 1) ||
        (read_sequence.data.size() != 1)) begin
      `uvm_error(
        "NPU_CORE",
        $sformatf(
          "read at 0x%0h returned response_count=%0d data_count=%0d",
          address,
          read_sequence.response.size(),
          read_sequence.data.size()
        )
      )
    end
    else if (read_sequence.response[0] != TVIP_AXI_OKAY) begin
      `uvm_error(
        "NPU_CORE",
        $sformatf(
          "read at 0x%0h returned response %0d",
          address,
          read_sequence.response[0]
        )
      )
    end
    else begin
      value = read_sequence.data[0][63:0];
    end
  endtask

  task automatic l1_write_word(
      input bit [19:0] address,
      input bit [63:0] value,
      input bit [7:0] strobe = 8'hff
  );
    write_word(L1_AXI_BASE + address, value, strobe);
  endtask

  task automatic l1_read_word(
      input bit [19:0] address,
      output bit [63:0] value
  );
    do_read(L1_AXI_BASE + address, value);
  endtask

  task automatic submit_commands(input int unsigned command_count);
    tvip_axi_data words[];
    tvip_axi_strobe strobes[];

    if ((command_count == 0) || (command_count > 8)) begin
      `uvm_fatal(
        "NPU_CORE",
        $sformatf("invalid command count %0d", command_count)
      )
    end

    words = new[2*command_count];
    strobes = new[2*command_count];
    for (int unsigned index = 0; index < command_count; index++) begin
      words[2*index] =
          tvip_axi_data'(command_words[index][63:0]);
      words[2*index+1] =
          tvip_axi_data'(command_words[index][127:64]);
      strobes[2*index] = tvip_axi_strobe'(8'hff);
      strobes[2*index+1] = tvip_axi_strobe'(8'hff);
    end

    do_write(
      CMD_FIFO_DATA,
      TVIP_AXI_FIXED_BURST,
      words,
      strobes
    );
  endtask

  task automatic read_command_response(
      input bit [11:0] expected_command_id,
      input bit [7:0] expected_status = STATUS_SUCCESS
  );
    bit [63:0] response;

    do_read(CMD_RSP_FIFO, response);
    if ((response[11:0] !== expected_command_id) ||
        (response[19:12] !== expected_status)) begin
      `uvm_error(
        "NPU_CORE",
        $sformatf(
          "command response mismatch: expected id/status=0x%03h/0x%02h actual=0x%03h/0x%02h",
          expected_command_id,
          expected_status,
          response[11:0],
          response[19:12]
        )
      )
    end
  endtask

  task automatic ctl_request(
      input bit [1:0] operation,
      input bit [63:0] argument0,
      input bit [63:0] argument1,
      output bit [63:0] result
  );
    bit [63:0] status;

    write_word(CTL_ARG0, argument0);
    write_word(CTL_ARG1, argument1);
    write_word(CTL_START, {62'd0, operation});
    status = 64'd0;
    for (int unsigned poll_count = 0;
         poll_count < 20000;
         poll_count++) begin
      do_read(CTL_STATUS, status);
      if (status[1]) begin
        break;
      end
    end

    if (!status[1] || status[0]) begin
      `uvm_fatal(
        "NPU_CORE",
        $sformatf(
          "control request timed out or stayed busy: status=0x%016h",
          status
        )
      )
    end
    if (status[15:8] != STATUS_SUCCESS) begin
      `uvm_error(
        "NPU_CORE",
        $sformatf(
          "control request status is 0x%02h",
          status[15:8]
        )
      )
    end
    do_read(CTL_RESULT, result);
  endtask

  task automatic query_task(
      input bit [11:0] command_id,
      input bit [2:0] selector,
      output bit [63:0] result
  );
    ctl_request(
      CTL_QUERY,
      {52'd0, command_id},
      {61'd0, selector},
      result
    );
  endtask

  task automatic acknowledge_task(input bit [11:0] command_id);
    bit [63:0] result;

    query_task(command_id, 3'd4, result);
    check_equal64(
      $sformatf("task 0x%03h ACK result", command_id),
      result,
      64'd0
    );
  endtask

  task automatic check_task_status(
      input bit [11:0] command_id,
      input bit [7:0] expected_status
  );
    bit [63:0] result;

    query_task(command_id, 3'd0, result);
    if ((result[3:0] !== 4'd3) ||
        (result[11:4] !== expected_status)) begin
      `uvm_error(
        "NPU_CORE",
        $sformatf(
          "task 0x%03h terminal data mismatch: 0x%016h",
          command_id,
          result
        )
      )
    end
  endtask

  task automatic run_all_checks();
    `uvm_info(
      "NPU_CORE",
      "start complete npu_single_core_top AXI/UVM test",
      UVM_LOW
    )

    write_word(CSR_CORE_CONTROL, 64'h1);
    write_word(CSR_L1_EXTERNAL_CONTROL, 64'h1);
    repeat (4) @(system_vif.monitor_cb);
    check_true(
      "NPU did not accept commands after CORE_CONTROL.START",
      system_vif.monitor_cb.accept_new_cmd === 1'b1
    );

    check_matrix_event_vector();
    check_dma();
    check_dma_writeback();
    check_complex();
    check_int16_vector();
    check_int16_matrix_pack();
    check_final_status();

    `uvm_info(
      "NPU_CORE",
      $sformatf(
        "complete single-core checks passed: system-memory reads=%0d writes=%0d",
        system_vif.monitor_cb.system_memory_read_handshakes,
        system_vif.monitor_cb.system_memory_write_handshakes
      ),
      UVM_LOW
    )
  endtask

  task automatic check_matrix_event_vector();
    bit [2047:0] matrix_desc;
    bit [2047:0] vector_desc;
    bit [63:0] result;

    `uvm_info(
      "NPU_CORE",
      "case: Matrix producer, Event wait and Vector consumer",
      UVM_LOW
    )

    l1_write_word(20'h00100, 64'h0000_0204_ff03_0201, 8'h3f);
    l1_write_word(20'h00200, 64'h0000_04fe_0103_ff02, 8'h3f);
    l1_write_word(20'h00300, 64'h0a07_0301_00ff_fcf8);
    l1_write_word(20'h00400, 64'h0101_0101_0101_0101);

    init_common(
      matrix_desc,
      8'h02,
      16'd256,
      64'h0100,
      64'h0200,
      64'd0,
      64'h0600,
      32'h0000_00a5
    );
    put_u32(matrix_desc, 16'h40, 32'd2);
    put_u32(matrix_desc, 16'h44, 32'd2);
    put_u32(matrix_desc, 16'h48, 32'd3);
    put_u32(matrix_desc, 16'h4c, 32'd1);
    put_u32(matrix_desc, 16'h50, 32'd2);
    put_u32(matrix_desc, 16'h54, 32'd2);
    put_u32(matrix_desc, 16'h58, 32'd3);
    put_u32(matrix_desc, 16'h5c, 32'h0000_0080);
    put_u32(matrix_desc, 16'h60, 32'd3);
    put_u32(matrix_desc, 16'h64, 32'd2);
    put_u32(matrix_desc, 16'h68, 32'd8);
    put_u8(matrix_desc, 16'h90, 8'd0);
    put_u8(matrix_desc, 16'h91, 8'd0);
    put_u8(matrix_desc, 16'h92, 8'd4);
    store_descriptor(64'h1000, matrix_desc, 256);

    init_common(
      vector_desc,
      8'h03,
      16'd192,
      64'h0300,
      64'h0400,
      64'd0,
      64'h0500,
      32'h0000_0055
    );
    put_u32(vector_desc, 16'h40, 32'd1);
    put_u32(vector_desc, 16'h44, 32'd8);
    put_u32(vector_desc, 16'h48, 32'd8);
    put_u32(vector_desc, 16'h50, 32'd1);
    put_u32(vector_desc, 16'h54, 32'd8);
    put_u32(vector_desc, 16'h58, 32'd1);
    put_u32(vector_desc, 16'h5c, 32'd8);
    put_u32(vector_desc, 16'h68, 32'd1);
    put_u32(vector_desc, 16'h6c, 32'd8);
    store_descriptor(64'h1100, vector_desc, 192);

    command_words[0] = make_command(
      48'h1000,
      12'h101,
      ENGINE_MATRIX,
      OPCODE_GEMM,
      EVENT_NONE,
      EVENT_NONE,
      12'h001
    );
    command_words[1] = make_command(
      48'h1100,
      12'h102,
      ENGINE_VECTOR,
      OPCODE_VADD_I,
      12'h001,
      EVENT_NONE,
      EVENT_NONE
    );
    submit_commands(2);
    read_command_response(12'h101);
    read_command_response(12'h102);

    ctl_request(CTL_WAIT, 64'h001, 64'd50000, result);
    check_true(
      "WAIT did not report Event success",
      (result[2:0] == EVENT_SUCCESS) &&
      (result[19:8] == 12'h101)
    );

    ctl_request(CTL_FENCE, 64'hf, 64'd50000, result);
    check_true(
      "Matrix/Event/Vector FENCE failed",
      result[7:0] == STATUS_SUCCESS
    );
    check_task_status(12'h101, STATUS_SUCCESS);
    query_task(12'h101, 3'd3, result);
    check_equal64("Matrix progress", result, 64'd4);
    check_task_status(12'h102, STATUS_SUCCESS);
    query_task(12'h102, 3'd3, result);
    check_equal64("Vector progress", result, 64'd8);

    l1_read_word(20'h00600, result);
    check_equal64(
      "Matrix result row 0",
      result,
      64'h0000_000d_0000_0002
    );
    l1_read_word(20'h00608, result);
    check_equal64(
      "Matrix result row 1",
      result,
      64'h0000_000d_0000_0006
    );
    l1_read_word(20'h00500, result);
    check_equal64(
      "Vector result",
      result,
      64'h0b08_0402_0100_fdf9
    );

    acknowledge_task(12'h101);
    acknowledge_task(12'h102);
    query_task(12'h101, 3'd0, result);
    check_true(
      "ACK did not release Matrix task",
      (result[3:0] == 4'd0) &&
      (result[11:4] == STATUS_NOT_FOUND)
    );
  endtask

  task automatic check_dma();
    bit [2047:0] descriptor;
    bit [63:0] result;

    `uvm_info(
      "NPU_CORE",
      "case: DMA system-memory-to-L1 transfer",
      UVM_LOW
    )

    system_vif.write_u64(
      64'h3000,
      64'h0a07_0301_00ff_fcf8
    );
    init_common(
      descriptor,
      8'h01,
      16'd256,
      64'h3000,
      64'd0,
      64'd0,
      64'h0900,
      32'h0000_0055
    );
    put_u8(descriptor, 16'h40, 8'd1);
    put_u8(descriptor, 16'h41, 8'd1);
    put_u8(descriptor, 16'h42, 8'd0);
    put_u8(descriptor, 16'h43, 8'd0);
    put_u8(descriptor, 16'h44, 8'd15);
    put_u8(descriptor, 16'h45, 8'd8);
    put_u32(descriptor, 16'h48, 32'd8);
    put_u64(descriptor, 16'h98, 64'd8);
    put_u64(descriptor, 16'ha0, 64'd8);
    store_descriptor(64'h1200, descriptor, 256);

    command_words[0] = make_command(
      48'h1200,
      12'h103,
      ENGINE_DMA,
      OPCODE_DMA_COPY_1D,
      EVENT_NONE,
      EVENT_NONE,
      EVENT_NONE
    );
    submit_commands(1);
    read_command_response(12'h103);
    ctl_request(CTL_FENCE, 64'h1, 64'd50000, result);
    check_true(
      "DMA FENCE failed",
      result[7:0] == STATUS_SUCCESS
    );
    query_task(12'h103, 3'd3, result);
    check_equal64("DMA progress", result, 64'd8);
    l1_read_word(20'h00900, result);
    check_equal64(
      "DMA destination",
      result,
      64'h0a07_0301_00ff_fcf8
    );
    acknowledge_task(12'h103);
  endtask

  task automatic check_dma_writeback();
    bit [2047:0] descriptor;
    bit [63:0] result;

    `uvm_info(
      "NPU_CORE",
      "case: DMA L1-to-system-memory writeback",
      UVM_LOW
    )

    l1_write_word(20'h00d00, 64'h8877_6655_4433_2211);
    system_vif.write_u64(64'h3100, 64'hdead_beef_cafe_5eed);
    init_common(
      descriptor,
      8'h01,
      16'd256,
      64'h0d00,
      64'd0,
      64'd0,
      64'h3100,
      32'h0000_0055
    );
    put_u8(descriptor, 16'h40, 8'd1);
    put_u8(descriptor, 16'h41, 8'd0);
    put_u8(descriptor, 16'h42, 8'd1);
    put_u8(descriptor, 16'h43, 8'd0);
    put_u8(descriptor, 16'h44, 8'd15);
    put_u8(descriptor, 16'h45, 8'd8);
    put_u32(descriptor, 16'h48, 32'd8);
    put_u64(descriptor, 16'h98, 64'd8);
    put_u64(descriptor, 16'ha0, 64'd8);
    store_descriptor(64'h1800, descriptor, 256);

    command_words[0] = make_command(
      48'h1800,
      12'h109,
      ENGINE_DMA,
      OPCODE_DMA_COPY_1D,
      EVENT_NONE,
      EVENT_NONE,
      EVENT_NONE
    );
    submit_commands(1);
    read_command_response(12'h109);
    ctl_request(CTL_FENCE, 64'h1, 64'd50000, result);
    check_true(
      "DMA writeback FENCE failed",
      result[7:0] == STATUS_SUCCESS
    );
    query_task(12'h109, 3'd3, result);
    check_equal64("DMA writeback progress", result, 64'd8);
    check_equal64(
      "DMA system-memory writeback data",
      system_vif.read_u64(64'h3100),
      64'h8877_6655_4433_2211
    );
    acknowledge_task(12'h109);
  endtask

  task automatic check_complex();
    bit [2047:0] descriptor;
    bit [63:0] result;

    `uvm_info(
      "NPU_CORE",
      "case: Complex activation integer to FP32 to integer",
      UVM_LOW
    )

    l1_write_word(20'h00700, 64'h0000_0000_0400_fffc, 8'h0f);
    init_common(
      descriptor,
      8'h04,
      16'd256,
      64'h0700,
      64'd0,
      64'd0,
      64'h0800,
      32'h0001_3055
    );
    put_u32(descriptor, 16'h40, 32'd1);
    put_u32(descriptor, 16'h44, 32'd4);
    put_u32(descriptor, 16'h48, 32'd4);
    put_u32(descriptor, 16'h4c, 32'd1);
    put_u32(descriptor, 16'h50, 32'd4);
    put_u32(descriptor, 16'h5c, 32'd4);
    put_u32(descriptor, 16'h70, 32'h3f80_0000);
    put_u32(descriptor, 16'h74, 32'h3f80_0000);
    put_u32(descriptor, 16'h78, 32'h3f80_0000);
    put_u32(descriptor, 16'h7c, 32'h3f80_0000);
    store_descriptor(64'h1300, descriptor, 256);

    command_words[0] = make_command(
      48'h1300,
      12'h104,
      ENGINE_COMPLEX,
      OPCODE_VACT_I,
      EVENT_NONE,
      EVENT_NONE,
      EVENT_NONE
    );
    submit_commands(1);
    read_command_response(12'h104);
    ctl_request(CTL_FENCE, 64'h8, 64'd50000, result);
    check_true(
      "Complex FENCE failed",
      result[7:0] == STATUS_SUCCESS
    );
    query_task(12'h104, 3'd3, result);
    check_equal64("Complex progress", result, 64'd4);
    l1_read_word(20'h00800, result);
    check_true(
      "Complex activation output mismatch",
      result[31:0] == 32'h0100_ffff
    );
    acknowledge_task(12'h104);
  endtask

  task automatic check_int16_vector();
    bit [2047:0] descriptor;
    bit [63:0] result;

    `uvm_info(
      "NPU_CORE",
      "case: INT16 dtype code 3 Vector ADD",
      UVM_LOW
    )

    l1_write_word(20'h00a00, 64'hfc70_012c_fffe_0001);
    l1_write_word(20'h00a10, 64'h0008_fff9_0006_0005);
    init_common(
      descriptor,
      8'h03,
      16'd192,
      64'h0a00,
      64'h0a10,
      64'd0,
      64'h0a20,
      32'h0000_00ff
    );
    put_u32(descriptor, 16'h40, 32'd1);
    put_u32(descriptor, 16'h44, 32'd4);
    put_u32(descriptor, 16'h48, 32'd4);
    put_u32(descriptor, 16'h4c, 32'd0);
    put_u32(descriptor, 16'h50, 32'd2);
    put_u32(descriptor, 16'h54, 32'd8);
    put_u32(descriptor, 16'h58, 32'd2);
    put_u32(descriptor, 16'h5c, 32'd8);
    put_u32(descriptor, 16'h60, 32'd2);
    put_u32(descriptor, 16'h64, 32'd8);
    put_u32(descriptor, 16'h68, 32'd2);
    put_u32(descriptor, 16'h6c, 32'd8);
    store_descriptor(64'h1400, descriptor, 192);

    command_words[0] = make_command(
      48'h1400,
      12'h105,
      ENGINE_VECTOR,
      OPCODE_VADD_I,
      EVENT_NONE,
      EVENT_NONE,
      EVENT_NONE
    );
    submit_commands(1);
    read_command_response(12'h105);
    ctl_request(CTL_FENCE, 64'h4, 64'd50000, result);
    check_true(
      "INT16 Vector FENCE failed",
      result[7:0] == STATUS_SUCCESS
    );
    check_task_status(12'h105, STATUS_SUCCESS);
    query_task(12'h105, 3'd3, result);
    check_equal64("INT16 Vector progress", result, 64'd4);
    l1_read_word(20'h00a20, result);
    check_equal64(
      "INT16 Vector result",
      result,
      64'hfc78_0125_0004_0006
    );
    acknowledge_task(12'h105);
  endtask

  task automatic check_int16_matrix_pack();
    bit [2047:0] descriptors [0:2];
    bit [63:0] result;
    bit [63:0] control_status;

    `uvm_info(
      "NPU_CORE",
      "case: INT16 Matrix pack 5/6 and reserved pack 7",
      UVM_LOW
    )

    l1_write_word(20'h00b00, 64'hffff_0003_0002_0001);
    l1_write_word(20'h00b08, 64'h0000_0000_0002_0004, 8'h0f);
    l1_write_word(20'h00b20, 64'h0001_0003_ffff_0002);
    l1_write_word(20'h00b28, 64'h0000_0000_0004_fffe, 8'h0f);
    l1_write_word(20'h00b40, 64'h0000_0000_ffff_0002, 8'h0f);
    l1_write_word(20'h00b50, 64'h0000_0000_0001_0003, 8'h0f);
    l1_write_word(20'h00b60, 64'h0000_0000_0004_fffe, 8'h0f);

    for (int unsigned index = 0; index < 2; index++) begin
      init_common(
        descriptors[index],
        8'h02,
        16'd256,
        64'h0b00,
        index == 0 ? 64'h0b20 : 64'h0b40,
        64'd0,
        index == 0 ? 64'h0c00 : 64'h0c20,
        32'h0000_00af
      );
      put_u32(descriptors[index], 16'h40, 32'd2);
      put_u32(descriptors[index], 16'h44, 32'd2);
      put_u32(descriptors[index], 16'h48, 32'd3);
      put_u32(descriptors[index], 16'h4c, 32'd1);
      put_u32(descriptors[index], 16'h50, 32'd2);
      put_u32(descriptors[index], 16'h54, 32'd2);
      put_u32(descriptors[index], 16'h58, 32'd3);
      put_u32(descriptors[index], 16'h5c, 32'h0000_0080);
      put_u32(descriptors[index], 16'h60, 32'd6);
      put_u32(descriptors[index], 16'h64, 32'd4);
      put_u32(descriptors[index], 16'h68, 32'd8);
      put_u8(descriptors[index], 16'h90, 8'd5);
      put_u8(
        descriptors[index],
        16'h91,
        index == 0 ? 8'd5 : 8'd6
      );
      put_u8(descriptors[index], 16'h92, 8'd4);
      store_descriptor(
        64'h1500 + index * 64'h100,
        descriptors[index],
        256
      );
      command_words[index] = make_command(
        48'(64'h1500 + index * 64'h100),
        12'(12'h106 + index),
        ENGINE_MATRIX,
        OPCODE_GEMM,
        EVENT_NONE,
        EVENT_NONE,
        EVENT_NONE
      );
    end

    descriptors[2] = descriptors[0];
    put_u64(descriptors[2], 16'h20, 64'h0c40);
    put_u8(descriptors[2], 16'h90, 8'd7);
    store_descriptor(64'h1700, descriptors[2], 256);
    command_words[2] = make_command(
      48'h1700,
      12'h108,
      ENGINE_MATRIX,
      OPCODE_GEMM,
      EVENT_NONE,
      EVENT_NONE,
      EVENT_NONE
    );

    submit_commands(3);
    read_command_response(12'h106);
    read_command_response(12'h107);
    read_command_response(12'h108);

    write_word(CTL_ARG0, 64'h2);
    write_word(CTL_ARG1, 64'd50000);
    write_word(CTL_START, 64'd3);
    write_word(CTL_CANCEL, 64'd1);
    do_read(CTL_STATUS, control_status);
    check_true(
      "CTL_CANCEL did not report ABORTED",
      control_status[1] &&
      !control_status[0] &&
      (control_status[15:8] == STATUS_ABORTED)
    );
    do_read(CTL_RESULT, result);
    check_true(
      "CTL_CANCEL result is not ABORTED",
      result[7:0] == STATUS_ABORTED
    );

    ctl_request(CTL_FENCE, 64'h2, 64'd50000, result);
    check_true(
      "Matrix FENCE did not report reserved pack failure",
      result[7:0] == STATUS_BAD_DESC
    );

    for (int unsigned index = 0; index < 3; index++) begin
      check_task_status(
        12'(12'h106 + index),
        index < 2 ? STATUS_SUCCESS : STATUS_BAD_DESC
      );
      query_task(12'(12'h106 + index), 3'd3, result);
      check_equal64(
        $sformatf(
          "INT16 Matrix command 0x%03h progress",
          12'h106 + index
        ),
        result,
        index < 2 ? 64'd4 : 64'd0
      );
      acknowledge_task(12'(12'h106 + index));
    end

    l1_read_word(20'h00c00, result);
    check_equal64(
      "linear INT16 Matrix row 0",
      result,
      64'h0000_000d_0000_0002
    );
    l1_read_word(20'h00c08, result);
    check_equal64(
      "linear INT16 Matrix row 1",
      result,
      64'h0000_000d_0000_0006
    );
    l1_read_word(20'h00c20, result);
    check_equal64(
      "tiled INT16 Matrix row 0",
      result,
      64'h0000_000d_0000_0002
    );
    l1_read_word(20'h00c28, result);
    check_equal64(
      "tiled INT16 Matrix row 1",
      result,
      64'h0000_000d_0000_0006
    );
    l1_read_word(20'h00c40, result);
    check_equal64(
      "reserved pack 7 destination",
      result,
      64'd0
    );
  endtask

  task automatic check_final_status();
    repeat (8) @(system_vif.monitor_cb);

    check_true(
      "system-bus memory model detected a protocol error",
      system_vif.monitor_cb.system_memory_protocol_error === 1'b0
    );
    check_true(
      "DMA writeback did not issue eight system-memory writes",
      system_vif.monitor_cb.system_memory_write_handshakes == 32'd8
    );
    check_true(
      "NPU issued no system-memory reads",
      system_vif.monitor_cb.system_memory_read_handshakes != 32'd0
    );
    check_true(
      "watchdog unexpectedly requested reset",
      system_vif.monitor_cb.wdt_reset_req === 1'b0
    );
    check_true(
      "masked interrupt unexpectedly asserted",
      (system_vif.monitor_cb.irq_done === 1'b0) &&
      (system_vif.monitor_cb.irq_exception === 1'b0) &&
      (system_vif.monitor_cb.irq_error === 1'b0)
    );
  endtask

  `uvm_object_utils(axi_tvip_npu_single_core_sequence)
endclass
