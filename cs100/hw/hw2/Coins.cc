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

//Parameterizec Constructor=================================== 
Coins::Coins ( int q, int d, int n, int p )
:quarters (q), dimes(d), nickels (n), pennies (p)
{}

//Deposit====================================================================== 
void Coins::depositChange ( Coins c )
{
	quarters += c.quarters;
	dimes += c.dimes;
	nickels += c.nickels;
	pennies += c.pennies;
}

//Check To See If Sufficient Funds====================================================================== 
bool Coins::hasSufficientAmount ( int amount )
{
	int q$,
		d$,
		n$,
		total;
	q$ = quarters * CENTS_PER_QUARTER;
	d$ = dimes * CENTS_PER_DIME;
	n$ = nickels * CENTS_PER_NICKEL;
	total = q$ + d$ + n$ + pennies;
	if ( amount < 0 )
		return false;

	if ( total < amount )
		return false;

	return true;
}

//Extract====================================================================== 
Coins Coins::extractChange ( int amount )
{

	if ( amount < 0 )
	{
		Coins trash ( 0, 0, 0, 0 );
		std::cout << ".: Cannot Extract Given Value :." << std:: endl;
		return trash;
	}
	int temp = amount;
	int q_c = 0,
		d_c = 0,
		n_c = 0,
		p_c = 0;

	for ( unsigned i = 0; ; i++ )
	{
		if ( temp == 0 )
		{
			Coins extracted ( q_c, d_c, n_c, p_c);
			//std::cout << extracted << std::endl;
			return extracted;
		}
		if ( temp - CENTS_PER_QUARTER >= 0 && quarters > 0 )
		{
			temp -= CENTS_PER_QUARTER;
			quarters--;
			q_c += 1;
		}
		else if ( temp - CENTS_PER_DIME >= 0 && dimes > 0 )
		{
			temp -= CENTS_PER_DIME;
			dimes--;
			d_c += 1;
		}
		else if ( temp - CENTS_PER_NICKEL >= 0 && nickels > 0 )
		{
			temp -= CENTS_PER_NICKEL;
			nickels--;
			n_c += 1;
		}
		else
		{
			temp -= 1;
			pennies--;
			p_c += 1;
		}

	}
}

//Print====================================================================== 
void Coins::print ( std::ostream & out )
{
	std::cout << quarters * CENTS_PER_QUARTER + dimes * CENTS_PER_DIME + nickels * CENTS_PER_NICKEL + pennies << std::endl;

	std::cout << "\t\tQuarters: " << quarters << std::endl
			  << "\t\tDimes: " << dimes << std::endl
			  << "\t\tNickel: " << nickels << std::endl
			  << "\t\tPennies: " << pennies << std::endl;
}

//Destructor====================================================================== 
//Coins::~Coins()
//{
//	delete quarters;
//}

//Overloaded << operator====================================================================== 
std::ostream & operator << ( std::ostream & out, Coins & c )
{
	c.print ( out );
	return out;
}
