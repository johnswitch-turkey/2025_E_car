#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "ti_msp_dl_config.h"

#define Exti_IRQHandler     GROUP1_IRQHandler

typedef enum {
    FORWARD,  // 正向
    REVERSAL  // 反向
} ENCODER_DIR;

typedef struct {
    volatile long long temp_count;      //保存实时计数值
    int count;                          //根据定时器时间更新的计数值
    ENCODER_DIR dir;                    //旋转方向
} ENCODER_RES;


static ENCODER_RES left_motor_encoder;
static ENCODER_RES right_motor_encoder;

void encoder_init(void);
int get_left_encoder(void);
int get_right_encoder(void);
void encoder_update_continue(void);
void encoder_update_repeat(void);

#endif
