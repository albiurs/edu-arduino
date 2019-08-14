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

// Call by Value
// Definition der Funktion.
// Void bedeutet das diese Funktion nichts zurückgibt
int y;
void calcY(int y) {
	y = y + 2;		// Die Veränderung von y ist ausserhalb von calcY nicht sichtbar.
					// calcY erstellt eine Kopie von y
}


//The setup function is called once at startup of the sketch
void setup()
{
	// config serial port & serial monitor to Baud rate 9600 bits/s
	Serial.begin(9600); // =serial return of Arduino's output
	DEBUG_PRINTLN();


	// Call by Value
	int y1 = 2;
	calcY(y1);
	// nach dem Aufruf hat die lokale Variable y1
	// immer noch den Wert 2
	DEBUG_PRINTLN(y);	// = 0
	DEBUG_PRINTLN(y1);	// = 2
	DEBUG_PRINTLN();
}

// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}
