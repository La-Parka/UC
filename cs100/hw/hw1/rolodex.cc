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


#include <stdio.h>
#include <iostream>
#include <fstream>
#include<stdlib.h>

class Rolodex 
{
	public:
		//Struct Card To Hold All The Values	
		struct Card
		{
			std::string fName,
			   			lName,
			  			 addr,
			   			phn;
			Card* next;

			//Constructor To Create A New Card
			Card ( std::string first, std::string last, std::string address, std::string phone)
			:fName (first), lName(last), addr (address), phn (phone)
			{
				next = NULL;
			}
		};
	private:
		//List of Cards
		Card* head;
		Card* tail;
		//If something is changed
		bool change;
		//SIze of the list
		unsigned size;
		//Function to change the value of "change"
		void changes();

	public:
		//Default Constructor
		Rolodex ();
		//Load Up The Menu
		void start ();
		//Inserts By Asking For Value Of Each Member Variable
		void p_insert();
		//Inserts With Pre-designated Parameters
		void insert (std::string, std::string, std::string, std::string);
		//Finds A Given Address
		void find ();
		//Deltes A GIven Address
		void delAddr ();
		//Prints All The Values In The Rolodex
		void print ();
		//Load FIles From A Given File
		void load ();
		//Save Rolodex To A File
		void save ();
		//Quits Program
		void quit ();
};
//Constructor======================================================================
Rolodex::Rolodex ()
:head (NULL), tail (NULL), size (0), change(false)
{}

//If a change was made======================================================================
void Rolodex::changes()
{
		change = true;
}

//Startup======================================================================
void Rolodex::start ()
{
	char option;
	do 
	{	
		std::cout << "\t===========  Welcome to the rodolex menu: =========== " << std::endl
				  << "\t Please choose from one of the following options" << std::endl;
		std:: cout << "\t|\t\ti - insert new address\t\t|" << std::endl
				   << "\t|\t\tf - find an address\t\t|" << std::endl
				   << "\t|\t\td - delete an address\t\t|" << std::endl
				   << "\t|\t\tp - print all\t\t\t|" << std::endl
				   << "\t|\t\tl - load address\t\t|" << std:: endl
				   << "\t|\t\ts - save adresses to file\t|" << std::endl
				   << "\t|\t\tq - quit program\t\t|" << std::endl;
	
		std::cout << "> ";
		std::cin >> option;
		std::cout << std::endl;
		switch (option)
		{
			case 'i': 
				p_insert ();
				break;
			case 'f':
				find();
				break;
			case 'd':
				delAddr();
				break;
			case 'p':
				print();
				break;
			case 'l':
				load();
				break;
			case 's':	
				save();
				break;
			case 'q':	
				quit();
				break;;
			default:	
				//If no valid option is choses ask user to try again
				std::cout << "\033c" << std::endl;
				std::cout << ".:Invalid Choice Please Try Again:." << std::endl << std::endl;
		}
	}
	while (true);
}

//Insert======================================================================
void Rolodex::insert (std::string first, std::string last, std::string address, std::string phone )
{
	Card* newCard = new Card( first,last,address,phone );

	//If Size Is 0 The Newly Inserteed Card Is The Head And Tail
	if ( size == 0 )
	{
		head = newCard;
		tail = head;
	}
	//If Last Name Is Less Than The Heads Last Name, The New Card Is The Head
	else
	{
		if ( head -> lName >= last )
		{
			newCard -> next = head;
			head = newCard;
		}
		//Going To Go Through The Entire List Of Cards To Find Were To Insert New Card
		else
		{
			Card* temp = head;
			for ( Card* lp = head -> next; temp != NULL; temp = temp -> next )
			{
				if ( lp )
				{
					if ( lp -> lName >= last )
					{
						temp -> next = newCard;
						newCard -> next = lp;
						break;
					}
					
				}
				else if ( temp == tail )
				{
					tail -> next = newCard;
					newCard -> next = NULL;
					tail = newCard;
				}
				if ( lp )
				{
					lp = lp -> next;
				}
			}
		}
	}
	//Size Is Incresed By One Because New Card Is Added
	size ++;
}

//Insert From Scratch======================================================================
void Rolodex::p_insert ( )
{
	std::cout << "\033c" << std::endl;
	changes();
	std::string first,
		   last,
		   address,
		   phone;

	//Asks User For Every Value In The Member Variables
	std::cout << "Enter first name: ";
	std::cin >> first;
	std::cout << std::endl;
	std::cin.ignore();

	std::cout << "Enter last name: ";
	getline (std::cin, last);
	std::cout << std::endl;

	std::cout << "Enter Address: ";
	getline (std::cin, address);
	std::cout << std::endl;

	std::cout << "Enter Phone: ";
	getline (std::cin, phone);
	std::cout << std::endl << std::endl;

	//Calls Insert To Insert New Card
	insert (first, last, address, phone);

}

//Search for Address====================================================================== 
void Rolodex::find()
{
	//CLears Screen To Be More Readable
	std::cout << "\033c" << std::endl;

	//If User Tries To Find A File But There Is None Error Appears
	if  ( size == 0 )
	{
		std::cout << "No Files In Rolodex" << std::endl << std::endl;
		return;
	}
	
	//Asks User For Last Name To Search For File
	std::string lst;
	std::cout << "Enter Last Name (CASE SENSITIVE): ";
	std::cin >> lst;
	std::cout << std::endl;

	Card* temp = head;

	while ( temp != NULL )
	{
		if ( temp -> lName == lst )
		{
			std::cout << "Adress Is: " << temp -> addr << std::endl << std::endl;
			return;
		}

		else
			temp = temp -> next;
	}
	//If Temmp Card Is Still Null There Was No File With Such Name
	if ( temp == NULL )
	{
		std::cout << "No File With " << lst << " Found!" << std::endl
				  << "Please Make Sure You Spelled It Correctly" << std::endl << std::endl;
	}

	return;
}

//Delete======================================================================
void Rolodex::delAddr ()
{
	//If No Files Cannot Delete 
	std::cout << "\033c" << std::endl;

	if ( size == 0 )
	{
		std::cout << "No Files In Rolodex" << std::endl <<std::endl;
		return;
	}

	std::string last;
	std::cout << "Please enter last name: ";
	std::cin >> last;
	Rolodex::Card* temp = head;
		if ( head -> lName == last )
		{
			delete head;
			head = temp -> next;
			size--;
			changes();
			return;
		}
		else
		{
			temp = head;
			for ( Card* lp = head -> next; temp != NULL; temp = temp -> next ) 
			{
				if ( lp )
				{
					if ( lp -> lName == last )
					{
						temp -> next = lp -> next;
						delete lp;
						size--;
						changes();
						return;
					}
				}
				if ( lp )
				{
					lp = lp -> next;
				}
			}
		}
		//If It Goes Through The Whole File And Does Not Find It Error Is Printed Out
	std::cout << "No Person With Last Name " << last << " found." << std::endl << std::endl;
	return;
}

//Print====================================================================== 
void Rolodex::print ()
{
	//If No Files Error Printed
	std::cout << "\033c" << std::endl;
	if (size == 0 )
	{
		std::cerr << "No Files To Print!" << std::endl << std::endl;
		return;
	}
	//Outputs Letter Of Last Name To Know Which Letter You Are On
	Card* temp = head;
	char beg = head -> lName.at(0);
	std::cout << "==============================_______" << static_cast<char>(toupper(beg)) << "________==================================" << std::endl;
	//int count = 0;
	while ( temp != NULL )
	{
		//If The First Letter Of The Last Name Is Different Then It OutPuts A New Letter
		if ( toupper( temp -> lName.at(0) ) != toupper ( beg ) )
		{
			beg = toupper( temp -> lName.at(0) );
			std::cout << "==============================_______" << static_cast<char>(toupper(beg)) << "________==================================" << std::endl;
		}
		//Outputs THe Contents Of A File
		std::cout << "First Name: " << temp -> fName << std::endl;		
		std::cout << "\tLast Name: " << temp -> lName << std::endl;
		std::cout << "\tAddress " << temp -> addr << std::endl;
		std::cout << "\tPhone:  " << temp -> phn << std::endl << std::endl ;
		temp = temp -> next;
	}
	std::cout << std::endl << std::endl;
}

//Load From File======================================================================
void Rolodex::load()
{
	std::string file;
	std::cout << "Enter File To Load From (include extension): ";
	std::cin >> file;
	std::ifstream myfile (file.c_str());
	//If No File With Such Name Is Found Retruns To The Menu
	if (!myfile.is_open())
	{
		std::cerr << "File Is Not Found" << std::endl << std::endl;
		return;
	}

	std::string first,
				last,
				addrss,
				phone,
				junk;
	//Goes Through File Reading In The Contents
	while (true)
	{
		getline (myfile, first );
		getline (myfile, last);
		getline (myfile, addrss);
		getline (myfile, phone);
		insert (first, last, addrss,phone);
		
		//If Getline Encounters Double-Slashes It Is The Terminating Of The File
		getline (myfile, junk);
		if (junk == "//")
			return;
	}
	myfile.close();
}

//Save To File====================================================================== 
void Rolodex::save()
{
	std::cout << "\033c" << std::endl;

	//If User Tries TO Save An Empty File Error
	if ( size == 0 )
	{
		std::cout << "Canot Save An Empty Rolodex" << std::endl << std::endl;
		return;
	}

	//Asks User What To Save The File To And What Type Of File
	std::string file;
	std::cout << "Save To File: (EXTENSION REQUIRED) ";
	std::cin >> file;
	std::cout << std::endl;

	std::ofstream myfile (file.c_str());
	if (!myfile.is_open())
	{
		std::cerr << "File Is Not Found" << std::endl << std::endl;
		return;
	}
	Card* temp = head;

	//Goes Through Rolodex And Adds Every Card To The File
	while (temp != NULL )
	{
		myfile << temp -> fName << std::endl;
		myfile << temp -> lName << std::endl;
		myfile << temp -> addr << std::endl;
		myfile << temp -> phn << std::endl;
		if (temp -> next == NULL)
		{
			myfile << "/" ;
		}
		myfile << "/" << std::endl;
		temp = temp -> next;
	}
	myfile.close();
}

//Quit Program======================================================================
void Rolodex::quit()
{
	char input;
	//If A Change Was Made Asks User If They Want To Save File 
	if (change)
	{
		do
		{
		std::cout << "Some changes were made do you want to save them? (y or n)? : ";
		std::cin >> input;
		std::cout << std::endl;
		if ( input == 'y' )
		{
			{
				save();
			}
			change = false;
			exit(0);
		}
		else if ( input == 'n')
		{
			exit(0);
		}
			//Outputs Error If Option Other Than N or Y Is Inputed
			std::cout << "Invalid option" << std::endl << std::endl;
		}
		while ( input != 'y' || input != 'n');
	}
	exit(0);
}
	
//============================================================================================
int main ()
{
	Rolodex program ;
	program.start();
	return 0;
}
