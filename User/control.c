#include "control.h"
#include "ti_msp_dl_config.h"

#include "motor.h"

#include "pid.h"

#include "control_logic.h"
#include "grey_sensor.h"
#include "encoder.h"

volatile uint8_t spin_flag = 0; 
volatile uint8_t Line_flag = 0; 

// float g_fSpeedControlOut_X,g_fSpeedControlOutOld_X;//X方向速度环输出
// float g_fSpeedControlOut_Y,g_fSpeedControlOutOld_Y;//X方向速度环输出

uint16_t wait_time;

volatile uint8_t corner_count = 0; // 记录走过角落数

volatile uint8_t cur_circle = 0; // 记录走过圈数

ControlState current_state = GO_STRAIGHT;

uint32_t total_pulse_x = 0;
uint32_t total_pulse_y = 0;


float x_out_pwm = 0.0;
float y_out_pwm = 0.0;

void control(void){

	static uint16_t actual_speedX,actual_speedY;

	static float cont_val_X = 0.0, cont_val_Y = 0.0;                  // 当前X,Y方向控制值（位置环、速度环共用）
		
	Light_GoStraight_control();

	switch(current_state){
		case GO_STRAIGHT:
		if (cur_circle == tar_circle){
			Motor_Disable();
		}
					// actual_speedX = Get_Encoder_countA;
					// actual_speedY = Get_Encoder_countB;
					// set_pid_target(&pid_speedX, 1600+Line_Num);
					// set_pid_target(&pid_speedY, 1600-Line_Num);
					// cont_val_X = speed_pid_realize(&pid_speedX, actual_speedX*27);
					// cont_val_Y = speed_pid_realize(&pid_speedY, actual_speedY*27);
					// x_out_pwm = Limit_speed (&cont_val_X);
					// y_out_pwm = Limit_speed (&cont_val_Y);

					// Get_Encoder_countA = 0;
					// Get_Encoder_countB = 0;

				// Motor_SetSpeed((int32_t)x_out_pwm, (int32_t)y_out_pwm);
				Motor_SetSpeed(1600+Line_Num, 1600-Line_Num);
			break;
		case TURN_LEFT:
			Motor_SetSpeed(2300, 700);
			corner_count ++;
			if (corner_count == 4){
				corner_count = 0;
				cur_circle ++;
			}
			current_state = WAIT_TURN;
			break;

		case WAIT_TURN:
			wait_time++;
			if (wait_time == 100) {
				current_state = GO_STRAIGHT;
			}

		case TURN_RIGHT:
			corner_count ++;
			if (corner_count == 4){
				corner_count = 0;
				cur_circle ++;
			}
			//右转
			Motor_SetSpeed(900, 2100);
			current_state = WAIT_TURN;
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

