// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))

float fadds(float in1, float in2){
    float result;
    __ASM volatile("fadd.s %0, %1, %2" : "=f"(result): "f"(in1), "f"(in2));
    return result;
}

struct float_test{
    volatile float      in1_s, in2_s;
    float               expected_s;
    int32_t             test_num;
};

struct float_test test[] = {
    //test1:
    {.in1_s = 0.1f, .in2_s = 0.2f,
     .expected_s = 0.3000000119f,
     .test_num = 1
    },
    //test2:
    {.in1_s = 1e8f, .in2_s = 1.0f,
     .expected_s = 1e8f,
     .test_num = 2
    },
    //test3:
    {.in1_s = 3.1415926535f, .in2_s = 2.7182818184f,
     .expected_s = 5.8598747253f,
     .test_num = 3
    },
};

int main(void)
{
    int failures = 0;

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    for(int i = 0; i < ARRAY_SIZE(test); i++){
        const struct float_test *tp = &test[i];

        float  actual_s = fadds(tp->in1_s, tp->in2_s);
        if(actual_s != tp->expected_s){
            cpu_error("Fail: fadd.s test%0d: expected = 0x%lx, cat_val = 0x%lx\n", tp->test_num, tp->expected_s, actual_s);
        }
        else{
            cpu_info("Pass: fadd.s test%0d\n", tp->test_num);
        }
    }

    simend();
    while(1);
}

