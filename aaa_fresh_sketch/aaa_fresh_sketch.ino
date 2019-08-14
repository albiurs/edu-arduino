/*
 * Fresh Sketch
 */

#include "Arduino.h"

#define DEBUG // activate "debug switch"

#ifdef DEBUG
#define DBUG_PRINT(x) Serial.print(x)		// activate print
#define DEBUG_PRINTLN(x) Serial.println(x)	// activate print line
#else
#define DEBUG_PRINT(x)						// do nothing
#define DEBUG_PRINTLN(x)					// do nothing
#endif

void print (const char str[], int number);
void print (const char str[], float number);



//The setup function is called once at startup of the sketch
void setup()
{
	// config serial port & serial monitor to Baud rate 9600 bits/s
	Serial.begin(9600); // =serial return of Arduino's output
	DEBUG_PRINTLN();
}



// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}



void print (const char str[], int number) {
	char buf[100];
	sprintf(buf, "%s %d", str, number);
	DEBUG_PRINTLN(buf);
}

void print (const char str[], float number) {
	char buf[100];
	char strbuf[10];
	dtostrf(number, 3, 3, strbuf);
	sprintf(buf, "%s %s", str, strbuf);
	DEBUG_PRINTLN(buf);
}
