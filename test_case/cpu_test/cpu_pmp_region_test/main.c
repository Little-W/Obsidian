// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

#if !defined(__PMP_PRESENT) || (__PMP_PRESENT == 0)
/* __PMP_PRESENT should be defined in <Device>.h */
#warning "__PMP_PRESENT is not defined or equal to 0, please check!"
#warning "This example require CPU PMP feature!"
#endif

#define MEDELEG_ECALL     (1 << 9)
#define MEDELEG_PAGEFAULT ((1 << 12) | (1 << 13) | (1 << 15))
//interrupt config
volatile uint32_t user_flg = 0;
volatile uint64_t op_flg   = 0;

void configure_pmp(void){
    uint64_t wdata;
    cpu_info("config_pmp start!\n");

    //pmp protect len:
    //config pmp0
    //wdata =  0x2084007;
      wdata = 0x10004007;
    __RV_CSR_WRITE(pmpaddr0, wdata);
    cpu_info("debug: ***** pmpaddr0 = 0x%lx\n",__RV_CSR_READ(pmpaddr0));
    //config pmp1    
    //wdata =  0x2084407;
      wdata = 0x10004407;  
    __RV_CSR_WRITE(pmpaddr1, wdata);
    cpu_info("debug: ***** pmpaddr1 = 0x%lx\n",__RV_CSR_READ(pmpaddr1));
    //config pmp2
    //wdata =  0x2084807;
      wdata = 0x10004807;
    __RV_CSR_WRITE(pmpaddr2, wdata);
    cpu_info("debug: ***** pmpaddr2 = 0x%lx\n",__RV_CSR_READ(pmpaddr2));
    //config pmp3
    //wdata =  0x2084c07;
      wdata = 0x10004c07;  
    __RV_CSR_WRITE(pmpaddr3, wdata);
    cpu_info("debug: ***** pmpaddr3 = 0x%lx\n",__RV_CSR_READ(pmpaddr3));
    //config pmp4
    //wdata =  0x2085007;
      wdata = 0x10005007;  
    __RV_CSR_WRITE(pmpaddr4, wdata);
    cpu_info("debug: ***** pmpaddr4 = 0x%lx\n",__RV_CSR_READ(pmpaddr4));
    //config pmp5
    //wdata =  0x2085407;
      wdata = 0x10005407;
    __RV_CSR_WRITE(pmpaddr5, wdata);
    cpu_info("debug: ***** pmpaddr5 = 0x%lx\n",__RV_CSR_READ(pmpaddr5));
    //config pmp6
    //wdata = 0x2085807;
      wdata = 0x10005807;  
    __RV_CSR_WRITE(pmpaddr6, wdata);
    cpu_info("debug: ***** pmpaddr6 = 0x%lx\n",__RV_CSR_READ(pmpaddr6));
    //config pmp7
    wdata = 0x1ffffff;
    __RV_CSR_WRITE(pmpaddr7, wdata);
    cpu_info("debug: ***** pmpaddr7 = 0x%lx\n",__RV_CSR_READ(pmpaddr7));

    //pmp cfg
    //set to read/write/execute(except pmp0)
    wdata = 0x1f1f1f1f1f1f1f18;
    __RV_CSR_WRITE(pmpcfg0, wdata);
    cpu_info("debug: ***** pmpcfg0 = 0x%lx\n",__RV_CSR_READ(pmpcfg0));
}

//user entry
void user_main(void){
    uint32_t rdata;
    int      i;
    user_flg = 1;
    cpu_info("user_mode: RISC-V user mode say hello!\n");


    //the addr is protected by pmp and permisssions is R/W/X, so can read it normally
    for(i = 1; i < 8; i++){
        op_flg = 0x40010000+((1+i) << 12)+8*i;
        write64(0x40010000+((1+i) << 12)+8*i,0xaaaa0000+4*i);
        rdata = read64(0x40010000+((1+i) << 12)+8*i);
        if (rdata != 0xaaaa0000+4*i)
            cpu_error("user_mode: cpu read addr = 0x%lx test fail, rdata = 0x%0x, gld_data = 0x%0x \n", op_flg, rdata, 0xaaaa0000+4*i);
    }

    op_flg = 1;
    rdata = read64(0x40010000);
    //cpu_error("shouldn't run at here!\n");
    simend();
}

//machine exception handle
__attribute__ ((aligned(4))) void machine_mode_exception_handler(void) {
    cpu_info("RISC-V machine exception hansler!\n");
    if(user_flg != 1){
        cpu_error("not enter user_main !~~\n");
        simend();
    }

    cpu_info("Caught illegal instruction during access non X/W/R region\n");
    simend();
}

int main(){
    uint32_t  rdata;
    uintptr_t mstatus;

    set_uncache_region(0x401ff000, 0xfffff000);

	  cpu_info("pmp test!~~~\n");

    //0. write value to ram
    write64(0x40000000,0x12345678);
    rdata = read64(0x40000000);
    if (rdata != 0x12345678)
        cpu_error("machine_mode: cpu read data test fail \n");

    //1. Disable interrupts by setting MSTATUS.MIE to 0.
    cpu_info("debug: mstatus=%x\n",__RV_CSR_READ(mstatus));
    asm volatile("csrc mstatus, %0" : : "r"(1 << 3));
    cpu_info("debug: mstatus=%x\n",__RV_CSR_READ(mstatus));

    //2. Write mtvec CSR with the base address of the machine mode exception handler. This is a
    //   required step in any boot flow.
    uintptr_t machine_vec = (uintptr_t)machine_mode_exception_handler;
    asm volatile("csrw mtvec, %0" : : "r"(machine_vec));

    //3. Write mstatus.MPP to 0 to set the previous mode to user, which allows us to return to that mode.
    asm volatile("csrc mstatus, %0" : : "r"(3 << 11));
    cpu_info("debug: mstatus=%x\n",__RV_CSR_READ(mstatus));

    //4. Setup the Physical Memory Protection (PMP) regions to grant the required regions to user
    //   and supervisor mode, and optionally, revoke permissions from machine mode.
    configure_pmp();

    //5. Write stvec CSR with the base address of the supervisor mode exception handler.
    //6. Write medeleg register to delegate exceptions to supervisor mode
    //7. Write mstatus.FS to enable floating-point (if supported).
    //8. Store machine mode user registers to stack or to an application-specific frame pointer

    //9. Write mepc with the entry point of user mode software
    uintptr_t user_entry = (uintptr_t)user_main;
    asm volatile("csrw mepc, %0" : : "r"(user_entry));
    cpu_info("debug: mepc=%x\n",__RV_CSR_READ(mepc));
    cpu_info("set user_entry done !~~~\n");

    //10. Execute mret instruction to enter user mode.
    asm volatile("mret");
    cpu_info("66666666666666666666666666!~~~\n");

    while(1);//code can not run
}
