#include <iostream>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ostream>

int const FOR_LOOP = 10000;
void print (char l)
{
	for ( unsigned i = 0; i <= FOR_LOOP; i++ )
	{
		std::cout << l << " ";
	}
	std::cout << std::endl << std::endl;
}

int main ()
{
	pid_t child_pid1;
	pid_t child_pid2;
	pid_t child_pid3;
	int status;

	if ( ! (child_pid1 = fork () ) )
	{
		std::cout << "Child id: " << getpid() << std::endl;
		sleep (2);
		print ('a');
	}

	else if ( ! ( child_pid2 = fork () ) )
	{
		std::cout << "Child id: " << getpid() << std::endl;
		sleep (2);
		print ('b');
	}
	else if ( ! ( child_pid3 = fork () ) )
	{
		std::cout << "Child id: " << getpid() << std::endl;
		sleep (2);
		print ('c');
	}
	else
	{
		std::cout << "Parent Id: " << getpid() << std::endl;
		sleep (2);
		std::cout << "Waiting for child to finish" << std::endl;
		wait (&child_pid1);
		wait (&child_pid2);
		wait (&child_pid3);
		print ('d');
	}
	//Print out 10000 d at the end because thats the parent so it has to wait
	return 0;
}
