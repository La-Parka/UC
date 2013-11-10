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

#include <iostream>
#include "String.h"

int main ()
{
	//Parameterized Construct//////////////////////////////////////////
	std::cout << "===== Param Construct =================" << std::endl;
	char x [] = "Hello";
	String x_1  (x);
	std::cout << "\tx: " << x_1
			  << std::endl;

	char y [] = "World";
	String y_1 (y);
	std::cout << "\ty: " << y_1
			  << std::endl;

	String z_1 ("");
	std::cout << "\tz: " << z_1
			  << std::endl << std::endl;

	//Size/////////////////////////////////////////////////////////////
	std::cout << "===== Size ===========================" << std::endl;
	std::cout << "\tx: " << x_1.length() << std::endl
			  << "\ty: " << y_1.length() << std::endl 
			  << "\tz: " << z_1.length() << std::endl
			  << std::endl;


	//Assignement Op//////////////////////////////////////////////////
	std::cout << "===== Assignemnt Op =================" << std::endl;
	x_1 = y_1;
	std::cout << "\tx = y" << std::endl
			  << "\tx: " <<  x_1 << std::endl;

	y_1 = z_1;
	std::cout << "\ty = z" << std::endl
			  << "\ty: " << y_1 << std::endl
			  << std::endl;

	//[] OPERATOR/////////////////////////////////////////////////////
	std::cout << "===== [] OP =========================" << std::endl;
	std::cout << "IN X: " << x_1 << std::endl;
	std::cout << "\tx_1[2]: " << x_1 [2] << std::endl;
	std::cout << "\tx_1[3]: " << x_1 [3] << std::endl; 
	std::cout << "\tx_1[4]: " << x_1 [4] << std::endl;
	std::cout << "\tx_1[5]: " << x_1 [5] << std::endl; 
	
	std::cout << "IN Y: " << y_1 << std::endl;
	std::cout << "\tY[2]: " << y_1 [2] << std::endl;
	std::cout << "\tY[3]: " << y_1 [3] << std::endl; 
	std::cout << "\tY[4]: " << y_1 [4] << std::endl;
	std::cout << "\tY[5]: " << y_1 [5] << std::endl; 
	std::cout << std::endl;


	//Index Of A Char////////////////////////////////////////////////////
	char c = 'W';
	std::cout << "===== Index Of c ========================" << std::endl;
	std::cout << "c: " << c << std:: endl;
	std::cout << "Index Is: " << std::endl;
	std::cout << "\tIn x: " <<x_1.indexOf ( c ) << std::endl;
	std::cout << "\tIn y: " << y_1.indexOf ( c ) << std::endl;
	std::cout << std::endl;
	
	c = 'o';
	std::cout << "c: " << c << std:: endl;
	std::cout << "Index Is: " << std::endl;
	std::cout << "\tIn x: " <<x_1.indexOf ( c ) << std::endl;
	std::cout << "\tIn y: " << y_1.indexOf ( c ) << std::endl;
	std::cout << std::endl;
	
	c = 'r';
	std::cout << "c: " << c << std:: endl;
	std::cout << "Index Is: " << std::endl;
	std::cout << "\tIn x: " <<x_1.indexOf ( c ) << std::endl;
	std::cout << "\tIn y: " << y_1.indexOf ( c ) << std::endl;
	std::cout << std::endl;

	c = 's';
	std::cout << "c: " << c << std:: endl;
	std::cout << "Index Is: " << std::endl;
	std::cout << "\tIn x: " <<x_1.indexOf ( c ) << std::endl;
	std::cout << "\tIn y: " << y_1.indexOf ( c ) << std::endl;
	std::cout << std::endl;

	
	//Equality Operator///////////////////////////////////////////////////
	z_1 = ("World");
	String w_1;
	std::cout << "====== Equality Op =====================" << std::endl;
	std::cout << "\tz: " << z_1 << std::endl;
	std::cout << "\tx: " << x_1 << std::endl;
	std::cout << "\tx == z" << std::endl;
	if ( x_1 == z_1 )
		std::cout << "\tTrue";
	else
		std::cout << "\tFalse";
	std::cout << std::endl << std::endl;
	
	y_1 = "Welcome";
	std::cout << "\ty: " << y_1 << std::endl;
	std::cout << "\tx: " << x_1 << std::endl;
	std::cout << "\tx == y" << std::endl;
	if ( x_1 == y_1 )
		std::cout << "\tTrue";
	else
		std::cout << "\tFalse";
	std::cout << std::endl << std::endl;
	
	std::cout << "\tz: " << z_1 << std::endl;
	std::cout << "\tw: " << w_1 << std::endl;
	std::cout << "\tz == w" << std::endl;
	if ( z_1 == w_1 )
		std::cout << "\tTrue";
	else
		std::cout << "\tFalse";
	std::cout << std::endl << std::endl;

	//+ Operator//////////////////////////////////////////////////////
	std::cout << "===== + OP ==========================" << std::endl;
	std::cout << "x: " << x_1 << std::endl;
	std::cout << "y: " << y_1 << std::endl;
	std::cout << "Result x + y: " << x_1 + y_1 << std::endl;
	std::cout << std::endl;
	
	std::cout << "x: " << x_1 << std::endl;
	std::cout << "w: " << w_1 << std::endl;
	std::cout << "Result w + x: " << w_1 + x_1 << std::endl;
	std::cout << std::endl;

	//+= Operator//////////////////////////////////////////////////////
	std::cout << "===== += OP ==========================" << std::endl;
	std::cout << "x: " << x_1 << std::endl;
	std::cout << "y: " << y_1 << std::endl;
	x_1 += y_1;
	std::cout << "x + y" << std::endl;
	std::cout << "x: " << x_1 << std::endl;
	std::cout << std::endl;
	
	std::cout << "w: " << w_1 << std::endl;
	std::cout << "y: " << y_1 << std::endl;
	std::cout << "w + y" << std::endl;
	w_1 += y_1;
	std::cout << "w: " << w_1 << std::endl;
	std::cout << std::endl;

	//Reading Input From User///////////////////////////////////////
	std::cout <<"===== Read =========================" << std::endl;
	String w;
	std::cout << "Enter A String: " ;
	std::cin >> w;
	std::cout << std::endl;
	std::cout << "Your string is: " << w << std::endl;

	return 0;
}
