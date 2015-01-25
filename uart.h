/*
 * uart.h
 *
 * Created: 1/25/2015 12:38:34 PM
 *  Author: mohamed
 */ 


#ifndef UART_H_
#define UART_H_
#include "micro_config.h"


void UART_init( );
void UART_sendByte( uint8 data );
uint8 UART_receiveByte(  );
void UART_sendString(const char *Str);
void UART_receiveString(char *Str);



#endif /* UART_H_ */