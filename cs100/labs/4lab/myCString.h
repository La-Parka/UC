#include <iostream>

using namespace std;
size_t my_strlen ( const char * str );
char * my_strstr ( char * str1, const char * str2 );
char * my_strcpy ( char * des, const char * source );
char * my_strcat ( char * des, const char * source );
int my_strcmp ( const char * str1, const char * str2 );
char * my_strchr ( char * str, int character );

char * my_strcpy ( char * des, const char * source )
{
	int des_sz, sou_sz;
	des_sz = my_strlen ( des );
	sou_sz = my_strlen ( source );
	if ( des_sz == sou_sz )
		for ( int i = 0; i < sou_sz; i++ )
			des [i] = source [i];
		return des;
	
	char* expand = new char [sou_sz ];
	for ( int i = 0; i < sou_sz; i ++ )
		expand [i] = source[i];

	des = NULL;
	des = expand;
	return expand;

}

char * my_strcat ( char * des, const char * source )
{
	int i = my_strlen ( des );
	int j = my_strlen ( source );
	int t = 0;

	char * ret = new char [i+j];

	for ( int g = 0; i > 0; i--, g++, t++ )
		ret[t] = des[g];

	for ( int g = 0; j > 0; j--, g++, t++ )
		ret[t] = source[g];
	ret[t] = '\0';

	return ret;
}

int my_strcmp ( const char * str1, const char * str2 )
{
	int ret = 0;
	int j = 0;
	if ( my_strlen ( str1 ) < my_strlen ( str2 ) )
	{
		for ( int i = my_strlen ( str2 ), j = 0; i > 0 && ret == 0; i--, j++ )
		{	
			if ( !str1[j] )
			{
				ret -= 1;
				return ret;
			}
			ret += str1[j] - str2[j];
		}
	return ret;	
	}

	for ( int i = my_strlen ( str1 ), j = 0; i > 0 && ret == 0; i--, j++ )
	{	
		if ( !str2[j] )
		{
			ret += 1;
			return ret;
		}
		ret += str1[j] - str2[j];
	}
	return ret;
}
char * my_strchr ( char * str, int character )
{
	for ( unsigned i = 0; str [i] != '\0'; i++ )
		if ( str [i] == character )
			return &str[i];

	return '\0';

}
char * my_strstr ( char * str1, const char * str2 )
{
	char * ret = '\0';
	if ( my_strlen ( str2) > my_strlen ( str1 ) )
		return ret;
	unsigned i = 0;
	unsigned g = 0;
	unsigned j = i;
	unsigned s_2 = my_strlen (str2);

	while ( str1[i] != '\0' )
	{
		for ( i; str1 [i] != '\0' || str2 [g] != '\0' || str1 [i] != str2 [g]; i++ )
		{
			if ( str1 [i] == str2 [g])
				g++;
			if ( str1 [i] == '\0' )
				return NULL;
		 	if ( str2 [g] == '\0' )
			{
				//cout << "i: " << i <<  endl;
				j = i - s_2 + 1;
				return &str1[j];
			}
		}
		i++;
		g = 0;
	}
}



//Size====================================================================== 
size_t my_strlen ( const char * str )
{
	size_t sz = 0;
	for ( unsigned i = 0;  str [i] != '\0'; i++)
		sz+=1;
	return sz;
}

