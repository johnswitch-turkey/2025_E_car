#include "uart.h"

#include "ti_msp_dl_config.h"


// 定义接收状态枚举
typedef enum {
    WAIT_HEADER,   // 等待帧头 ':'
    RECEIVE_X,     // 接收X坐标
    RECEIVE_Y,     // 接收Y坐标
    RECEIVE_NUM    // 接收数字编号
} ReceiveState;

// 全局变量
static ReceiveState receive_state = WAIT_HEADER;
static int16_t rx_x = 0;      // X坐标临时存储
static int16_t rx_y = 0;      // Y坐标临时存储
static uint8_t rx_num = 0;    // 数字编号临时存储
static bool x_negative = false; // X是否为负数
static bool y_negative = false; // Y是否为负数
int16_t cy =0;
int16_t cx =0;

void UART_OPENCV_INST_IRQHandler(void)
{
    uint8_t gData;
    switch (DL_UART_Main_getPendingInterrupt(UART_OPENCV_INST)) {
        case DL_UART_MAIN_IIDX_RX:
            gData = DL_UART_Main_receiveData(UART_OPENCV_INST);
            
            if(gData == 'S')  // 紧急停止命令
            {

            }
            else
            {
                switch(receive_state)
                {
                    case WAIT_HEADER:
                        if(gData == ':')  // 检测到帧头
                        {
                            receive_state = RECEIVE_X;
                            rx_x = 0;
                            x_negative = false;
                        }
                        break;
                        
                    case RECEIVE_X:
                        if(gData == ',')  // X坐标接收完成
                        {
                            receive_state = RECEIVE_Y;
                            rx_y = 0;
                            y_negative = false;
                        }
                        else if(gData == '-')  // 负号
                        {
                            x_negative = true;
                        }
                        else if(gData >= '0' && gData <= '9')  // 数字
                        {
                            rx_x = rx_x * 10 + (gData - '0');
                        }
                        break;
                        
                    case RECEIVE_Y:
                        if(gData == ',')  // Y坐标接收完成
                        {
                            receive_state = RECEIVE_NUM;
                            rx_num = 0;
                        }
                        else if(gData == '-')  // 负号
                        {
                            y_negative = true;
                        }
                        else if(gData >= '0' && gData <= '9')  // 数字
                        {
                            rx_y = rx_y * 10 + (gData - '0');
                        }
                        break;
                        
                    case RECEIVE_NUM:
                        if(gData == '#')  // 帧尾
                        {
                            // 处理符号
                            if(x_negative) rx_x = -rx_x;
                            if(y_negative) rx_y = -rx_y;
                            
                            // 存储到全局变量
                            cx = rx_x;
                            cy = rx_y;

                            
                            // 重置状态
                            receive_state = WAIT_HEADER;
                        }
                        else if(gData >= '0' && gData <= '9')  // 数字编号
                        {
                            rx_num = gData - '0';
                        }
                        break;
                }
            }
            break;
            
        default:
            break;
    }
}
