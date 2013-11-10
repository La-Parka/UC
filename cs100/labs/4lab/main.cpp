#include <iostream>
#include "myCString.h"

using namespace std;
int main ()
{
	char * x = "";
	char * y = "123234";
	char * z = "Hello";
	cout << " ===== Size =====" << endl;
	cout << "x len: " << my_strlen (x) << endl;
	cout << "y_len: " << my_strlen (y) << endl;
	cout << endl;

	cout << "===== Sub Str =====" << endl;
	char * x_1 = my_strstr ( x, "lo" );
	if ( x_1 )
		cout << "x: " << x_1 << endl;
	char * y_1 = my_strstr ( y, "234" ); 
	if (y_1)
		cout << "y: " << y_1 << endl;
	cout << endl;

	cout << "=====Search for x =====" << endl;
	 char * x_2 =  my_strchr ( x, 'e');
	 char * y_2 = my_strchr ( y, 'e');
	 char * z_2 = my_strchr ( z, 'e');
	if ( x_2 )
		 cout << "e found in x: " << x_2 - x + 1 << endl;
	if ( y_2 )
		 cout << "e found in y: " << y_2 - y + 1 << endl;
	if ( z_2 )
		 cout << "e found in z: " << z_2 - z + 1 << endl;
		 cout << endl;

	cout << "=====Compare=====" << endl;
	cout << "\"\" vs \"123234\":" << my_strcmp ( x, y ) << endl;
	cout << "\"\" vs \"Hello\":" << my_strcmp ( x, z ) << endl;
	cout << "\"123234\" vs \"Hello\":" << my_strcmp ( y, z ) << endl;
	cout << "\"123234\" vs \"123234\":" << my_strcmp ( y, y ) << endl;
	cout << "\"123234\" vs \"\":" << my_strcmp ( y, x ) << endl;
	cout << "\"\" vs \"\":" << my_strcmp ( x, x ) << endl;
	cout << endl;

	cout << "=====Concatanation===== =P" << endl;
	cout << "\"123234\" vs \"Hello\": " << my_strcat ( y, z ) << endl << endl;

	cout << "=====Copy=====" << endl;
	cout << "Copy \"123234\" to \"\": " << endl;
	cout << "x is now: " << my_strcpy ( y, z ) << endl;

	return 0;
}
