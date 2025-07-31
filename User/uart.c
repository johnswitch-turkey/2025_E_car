#include "uart.h"
#include "ti_msp_dl_config.h"

// 定义接收状态枚举
typedef enum {
    WAIT_COLON,    // 等待冒号':'
    WAIT_NUMBER,   // 等待数字
    WAIT_CR,       // 等待'\r'
    WAIT_LF        // 等待'\n'
} ReceiveState;

// 全局变量
static ReceiveState receive_state = WAIT_COLON;
static uint8_t received_number = 0;

void UART_TJC_INST_IRQHandler(void)
{
    uint8_t gData;
    switch (DL_UART_Main_getPendingInterrupt(UART_TJC_INST)) {
        case DL_UART_MAIN_IIDX_RX:
            gData = DL_UART_Main_receiveData(UART_TJC_INST);
            
            switch(receive_state)
            {
                case WAIT_COLON:
                    if(gData == ':')  // 检测到帧头冒号
                    {
                        receive_state = WAIT_NUMBER;
                    }
                    break;
                    
                case WAIT_NUMBER:
                    if(gData >= '0' && gData <= '9')  // 接收数字
                    {
                        received_number = gData - '0';
                        receive_state = WAIT_CR;
                    }
                    else
                    {
                        // 不是数字，重置状态
                        receive_state = WAIT_COLON;
                    }
                    break;
                    
                case WAIT_CR:
                    if(gData == '\r')  // 接收回车符
                    {
                        receive_state = WAIT_LF;
                    }
                    else
                    {
                        // 不符合协议，重置状态
                        receive_state = WAIT_COLON;
                    }
                    break;
                    
                case WAIT_LF:
                    if(gData == '\n')  // 接收换行符
                    {
                        // 完整接收到一个有效帧 ":1\r\n"
                        // 在这里处理接收到的数字 received_number
                        
                        // 示例：如果是1则执行某些操作
                        if(received_number == 1)
                        {
                            // 执行对应1的操作
                        }
                        
                        // 重置状态准备接收下一个帧
                        receive_state = WAIT_COLON;
                    }
                    else
                    {
                        // 不符合协议，重置状态
                        receive_state = WAIT_COLON;
                    }
                    break;
            }
            break;
            
        default:
            break;
    }
}