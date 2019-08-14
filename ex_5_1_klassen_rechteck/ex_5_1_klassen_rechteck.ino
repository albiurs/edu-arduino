/*
 * Fresh Sketch
 */

#include "Arduino.h"
#include <math.h>

#define DEBUG // activate "debug switch"

#ifdef DEBUG
#define DBUG_PRINT(x) Serial.print(x)		// acitvate print
#define DEBUG_PRINTLN(x) Serial.println(x)	// activate print line
#else
#define DEBUG_PRINT(x)						// do nothing
#define DEBUG_PRINTLN(x)					// do nothing
#endif

// Lösung Rechteck
#include "Arduino.h" // nur bei Sloeber IDE
#include  <math.h>
//#include "Punkt2.h"
//class Punkt2;

/*
class Punkt {
private:
	double x, y;

public:
	Punkt(double X=0, double Y=0) {
		x=X; y=Y;
	}

	void set (double X , double Y) {
		x=X;
		y=Y;
	}

	double getX () {
		return x;
	}

	double getY () {
		return y;
	}
};
*/

class Rechteck {
private:
	Punkt A;
	Punkt B;

public:
	Rechteck(Punkt A, Punkt B) {
		this->A = A;
		this->B = B;
	}

	double computeFlaeche() {
		return fabs((A.getX() -B.getX()) * (A.getY() - B.getY()));
	}

	double computeUmfang() {
		return fabs(2 * (A.getX() - B.getX())) + fabs(2 * (A.getY() - B.getY()));
	}

	Rechteck* get() {
		return this;
	}

	Punkt getA() {
		return A;
	}

	Punkt getB() {
		return B;
	}
};

void print (const char str[], double number) {
	char buf[100];
	char strbuf[10];
	dtostrf(number, 3, 3, strbuf);
	sprintf(buf, "%s %s", str, strbuf);
	Serial.println(buf);
}



void setup()
{
	Serial.begin(9600);  // Initialize serial communications with the PC
	// Zwei Variablen vom Typ "Punkt" zur Eingabe der Rechteckkoordinanten
	Punkt A, B;
	A.set(2.0,2.0);
	B.set(4.0,4.0);

	// Erzeugen eines Objekts der Klasse "Rechteck" und
	// Berechnung des Umfangs und der Flaeche des Rechteckes
	Rechteck re( A, B);

	print("Fläche = ", re.computeFlaeche());
	print("Umfang = ", re.computeUmfang());
}

// The loop function is called in an endless loop
void loop()
{
	//Add your repeated code here
}
