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

// exercise 7 definitions
void initIntArray(int vals[], int size) {
	for(int cnt=0; cnt<size; cnt++) {
		vals[cnt]=cnt;
	}
}

void printIntArray(int vals[], int size) {
	char buf[10];

	for(int cnt=0; cnt<size; cnt++) {
		sprintf(buf, "cnt = %d", vals[cnt]);
		DEBUG_PRINTLN(buf);
	}
}



//The setup function is called once at startup of the sketch
void setup()
{
	// config serial port & serial monitor to Baud rate 9600 bits/s
	Serial.begin(9600); // =serial return of Arduino's output
	DEBUG_PRINTLN();


	// exercise 7 - functions
	int valuesTwo[10];
	int arrLength = sizeof(valuesTwo)/sizeof(valuesTwo[0]);
	initIntArray(valuesTwo, arrLength);
	printIntArray(valuesTwo, arrLength);
	DEBUG_PRINTLN();
}

// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}
