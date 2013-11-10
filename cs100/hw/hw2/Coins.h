/*
* Course: CS 100 Fall 2013
*
* First Name: Marco
* Last Name: Tobon
* Username: mtobo001
* email address: mtobo001@ucr.edu
*
*
* Assignment: “Homework #2”
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

//Coins.h
#ifndef _COINS_H_
#define _COINS_H

#include <iostream>
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
	public:
		Coins ( int q, int d, int n, int p );
		void depositChange ( Coins c );
		bool hasSufficientAmount ( int amount );
		Coins extractChange ( int amount );
		void print ( std::ostream & out );
//		~Coins();
	private:
		int quarters, dimes, nickels, pennies;
};
std::ostream & operator << ( std::ostream & out, Coins & c );

#endif

