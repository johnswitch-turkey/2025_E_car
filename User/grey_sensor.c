#include "grey_sensor.h"

#include "ti_msp_dl_config.h"

#include "control.h"

//用来巡线的 '灰度传感器' 和 用来检测是否放上药品的 '红外传感器' 的代码都放在这个.c文件里了

uint8_t L3_Val,L2_Val, L1_Val, M_Val, R1_Val, R2_Val,R3_Val;
int Line_Num = 0;

SensorState sensor_state ;


/*******************灰度传感器巡线*************/
//只要把速度环控制好，补偿值即可确定。  不同速度值需要不同的补偿值。  测试好一个最好的。  不同的转速要对应不同的补偿系数或数值
void Light_GoStraight_control(void)   //灰度巡线直行, 需要有个判断需要直行多长距离的函数    //补偿要到中间的传感器测到回到线上为止
{
	  Get_Light_TTL();  
	  
	if(L3_Val == 0 && L2_Val == 0 && R3_Val == 1) {
		Line_Num = 75;  
		sensor_state = L3;
		current_state = TURN_LEFT;
	}  

	// if(L3_Val == 0 && L2_Val == 0 && L3_Val == 0) {
	// 	Line_Num = 75;  
	// 	sensor_state = L3;
	// 	current_state = TURN_LEFT;
	// }  
	else if (L3_Val == 0 && L2_Val == 0 && L1_Val == 1) {
		Line_Num = 70;
		sensor_state = L3_L2;
	} 
	else if (L3_Val == 1 && L2_Val == 0 && L1_Val == 1) {
		Line_Num =60 ;
		sensor_state = L2;
	
	} else if (L3_Val == 1 && L2_Val == 0 && L1_Val == 0 && M_Val == 1) {
		Line_Num = 50;
		sensor_state = L2_L1;	
	} else if (L2_Val == 1 && L1_Val == 0 && M_Val == 1) {
		Line_Num = 40;
		sensor_state = L1;  
	} else if (L2_Val == 1 && L1_Val == 0 && M_Val == 0 && R1_Val == 1) {
		Line_Num = 30;
		sensor_state = L1_M;   
	}else if (L1_Val == 1 && M_Val == 0 && R1_Val == 1) {
		Line_Num = 0;
		sensor_state = M;   
		
	} else if (L1_Val == 1 && M_Val == 0 && R1_Val == 0 && R2_Val == 1) {
		Line_Num = -30;
		sensor_state = M_R1;   
	} else if ( M_Val == 1 && R1_Val == 0&& R2_Val == 1) {
		Line_Num = -40;
		sensor_state = R1; 
	} else if (M_Val == 1 && R1_Val == 0 && R2_Val == 0 && R3_Val == 1 ) {
		Line_Num = -50;
		sensor_state = R1_R2; 
	} else if (R1_Val == 1 && R2_Val == 0 && R3_Val == 1 ) {
		Line_Num = -60;
		sensor_state = R2;
	} 
	// else if ( R3_Val == 1 && R2_Val == 0 && R3_Val == 0) {
	// 	Line_Num = -70;
	// 	sensor_state = R2_R3;  
	// }  
	else if( R3_Val == 0 && R2_Val == 0 && L3_Val == 1) {
		Line_Num = -75;
		sensor_state = R3;  
		current_state = TURN_RIGHT;
	}
// 	else if( R3_Val == 0 && R2_Val == 0 && R1_Val == 0) {
// 		Line_Num = -75;
// 		sensor_state = R3;  
// 		current_state = TURN_RIGHT;
// 	}
// }

}

//把灰度传感器当作只输出高低电平。 高电平是识别到红线了。
void Get_Light_TTL(void)
{	
    if (!DL_GPIO_readPins(GPIO_GREY_SENSOR_L3_PORT,GPIO_GREY_SENSOR_L3_PIN)) {L3_Val = 1;} else {L3_Val = 0;}
    if (!DL_GPIO_readPins(GPIO_GREY_SENSOR_L2_PORT,GPIO_GREY_SENSOR_L2_PIN)) {L2_Val = 1;} else {L2_Val = 0;}
    if (!DL_GPIO_readPins(GPIO_GREY_SENSOR_L1_PORT,GPIO_GREY_SENSOR_L1_PIN)) {L1_Val = 1;} else {L1_Val = 0;}
    if (!DL_GPIO_readPins(GPIO_GREY_SENSOR_M_PORT,GPIO_GREY_SENSOR_M_PIN)) {M_Val = 1;} else {M_Val = 0;}
    if (!DL_GPIO_readPins(GPIO_GREY_SENSOR_R1_PORT,GPIO_GREY_SENSOR_R1_PIN)) {R1_Val = 1;} else {R1_Val = 0;}
    if (!DL_GPIO_readPins(GPIO_GREY_SENSOR_R2_PORT,GPIO_GREY_SENSOR_R2_PIN)) {R2_Val = 1;} else {R2_Val = 0;}
    if (!DL_GPIO_readPins(GPIO_GREY_SENSOR_R3_PORT,GPIO_GREY_SENSOR_R3_PIN)) {R3_Val = 1;} else {R3_Val = 0;}

// if(HAL_GPIO_ReadPin(L3_GPIO_Port, L3_Pin) == GPIO_PIN_SET){L3_Val = 1;} else {L3_Val = 0;}
// 	if(HAL_GPIO_ReadPin(L2_GPIO_Port, L2_Pin) == GPIO_PIN_SET){L2_Val = 1;} else {L2_Val = 0;}
// 	if(HAL_GPIO_ReadPin(L1_GPIO_Port, L1_Pin) == GPIO_PIN_SET){L1_Val = 1;} else {L1_Val = 0;}
// 	if(HAL_GPIO_ReadPin(M_GPIO_Port, M_Pin) == GPIO_PIN_SET)  {M_Val = 1;} else {M_Val = 0;}
// 	if(HAL_GPIO_ReadPin(R1_GPIO_Port, R1_Pin) == GPIO_PIN_SET){R1_Val = 1;} else {R1_Val = 0;}
// 	if(HAL_GPIO_ReadPin(R2_GPIO_Port, R2_Pin) == GPIO_PIN_SET){R2_Val = 1;} else {R2_Val = 0;}
// 	if(HAL_GPIO_ReadPin(R3_GPIO_Port, R3_Pin) == GPIO_PIN_SET){R3_Val = 1;} else {R3_Val = 0;}
}




