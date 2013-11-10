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
#ifndef _STRING_H_
#define _STRING_H_
#include <iostream>

class String
{
	public:
		//Both Constructors should construct
		//This string from the parameter s
		String ( const char * s = "" );
		String ( const String & s );
		String operator = ( const String & s );
		char & operator [] ( int index );
		int size ();
		String reverse ();// does not modify this String
		int indexOf ( char C );
		int indexOf ( String pattern );
		bool operator == ( String s );
		bool operator != ( String s );
		bool operator > ( String s );
		bool operator < ( String s );
		bool operator <= ( String s );
		bool operator >= ( String s );
		//COncatenates this and s to return result
		String operator + ( String s );
		//Concatenates s onto end of this
		String operator += ( String s );
		void print ( std::ostream & out );
		void read ( std::istream & in );
		~String ();

	private:
		bool inBounds ( int i )
		{
			return i >= 0 && i < len;
		}
		unsigned length ( const char * x );
		char * buf;
		int len; //THe number of chars in buf
};

std::ostream & operator << ( std::ostream & out, String str );
std::istream & operator >> ( std::istream & in, String & str );
#endif
