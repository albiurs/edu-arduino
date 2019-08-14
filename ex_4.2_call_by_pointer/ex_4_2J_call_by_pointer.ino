/*
 * Call by Pointer
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

// Call by Pointer
void swap(int *a, int *b);



//The setup function is called once at startup of the sketch
void setup()
{
	// config serial port & serial monitor to Baud rate 9600 bits/s
	Serial.begin(9600); // =serial return of Arduino's output
	DEBUG_PRINTLN();


	// Call by Pointer
	int x = 1;
	int y = 2;
	swap(&x, &y); // nachdem Aufruf besitzt x den Wert 2, y den Wert 1
	DEBUG_PRINTLN(x);	// = 2
	DEBUG_PRINTLN(y);	// = 1
	DEBUG_PRINTLN();
}



// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}



// Call by Pointer
void swap(int *a, int *b)
{
	int tmp;
	tmp = *a; // Variable wird temporär zwischengespeichert;
	*a = *b;
	*b = tmp;
}
/*
void swap(int *a, int *b)
{
	int *tmp = a; // Variable wird temporär zwischengespeichert;
	a = b;
	b = tmp;
	//*tmp = (*a) + (*b); // Falls man auf die Werte zugreifen will
}
*/

