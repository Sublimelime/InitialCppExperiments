/*
 * Mainfile.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#include <memory>
#include <string>
#include <vector>

#include "Game.h"
#include "Rental.h"
#include "Video.h"
#include "VideoStore.h"

int
main ()
{
  using namespace std;
  vector<unique_ptr<Rental>> rentals;
  rentals.push_back (
      unique_ptr<Rental> (
	  new Game ("Overwatch", 40, GameRating::TEEN, "PC", 1)));


  rentals.push_back (
      unique_ptr<Rental> (
	  new Game ("Team Fortress 2", 0, GameRating::MATURE, "PC", 6)));


  rentals.push_back (
      unique_ptr<Rental> (
	  new Game ("Tic Tac Toe", 0, GameRating::EVERYONE, "Board", 2)));


  rentals.push_back (
      unique_ptr<Rental> (
	  new Game ("Connect 4", 10, GameRating::EVERYONE, "PC", 2)));


  vector<string> actors
    { "Frank", "Joe", "Bill" };
  rentals.push_back (
      unique_ptr<Rental> (
	  new Video ("SpongeBob", 15, VideoRating::G,
		     "Who lives in a pineapple under the sea", actors,
		     "Michal Bay", 200)));


  vector<string> actors2
    { "Jack", "Jane", "Freddy" };
  rentals.push_back (
      unique_ptr<Rental> (
	  new Video ("Initial D", 5, VideoRating::PG13, "Deja Vu", actors2,
		     "Drift", 200)));

  vector<string> actors3
    { "Sheldon", "Jane", "Robert" };
  rentals.push_back (
      unique_ptr<Rental> (
	  new Video ("The Big Bang", 10, VideoRating::R, "Buncha nerds",
		     actors3, "Unknown", 180)));

  vector<string> actors4
    { "Noah", "Hunter", "Christian" };
  rentals.push_back (
      unique_ptr<Rental> (
	  new Video ("Jumanji", 10, VideoRating::PG13,
		     "An unfortunate board game", actors4, "Unknown", 250)));


  VideoStore videoStore (rentals);

  return 0;
}
