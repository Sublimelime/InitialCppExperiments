/*
 * VideoStore.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#include "VideoStore.h"
#include <vector>

/*
 * adds a rental pointer to the appropriate vector for it's type.
 * Don't forget to deallocate the pointer sent.
 */
void VideoStore::addRental(Rental* r) {
	if (dynamic_cast<Game*>(r) != nullptr) { //the rental is a game
		Game* game = dynamic_cast<Game*>(r);
		games.push_back(*game); //add the game to the list of games
	} else if (dynamic_cast<Video*>(r) != nullptr) {
		Video* video = dynamic_cast<Video*>(r);
		videos.push_back(*video); //add the video to the list of videos
	} else {
		throw "Pointer is not a game or Video.";
	}
}

int VideoStore::gamesInStock() {
	if (games.empty()) {
		return 0;
	}
	int counter { 0 };
	for (unsigned int i = 0; i < games.size(); i++) {
		if (!games.at(i).isRented()) {
			counter++;
		}
	}
	return counter;
}
int VideoStore::videosInStock() {
	if (videos.empty()) {
		return 0;
	}
	int counter { 0 };
	for (unsigned int i = 0; i < videos.size(); i++) {
		if (!videos.at(i).isRented()) {
			counter++;
		}
	}
	return counter;
}

void VideoStore::removeGame(int index) {
	index--;
	games.erase(games.begin() + index);

}

void VideoStore::removeVideo(int index) {
	index--;
	videos.erase(videos.begin() + index);

}

