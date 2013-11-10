#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	int vector_size = 23;
	char input;

	//Initializing Vector WIth Given Size
	cout << endl;
	cout << "Initializing Vector" << endl << endl;
	vector <int> myvector(vector_size); // The default constructor was used instead of a parameterized size constructor. 
	for ( unsigned i = 0; i < vector_size; i ++ )
	{
		myvector.at(i) = i + 1;
	}
	cout << endl  <<endl;
	while ( true )
	{
	
		cout << "============================== VECTOR ERRORS ==============================" <<endl;
		cout << "\tPrint What The Vector Cointains (p): " << endl
			 << "\tCheck First Element Of Vector (f): " << endl
			 << "\tAdd Elements In Vector (+): " << endl
			 << "\tFind Average (a): " << endl
			 << "\tCheck If 13 Is In Vector: (s): " << endl
			 << "\tChanges Elements In Vector To Different Ones (c): " << endl
			 << "\tDeletes All Elements In Vector (d): " <<endl
			 << "\tAdd 2 vectors (2): " << endl
			 << "\tQuit Program: (q)" << endl << endl;
	
		cin >> input;
		cout << endl;
	// Case table was mixed up for some reason
		switch (input)
		{
			case 'p':
	
				//Contains
				cout << "===== Printing Vector =====" << endl;
				cout << "My Vector Contains: " << endl;
				for ( vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
				{
					cout << *it << ",";
				}
				cout << endl << endl;
				break;
	
			case 'f':
	
				//Accessing FIrst ELemnt
				cout << "First Element Is: " << myvector.front() << endl << endl; // This was printing the wrong element
				break;
			
			case '+':
			{
				cout << "===== Adding Elements =====" << endl;
				int total = 0; // total was uninitialized
				for ( vector<int>::iterator it = myvector.begin (); it != myvector.end(); ++it )
				{
					total += *it;
				}

				//Adding Vecotor Elements
							cout << "The Total Is: " << total << endl <<endl;
				break;
			}

			case 'a':
			{
					cout << "===== Adding Elements =====" << endl;
				int total = 0; // total was uninitialized
				for ( vector<int>::iterator it = myvector.begin (); it != myvector.end(); ++it )
				{
					total += *it;
				}

				// Finding Average Of Vector Elements
				cout << "Average Is: " << total / myvector.size()  << endl <<endl; // This was dividing by the wrong # of elements
				break;
			}
			case 's':
	
				//Looks THrough Vector To See If '13' is contained
				cout << "===== Looking for a 13 =====" <<endl << endl;
				for ( unsigned i = 0; i < myvector.size(); i++ ) // This was i <= myvector.size(), causing out of range
				{
					if ( myvector.at(i) == 13 )
						cout << "13 Found" << endl; // Output was lying to me :(
				}
				cout <<endl;
				break;
			
			case 'c':
	
				//Changing Element
				cout << "===== Changing elements in the vector =====" << endl << endl;
				for ( unsigned i = 0; i < myvector.size(); i -- )
				{
					myvector.at (i) = myvector.at(i) + 32;
				}
				for (unsigned i = 0; i < myvector.size(); i++ )
					cout << "My vector Contains: " << myvector.at(i) << endl;
				break;
			
			case 'd': 
	
				//Delete Elements
				cout << "===== Deleting All Elements =====" << endl << endl;
				for ( vector <int>::iterator it = myvector.begin (); it != myvector.end(); )
				{
					it = myvector.erase (it); // it + 1 doesn't work
				}
				if ( myvector.size() > 0 )
					cout << "All Elements Are Not Deleted" <<endl << endl;
				break;

			case '2':
			{

				cout << "===== Adding 2 Vectors =====";
				vector <int> second (9);
				cout << "Second Vector Contains: " << endl;
				for (unsigned i =0; i < second.size(); i++)
				{
					second.at(i) = 3+ i;
					cout << second.at(i) << ",";
				}
				cout << endl;
				cout << "Third Vector WWould Be: " << endl;
				if ( myvector.size() > second.size() )
				{
					for ( unsigned i = 0; i < myvector.size(); i++ )
					{
						cout << myvector.at(i) + second.at(i);
					}
					cout << endl;
				}
				else 
				{
					for (unsigned i = 0; i < second.size(); i++ )
					{
						cout << myvector.at(i) + second.at(i) + 1;
					}
					cout << endl;
				}
			}

			case 'q':
				cout << "===== Exiting =====" << endl << endl;
				exit (0);
			
			default:
				//Prints Error Message And User Inputs New Choice
				//cout << "Segmentation Fault" << endl; <- FALSE ERROR MESSAGE!
				cout << "Invalid input" << endl;
				exit(1);
		}
				
	}

	return 0;
}
