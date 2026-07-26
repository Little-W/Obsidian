`ifndef NPU_CMD_BACKEND_IF_SV
`define NPU_CMD_BACKEND_IF_SV

interface npu_cmd_backend_if (
    input logic clk,
    input logic reset_n
);
    logic        cmd_valid;
    logic        cmd_ready;
    logic [63:0] cmd_data;
    logic        cmd_first;
    logic        cmd_last;

    logic        cmd_rsp_valid;
    logic        cmd_rsp_ready;
    logic [63:0] cmd_rsp_data;

    logic        protocol_error_clear;
    logic        cmd_ingress_idle;
    logic        awlock;
    logic        arlock;

    clocking driver_cb @(posedge clk, negedge reset_n);
        input  cmd_valid;
        output cmd_ready;
        input  cmd_data;
        input  cmd_first;
        input  cmd_last;
        output cmd_rsp_valid;
        input  cmd_rsp_ready;
        output cmd_rsp_data;
        output protocol_error_clear;
        input  cmd_ingress_idle;
        output awlock;
        output arlock;
    endclocking

    clocking monitor_cb @(posedge clk);
        input reset_n;
        input cmd_valid;
        input cmd_ready;
        input cmd_data;
        input cmd_first;
        input cmd_last;
        input cmd_rsp_valid;
        input cmd_rsp_ready;
        input cmd_rsp_data;
        input protocol_error_clear;
        input cmd_ingress_idle;
        input awlock;
        input arlock;
    endclocking
endinterface

typedef virtual npu_cmd_backend_if npu_cmd_backend_vif;

`endif
