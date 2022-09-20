#include<iostream>
#include <cmath>
using namespace std; 

int main()
{
    double pi, s = 0 ;
    int in, aux = 1, base = 1; 
    
    cin >> in;
    do
    {
    if (aux % 2 != 0)
        s = s +(1/pow(base, 3));
    else 
        s = s - (1/pow(base, 3));
        aux++;
        base = base+ 2;
        
    }
    while (aux <= in);
    pi = pow((s*31),1.0/3);
    cout << " O valor de Pi é: "<< pi << endl; 
    
    return 0;
}
