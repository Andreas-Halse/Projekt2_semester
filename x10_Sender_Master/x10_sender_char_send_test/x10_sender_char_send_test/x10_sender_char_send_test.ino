
#include <avr/io.h>
#include <avr/interrupt.h>

char array[] = { '0','1' };
char* ptr = array;

ISR(TIMER1_COMPA_vect); // prototype
ISR(TIMER3_OVF_vect);

ISR(TIMER3_OVF_vect)
{
	PORTB = 0x00; // dummy burst signal off
	TIMSK3 = 0x00; //disables overflow interrupt
}

int main(void)
{
	TCCR1B = 0b00001100;
	TCCR1A = 0x00;
	TCCR3B = 0x02;
	OCR1A = 624;
	TIMSK1 = 0x02;
	DDRB = 0xFF; // output port
	sei(); // enable interrupts
	for (;;)
	{

	}
}
ISR(TIMER1_COMPA_vect)
{
	if (*ptr == '0')
	{
		PORTB = 0x00;
		ptr++;
	}
	else if (*ptr == '1')
	{
		PORTB = 0xFF;
		ptr--;
	}
	TIMSK3 = 0x01;//overflow interrupt enable
	TCNT3 = 63536; // x-value sent to timer 3 for overflow after 1 ms
}