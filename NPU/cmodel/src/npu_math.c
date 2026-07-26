#include "npu_cmodel.h"

#include <float.h>
#include <limits.h>

_Static_assert(sizeof(float) == 4u,
               "mode 0 requires 32-bit float");
_Static_assert(FLT_RADIX == 2,
               "mode 0 requires binary floating point");
_Static_assert(FLT_MANT_DIG == 24,
               "mode 0 requires binary32 precision");
_Static_assert(FLT_MAX_EXP == 128 &&
                   FLT_MIN_EXP == -125,
               "mode 0 requires binary32 exponent range");

typedef union {
    float value;
    uint32_t bits;
} npu_float_bits_t;

static uint32_t npu_float_bit_pattern(float value)
{
    npu_float_bits_t bits;

    bits.value = value;
    return bits.bits;
}

void npu_mode0_trace_clear(npu_mode0_trace_t *trace)
{
    if (trace != NULL) {
        *trace = (npu_mode0_trace_t){0};
    }
}

/*
 * Keep every elementary operation at FP32 precision.  The build also uses
 * -ffp-contract=off, but the volatile destination makes the intended
 * operation sequence explicit for the reference model.
 */
static float npu_fp32_add(float a, float b)
{
    volatile float result = a + b;
    return result;
}

static float npu_fp32_sub(float a, float b)
{
    volatile float result = a - b;
    return result;
}

static float npu_fp32_mul(float a, float b)
{
    volatile float result = a * b;
    return result;
}

static int npu_float_is_nan_value(float x)
{
    npu_float_bits_t bits;

    bits.value = x;
    return (bits.bits & 0x7f800000u) == 0x7f800000u &&
           (bits.bits & 0x007fffffu) != 0u;
}

static float npu_abs_float(float x)
{
    npu_float_bits_t bits;

    bits.value = x;
    bits.bits &= 0x7fffffffu;
    return bits.value;
}

static float npu_float_with_sign(float magnitude, uint32_t sign)
{
    npu_float_bits_t bits;

    bits.value = magnitude;
    bits.bits = (bits.bits & 0x7fffffffu) |
                (sign & 0x80000000u);
    return bits.value;
}

static float npu_maximum_finite_float(uint32_t sign)
{
    npu_float_bits_t bits;

    bits.bits = (sign & 0x80000000u) | 0x7f7fffffu;
    return bits.value;
}

static int32_t npu_round_nearest_integer_float(float x)
{
    int32_t integer;
    float fraction;
    float magnitude;
    int negative;

    negative = x < 0.0f;
    magnitude = negative != 0 ? -x : x;
    integer = (int32_t)magnitude;
    fraction = npu_fp32_sub(magnitude, (float)integer);
    if (fraction > 0.5f ||
        (fraction == 0.5f && (integer & 1) != 0)) {
        integer++;
    }
    return negative != 0 ? -integer : integer;
}

static float npu_pow2_integer(int32_t exponent)
{
    npu_float_bits_t bits;

    if (exponent < -149) {
        return 0.0f;
    }
    if (exponent < -126) {
        bits.bits = UINT32_C(1) <<
                    (uint32_t)(exponent + 149);
        return bits.value;
    }
    if (exponent > 127) {
        return npu_maximum_finite_float(0u);
    }
    bits.bits = (uint32_t)(exponent + 127) << 23;
    return bits.value;
}

static float npu_scale_pow2_saturating(float value, int32_t exponent)
{
    npu_float_bits_t bits;

    /*
     * Reciprocal of a subnormal input can require a scale greater than
     * 2^127.  Split that scale into representable powers of two and
     * saturate if an intermediate multiplication overflows.
     */
    while (exponent > 127) {
        value = npu_fp32_mul(value, npu_pow2_integer(127));
        exponent -= 127;
        bits.value = value;
        if ((bits.bits & 0x7f800000u) == 0x7f800000u) {
            return npu_maximum_finite_float(bits.bits);
        }
    }

    while (exponent < -149) {
        value = npu_fp32_mul(value, npu_pow2_integer(-149));
        exponent += 149;
        if (value == 0.0f) {
            return value;
        }
    }

    value = npu_fp32_mul(value, npu_pow2_integer(exponent));
    bits.value = value;
    if ((bits.bits & 0x7f800000u) == 0x7f800000u) {
        return npu_maximum_finite_float(bits.bits);
    }
    return value;
}

static void npu_normalize_positive_float(float value,
                                         float *mantissa,
                                         int32_t *exponent)
{
    npu_float_bits_t bits;
    uint32_t exponent_field;

    bits.value = value;
    exponent_field = (bits.bits >> 23) & 0xffu;
    if (exponent_field == 0u) {
        value = npu_fp32_mul(value, 0x1.000000p+24f);
        bits.value = value;
        exponent_field = (bits.bits >> 23) & 0xffu;
        *exponent = (int32_t)exponent_field - 127 - 24;
    } else {
        *exponent = (int32_t)exponent_field - 127;
    }

    bits.bits = 0x3f800000u | (bits.bits & 0x007fffffu);
    *mantissa = bits.value;
}

int npu_float_is_finite_positive(float x)
{
    npu_float_bits_t bits;

    bits.value = x;
    if ((bits.bits & 0x80000000u) != 0u) {
        return 0;
    }
    if ((bits.bits & 0x7fffffffu) == 0u) {
        return 0;
    }
    return (bits.bits & 0x7f800000u) != 0x7f800000u;
}

static float npu_exp_approx_impl(float x,
                                 npu_mode0_trace_t *trace)
{
    const float inv_ln2 = 0x1.715476p+0f;
    const float ln2_hi = 0x1.62e300p-1f;
    const float ln2_lo = 0x1.2fefa2p-17f;
    float r;
    float polynomial;
    int32_t exponent;

    if (trace != NULL) {
        trace->exp_valid = 0u;
        trace->exp_k = 0;
        trace->exp_r_bits = 0u;
    }
    if (npu_float_is_nan_value(x) != 0) {
        return 0.0f;
    }
    if (x < -16.0f) {
        return 0.0f;
    }
    if (x > 16.0f) {
        x = 16.0f;
    }

    exponent = npu_round_nearest_integer_float(
        npu_fp32_mul(x, inv_ln2));
    r = npu_fp32_sub(
        x, npu_fp32_mul((float)exponent, ln2_hi));
    r = npu_fp32_sub(
        r, npu_fp32_mul((float)exponent, ln2_lo));
    if (trace != NULL) {
        trace->exp_valid = 1u;
        trace->exp_k = exponent;
        trace->exp_r_bits = npu_float_bit_pattern(r);
    }

    polynomial = 0x1.6c16c2p-10f;
    polynomial = npu_fp32_add(
        0x1.111112p-7f, npu_fp32_mul(r, polynomial));
    polynomial = npu_fp32_add(
        0x1.555556p-5f, npu_fp32_mul(r, polynomial));
    polynomial = npu_fp32_add(
        0x1.555556p-3f, npu_fp32_mul(r, polynomial));
    polynomial = npu_fp32_add(
        0x1.000000p-1f, npu_fp32_mul(r, polynomial));
    polynomial = npu_fp32_add(
        1.0f, npu_fp32_mul(r, polynomial));
    polynomial = npu_fp32_add(
        1.0f, npu_fp32_mul(r, polynomial));

    return npu_fp32_mul(polynomial,
                        npu_pow2_integer(exponent));
}

float npu_exp_approx(float x)
{
    return npu_exp_approx_impl(x, NULL);
}

float npu_exp_approx_traced(float x,
                            npu_mode0_trace_t *trace)
{
    return npu_exp_approx_impl(x, trace);
}

static float npu_reciprocal_approx_impl(
    float x, npu_mode0_trace_t *trace)
{
    const float seed_a = 0x1.69696ap+0f;
    const float seed_b = 0x1.e1e1e2p-2f;
    npu_float_bits_t input;
    float magnitude;
    float mantissa;
    float y;
    float product;
    int32_t exponent;
    uint32_t sign;
    uint32_t magnitude_bits;
    uint32_t exponent_bits;
    unsigned int iteration;

    if (trace != NULL) {
        trace->reciprocal_valid = 0u;
        trace->reciprocal_newton_bits = 0u;
    }
    input.value = x;
    sign = input.bits & 0x80000000u;
    magnitude_bits = input.bits & 0x7fffffffu;
    exponent_bits = magnitude_bits & 0x7f800000u;

    if (magnitude_bits == 0u) {
        return npu_maximum_finite_float(sign);
    }
    if (exponent_bits == 0x7f800000u) {
        if ((magnitude_bits & 0x007fffffu) != 0u) {
            return 0.0f;
        }
        return npu_float_with_sign(0.0f, sign);
    }

    magnitude = npu_abs_float(x);
    npu_normalize_positive_float(magnitude,
                                 &mantissa, &exponent);

    y = npu_fp32_sub(seed_a,
                     npu_fp32_mul(seed_b, mantissa));
    for (iteration = 0u; iteration < 3u; iteration++) {
        product = npu_fp32_mul(mantissa, y);
        y = npu_fp32_mul(
            y, npu_fp32_sub(2.0f, product));
    }
    if (trace != NULL) {
        trace->reciprocal_valid = 1u;
        trace->reciprocal_newton_bits =
            npu_float_bit_pattern(y);
    }

    y = npu_scale_pow2_saturating(y, -exponent);
    return npu_float_with_sign(y, sign);
}

float npu_reciprocal_approx(float x)
{
    return npu_reciprocal_approx_impl(x, NULL);
}

float npu_reciprocal_approx_traced(
    float x, npu_mode0_trace_t *trace)
{
    return npu_reciprocal_approx_impl(x, trace);
}

static float npu_rsqrt_approx_impl(
    float x, npu_mode0_trace_t *trace)
{
    npu_float_bits_t input;
    npu_float_bits_t seed;
    float mantissa;
    float half;
    float y;
    float square;
    float correction;
    int32_t exponent;
    uint32_t magnitude_bits;
    unsigned int iteration;

    if (trace != NULL) {
        trace->rsqrt_valid = 0u;
        trace->rsqrt_newton_bits = 0u;
    }
    input.value = x;
    magnitude_bits = input.bits & 0x7fffffffu;

    if ((magnitude_bits & 0x7f800000u) == 0x7f800000u) {
        if ((magnitude_bits & 0x007fffffu) != 0u) {
            return 0.0f;
        }
        if ((input.bits & 0x80000000u) == 0u) {
            return 0.0f;
        }
        return npu_maximum_finite_float(0u);
    }
    if ((input.bits & 0x80000000u) != 0u ||
        magnitude_bits == 0u) {
        return npu_maximum_finite_float(0u);
    }

    npu_normalize_positive_float(x, &mantissa, &exponent);
    if ((exponent % 2) != 0) {
        mantissa = npu_fp32_mul(mantissa, 2.0f);
        exponent--;
    }

    half = npu_fp32_mul(0.5f, mantissa);
    seed.value = mantissa;
    seed.bits = 0x5f375a86u - (seed.bits >> 1);
    y = seed.value;

    for (iteration = 0u; iteration < 3u; iteration++) {
        square = npu_fp32_mul(y, y);
        correction = npu_fp32_sub(
            1.5f, npu_fp32_mul(half, square));
        y = npu_fp32_mul(y, correction);
    }
    if (trace != NULL) {
        trace->rsqrt_valid = 1u;
        trace->rsqrt_newton_bits =
            npu_float_bit_pattern(y);
    }

    return npu_scale_pow2_saturating(
        y, -(exponent / 2));
}

float npu_rsqrt_approx(float x)
{
    return npu_rsqrt_approx_impl(x, NULL);
}

float npu_rsqrt_approx_traced(float x,
                              npu_mode0_trace_t *trace)
{
    return npu_rsqrt_approx_impl(x, trace);
}

float npu_sigmoid_approx(float x)
{
    npu_float_bits_t input;
    float magnitude;
    float exponential;
    float inverse;

    if (npu_float_is_nan_value(x) != 0) {
        return 0.0f;
    }
    if (x > 16.0f) {
        return 1.0f;
    }
    if (x < -16.0f) {
        return 0.0f;
    }

    input.value = x;
    magnitude = npu_abs_float(x);
    exponential = npu_exp_approx(-magnitude);
    inverse = npu_reciprocal_approx(
        npu_fp32_add(1.0f, exponential));
    if ((input.bits & 0x80000000u) == 0u) {
        return inverse;
    }
    return npu_fp32_mul(exponential, inverse);
}

float npu_tanh_approx(float x)
{
    const float coefficient_3 = -0x1.555556p-2f;
    const float coefficient_5 = 0x1.111112p-3f;
    const float coefficient_7 = -0x1.ba1ba2p-5f;
    npu_float_bits_t input;
    float magnitude;
    float square;
    float polynomial;
    float exponential;
    float numerator;
    float inverse;
    float result;
    uint32_t sign;

    if (npu_float_is_nan_value(x) != 0) {
        return 0.0f;
    }

    input.value = x;
    sign = input.bits & 0x80000000u;
    magnitude = npu_abs_float(x);
    if (magnitude > 8.0f) {
        return npu_float_with_sign(1.0f, sign);
    }

    if (magnitude < 0.25f) {
        square = npu_fp32_mul(magnitude, magnitude);
        polynomial = coefficient_7;
        polynomial = npu_fp32_add(
            coefficient_5,
            npu_fp32_mul(square, polynomial));
        polynomial = npu_fp32_add(
            coefficient_3,
            npu_fp32_mul(square, polynomial));
        polynomial = npu_fp32_add(
            1.0f, npu_fp32_mul(square, polynomial));
        result = npu_fp32_mul(magnitude, polynomial);
        return npu_float_with_sign(result, sign);
    }

    exponential = npu_exp_approx(
        npu_fp32_mul(-2.0f, magnitude));
    numerator = npu_fp32_sub(1.0f, exponential);
    inverse = npu_reciprocal_approx(
        npu_fp32_add(1.0f, exponential));
    result = npu_fp32_mul(numerator, inverse);
    return npu_float_with_sign(result, sign);
}

float npu_gelu_approx(float x)
{
    const float sqrt_two_over_pi = 0x1.988454p-1f;
    const float cubic_coefficient = 0x1.6e4e26p-5f;
    float square;
    float shape;
    float inner;
    float tanh_value;
    float half_x;

    if (npu_float_is_nan_value(x) != 0) {
        return 0.0f;
    }
    if (x > 8.0f) {
        return x;
    }
    if (x < -8.0f) {
        return 0.0f;
    }

    square = npu_fp32_mul(x, x);
    shape = npu_fp32_add(
        1.0f, npu_fp32_mul(cubic_coefficient, square));
    inner = npu_fp32_mul(
        npu_fp32_mul(sqrt_two_over_pi, x), shape);
    tanh_value = npu_tanh_approx(inner);
    half_x = npu_fp32_mul(0.5f, x);
    return npu_fp32_mul(
        half_x, npu_fp32_add(1.0f, tanh_value));
}

float npu_silu_approx(float x)
{
    if (npu_float_is_nan_value(x) != 0) {
        return 0.0f;
    }
    if (x > 16.0f) {
        return x;
    }
    if (x < -16.0f) {
        return 0.0f;
    }
    return npu_fp32_mul(x, npu_sigmoid_approx(x));
}

int32_t npu_float_to_int(float x, npu_round_mode_t mode)
{
    npu_float_bits_t input;
    uint32_t sign;
    uint32_t exponent_field;
    uint32_t fraction_field;
    uint32_t significand;
    uint32_t magnitude = 0u;
    uint32_t remainder = 0u;
    uint32_t half = 0u;
    int32_t exponent;
    uint32_t shift;
    int increment = 0;

    input.value = x;
    sign = input.bits & 0x80000000u;
    exponent_field = (input.bits >> 23) & 0xffu;
    fraction_field = input.bits & 0x007fffffu;

    if (exponent_field == 0xffu) {
        if (fraction_field != 0u) {
            return 0;
        }
        return sign != 0u ? INT32_MIN : INT32_MAX;
    }
    if (exponent_field == 0u) {
        remainder = fraction_field;
        exponent = -126;
    } else {
        significand = 0x00800000u | fraction_field;
        exponent = (int32_t)exponent_field - 127;

        if (exponent >= 31) {
            return sign != 0u ? INT32_MIN : INT32_MAX;
        }
        if (exponent >= 23) {
            magnitude = significand <<
                        (uint32_t)(exponent - 23);
        } else if (exponent >= 0) {
            shift = (uint32_t)(23 - exponent);
            magnitude = significand >> shift;
            remainder = significand &
                        ((UINT32_C(1) << shift) - 1u);
            half = UINT32_C(1) << (shift - 1u);
        } else {
            remainder = significand;
            if (exponent == -1) {
                half = 0x00800000u;
            }
        }
    }

    if (mode == NPU_ROUND_NEAREST_EVEN) {
        if (exponent == -1) {
            increment = remainder > half;
        } else if (exponent >= 0 && remainder != 0u &&
                   (remainder > half ||
                    (remainder == half &&
                     (magnitude & 1u) != 0u))) {
            increment = 1;
        }
    } else if (mode == NPU_ROUND_TO_POS_INF) {
        increment = sign == 0u && remainder != 0u;
    } else if (mode == NPU_ROUND_TO_NEG_INF) {
        increment = sign != 0u && remainder != 0u;
    }

    if (increment != 0) {
        magnitude++;
    }

    if (sign != 0u) {
        if (magnitude >= UINT32_C(0x80000000)) {
            return INT32_MIN;
        }
        return -(int32_t)magnitude;
    }
    if (magnitude > (uint32_t)INT32_MAX) {
        return INT32_MAX;
    }
    return (int32_t)magnitude;
}

int32_t npu_float_to_int_traced(
    float x, npu_round_mode_t mode,
    npu_mode0_trace_t *trace)
{
    if (trace != NULL) {
        trace->f2i_valid = 1u;
        trace->f2i_input_bits =
            npu_float_bit_pattern(x);
    }
    return npu_float_to_int(x, mode);
}
