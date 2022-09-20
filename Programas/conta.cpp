#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double s, s1, s2, s3, area, perimetro;
 
    cout <<"\nDIGITE O LADO 1 DO TRIÂNGULO" << endl;
    cin >> s1;
    
    cout <<"\nDIGITE O LADO 2 DO TRIÂNGULO" << endl;
    cin >> s2;
 
    cout <<"\nDIGITE O LADO 3 DO TRIÂNGULO" << endl;
    cin >> s3;
 
    perimetro = s1+s2+s3;
    
    s = (s1+s2+s3)/2.0;
   
    area = pow(s* (s-s1)*(s-s2)*(s-s3), 0.5);

    cout <<"\nPERÍMETRO DO TRIÃNGULO =" << perimetro << endl;
    cout <<"\nÁREA DO TRIÃNGULO =" << area << endl;
    
    return 0;
}
    

    
   
 
 
 


