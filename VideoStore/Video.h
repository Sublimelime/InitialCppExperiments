/*
 * Video.h
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#ifndef VIDEO_H_
#define VIDEO_H_

#include <string>
#include <vector>
#include "Rental.h"

class Video: public Rental {

	const std::string director, description, title;
	const double cost;
	const int minutes;
	std::string ratingLocalized;
	VideoRating rating;
	std::vector<std::string> leadingActors;

public:
	Video(std::string title, double cost, VideoRating rating,
			std::string description, std::vector<std::string> leadingActors,
			std::string director, int minutes) :
			title(title), cost(cost), rating(rating), description(description), minutes(
					minutes), leadingActors(leadingActors) {
		//set the printable variable off of the rating, so it can be printed
		switch (static_cast<int>(rating)) {
			case 1:
			ratingLocalized = "G";
			break;
			case 2:
			ratingLocalized = "PG";
			break;
			case 3:
			ratingLocalized = "PG13";
			break;
			case 4:
			ratingLocalized = "R";
			break;
		}
	}

	virtual const std::string& toString() const override {
		return "Video: Title:" << title << "\nCost: " << cost << "\nRating"
				<< ratingLocalized << "\nDirector: " << director << "\nMinutes:"
				<< minutes << "\nDesc: " << description << "\nLeading actors: "
				<< leadingActors;
	}

	const std::string& getDescription() const {
		return description;
	}

	const std::string& getDirector() const {
		return director;
	}

	const int getMinutes() const {
		return minutes;
	}

	const std::string& getRatingLocalized() const {
		return ratingLocalized;
	}

	const std::vector<std::string>& getLeadingActors() const {
		return leadingActors;
	}
};



#endif /* VIDEO_H_ */
