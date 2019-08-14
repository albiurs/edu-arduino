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

// Decalaration and initialisation
int n = 5; 		// Deklaration einer normalen Variablen
int *ip;		// Deklaration eines Zeigers der auf Integer zeigen kann

struct Auto // Struktur erstellen
{
	int maxGeschwindigkeit;
};



//The setup function is called once at startup of the sketch
void setup()
{
	// config serial port & serial monitor to Baud rate 9600 bits/s
	Serial.begin(9600); // =serial return of Arduino's output
	DEBUG_PRINTLN();


	// Pointer
	ip = &n;			// Pointer ip (= Adresse) wird initialisiert mit der Adresse der Variablen n
	*ip = *ip + 2;	// n wird mithilfe des Zeigers um 2 erhöht
	DEBUG_PRINTLN(n);	// = 7
	DEBUG_PRINTLN();

	Auto bmw, *pBmw; // Anlegen einer Variablen und einem Pointer
	pBmw = &bmw; // Pointer bekommt die Adresse von bmw
	//(*pBmw).maxGeschwindigkeit = 290; // zugriff auf die Variable
	pBmw->maxGeschwindigkeit = 290; // bessere alternative
	DEBUG_PRINTLN(((*pBmw).maxGeschwindigkeit)); // output 290
	DEBUG_PRINTLN(pBmw->maxGeschwindigkeit);	 // output 290
	DEBUG_PRINTLN(bmw.maxGeschwindigkeit);		 // output 290
	DEBUG_PRINTLN();
}

// The loop function is called in an endless loop
void loop()
{
	// Repeated Code
}
