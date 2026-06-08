#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"
#include "memmap_test_struct.h"
static void test_noc_array(const PhyRegTypeDef_t* array, size_t num_elements, const char* array_name) {
    for (size_t i = 0; i < num_elements; i++) {
        uint64_t addr = array[i].soc_base + array[i].reg_offset;
        uint32_t addr_hi = (uint32_t)(addr >> 32);
        uint32_t addr_lo = (uint32_t)(addr & 0xFFFFFFFFu);

        uint32_t rdata = read32(addr);
        if (rdata != array[i].reset_value) {
            cpu_error("%s %s Index=%u: ResetValue Error! addr=0x%x%x, exp=0x%x, act=0x%x\n",
                      array_name,
                      array[i].ip_name,
                      (unsigned int)array[i].index,
                      addr_hi,
                      addr_lo,
                      array[i].reset_value,
                      rdata);
        }

        uint32_t test_vals[2] = {0x55555555u, 0xAAAAAAAAu};
        for (int j = 0; j < 2; j++) {
            write32(addr, test_vals[j]);
            rdata = read32(addr);
            uint32_t exp_data = (test_vals[j] & array[i].wr_mask) |
                                (array[i].reset_value & ~array[i].wr_mask);
            if (rdata != exp_data) {
                cpu_error("%s %s Index=%u: Mask Write Error! addr=0x%x%x, write=0x%x, exp=0x%x, act=0x%x\n",
                          array_name,
                          array[i].ip_name,
                          (unsigned int)array[i].index,
                          addr_hi,
                          addr_lo,
                          test_vals[j],
                          exp_data,
                          rdata);
            }
        }

        cpu_info("%s %s Index=%u: Initial & Mask Test Pass !!!\n",
                 array_name,
                 array[i].ip_name,
                 (unsigned int)array[i].index);
    }
}

static void test_noc_reg_id_array(const MemTypeDef_t* array, size_t num_elements, const char* array_name) {
    for (size_t i = 0; i < num_elements; i++) {
        uint64_t addr = array[i].soc_base + array[i].reg_offset;
        uint32_t addr_hi = (uint32_t)(addr >> 32);
        uint32_t addr_lo = (uint32_t)(addr & 0xFFFFFFFFu);

        uint32_t rdata = read32(addr);
        if (rdata == 0x00000000u) {
            cpu_error("%s %s: ID Read Error! addr=0x%x%x, act=0x%x\n",
                      array_name,
                      array[i].ip_name,
                      addr_hi,
                      addr_lo,
                      rdata);
        } else {
            cpu_info("%s %s: ID Read Pass, addr=0x%x%x, data=0x%x\n",
                     array_name,
                     array[i].ip_name,
                     addr_hi,
                     addr_lo,
                     rdata);
        }
    }
}

int main(void)
{

    set_uncache_region(0x401ff000, 0xffff000);
    crg_init();
    write32(AON_SUB_PMU_BASE_ADDR+0x40,0x7ff);
    write32(MEDIA_SUB_CRG_BASE_ADDR      , 0x7f        );
    write32(MEDIA_SUB_CRG_BASE_ADDR +0x4     , 0x0      );

    cpu_info("Case5 NOC register test starting\n");
    test_noc_reg_id_array(jtag_ap_noc_reg_id_addr,
                          sizeof(jtag_ap_noc_reg_id_addr) / sizeof(MemTypeDef_t),
                          "jtag_ap_noc_reg_id_addr");

    test_noc_array(jtag_ap_noc_sub_reg,
                   sizeof(jtag_ap_noc_sub_reg) / sizeof(PhyRegTypeDef_t),
                   "jtag_ap_noc_sub_reg");
    
    cpu_info("Case5 done !!!\n");
    simend();
    while(1);
}