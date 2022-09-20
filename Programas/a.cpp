#include <iostream>

using namespace std;

int main ()
{
	int x;
	int y;
	int j = 1;
	
	
	cin >> x >> y;

	for ( int i = 1; i <=8; i++)
	{	
		
	     cout << endl;
			
	     for ( j = 1; j <=8; j++)
	     {
		if ( i == x && j == y)
		cout <<"C";
		else
			if ( i == x)	
			cout <<"A";
			else
				if ( j == y)
				cout <<"B";
				if ( i !=x && i!=y && j!=x && j!=y)
				cout <<"O";
			
	     }
		
	
	} 

	cout << endl;

	return 0;
}
