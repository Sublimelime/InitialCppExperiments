/*
 * VideoStore.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: othscs253
 */

#include "VideoStore.h"

#include <iterator>
#include <iostream>

/*
 * adds a rental pointer to the appropriate vector for it's type.
 */
void
VideoStore::addRental (const std::unique_ptr<Rental>& r)
{
  if (dynamic_cast<Game*> (r.get ()) != nullptr)
    { //the rental is a game
      Game* game = dynamic_cast<Game*> (r.get ());
      games.push_back (*game); //add the game to the list of games
    }
  else if (dynamic_cast<Video*> (r.get ()) != nullptr)
    {
      Video* video = dynamic_cast<Video*> (r.get ());
      videos.push_back (*video); //add the video to the list of videos
    }
  else
    {
      throw "Pointer is not a game or Video.";
    }
}

int
VideoStore::gamesInStock ()
{
  if (games.empty ())
    {
      return 0;
    }
  int counter
    { 0 };
  for (unsigned int i = 0; i < games.size (); i++)
    {
      if (!games.at (i).isRented ())
	{
	  counter++;
	}
    }
  return counter;
}
int
VideoStore::videosInStock ()
{
  if (videos.empty ())
    {
      return 0;
    }
  int counter
    { 0 };
  for (unsigned int i = 0; i < videos.size (); i++)
    {
      if (!videos.at (i).isRented ())
	{
	  counter++;
	}
    }
  return counter;
}

void
VideoStore::removeGame (int index)
{
  if (index != 0)
    {
      index--;
    }

  games.erase (games.begin () + index);
}

void
VideoStore::removeVideo (int index)
{
  if (index != 0)
    {
      index--;
    }

  videos.erase (videos.begin () + index);

}

void
VideoStore::listGamesInStock ()
{
  if (gamesInStock () == 0)
    {
      return;
    }
  int counter (1);
  for (unsigned int i = 0; i < games.size (); i++)
    {
      if (!games.at (i).isRented ())
	{
	  std::cout << counter << '\n';
	  std::cout << games.at (i);
	  std::cout << "\n";
	  counter++;
	}
    }
}

void
VideoStore::listVideosInStock ()
{
  if (videosInStock () == 0)
    {
      return;
    }
  int counter (1);
  for (unsigned int i = 0; i < videos.size (); i++)
    {
      if (!videos.at (i).isRented ())
	{
	  std::cout << counter << '\n';
	  std::cout << videos.at (i);
	  std::cout << "\n";
	  counter++;
	}
    }
}
