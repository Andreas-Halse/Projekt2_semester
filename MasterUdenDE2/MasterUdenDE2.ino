/*
 Name:		x10SenderOliverVersion.ino
 Created:	12/10/2021 12:43:30 PM
 Author:	Oliver V. Schousboe
*/
ISR(TIMER1_COMPA_vect);

//Der skal være en clock med en frekvens på 50hz 
//Hver gang clocken overflower skal man kunne sende 1 eller 0 (gøres med interrupt) 
//Bittet der skal sendes afgøres af et array som defineres globalt 
//Når output pin er sat og holdt i et ms flyttes pointeren 

char array1[] = "111010101";
char array2[] = "111101010";
char* bitPointer = nullptr;
int bitcounter = 0;
int twoMessagesSent = 0;
int countCrosses = 0;

ISR(TIMER1_COMPA_vect)
{
	if (twoMessagesSent == 2)
	{
		return;
	}
	else
	{
		switch (bitPointer[bitcounter])
		{
		case '1':
			//digitalWrite(49, HIGH);
			PORTL |= 0b00000001;
			bitcounter++;
			_delay_ms(5);
			PORTL &= 0b11111110;
			//digitalWrite(49, LOW);
			break;
		case '0':
			bitcounter++;
			break;
		case '\0':
			++countCrosses;
			if (countCrosses == 3)
			{
				bitcounter -= bitcounter;
				countCrosses = 0;
				twoMessagesSent++;
			}
			break;
		default:
			Serial.print("Went to default case!\n");
			break;
		}
	}
}


void initClock()
{
	//starter timer 1 med en frekvens på 50hz
	TCCR1B = 0b00001100;
	TCCR1A = 0x00;
	OCR1A = 624;
	//enabler interrupt på rising edge for clock 1
	TIMSK1 = 0x02;

	DDRL = 0xFF;
}

// the setup function runs once when you press reset or power the board
void setup() {
	sei(); // enable global interrupts
	Serial.begin(9600);
	initClock();
}

int incomingByte = 0;

// the loop function runs over and over again until power down or reset
void loop() {
	// send data only when you receive data:
	if (Serial.available() > 0) {
		// read the incoming byte:
		incomingByte = Serial.read();

		// say what you got:
		Serial.print("I received: ");
		Serial.println(incomingByte, DEC);
		if (incomingByte == 111)			// O
		{
			incomingByte = 0;
			twoMessagesSent = 0;
			bitPointer = array1;
		}
		if (incomingByte == 112)			// P
		{
			incomingByte = 0;
			twoMessagesSent = 0;
			bitPointer = array2;
		}
	}
}