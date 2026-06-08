// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

int64_t test_addw(uint64_t in1, uint64_t in2){
    int64_t result;
    __ASM volatile("addw %0, %1, %2" : "=r"(result): "r"(in1), "r"(in2));
    return result;
}

int main(void)
{
    int failures = 0;

    struct {
        uint64_t in1, in2;
        int64_t  expected;
        int32_t  test_num;
    }tests[] = {
        //test1: positive number + positive number, result is positive number
        {0x1234567812345678, 0x8765432167654321, 0x0000000079999999, 1},
        //test2: positive number + positive number, result is negitive number
        {0x1234567812345678, 0x8765432187654321, 0xffffffff99999999, 2},
        //test3: max positive number + min negative number, result is -1(sign extened)
        {0x123456787fffffff, 0x8765432180000000, 0xffffffffffffffff, 3},
        //test4: overflow
        {0x1234567870000000, 0x8765432170000000, 0xffffffffe0000000, 4},
        //test5: high 32bit are same, low 32bit are not same, result is same
        {0x1111111122222222, 0x3333333344444444, 0x0000000066666666, 5},
        //test6: high 32bit are same, low 32bit are not same, result is same
        {0xaaaaaaaa22222222, 0xbbbbbbbb44444444, 0x0000000066666666, 6},
    };

    set_uncache_region(0x401ff000, 0xfffff000);

    crg_init();

    for(int i = 0; i < 6; i++){
        int64_t act_val = test_addw(tests[i].in1, tests[i].in2);
        if(act_val != tests[i].expected){
            cpu_error("Fail: test%0d: expected = %lx, cat_val = %lx\n", tests[i].test_num, tests[i].expected, act_val);
        }
        else{
            cpu_info("Pass: test%0d\n", tests[i].test_num);
        }
    }

    simend();
    while(1);
}

