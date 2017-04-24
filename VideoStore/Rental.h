/*
 * Rental.h
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#ifndef RENTAL_H_
#define RENTAL_H_

#include <string>
#include <iostream>

class Rental {
	std::string title;
	double cost;
	int rating;
	bool rented;

public:

	Rental(std::string title, double cost, int rating) :
			title(title), rating(rating), cost(cost), rented(false) {
	}

	double getCost() const {
		return cost;
	}

	int getRating() const {
		return rating;
	}

	bool isRented() const {
		return rented;
	}

	void setRented(bool rented) {
		this->rented = rented;
	}

	const std::string& getTitle() const {
		return title;
	}

	virtual friend std::ostream& operator<<(std::ostream &out,
			const Rental &point) {
		out << "Rental: Title: " << title << "\nCost: " << cost << "\nRating: "
				<< rating << '\n';
		return out;
	}
};



#endif /* RENTAL_H_ */
