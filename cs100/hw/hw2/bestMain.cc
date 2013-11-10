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
	Coins myBank ( 10, 10, 10, 10 );
	char option;
	while ( true )
	{
		std::cout << "============================== Welcome To The Bank ==============================" << std::endl;
		std::cout << "\tDeposit Change (d):" << std::endl
				  << "\tExtract Change (e):" << std::endl
				  << "\tPrint Balance (p):" << std::endl
				  << "\tQuit (q):" << std::endl << std::endl;
	
		std::cout << "Choose One Of The Options: ";
		std::cin >> option;
		std::cout << std::endl;
	
		switch ( option )
		{
			case 'd':
			{
				int q, d, n, p;
				std::cout << "===== Deposit =====" << std::endl;
				std::cout << "How Many Quarters: "; 
				std:: cin >> q;
				std::cout << "How Many Dimes: ";
				std::cin >> d;
				std::cout << "How Many Nickels: ";
				std::cin >> n;
				std::cout << "How Many Pennies: ";
				std::cin >> p;
				std::cout << std::endl;
				Coins deposit ( q, d, n, p );
				myBank.depositChange ( deposit );
			}
				break;
			
			case 'e':
			{
				int amount;
				std::cout << "===== Extracting =====" << std::endl;
				std::cout << "How Much Would You Like To Extract?: ";
				std::cin >> amount;
				std::cout << std::endl;
				if ( myBank.hasSufficientAmount ( amount ) )
				{
					myBank.extractChange ( amount ) ;
					std::cout << ".: Sussesful Extraction :." << std::endl << std::endl;
				}
				else
				{
					std::cout << ".: You Do Not Have Sufficient Funds :." << std::endl << std::endl;
				}
			}
				break;
				
			case 'p':
				std::cout << "===== Printing Account Info =====" <<std::endl;
				std::cout << "Total: " <<  myBank << std::endl;
				break;
	
			case 'q':
				exit(0);
	
			default:
				std::cout << ".: No Valid Option Chosen, Please Try Again :." << std::endl << std::endl;
	
		}
	}
	return 0;
}
