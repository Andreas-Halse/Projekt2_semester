/*
 Name:		First_draft.ino
 Created:	12/8/2021 1:02:37 PM
 Author:	oliver
*/
#define F_CPU 16000000

int incomingByte = 0; // for incoming serial data

void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    DDRB = 0xFF;
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
    case 0b1100010:
        PORTB = 0b01100010;
        break;
    case 0b1110011:
        PORTB = 0b01110011;
        break;
    default:
        break;
    }
}
