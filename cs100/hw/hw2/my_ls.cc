#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <list>

//Prints Files Data====================================================================== 
void file_print ( char * arg )
{
	struct stat f_stat;
	stat ( arg, &f_stat);
	if ( S_ISREG (f_stat.st_mode) && !S_ISDIR (f_stat.st_mode) )
	{
		if (f_stat.st_mode & S_IRUSR)
			std::cout << "r";
		else
			std::cout << "-";
		if (f_stat.st_mode & S_IWUSR)
			std::cout << "w";
		else
			std::cout << "-";
		if (f_stat.st_mode & S_IXUSR)
				std::cout << "x";
		else
			std::cout << "-";

		if (f_stat.st_mode & S_IRGRP) 
			std::cout << "r"; 
		else
			std::cout << "-";
		
		if (f_stat.st_mode & S_IWGRP) 
			std::cout << "w"; 
		else
			std::cout << "-";
		if (f_stat.st_mode & S_IXGRP) 
			std::cout << "x";
		else
			std::cout << "-";
		if (f_stat.st_mode & S_IROTH) 
			std::cout << "r";
		else
			std::cout << "-";
		if (f_stat.st_mode & S_IWOTH) 
			std::cout << "w";
		else
			std::cout <<"-";
		if (f_stat.st_mode & S_IXOTH) 
			std::cout << "x";
		else
			std::cout << "-";
	    std::cout << " " << f_stat.st_nlink << " LINKS";
    	std::cout << " " << f_stat.st_size << " SIZE";
		std::cout << " " << f_stat.st_mtime << " MOD DATE ";
		std::cout << arg  << std::endl;
	}
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
	std::cout << directory  << " contains: " << std::endl;
	while ( ( files = readdir ( dir ) ) )
	{
		struct stat st;
		stat ( files -> d_name, &st);

		//if (!S_ISREG ( st.st_mode ) && S_ISDIR ( st.st_mode) )
		if ( files -> d_type == DT_DIR)
		{
			if (!strcmp( files -> d_name,".") || !strcmp( files -> d_name,"..") )
				continue;
			else if (!S_ISREG ( st.st_mode ) && S_ISDIR ( st.st_mode))
			{
				std::string file_name = std::string(directory) + "/" + std::string( files -> d_name);
				directories.push_back( file_name );
			}
		}
		
		if ( !files )
		{
			std::cout << "Error files could not be initialized correctly" << std::endl;
		}
		std::cout << "\t" << files -> d_name << std::endl;
	}
	closedir(dir);

}

//Checks What TYpe Of Argument Passed In====================================================================== 
void check_what_it_is ( std::list <std::string>& direct, char * arg )
{
	struct stat check;
	stat ( arg, &check );
	if ( !S_ISREG ( check.st_mode ) && S_ISDIR ( check.st_mode ) )
	{
		traverse ( direct, arg );
	}
	else
		file_print ( arg );
}

//Main====================================================================== 
int main ( int args, char * argv [] )
{
	std::list <std::string> directories;
	
	//If Arguments Is ONly Excecutable PWD
	if ( args <= 1 )
	{
		traverse ( directories, ".");
	}

	//Else Goes Thorugh Every Argument Passed In
	else
	{
		for (unsigned i = 1; i < args; i++ )
		{
			check_what_it_is (directories, argv [i] );
		}
	}

	while ( directories.size() > 0 )
	{
		traverse (directories, (char*)directories.front().c_str());
		directories.pop_front();
	}

	return 0;
}
