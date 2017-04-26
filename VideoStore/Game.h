/*
 * Game.h
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>

#include "Rental.h"

class Game: public Rental {

	std::string platform;
	int numberOfPlayers;
	std::string ratingLocalized;
	GameRating rating;

public:
	Game(std::string title, double cost, GameRating rating,
			std::string platform,
			int numberOfPlayers) :
			Rental(title, cost), platform(platform), numberOfPlayers(
					numberOfPlayers), rating(rating) {
		//set the printable variable off of the rating, so it can be printed
		switch (static_cast<int>(rating)) {
		case 0:
			ratingLocalized = "G";
			break;
		case 1:
			ratingLocalized = "Everyone";
			break;
		case 2:
			ratingLocalized = "Everyone 10+";
			break;
		case 3:
			ratingLocalized = "Teen";
			break;
		case 4:
			ratingLocalized = "Mature";
			break;
		case 5:
			ratingLocalized = "Adults only";
			break;
		case 6:
			ratingLocalized = "Rating pending";
			break;
		}
	}


	int getNumberOfPlayers() const {
		return numberOfPlayers;
	}

	const std::string& getPlatform() const {
		return platform;
	}

	virtual std::string toString() const override {
		std::string temp = "Game: \nTitle: " + title + "\nCost: "
				+ std::to_string(cost) + "\nRating: " + ratingLocalized
				+ "\n# of players: "
				+ std::to_string(numberOfPlayers)
				+ "\nPlatform: " + platform;
		return temp;
	}

};

#endif /* GAME_H_ */
