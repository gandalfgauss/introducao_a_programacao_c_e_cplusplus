#include <iostream>
#include <iomanip>
using namespace std;

int main () 
{
	int n = 0;
	int i = 0;
	double k = 0;
	
	do
	{ 
		cin >> n;
		
		if ( n > 0 )
		{	
		
			i++;
			k += n;
		}
	} while ( n > 0);
	
	cout << fixed << setprecision(2) << k/i << endl;
	

	return 0;
}
	
