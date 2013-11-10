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

#include "Coins.h"
#include <iostream>

const int CENTS_FOR_CANDYBAR = 482;

int main ()
{
	//Creates a Coins object called 'pocket'
	Coins pocket ( 100, 10, 10, 10 );
	std::cout << "I started with " << pocket << "in my pocket" << std::endl << std::endl;

	//Creates a Coins Object called payforcandy and initializes it.
	Coins payForCandy = pocket.extractChange ( CENTS_FOR_CANDYBAR );
	std::cout << "I bough a candybar for " << CENTS_FOR_CANDYBAR << " cents using " << payForCandy << std::endl;
	
	std::cout << "I have " << pocket << "left in my pocket" << std::endl << std::endl;
	return 0;
}
