/*
 * Call by Reference
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

// call by reference
void swap (int &a, int &b);



//The setup function is called once at startup of the sketch
void setup()
{
	// config serial port & serial monitor to Baud rate 9600 bits/s
	Serial.begin(9600); // =serial return of Arduino's output
	DEBUG_PRINTLN();


	// call by reference
	int x=1,y=2;
	swap(x, y); // nachdem Aufruf hat x den Wert 2 und y den Wert 1
	DEBUG_PRINTLN(x);
	DEBUG_PRINTLN(y);
}



// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}



// call by reference
void swap (int &a, int &b) {
	int tmp = a; // Variable wird temporär zwischen gespeichert
	a=b;
	b=tmp;
}
