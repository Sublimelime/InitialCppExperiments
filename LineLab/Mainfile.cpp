/*
 * Mainfile.cpp
 *
 *  Created on: Apr 18, 2017
 *      Author: othscs253
 */

#include <iostream>
#include "Mainfile.h"
#include "Line.h"
#include <string>
#include <cmath>

int main() {
	using namespace std;
	int p1x, p2x, p2y, p1y;

	cout << "Please enter X for line 1, point 1.\n";
	cin >> p1x;
	if (!checkCin()) {
		return 0;
	}
	cout << "Please enter Y for line 1, point 1.\n";
	cin >> p1y;
	if (!checkCin()) {
		return 0;
	}
	cout << "Please enter X for line 1, point 2.\n";
	cin >> p2x;
	if (!checkCin()) {
		return 0;
	}
	cout << "Please enter Y for line 1, point 2.\n";
	cin >> p2y;
	if (!checkCin()) {
		return 0;
	}

	Line line1 { p1x, p2x, p1y, p2y };

	cout << "Please enter X for line 2, point 1.\n";
	cin >> p1x;
	if (!checkCin()) {
		return 0;
	}
	cout << "Please enter Y for line 2, point 1.\n";
	cin >> p1y;
	if (!checkCin()) {
		return 0;
	}
	cout << "Please enter X for line 2, point 2.\n";
	cin >> p2x;
	if (!checkCin()) {
		return 0;
	}
	cout << "Please enter Y for line 2, point 2.\n";
	cin >> p2y;
	if (!checkCin()) {
		return 0;
	}

	Line line2(p1x, p2x, p1y, p2y);

	while (true) {
		cout << "Choices:\n1. View line 1\n2. View line 2\n"
				<< "3. Change line 1\n4. Change line 2\n5. View intersection\n";
		int choice;
		cin >> choice;
		if (!checkCin()) {
			continue;
		}
		switch (choice) {
		case 1: {
			cout << line1.print();
		}
			break;
		case 2: {
			cout << line2.print();
		}
			break;
		case 3: {
			changeLine(line1);
		}
			break;
		case 4: {
			changeLine(line2);
		}
			break;
		case 5: {
			cout << viewIntersect(line1, line2);
		}
			break;
		default:
			cout << "Invalid choice.\n";
		}

	}

	return 0;
}

//checks if input was valid, and clears it out
bool checkCin() {
	using namespace std;
	if (cin.fail()) {
		cin.clear();
		cout << "Invalid input.\n";
		cin.ignore(12344557, '\n');
		return false;
	}
	cin.ignore(12344557, '\n');
	return true;
}

std::string viewIntersect(Line &ln1, Line &ln2) {
	if (abs(ln1.getSlope() - ln2.getSlope()) > 0.00000000001) {
		double xInter = (ln2.getYInt() - ln1.getYInt())
				/ (ln1.getSlope() - ln2.getSlope());
		double yInter = ln1.getSlope() * xInter + ln1.getYInt();

		return "The two lines intersect at: (" + xInter + "," + yInter + ")";
	}

	return "No intersect found.\n";
}

void changeLine(Line &line) {
	using std::cout;
	using std::cin;

	while (true) {
		cout << "--------------------------\n";
		cout << "Choices:\n";
		cout << "1.Change point 1\n2.Change point 2\n3.Change both\n4.Cancel\n";
		int choice;
		cin >> choice;
		if (!checkCin()) {
			continue;
		}
		switch (choice) {
		case 1:
			changePoint1(line);
			return;
		case 2:
			changePoint2(line);
			return;
		case 3:
			changePoint1(line);
			changePoint2(line);
			break;
		case 4:
			return;
		}
	}
}

void changePoint1(Line &line) {
	using std::cout;
	using std::cin;

	cout << "New value for X?\n";
	int newX;
	cin >> newX;
	if (!checkCin()) {
		return;
	}
	cout << "New value for Y?\n";
	int newY;
	cin >> newY;
	if (!checkCin()) {
		return;
	}
	line.setPoint1X(newX);
	line.setPoint1Y(newY);
}

void changePoint2(Line &line) {
	using std::cout;
	using std::cin;

	cout << "New value for X?\n";
	int newX;
	cin >> newX;
	if (!checkCin()) {
		return;
	}
	cout << "New value for Y?\n";
	int newY;
	cin >> newY;
	if (!checkCin()) {
		return;
	}
	line.setPoint2X(newX);
	line.setPoint2Y(newY);
}









