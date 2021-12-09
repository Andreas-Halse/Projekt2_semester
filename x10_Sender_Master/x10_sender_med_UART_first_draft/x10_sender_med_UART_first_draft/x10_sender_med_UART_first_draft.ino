#include <avr/io.h>
#include <avr/interrupt.h>
#define SIZE 12

char nextBitArray1[SIZE] = { '1','1','0','1','1','0','1','1','0','0','0', '0'};	// global array of bits that needs to be send to slaves 
char nextBitArray2[SIZE] = { '1','1','1','1','1','1','1','1','1','0','0', '0'};
char nextBitArray3[SIZE] = { '1','0','1','0','1','0','1','1','0','0','0', '0'};
volatile char* bit;														// global pointer to array of bits
int incomingChar;// global char for switch case
int zeroCounter = 3;

volatile bool stopReached = true;
volatile bool intReached = true;
volatile bool sentTwice = false;

ISR(TIMER1_COMPA_vect);													// ISR prototype
ISR(TIMER3_OVF_vect);													// ISR prototype

ISR(TIMER3_OVF_vect)
{
	digitalWrite(11, LOW);														// dummy burst signal off
	TIMSK3 = 0x00;														// disables overflow interrupt for timer3
}

ISR(TIMER1_COMPA_vect)													// overflow from timer1
{




	if (zeroCounter > 2)
	{
		
		if (!( * bit == '0' || *bit == '1')||*bit=='\n')
		{
			Serial.print(*bit);
		
			return;
		}
		
		
		if (!stopReached)
		{
			if ((*(bit - 3)) == 1)//tjekker at den sidste sendte databit er 1, for ikke at bruge 10'et fra machester enkrypteringen, som en del af stop'bitsne
			{
				Serial.print("pointeren er:  ");
				Serial.print(*bit);
				Serial.print("\n");
				digitalWrite(11, LOW);			
				bit++;
			}

			if (sentTwice)
			{
					stopReached = true;
					sentTwice = false;
					zeroCounter = 3;


			}
			else
			{

				Serial.print("\n\nsending twice\n\n");
				bit -= (SIZE - 1);
				sentTwice = true;
				zeroCounter = 0;
			}
			
			
		}

		return;
		
	}
	Serial.print("pointeren er:  ");
	Serial.print(*bit);
	Serial.print("\n");
	intReached = true;
	if (*bit == '0')
	{
		Serial.print("test1\n");

		digitalWrite(11, LOW);													// if pointer points to 0 turn off all LEDS
		bit++;
		zeroCounter++;


	}
	else if (*bit == '1')
	{
		Serial.print("test2\n");
		digitalWrite(11, HIGH);													// if pointer points to 1 turn on all LEDS
		bit++;
		zeroCounter = 0;

	}
	else
	{
		Serial.print("hello\n");

		PORTB = 0b11110000;
	}
	TIMSK3 = 0x01;														// overflow interrupt enable
	TCNT3 = 63536;														// x-value sent to timer 3 for overflow after 1 ms

}

void switchFunction() {
	stopReached = false;// soerger for switchFunction ikke kaldes igen foer kommandoen er udfoert
	zeroCounter = 0;
	int x = bit;
	Serial.println(x);
	switch (incomingChar)
	{
	case 49:	// if case is 'k'

		TIMSK1 = 0x00;													// disable interrupt timer1

		intReached = false;
		zeroCounter = 0;

		bit = nextBitArray1;											// change global pointer placement

		TIFR1 |= 0b00000010;											// make sure reset flag is reset by writing a 1 to the TIFR flag
		TIMSK1 = 0x02;					// enable interrupt
		break;

	case 50:													// if case is 'f'
		intReached = false;

		TIMSK1 = 0x00;													// disable interrupt timer1

		zeroCounter = 0;
		bit = nextBitArray2;											// change global pointer placement

		TIFR1 |= 0b00000010;											// make sure reset flag is reset by writing a 1 to the TIFR flag
		TIMSK1 = 0x02;													// enable interrupt
		break;

	case 51:													// if case is 'h'
		intReached = false;
		TIMSK1 = 0x00;													// disable interrupt timer1
		zeroCounter = 0;

		bit = nextBitArray3;											// change global pointer placement

		TIFR1 |= 0b00000010;											// make sure reset flag is reset by writing a 1 to the TIFR flag
		TIMSK1 = 0x02;													// enable interrupt
		break;

	default:															// default case

		break;
	}
}


void setup()
{
	Serial.begin(9600);
	pinMode(11, OUTPUT);
	TCCR1B = 0b00001100;												// setup timer1
	TCCR1A = 0x00;														//
	TCCR3B = 0x02;														// setup timer3
	OCR1A = 624;														// make timer start at 624
	TIMSK1 = 0x02;														// enable interrupts
	DDRB = 0xFF;														// set portB to output
	sei();																// enable global interrupts
}

void loop()
{
	if ((intReached && stopReached)&&(Serial.available()>0))
	{

		Serial.print("command recieved");
		cli();
		incomingChar = Serial.read();//loader char'en ind i incomingChar til switch casen.
		Serial.print("I received: ");
		Serial.println(incomingChar);

		switchFunction();
		sei();
	}

}