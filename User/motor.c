#include "motor.h"

#include "ti_msp_dl_config.h"



/*******************驱动相关************************/
void Motor_SetSpeed(int32_t speed1, int32_t speed2) {
    uint16_t abs_speed1;
    uint16_t abs_speed2;
    if (speed1 > 0){
        DL_GPIO_setPins(GPIO_DIRS_DIR_L1_PORT, GPIO_DIRS_DIR_L1_PIN);
        DL_GPIO_clearPins(GPIO_DIRS_DIR_L2_PORT, GPIO_DIRS_DIR_L2_PIN);
        abs_speed1 = speed1;
    } else if (speed1 < 0){
        DL_GPIO_clearPins(GPIO_DIRS_DIR_L1_PORT, GPIO_DIRS_DIR_L1_PIN);
        DL_GPIO_setPins(GPIO_DIRS_DIR_L2_PORT, GPIO_DIRS_DIR_L2_PIN);
        abs_speed1 = -speed1;
    }
    else {
        DL_TimerA_stopCounter(PWM_ENCODER_INST);
    }
    if (speed2 > 0){
        DL_GPIO_setPins(GPIO_DIRS_DIR_R1_PORT, GPIO_DIRS_DIR_R1_PIN);
        DL_GPIO_clearPins(GPIO_DIRS_PIN_R2_PORT, GPIO_DIRS_PIN_R2_PIN);
        abs_speed2 = speed2;
    }
    else if (speed2 < 0){
        DL_GPIO_clearPins(GPIO_DIRS_DIR_R1_PORT, GPIO_DIRS_DIR_R1_PIN);
        DL_GPIO_setPins(GPIO_DIRS_PIN_R2_PORT, GPIO_DIRS_PIN_R2_PIN);
        abs_speed2 = -speed2;
    }
    else{
        DL_TimerA_stopCounter(PWM_ENCODER_INST);
    }

    static uint16_t speed1_out;
    static uint16_t speed2_out;

        speed1_out = 2000 - abs_speed1;
		DL_TimerA_stopCounter(PWM_ENCODER_INST);
        //MOTOR_TIM.Instance->CCR1 = speed1;
        DL_TimerG_setCaptureCompareValue(PWM_ENCODER_INST,(uint32_t)speed1_out,DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
        // MOTOR_TIM.Instance->EGR = TIM_EGR_UG;
        // PWM_ENCODER_INST->CONTROL |= GPT_CONTROL_LOAD_MASK;
		DL_TimerA_startCounter(PWM_ENCODER_INST);
    


        

        speed2_out = 2000 - abs_speed2;
        DL_TimerA_stopCounter(PWM_ENCODER_INST);
        //MOTOR_TIM.Instance->CCR1 = speed1;
        DL_TimerG_setCaptureCompareValue(PWM_ENCODER_INST,(uint32_t)speed2_out,DL_TIMERA_CAPTURE_COMPARE_1_INDEX);
        // MOTOR_TIM.Instance->EGR = TIM_EGR_UG;
        // PWM_ENCODER_INST->CONTROL |= GPT_CONTROL_LOAD_MASK;
		DL_TimerA_startCounter(PWM_ENCODER_INST);
    }


void Motor_Enable(void){
    DL_TimerA_startCounter(PWM_ENCODER_INST);
}

void Motor_Disable(void){
    DL_TimerA_stopCounter(PWM_ENCODER_INST);
}

float Limit_speed (float * val )
{
    if (* val > TARGET_SPEED_MAX)
	{
		* val = TARGET_SPEED_MAX;   
	}
	else if (* val < -TARGET_SPEED_MAX)
	{
		* val = -TARGET_SPEED_MAX;
	}

    return * val;
								
}




/*******************编码器相关************************/

// long g_lMotorPulseSigma = 0;
// long g_lMotor2PulseSigma = 0;
// short g_nMotorPulse = 0;
// short g_nMotor2Pulse = 0;

/*******************实际运行时读取编码器数值************************/
// void GetMotorPulse(void)//读取电机脉冲
// {
// 	g_nMotorPulse = (short)(__HAL_TIM_GET_COUNTER(&MOTOR1_TIM_ENCODER));//获取计数器值
// 	g_nMotorPulse = -g_nMotorPulse;   //测试下看看符不符合先
// 	__HAL_TIM_SET_COUNTER(&MOTOR1_TIM_ENCODER,0);//TIM4计数器清零
	
// 	g_nMotor2Pulse = (short)(__HAL_TIM_GET_COUNTER(&MOTOR2_TIM_ENCODER));//获取计数器值

// 	g_nMotor2Pulse = g_nMotor2Pulse;  //测试下看看符不符合先
//     //g_nMotor2Pulse = -g_nMotor2Pulse;  //测试下看看符不符合先
// 	//为什么只有在两个都取反之后，才能让两个串级PID有用？不然就会让位置环失效
// 	//暂时不要浪费时间去找原因,直接在内环（速度）的输出值那 数值取反 就好。
// 	__HAL_TIM_SET_COUNTER(&MOTOR2_TIM_ENCODER,0);//TIM2计数器清零

// 	g_lMotorPulseSigma += g_nMotorPulse;//位置外环使用的脉冲累积      //完成一次位置控制之后才清除。
// 	g_lMotor2PulseSigma += g_nMotor2Pulse;//位置外环使用的脉冲累积   //记录了之后也要及时清零呀！！！

// }