/*
* Course: CS 100 Fall 2013
*
* First Name: Marco
* Last Name: Tobon
* Username: mtobo001
* email address: mtobo001@ucr.edu
*
*
* Assignment: “Homework #5”
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include "Animal.h"
#include <iostream>
#include <list>

void poly ( std::list <Animal*> farm )
{
	std::cout << "In The Farm You Can Hear A Lot Of Animal Noises" << std::endl << std::endl;

	while ( !farm.empty() )
	{
		(farm.front()) -> sound ();
		farm.pop_front();
	}
}

int main ()
{
	Dog perrito ("Scooby-Doo");
	Cat gato ("Tom");
	Rooster gallo ("Foghorn Leghorn");
	
	std::list <Animal*> farm;
	farm.push_back (&perrito);
	farm.push_back (&gato);
	farm.push_back (&gallo);
	
	poly ( farm );
}
