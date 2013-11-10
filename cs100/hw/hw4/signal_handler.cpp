/*
#* Course: CS 100 Fall 2013
#*
#* First Name: Marco
#* Last Name: Tobon
#* Username: mtobo001
#* email address: mtobo001@ucr.edu
#*
#*
#* Assignment: “Homework #4”
#*
#* I hereby certify that the contents of this file represent
#* my own original individual work. Nowhere herein is there
#* code from any outside resources such as another individual,
#* a website, or publishings unless specifically designated as
#* permissible by the instructor or TA.
#*/
#include <stdio.h>
#include <iostream>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

int c_count = 0,
	z_count = 0,
	q_count = 0;
struct sigaction action;

void sighandler ( int signum, siginfo_t *info, void *ptr)
{
	if ( signum == 2 )
	{
		std::cout << "I" << std::flush;
		c_count +=1;
	}
	else if ( signum == 20 )
	{
		signal (SIGTSTP, SIG_DFL);
		raise (SIGTSTP);
		std::cout << "S" << std::flush;
		z_count +=1;
	}
	else if ( signum == 3 )
	{
		std::cout << "Q" << std::flush;
		q_count +=1;
	}
}

int main ()
{
	memset (&action, 0 , sizeof (action));
	action.sa_sigaction = sighandler;
	action.sa_flags = SA_SIGINFO;
	sigaction (SIGINT, &action, NULL);
	sigaction (SIGQUIT, &action, NULL);
	while (true)
	{
	sigaction (SIGTSTP, &action, NULL);
		std::cout << "X" << std::flush;
		usleep(1);
		if ( z_count == 3 )
		{
			std::cout << std::endl <<  "Interrupt: " << c_count << std::endl;
			std::cout << "Stop: " << q_count << std::endl;
			std::cout << "Quit: " << z_count << std::endl << std::endl;
			exit(0);
		}
	}

	return 0;
}
