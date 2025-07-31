#include "uart.h"
#include "ti_msp_dl_config.h"



#include <stdio.h>
#include <string.h>

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






// 发送单个字符的函数
int fputc(int c, FILE* stream)
{
    // 调用DL_UART_Main_transmitDataBlocking函数，将字符c通过UART_0_INST发送出去
    DL_UART_Main_transmitDataBlocking(UART_CV_INST, c);
    // 返回字符c
    return c;
}

// 发送字符串的函数
int fputs(const char* restrict s, FILE* restrict stream)
{
    // 定义变量i和len，分别用于循环和存储字符串s的长度
    uint16_t i, len;
    // 获取字符串s的长度
    len = strlen(s);
    // 循环遍历字符串s的每个字符
    for(i=0; i<len; i++)
    {
        // 将字符串s的每个字符通过UART_0_INST发送出去
        DL_UART_Main_transmitDataBlocking(UART_CV_INST, s[i]);
    }
    // 返回写入的字符数
    return len;
}

// 发送字符串并添加换行符的函数
int puts(const char *_ptr)
{
    // 使用fputs函数将字符串输出到标准输出流
    int count = fputs(_ptr, stdout);
    // 使用fputs函数将换行符输出到标准输出流
    count += fputs("\n", stdout);
    // 返回输出字符的个数
    return count;
}

// 简化的字符串发送函数
void send_string(const char* str)
{
    // 直接调用fputs函数发送字符串
    fputs(str, stdout);
}


