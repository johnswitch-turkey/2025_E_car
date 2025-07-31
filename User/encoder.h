#ifndef _ENCODER_H
#define _ENCODER_H
#include "ti_msp_dl_config.h"


extern int Get_Encoder_countA,Get_Encoder_countB;

extern volatile uint8_t tar_circle;

// 定义长按和短按的时间阈值（单位：毫秒）
#define LONG_PRESS_THRESHOLD_MS 5000
#define SHORT_PRESS_THRESHOLD_MS 50

// 定义按键状态
typedef enum {
    BUTTON_RELEASED,
    BUTTON_PRESSED,
    BUTTON_LONG_PRESSED
} ButtonState;


extern volatile ButtonState buttonState;
extern volatile uint32_t pressDurationMs;

#endif










// #ifndef _ENCODER_H_
// #define _ENCODER_H_

// #include "ti_msp_dl_config.h"

// #define Exti_IRQHandler     GROUP1_IRQHandler

// typedef enum {
//     FORWARD,  // 正向
//     REVERSAL  // 反向
// } ENCODER_DIR;

// typedef struct {
//     volatile long long temp_count;      //保存实时计数值
//     int count;                          //根据定时器时间更新的计数值
//     ENCODER_DIR dir;                    //旋转方向
// } ENCODER_RES;


// extern ENCODER_RES left_motor_encoder;
// extern ENCODER_RES right_motor_encoder;

// void encoder_init(void);
// int get_left_encoder(void);
// int get_right_encoder(void);
// void encoder_update_continue(void);
// void encoder_update_repeat(void);

// #endif
