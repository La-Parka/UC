/*
#* Course: CS 100 Fall 2013
#*
#* First Name: Marco
#* Last Name: Tobon
#* Username: mtobo001
#* email address: mtobo001@ucr.edu
#*
#*
#* Assignment: “Homework #2”
#*
#* I hereby certify that the contents of this file represent
#* my own original individual work. Nowhere herein is there
#* code from any outside resources such as another individual,
#* a website, or publishings unless specifically designated as
#* permissible by the instructor or TA.
#*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "Timer.h"

//Uses in.get(), out.put====================================================================== 
void char_get ( char * in, char * out )
{
	Timer t;
	double eTime;
	std::ifstream in_file;
	std::ofstream out_file;
	out_file.open ( out , std::ios::out );
	in_file.open ( in , std::ios::in );
	if ( in_file.is_open () && out_file.is_open () )
	{
		char x = '\0';
		t.start();
		while (!in_file.eof() ) //!in.eof() )
		{
			x = in_file.get();
			if ( x == EOF )
			{
				t.elapsedUserTime (eTime);
				std::cout << "Time For Char By Char: " << eTime << std::endl;
				return;
			}
			out_file.put(x);
		}
	}
	else
	{
		std::cout << "Error Opening File" << std::endl;
		exit(1);
	}


}

//Uses UNIX read() and write ()====================================================================== 
void unx ( char * in, char * out )
{
	int file_des;
	int file_sor;
	int byte = 1;
	file_sor = open ( in, O_RDONLY);
	file_des = open ( out, O_WRONLY);
	if ( file_des < 0 || file_sor < 0 )
	{
		std::cerr << "Error Opening File" <<std::endl;
		exit(1);
	}
	char c [0];
	while (read (file_sor, c, byte) > 0 )
	{
		read ( file_sor, c, byte);
		//std::cout << c<< std::endl;
		write (file_des, c, byte); 
	}

}

//Uses BUFSIZE and UNIX read() write()====================================================================== 
//void buf_unix ( ifstream in, ofstream out );




int main ( int args, char * argv [] )
{
	if ( args < 3 || args > 3 )
	{
		if ( args > 3 )
		{
			std::cerr << "To Many Command-Line Operator" << std::endl
					 << argv[1] << " <input_file> <output_file>" << std::endl;
					 exit(1);
		}
		else
		{
			std::cerr << "To Few Command-Line Operator" << std::endl
					 << argv[1] << " <input_file> <output_file>" << std::endl;
			exit(1);
		}
	}
	char_get ( argv[1], argv[2] );
		
	//unx ( argv[1], argv[2] );
}

