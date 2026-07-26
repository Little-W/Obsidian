package npu_engine_pkg;

  localparam logic [7:0] NPU_STATUS_SUCCESS           = 8'h00;
  localparam logic [7:0] NPU_STATUS_ILLEGAL_OPCODE    = 8'h01;
  localparam logic [7:0] NPU_STATUS_BAD_DESC          = 8'h02;
  localparam logic [7:0] NPU_STATUS_BAD_SHAPE         = 8'h03;
  localparam logic [7:0] NPU_STATUS_ADDR_FAULT        = 8'h04;
  localparam logic [7:0] NPU_STATUS_BUS_DECERR        = 8'h05;
  localparam logic [7:0] NPU_STATUS_BUS_SLVERR        = 8'h06;
  localparam logic [7:0] NPU_STATUS_DTYPE_UNSUPPORTED = 8'h07;
  localparam logic [7:0] NPU_STATUS_NUMERIC_EXCEPTION = 8'h0c;
  localparam logic [7:0] NPU_STATUS_ADDR_OVERLAP      = 8'h0d;

  localparam logic [7:0] NPU_DMA_COPY_1D      = 8'h20;
  localparam logic [7:0] NPU_DMA_COPY_ND      = 8'h21;
  localparam logic [7:0] NPU_DMA_FILL         = 8'h22;
  localparam logic [7:0] NPU_DMA_TRANSPOSE_2D = 8'h23;
  localparam logic [7:0] NPU_DMA_PACK         = 8'h24;
  localparam logic [7:0] NPU_DMA_SPLIT        = 8'h25;

  localparam logic [7:0] NPU_MATRIX_GEMM       = 8'h40;
  localparam logic [7:0] NPU_MATRIX_BMM        = 8'h41;
  localparam logic [7:0] NPU_MATRIX_GEMM_ACCUM = 8'h42;
  localparam logic [7:0] NPU_MATRIX_GEMM_ZERO  = 8'h43;

  localparam logic [7:0] NPU_VECTOR_ADD    = 8'h60;
  localparam logic [7:0] NPU_VECTOR_SUB    = 8'h61;
  localparam logic [7:0] NPU_VECTOR_MUL    = 8'h62;
  localparam logic [7:0] NPU_VECTOR_FMA    = 8'h63;
  localparam logic [7:0] NPU_VECTOR_MAX    = 8'h64;
  localparam logic [7:0] NPU_VECTOR_MIN    = 8'h65;
  localparam logic [7:0] NPU_VECTOR_CMP    = 8'h66;
  localparam logic [7:0] NPU_VECTOR_SELECT = 8'h67;
  localparam logic [7:0] NPU_VECTOR_CLAMP  = 8'h68;
  localparam logic [7:0] NPU_VECTOR_RELU   = 8'h69;

  localparam logic [7:0] NPU_COMPLEX_ACT         = 8'h80;
  localparam logic [7:0] NPU_COMPLEX_SOFTMAX     = 8'h81;
  localparam logic [7:0] NPU_COMPLEX_NORM        = 8'h82;
  localparam logic [7:0] NPU_COMPLEX_STAT        = 8'h84;
  localparam logic [7:0] NPU_COMPLEX_ADD_RESCALE = 8'h86;

  localparam logic [1:0] NPU_DTYPE_INT4  = 2'd0;
  localparam logic [1:0] NPU_DTYPE_INT8  = 2'd1;
  localparam logic [1:0] NPU_DTYPE_INT32 = 2'd2;
  localparam logic [1:0] NPU_DTYPE_INT16 = 2'd3;

  function automatic logic dtype_valid(input logic [1:0] dtype);
    case (dtype)
      NPU_DTYPE_INT4,
      NPU_DTYPE_INT8,
      NPU_DTYPE_INT32,
      NPU_DTYPE_INT16: return 1'b1;
      default:         return 1'b0;
    endcase
  endfunction

  function automatic logic [5:0] dtype_width(input logic [1:0] dtype);
    case (dtype)
      NPU_DTYPE_INT4:  return 6'd4;
      NPU_DTYPE_INT8:  return 6'd8;
      NPU_DTYPE_INT32: return 6'd32;
      NPU_DTYPE_INT16: return 6'd16;
      default:         return 6'd0;
    endcase
  endfunction

  function automatic logic [2:0] dtype_bytes(input logic [1:0] dtype);
    case (dtype)
      NPU_DTYPE_INT8:  return 3'd1;
      NPU_DTYPE_INT32: return 3'd4;
      NPU_DTYPE_INT16: return 3'd2;
      default:         return 3'd0;
    endcase
  endfunction

  function automatic logic [2:0] dtype_storage_bytes(
    input logic [1:0] dtype
  );
    if (dtype == NPU_DTYPE_INT4)
      return 3'd1;
    return dtype_bytes(dtype);
  endfunction

  function automatic logic signed [63:0] dtype_min(input logic [1:0] dtype);
    case (dtype)
      NPU_DTYPE_INT4:  return -64'sd8;
      NPU_DTYPE_INT8:  return -64'sd128;
      NPU_DTYPE_INT32: return -64'sd2147483648;
      NPU_DTYPE_INT16: return -64'sd32768;
      default:         return 64'sd0;
    endcase
  endfunction

  function automatic logic signed [63:0] dtype_max(input logic [1:0] dtype);
    case (dtype)
      NPU_DTYPE_INT4:  return 64'sd7;
      NPU_DTYPE_INT8:  return 64'sd127;
      NPU_DTYPE_INT32: return 64'sd2147483647;
      NPU_DTYPE_INT16: return 64'sd32767;
      default:         return 64'sd0;
    endcase
  endfunction

  function automatic logic signed [63:0] load_element(
    input logic [63:0] beat,
    input logic [2:0]  byte_lane,
    input logic        high_nibble,
    input logic [1:0]  dtype
  );
    logic [7:0]  byte_value;
    logic [3:0]  nibble_value;
    logic [15:0] half_value;
    logic [31:0] word_value;
    begin
      byte_value = beat[byte_lane * 8 +: 8];
      nibble_value = high_nibble ? byte_value[7:4] : byte_value[3:0];
      half_value = beat[byte_lane * 8 +: 16];
      word_value = beat[byte_lane * 8 +: 32];
      case (dtype)
        NPU_DTYPE_INT4:
          load_element = {{60{nibble_value[3]}}, nibble_value};
        NPU_DTYPE_INT8:
          load_element = {{56{byte_value[7]}}, byte_value};
        NPU_DTYPE_INT32:
          load_element = {{32{word_value[31]}}, word_value};
        NPU_DTYPE_INT16:
          load_element = {{48{half_value[15]}}, half_value};
        default:
          load_element = 64'sd0;
      endcase
    end
  endfunction

  function automatic logic [63:0] store_element_data(
    input logic [63:0] old_beat,
    input logic signed [31:0] value,
    input logic [2:0]  byte_lane,
    input logic        high_nibble,
    input logic [1:0]  dtype
  );
    logic [63:0] result;
    logic [7:0] byte_value;
    begin
      result = old_beat;
      case (dtype)
        NPU_DTYPE_INT4: begin
          byte_value = old_beat[byte_lane * 8 +: 8];
          if (high_nibble)
            byte_value[7:4] = value[3:0];
          else
            byte_value[3:0] = value[3:0];
          result[byte_lane * 8 +: 8] = byte_value;
        end
        NPU_DTYPE_INT8:
          result[byte_lane * 8 +: 8] = value[7:0];
        NPU_DTYPE_INT32:
          result[byte_lane * 8 +: 32] = value[31:0];
        NPU_DTYPE_INT16:
          result[byte_lane * 8 +: 16] = value[15:0];
        default: result = old_beat;
      endcase
      return result;
    end
  endfunction

  function automatic logic [7:0] store_element_strb(
    input logic [2:0] byte_lane,
    input logic [1:0] dtype
  );
    logic [7:0] result;
    begin
      result = 8'd0;
      case (dtype)
        NPU_DTYPE_INT4,
        NPU_DTYPE_INT8: result[byte_lane] = 1'b1;
        NPU_DTYPE_INT32: result = 8'h0f << byte_lane;
        NPU_DTYPE_INT16: result = 8'h03 << byte_lane;
        default: result = 8'd0;
      endcase
      return result;
    end
  endfunction

  function automatic logic signed [63:0] clip_to_dtype(
    input logic signed [63:0] value,
    input logic [1:0] dtype
  );
    logic signed [63:0] minimum;
    logic signed [63:0] maximum;
    begin
      minimum = dtype_min(dtype);
      maximum = dtype_max(dtype);
      if (value < minimum)
        return minimum;
      if (value > maximum)
        return maximum;
      return value;
    end
  endfunction

  function automatic logic signed [63:0] wrap_to_dtype(
    input logic signed [31:0] value,
    input logic [1:0] dtype
  );
    case (dtype)
      NPU_DTYPE_INT4:  return {{60{value[3]}}, value[3:0]};
      NPU_DTYPE_INT8:  return {{56{value[7]}}, value[7:0]};
      NPU_DTYPE_INT32: return {{32{value[31]}}, value[31:0]};
      NPU_DTYPE_INT16: return {{48{value[15]}}, value[15:0]};
      default:         return 64'sd0;
    endcase
  endfunction

  function automatic logic [7:0] memory_status_to_task(
    input logic [2:0] status
  );
    case (status)
      3'd0: return NPU_STATUS_SUCCESS;
      3'd1: return NPU_STATUS_BUS_SLVERR;
      3'd2: return NPU_STATUS_BUS_DECERR;
      default: return NPU_STATUS_ADDR_FAULT;
    endcase
  endfunction

  /*
   * CME IEEE-754 binary32 reference arithmetic.
   *
   * Each helper accepts and returns the 32-bit IEEE-754 representation.  The
   * arithmetic is integer/bit based and therefore synthesizable.  Normal
   * finite values use round-to-nearest-even after every operation.  Subnormal
   * results are flushed to signed zero; NaN inputs produce a canonical quiet
   * NaN.  The separate npu_complex_math_core module is the intended FP IP
   * replacement point for a production implementation.
   */
  function automatic logic fp32_is_nan(input logic [31:0] bits);
    logic unused_sign;
    begin
      unused_sign = bits[31];
      return bits[30:23] == 8'hff && bits[22:0] != 0;
    end
  endfunction

  function automatic logic fp32_is_inf(input logic [31:0] bits);
    logic unused_sign;
    begin
      unused_sign = bits[31];
      return bits[30:23] == 8'hff && bits[22:0] == 0;
    end
  endfunction

  function automatic logic fp32_is_zero(input logic [31:0] bits);
    logic unused_sign;
    begin
      unused_sign = bits[31];
      return bits[30:0] == 0;
    end
  endfunction

  function automatic logic fp32_finite_positive(input logic [31:0] bits);
    return bits[30:23] != 8'hff && !bits[31] &&
           bits[30:0] != 0;
  endfunction

  function automatic logic [31:0] fp32_neg(input logic [31:0] value);
    return {~value[31], value[30:0]};
  endfunction

  function automatic logic fp32_equal(
    input logic [31:0] lhs,
    input logic [31:0] rhs
  );
    if (fp32_is_nan(lhs) || fp32_is_nan(rhs))
      return 1'b0;
    if (fp32_is_zero(lhs) && fp32_is_zero(rhs))
      return 1'b1;
    return lhs == rhs;
  endfunction

  function automatic logic fp32_less_than(
    input logic [31:0] lhs,
    input logic [31:0] rhs
  );
    if (fp32_is_nan(lhs) || fp32_is_nan(rhs) ||
        fp32_equal(lhs, rhs))
      return 1'b0;
    if (lhs[31] != rhs[31])
      return lhs[31];
    if (!lhs[31])
      return lhs[30:0] < rhs[30:0];
    return lhs[30:0] > rhs[30:0];
  endfunction

  function automatic logic [31:0] fp32_from_int(
    input logic signed [63:0] value
  );
    logic sign;
    logic [63:0] magnitude;
    logic [23:0] shifted_significand;
    logic [63:0] remainder_mask;
    logic [63:0] remainder;
    logic [63:0] halfway;
    logic [24:0] rounded;
    logic [22:0] fraction;
    logic [8:0] exponent;
    integer leading_bit;
    integer shift_amount;
    integer bit_index;
    begin
      if (value == 0)
        return 32'd0;
      sign = value[63];
      magnitude = sign ? (~$unsigned(value) + 64'd1) :
                         $unsigned(value);
      leading_bit = 0;
      for (bit_index = 0; bit_index < 64; bit_index = bit_index + 1)
        if (magnitude[bit_index])
          leading_bit = bit_index;
      exponent = 9'(leading_bit + 127);
      if (leading_bit <= 23) begin
        shifted_significand =
          24'(magnitude << (23 - leading_bit));
        fraction = shifted_significand[22:0];
      end else begin
        shift_amount = leading_bit - 23;
        shifted_significand = 24'(magnitude >> shift_amount);
        remainder_mask = (64'd1 << shift_amount) - 1;
        remainder = magnitude & remainder_mask;
        halfway = 64'd1 << (shift_amount - 1);
        rounded = {1'b0, shifted_significand};
        if (remainder > halfway ||
            (remainder == halfway && shifted_significand[0]))
          rounded = rounded + 1;
        if (rounded[24]) begin
          fraction = rounded[23:1];
          exponent = exponent + 1;
        end else
          fraction = rounded[22:0];
      end
      if (exponent >= 255)
        return {sign, 8'hff, 23'd0};
      return {sign, exponent[7:0], fraction};
    end
  endfunction

  function automatic logic [31:0] fp32_add(
    input logic [31:0] lhs,
    input logic [31:0] rhs
  );
    logic lhs_sign;
    logic rhs_sign;
    logic result_sign;
    logic [7:0] lhs_exp;
    logic [7:0] rhs_exp;
    logic [8:0] large_exp;
    logic [8:0] small_exp;
    logic [23:0] lhs_mant;
    logic [23:0] rhs_mant;
    logic [23:0] large_mant;
    logic [23:0] small_mant;
    logic large_sign;
    logic small_sign;
    logic lhs_larger;
    logic [27:0] large_ext;
    logic [27:0] small_ext;
    logic [27:0] aligned_small;
    logic [27:0] work_ext;
    logic [27:0] discarded_mask;
    logic [24:0] rounded;
    logic [23:0] mantissa;
    logic increment;
    logic sticky;
    integer shift_amount;
    integer normalize_count;
    begin
      if (fp32_is_nan(lhs) || fp32_is_nan(rhs))
        return 32'h7fc0_0000;
      if (fp32_is_inf(lhs) || fp32_is_inf(rhs)) begin
        if (fp32_is_inf(lhs) && fp32_is_inf(rhs) &&
            lhs[31] != rhs[31])
          return 32'h7fc0_0000;
        return fp32_is_inf(lhs) ? lhs : rhs;
      end
      if (fp32_is_zero(lhs))
        return rhs;
      if (fp32_is_zero(rhs))
        return lhs;

      lhs_sign = lhs[31];
      rhs_sign = rhs[31];
      lhs_exp = lhs[30:23];
      rhs_exp = rhs[30:23];
      lhs_mant = lhs_exp == 0 ? {1'b0, lhs[22:0]} :
                               {1'b1, lhs[22:0]};
      rhs_mant = rhs_exp == 0 ? {1'b0, rhs[22:0]} :
                               {1'b1, rhs[22:0]};
      lhs_larger =
        ({1'b0, (lhs_exp == 0 ? 8'd1 : lhs_exp)} >
         {1'b0, (rhs_exp == 0 ? 8'd1 : rhs_exp)}) ||
        ((lhs_exp == rhs_exp) && lhs_mant >= rhs_mant);
      if (lhs_larger) begin
        large_exp = {1'b0, (lhs_exp == 0 ? 8'd1 : lhs_exp)};
        small_exp = {1'b0, (rhs_exp == 0 ? 8'd1 : rhs_exp)};
        large_mant = lhs_mant;
        small_mant = rhs_mant;
        large_sign = lhs_sign;
        small_sign = rhs_sign;
      end else begin
        large_exp = {1'b0, (rhs_exp == 0 ? 8'd1 : rhs_exp)};
        small_exp = {1'b0, (lhs_exp == 0 ? 8'd1 : lhs_exp)};
        large_mant = rhs_mant;
        small_mant = lhs_mant;
        large_sign = rhs_sign;
        small_sign = lhs_sign;
      end

      large_ext = {1'b0, large_mant, 3'b000};
      small_ext = {1'b0, small_mant, 3'b000};
      shift_amount =
        {23'd0, large_exp} - {23'd0, small_exp};
      if (shift_amount >= 28)
        aligned_small = small_ext == 0 ? 28'd0 : 28'd1;
      else begin
        aligned_small = small_ext >> shift_amount;
        discarded_mask =
          shift_amount == 0 ? 28'd0 :
          ((28'd1 << shift_amount) - 1);
        sticky = |(small_ext & discarded_mask);
        aligned_small[0] = aligned_small[0] | sticky;
      end

      result_sign = large_sign;
      if (large_sign == small_sign) begin
        work_ext = large_ext + aligned_small;
        if (work_ext[27]) begin
          sticky = work_ext[0];
          work_ext = work_ext >> 1;
          work_ext[0] = work_ext[0] | sticky;
          large_exp = large_exp + 1;
        end
      end else begin
        work_ext = large_ext - aligned_small;
        if (work_ext == 0)
          return 32'd0;
        for (normalize_count = 0;
             normalize_count < 26;
             normalize_count = normalize_count + 1) begin
          if (!work_ext[26] && large_exp > 1) begin
            work_ext = work_ext << 1;
            large_exp = large_exp - 1;
          end
        end
      end

      mantissa = work_ext[26:3];
      increment = work_ext[2] &&
                  (work_ext[1] || work_ext[0] || mantissa[0]);
      rounded = {1'b0, mantissa} + {24'd0, increment};
      if (rounded[24]) begin
        mantissa = rounded[24:1];
        large_exp = large_exp + 1;
      end else
        mantissa = rounded[23:0];
      if (large_exp >= 255)
        return {result_sign, 8'hff, 23'd0};
      if (large_exp == 1 && !mantissa[23])
        return {result_sign, 8'd0, mantissa[22:0]};
      return {result_sign, large_exp[7:0], mantissa[22:0]};
    end
  endfunction

  function automatic logic [31:0] fp32_sub(
    input logic [31:0] lhs,
    input logic [31:0] rhs
  );
    return fp32_add(lhs, fp32_neg(rhs));
  endfunction

  function automatic logic [31:0] fp32_mul(
    input logic [31:0] lhs,
    input logic [31:0] rhs
  );
    logic result_sign;
    logic [23:0] lhs_mant;
    logic [23:0] rhs_mant;
    logic [47:0] product;
    logic [47:0] remainder_mask;
    logic [47:0] remainder;
    logic [47:0] halfway;
    logic [24:0] rounded;
    logic [23:0] mantissa;
    integer lhs_unbiased;
    integer rhs_unbiased;
    integer result_unbiased;
    integer shift_amount;
    integer normalize_count;
    begin
      if (fp32_is_nan(lhs) || fp32_is_nan(rhs) ||
          ((fp32_is_inf(lhs) && fp32_is_zero(rhs)) ||
           (fp32_is_inf(rhs) && fp32_is_zero(lhs))))
        return 32'h7fc0_0000;
      result_sign = lhs[31] ^ rhs[31];
      if (fp32_is_inf(lhs) || fp32_is_inf(rhs))
        return {result_sign, 8'hff, 23'd0};
      if (fp32_is_zero(lhs) || fp32_is_zero(rhs))
        return {result_sign, 31'd0};

      lhs_mant = lhs[30:23] == 0 ? {1'b0, lhs[22:0]} :
                                      {1'b1, lhs[22:0]};
      rhs_mant = rhs[30:23] == 0 ? {1'b0, rhs[22:0]} :
                                      {1'b1, rhs[22:0]};
      lhs_unbiased = lhs[30:23] == 0 ? -126 :
                     {24'd0, lhs[30:23]} - 127;
      rhs_unbiased = rhs[30:23] == 0 ? -126 :
                     {24'd0, rhs[30:23]} - 127;
      for (normalize_count = 0;
           normalize_count < 23;
           normalize_count = normalize_count + 1) begin
        if (!lhs_mant[23]) begin
          lhs_mant = lhs_mant << 1;
          lhs_unbiased = lhs_unbiased - 1;
        end
        if (!rhs_mant[23]) begin
          rhs_mant = rhs_mant << 1;
          rhs_unbiased = rhs_unbiased - 1;
        end
      end

      product = lhs_mant * rhs_mant;
      result_unbiased = lhs_unbiased + rhs_unbiased;
      if (product[47]) begin
        shift_amount = 24;
        result_unbiased = result_unbiased + 1;
      end else
        shift_amount = 23;
      mantissa = 24'(product >> shift_amount);
      remainder_mask = (48'd1 << shift_amount) - 1;
      remainder = product & remainder_mask;
      halfway = 48'd1 << (shift_amount - 1);
      rounded = {1'b0, mantissa};
      if (remainder > halfway ||
          (remainder == halfway && mantissa[0]))
        rounded = rounded + 1;
      if (rounded[24]) begin
        mantissa = rounded[24:1];
        result_unbiased = result_unbiased + 1;
      end else
        mantissa = rounded[23:0];
      if (result_unbiased > 127)
        return {result_sign, 8'hff, 23'd0};
      if (result_unbiased < -126)
        return {result_sign, 31'd0};
      return {
        result_sign,
        8'(result_unbiased + 127),
        mantissa[22:0]
      };
    end
  endfunction

  function automatic logic [31:0] fp32_div(
    input logic [31:0] numerator_value,
    input logic [31:0] denominator_value
  );
    logic result_sign;
    logic [23:0] numerator_mant;
    logic [23:0] denominator_mant;
    logic [55:0] scaled_numerator;
    logic [55:0] denominator_wide;
    logic [23:0] division_remainder;
    logic [27:0] quotient_ext;
    logic [24:0] rounded;
    logic [23:0] mantissa;
    logic increment;
    integer numerator_unbiased;
    integer denominator_unbiased;
    integer result_unbiased;
    integer normalize_count;
    begin
      if (fp32_is_nan(numerator_value) ||
          fp32_is_nan(denominator_value) ||
          (fp32_is_zero(numerator_value) &&
           fp32_is_zero(denominator_value)) ||
          (fp32_is_inf(numerator_value) &&
           fp32_is_inf(denominator_value)))
        return 32'h7fc0_0000;
      result_sign = numerator_value[31] ^ denominator_value[31];
      if (fp32_is_inf(numerator_value) ||
          fp32_is_zero(denominator_value))
        return {result_sign, 8'hff, 23'd0};
      if (fp32_is_zero(numerator_value) ||
          fp32_is_inf(denominator_value))
        return {result_sign, 31'd0};

      numerator_mant =
        numerator_value[30:23] == 0 ?
        {1'b0, numerator_value[22:0]} :
        {1'b1, numerator_value[22:0]};
      denominator_mant =
        denominator_value[30:23] == 0 ?
        {1'b0, denominator_value[22:0]} :
        {1'b1, denominator_value[22:0]};
      numerator_unbiased =
        numerator_value[30:23] == 0 ? -126 :
        {24'd0, numerator_value[30:23]} - 127;
      denominator_unbiased =
        denominator_value[30:23] == 0 ? -126 :
        {24'd0, denominator_value[30:23]} - 127;
      for (normalize_count = 0;
           normalize_count < 23;
           normalize_count = normalize_count + 1) begin
        if (!numerator_mant[23]) begin
          numerator_mant = numerator_mant << 1;
          numerator_unbiased = numerator_unbiased - 1;
        end
        if (!denominator_mant[23]) begin
          denominator_mant = denominator_mant << 1;
          denominator_unbiased = denominator_unbiased - 1;
        end
      end

      result_unbiased = numerator_unbiased - denominator_unbiased;
      scaled_numerator = {32'd0, numerator_mant} << 26;
      denominator_wide = {32'd0, denominator_mant};
      quotient_ext =
        28'(scaled_numerator / denominator_wide);
      division_remainder =
        24'(scaled_numerator % denominator_wide);
      if (!quotient_ext[26]) begin
        quotient_ext = quotient_ext << 1;
        result_unbiased = result_unbiased - 1;
      end
      if (division_remainder != 0)
        quotient_ext[0] = 1'b1;
      mantissa = quotient_ext[26:3];
      increment = quotient_ext[2] &&
                  (quotient_ext[1] || quotient_ext[0] || mantissa[0]);
      rounded = {1'b0, mantissa} + {24'd0, increment};
      if (rounded[24]) begin
        mantissa = rounded[24:1];
        result_unbiased = result_unbiased + 1;
      end else
        mantissa = rounded[23:0];
      if (result_unbiased > 127)
        return {result_sign, 8'hff, 23'd0};
      if (result_unbiased < -126)
        return {result_sign, 31'd0};
      return {
        result_sign,
        8'(result_unbiased + 127),
        mantissa[22:0]
      };
    end
  endfunction

  function automatic logic signed [63:0] fp32_to_int_round(
    input logic [31:0] value,
    input logic [1:0]  rounding
  );
    logic sign;
    logic [23:0] significand;
    logic [63:0] magnitude;
    logic [63:0] quotient;
    logic [63:0] remainder;
    logic [63:0] remainder_mask;
    logic [63:0] halfway;
    logic increment;
    integer unbiased;
    integer shift_amount;
    begin
      sign = value[31];
      if (fp32_is_nan(value))
        return 64'sd0;
      if (fp32_is_inf(value))
        return sign ? 64'sh8000_0000_0000_0000 :
                      64'sh7fff_ffff_ffff_ffff;
      if (fp32_is_zero(value))
        return 64'sd0;
      significand = value[30:23] == 0 ?
                    {1'b0, value[22:0]} :
                    {1'b1, value[22:0]};
      unbiased = value[30:23] == 0 ? -126 :
                 {24'd0, value[30:23]} - 127;
      quotient = 64'd0;
      remainder = 64'd0;
      halfway = 64'd0;
      if (unbiased >= 63)
        return sign ? 64'sh8000_0000_0000_0000 :
                      64'sh7fff_ffff_ffff_ffff;
      if (unbiased >= 23)
        quotient = {40'd0, significand} << (unbiased - 23);
      else begin
        shift_amount = 23 - unbiased;
        if (shift_amount >= 64) begin
          quotient = 64'd0;
          remainder = {40'd0, significand};
          halfway = 64'hffff_ffff_ffff_ffff;
        end else begin
          quotient = {40'd0, significand} >> shift_amount;
          remainder_mask = (64'd1 << shift_amount) - 1;
          remainder = {40'd0, significand} & remainder_mask;
          halfway = 64'd1 << (shift_amount - 1);
        end
      end
      increment = 1'b0;
      case (rounding)
        2'd0:
          increment =
            remainder > halfway ||
            (remainder == halfway && quotient[0]);
        2'd2: increment = !sign && remainder != 0;
        2'd3: increment = sign && remainder != 0;
        default: increment = 1'b0;
      endcase
      magnitude = quotient + {63'd0, increment};
      if (sign) begin
        if (magnitude >= 64'h8000_0000_0000_0000)
          return 64'sh8000_0000_0000_0000;
        return $signed((~magnitude) + 64'd1);
      end
      if (magnitude > 64'h7fff_ffff_ffff_ffff)
        return 64'sh7fff_ffff_ffff_ffff;
      return $signed(magnitude);
    end
  endfunction

  function automatic logic [31:0] fp32_exp_neg_approx(
    input logic [31:0] value
  );
    logic [31:0] reduced;
    logic [31:0] polynomial;
    begin
      if (fp32_is_nan(value))
        return 32'h7fc0_0000;
      if (!value[31] || fp32_is_zero(value))
        return 32'h3f80_0000;
      if (fp32_less_than(value, 32'hc180_0000) ||
          fp32_equal(value, 32'hc180_0000))
        return 32'd0;
      reduced = fp32_mul(value, 32'h3d80_0000);
      polynomial = 32'h3c08_8889;
      polynomial = fp32_add(
        32'h3d2a_aaab, fp32_mul(reduced, polynomial)
      );
      polynomial = fp32_add(
        32'h3e2a_aaab, fp32_mul(reduced, polynomial)
      );
      polynomial = fp32_add(
        32'h3f00_0000, fp32_mul(reduced, polynomial)
      );
      polynomial = fp32_add(
        32'h3f80_0000, fp32_mul(reduced, polynomial)
      );
      polynomial = fp32_add(
        32'h3f80_0000, fp32_mul(reduced, polynomial)
      );
      polynomial = fp32_mul(polynomial, polynomial);
      polynomial = fp32_mul(polynomial, polynomial);
      polynomial = fp32_mul(polynomial, polynomial);
      polynomial = fp32_mul(polynomial, polynomial);
      if (polynomial[31])
        return 32'd0;
      return polynomial;
    end
  endfunction

  function automatic logic [31:0] fp32_sigmoid_approx(
    input logic [31:0] value
  );
    logic [31:0] exponential;
    logic [31:0] denominator;
    begin
      if (fp32_is_nan(value))
        return 32'h7fc0_0000;
      if (value[31] && !fp32_is_zero(value)) begin
        exponential = fp32_exp_neg_approx(value);
        denominator = fp32_add(32'h3f80_0000, exponential);
        return fp32_div(exponential, denominator);
      end
      exponential = fp32_exp_neg_approx(fp32_neg(value));
      denominator = fp32_add(32'h3f80_0000, exponential);
      return fp32_div(32'h3f80_0000, denominator);
    end
  endfunction

  function automatic logic [31:0] fp32_tanh_approx(
    input logic [31:0] value
  );
    logic [31:0] doubled;
    logic [31:0] sigmoid_value;
    begin
      doubled = fp32_mul(value, 32'h4000_0000);
      sigmoid_value = fp32_sigmoid_approx(doubled);
      return fp32_sub(
        fp32_mul(sigmoid_value, 32'h4000_0000),
        32'h3f80_0000
      );
    end
  endfunction

  function automatic logic [31:0] fp32_rsqrt_approx(
    input logic [31:0] value
  );
    logic [31:0] half_value;
    logic [31:0] estimate;
    logic [31:0] estimate_sq;
    logic [31:0] correction;
    integer iteration;
    begin
      if (fp32_is_nan(value) || value[31])
        return 32'h7fc0_0000;
      if (fp32_is_zero(value))
        return 32'h7f80_0000;
      if (fp32_is_inf(value))
        return 32'd0;
      half_value = fp32_mul(value, 32'h3f00_0000);
      estimate = 32'h5f37_5a86 - (value >> 1);
      for (iteration = 0; iteration < 2; iteration = iteration + 1) begin
        estimate_sq = fp32_mul(estimate, estimate);
        correction = fp32_sub(
          32'h3fc0_0000,
          fp32_mul(half_value, estimate_sq)
        );
        estimate = fp32_mul(estimate, correction);
      end
      return estimate;
    end
  endfunction

endpackage
