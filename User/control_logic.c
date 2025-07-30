#include "control_logic.h"
#include "control.h"
//#include "uart.h"
#include "ti_msp_dl_config.h"

volatile uint8_t j;

void TIMER_LOGIC_INST_IRQHandler(void){

    switch (DL_TimerA_getPendingInterrupt(TIMER_LOGIC_INST)) {
        case DL_TIMERA_IIDX_ZERO:
            DL_TimerA_clearInterruptStatus(TIMER_LOGIC_INST, DL_TIMERA_INTERRUPT_ZERO_EVENT);
            // control();
            // j ++;
            // if(j == 100){
            //     j = 0;
            //     DL_GPIO_togglePins(GPIO_LEDS_PORT,GPIO_LEDS_PIN_LED_1_PIN);
            // }
        default:
            break;
    }

}

void NMI_Handler(void)
{
    __BKPT();
}

void HardFault_Handler(void)
{
    __BKPT();
}

void SVC_Handler(void)
{
    __BKPT();
}

void PendSV_Handler(void)
{
    __BKPT();
}

void SysTick_Handler(void)
{
    __BKPT();
}

void GROUP0_IRQHandler(void)
{
    __BKPT();
}



void TIMG8_IRQHandler(void)
{
    __BKPT();
}

void UART3_IRQHandler(void)
{
    __BKPT();
}

void ADC0_IRQHandler(void)
{
    __BKPT();
}

void ADC1_IRQHandler(void)
{
    __BKPT();
}

void CANFD0_IRQHandler(void)
{
    __BKPT();
}

void DAC0_IRQHandler(void)
{
    __BKPT();
}

void SPI0_IRQHandler(void)
{
    __BKPT();
}

void SPI1_IRQHandler(void)
{
    __BKPT();
}


void UART2_IRQHandler(void)
{
    __BKPT();
}

void UART0_IRQHandler(void)
{
    __BKPT();
}

void TIMG0_IRQHandler(void)
{
    __BKPT();
}

void TIMG6_IRQHandler(void)
{
    __BKPT();
}



void TIMG7_IRQHandler(void)
{
    __BKPT();
}

void TIMG12_IRQHandler(void)
{
    __BKPT();
}

void I2C0_IRQHandler(void)
{
    __BKPT();
}

void I2C1_IRQHandler(void)
{
    __BKPT();
}

void AES_IRQHandler(void)
{
    __BKPT();
}

void RTC_IRQHandler(void)
{
    __BKPT();
}

void DMA_IRQHandler(void)
{
    __BKPT();
}
