#ifndef _UART_H_
#define _UART_H_

#include "ti_msp_dl_config.h"

extern int16_t cy ;
extern int16_t cx ;

// void send_string(const char* str);

void send_string(const void* buffer);

#endif