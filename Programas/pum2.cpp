#include <iostream>

using namespace std;

int main () 
{
	int n;
	int i = 1;

	cin >> n;
	
	while ( n > 0 )
	{
		cout << i << " " << i + 1 << " " << i + 2 << " " << "PUM" << endl;
		i += 4;
		n--;
	}

	return 0;
}
