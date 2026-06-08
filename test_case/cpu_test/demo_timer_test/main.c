// See LICENSE for license details.
#include <stdio.h>
#include "nuclei_sdk_soc.h"
#include "system.h"
#include "sysdef.h"

#if defined(__ECLIC_PRESENT) && (__ECLIC_PRESENT == 1)
#else
#error "This example require CPU ECLIC feature"
#endif

#if defined(__SYSTIMER_PRESENT) && (__SYSTIMER_PRESENT == 1)
#else
#error "This example require CPU System Timer feature"
#endif

/* Define the interrupt handler name same as vector table in case download mode is flashxip. */
#define mtimer_irq_handler     eclic_mtip_handler
#define mtimer_sw_irq_handler  eclic_msip_handler

static volatile uint32_t int0_cnt = 0;    /* mtip timer interrupt test counter */
static volatile uint32_t int1_cnt = 0;    /* msip timer interrupt test counter */
volatile unsigned int msip_trig_flag = 1; /* sw trigger mtimer sw interrupt flag */

#define LOOP_COUNT      2

void mtimer_irq_handler(void)
{
    int0_cnt++;
    cpu_info("MTimer IRQ handler %d\n", int0_cnt);
    uint64_t now = SysTimer_GetLoadValue();
    SysTimer_SetCompareValue(now + SOC_TIMER_FREQ / 10);
}

void mtimer_sw_irq_handler(void)
{
    SysTimer_ClearSWIRQ();
    int1_cnt++;
    cpu_info("MTimer SW IRQ handler %d\n", int1_cnt);
    msip_trig_flag = 1;
}

void setup_timer()
{
    cpu_info("init timer and start\n");
    uint64_t now = SysTimer_GetLoadValue();
    uint64_t then = now + SOC_TIMER_FREQ / 10;
    SysTimer_SetCompareValue(then);
}

int main(void)
{
    uint32_t returnCode;

    set_uncache_region(0x401ff000, 0xfffff000);
    crg_init();

    cpu_info("register mtimer_irq_handler\n");
    returnCode = ECLIC_Register_IRQ(
                     SysTimer_IRQn, ECLIC_NON_VECTOR_INTERRUPT, ECLIC_LEVEL_TRIGGER, 1, 0,
                     (void *)mtimer_irq_handler); /* register system timer interrupt */

    __enable_irq(); /* enable global interrupt */

    setup_timer(); /* initialize timer */

    while (int0_cnt < LOOP_COUNT);
    ECLIC_DisableIRQ(SysTimer_IRQn); /* Disable MTIP iterrupt */

    cpu_info("register mtimer_sw_irq_handler\n");
    returnCode = ECLIC_Register_IRQ(
                     SysTimerSW_IRQn, ECLIC_NON_VECTOR_INTERRUPT,
                     ECLIC_POSTIVE_EDGE_TRIGGER, 2, 0,
                     (void *)mtimer_sw_irq_handler); /* register system timer SW interrupt */

    do {
        if (msip_trig_flag == 1) {
            msip_trig_flag = 0;
            SysTimer_SetSWIRQ(); /* trigger timer sw interrupt */
            delay_1ms(10);
        }
    } while (int1_cnt < LOOP_COUNT); /* check test end condition */

    cpu_info("MTimer msip and mtip interrupt test finish and pass\n");

    if (returnCode != 0) { /* Check return code for errors */
        //return -1;
        cpu_error("cpu returnCode error");
    }

    simend();
    while(1);
    //return 0;
}

