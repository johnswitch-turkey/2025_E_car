
#include "encoder.h"


#include "ti_msp_dl_config.h"


static volatile uint32_t gpio_interrup;
static ENCODER_RES left_motor_encoder;
static ENCODER_RES right_motor_encoder;

int32_t x_pulse = 0;
int32_t y_pulse = 0;

/*******************************************************
函数功能：外部中断模拟编码器信号
入口函数：无
返回  值：无
***********************************************************/
void Exti_IRQHandler(void)
{
	//获取中断信号
	gpio_interrup = DL_GPIO_getEnabledInterruptStatus(GPIO_ENCODER_PORT, GPIO_ENCODER_PIN_LA_PIN | GPIO_ENCODER_PIN_RA_PIN );
	//encoder LA
	if((gpio_interrup & GPIO_ENCODER_PIN_LA_PIN)==GPIO_ENCODER_PIN_LA_PIN)
	{
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_LB_PIN))
		{
			x_pulse++;
			left_motor_encoder.temp_count++;
		}
		else
		{
			x_pulse--;
			left_motor_encoder.temp_count--;
		}
	}
	//encoder RA
	if((gpio_interrup & GPIO_ENCODER_PIN_RA_PIN)==GPIO_ENCODER_PIN_RA_PIN)
	{
		if(!DL_GPIO_readPins(GPIO_ENCODER_PORT,GPIO_ENCODER_PIN_RB_PIN))
		{
			y_pulse ++;
			right_motor_encoder.temp_count--;
		}
		else
		{
			y_pulse--;
			right_motor_encoder.temp_count++;
		}
	}

	//清除状态
	DL_GPIO_clearInterruptStatus(GPIOA,GPIO_ENCODER_PIN_LA_PIN|GPIO_ENCODER_PIN_RA_PIN);
}