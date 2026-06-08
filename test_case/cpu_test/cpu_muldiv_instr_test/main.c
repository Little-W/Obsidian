// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

int64_t test_mulw(uint64_t in1, uint64_t in2){
    int64_t result;
    __ASM volatile("mulw %0, %1, %2" : "=r"(result): "r"(in1), "r"(in2));
    return result;
}
int64_t test_divw(uint64_t in1, uint64_t in2){
    int64_t result;
    __ASM volatile("divw %0, %1, %2" : "=r"(result): "r"(in1), "r"(in2));
    return result;
}

int main(void)
{
    int failures = 0;

    typedef struct {
        uint64_t in1, in2;
        int64_t  expected;
        int32_t  test_num;
    }type_cal;
    type_cal mulw[] = {
        //test1:
        {0x1111111112345678, 0x2222222287654321, 0x0000000070b88d78, 1},
        //test2:
        {0x1111111100000000, 0x2222222200000000, 0x0000000000000000, 2},
        //test3:
        {0x1234567880000000, 0x55555555ffffffff, 0xffffffff80000000, 3},
    };
    type_cal divw[] = {
        //test1:
        {0x111111110000000c, 0x2222222200000003, 0x0000000000000004, 1},
        //test2:
        {0xaaaaaaaa80000000, 0x2222222200000002, 0xffffffffc0000000, 2},
        //test3:
        {0x1234567812345678, 0x5555555510000000, 0x0000000000000001, 3},
    };

    set_uncache_region(0x401ff000, 0xfffff000);

    cpu_info("init crg start\n");
    crg_init();
    cpu_info("init crg done\n");

    for(int i = 0; i < 3; i++){
        int64_t act_val = test_mulw(mulw[i].in1, mulw[i].in2);
        if(act_val != mulw[i].expected){
            cpu_error("Fail: mulw test%0d: expected = 0x%lx, cat_val = 0x%lx\n", mulw[i].test_num, mulw[i].expected, act_val);
        }
        else{
            cpu_info("Pass: mulw test%0d\n", mulw[i].test_num);
        }
    }

    for(int i = 0; i < 3; i++){
        int64_t act_val = test_divw(divw[i].in1, divw[i].in2);
        if(act_val != divw[i].expected){
            cpu_error("Fail: divw test%0d: expected = 0x%lx, cat_val = 0x%lx\n", divw[i].test_num, divw[i].expected, act_val);
        }
        else{
            cpu_info("Pass: divw test%0d\n", divw[i].test_num);
        }
    }

    simend();
    while(1);
}

