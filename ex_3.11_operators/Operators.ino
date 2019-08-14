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

	// arithmetic Operators
	int a = 2;
	int b = 3;

	a = a + b;	// Addition
	a += b;
	a = a - b;	// Subtraktion
	a -=b;
	a = a * b;	// Multiplikation
	a *= b;
	a = a / b;	// Division (Vorsicht bei Integer)
	a /= b;
	a = a % b;	// Modulo (Rest bei Division)
	a %= b;
	a = b++;	// Post Inkrement: zuerst zuweisen und erst danach 1 hochzählen
	a = ++b;	// Pre Inkrement: zuerst 1 hochzählen und erst danach zuweisen
	a = b--;	// Post Dekrement
	a = --b;	// Pre Dekrement


	// Vergleichsoperatoren
	int a = 3, b = 6;
	a < b; // a kleiner b
	a <= b; // a kleiner gleich b
	a > b; // a größer b
	a >= b; // a größer gleich b
	a == b; // a gleich b (Vorsicht bei Gleitkommazahlen) a != b; // a ungleich b (Vorsicht bei Gleitkommazahlen)
	if(a == b) // wenn erfüllt {
		//..dann tue das
	}


	// Logische Operatoren
	bool a = true;
	a = !a; // jetzt hat a den wert false
	a = a && true; // logisches UND
	a = a || true; // logisches ODER


	// Bitorientierte Operatoren
	short int n = 6 // 0..000110 entspricht 6
	n = ~n; // Complement, d.h. jede 0 wird eine 1 und jede 1 eine 0
	n = n & 1; // bit-AND
	n = n | 1; // bit-OR n = n ^ 1 // bit-XOR
	n = n << 2; // shift left by 2 n = n >> 2 // shift right by 2
	if ((n | 1) == n) // 10101 OR 00001 = 10101 {
	 // zahl n ist ungerade
	}
}

// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}
