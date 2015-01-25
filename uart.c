/*
 * uart.c
 *
 * Created: 1/25/2015 12:14:07 PM
 *  Author: mohamed
 */ 

#include "uart.h"
void UART_init( unsigned int ubrr)
{
	/* Set baud rate */
	UBRRH = 0 ;
	UBRRL = 12 ;
	/* Enable receiver and transmitter */
	UCSRA |=(1<<U2X);
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}
/*********************************************************************************************/
void UART_sendByte( uint8 data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )	;
	/* Put data into buffer, sends the data */
	UDR = data;
}

/**************************************************************************************************/

uint8 UART_receiveByte(  )

{	
	while ( !(UCSRA & (1<<RXC)) )	;
	
	return UDR ;
	
}

/*****************************************************************************************************/
void UART_sendString(const char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}

void UART_receiveString(char *Str)
{
	uint8 i = 0;
	Str[i] = UART_receiveByte();
	while(Str[i] != '\r')
	{
		i++;
		Str[i] = UART_receiveByte();
	}
	Str[i] = '\0';
}