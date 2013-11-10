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


#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>
#include <stdlib.h>
#define STACK_CAPACITY 1000

class Stack
{
	private:
		char* newStack;
		unsigned size;
	public:
		Stack ();
		void push (char c);
		char pop ();
		char top();
		bool isEmpty();
		~Stack ();
};

//Constructor===========================================================
Stack::Stack()
:newStack (new char [0]), size (0)
{}

//Adding Element====================================================================== 
void Stack::push (char c)
{
	if ( size < STACK_CAPACITY )
	{
		newStack [size] = c;
		size ++;
	}
	else
	{
		std::cerr<< "Cannot add element goes over STACK_CAPACITY of: " << STACK_CAPACITY << "!" << std::endl;
		exit(1);
	}
}

//Removing Element======================================================================
char Stack::pop ()
{
	char temp = '\0';
//	std::cout << size << "!" << std::endl;
	if (size == 0)
	{
		std::cerr << "Cannot pop element because there are no elements" << std::endl;
		exit(1);
	}

	temp = newStack[size -1];
	size--;
	return temp;
}

//Top Element====================================================================== 
char Stack::top()
{
	return newStack [size -1];
}

//CHeck IF Empty======================================================================
bool Stack::isEmpty()
{
	if (size > 0)
		return false;
	return true;
}
	
//Destructor======================================================================
Stack::~Stack ()
{
	delete []newStack;
}

#endif


