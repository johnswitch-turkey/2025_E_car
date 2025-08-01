#ifndef CONTROL_H
#define CONTROL_H
#include "ti_msp_dl_config.h"

#define SPEED_CONTROL_PERIOD 3 //速度环控制周期

extern volatile uint8_t spin_flag ; //用于判断是否需要转弯
extern volatile uint8_t Line_flag ; //用于判断是否需要巡线

extern long long x;

typedef enum {
	GO_STRAIGHT,
	TURN_LEFT,
	WAIT_TURN,
	TURN_RIGHT,
	STOP
} ControlState;

void SpeedControlOutput(void);

void control(void);

extern ControlState current_state;

#endif
