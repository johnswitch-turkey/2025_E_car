#include "control.h"
#include "ti_msp_dl_config.h"

#include "motor.h"

#include "pid.h"

#include "control_logic.h"
#include "grey_sensor.h"
#include "encoder.h"

volatile uint8_t spin_flag = 0; 
volatile uint8_t Line_flag = 0; 

float g_fSpeedControlOut_X,g_fSpeedControlOutOld_X;//X方向速度环输出
float g_fSpeedControlOut_Y,g_fSpeedControlOutOld_Y;//X方向速度环输出



uint16_t corner_count;

ControlState current_state = GO_STRAIGHT;



float x_out_pwm = 0.0;
float y_out_pwm = 0.0;

void control(void){

	static int actual_speedX,actual_speedY;

	static float cont_val_X = 0.0, cont_val_Y = 0.0;                  // 当前X,Y方向控制值（位置环、速度环共用）
		
	Light_GoStraight_control();

	switch(current_state){
		case GO_STRAIGHT:

					actual_speedX = Get_Encoder_countA;
					actual_speedY = Get_Encoder_countB;
					// set_pid_target(&pid_speedX, 400+Line_Num);
					// set_pid_target(&pid_speedY, 400-Line_Num);
					// cont_val_X = speed_pid_realize(&pid_speedX, actual_speedX);
					// cont_val_Y = speed_pid_realize(&pid_speedY, actual_speedY);
					// x_out_pwm = Limit_speed (&cont_val_X);
					// y_out_pwm = Limit_speed (&cont_val_Y);

					Get_Encoder_countA = 0;
					Get_Encoder_countB = 0;

				// Motor_SetSpeed(x_out_pwm, y_out_pwm);
			break;
		case TURN_LEFT:
			switch (sensor_state){

				case L3: 
					Motor_SetSpeed(500, 500); 
					break;
				case L3_L2: 
					Motor_SetSpeed(500, 500);
					break;
				case L2: 
					Motor_SetSpeed(500, 500);
					break;
				case L2_L1: 
					Motor_SetSpeed(500, 500);
					break;
				case L1: 
					Motor_SetSpeed(500, 500);
					break;
				case L1_M: 
					Motor_SetSpeed(500, 500);
					break;
				case M: 
					current_state = GO_STRAIGHT;

					break;
				case M_R1:
					Motor_SetSpeed(500, 500);
					break;
				case R1:
				case R1_R2:
				case R2:
				case R2_R3:
				case R3:
				break;
			}

			
			break;
		case TURN_RIGHT:
			//右转
			Motor_SetSpeed(500, 300);
			break;
		case STOP:
			//停止
			// Motor_SetSpeed(0, 0);
			break;
		default:
			break;
	}

}


// void SpeedControlOutput(void)    //平滑输出，将一次速度环控制拆分为三次输出，每次两个10ms周期的PWM
// {
// 	float fValue_X,fValue_Y;
// 	fValue_X = x_speed - g_fSpeedControlOutOld_X ;//速度计算量差值=本次速度计算量-上次速度计算量
// 	g_fSpeedControlOut_X = (fValue_X * (g_nSpeedControlPeriod + 1) / SPEED_CONTROL_PERIOD + g_fSpeedControlOutOld_X);//x方向速度计算量差值
	
// 	fValue_Y = y_speed - g_fSpeedControlOutOld_Y ;//速度计算量差值=本次速度计算量-上次速度计算量
// 	g_fSpeedControlOut_Y = (fValue_Y * (g_nSpeedControlPeriod + 1) / SPEED_CONTROL_PERIOD + g_fSpeedControlOutOld_Y);//Y方向速度计算量差值
// }

