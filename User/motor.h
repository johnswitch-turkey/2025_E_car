#ifndef __MOTOR_H
#define __MOTOR_H

#include "ti_msp_dl_config.h"

/*******************电机相关************************/
/* 编码器线数 */
#define ENCODER_RESOLUTION                     13

/* 经过倍频之后的总分辨率 */
#define ENCODER_TOTAL_RESOLUTION             (ENCODER_RESOLUTION * 4)  /* 4倍频后的总分辨率 */

/* 减速电机减速比 */
#define REDUCTION_RATIO  28

/*在sysTick里调用PID计算的周期，以毫秒为单位*/
#define SPEED_PID_PERIOD  10    //这个要看定时器7的中断周期
#define TARGET_SPEED_MAX  2000  //// 60rpm可以3s走完60cm


/*******************驱动相关************************/
#define MOTOR_TIM htim1
#define MOTOR1_CHANNEL TIM_CHANNEL_1
#define MOTOR2_CHANNEL TIM_CHANNEL_2

void Motor_SetSpeed(uint16_t speed1, uint16_t speed2);

void motor1_enable(void);
void motor2_enable(void);

void motor1_disable(void);
void motor2_disable(void);



extern long g_lMotorPulseSigma;//电机25ms内累计脉冲总和
extern long g_lMotor2PulseSigma;
extern short g_nMotorPulse,g_nMotor2Pulse;//全局变量， 保存电机脉冲数值


void GetMotorPulse(void);

float Limit_speed (float * val );

#endif
