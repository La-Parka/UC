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

int main ()
{
	//Bag of Chips
	Coins pocket ( 5, 3, 6, 8 );
	Coins piggyBank ( 50, 50, 50 , 50 );

	int bagChips = 68;

//Initial Starting
	std::cout << "============================== Initial ==============================" << std::endl; 
	std::cout << "I have " << pocket << "in my pocket" << std::endl << std::endl
			  << "And in my piggyBank " << piggyBank << std::endl;

//Buying Chips
	std::cout << "============================== Buying Chips  ==============================" << std::endl;
	std::cout << "I bought a bag of chips for " << bagChips << std::endl << std::endl;
	pocket.extractChange ( bagChips );
	std::cout << "Now I have " << pocket << "in my pocket" << std::endl << std::endl;
	
//Transfer
	std::cout << "============================== Transfer ==============================" << std::endl;
	Coins dep = piggyBank.extractChange ( 237 );
	std::cout << "I deposited " << dep << std::endl;
	pocket.depositChange( dep );
	std::cout << "My pocket now contains " << pocket << std::endl;
	
//Vacuum
	std::cout << "============================== Vacuum ==============================" << std::endl;
	Coins vacuum ( 2, 3, 7, 15 );
	std::cout << "While vacumming I found " << vacuum << std::endl;
	pocket.depositChange ( vacuum );
	std::cout << "Now I have " << pocket << "in my pocket" << std::endl << std::endl;
	return 0;
}
