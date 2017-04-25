/*
 * Game.h
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <iostream>

#include "Rental.h"

class Game: public Rental {

	const std::string platform;
	const int numberOfPlayers;
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
		case 5:
			ratingLocalized = "Mature";
			break;
		case 6:
			ratingLocalized = "Adults only";
			break;
		case 7:
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

	virtual std::string& toString() const override {
		return "Game: Title:" << title << "\nCost: " << cost << "\nRating"
				<< ratingLocalized << "\n# of players: " << numberOfPlayers
				<< "\nPlatform:" << platform;
	}

};

#endif /* GAME_H_ */