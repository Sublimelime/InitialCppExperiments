/*
 * Mainfile.cpp
 *
 * This is a simple program that takes a number and attempts to translate it into english.
 * For example, 254 would print as "Two hundred and fifty-four".
 *
 *  Created on: Apr 28, 2017
 *      Author: noah
 */

#include "Dictionary.h"
#include "Mainfile.h"
#include <string>
#include <iostream>

int
main ()
{
  using namespace std;

  cout
      << "Please enter a number to print in English. Do not include commas or spaces.\n";

  long input;
  cin >> input;
  if (!checkCin ())
    {
      cerr << "Invalid input, terminating.\n";
      return 1;
    }
  std::string inputString = to_string (input);



  return 0;
}

//takes a char of an int, such as '2', and returns the int it represents, eg 2.
int
charIntToInt (char c)
{
  return c - '0';
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
