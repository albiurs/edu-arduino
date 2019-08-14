/*
 * Header-Test
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

// Test Header-File Deklaration
#include "haederTest.h"

int add(int a, int b) { // Definition der Funktion
	return (a + b);
}
int res_c = add(1, 2); // Aufruf der Funktion


//The setup function is called once at startup of the sketch
void setup()
{
	// config serial port & serial monitor to Baud rate 9600 bits/s
	Serial.begin(9600); // =serial return of Arduino's output

	// Test Header-File Deklaration
	DEBUG_PRINTLN(res_c);
	DEBUG_PRINTLN();
}


// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
