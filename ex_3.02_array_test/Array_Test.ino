/*
 * Array-Test
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

	// exercise 2 - Arrays
	int size = 10;
	int values[size];
	for (int cnt=0; cnt<size; cnt++) {
		values[cnt]=cnt;
	}
	for (int cnt=0; cnt<size; cnt++) {
		DEBUG_PRINTLN(values[cnt]);
	}
	DEBUG_PRINTLN();
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
