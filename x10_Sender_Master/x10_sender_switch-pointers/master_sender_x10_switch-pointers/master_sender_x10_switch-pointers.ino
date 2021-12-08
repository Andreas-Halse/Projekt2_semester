#include <avr/io.h>
#include <avr/interrupt.h>

char nextBitArray1[10] = { '1','1','1','1','1','1','1','1','1','1'};	// global array of bits that needs to be send to slaves 
char nextBitArray2[10] = { '1','1','1','1','1','1','1','1','0','0' };
char nextBitArray3[10] = { '0','0','0','0','0','0','0','0','0','0' };
volatile char* bit;														// global pointer to array of bits
char a = 'a';															// global char for switch case


ISR(TIMER1_COMPA_vect);													// ISR prototype
ISR(TIMER3_OVF_vect);													// ISR prototype
	
ISR(TIMER3_OVF_vect)
{
	PORTB = 0x00;														// dummy burst signal off
	TIMSK3 = 0x00;														// disables overflow interrupt for timer3
}

ISR(TIMER1_COMPA_vect)													// overflow from timer1
{
	if (*bit == '0')
	{
		PORTB = 0x00;													// if pointer points to 0 turn off all LEDS
		bit++;
	}
	else if (*bit == '1')
	{
		PORTB = 0xFF;													// if pointer points to 1 turn on all LEDS
		bit++;
	}
	else if (*bit == '\0')
	{
		PORTB = 0b11111100;												// else turn on all LEDS
		bit -= 10;
	}
	else
	{
		PORTB = 0b11110000;
	}
	TIMSK3 = 0x01;														// overflow interrupt enable
	TCNT3 = 63536;														// x-value sent to timer 3 for overflow after 1 ms

}

void switchFunction() {
	switch (PINA)
	{
	case 0b11111110:													// if case is 'k'
		TIMSK1 = 0x00;													// disable interrupt

		bit = nextBitArray1;

		TIFR1 |= 0b00000010;											// make sure reset flag is reset by writing a 1 to the TIFR flag
		TIMSK1 = 0x02;													// enable interrupt
		break;

	case 0b11111101:													// if case is 'f'
		TIMSK1 = 0x00;													// disable interrupt

		bit = nextBitArray2;

		TIFR1 |= 0b00000010;											// make sure reset flag is reset by writing a 1 to the TIFR flag
		TIMSK1 = 0x02;													// enable interrupt
		break;
			
	case 0b11111011:													// if case is 'h'
		TIMSK1 = 0x00;													// disable interrupt
		
		bit = nextBitArray3;

		TIFR1 |= 0b00000010;											// make sure reset flag is reset by writing a 1 to the TIFR flag
		TIMSK1 = 0x02;													// enable interrupt
		break;

	default:															// default case

		break;
	}
}

int main(void)
{
	DDRA = 0x00;														// set portA to input
	TCCR1B = 0b00001100;												// setup timer1
	TCCR1A = 0x00;														//
	TCCR3B = 0x02;														// setup timer3
	OCR1A = 624;
	TIMSK1 = 0x02;														// enable interrupts
	DDRB = 0xFF;														// set portB to output
	sei();																// enable global interrupts
	for (;;)
	{
		if (PINA != 0b11111111)
		{
			switchFunction();
		}
	}
}