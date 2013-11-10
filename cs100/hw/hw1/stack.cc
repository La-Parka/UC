/*
* Course: CS 100 Fall 2013
*
* First Name: Marco
* Last Name: TObon
* Username: mtobo001
* email address: mtobo001@ucr.edu
*
*
* Assignment: “Homework #1”
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/


#include "stack.h"
#include <iostream>

int main ()
{
	Stack word;
	std::string input;
	while( std::cin >> input)
	{
		std::cout << std::endl;

		for (unsigned i =0; i < input.size(); i++)
		{
			word.push( input.at(i) );
		}

		if (input.size() > 0)
			std::cout << "Output: " << std::endl;

		
		while ( !word.isEmpty() )
		{
			std::cout << word.pop();
		}
		
	
		std::cout << std::endl << std::endl;

	}
	return 0;
}
