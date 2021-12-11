/*
 Name:		First_draft.ino
 Created:	12/8/2021 1:02:37 PM
 Author:	oliver
*/
#define F_CPU 16000000

int incomingByte = 0; // for incoming serial data
char bitArray[] = { '1','0','1','0' };
volatile int ptrCounter;

void sendBitAndMovePointer(char array[], int ptrCount)
{
    if (array[ptrCount] == '1')
    {
        digitalWrite(11, HIGH);
    }
    if (array[ptrCount] == '0')
    {
        digitalWrite(11, LOW);
    }
    if (array[ptrCount] == '\0')
    {
        //disable timer interrupt if array is done;
        cli();
        return;
    }
    //start timer for 1 second
    //wait for timer overflow and end -- do in new function
}


ISR(TIMER1_COMPA_vect);

ISR(TIMER1_COMPA_vect)
{
    sendBitAndMovePointer(bitArray,ptrCounter);
    ptrCounter++;
}

void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps - bits pr secodns

    DDRA = 0xFF;
    TCCR1B = 0b00001100;												// setup timer1
    TCCR1A = 0x00;														//
    OCR1A = 624;														// make timer start at 624
    TIMSK1 = 0x02;   																// enable global interrupts
}

void loop() {
    // read and send (print) data only when you're receive data:
    if (Serial.available() > 0) {
        // read the incoming byte:
        incomingByte = Serial.read();

        // say what you got:
        Serial.print("I received: ");
        Serial.println(incomingByte, BIN);
        _delay_ms(500);
    }

    switch (incomingByte)
    {
    case 0b1100010:                 // b  
            //enable timer1 interrupt
            sei();
        break;
    case 0b1110011:                 // s
            cli();
        break;
    default:
        break;
    }
}






void sendMessageOG(char* bitPtr)
{
    for (int i = 0; i < 4; i++)
    {
        if (*bitPtr == '1')
        {
            digitalWrite(11, HIGH);
        }
        if (*bitPtr == '0')
        {
            digitalWrite(11, LOW);
        }
        bitPtr++;
        ptrCounter++;
        _delay_ms(1);
    }
    if (*bitPtr == '\0')
    {
        bitPtr -= ptrCounter;
    }
    //amIAllowedToSendMessage = false;
}
void allowMessage()
{
    //amIAllowedToSendMessage = true;
}