/*
 * mainfile.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: othscs253
 */

#include <iostream>
#include <cmath>

using namespace std;
int main() {

	int finalPrice = 0, finalDiscount = 0;
	double price, discount;
	double total;

	do {
		cout << "Please enter a price, enter 0 to start entering discounts.\n";
		cin >> price;
		cin.ignore(3445564,'\n');
		finalPrice += price;
	} while (price > 0);

	do {
		cout << "Please enter the discounts. Enter 0 to calculate.\n";
		cin >> discount;
		cin.ignore(1223445,'\n');
		finalDiscount -= discount;
	} while(discount > 0);

	cout << "Subtotal is: " << finalPrice << endl;
	cout << "With a discount of " << finalDiscount << " dollars off, ";
	total = finalPrice + finalDiscount;
	cout << "final total is $" << total;

	return 0;
}


