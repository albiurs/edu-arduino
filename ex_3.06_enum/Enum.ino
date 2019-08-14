/*
 * Fresh Sketch
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



//The setup function is called once at startup of the sketch
void setup()
{
	// config serial port & serial monitor to Baud rate 9600 bits/s
	Serial.begin(9600); // =serial return of Arduino's output
	DEBUG_PRINTLN();

	// exercise 6 - Enum
	// extension of exercise 1
	enum Tag {
		montag, dienstag, mittwoch, donnerstag, freitag, samstag, sonntag
	};

	Tag tag;	// declaration of new variable
	tag = samstag;
	if(tag == samstag) {
		// gute Laune
		DEBUG_PRINTLN("gute Laune");
	}
	DEBUG_PRINTLN();
}

// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}
