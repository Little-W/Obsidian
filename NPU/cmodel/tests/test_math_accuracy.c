#include "test_util.h"

#include <float.h>
#include <math.h>
#include <stdint.h>

#ifdef NPU_MATH_ACCURACY_STANDALONE
#include <stdio.h>
#endif

#define MATH_GRID_STEPS 65536u
#define MATH_MANTISSA_STEPS 2048u

static int math_check_relative(float actual,
                               double reference,
                               double limit)
{
    double error;

    if (!isfinite((double)actual) || !isfinite(reference) ||
        reference == 0.0) {
        return 0;
    }
    error = fabs((double)actual - reference) /
            fabs(reference);
    return error <= limit;
}

static int math_check_absolute(float actual,
                               double reference,
                               double limit)
{
    if (!isfinite((double)actual) || !isfinite(reference)) {
        return 0;
    }
    return fabs((double)actual - reference) <= limit;
}

static double math_sigmoid_reference(double value)
{
    double exponential;

    if (value >= 0.0) {
        exponential = exp(-value);
        return 1.0 / (1.0 + exponential);
    }
    exponential = exp(value);
    return exponential / (1.0 + exponential);
}

static double math_gelu_reference(double value)
{
    const double sqrt_two_over_pi =
        0.79788456080286535587989211986876;
    double cubic = value * value * value;
    double inner =
        sqrt_two_over_pi * (value + 0.044715 * cubic);

    return 0.5 * value * (1.0 + tanh(inner));
}

static int math_test_exp_range(void)
{
    const double relative_limit = 1.0 / 1024.0;
    uint32_t index;

    for (index = 0u; index <= MATH_GRID_STEPS; index++) {
        float value = (float)(
            -16.0 +
            32.0 * (double)index / (double)MATH_GRID_STEPS);
        double reference = exp((double)value);

        TEST_CHECK(math_check_relative(
            npu_exp_approx(value), reference, relative_limit));
    }
    TEST_CHECK(npu_exp_approx(-17.0f) == 0.0f);
    TEST_CHECK(npu_exp_approx(17.0f) ==
               npu_exp_approx(16.0f));
    return 0;
}

static int math_test_reciprocal_range(void)
{
    const double relative_limit = 1.0 / 1024.0;
    int exponent;
    uint32_t index;

    for (exponent = -12; exponent <= 11; exponent++) {
        for (index = 0u;
             index < MATH_MANTISSA_STEPS;
             index++) {
            double mantissa =
                1.0 +
                (double)index /
                    (double)MATH_MANTISSA_STEPS;
            float positive =
                (float)ldexp(mantissa, exponent);
            float negative = -positive;

            TEST_CHECK(math_check_relative(
                npu_reciprocal_approx(positive),
                1.0 / (double)positive,
                relative_limit));
            TEST_CHECK(math_check_relative(
                npu_reciprocal_approx(negative),
                1.0 / (double)negative,
                relative_limit));
        }
    }
    TEST_CHECK(math_check_relative(
        npu_reciprocal_approx(4096.0f),
        1.0 / 4096.0, relative_limit));
    TEST_CHECK(math_check_relative(
        npu_reciprocal_approx(-4096.0f),
        -1.0 / 4096.0, relative_limit));
    return 0;
}

static int math_test_rsqrt_range(void)
{
    const double relative_limit = 1.0 / 1024.0;
    int exponent;
    uint32_t index;

    for (exponent = -12; exponent <= 11; exponent++) {
        for (index = 0u;
             index < MATH_MANTISSA_STEPS;
             index++) {
            double mantissa =
                1.0 +
                (double)index /
                    (double)MATH_MANTISSA_STEPS;
            float value =
                (float)ldexp(mantissa, exponent);

            TEST_CHECK(math_check_relative(
                npu_rsqrt_approx(value),
                1.0 / sqrt((double)value),
                relative_limit));
        }
    }
    TEST_CHECK(math_check_relative(
        npu_rsqrt_approx(4096.0f),
        1.0 / 64.0, relative_limit));
    return 0;
}

static int math_test_activation_ranges(void)
{
    const double strict_absolute_limit = 1.0 / 4096.0;
    const double relaxed_absolute_limit = 1.0 / 1024.0;
    uint32_t index;

    for (index = 0u; index <= MATH_GRID_STEPS; index++) {
        float value = (float)(
            -16.0 +
            32.0 * (double)index / (double)MATH_GRID_STEPS);
        double source = (double)value;

        TEST_CHECK(math_check_absolute(
            npu_sigmoid_approx(value),
            math_sigmoid_reference(source),
            strict_absolute_limit));
        TEST_CHECK(math_check_absolute(
            npu_silu_approx(value),
            source * math_sigmoid_reference(source),
            relaxed_absolute_limit));
    }

    for (index = 0u; index <= MATH_GRID_STEPS; index++) {
        float value = (float)(
            -8.0 +
            16.0 * (double)index / (double)MATH_GRID_STEPS);
        double source = (double)value;

        TEST_CHECK(math_check_absolute(
            npu_tanh_approx(value), tanh(source),
            strict_absolute_limit));
        TEST_CHECK(math_check_absolute(
            npu_gelu_approx(value),
            math_gelu_reference(source),
            relaxed_absolute_limit));
    }
    return 0;
}

static int math_test_mode0_checkpoints(void)
{
    npu_mode0_trace_t trace;
    float value;
    int32_t integer;

    npu_mode0_trace_clear(&trace);
    value = npu_exp_approx_traced(1.0f, &trace);
    TEST_CHECK(value == npu_exp_approx(1.0f));
    TEST_CHECK(trace.exp_valid == 1u);
    TEST_CHECK(trace.exp_k == 1);
    TEST_CHECK(trace.exp_r_bits == UINT32_C(0x3e9d1bd0));

    value = npu_reciprocal_approx_traced(3.0f, &trace);
    TEST_CHECK(value == npu_reciprocal_approx(3.0f));
    TEST_CHECK(trace.reciprocal_valid == 1u);
    TEST_CHECK(trace.reciprocal_newton_bits ==
               UINT32_C(0x3f2aaaab));

    value = npu_rsqrt_approx_traced(4.0f, &trace);
    TEST_CHECK(value == npu_rsqrt_approx(4.0f));
    TEST_CHECK(trace.rsqrt_valid == 1u);
    TEST_CHECK(trace.rsqrt_newton_bits ==
               UINT32_C(0x3f7fffff));

    integer = npu_float_to_int_traced(
        -2.5f, NPU_ROUND_NEAREST_EVEN, &trace);
    TEST_CHECK(integer == -2);
    TEST_CHECK(trace.f2i_valid == 1u);
    TEST_CHECK(trace.f2i_input_bits ==
               UINT32_C(0xc0200000));

    (void)npu_exp_approx_traced(-17.0f, &trace);
    TEST_CHECK(trace.exp_valid == 0u);
    (void)npu_reciprocal_approx_traced(0.0f, &trace);
    TEST_CHECK(trace.reciprocal_valid == 0u);
    (void)npu_rsqrt_approx_traced(-1.0f, &trace);
    TEST_CHECK(trace.rsqrt_valid == 0u);
    return 0;
}

int test_math_accuracy(void)
{
    TEST_CHECK(math_test_exp_range() == 0);
    TEST_CHECK(math_test_reciprocal_range() == 0);
    TEST_CHECK(math_test_rsqrt_range() == 0);
    TEST_CHECK(math_test_activation_ranges() == 0);
    TEST_CHECK(math_test_mode0_checkpoints() == 0);
    return 0;
}

#ifdef NPU_MATH_ACCURACY_STANDALONE
int main(void)
{
    int line = test_math_accuracy();

    if (line != 0) {
        (void)printf(
            "math accuracy test failed at line %d\n", line);
        return 1;
    }
    (void)printf("math accuracy test passed\n");
    return 0;
}
#endif
