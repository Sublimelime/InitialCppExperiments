/*
 * VideoStore.h
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#ifndef VIDEOSTORE_H_
#define VIDEOSTORE_H_

#include <memory>
#include <vector>

#include "Game.h"
#include "Video.h"

class VideoStore
{

  std::vector<Game> games;
  std::vector<Video> videos;

public:

  void
  addRental (const std::unique_ptr<Rental>& r);
  void
  removeGame (int index);
  void
  removeVideo (int index);
  int
  gamesInStock ();
  int
  videosInStock ();

  /**
   * Takes a vector of rental pointers, sorts them into games and videos.
   * Don't forget to delete all the rentals in the vector sent.
   */
  VideoStore (const std::vector<std::unique_ptr<Rental>>& rentals)
  {
    for (unsigned int i = 0; i < rentals.size (); i++)
      {
	addRental (rentals.at (i));
      }
  }

  const std::vector<Game>&
  getGames () const
  {
    return games;
  }

  const std::vector<Video>&
  getVideos () const
  {
    return videos;
  }

};

#endif /* VIDEOSTORE_H_ */
