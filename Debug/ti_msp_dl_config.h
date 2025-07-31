/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_ENCODER */
#define PWM_ENCODER_INST                                                   TIMA0
#define PWM_ENCODER_INST_IRQHandler                             TIMA0_IRQHandler
#define PWM_ENCODER_INST_INT_IRQN                               (TIMA0_INT_IRQn)
#define PWM_ENCODER_INST_CLK_FREQ                                       80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_ENCODER_C0_PORT                                           GPIOA
#define GPIO_PWM_ENCODER_C0_PIN                                    DL_GPIO_PIN_8
#define GPIO_PWM_ENCODER_C0_IOMUX                                (IOMUX_PINCM19)
#define GPIO_PWM_ENCODER_C0_IOMUX_FUNC               IOMUX_PINCM19_PF_TIMA0_CCP0
#define GPIO_PWM_ENCODER_C0_IDX                              DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_ENCODER_C1_PORT                                           GPIOA
#define GPIO_PWM_ENCODER_C1_PIN                                    DL_GPIO_PIN_9
#define GPIO_PWM_ENCODER_C1_IOMUX                                (IOMUX_PINCM20)
#define GPIO_PWM_ENCODER_C1_IOMUX_FUNC               IOMUX_PINCM20_PF_TIMA0_CCP1
#define GPIO_PWM_ENCODER_C1_IDX                              DL_TIMER_CC_1_INDEX



/* Defines for TIMER_LOGIC */
#define TIMER_LOGIC_INST                                                 (TIMA1)
#define TIMER_LOGIC_INST_IRQHandler                             TIMA1_IRQHandler
#define TIMER_LOGIC_INST_INT_IRQN                               (TIMA1_INT_IRQn)
#define TIMER_LOGIC_INST_LOAD_VALUE                                      (9999U)
/* Defines for TIMER_BUTTON */
#define TIMER_BUTTON_INST                                                (TIMG0)
#define TIMER_BUTTON_INST_IRQHandler                            TIMG0_IRQHandler
#define TIMER_BUTTON_INST_INT_IRQN                              (TIMG0_INT_IRQn)
#define TIMER_BUTTON_INST_LOAD_VALUE                                    (39999U)



/* Defines for UART_TJC */
#define UART_TJC_INST                                                      UART1
#define UART_TJC_INST_FREQUENCY                                         40000000
#define UART_TJC_INST_IRQHandler                                UART1_IRQHandler
#define UART_TJC_INST_INT_IRQN                                    UART1_INT_IRQn
#define GPIO_UART_TJC_RX_PORT                                              GPIOA
#define GPIO_UART_TJC_TX_PORT                                              GPIOA
#define GPIO_UART_TJC_RX_PIN                                      DL_GPIO_PIN_18
#define GPIO_UART_TJC_TX_PIN                                      DL_GPIO_PIN_17
#define GPIO_UART_TJC_IOMUX_RX                                   (IOMUX_PINCM40)
#define GPIO_UART_TJC_IOMUX_TX                                   (IOMUX_PINCM39)
#define GPIO_UART_TJC_IOMUX_RX_FUNC                    IOMUX_PINCM40_PF_UART1_RX
#define GPIO_UART_TJC_IOMUX_TX_FUNC                    IOMUX_PINCM39_PF_UART1_TX
#define UART_TJC_BAUD_RATE                                              (115200)
#define UART_TJC_IBRD_40_MHZ_115200_BAUD                                    (21)
#define UART_TJC_FBRD_40_MHZ_115200_BAUD                                    (45)





/* Port definition for Pin Group GPIO_LEDS */
#define GPIO_LEDS_PORT                                                   (GPIOB)

/* Defines for PIN_LED_1: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_LEDS_PIN_LED_1_PIN                                 (DL_GPIO_PIN_22)
#define GPIO_LEDS_PIN_LED_1_IOMUX                                (IOMUX_PINCM50)
/* Defines for DIR_L1: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_DIRS_DIR_L1_PORT                                            (GPIOB)
#define GPIO_DIRS_DIR_L1_PIN                                    (DL_GPIO_PIN_13)
#define GPIO_DIRS_DIR_L1_IOMUX                                   (IOMUX_PINCM30)
/* Defines for DIR_L2: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_DIRS_DIR_L2_PORT                                            (GPIOB)
#define GPIO_DIRS_DIR_L2_PIN                                    (DL_GPIO_PIN_27)
#define GPIO_DIRS_DIR_L2_IOMUX                                   (IOMUX_PINCM58)
/* Defines for DIR_R1: GPIOA.26 with pinCMx 59 on package pin 30 */
#define GPIO_DIRS_DIR_R1_PORT                                            (GPIOA)
#define GPIO_DIRS_DIR_R1_PIN                                    (DL_GPIO_PIN_26)
#define GPIO_DIRS_DIR_R1_IOMUX                                   (IOMUX_PINCM59)
/* Defines for PIN_R2: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_DIRS_PIN_R2_PORT                                            (GPIOB)
#define GPIO_DIRS_PIN_R2_PIN                                    (DL_GPIO_PIN_21)
#define GPIO_DIRS_PIN_R2_IOMUX                                   (IOMUX_PINCM49)
/* Defines for L3: GPIOA.22 with pinCMx 47 on package pin 18 */
#define GPIO_GREY_SENSOR_L3_PORT                                         (GPIOA)
#define GPIO_GREY_SENSOR_L3_PIN                                 (DL_GPIO_PIN_22)
#define GPIO_GREY_SENSOR_L3_IOMUX                                (IOMUX_PINCM47)
/* Defines for L2: GPIOA.21 with pinCMx 46 on package pin 17 */
#define GPIO_GREY_SENSOR_L2_PORT                                         (GPIOA)
#define GPIO_GREY_SENSOR_L2_PIN                                 (DL_GPIO_PIN_21)
#define GPIO_GREY_SENSOR_L2_IOMUX                                (IOMUX_PINCM46)
/* Defines for L1: GPIOA.16 with pinCMx 38 on package pin 9 */
#define GPIO_GREY_SENSOR_L1_PORT                                         (GPIOA)
#define GPIO_GREY_SENSOR_L1_PIN                                 (DL_GPIO_PIN_16)
#define GPIO_GREY_SENSOR_L1_IOMUX                                (IOMUX_PINCM38)
/* Defines for M: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_GREY_SENSOR_M_PORT                                          (GPIOA)
#define GPIO_GREY_SENSOR_M_PIN                                  (DL_GPIO_PIN_15)
#define GPIO_GREY_SENSOR_M_IOMUX                                 (IOMUX_PINCM37)
/* Defines for R1: GPIOA.14 with pinCMx 36 on package pin 7 */
#define GPIO_GREY_SENSOR_R1_PORT                                         (GPIOA)
#define GPIO_GREY_SENSOR_R1_PIN                                 (DL_GPIO_PIN_14)
#define GPIO_GREY_SENSOR_R1_IOMUX                                (IOMUX_PINCM36)
/* Defines for R2: GPIOB.23 with pinCMx 51 on package pin 22 */
#define GPIO_GREY_SENSOR_R2_PORT                                         (GPIOB)
#define GPIO_GREY_SENSOR_R2_PIN                                 (DL_GPIO_PIN_23)
#define GPIO_GREY_SENSOR_R2_IOMUX                                (IOMUX_PINCM51)
/* Defines for R3: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_GREY_SENSOR_R3_PORT                                         (GPIOA)
#define GPIO_GREY_SENSOR_R3_PIN                                 (DL_GPIO_PIN_13)
#define GPIO_GREY_SENSOR_R3_IOMUX                                (IOMUX_PINCM35)
/* Port definition for Pin Group ENCODERA */
#define ENCODERA_PORT                                                    (GPIOB)

/* Defines for E1A: GPIOB.18 with pinCMx 44 on package pin 15 */
// groups represented: ["ENCODERB","KEYS","ENCODERA"]
// pins affected: ["E2A","E2B","KEY1","KEY2","KEY3","E1A","E1B"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define ENCODERA_E1A_IIDX                                   (DL_GPIO_IIDX_DIO18)
#define ENCODERA_E1A_PIN                                        (DL_GPIO_PIN_18)
#define ENCODERA_E1A_IOMUX                                       (IOMUX_PINCM44)
/* Defines for E1B: GPIOB.17 with pinCMx 43 on package pin 14 */
#define ENCODERA_E1B_IIDX                                   (DL_GPIO_IIDX_DIO17)
#define ENCODERA_E1B_PIN                                        (DL_GPIO_PIN_17)
#define ENCODERA_E1B_IOMUX                                       (IOMUX_PINCM43)
/* Port definition for Pin Group ENCODERB */
#define ENCODERB_PORT                                                    (GPIOB)

/* Defines for E2A: GPIOB.15 with pinCMx 32 on package pin 3 */
#define ENCODERB_E2A_IIDX                                   (DL_GPIO_IIDX_DIO15)
#define ENCODERB_E2A_PIN                                        (DL_GPIO_PIN_15)
#define ENCODERB_E2A_IOMUX                                       (IOMUX_PINCM32)
/* Defines for E2B: GPIOB.16 with pinCMx 33 on package pin 4 */
#define ENCODERB_E2B_IIDX                                   (DL_GPIO_IIDX_DIO16)
#define ENCODERB_E2B_PIN                                        (DL_GPIO_PIN_16)
#define ENCODERB_E2B_IOMUX                                       (IOMUX_PINCM33)
/* Defines for KEY1: GPIOB.14 with pinCMx 31 on package pin 2 */
#define KEYS_KEY1_PORT                                                   (GPIOB)
#define KEYS_KEY1_IIDX                                      (DL_GPIO_IIDX_DIO14)
#define KEYS_KEY1_PIN                                           (DL_GPIO_PIN_14)
#define KEYS_KEY1_IOMUX                                          (IOMUX_PINCM31)
/* Defines for KEY2: GPIOB.19 with pinCMx 45 on package pin 16 */
#define KEYS_KEY2_PORT                                                   (GPIOB)
#define KEYS_KEY2_IIDX                                      (DL_GPIO_IIDX_DIO19)
#define KEYS_KEY2_PIN                                           (DL_GPIO_PIN_19)
#define KEYS_KEY2_IOMUX                                          (IOMUX_PINCM45)
/* Defines for KEY3: GPIOB.20 with pinCMx 48 on package pin 19 */
#define KEYS_KEY3_PORT                                                   (GPIOB)
#define KEYS_KEY3_IIDX                                      (DL_GPIO_IIDX_DIO20)
#define KEYS_KEY3_PIN                                           (DL_GPIO_PIN_20)
#define KEYS_KEY3_IOMUX                                          (IOMUX_PINCM48)
/* Defines for KEY4: GPIOA.12 with pinCMx 34 on package pin 5 */
#define KEYS_KEY4_PORT                                                   (GPIOA)
// pins affected by this interrupt request:["KEY4"]
#define KEYS_GPIOA_INT_IRQN                                     (GPIOA_INT_IRQn)
#define KEYS_GPIOA_INT_IIDX                     (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define KEYS_KEY4_IIDX                                      (DL_GPIO_IIDX_DIO12)
#define KEYS_KEY4_PIN                                           (DL_GPIO_PIN_12)
#define KEYS_KEY4_IOMUX                                          (IOMUX_PINCM34)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_ENCODER_init(void);
void SYSCFG_DL_TIMER_LOGIC_init(void);
void SYSCFG_DL_TIMER_BUTTON_init(void);
void SYSCFG_DL_UART_TJC_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
