///*
// Name:		X_10_communication.ino
// Created:	11/29/2021 8:33:56 AM
// Author:	oscar
//*/
//// the setup function runs once when you press reset or power the board
#include <avr/io.h>
#include <interrupt.h>
#define F_CPU 16000000
#define SIZE 8;
ISR(TIMER1_COMPA_vect);
ISR(TIMER3_OVF_vect);

int volatile mario_funhouse;
char nextMessage[SIZE];

int main()
{
	DDRK = 0x00; //data in pin pk7
	DDRB = 0xFF;
	TCCR3A = 0b00000000; // normal mode
	TCCR3B = 0x02; //prescaler of 8
	TCCR1B = 0b00001100; // 1100 means prescaler at 256 and sets to ctc
	OCR1A = 0x270; //sets the max value at 624 which means we get frequency=16000000/(	2*256*(1+624))=50
	TIMSK1 = 0x02; //enables compare match interrupt

	sei(); //enable intterupts
	for (;;)
	{

	}
}

ISR(TIMER3_OVF_vect)
{
	PORTK &= 0b01111111; // dummy burst signal off
	TIMSK3 = 0x00; //disables overflow interrupt
}

ISR(TIMER1_COMPA_vect)
{
	PORTB = 0xFF; //  dummy burst signal on
	TIMSK3 = 0x01;//overflow int enable
	TCNT3 = 63536; // x-value sent to timer 3 for overflow after 1 ms
}


void sendArray(char* arrayPtr)
{
	if(mario_funhouse<SIZE)
	{
	if (*arrayPtr == '1')
	{
		PORTK |= 0b10000000;
	}
	else
	{
		PORTK &= 0b01111111;
	}

	}
	TIMSK3 = 0x01;//overflow int enable
	TCNT3 = 63536; // x-value sent to timer 3 for overflow after 1 me
}