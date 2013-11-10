/*
* Course: CS 100 Fall 2013
*
* First Name: Marco
* Last Name: Tobon
* Username: mtobo001
* email address: mtobo001@ucr.edu
*
*
* Assignment: “Homework #4”
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#include <iostream>
#include "String.h"

//Constructor from char pointer====================================================================== 
String::String ( const char * s  )
:head (NULL)
{
	unsigned i =0;
	ListNode * temp = head;
	if ( s[0] == '\0' )
	{
		//head = new ListNode ( , NULL );
		return;
	}
	for ( i = 0 ; s[i] != '\0'; i++ )
	{
		if ( head == NULL )
			head = new ListNode ( s[i], NULL );
		else
		{
			temp = head;
			while ( temp -> next )
			{
				temp = temp -> next;
			}
			temp -> next = new ListNode ( s[i], NULL );
		}
	}
}

//Constructor from a string====================================================================== 
String::String ( const String & s )
:head (NULL)
{
	if ( s.head == NULL )
		return;

	head = new ListNode ( (s.head) -> info, NULL );
	ListNode * temp = head;
	ListNode * temp2 = s.head;
	while ( temp2 -> next )
	{
		temp -> next = new ListNode ( (temp2 -> next) -> info, NULL );
		temp2 = temp2 -> next;
		temp = temp -> next;
	}

}

//Overloaded Assignment Operator====================================================================== 
String String::operator = ( const String & s )
{
	//std::cout << (*this) << std::endl;
	//std::cout << "OP ="<< std::endl;
	if ( (s.head) == NULL)
	{
		(*this).~String();
		head = new ListNode ( '\0', NULL);;
	}
	else
	{
		head = new ListNode ( (s.head) -> info, NULL);
		ListNode * temp = NULL;
		ListNode * temp2 = s.head -> next;
		while ( temp2 )
		{
			temp = head;
			while ( temp -> next)
			{
				//std::cout << temp -> info << std::endl;
				temp = temp -> next;
			}
			//std::cout << std::endl;
			temp -> next = new ListNode ( temp2 -> info, NULL );
			//std::cout << "temp info: " << temp -> info << std::endl;
			temp2 = temp2 -> next;
		}
	}
	return *this;
}

//Returns char at pos====================================================================== 
char & String::operator [] ( int index )
{
	ListNode * temp = head;
	if ( this -> inBounds ( index ) )
	{
		for ( index; index > -1; index -- )
		{
			if ( index == 0 )
				return temp -> info;
			temp = temp -> next;
		}
	}
	
	std::cerr << std::endl <<  "\tInvalid Index Either Negaive Or Greater Than The Size Of String" << std::endl;
	return temp -> info;
}

//Returns Size====================================================================== 
int String::length() const
{
	int counter = 0;
	ListNode * temp = head;
	while ( temp )
	{
		counter += 1;
		temp = temp -> next;
	}
	return counter;
}

//Return Index Of Given Char====================================================================== 
int String::indexOf ( char c )
{
	int counter = 0;
	ListNode * temp = head;
	while ( temp -> next )
	{
		if ( temp -> info == c )
			return counter;
		counter += 1;
		temp = temp -> next;
	}

	std::cerr << std::endl << "\tCharacter " << c << " Not Found" << std::endl;
	return -1;
}

//Check If Strings Are Equal====================================================================== 
bool String::operator == ( String s )
{
	if ( (*this).length () != s.length () )
	{
		return false;
	}
	ListNode * temp = head; 
	ListNode * temp2 = s.head;
	while ( temp -> next )
	{
		if ( temp -> info != temp2 -> info )
			return false;
		temp = temp -> next;
		temp2 = temp2 -> next;
	}
	return true;
}

//Adds Implicit String And S To Return Result================================================================ 
String String::operator + ( String s )
{
	String result;
	ListNode * r_temp = NULL;
	ListNode * temp = s.head;
	result  = (*this);
	if ( s.head == NULL )
		return result;
	else if ( result.head == NULL)
	{
		result = s;
		return result;
	}

	r_temp = result.head;
	while (r_temp -> next)
	{
		r_temp = r_temp -> next;
	}
	r_temp -> next = new ListNode (' ',NULL);
	while ( temp ) 
	{
		r_temp = result.head;
		while ( r_temp -> next)
			r_temp = r_temp -> next;
		r_temp -> next = new ListNode ( temp -> info, NULL);
		temp = temp -> next;
	}
	return result;
}

//Adds S To End Of This====================================================================== 
String String::operator += ( String s )
{
	ListNode * r_temp = NULL;
	ListNode * temp = s.head;
	if ( s.head == NULL )
		return *this;
	else if ( head == NULL)
	{
		*this  = s;
		return *this;
	}

	r_temp = head;
	while (r_temp -> next)
	{
		r_temp = r_temp -> next;
	}
	r_temp -> next = new ListNode (' ',NULL);
	while ( temp ) 
	{
		r_temp = head;
		while ( r_temp -> next)
			r_temp = r_temp -> next;
		r_temp -> next = new ListNode ( temp -> info, NULL);
		temp = temp -> next;
	}
	return *this;
}

//Prints String====================================================================== 
void String::print ( std::ostream & out )
{
	if ( head == NULL )
	{
		out << "";
		return;
	}
	ListNode * temp = head;
	while ( temp )
	{
		out << temp -> info;
		temp = temp -> next;
	}
}

//Reads In A String From Input====================================================================== 
void String::read ( std::istream & in )
{

	std::string inp;

	in >> inp;
	*this = (inp.c_str());
}

//Destructor====================================================================== 
String::~String ()
{
	ListNode * temp = head;
	for ( ListNode * cur = head; cur != NULL;)
	{
		//std::cout << "Cur: " << cur -> info << std::endl;
		temp = cur -> next;
		delete cur;
		cur = temp;
	}
}

//Overloaded Inserter Op====================================================================== 
std::ostream & operator << ( std::ostream & out, String str )
{
	str.print ( out );
	return out;
}

//Overloaded Extarctor Op====================================================================== 
std::istream & operator >> ( std::istream & in, String & str )
{
	str.read ( in );
	return in;
}

