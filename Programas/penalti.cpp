#include <iostream>

using namespace std;

int main ()
{
	int x, y, z, a, b, c, r, s;
	
	r=0;
	s = 0;
	
	cin >> x;
	cin >> y;
	cin >> z;
	
	cout << endl;
	
	cin >> a >> b >> c;

	if ( x + y + z > a + b + c )

		cout <<"\nXILOGRAVURA DE ISOPOR" << endl;

	else 
		if ( a + b + c > x + y + z)
		cout <<"\nTRANSEUNTE ALADO" << endl;

		else 
		{
			cout <<"\nEMPATADO" << endl;
			while ( s == r )
		
			{
				cin >> s >> r;

				if (s == r)
				cout <<"\nEMPATADO" << endl;
		
				
			}
			
			if ( s > r)
			cout <<"\nTRANSEUNTE ALADO" << endl;
			
			else 
			cout <<"\nXILOGRAVURA DE ISOPOR" << endl;
		}
	
		
	return 0;
}
