/*
 * Line.h
 *
 *  Created on: Apr 18, 2017
 *      Author: othscs253
 */

#ifndef LINE_H_
#define LINE_H_

#include <string>

class Line {

	int point1X, point2X, point1Y, point2Y;

public:

	Line(int p1x, int p2x, int p1y, int p2y) {
		point1X = p1x;
		point2X = p2x;
		point1Y = p1y;
		point2Y = p2y;
	}

	int getPoint1X() const {
		return point1X;
	}

	void setPoint1X(int point1X) {
		this->point1X = point1X;
	}

	int getPoint1Y() const {
		return point1Y;
	}

	void setPoint1Y(int point1Y) {
		this->point1Y = point1Y;
	}

	int getPoint2X() const {
		return point2X;
	}

	void setPoint2X(int point2X) {
		this->point2X = point2X;
	}

	int getPoint2Y() const {
		return point2Y;
	}

	void setPoint2Y(int point2Y) {
		this->point2Y = point2Y;
	}

	std::string print();
};


#endif /* LINE_H_ */
