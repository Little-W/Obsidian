package npu_rtl_pkg;

  /* verilator lint_off UNUSEDPARAM */
  localparam int unsigned NPU_DATA_W         = 64;
  localparam int unsigned NPU_GADDR_W        = 48;
  localparam int unsigned NPU_L1_ADDR_W      = 20;
  localparam int unsigned NPU_CMD_W          = 128;
  localparam int unsigned NPU_DESC_W         = 2048;
  localparam int unsigned NPU_DESC_MAX_BYTES = NPU_DESC_W / 8;
  /* verilator lint_on UNUSEDPARAM */

  typedef enum logic [1:0] {
    NPU_DTYPE_INT4  = 2'd0,
    NPU_DTYPE_INT8  = 2'd1,
    NPU_DTYPE_INT32 = 2'd2,
    NPU_DTYPE_INT16 = 2'd3
  } npu_dtype_e;

  typedef enum logic [3:0] {
    NPU_ENGINE_CONTROL = 4'h0,
    NPU_ENGINE_DMA     = 4'h1,
    NPU_ENGINE_MATRIX  = 4'h2,
    NPU_ENGINE_VECTOR  = 4'h3,
    NPU_ENGINE_COMPLEX = 4'h4
  } npu_engine_e;

  typedef enum logic [7:0] {
    NPU_STATUS_SUCCESS              = 8'h00,
    NPU_STATUS_ILLEGAL_OPCODE       = 8'h01,
    NPU_STATUS_BAD_DESC             = 8'h02,
    NPU_STATUS_BAD_SHAPE            = 8'h03,
    NPU_STATUS_ADDR_FAULT           = 8'h04,
    NPU_STATUS_BUS_DECERR           = 8'h05,
    NPU_STATUS_BUS_SLVERR           = 8'h06,
    NPU_STATUS_DTYPE_UNSUPPORTED    = 8'h07,
    NPU_STATUS_DEPENDENCY_FAILED    = 8'h08,
    NPU_STATUS_TIMEOUT              = 8'h09,
    NPU_STATUS_ABORTED              = 8'h0a,
    NPU_STATUS_L1_ECC_UNCORRECTABLE = 8'h0b,
    NPU_STATUS_NUMERIC_EXCEPTION    = 8'h0c,
    NPU_STATUS_ADDR_OVERLAP         = 8'h0d
  } npu_status_e;

  typedef enum logic [2:0] {
    NPU_MEM_OK       = 3'd0,
    NPU_MEM_ADDR     = 3'd1,
    NPU_MEM_PERM     = 3'd2,
    NPU_MEM_SLVERR   = 3'd3,
    NPU_MEM_DECERR   = 3'd4,
    NPU_MEM_PROTOCOL = 3'd5
  } npu_mem_status_e;

  typedef enum logic [2:0] {
    NPU_L1_OK             = 3'd0,
    NPU_L1_ECC_CORRECTED  = 3'd1,
    NPU_L1_ECC_UNCORRECT  = 3'd2,
    NPU_L1_PROTOCOL_ERROR = 3'd3,
    NPU_L1_ADDR_FAULT     = 3'd4
  } npu_l1_status_e;

  typedef enum logic [2:0] {
    NPU_EVENT_FREE    = 3'd0,
    NPU_EVENT_PENDING = 3'd1,
    NPU_EVENT_SUCCESS = 3'd2,
    NPU_EVENT_ERROR   = 3'd3
  } npu_event_state_e;

  typedef enum logic [3:0] {
    NPU_TASK_FREE        = 4'd0,
    NPU_TASK_FETCH_DESC  = 4'd1,
    NPU_TASK_WAIT_EVENT  = 4'd2,
    NPU_TASK_READY       = 4'd3,
    NPU_TASK_RUNNING     = 4'd4,
    NPU_TASK_SUCCESS     = 4'd5,
    NPU_TASK_ERROR       = 4'd6
  } npu_task_state_e;

  localparam logic [11:0] NPU_EVENT_NONE = 12'hfff;
  /* verilator lint_off UNUSEDPARAM */
  localparam logic [7:0] NPU_STATUS_NOT_FOUND = 8'h81;

  localparam logic [1:0] NPU_CTL_WAIT  = 2'd1;
  localparam logic [1:0] NPU_CTL_QUERY = 2'd2;
  localparam logic [1:0] NPU_CTL_FENCE = 2'd3;
  /* verilator lint_on UNUSEDPARAM */

  localparam logic [7:0] NPU_OPCODE_NOP              = 8'h00;
  localparam logic [7:0] NPU_OPCODE_EVENT_SIGNAL     = 8'h01;
  localparam logic [7:0] NPU_OPCODE_EVENT_REARM      = 8'h02;
  localparam logic [7:0] NPU_OPCODE_EVENT_JOIN       = 8'h03;
  localparam logic [7:0] NPU_OPCODE_GLOBAL_FENCE     = 8'h04;
  localparam logic [7:0] NPU_OPCODE_DMA_COPY_1D      = 8'h20;
  localparam logic [7:0] NPU_OPCODE_DMA_COPY_ND      = 8'h21;
  localparam logic [7:0] NPU_OPCODE_DMA_FILL         = 8'h22;
  localparam logic [7:0] NPU_OPCODE_DMA_TRANSPOSE_2D = 8'h23;
  localparam logic [7:0] NPU_OPCODE_DMA_PACK         = 8'h24;
  localparam logic [7:0] NPU_OPCODE_DMA_SPLIT        = 8'h25;
  localparam logic [7:0] NPU_OPCODE_GEMM             = 8'h40;
  localparam logic [7:0] NPU_OPCODE_BMM              = 8'h41;
  localparam logic [7:0] NPU_OPCODE_GEMM_ACCUM       = 8'h42;
  localparam logic [7:0] NPU_OPCODE_GEMM_ZERO        = 8'h43;
  localparam logic [7:0] NPU_OPCODE_VADD_I           = 8'h60;
  localparam logic [7:0] NPU_OPCODE_VSUB_I           = 8'h61;
  localparam logic [7:0] NPU_OPCODE_VMUL_I           = 8'h62;
  localparam logic [7:0] NPU_OPCODE_VFMA_I           = 8'h63;
  localparam logic [7:0] NPU_OPCODE_VMAX_I           = 8'h64;
  localparam logic [7:0] NPU_OPCODE_VMIN_I           = 8'h65;
  localparam logic [7:0] NPU_OPCODE_VCMP_I           = 8'h66;
  localparam logic [7:0] NPU_OPCODE_VSEL_I           = 8'h67;
  localparam logic [7:0] NPU_OPCODE_VCLAMP_I         = 8'h68;
  localparam logic [7:0] NPU_OPCODE_VRELU_I          = 8'h69;
  localparam logic [7:0] NPU_OPCODE_VACT_I           = 8'h80;
  localparam logic [7:0] NPU_OPCODE_VSOFTMAX_I       = 8'h81;
  localparam logic [7:0] NPU_OPCODE_VNORM_I          = 8'h82;
  localparam logic [7:0] NPU_OPCODE_VSTAT_I          = 8'h84;
  localparam logic [7:0] NPU_OPCODE_VADD_RESCALE_I   = 8'h86;

  function automatic logic npu_dtype_valid(input logic [1:0] dtype);
    return dtype inside {
      NPU_DTYPE_INT4,
      NPU_DTYPE_INT8,
      NPU_DTYPE_INT32,
      NPU_DTYPE_INT16
    };
  endfunction

  /* verilator lint_off UNUSEDSIGNAL */
  function automatic logic npu_numeric_cfg_valid(input logic [31:0] cfg);
    logic dtype_fields_valid;
    begin
      dtype_fields_valid =
          npu_dtype_valid(cfg[1:0])
        & npu_dtype_valid(cfg[3:2])
        & npu_dtype_valid(cfg[5:4])
        & npu_dtype_valid(cfg[7:6]);
      // acc_dtype uses its own encoding: zero denotes an INT32 accumulator.
      return dtype_fields_valid & (cfg[9:8] == 2'd0) & (cfg[31:17] == 15'd0);
    end
  endfunction
  /* verilator lint_on UNUSEDSIGNAL */

  function automatic logic npu_event_ref_valid(input logic [11:0] event_ref);
    return (event_ref == NPU_EVENT_NONE) || (event_ref[7:0] != 8'hff);
  endfunction

  function automatic logic npu_opcode_engine_valid(
    input logic [3:0] engine,
    input logic [7:0] opcode
  );
    begin
      unique case (engine)
        NPU_ENGINE_CONTROL: begin
          return opcode inside {
            NPU_OPCODE_NOP,
            NPU_OPCODE_EVENT_SIGNAL,
            NPU_OPCODE_EVENT_REARM,
            NPU_OPCODE_EVENT_JOIN,
            NPU_OPCODE_GLOBAL_FENCE
          };
        end
        NPU_ENGINE_DMA: begin
          return opcode inside {
            NPU_OPCODE_DMA_COPY_1D,
            NPU_OPCODE_DMA_COPY_ND,
            NPU_OPCODE_DMA_FILL,
            NPU_OPCODE_DMA_TRANSPOSE_2D,
            NPU_OPCODE_DMA_PACK,
            NPU_OPCODE_DMA_SPLIT
          };
        end
        NPU_ENGINE_MATRIX: begin
          return opcode inside {
            NPU_OPCODE_GEMM,
            NPU_OPCODE_BMM,
            NPU_OPCODE_GEMM_ACCUM,
            NPU_OPCODE_GEMM_ZERO
          };
        end
        NPU_ENGINE_VECTOR: begin
          return opcode inside {
            NPU_OPCODE_VADD_I,
            NPU_OPCODE_VSUB_I,
            NPU_OPCODE_VMUL_I,
            NPU_OPCODE_VFMA_I,
            NPU_OPCODE_VMAX_I,
            NPU_OPCODE_VMIN_I,
            NPU_OPCODE_VCMP_I,
            NPU_OPCODE_VSEL_I,
            NPU_OPCODE_VCLAMP_I,
            NPU_OPCODE_VRELU_I
          };
        end
        NPU_ENGINE_COMPLEX: begin
          return opcode inside {
            NPU_OPCODE_VACT_I,
            NPU_OPCODE_VSOFTMAX_I,
            NPU_OPCODE_VNORM_I,
            NPU_OPCODE_VSTAT_I,
            NPU_OPCODE_VADD_RESCALE_I
          };
        end
        default: return 1'b0;
      endcase
    end
  endfunction

  function automatic logic [15:0] npu_desc_bytes_for_engine(input logic [3:0] engine);
    unique case (engine)
      NPU_ENGINE_CONTROL: return 16'd64;
      NPU_ENGINE_VECTOR:  return 16'd192;
      NPU_ENGINE_DMA,
      NPU_ENGINE_MATRIX,
      NPU_ENGINE_COMPLEX: return 16'd256;
      default:            return 16'd0;
    endcase
  endfunction

  function automatic logic [7:0] npu_mem_to_task_status(input logic [2:0] status);
    unique case (status)
      NPU_MEM_OK:       return NPU_STATUS_SUCCESS;
      NPU_MEM_ADDR,
      NPU_MEM_PERM:     return NPU_STATUS_ADDR_FAULT;
      NPU_MEM_SLVERR:   return NPU_STATUS_BUS_SLVERR;
      NPU_MEM_DECERR:   return NPU_STATUS_BUS_DECERR;
      default:          return NPU_STATUS_BAD_DESC;
    endcase
  endfunction

endpackage
