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
#include "Mainfile.h"
#include "Rental.h"
#include "Video.h"
#include "VideoStore.h"

int
main ()
{
  using namespace std;
  vector<unique_ptr<Rental>> rentals;
  vector<Game> rentedGames;
  vector<Video> rentedVideos;

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

  do
    {
      cout << "1. Rent Game \n2. Rent Video \n3. Checkout\n";
      int action;
      cin >> action;
      if (!checkCin () || action < 1 || action > 3)
	{
	  continue;
	}

      if (action == 1)
	{
	  //rent game
	  if (videoStore.gamesInStock () != 0)
	    {
	      cout << "Games: -------------\n";
	      videoStore.listGamesInStock ();

	      cout
		  << "Please enter the number of the game you wish to rent. Enter 6 to cancel.\n";
	      int rentNum;
	      cin >> rentNum;
	      if (!checkCin ())
		{
		  continue;
		}

	      rentNum--;
	      if (rentNum != 5)
		{
		  rentedGames.push_back (videoStore.getGames ().at (rentNum));
		  videoStore.removeGame (rentNum);
		}
	    }
	  else
	    {
	      cout << "Out of games.\n";
	    }
	}
      else if (action == 2)
	{
	  //rent video
	  if (videoStore.videosInStock () != 0)
	    {
	      cout << "Videos: ------------\n";
	      videoStore.listVideosInStock ();
	      cout
		  << "\nPlease enter the number of the video you wish to rent. Enter 6 to cancel.\n";
	      int rentNum;
	      cin >> rentNum;
	      if (!checkCin ())
		{
		  continue;
		}

	      rentNum--;
	      if (rentNum != 5)
		{
		  rentedVideos.push_back (videoStore.getVideos ().at (rentNum));
		  videoStore.removeVideo (rentNum);
		}
	    }
	  else
	    {
	      cout << "Out of videos\n";
	    }
	}
      else if (action == 3)
	{
	  //checkout
	  double subTotal = 0;

	  for (Game rentedGame : rentedGames)
	    {
	      subTotal += rentedGame.getCost ();
	    }

	  for (Video rentedVideo : rentedVideos)
	    {
	      subTotal += rentedVideo.getCost ();
	    }
	  //print arrays
	  for (Game rentedGame : rentedGames)
	    {
	      cout
		  << "Rented Game: " + rentedGame.getTitle () + ", Cost: "
		      + to_string (rentedGame.getCost ()) + "\n";

	    }
	  for (Video rentedVideo : rentedVideos)
	    {
	      cout
		  << "Rented Video: " + rentedVideo.getTitle () + ", Cost: "
		      + to_string (rentedVideo.getCost ()) + "\n";

	    }
	  //get subtotal
	  cout << "Subtotal: $" + to_string (subTotal) + "\n";
	  double tax = (subTotal * 0.0825); //tax in texas is 8.25%
	  double finalTotal = subTotal + tax;
	  cout << "Tax: $" + to_string (tax) + "\n";
	  cout << "Final Total: $" + to_string (finalTotal) + "\n";
	  return 0;
	}

    }
  while (true);

  return 0;
}

bool
checkCin ()
{
  using namespace std;
  if (cin.fail ())
    {
      cin.clear ();
      cout << "Invalid input.\n";
      cin.ignore (12344557, '\n');
      return false;
    }
  cin.ignore (12344557, '\n');
  return true;
}
