/*
 * Projekt 16: Eine Binärzahlenanzeige aus LEDs bauen
 */

#include "Arduino.h"

#define DEBUG // activate "debug switch"

#ifdef DEBUG
#define DBUG_PRINT(x) Serial.print(x)		// acitvate print
#define DEBUG_PRINTLN(x) Serial.println(x)	// activate print line
#else
#define DEBUG_PRINT(x)						// do nothing
#define DEBUG_PRINTLN(x)					// do nothing
#endif

#define DATA 6 // Digitalpin 6 an Pin 14 des 74HC595
#define LATCH 8 // Digitalpin 8 an Pin 12 des 74HC595
#define CLOCK 10 // Digitalpin 10 an Pin 11 des 74HC595


//The setup function is called once at startup of the sketch
void setup()
{
	pinMode(LATCH, OUTPUT);
	pinMode(CLOCK, OUTPUT);
	pinMode(DATA, OUTPUT);
}


// The loop function is called in an endless loop
void loop()
{
	int i;

	for ( i = 0; i < 256; i++ ) {
		digitalWrite(LATCH, LOW);
		shiftOut(DATA, CLOCK, MSBFIRST, i);
		digitalWrite(LATCH, HIGH);
		delay(200);
	}
}

