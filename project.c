/*
 * project.c
 *
 * Created: 1/25/2015 12:18:48 PM
 *  Author: mohamed
 */ 

#include "uart.h"

int main(void)
{
	char Str[20];
	char data;
	UART_init();
	while(1)
	{
		//data = UART_recieveByte(); //Receive Byte from Terminal1
		//UART_sendByte(data); //Resend the received byte to Terminal2
		UART_receiveString(Str); //Receive String from Terminal
		UART_sendString(Str); //Resend the string to Terminal2
	}
}