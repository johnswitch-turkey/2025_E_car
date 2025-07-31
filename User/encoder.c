#include "encoder.h"
uint32_t gpio_interrup1,gpio_interrup2;
int Get_Encoder_countA,Get_Encoder_countB;
/*******************************************************
函数功能：外部中断模拟编码器信号
入口函数：无
返回  值：无
***********************************************************/
void GROUP1_IRQHandler(void)
{
	//获取中断信号
    gpio_interrup1 = DL_GPIO_getEnabledInterruptStatus(ENCODERA_PORT,ENCODERA_E1A_PIN|ENCODERA_E1B_PIN);
    gpio_interrup2 = DL_GPIO_getEnabledInterruptStatus(ENCODERB_PORT,ENCODERB_E2A_PIN|ENCODERB_E2B_PIN);
    
    
	//encoderB
	if((gpio_interrup1 & ENCODERA_E1A_PIN)==ENCODERA_E1A_PIN)
	{
		if(!DL_GPIO_readPins(ENCODERA_PORT,ENCODERA_E1B_PIN))
		{
			Get_Encoder_countA++;
		}
		else
		{
			Get_Encoder_countA--;
		}
	}
	else if((gpio_interrup1 & ENCODERA_E1B_PIN)==ENCODERA_E1B_PIN)
	{
		if(!DL_GPIO_readPins(ENCODERA_PORT,ENCODERA_E1A_PIN))
		{
			Get_Encoder_countA--;
		}
		else
		{
			Get_Encoder_countA++;
		}
	}
	
	//encoderA
	if((gpio_interrup2 & ENCODERB_E2A_PIN)==ENCODERB_E2A_PIN)
	{
		if(!DL_GPIO_readPins(ENCODERB_PORT,ENCODERB_E2B_PIN))
		{
			Get_Encoder_countB--;
		}
		else
		{
			Get_Encoder_countB++;
		}
	}
	else if((gpio_interrup2 & ENCODERB_E2B_PIN)==ENCODERB_E2B_PIN)
	{
		if(!DL_GPIO_readPins(ENCODERB_PORT,ENCODERB_E2A_PIN))
		{
			Get_Encoder_countB++;
		}                 
		else              
		{                 
			Get_Encoder_countB--;
		}
	}
	DL_GPIO_clearInterruptStatus(ENCODERA_PORT,ENCODERA_E1A_PIN|ENCODERA_E1B_PIN);
	DL_GPIO_clearInterruptStatus(ENCODERB_PORT,ENCODERB_E2A_PIN|ENCODERB_E2B_PIN);
}











































// #include "encoder.h"


// #include "ti_msp_dl_config.h"


// static volatile uint32_t gpio_interrup;
// ENCODER_RES left_motor_encoder;
// ENCODER_RES right_motor_encoder;

// int32_t x_pulse = 0;
// int32_t y_pulse = 0;

// /*******************************************************
// 函数功能：外部中断模拟编码器信号
// 入口函数：无
// 返回  值：无
// ***********************************************************/
// void Exti_IRQHandler(void)
// {
// 	//获取中断信号
// 	gpio_interrup = DL_GPIO_getEnabledInterruptStatus(GPIO_ENCODER_PORT, GPIO_ENCODER_PIN_LA_PIN | GPIO_ENCODER_PIN_RA_PIN );
// 	//encoder LA
// 	if((gpio_interrup & GPIO_ENCODER_PIN_LA_PIN)==GPIO_ENCODER_PIN_LA_PIN)
// 	{
// 		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_LB_PIN))
// 		{
// 			x_pulse++;
// 			left_motor_encoder.temp_count++;
// 		}
// 		else
// 		{
// 			x_pulse--;
// 			left_motor_encoder.temp_count--;
// 		}
// 	}
// 	//encoder RA
// 	if((gpio_interrup & GPIO_ENCODER_PIN_RA_PIN)==GPIO_ENCODER_PIN_RA_PIN)
// 	{
// 		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_RB_PIN))
// 		{
// 			y_pulse --;
// 			right_motor_encoder.temp_count--;
// 		}
// 		else
// 		{
// 			y_pulse++;
// 			right_motor_encoder.temp_count++;
// 		}
// 	}

// 	//清除状态
// 	DL_GPIO_clearInterruptStatus(GPIOA,GPIO_ENCODER_PIN_LA_PIN|GPIO_ENCODER_PIN_RA_PIN);
// }