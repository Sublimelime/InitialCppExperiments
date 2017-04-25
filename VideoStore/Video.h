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
	int minutes;
	std::string ratingLocalized;
	VideoRating rating;

public:
	Video(std::string title, double cost, VideoRating rating,
			std::string description, std::string director, int minutes) :
			title(title), cost(cost), rating(rating), description(description), minutes(
					minutes) {
		//set the printable variable off of the rating, so it can be printed
		switch (static_cast<int>(rating)) {
			case 1:
			ratingLocalized = "G";
			break;
			case 2:
			ratingLocalized = "Everyone";
			break;
			case 3:
			ratingLocalized = "Everyone 10+";
			break;
			case 4:
			ratingLocalized = "Teen";
			break;

		}
	}

	virtual std::string& toString() const override {
		return "Video: Title:" << title << "\nCost: " << cost << "\nRating"
				<< ratingLocalized << "\n# of players: " << numberOfPlayers
				<< "\nPlatform:" << platform;
	}

};



#endif /* VIDEO_H_ */
