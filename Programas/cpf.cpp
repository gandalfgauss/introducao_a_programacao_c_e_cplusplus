#include <iostream> 

using namespace std;

int main () 
{
	int  a, b, c, d, e, f, g, h, i, j, k,l, m, n, o;
	long x;
	
	cout <<"\nDigite seu CPF" << endl;
	cin >> x;
	
	
	a = x % 10;
	b = (( x % 100) - a ) / 10;
	c = (( x % 1000) - b - a) / 100;
	d = (( x % 10000) - c - b - a) / 1000;
	e = (( x % 100000)- d - c - b - a) / 10000;
	f = (( x % 1000000)- e - d - c - b - a) / 100000;
	g = (( x % 10000000)- f - e - d - c - b - a) / 1000000;
	h = (( x % 100000000)- g - f - e - d - c - b - a) / 10000000;
	i = (( x % 1000000000)- h - g - f - e - d - c - b - a) / 100000000;
	j = (( x % 10000000000)- i - g - f - e - d - c - b - a) / 1000000000;
	k = (( x % 100000000000)- j -i - g - f - e - d - c - b - a) / 10000000000;
	
	l = k*10 + j*9 + i*8 + h*7 + g*6 + f*5 + e*4 + d*3 + c*2;
	
	m = (l*10) % 11;
	
	if ( m == b )
	{
		
	}
	
	else
	{
		if ( m == 10 && b == 0)
		{}
		
		else
		cout <<" Está incorreto";
	}
	
	
	n = k*11 + j*10 + i*9 + h*8 + g*7 + f*6 + e*5 + d*4 + c*3 + b*2;
	
	o = (n*10) % 11;
	
	if ( o == a)
	{
		cout <<"\nEstá correto" << endl;
	}
	
	else
	{
		if ( o == 10 && a == 0)	
		cout << "\nEstá correto" << endl;
		
		else
		cout << "\nEstá incorreto" << endl;
	}
	
	
	return 0;
	
}
	
	
