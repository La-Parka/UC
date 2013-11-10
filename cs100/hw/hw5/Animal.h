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

#include <iostream>

class Animal
{
	protected:
		std::string name;
	
	public:
		virtual void sound ()  = 0;
		Animal ( std::string a_name = "" )
		:name (a_name)
		{}
};

//First Derived Class====================================================================== 
class Dog: public Animal
{
	public:
		Dog ( std::string d_name = "" )
		:Animal (d_name)
		{}

		virtual void sound ()
		{
			std::cout << "  " << name << " The Dog Goes: " << std::endl;
			std::cout << "\tWoof Woof" << std::endl;
		}
};
	
//Second Derived Class======================================================================
class Cat: public Animal
{
	public:
		Cat ( std::string c_name = "" )
		:Animal (c_name)
		{}

		virtual void sound ()
		{
			std::cout << "  " << name << " The Cat Goes: " << std::endl;
			std::cout << "\tMeow Meow" << std::endl;
		}

};

//Third DErived Class======================================================================
class Rooster: public Animal
{
	public:
		Rooster ( std::string r_name = "" )
		:Animal (r_name)
		{}

		virtual void sound ()
		{
			std::cout << "  " << name << " The Rooster Goes: " << std::endl;
			std::cout << "\tCock-A-Doodle-Doo" << std::endl;
		}
};
