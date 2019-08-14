/*
 * Hello World
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


// Test Header-File Deklaration
#include "haederTest.h"

int add(int a, int b) { // Definition der Funktion
	return (a + b);
}
int res_c = add(1, 2); // Aufruf der Funktion


// Call by Value
// Definition der Funktion.
// Void bedeutet das diese Funktion nichts zurückgibt
int y;
void calcY(int y) {
	y = y + 2;		// Die Veränderung von y ist ausserhalb von calcY nicht sichtbar.
					// calcY erstellt eine Kopie von y
}


// Pointer und struct
int n = 5; 		// Deklaration einer normalen Variablen
int *ptr;		// Deklaration eines Zeigers der auf Integer zeigen kann


struct Auto {	// Struktur erstellen
	int maxGeschwindigkeit;
};


// Call by Pointer
void swap (int *a, int *b) {
	int *tmp = a; // Variable wird temporär zwischen gespeichert a=b;
	a = b;
	b = tmp;
	//*tmp = (*a) + (*b); // Falls man auf die Werte zugreifen will
}

int xx = 1, yy = 2;


//The setup function is called once at startup of the sketch
void setup()
{
	// config serial port & serial monitor to Baud rate 9600 bits/s
	Serial.begin(9600); // =serial return of Arduino's output

	// exercise 1 - Hello World
	DEBUG_PRINTLN("Hello World");
	DEBUG_PRINTLN();


	// exercise 2 - Arrays
	int size = 10;
	int values[size];
	for (int cnt=0; cnt<size; cnt++) {
		values[cnt]=cnt;
	}
	for (int cnt=0; cnt<size; cnt++) {
		DEBUG_PRINTLN(values[cnt]);
	}
	DEBUG_PRINTLN();


	// exercise 3 - Strings
	char str1[5] = {'T', 'e', 's', 't', '\0'};
	char str2[] = "Hallo";	// Array-length = 5 after declaration
	char str3[5] = "Velo";
	char str4[15] = "ok";	// sizeof(str4) is 15!

	for (unsigned int cnt=0; cnt<sizeof(str1); cnt++) {
		DEBUG_PRINTLN(str1[cnt]);
	}

	for (int cnt=0; cnt<sizeof(str2); cnt++) {
		DEBUG_PRINTLN(str2[cnt]);
	}

	for (int cnt=0; cnt<sizeof(str3); cnt++) {
		DEBUG_PRINTLN(str3[cnt]);
	}
	for (int cnt=0; cnt<sizeof(str4); cnt++) {	// sizeof(str4) is 15!
		DEBUG_PRINTLN(str4[cnt]);
	}
	DEBUG_PRINTLN();


	// exercise 4 - format Strings
	// continuation of exercise 2
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
		dtostrf(rad, 5, 3, strbuf);
		sprintf(buf, "rad=%s, wave[i]=%d", strbuf, wave[i]); // ????
		DEBUG_PRINTLN(buf);
	}
	DEBUG_PRINTLN();



	// exercise 6 - Enum
	// extension of exercise 1
	enum Tag {
		montag, dienstag, mittwoch, donnerstag, freitag, samstag, sonntag
	};

	Tag tag;	// declaration of new variable
	tag = samstag;
	if(tag == samstag) {
		// gute Laune
		DEBUG_PRINTLN("gute Laune");
	}
	DEBUG_PRINTLN();


	// exercise 7 - functions
	int valuesTwo[10];
	int arrLength = sizeof(valuesTwo)/sizeof(valuesTwo[0]);
	initIntArray(valuesTwo, arrLength);
	printIntArray(valuesTwo, arrLength);
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


	// Test Header-File Deklaration
	DEBUG_PRINTLN(res_c);
	DEBUG_PRINTLN();


	// Call by Value
	int y1 = 2;
	calcY(y1);
	// nach dem Aufruf hat die lokale Variable y1
	// immer noch den Wert 2
	DEBUG_PRINTLN(y);	// = 0
	DEBUG_PRINTLN(y1);	// = 2
	DEBUG_PRINTLN();


	// Pointer
	ptr = &n;			// Pointer wird initialisiert mit der Adresse der Variablen
	*ptr = *ptr + 2;	// n wird mithilfe des Zeigers um 2 erhöht
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


	// Call by Pointer
	swap(&xx, &yy); // nachdem Aufruf besitzt x den Wert 2, y den Wert 1
	DEBUG_PRINTLN(xx);	// = 2
	DEBUG_PRINTLN(yy);	// = 1
	DEBUG_PRINTLN();


}
// The loop function is called in an endless loop
void loop()
{
	//Add your repeated code here
}
