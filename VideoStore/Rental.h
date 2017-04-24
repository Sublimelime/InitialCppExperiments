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
	G, EVERYONE, EVERONE_TEN_PLUS, TEEN, MATURE, ADULTS, ONLY, RATING_PENDING,
};

enum class VideoRating {
	G, PG, PG13, R,
};

class Rental {
	std::string title;
	double cost;
	GameRating rating;
	bool rented;

public:

	Rental(std::string title, double cost, GameRating rating) :
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
			const Rental &rental) {
		out << "Rental: Title: " << title << "\nCost: " << cost << "\nRating: "
				<< rating << '\n';
		return out;
	}
};



#endif /* RENTAL_H_ */
