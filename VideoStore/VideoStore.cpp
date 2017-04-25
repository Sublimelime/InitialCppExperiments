/*
 * VideoStore.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

//adds a rental pointer to the appropriate vector for it's type.
void VideoStore::addRental(Rental* r) {

}

int VideoStore::gamesInStock() {
	int counter { 0 };
	for (int i = 0; i < games.size(); i++) {
		if (!games.at(i).rented) {
			counter++;
		}
	}
	return counter;
}
int VideoStore::videosInStock() {
	int counter { 0 };
	for (int i = 0; i < videos.size(); i++) {
		if (!videos.at(i).rented) {
			counter++;
		}
	}
	return counter;
}

