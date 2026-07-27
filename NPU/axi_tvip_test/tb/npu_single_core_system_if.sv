`ifndef NPU_SINGLE_CORE_SYSTEM_IF_SV
`define NPU_SINGLE_CORE_SYSTEM_IF_SV

interface npu_single_core_system_if #(
    parameter int unsigned MEMORY_BYTES = 1 << 16
) (
    input logic clk,
    input logic reset_n
);
    logic full_core_mode;
    logic system_memory_backpressure_enable;

    logic accept_new_cmd;
    logic core_idle;
    logic wdt_reset_req;
    logic irq_done;
    logic irq_exception;
    logic irq_error;

    logic [31:0] system_memory_read_handshakes;
    logic [31:0] system_memory_aw_handshakes;
    logic [31:0] system_memory_write_handshakes;
    logic system_memory_protocol_error;

    logic [7:0] system_memory [0:MEMORY_BYTES-1];

    task automatic clear_memory();
        for (int unsigned index = 0; index < MEMORY_BYTES; index++) begin
            system_memory[index] = 8'd0;
        end
    endtask

    task automatic load_memory_hex(input string file_name);
        $readmemh(file_name, system_memory);
    endtask

    task automatic write_byte(
        input longint unsigned address,
        input logic [7:0] value
    );
        if (address >= 64'(MEMORY_BYTES)) begin
            $fatal(
                1,
                "system-memory preload address 0x%0h exceeds %0d-byte model",
                address,
                MEMORY_BYTES
            );
        end
        system_memory[int'(address)] = value;
    endtask

    task automatic write_u32(
        input longint unsigned address,
        input logic [31:0] value
    );
        for (int unsigned index = 0; index < 4; index++) begin
            write_byte(address + 64'(index), value[index*8 +: 8]);
        end
    endtask

    task automatic write_u64(
        input longint unsigned address,
        input logic [63:0] value
    );
        for (int unsigned index = 0; index < 8; index++) begin
            write_byte(address + 64'(index), value[index*8 +: 8]);
        end
    endtask

    function automatic logic [63:0] read_u64(
        input longint unsigned address
    );
        logic [63:0] value;
        value = 64'd0;
        for (int unsigned index = 0; index < 8; index++) begin
            if ((address + 64'(index)) < 64'(MEMORY_BYTES)) begin
                value[index*8 +: 8] =
                    system_memory[int'(address + 64'(index))];
            end
        end
        return value;
    endfunction

    clocking monitor_cb @(posedge clk);
        input reset_n;
        input full_core_mode;
        input accept_new_cmd;
        input core_idle;
        input wdt_reset_req;
        input irq_done;
        input irq_exception;
        input irq_error;
        input system_memory_read_handshakes;
        input system_memory_aw_handshakes;
        input system_memory_write_handshakes;
        input system_memory_protocol_error;
    endclocking
endinterface

typedef virtual npu_single_core_system_if npu_single_core_system_vif;

`endif
