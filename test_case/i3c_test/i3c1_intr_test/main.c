// See LICENSE for license details.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "nuclei_sdk_soc.h"
#include "../../common/system.h"
#include "../../common/sysdef.h"

volatile int int_flg = 0;
uint32_t rx_data[2];
volatile uint32_t rx_data1 = 0;
volatile uint32_t rx_data2 = 0;

#define I3C_RX_INTR_MASK 0x2

// i30 interrupt func
void mcu_i3c1_intr_handler(void) {
    uint32_t intr_status;

    cpu_info("[INT]mcu_i3c1_intr            hit\n");
    send_label(Ext_MCU_I3C1_INTR_IRQn             );
    wait(100);
    intr_status = read32(MCU_SUB_I3C1_BASE_ADDR + INTR_STATUS);
    cpu_info("==i3c1 intr status before clear :0x%x==\n", intr_status);
    cpu_info("==[Hurydebug1104]READ FX FIFO DATA==\n");

    if(int_flg==0){
      rx_data1 = read32(MCU_SUB_I3C1_BASE_ADDR + RX_DATA_PORT);
      cpu_info("==rx fifo data1 :0x%x==\n",rx_data1);

    }
    if(int_flg==1){
      rx_data2 = read32(MCU_SUB_I3C1_BASE_ADDR + RX_DATA_PORT);
      cpu_info("==rx fifo data2 :0x%x==\n",rx_data2);

    }
   write32(MCU_SUB_I3C1_BASE_ADDR + INTR_STATUS, I3C_RX_INTR_MASK);
   intr_status = read32(MCU_SUB_I3C1_BASE_ADDR + INTR_STATUS);
   cpu_info("==i3c1 intr status after clear :0x%x==\n", intr_status);
   int_flg++;
}


int main(void)
{
    uint32_t returnCode;
    CSR_MCFGINFO_Type mcfg;
    uint32_t wdata,rdata;

    set_uncache_region(0x83ff000, 0xfffff000);
    crg_init();
    cpu_info("i3c1 main c start !!!\n");

    // Do PLIC present check via CSR MCFGINFO register
    // Just to confirm whether PLIC really present
    mcfg.d = __RV_CSR_READ(CSR_MCFG_INFO);
    if (mcfg.b.plic == 0) {
        cpu_error("PLIC is not present in this CPU, please check!\n");
        return 0;
    }

    // Initialize interrupt mode to clint/plic mode
    PLIC_Interrupt_Init();

    // inital timer interrupt as non-vector interrupt
    returnCode = PLIC_Register_IRQ(Ext_MCU_I3C1_INTR_IRQn , 1, (void*)mcu_i3c1_intr_handler );;

    __enable_irq();

    //cfg reg
    //1.0 set static addr en
    write32(MCU_SUB_SCU_BASE_ADDR + MCUSS_I3C1_STAT, 0x58800);
    //1.1 set thld
    rdata=read32(MCU_SUB_I3C1_BASE_ADDR + DATA_BUFFER_THLD_CTRL);
    write32(MCU_SUB_I3C1_BASE_ADDR + DATA_BUFFER_THLD_CTRL ,rdata & 0XFFFFF8FF);
    //1.2 set slave
    write32(MCU_SUB_I3C1_BASE_ADDR + DEVICE_CTRL_EXTENDED ,0X1);
    // clear stale RX interrupt status before enabling signal
    write32(MCU_SUB_I3C1_BASE_ADDR + INTR_STATUS, I3C_RX_INTR_MASK);
    //2. enable intr
    write32(MCU_SUB_I3C1_BASE_ADDR + INTR_STATUS_EN ,0xFFFF);
    write32(MCU_SUB_I3C1_BASE_ADDR + INTR_SIGNAL_EN ,0x2);
    //3. set dev ctrl
    write32(MCU_SUB_I3C1_BASE_ADDR + DEVICE_CTRL ,0x8000000);
    //4.set dev addr
    write32(MCU_SUB_I3C1_BASE_ADDR + DEVICE_ADDR ,0x8031);
    //5.en i3c ctrl
    rdata = read32(MCU_SUB_I3C1_BASE_ADDR + DEVICE_CTRL);
    write32(MCU_SUB_I3C1_BASE_ADDR + DEVICE_CTRL ,rdata  | 0x80000000);

    //iomux
    iomux_mcu1_cfg(70, 0);//i3c1 first mux scl
    iomux_mcu1_cfg(71, 0);//i3c1 first mux sda
    iomux_mcu1_cfg(72, 1);//i3c1 second mux scl
    iomux_mcu1_cfg(73, 1);//i3c1 second mux sda

    send_label(0x12345678);

    while(int_flg != 2);
    cpu_info("int_flg=%0d \n",int_flg);
    cpu_info("[HURYDEBUG1105]rx_data1=0x%x, rx_data2=0x%x \n",rx_data1,rx_data2);

    if(rx_data1 == 0x998855aa && rx_data2 == 0xaa558899){
        cpu_info("==Check Data Pass!!!== \n");
    }
    else{
        cpu_error("==Check Data Fail!!! act data0 = 0x%x, act data1 = 0x%x,expect data0=0x998855aa, expect data1= 0xaa558899== \n",rx_data1, rx_data2);
    }

    cpu_info("i3c1 test done !!!\n");

    simend();
    while(1);
}
