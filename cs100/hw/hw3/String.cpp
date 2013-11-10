/*
* Course: CS 100 Fall 2013
*
* First Name: Marco
* Last Name: Tobon
* Username: mtobo001
* email address: mtobo001@ucr.edu
*
*
* Assignment: “Homework #3”
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
:buf ('\0'), len (0)
{
	len = length (s);
	//std::cout << len << std::endl;
	buf = new char  [len + 1 ];
	unsigned i =0;
	for ( i = 0 ; s[i] != '\0'; i++ )
	{
		buf [i]  = s [i];
	}
	buf [i] = '\0';
}

//Constructor from a string====================================================================== 
String::String ( const String & s )
:buf ( NULL ), len ( s.len )
{
	buf = new char [len];
	unsigned i = 0;
	for ( i = 0; i < s.len; i++ )
	{
		buf [i] = s.buf [i];
	}
	buf [i] = '\0';
}

//Overloaded Assignment Operator====================================================================== 
String String::operator = ( const String & s )
{
	len = s.len;
	buf = new char [len];
	unsigned i = 0;
	for ( i = 0; s.buf[i] != '\0'; i++)
	{
		buf [i] = s.buf [i];
	}
	buf [i] = '\0';

	return *this;

}

//Returns char at pos====================================================================== 
char & String::operator [] ( int index )
{
	if ( this -> inBounds ( index ) )
	{
		return buf [index];
	}
	
	std::cerr << std::endl <<  "\tInvalid Index Either Negaive Or Greater Than The Size Of String" << std::endl;
	return buf[index];
}

//Returns Size====================================================================== 
int String::size()
{
	return len;
}

//Reverses string====================================================================== 
String String::reverse ()// does not modify this String
{
	String rev;
	rev.len = len;
	rev.buf = new char [len];
	unsigned i = 0;
	unsigned j = 0;
	for ( i = 0, j = len -1 ; this -> buf [i] != '\0'; i++, j-- )
	{
		rev.buf [i] = this -> buf [j];
	}
	return rev;
}

//Return Index Of Given Char====================================================================== 
int String::indexOf ( char c )
{
	unsigned i = 0;
	for ( i = 0; this -> buf [i] != '\0'; i++ )
	{
		if ( this -> buf [i] == c )
			return i;
	}
	std::cerr << std::endl << "\tCharacter " << c << " Not Found" << std::endl;
	return -1;
}

//First index of pattern====================================================================== 
int String::indexOf ( String pattern )
{
	unsigned i = 0;
	unsigned j = 0;
	unsigned g = 0;
	int length = pattern.len;
	for ( i = 0; this -> buf [i] != '\0'; i++ )
	{
		if ( this -> buf [i] == pattern [g] )
		{
			length --;
			 j = i;
			 for ( i += 1, g += 1; this -> buf [i] != '\0' || pattern.buf [g] != '\0'; i++, g++ )
			 {
				 if ( this -> buf [i] == pattern.buf [g] )
				 {
					 length --;
					 if ( length == 0 )
					 {
						 return j;
					 }
				 }
			 }
			g = 0;
			i = j;
			length = pattern.len;
		}
	}
	std::cout << "Pattern Not Found" << std::endl;
	return -1;
}

//Check If Strings Are Equal====================================================================== 
bool String::operator == ( String s )
{
	if ( this -> len != s.len )
	{
		return false;
	}
	for ( unsigned i = 0; this -> buf [i] != '\0'; i++ )
	{
		if ( this -> buf [i] != s.buf [i] )
			return false;
	}
	return true;
}

//Check If Both Strings Are Not Equal====================================================================== 
bool String::operator != ( String s )
{
	if ( this -> len != s.len )
		return true;
	for ( unsigned i = 0; this -> buf [i] != '\0'; i++ )
	{
		if ( this -> buf [i] != s.buf [i] )
			return true;
	}
		return false;
}

//Checks If Implicit String Is Greater======================================================================
bool String::operator > ( String s )
{
	int c = 0;
	if ( s.len > this -> len )
	{
		for ( unsigned i = 0; this -> buf [i] != '\0'; i ++ )
		{
			if ( this -> buf [i] == s.buf [i] )
				c++;
		 	 else if ( this -> buf [i] < s.buf [i] )
				return false;
			else 
				return true;
		}
	}
	else
	{
		for ( unsigned i = 0; s.buf [i] != '\0'; i++ )
		{
			if ( this -> buf [i] == s.buf [i] )
				c++;
			else if ( this -> buf [i] < s.buf [i] )
				return false;
			else
				return true;
		}
	}
	if ( c == len )
		return false;
	
	return true;
 
}

//Checks If Implicit Parameter Is Lesser====================================================================== 
bool String::operator < ( String s )
{
	int c = 0;
	if ( s.len > this -> len )
	{
		for ( unsigned i = 0; this -> buf [i] != '\0'; i ++ )
		{
			if ( this -> buf [i] == s.buf [i] )
				c++;
			else if ( this -> buf [i] > s.buf [i] )
				return false;
			else
				return true;
		}
	}
	
	else
	{
		for ( unsigned i = 0; s.buf [i] != '\0'; i++ )
		{
			if ( this -> buf [i] == s.buf [i] )
				c++;
			else if ( this -> buf [i] > s.buf [i] )
				return false;
			else
				return true;
		}
	}
	
	if ( c == len )
		return false;
	
	return true;
}

//Checks If Implicit Paramter Is Less Than Or Equal To=================================== 
bool String::operator <= ( String s )
{
	if ( s.len > this -> len )
	{
		for ( unsigned i = 0; this -> buf [i] != '\0'; i ++ )
		{
			if ( this -> buf [i] > s.buf [i] )
				return false;
			else if ( this -> buf [i] < s.buf [i] )
				return true;
		}
	}
	
	else
	{
		for ( unsigned i = 0; s.buf [i] != '\0'; i++ )
		{
			if ( this -> buf [i] > s.buf [i] )
				return false;
			else if ( this -> buf [i] < s.buf [i] )
				return true;
		}
	}
	
	return true;
}

//Checks If Implicit Parameter Is Greater Than Or Equal=================================== 
bool String::operator >= ( String s )
{
	if ( s.len > this -> len )
	{
		for ( unsigned i = 0; this -> buf [i] != '\0'; i ++ )
		{
			if ( this -> buf [i] < s.buf [i] )
				return false;
			else if ( this -> buf [i] > s.buf [i] )
				return true;
		}
	}
	
	else
	{
		for ( unsigned i = 0; s.buf [i] != '\0'; i++ )
		{
			if ( this -> buf [i] < s.buf [i] )
				return false;
			else if ( this -> buf [i] > s.buf [i] )
				return true;
		}
	}
	
	return true;
}

//Adds Implicit String And S To Return Result================================================================ 
String String::operator + ( String s )
{
	String result;
	result.len = len + s.len + 1;
	result.buf = new char [len];
	unsigned i = 0;
	for ( i = 0; this -> buf [i] != '\0'; i++ )
	{
		result.buf [i] = this -> buf [i];
	}
	result.buf [i] = ' ';
	int g = 0;
	for ( i += 1; s.buf [g] != '\0'; i++, g++ )
	{
		result.buf [i] = s.buf [g];
	}
	result.buf [i] = '\0';
	return result;
}

//Adds S To End Of This====================================================================== 
String String::operator += ( String s )
{
	String concat (buf);
	len = concat.len + s.len + 1;
	buf = new char [len];
	unsigned i = 0;
	for ( i = 0; concat.buf [i] != '\0'; i++ )
	{
		buf [i] = concat.buf [i];
	}
	buf [i] = ' ';
	int g = 0;
	for ( i += 1; s.buf [g] != '\0'; i++, g++ )
	{
		buf [i] = s.buf [g];
	}
	buf [i] = '\0';
	return *this;
}

//Prints String====================================================================== 
void String::print ( std::ostream & out )
{
	for ( int i = 0; i < len; i++ )
	{
		out << buf [i];
	}
	//	out << buf;
}

//Reads In A String From Input====================================================================== 
void String::read ( std::istream & in )
{

	std::string inp;

	in >> inp;
	len = inp.size();
	buf = new char [len + 1];
	unsigned i = 0;
	for ( i = 0; inp [i] != '\0'; i++ )
	{
		buf [i] = inp [i];
	}
	buf [i] = '\0';
}

//Gets Size Of Char *====================================================================== 
unsigned String::length ( const char * x )
{
	unsigned sz = 0;
	for ( unsigned i = 0; x[i] != '\0'; i++ )
	{
		sz++;
	}
	return sz;
}

//Destructor====================================================================== 
String::~String ()
{
	delete buf;	
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
