#include <iostream>

using namespace std;

int main ()
{
	int x, y;

	cin >> x >> y;
	cout << x << " ";
	
	for ( int r = 1; r <=9; r++)
	{
			
		x+= y;
		cout << x << " ";
		
	}

	cout << endl;
	return 0;
}
