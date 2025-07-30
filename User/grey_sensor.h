#ifndef __GRAY_SENSOR_H
#define __GRAY_SENSOR_H
#include "ti_msp_dl_config.h"

extern uint8_t L2_Val, L1_Val, M_Val, R1_Val, R2_Val,L3_Val, R3_Val;

extern int Line_Num;



typedef enum {
    L3,
    L3_L2,
    L2,
    L2_L1,
    L1,
    L1_M,
    M,
    M_R1,
    R1,
    R1_R2,
    R2,
    R2_R3,
    R3
}SensorState;

extern SensorState sensor_state;

void Get_Light_TTL(void);
void Light_GoStraight_control(void);


#endif