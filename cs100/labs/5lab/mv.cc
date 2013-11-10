#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <list>

//Prints Files Data====================================================================== 
void file_print ( char * arg )
{
	int status;
	std::cout << "Removing: " << arg << std::endl;
	status = unlink (arg);
	if ( status == 0 )
	{
		std::cout << "Succesful Remove" << std::endl << std::endl;
	}
	else
		std::cout << "Error" << std::endl << std::endl;
}

//Traverses Through Directory====================================================================== 
void traverse ( std::list <std::string> & directories, char *directory )
{
	DIR *dir;// = NULL;
	dir = opendir ( directory );
	struct dirent *files = NULL;
	if (!dir)
	{
		std::cout << "Error dir could not be initialized correctly" << std::endl;
		exit (1);
		
	}		
	while ( ( files = readdir ( dir ) ) )
	{
		struct stat st;
		stat ( files -> d_name, &st);
		if ( !files )
		{
			std::cout << "Error files could not be initialized correctly" << std::endl;
		}


		else if ( files -> d_type == DT_DIR)
		{
			if (!strcmp( files -> d_name,".") || !strcmp( files -> d_name,"..") )
				continue;
			else if (!S_ISREG ( st.st_mode ) && S_ISDIR ( st.st_mode))
			{
				std::string file_name = std::string(directory) + std::string( files -> d_name) + '/';
				directories.push_back( file_name );
			}
		}
		else //if ( S_ISREG ( st.st_mode ) && !S_ISDIR (st.st_mode ))
		{
			std::string file = files -> d_name;
			char path [100] ;
			strcpy (path, directory);
			strcat (path,file.c_str());
			file_print (path);
			//path = NULL;
		}	
	
	}

	closedir(dir);
}

//Checks What TYpe Of Argument Passed In====================================================================== 
bool check_what_it_is ( std::list <std::string>& direct, char * arg )
{
	struct stat check;
	stat ( arg, &check );
	if ( !S_ISREG ( check.st_mode ) && S_ISDIR ( check.st_mode ) )
	{
		traverse ( direct, arg );
		std::cout << "Dir: " <<std::endl;
		return true;
	}
	else if ( S_ISREG (check.st_mode))
		return true;
	else
		std::cout << "Error" << std::endl;
		return false;

}

//Main====================================================================== 
int main ( int args, char * argv [] )
{
	std::list <std::string> directories;
	
	//If Arguments Is ONly Excecutable PWD
	if ( args == 3 )
	{
		char * t = "./";
		char * file = argv [1];
		std::string t2 = (std::string(t) + std::string(argv[2])).c_str();
		const char* temp = t2.c_str();

		std::cout << temp << std::endl;
		int status;
		check_what_it_is ( directories, argv[1] );
		check_what_it_is ( directories, argv[2]);
		status = link (file, temp);	
		

	}
	else
	{
		std::cout << "Error" << std::endl;
		exit(0);
	}

	//Else Goes Thorugh Every Argument Passed In
/*
	else
	{
		for (unsigned i = 1; i < args; i++ )
		{
			check_what_it_is (directories, argv [i] );
		}
	}
*/
/*	std::list <std::string> dire;

	while( directories.size() > 0 )
	{
		traverse (directories, (char*)directories.front().c_str());
		dire.push_front (directories.front());
		directories.pop_front();
	}
	while ( dire.size() > 0 )
	{
		rmdir (dire.front().c_str());
		dire.pop_front();
	}
	rmdir (argv[1]);
*/
	return 0;
}
