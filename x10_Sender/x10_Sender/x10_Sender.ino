///*
// Name:		X_10_communication.ino
// Created:	11/29/2021 8:33:56 AM
// Author:	oscar
//*/
//// the setup function runs once when you press reset or power the board
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#define SIZE 8

bool bit = false;
int volatile mario_funhouse = 0;
char nextMessage[SIZE] = {'1','0','1','0','1','1','1','1'};
char* nextBitPtr = nextMessage;


ISR(TIMER1_COMPA_vect);
ISR(TIMER3_OVF_vect);

ISR(TIMER3_OVF_vect)
{
	PORTB = 0x00; // dummy burst signal off
	TIMSK3 = 0x00; //disables overflow interrupt
}

//Clock - triggers on rising edge
ISR(TIMER1_COMPA_vect)
{
	if(bit)
	{
		mario_funhouse++;
		PORTB |= (1 << mario_funhouse);; //  dummy burst signal on
		TIMSK3 = 0x01;//overflow interrupt enable
		TCNT3 = 63536; // x-value sent to timer 3 for overflow after 1 ms
		nextBitPtr++;
	}
	else
	{
		mario_funhouse++;
		PORTB |= (0 << mario_funhouse);; //  dummy burst signal on
		nextBitPtr++;
	}
}

void startAll()
{
	//set portb to output port
	DDRB = 0xFF;
	PORTB = 0x00;
	//initiate timer3 for 1ms burst
	TCCR3A = 0b00000000; // normal mode
	TCCR3B = 0x02; //prescaler of 8

	//initiate timer1 for clock
	TCCR1B = 0b00001100; // 1100 means prescaler at 256 and sets to ctc

	OCR1A = 0x270; //sets the max value at 624 which means we get frequency=16000000/(	2*256*(1+624))=50
	TIMSK1 = 0x02; //enables compare match interrupt
}


void checkBit(char* arrayPtr)
{
	if (*arrayPtr == '1')
	{
		bit = true;
	}
	if (*arrayPtr == '0')
	{
		bit = false;
	}
}


int main()
{
	sei(); //enable intterupts
	startAll();
	for (;;)
	{
		if (mario_funhouse <= 7 && mario_funhouse >= 0)
		{
			checkBit(nextBitPtr);
		}
		if (mario_funhouse == 8)
		{
			cli();
		}
	}
}
