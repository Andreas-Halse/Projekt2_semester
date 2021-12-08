#include <avr/io.h>
#include <avr/interrupt.h>

char nextBitArray[101] = { '1' };
char* bit = nextBitArray;
char a = 'f';
ISR(TIMER1_COMPA_vect); // prototype
ISR(TIMER3_OVF_vect);

ISR(TIMER3_OVF_vect)
{
	PORTB = 0x00; // dummy burst signal off
	TIMSK3 = 0x00; //disables overflow interrupt
}

int main(void)
{
	DDRA = 0x00;
	TCCR1B = 0b00001100;
	TCCR1A = 0x00;
	TCCR3B = 0x02;
	OCR1A = 624;
	TIMSK1 = 0x02;
	DDRB = 0xFF; // output port
	sei(); // enable interrupts
	for (;;)
	{
		myfunction();
	}
}
ISR(TIMER1_COMPA_vect)
{
	if (*bit == '0')
	{
		PORTB = 0x00;
		bit++;
	}
	else if (*bit == '1')
	{
		PORTB = 0xFF;
		bit++;
	}
	else
	{
		PORTB = 0xFF;
	}
	TIMSK3 = 0x01;//overflow interrupt enable
	TCNT3 = 63536; // x-value sent to timer 3 for overflow after 1 ms
	
}

void myfunction() {
	switch (a)
	{
	case 'k':

		TIMSK1 = 0x00;
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
		TIFR1 |= 0b00000010;
		TIMSK1 = 0x02;

		break;



	case 'f':

		TIMSK1 = 0x00;
		bool y = true;
		for (int i = 0; i < 100; i++)
		{
			if (y)
			{
				nextBitArray[i] = '1';
			}
		}
		TIFR1 |= 0b00000010;
		TIMSK1 = 0x02;

		break;
	case 'h':
		PORTB = 0xFF;
		TIMSK1 = 0x00;
		for (int i = 0; i < 100; i++)
		{

			nextBitArray[i] = '1';

		}
		TIFR1 |= 0b00000010;
		TIMSK1 = 0x02;

		break;
	default:
		break;
	}
}