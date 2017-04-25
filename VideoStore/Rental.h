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

enum class GameRating {
	G, EVERYONE, EVERYONE_TEN_PLUS, TEEN, MATURE, ADULTS_ONLY, RATING_PENDING,
};

enum class VideoRating {
	G, PG, PG13, R,
};

class Rental {
	std::string title;
	double cost;
	bool rented;

public:

	Rental(std::string title, double cost,) :
			title(title), cost(cost), rented(false) {
	}

	virtual ~Rental() {

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

	friend std::ostream& operator<<(std::ostream &out, const Rental &b) {
		// Delegate printing responsibility for printing to member function print()
		out << b.toString();
		return out;
	}

	virtual const std::string& toString() const {
		return "Rental";
	}

};



#endif /* RENTAL_H_ */
