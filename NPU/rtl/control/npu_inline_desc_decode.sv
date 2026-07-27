module npu_inline_desc_decode (
  /* verilator lint_off UNUSEDSIGNAL */
  input  logic [127:0]  cmd_i,
  /* verilator lint_on UNUSEDSIGNAL */
  input  logic [47:0]   input_base_i,
  input  logic [47:0]   weight_base_i,
  input  logic [47:0]   work_base_i,
  input  logic [47:0]   output_base_i,
  input  logic [47:0]   kv_base_i,
  /* verilator lint_off UNUSEDSIGNAL */
  input  logic [19:0]   param_l1_base_i,
  /* verilator lint_on UNUSEDSIGNAL */
  output logic           valid_o,
  output logic [3:0]     engine_o,
  output logic [7:0]     opcode_o,
  output logic [2047:0] desc_flat_o
);
  import npu_rtl_pkg::*;

  logic [5:0]  command_opcode_full;
  logic [5:0]  command_opcode;
  logic [79:0] payload;
  logic [1:0]  header_dtype;
  logic [27:0] src_aref;
  logic [27:0] dst_aref;
  logic [63:0] src_addr;
  logic [63:0] dst_addr;
  logic [31:0] count;
  logic [31:0] rows;
  logic [31:0] length;
  logic [31:0] row_bytes_src;
  logic [31:0] row_bytes_dst;
  logic [31:0] numeric_cfg;
  logic [1:0]  src_dtype;
  logic [1:0]  src1_dtype;
  logic [1:0]  src2_dtype;
  logic [1:0]  dst_dtype;
  logic [31:0] matrix_m;
  logic [31:0] matrix_n;
  logic [31:0] matrix_k;
  logic [31:0] batch_count;
  logic [31:0] matrix_flags;
  logic [31:0] vector_flags;
  logic [7:0]  broadcast_mode;
  logic [31:0] function_mode;
  logic [31:0] mask_mode;
  logic [63:0] aux_addr;
  logic [63:0] beta_addr;

  function automatic logic [2:0] dtype_bytes_value(
    input logic [1:0] dtype
  );
    unique case (dtype)
      NPU_DTYPE_INT8:  return 3'd1;
      NPU_DTYPE_INT16: return 3'd2;
      NPU_DTYPE_INT32: return 3'd4;
      default:         return 3'd1;
    endcase
  endfunction

  function automatic logic [2:0] dtype_rank(
    input logic [1:0] dtype
  );
    unique case (dtype)
      NPU_DTYPE_INT4:  return 3'd0;
      NPU_DTYPE_INT8:  return 3'd1;
      NPU_DTYPE_INT16: return 3'd2;
      default:         return 3'd3;
    endcase
  endfunction

  function automatic logic [31:0] storage_bytes(
    input logic [31:0] elements,
    input logic [1:0] dtype
  );
    if (dtype == NPU_DTYPE_INT4)
      return (elements + 1'b1) >> 1;
    return elements * dtype_bytes_value(dtype);
  endfunction

  function automatic logic [31:0] storage_bytes_nibble(
    input logic [31:0] elements,
    input logic [1:0] dtype,
    input logic start_nibble
  );
    if (dtype == NPU_DTYPE_INT4)
      return (elements + {31'd0, start_nibble} + 1'b1) >> 1;
    return elements * dtype_bytes_value(dtype);
  endfunction

  function automatic logic [31:0] matrix_tail(
    input logic [31:0] size,
    input logic [31:0] tile
  );
    if (size == 0)
      return 32'd0;
    if ((size % tile) == 0)
      return tile;
    return size % tile;
  endfunction

  function automatic logic [7:0] matrix_pack_a(
    input logic [1:0] dtype
  );
    unique case (dtype)
      NPU_DTYPE_INT4:  return 8'd1;
      NPU_DTYPE_INT8:  return 8'd0;
      NPU_DTYPE_INT16: return 8'd5;
      default:         return 8'd4;
    endcase
  endfunction

  function automatic logic [7:0] matrix_pack_b_tiled(
    input logic [1:0] dtype
  );
    unique case (dtype)
      NPU_DTYPE_INT4:  return 8'd3;
      NPU_DTYPE_INT8:  return 8'd2;
      NPU_DTYPE_INT16: return 8'd6;
      default:         return 8'd4;
    endcase
  endfunction

  function automatic logic [7:0] matrix_pack_c(
    input logic [1:0] dtype
  );
    unique case (dtype)
      NPU_DTYPE_INT4:  return 8'd1;
      NPU_DTYPE_INT8:  return 8'd0;
      NPU_DTYPE_INT16: return 8'd5;
      default:         return 8'd4;
    endcase
  endfunction

  function automatic logic [31:0] broadcast_row_bytes(
    input logic [31:0] columns,
    input logic [1:0] dtype,
    input logic [1:0] mode
  );
    unique case (mode)
      2'd0: return storage_bytes(columns, dtype);
      2'd2: return dtype == NPU_DTYPE_INT4
                   ? 32'd1 : {29'd0, dtype_bytes_value(dtype)};
      default: return 32'd0;
    endcase
  endfunction

  function automatic logic [31:0] fp32_pow2(
    input logic [3:0] exponent
  );
    unique case (exponent)
      4'h0: return 32'h3f80_0000;
      4'h1: return 32'h4000_0000;
      4'h2: return 32'h4080_0000;
      4'h3: return 32'h4100_0000;
      4'h4: return 32'h4180_0000;
      4'h5: return 32'h4200_0000;
      4'h6: return 32'h4280_0000;
      4'h7: return 32'h4300_0000;
      4'h8: return 32'h3b80_0000;
      4'h9: return 32'h3c00_0000;
      4'ha: return 32'h3c80_0000;
      4'hb: return 32'h3d00_0000;
      4'hc: return 32'h3d80_0000;
      4'hd: return 32'h3e00_0000;
      4'he: return 32'h3e80_0000;
      default: return 32'h3f00_0000;
    endcase
  endfunction

  function automatic logic [31:0] epsilon_bits(
    input logic [1:0] profile
  );
    unique case (profile)
      2'd0: return 32'h3727_c5ac;
      2'd1: return 32'h3586_37bd;
      2'd2: return 32'h3a83_126f;
      default: return 32'h38d1_b717;
    endcase
  endfunction

  function automatic logic [63:0] lref14_addr(
    input logic [13:0] reference
  );
    return {44'd0, reference, 6'd0};
  endfunction

  function automatic logic [63:0] lref12_addr(
    input logic [11:0] reference
  );
    return {46'd0, reference, 6'd0};
  endfunction

  function automatic logic [63:0] lref16_addr(
    input logic [15:0] reference
  );
    return {44'd0, reference, 4'd0};
  endfunction

  function automatic logic [47:0] aref_base(
    input logic [2:0] base_select
  );
    unique case (base_select)
      3'd0: return 48'd0;
      3'd1: return input_base_i;
      3'd2: return weight_base_i;
      3'd3: return work_base_i;
      3'd4: return output_base_i;
      3'd5: return kv_base_i;
      default: return 48'd0;
    endcase
  endfunction

  function automatic logic aref_valid(input logic [27:0] reference);
    /* verilator lint_off UNUSEDSIGNAL */
    logic [48:0] address_sum;
    /* verilator lint_on UNUSEDSIGNAL */
    begin
      address_sum =
        {1'b0, aref_base(reference[26:24])} +
        {25'd0, reference[23:0]};
      if (!reference[27])
        return (reference[26:24] == 3'd0) &&
               (reference[23:20] == 4'd0);
      return (reference[26:24] <= 3'd5) && !address_sum[48];
    end
  endfunction

  function automatic logic [63:0] aref_addr(input logic [27:0] reference);
    logic [47:0] address_sum;
    begin
      if (!reference[27])
        return {44'd0, reference[19:0]};
      address_sum =
        aref_base(reference[26:24]) +
        {24'd0, reference[23:0]};
      return {16'd0, address_sum};
    end
  endfunction

  always_comb begin
    command_opcode_full = cmd_i[127:122];
    command_opcode = command_opcode_full;
    payload = cmd_i[79:0];
    header_dtype = cmd_i[81:80];
    engine_o = npu_cmd_engine_from_opcode(command_opcode_full);
    opcode_o = npu_cmd_expanded_opcode(command_opcode_full);
    valid_o = npu_cmd_opcode_valid(command_opcode_full);
    desc_flat_o = 2048'd0;

    src_aref = payload[79:52];
    dst_aref = payload[51:24];
    src_addr = aref_addr(src_aref);
    dst_addr = aref_addr(dst_aref);
    count = {12'd0, payload[23:4]};
    rows = {24'd0, payload[23:16]};
    length = {24'd0, payload[15:8]};
    row_bytes_src = 32'd0;
    row_bytes_dst = 32'd0;
    numeric_cfg = 32'd0;
    src_dtype = header_dtype;
    src1_dtype = header_dtype;
    src2_dtype = header_dtype;
    dst_dtype = header_dtype;
    matrix_m = 32'd0;
    matrix_n = 32'd0;
    matrix_k = 32'd0;
    batch_count = 32'd1;
    matrix_flags = 32'd0;
    vector_flags = 32'd0;
    broadcast_mode = 8'd0;
    function_mode = 32'd0;
    mask_mode = 32'd0;
    aux_addr = 64'd0;
    beta_addr = 64'd0;

    desc_flat_o[7:0] = 8'h01;
    desc_flat_o[15:8] = {4'd0, engine_o};
    desc_flat_o[31:16] = npu_desc_bytes_for_engine(engine_o);
    desc_flat_o[511:480] = {22'd0, cmd_i[121:112]};

    unique case (command_opcode)
      6'd0, 6'd1, 6'd2, 6'd3, 6'd4: begin
        desc_flat_o[31:16] = 16'd64;
        desc_flat_o[64 +: 64] =
          {52'd0, npu_cmd_event_ref(cmd_i[111:104])};
        desc_flat_o[128 +: 64] =
          {52'd0, npu_cmd_event_ref(cmd_i[103:96])};
        desc_flat_o[256 +: 64] =
          {52'd0, npu_cmd_event_ref(cmd_i[95:88])};
        desc_flat_o[320 +: 64] = {60'd0, payload[79:76]};
        desc_flat_o[39:32] = {7'd0, payload[75]};
        valid_o = valid_o && (payload[74:0] == 75'd0);
        unique case (command_opcode)
          6'd0:
            valid_o = valid_o &&
              (cmd_i[111:88] == 24'hff_ffff) &&
              (payload[79:75] == 5'd0);
          6'd1, 6'd2:
            valid_o = valid_o &&
              (cmd_i[111:96] == 16'hffff) &&
              (cmd_i[95:88] != 8'hff) &&
              (payload[79:75] == 5'd0);
          6'd3:
            valid_o = valid_o &&
              (cmd_i[111:104] != 8'hff) &&
              (cmd_i[103:96] != 8'hff) &&
              (cmd_i[95:88] != 8'hff) &&
              (cmd_i[111:104] != cmd_i[103:96]) &&
              (payload[79:76] == 4'd0);
          default:
            valid_o = valid_o &&
              (cmd_i[111:96] == 16'hffff) &&
              (payload[79:76] != 4'd0) &&
              !payload[75];
        endcase
      end

      6'd5, 6'd6: begin
        dst_dtype = payload[3:2];
        numeric_cfg[1:0] = src_dtype;
        numeric_cfg[3:2] = src_dtype;
        numeric_cfg[5:4] = src_dtype;
        numeric_cfg[7:6] = dst_dtype;
        valid_o = valid_o && aref_valid(src_aref) &&
                  aref_valid(dst_aref) && (count != 0) && !payload[0];
        desc_flat_o[39:32] = {
          4'd0, dst_aref[27], 2'd0, src_aref[27]
        };
        desc_flat_o[64 +: 64] = src_addr;
        desc_flat_o[256 +: 64] = dst_addr;
        desc_flat_o[448 +: 32] = numeric_cfg;
        desc_flat_o[16'h40 * 8 +: 8] = 8'd1;
        desc_flat_o[16'h41 * 8 +: 8] = {7'd0, src_aref[27]};
        desc_flat_o[16'h42 * 8 +: 8] = {7'd0, dst_aref[27]};
        if (dtype_rank(src_dtype) == dtype_rank(dst_dtype))
          desc_flat_o[16'h43 * 8 +: 8] = 8'd0;
        else if (dtype_rank(src_dtype) < dtype_rank(dst_dtype))
          desc_flat_o[16'h43 * 8 +: 8] = 8'd1;
        else if ((dst_dtype == NPU_DTYPE_INT4) &&
                 (src_dtype != NPU_DTYPE_INT4))
          desc_flat_o[16'h43 * 8 +: 8] = 8'd3;
        else
          desc_flat_o[16'h43 * 8 +: 8] = 8'd2;
        desc_flat_o[16'h44 * 8 +: 8] = 8'd7;
        desc_flat_o[16'h45 * 8 +: 8] = 8'd1;
        desc_flat_o[16'h46 * 8] = payload[1];
        desc_flat_o[16'h47 * 8] = payload[0];
        desc_flat_o[16'h48 * 8 +: 32] = count;
        desc_flat_o[16'h98 * 8 +: 64] =
          {32'd0, storage_bytes_nibble(count, src_dtype, payload[1])};
        desc_flat_o[16'ha0 * 8 +: 64] =
          {32'd0, storage_bytes_nibble(count, dst_dtype, payload[0])};
      end

      6'd7: begin
        count = {12'd0, payload[51:32]};
        dst_aref = payload[79:52];
        dst_addr = aref_addr(dst_aref);
        numeric_cfg[1:0] = header_dtype;
        numeric_cfg[3:2] = header_dtype;
        numeric_cfg[5:4] = header_dtype;
        numeric_cfg[7:6] = header_dtype;
        valid_o = valid_o && aref_valid(dst_aref) && (count != 0);
        desc_flat_o[39:32] = {4'd0, dst_aref[27], 3'd0};
        desc_flat_o[256 +: 64] = dst_addr;
        desc_flat_o[448 +: 32] = numeric_cfg;
        desc_flat_o[16'h40 * 8 +: 8] = 8'd1;
        desc_flat_o[16'h41 * 8 +: 8] = 8'd0;
        desc_flat_o[16'h42 * 8 +: 8] = {7'd0, dst_aref[27]};
        desc_flat_o[16'h43 * 8 +: 8] = 8'd0;
        desc_flat_o[16'h44 * 8 +: 8] = 8'd7;
        desc_flat_o[16'h45 * 8 +: 8] = 8'd1;
        desc_flat_o[16'h48 * 8 +: 32] = count;
        desc_flat_o[16'h90 * 8 +: 32] = payload[31:0];
        desc_flat_o[16'ha0 * 8 +: 64] =
          {32'd0, storage_bytes(count, header_dtype)};
      end

      6'd8: begin
        dst_dtype = payload[7:6];
        rows = {24'd0, payload[23:16]};
        length = {24'd0, payload[15:8]};
        row_bytes_src =
          storage_bytes_nibble(length, src_dtype, payload[5]);
        row_bytes_dst =
          storage_bytes_nibble(rows, dst_dtype, payload[4]);
        numeric_cfg[1:0] = src_dtype;
        numeric_cfg[3:2] = src_dtype;
        numeric_cfg[5:4] = src_dtype;
        numeric_cfg[7:6] = dst_dtype;
        valid_o = valid_o && aref_valid(src_aref) &&
                  aref_valid(dst_aref) && (src_dtype == dst_dtype) &&
                  (rows != 0) && (length != 0) && !payload[4] &&
                  (payload[3:0] == 4'd0);
        desc_flat_o[39:32] = {
          4'd0, dst_aref[27], 2'd0, src_aref[27]
        };
        desc_flat_o[64 +: 64] = src_addr;
        desc_flat_o[256 +: 64] = dst_addr;
        desc_flat_o[448 +: 32] = numeric_cfg;
        desc_flat_o[16'h40 * 8 +: 8] = 8'd2;
        desc_flat_o[16'h41 * 8 +: 8] = {7'd0, src_aref[27]};
        desc_flat_o[16'h42 * 8 +: 8] = {7'd0, dst_aref[27]};
        desc_flat_o[16'h44 * 8 +: 8] = 8'd7;
        desc_flat_o[16'h45 * 8 +: 8] = 8'd1;
        desc_flat_o[16'h46 * 8] = payload[5];
        desc_flat_o[16'h47 * 8] = payload[4];
        desc_flat_o[16'h48 * 8 +: 32] = rows;
        desc_flat_o[16'h4c * 8 +: 32] = length;
        desc_flat_o[16'h60 * 8 +: 32] = row_bytes_src;
        desc_flat_o[16'h78 * 8 +: 32] = row_bytes_dst;
        desc_flat_o[16'h98 * 8 +: 64] =
          {32'd0, rows * row_bytes_src};
        desc_flat_o[16'ha0 * 8 +: 64] =
          {32'd0, length * row_bytes_dst};
      end

      6'd9, 6'd10: begin
        count = {24'd0, payload[23:16]};
        rows = {24'd0, payload[15:8]};
        length = {24'd0, payload[7:0]};
        numeric_cfg[1:0] = header_dtype;
        numeric_cfg[3:2] = header_dtype;
        numeric_cfg[5:4] = header_dtype;
        numeric_cfg[7:6] = header_dtype;
        valid_o = valid_o && aref_valid(src_aref) &&
                  aref_valid(dst_aref) && (count != 0) &&
                  (rows != 0) && (length >= rows);
        desc_flat_o[39:32] = {
          4'd0, dst_aref[27], 2'd0, src_aref[27]
        };
        desc_flat_o[64 +: 64] = src_addr;
        desc_flat_o[256 +: 64] = dst_addr;
        desc_flat_o[448 +: 32] = numeric_cfg;
        desc_flat_o[16'h40 * 8 +: 8] = 8'd1;
        desc_flat_o[16'h41 * 8 +: 8] = {7'd0, src_aref[27]};
        desc_flat_o[16'h42 * 8 +: 8] = {7'd0, dst_aref[27]};
        desc_flat_o[16'h44 * 8 +: 8] = 8'd7;
        desc_flat_o[16'h45 * 8 +: 8] = 8'd1;
        desc_flat_o[16'h48 * 8 +: 32] = count;
        desc_flat_o[16'h98 * 8 +: 64] =
          command_opcode == 6'd9
            ? {32'd0, (count - 1'b1) * length + rows}
            : {32'd0, count * rows};
        desc_flat_o[16'ha0 * 8 +: 64] =
          command_opcode == 6'd9
            ? {32'd0, count * rows}
            : {32'd0, (count - 1'b1) * length + rows};
        desc_flat_o[16'ha8 * 8 +: 16] = count[15:0];
        desc_flat_o[16'haa * 8 +: 16] = rows[15:0];
        desc_flat_o[16'hac * 8 +: 32] = length;
      end

      6'd12, 6'd14, 6'd15: begin
        matrix_m = {26'd0, payload[25:20]} + 1'b1;
        matrix_n = {26'd0, payload[19:14]} + 1'b1;
        matrix_k = {26'd0, payload[13:8]} + 1'b1;
        src_dtype = header_dtype;
        src1_dtype =
          (header_dtype == NPU_DTYPE_INT8) && payload[7]
            ? NPU_DTYPE_INT4 : header_dtype;
        src2_dtype = NPU_DTYPE_INT32;
        dst_dtype = payload[6:5];
        numeric_cfg[1:0] = src_dtype;
        numeric_cfg[3:2] = src1_dtype;
        numeric_cfg[5:4] = src2_dtype;
        numeric_cfg[7:6] = dst_dtype;
        numeric_cfg[12] = 1'b1;
        desc_flat_o[64 +: 64] = lref14_addr(payload[79:66]);
        desc_flat_o[128 +: 64] = lref14_addr(payload[65:52]);
        desc_flat_o[256 +: 64] = lref14_addr(payload[51:38]);
        desc_flat_o[320 +: 64] = lref12_addr(payload[37:26]);
        desc_flat_o[448 +: 32] = numeric_cfg;
        desc_flat_o[16'h40 * 8 +: 32] = matrix_m;
        desc_flat_o[16'h44 * 8 +: 32] = matrix_n;
        desc_flat_o[16'h48 * 8 +: 32] = matrix_k;
        desc_flat_o[16'h4c * 8 +: 32] = 32'd1;
        desc_flat_o[16'h50 * 8 +: 32] = matrix_tail(matrix_m, 32'd8);
        desc_flat_o[16'h54 * 8 +: 32] = matrix_tail(matrix_n, 32'd8);
        desc_flat_o[16'h58 * 8 +: 32] = matrix_tail(matrix_k, 32'd16);
        matrix_flags[2] =
          (command_opcode == 6'd12) && (payload[37:26] != 12'd0);
        matrix_flags[5] =
          (command_opcode == 6'd12) && (dst_dtype != NPU_DTYPE_INT32);
        matrix_flags[6] = command_opcode == 6'd14;
        matrix_flags[7] = command_opcode == 6'd12;
        desc_flat_o[16'h5c * 8 +: 32] = matrix_flags;
        desc_flat_o[16'h60 * 8 +: 32] =
          storage_bytes(matrix_k, src_dtype);
        desc_flat_o[16'h64 * 8 +: 32] =
          storage_bytes(matrix_n, src1_dtype);
        desc_flat_o[16'h68 * 8 +: 32] =
          storage_bytes(matrix_n, dst_dtype);
        desc_flat_o[16'h6c * 8 +: 32] = 32'd4;
        desc_flat_o[16'h70 * 8 +: 64] =
          {32'd0, matrix_m * storage_bytes(matrix_k, src_dtype)};
        desc_flat_o[16'h78 * 8 +: 64] =
          {32'd0,
           ((matrix_k + 15) >> 4) * ((matrix_n + 7) >> 3) *
           storage_bytes(32'd128, src1_dtype)};
        desc_flat_o[16'h80 * 8 +: 64] =
          {32'd0, matrix_m * storage_bytes(matrix_n, dst_dtype)};
        desc_flat_o[16'h88 * 8 +: 64] =
          {32'd0, matrix_m * matrix_n * 4};
        desc_flat_o[16'h90 * 8 +: 8] = matrix_pack_a(src_dtype);
        desc_flat_o[16'h91 * 8 +: 8] =
          matrix_pack_b_tiled(src1_dtype);
        desc_flat_o[16'h92 * 8 +: 8] = matrix_pack_c(dst_dtype);
        desc_flat_o[16'h94 * 8 +: 8] = 8'd0;
        if (matrix_flags[2])
          desc_flat_o[16'ha0 * 8 +: 32] = matrix_n;
        if (matrix_flags[5]) begin
          desc_flat_o[16'h9c * 8 +: 32] = 32'd1;
          desc_flat_o[16'ha4 * 8 +: 8] = 8'd1;
          desc_flat_o[16'ha6 * 8 +: 8] = 8'd8;
          desc_flat_o[16'ha8 * 8 +: 32] = 32'd8;
          desc_flat_o[16'hb0 * 8] = 1'b1;
          desc_flat_o[16'hb1 * 8 +: 8] =
            {3'd0, payload[4:0]};
        end
        if (command_opcode == 6'd14) begin
          desc_flat_o[192 +: 64] = lref14_addr(payload[51:38]);
          valid_o = valid_o && (dst_dtype == NPU_DTYPE_INT32) &&
                    (payload[37:26] == 12'd0) &&
                    (payload[4:0] == 5'd0) &&
                    (!payload[7] ||
                     (src_dtype == NPU_DTYPE_INT8)) &&
                    ((src_dtype == NPU_DTYPE_INT4) ||
                     (src_dtype == NPU_DTYPE_INT8) ||
                     (src_dtype == NPU_DTYPE_INT16));
        end else if (command_opcode == 6'd15) begin
          valid_o = valid_o && (dst_dtype == NPU_DTYPE_INT32) &&
                    (payload[79:66] == 14'd0) &&
                    (payload[65:52] == 14'd0) &&
                    (payload[37:26] == 12'd0) &&
                    (payload[13:8] == 6'd0) &&
                    !payload[7] &&
                    (payload[4:0] == 5'd0);
          numeric_cfg = 32'd0;
          numeric_cfg[7:6] = NPU_DTYPE_INT32;
          desc_flat_o[64 +: 192] = 192'd0;
          desc_flat_o[320 +: 128] = 128'd0;
          desc_flat_o[448 +: 32] = numeric_cfg;
          desc_flat_o[16'h48 * 8 +: 32] = 32'd0;
          desc_flat_o[16'h58 * 8 +: 32] = 32'd0;
          desc_flat_o[16'h5c * 8 +: 32] = 32'd0;
          desc_flat_o[16'h60 * 8 +: 64] = 64'd0;
          desc_flat_o[16'h6c * 8 +: 32] = 32'd0;
          desc_flat_o[16'h70 * 8 +: 128] = 128'd0;
          desc_flat_o[16'h88 * 8 +: 64] = 64'd0;
          desc_flat_o[16'h90 * 8 +: 8] =
            matrix_pack_a(NPU_DTYPE_INT4);
          desc_flat_o[16'h91 * 8 +: 8] =
            matrix_pack_b_tiled(NPU_DTYPE_INT4);
          desc_flat_o[16'h92 * 8 +: 8] =
            matrix_pack_c(NPU_DTYPE_INT32);
        end else begin
          valid_o = valid_o &&
            ((dst_dtype != NPU_DTYPE_INT32) ||
             (payload[4:0] == 5'd0)) &&
            (!payload[7] ||
             (src_dtype == NPU_DTYPE_INT8)) &&
            ((src_dtype == NPU_DTYPE_INT4) ||
             (src_dtype == NPU_DTYPE_INT8) ||
             (src_dtype == NPU_DTYPE_INT16));
        end
      end

      6'd13: begin
        batch_count = {26'd0, payload[37:32]} + 1'b1;
        matrix_m = {26'd0, payload[31:26]} + 1'b1;
        matrix_n = {26'd0, payload[25:20]} + 1'b1;
        matrix_k = {26'd0, payload[19:14]} + 1'b1;
        src_dtype = header_dtype;
        src1_dtype =
          (header_dtype == NPU_DTYPE_INT8) && payload[13]
            ? NPU_DTYPE_INT4 : header_dtype;
        src2_dtype = NPU_DTYPE_INT32;
        dst_dtype = payload[12:11];
        numeric_cfg[1:0] = src_dtype;
        numeric_cfg[3:2] = src1_dtype;
        numeric_cfg[5:4] = src2_dtype;
        numeric_cfg[7:6] = dst_dtype;
        numeric_cfg[12] = 1'b1;
        valid_o = valid_o && (payload[5:0] == 6'd0) &&
          ((dst_dtype != NPU_DTYPE_INT32) ||
           (payload[10:6] == 5'd0)) &&
          (!payload[13] ||
           (src_dtype == NPU_DTYPE_INT8)) &&
          ((src_dtype == NPU_DTYPE_INT4) ||
           (src_dtype == NPU_DTYPE_INT8) ||
           (src_dtype == NPU_DTYPE_INT16));
        desc_flat_o[64 +: 64] = lref14_addr(payload[79:66]);
        desc_flat_o[128 +: 64] = lref14_addr(payload[65:52]);
        desc_flat_o[256 +: 64] = lref14_addr(payload[51:38]);
        desc_flat_o[448 +: 32] = numeric_cfg;
        desc_flat_o[16'h40 * 8 +: 32] = matrix_m;
        desc_flat_o[16'h44 * 8 +: 32] = matrix_n;
        desc_flat_o[16'h48 * 8 +: 32] = matrix_k;
        desc_flat_o[16'h4c * 8 +: 32] = batch_count;
        desc_flat_o[16'h50 * 8 +: 32] = matrix_tail(matrix_m, 32'd8);
        desc_flat_o[16'h54 * 8 +: 32] = matrix_tail(matrix_n, 32'd8);
        desc_flat_o[16'h58 * 8 +: 32] = matrix_tail(matrix_k, 32'd16);
        matrix_flags[5] = dst_dtype != NPU_DTYPE_INT32;
        matrix_flags[7] = 1'b1;
        desc_flat_o[16'h5c * 8 +: 32] = matrix_flags;
        desc_flat_o[16'h60 * 8 +: 32] =
          storage_bytes(matrix_k, src_dtype);
        desc_flat_o[16'h64 * 8 +: 32] =
          storage_bytes(matrix_n, src1_dtype);
        desc_flat_o[16'h68 * 8 +: 32] =
          storage_bytes(matrix_n, dst_dtype);
        desc_flat_o[16'h6c * 8 +: 32] = 32'd4;
        desc_flat_o[16'h70 * 8 +: 64] =
          {32'd0, matrix_m * storage_bytes(matrix_k, src_dtype)};
        desc_flat_o[16'h78 * 8 +: 64] =
          {32'd0,
           ((matrix_k + 15) >> 4) * ((matrix_n + 7) >> 3) *
           storage_bytes(32'd128, src1_dtype)};
        desc_flat_o[16'h80 * 8 +: 64] =
          {32'd0, matrix_m * storage_bytes(matrix_n, dst_dtype)};
        desc_flat_o[16'h88 * 8 +: 64] =
          {32'd0, matrix_m * matrix_n * 4};
        desc_flat_o[16'h90 * 8 +: 8] = matrix_pack_a(src_dtype);
        desc_flat_o[16'h91 * 8 +: 8] =
          matrix_pack_b_tiled(src1_dtype);
        desc_flat_o[16'h92 * 8 +: 8] = matrix_pack_c(dst_dtype);
        desc_flat_o[16'h94 * 8 +: 8] = 8'd0;
        if (matrix_flags[5]) begin
          desc_flat_o[16'h9c * 8 +: 32] = 32'd1;
          desc_flat_o[16'ha4 * 8 +: 8] = 8'd1;
          desc_flat_o[16'ha6 * 8 +: 8] = 8'd8;
          desc_flat_o[16'ha8 * 8 +: 32] = 32'd8;
          desc_flat_o[16'hb0 * 8] = 1'b1;
          desc_flat_o[16'hb1 * 8 +: 8] =
            {3'd0, payload[10:6]};
        end
      end

      6'd16, 6'd17, 6'd18, 6'd19, 6'd20,
      6'd21, 6'd22, 6'd23, 6'd24, 6'd25: begin
        rows = {27'd0, payload[15:11]} + 1'b1;
        length = {27'd0, payload[10:6]} + 1'b1;
        src_dtype = header_dtype;
        src1_dtype = header_dtype;
        src2_dtype = header_dtype;
        dst_dtype = header_dtype;
        broadcast_mode = {
          2'd0, payload[1:0], payload[3:2], payload[5:4]
        };
        if (command_opcode == 6'd18) begin
          dst_dtype = NPU_DTYPE_INT32;
        end else if (command_opcode == 6'd19) begin
          dst_dtype = NPU_DTYPE_INT32;
          src2_dtype = NPU_DTYPE_INT32;
        end else if (command_opcode == 6'd22) begin
          dst_dtype = NPU_DTYPE_INT8;
        end
        numeric_cfg[1:0] = src_dtype;
        numeric_cfg[3:2] = src1_dtype;
        numeric_cfg[5:4] = src2_dtype;
        numeric_cfg[7:6] = dst_dtype;
        desc_flat_o[64 +: 64] = lref16_addr(payload[79:64]);
        desc_flat_o[128 +: 64] = lref16_addr(payload[63:48]);
        desc_flat_o[192 +: 64] = lref16_addr(payload[47:32]);
        desc_flat_o[256 +: 64] = lref16_addr(payload[31:16]);
        desc_flat_o[448 +: 32] = numeric_cfg;
        desc_flat_o[16'h40 * 8 +: 32] = rows;
        desc_flat_o[16'h44 * 8 +: 32] = length;
        desc_flat_o[16'h48 * 8 +: 32] = length;
        desc_flat_o[16'h50 * 8 +: 32] =
          {29'd0, dtype_bytes_value(src_dtype)};
        desc_flat_o[16'h54 * 8 +: 32] =
          broadcast_row_bytes(length, src_dtype, payload[5:4]);
        desc_flat_o[16'h58 * 8 +: 32] =
          {29'd0, dtype_bytes_value(src1_dtype)};
        desc_flat_o[16'h5c * 8 +: 32] =
          broadcast_row_bytes(length, src1_dtype, payload[3:2]);
        desc_flat_o[16'h60 * 8 +: 32] =
          {29'd0, dtype_bytes_value(src2_dtype)};
        desc_flat_o[16'h64 * 8 +: 32] =
          broadcast_row_bytes(length, src2_dtype, payload[1:0]);
        desc_flat_o[16'h68 * 8 +: 32] =
          {29'd0, dtype_bytes_value(dst_dtype)};
        desc_flat_o[16'h6c * 8 +: 32] =
          storage_bytes(length, dst_dtype);
        desc_flat_o[16'h78 * 8 +: 8] = broadcast_mode;
        desc_flat_o[16'h7a * 8 +: 8] = 8'd0;
        valid_o = valid_o &&
          (((command_opcode == 6'd19) ||
            (command_opcode == 6'd22) ||
            (command_opcode == 6'd23) ||
            (command_opcode == 6'd24)) ||
           (payload[47:32] == 16'd0));
        if (command_opcode == 6'd22) begin
          desc_flat_o[192 +: 64] = 64'd0;
          desc_flat_o[16'h79 * 8 +: 8] =
            {5'd0, payload[47:45]};
          valid_o = valid_o && (payload[44:32] == 13'd0) &&
                    (payload[47:45] <= 3'd5) &&
                    (payload[1:0] == 2'd0);
        end
        if (command_opcode == 6'd23) begin
          vector_flags[0] = 1'b1;
          desc_flat_o[192 +: 64] = 64'd0;
          desc_flat_o[320 +: 64] = lref16_addr(payload[47:32]);
          desc_flat_o[16'h7b * 8 +: 8] = 8'd1;
          desc_flat_o[16'h90 * 8 +: 32] = 32'd1;
          desc_flat_o[16'h94 * 8 +: 32] = length;
          valid_o = valid_o && (payload[1:0] == 2'd0);
        end
        if (command_opcode == 6'd24) begin
          desc_flat_o[128 +: 64] = 64'd0;
          desc_flat_o[192 +: 64] = 64'd0;
          desc_flat_o[16'h70 * 8 +: 32] =
            {{16{payload[63]}}, payload[63:48]};
          desc_flat_o[16'h74 * 8 +: 32] =
            {{16{payload[47]}}, payload[47:32]};
          valid_o = valid_o &&
                    (payload[3:0] == 4'd0) &&
                    ($signed(payload[63:48]) <=
                     $signed(payload[47:32]));
        end
        if (command_opcode == 6'd25) begin
          desc_flat_o[128 +: 64] = 64'd0;
          desc_flat_o[192 +: 64] = 64'd0;
          valid_o = valid_o && (payload[63:32] == 32'd0) &&
                    (payload[3:0] == 4'd0);
        end
        desc_flat_o[16'h4c * 8 +: 32] = vector_flags;
      end

      6'd26, 6'd27, 6'd28, 6'd30, 6'd32: begin
        rows = {27'd0, payload[31:27]} + 1'b1;
        length = {24'd0, payload[26:19]} + 1'b1;
        src_dtype = header_dtype;
        src1_dtype = header_dtype;
        src2_dtype = header_dtype;
        dst_dtype = header_dtype;
        aux_addr = lref16_addr(payload[63:48]);
        row_bytes_src = storage_bytes(length, src_dtype);
        desc_flat_o[64 +: 64] = lref16_addr(payload[79:64]);
        desc_flat_o[256 +: 64] = lref16_addr(payload[47:32]);
        desc_flat_o[16'h40 * 8 +: 32] = rows;
        desc_flat_o[16'h44 * 8 +: 32] = length;
        desc_flat_o[16'h48 * 8 +: 32] = length;
        desc_flat_o[16'h50 * 8 +: 32] = row_bytes_src;
        desc_flat_o[16'h5c * 8 +: 32] =
          storage_bytes(length, dst_dtype);

        unique case (command_opcode)
          6'd26: begin
            function_mode = {30'd0, payload[18:17]};
            dst_dtype = payload[8:7];
            numeric_cfg[1:0] = src_dtype;
            numeric_cfg[3:2] = src_dtype;
            numeric_cfg[5:4] = src_dtype;
            numeric_cfg[7:6] = dst_dtype;
            numeric_cfg[12] = 1'b1;
            numeric_cfg[14:13] = 2'd1;
            numeric_cfg[16] = 1'b1;
            desc_flat_o[16'h70 * 8 +: 32] =
              fp32_pow2(payload[16:13]);
            desc_flat_o[16'h7c * 8 +: 32] =
              fp32_pow2(payload[12:9]);
            unique case (payload[6:5])
              2'd0: begin
                desc_flat_o[16'h94 * 8 +: 32] = 32'hc180_0000;
                desc_flat_o[16'h98 * 8 +: 32] = 32'h4180_0000;
              end
              2'd1: begin
                desc_flat_o[16'h94 * 8 +: 32] = 32'hc100_0000;
                desc_flat_o[16'h98 * 8 +: 32] = 32'h4100_0000;
              end
              2'd2: begin
                desc_flat_o[16'h94 * 8 +: 32] = 32'hc080_0000;
                desc_flat_o[16'h98 * 8 +: 32] = 32'h4080_0000;
              end
              default: begin
                desc_flat_o[16'h94 * 8 +: 32] = 32'hc000_0000;
                desc_flat_o[16'h98 * 8 +: 32] = 32'h4000_0000;
              end
            endcase
            valid_o = valid_o && (payload[4:0] == 5'd0) &&
                      (payload[63:48] == 16'd0);
          end

          6'd27: begin
            function_mode = 32'd4;
            mask_mode = {30'd0, payload[18:17]};
            dst_dtype = payload[7:6];
            numeric_cfg[1:0] = src_dtype;
            numeric_cfg[3:2] = src_dtype;
            numeric_cfg[5:4] = src_dtype;
            numeric_cfg[7:6] = dst_dtype;
            numeric_cfg[12] = 1'b1;
            numeric_cfg[14:13] = 2'd1;
            numeric_cfg[16] = 1'b1;
            desc_flat_o[16'h70 * 8 +: 32] =
              fp32_pow2(payload[15:12]);
            desc_flat_o[16'h7c * 8 +: 32] =
              fp32_pow2(payload[11:8]);
            desc_flat_o[16'h9e * 8 +: 8] = {7'd0, payload[16]};
            desc_flat_o[16'hb0 * 8 +: 32] = length;
            desc_flat_o[16'h94 * 8 +: 32] = 32'hc180_0000;
            desc_flat_o[16'h98 * 8 +: 32] = 32'h4180_0000;
            if (mask_mode == 32'd1) begin
              desc_flat_o[16'h60 * 8 +: 64] = aux_addr;
              desc_flat_o[16'h68 * 8 +: 32] = length;
            end else if (mask_mode == 32'd3) begin
              desc_flat_o[16'hc0 * 8 +: 64] = aux_addr;
              desc_flat_o[16'hc8 * 8 +: 32] = 32'd4;
            end
            valid_o = valid_o && (payload[5:0] == 6'd0) &&
              (((mask_mode == 32'd0) &&
                (payload[63:48] == 16'd0)) ||
               (mask_mode == 32'd1 || mask_mode == 32'd3)) &&
              (mask_mode != 32'd2);
          end

          6'd28: begin
            function_mode = payload[18] ? 32'd6 : 32'd5;
            dst_dtype = payload[3:2];
            beta_addr =
              aux_addr + (({32'd0, storage_bytes(length, src_dtype)} +
                           64'd63) & ~64'd63);
            numeric_cfg[1:0] = src_dtype;
            numeric_cfg[3:2] = src_dtype;
            numeric_cfg[5:4] = src_dtype;
            numeric_cfg[7:6] = dst_dtype;
            numeric_cfg[12] = 1'b1;
            numeric_cfg[14:13] = 2'd1;
            numeric_cfg[16] = 1'b1;
            desc_flat_o[128 +: 64] = aux_addr;
            desc_flat_o[192 +: 64] =
              payload[18] ? 64'd0 : beta_addr;
            desc_flat_o[16'h54 * 8 +: 32] = 32'd0;
            desc_flat_o[16'h58 * 8 +: 32] = 32'd0;
            desc_flat_o[16'h70 * 8 +: 32] =
              fp32_pow2(payload[15:12]);
            desc_flat_o[16'h74 * 8 +: 32] =
              fp32_pow2(payload[11:8]);
            desc_flat_o[16'h78 * 8 +: 32] =
              fp32_pow2(payload[11:8]);
            desc_flat_o[16'h7c * 8 +: 32] =
              fp32_pow2(payload[7:4]);
            desc_flat_o[16'h90 * 8 +: 32] =
              epsilon_bits(payload[17:16]);
            desc_flat_o[16'hb0 * 8 +: 32] = length;
            valid_o = valid_o && (payload[1:0] == 2'd0) &&
                      (beta_addr[63:20] == 44'd0);
          end

          6'd30: begin
            function_mode = 32'd7 + {30'd0, payload[18:17]};
            dst_dtype = NPU_DTYPE_INT32;
            numeric_cfg[1:0] = src_dtype;
            numeric_cfg[3:2] = src_dtype;
            numeric_cfg[5:4] = src_dtype;
            numeric_cfg[7:6] = dst_dtype;
            numeric_cfg[12] = 1'b1;
            desc_flat_o[16'h5c * 8 +: 32] = 32'd4;
            valid_o = valid_o && (payload[18:17] <= 2'd2) &&
                      (payload[16:0] == 17'd0) &&
                      (payload[63:48] == 16'd0);
          end

          default: begin
            function_mode = 32'd12;
            dst_dtype = payload[6:5];
            numeric_cfg[1:0] = src_dtype;
            numeric_cfg[3:2] = src_dtype;
            numeric_cfg[5:4] = src_dtype;
            numeric_cfg[7:6] = dst_dtype;
            numeric_cfg[12] = 1'b1;
            numeric_cfg[14:13] = 2'd1;
            numeric_cfg[16] = 1'b1;
            desc_flat_o[128 +: 64] = aux_addr;
            desc_flat_o[16'h54 * 8 +: 32] =
              storage_bytes(length, src1_dtype);
            desc_flat_o[16'h70 * 8 +: 32] =
              fp32_pow2(payload[18:15]);
            desc_flat_o[16'h74 * 8 +: 32] =
              fp32_pow2(payload[14:11]);
            desc_flat_o[16'h7c * 8 +: 32] =
              fp32_pow2(payload[10:7]);
            valid_o = valid_o && (payload[4:0] == 5'd0);
          end
        endcase
        desc_flat_o[448 +: 32] = numeric_cfg;
        desc_flat_o[16'h4c * 8 +: 32] = function_mode;
        desc_flat_o[16'h5c * 8 +: 32] =
          command_opcode == 6'd30
            ? 32'd4 : storage_bytes(length, dst_dtype);
        desc_flat_o[16'h6c * 8 +: 32] = mask_mode;
      end

      default: valid_o = 1'b0;
    endcase
  end

endmodule
