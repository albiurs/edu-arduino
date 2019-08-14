/*
 * Project 7.1 passive buzzer with transistor
 */

#include "Arduino.h"

#define DEBUG // debug switch

#ifdef DEBUG
#define DEBUGPRINT(x) Serial.print(x)
#define DEBUGPRINTLN(x) Serial.print(x)
#else
#define DEBUGPRINT(x)
#define DEBUGPRINTLN(x)
#endif

#include "pitches.h"

// notes in the melody:
int melody[] = {
		NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};
int duration = 100;

//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);

	pinMode(8, OUTPUT);
}

// The loop function is called in an endless loop
void loop()
{
	for (int thisNote = 0; thisNote < 8; thisNote++) {
		// pin8 output the voice, every scale is 0.5 second
		tone(8, melody[thisNote], duration);
		delay(200);
	}

	for (int thisNote = 7; thisNote >= 0; thisNote--) {
		// pin8 output the voice, every scale is 0.5 second
		tone(8, melody[thisNote], duration);
		delay(200);
	}

	// restart after two seconds
	delay(2000);
}
