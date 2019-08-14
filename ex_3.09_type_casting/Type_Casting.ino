/*
 * Type Casting
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


	// Type Casting
	int a = 5, b = 2;
	float f = 0.0;
	int c = 257;
	long d = 257;
	long e;

	f = a / b;			/* f ist 2 !!!! nicht etwa 2.5 weshalb? */
	f = (float)a / b;	/* jetzt ist f 2.5 */
	f = (float) (a / b);/* jetzt ist f wieder 2 */

	b = (char)c;		/* b ist nun 1, weshalb?? */
	DEBUG_PRINTLN(b);	// char = 8 bit = 256 Möglichkeiten, dann Überlauf
	f = a / 3.0;		/* f ist jetzt 1.6666666 weshalb?? */
	c = a / 3.0;		/* c ist jetzt 1 weshalb?? */
	c = a / 3.0 + 0.5;	/* c ist jetzt 2 weshalb?? */
	c = a / 3 + 0.5;	/* c ist jetzt 1 weshalb?? */
	DEBUG_PRINTLN();
}

// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}
