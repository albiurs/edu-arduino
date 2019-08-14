/*
 * String Tests
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


	// exercise 3 - Strings
	char str1[5] = {'T', 'e', 's', 't', '\0'};
	char str2[] = "Hallo";	// Array-length = 5 after declaration
	char str3[5] = "Velo";
	char str4[15] = "ok";	// sizeof(str4) is 15!

	for (unsigned int cnt=0; cnt<sizeof(str1); cnt++) { // unsigned int weil sizeof Rückgabe unsigned int ist
		DEBUG_PRINTLN(str1[cnt]);
	}

	for (unsigned int cnt=0; cnt<sizeof(str2); cnt++) {
		DEBUG_PRINTLN(str2[cnt]);
	}

	for (unsigned int cnt=0; cnt<sizeof(str3); cnt++) {
		DEBUG_PRINTLN(str3[cnt]);
	}
	for (unsigned int cnt=0; cnt<sizeof(str4); cnt++) {	// sizeof(str4) is 15!
		DEBUG_PRINTLN(str4[cnt]);
	}
	DEBUG_PRINTLN();


	// exercise 4 - format Strings
	// continuation of exercise 2
	int size = 10;
	int values[size];
	for (int cnt=0; cnt<size; cnt++) {
		values[cnt]=cnt;
	}
	for (int cnt=0; cnt<size; cnt++) {	// size defined in exercise 2
		char buf[20];
		sprintf(buf, "values[cnt] = %d %s", values[cnt], "hello");
		DEBUG_PRINTLN(buf);
	}
	DEBUG_PRINTLN();


	// exercise 5 - format Strings 2
	// transformation of float
	// Periode einer Sinusschwingung
	const float pi = 3.14;
	int wave[256];

	float rad = 0;
	for (int i = 0; i < 256; i++) {
		rad = rad + (2.00 * pi / 256.00);
		wave[i] = (sin(rad) * 128) + 128;

		char buf[64];
		char strbuf[8];
		// rad = value,
		// 5 = length of the string that will be created,
		// 3 = number of digits after the decimal point to print,
		// strbuf = array to output the number-string
		dtostrf(rad, 5, 3, strbuf);	// dtostrf = double to string format
		sprintf(buf, "rad=%s, wave[i]=%d", strbuf, wave[i]); // ????
		DEBUG_PRINTLN(buf);
	}
	DEBUG_PRINTLN();


	// String Class of Arduino
	String string1 = "Hello String";                    // using a constant String
	String string2 = String('a');                       // converting a constant char into a String
	String string3 = String("This is a string");        // converting a constant string into a String object
	String string4 = String(string2 + " with more");  // concatenating two strings
	String string5 = String(13);                        // using a constant integer
	String string6 = String(analogRead(0), DEC);        // using an int and a base
	String string7 = String(45, HEX);                   // using an int and a base (hexadecimal)
	String string8 = String(255, BIN);                  // using an int and a base (binary)
	String string9 = String(millis(), DEC);             // using a long and a base
	String string10 = String(5.698, 3);                  // using a float and the decimal places
	String string11 = String("Hello String " + String(5));
	DEBUG_PRINTLN(string11);
}


// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}
