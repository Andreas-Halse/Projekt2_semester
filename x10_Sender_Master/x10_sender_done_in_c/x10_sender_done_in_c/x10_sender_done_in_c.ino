#include <avr/io.h>
#include <avr/interrupt.h>

char nextBitArray[101] = { '1' };	// global array of bits that needs to be send to slaves 
char* bit = nextBitArray;			// global pointer to array of bits
char a = 'f';						// global char for switch case

ISR(TIMER1_COMPA_vect);				// ISR prototype
ISR(TIMER3_OVF_vect);				// ISR prototype

ISR(TIMER3_OVF_vect)
{
	PORTB = 0x00;					// dummy burst signal off
	TIMSK3 = 0x00;					// disables overflow interrupt for timer3
}

ISR(TIMER1_COMPA_vect)				// overflow from timer1
{
	if (*bit == '0')
	{
		PORTB = 0x00;				// if pointer points to 0 turn off all LEDS
		bit++;
	}
	else if (*bit == '1')
	{
		PORTB = 0xFF;				// if pointer points to 1 turn on all LEDS
		bit++;
	}
	else
	{
		PORTB = 0xFF;				// else turn on all LEDS
	}
	TIMSK3 = 0x01;					// overflow interrupt enable
	TCNT3 = 63536;					// x-value sent to timer 3 for overflow after 1 ms

}

int main(void)
{
	DDRA = 0x00;					// set portA to input
	TCCR1B = 0b00001100;			// setup timer1
	TCCR1A = 0x00;					//
	TCCR3B = 0x02;					// setup timer3
	OCR1A = 624;			
	TIMSK1 = 0x02;					// enable interrupts
	DDRB = 0xFF;					// set portB to output
	sei();							// enable global interrupts
	for (;;)
	{
		myfunction();
	}
}

void myfunction() {
	switch (a)
	{
	case 'k':						// if case is 'k'
		TIMSK1 = 0x00;				// disable interrupt
		bool x = true;
		for (int i = 0; i < 100; i++)
		{
			if (x)
			{
				x = false;
				nextBitArray[i] = '1';
			}
			else
			{
				x = true;
				nextBitArray[i] = '0';
			}
		}
		TIFR1 |= 0b00000010;		// make sure reset flag is reset by writing a 1 to the TIFR flag
		TIMSK1 = 0x02;				// enable interrupt
	break;

	case 'f':						// if case is 'f'
		TIMSK1 = 0x00;				// disable interrupt
		for (int i = 0; i < 100; i++)
		{

			nextBitArray[i] = '0';
		}
		TIFR1 |= 0b00000010;		// make sure reset flag is reset by writing a 1 to the TIFR flag
		TIMSK1 = 0x02;				// enable interrupt
	break;

	case 'h':						// if case is 'h'
		TIMSK1 = 0x00;				// disable interrupt
		for (int i = 0; i < 100; i++)
		{
			nextBitArray[i] = '1';	
		}
		TIFR1 |= 0b00000010;		// make sure reset flag is reset by writing a 1 to the TIFR flag
		TIMSK1 = 0x02;				// enable interrupt
	break;

	default:						// default case

	break;
	}
}