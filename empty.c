/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"

#include "motor.h"
#include "control.h"
#include "encoder.h"
#include "pid.h"

int main(void)
{
    SYSCFG_DL_init();

    NVIC_ClearPendingIRQ(UART_OPENCV_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_OPENCV_INST_INT_IRQN);
    NVIC_ClearPendingIRQ(TIMER_LOGIC_INST_INT_IRQN);
    NVIC_EnableIRQ(TIMER_LOGIC_INST_INT_IRQN);
    DL_TimerA_enableInterrupt(TIMER_LOGIC_INST, DL_TIMERA_INTERRUPT_ZERO_EVENT);

    NVIC_ClearPendingIRQ(GPIO_ENCODER_INT_IRQN);
    NVIC_EnableIRQ(GPIO_ENCODER_INT_IRQN);

    DL_GPIO_setPins(GPIO_DIRS_DIR_L1_PORT, GPIO_DIRS_DIR_L1_PIN);
    DL_GPIO_clearPins(GPIO_DIRS_DIR_L2_PORT, GPIO_DIRS_DIR_L2_PIN);
    DL_GPIO_setPins(GPIO_DIRS_DIR_R1_PORT, GPIO_DIRS_DIR_R1_PIN);
    DL_GPIO_clearPins(GPIO_DIRS_PIN_R2_PORT, GPIO_DIRS_PIN_R2_PIN);
    Motor_SetSpeed(400, 400);
    set_p_i_d(&pid_speedX, 1.0, 0.0, 0.0);
    set_p_i_d(&pid_speedY, 1.0, 0.0, 0.0);



    while (1) {
        // DL_GPIO_togglePins(GPIO_LEDS_PORT,GPIO_LEDS_PIN_LED_1_PIN);
        // delay_cycles(40000000);
        // DL_GPIO_setPins(GPIO_LEDS_PORT, GPIO_LEDS_PIN_LED_1_PIN);
        // delay_cycles(40000000);
    }
}





