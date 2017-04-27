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

class Video : public Rental
{

  std::string description, director;
  int minutes;
  std::string ratingLocalized;
  VideoRating rating;
  std::vector<std::string> leadingActors;

public:
  Video (std::string title, double cost, VideoRating rating,
	 std::string description, std::vector<std::string> leadingActors,
	 std::string director, int minutes) :
      Rental (title, cost), rating (rating), description (description), minutes (
	  minutes), leadingActors (leadingActors), director (director)
  {
    //set the printable variable off of the rating, so it can be printed
    switch (static_cast<int> (rating))
      {
      case 0:
	ratingLocalized = "G";
	break;
      case 1:
	ratingLocalized = "PG";
	break;
      case 2:
	ratingLocalized = "PG13";
	break;
      case 3:
	ratingLocalized = "R";
	break;
      }
  }

  virtual std::string
  toString () const override
  {
    std::string temp = "\nVideo: \nTitle: " + title + "\nCost: "
	+ std::to_string (cost) + "\nRating: " + ratingLocalized
	+ "\nDirector: " + director + "\nMinutes:" + std::to_string (minutes)
	+ "\nDesc: " + description + "\nLeading actors: ";
    for (unsigned int i = 0; i < leadingActors.size (); i++)
      {
	temp += leadingActors.at (i);
	temp += ", ";
      }
    return temp;
  }

  const std::string&
  getDescription () const
  {
    return description;
  }

  const std::string&
  getDirector () const
  {
    return director;
  }

  const int
  getMinutes () const
  {
    return minutes;
  }

  const std::string&
  getRatingLocalized () const
  {
    return ratingLocalized;
  }

  const std::vector<std::string>&
  getLeadingActors () const
  {
    return leadingActors;
  }
};

#endif /* VIDEO_H_ */
