#include "uart.h"
unsigned char string_buffer[100]="learn-in-depth:Abdallah";
unsigned char const string_buffer2[100]="learn-in-depth:Abdallah";
void main(void)
{
	Uart_sent_string(string_buffer);
}