/*
 * Punkt2.h
 *
 *  Created on: 4 Jul 2019
 *      Author: alu
 */

#ifndef PUNKT2_H_
#define PUNKT2_H_

class Punkt2 {

private:
	double x, y;

public:
	Punkt2(double X=0, double Y=0);

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

#endif /* PUNKT2_H_ */
