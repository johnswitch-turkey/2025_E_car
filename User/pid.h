#ifndef __PID_H
#define __PID_H


#include "ti_msp_dl_config.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//这两个可以定义为 宏定义
#define sampleTime  0.01f  // 采样时间  10ms 这个函数是每10ms调用一次？需要相应修改，
#define sampleFreq  100.0f  // 采样频率  100Hz 这个函数是每10ms调用一次？需要相应修改

typedef struct
{
    float target_val;               //目标值
    float actual_val;        		//实际值
    float err;             			//定义偏差值
    float err_last;          		//定义上一个偏差值
    float errDeri;          		//定义 两个误差的差值
    float Kp, Ki, Kd;          		//定义比例、积分、微分系数
    float integral;          		//定义积分值
}_pid;

extern _pid pid_positionX, pid_positionY, pid_speedX, pid_speedY;

extern void PID_param_init(void);

extern void set_pid_target(_pid* pid, float temp_val);
extern float get_pid_target(_pid* pid);

extern void set_p_i_d(_pid* pid, float p, float i, float d);

extern float location_pid_realize(_pid* pid, float actual_val);
extern float speed_pid_realize(_pid* pid, float actual_val);


#endif
