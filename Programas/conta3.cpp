#include <iostream>
#include <cmath>

using namespace std;

int main()
{
     
    int num1;
    int num2;
    int num3;
   
    cout <<"\nDigite o lado 1 do triângulo" << endl;
    cin >> num1;
 
    cout <<"\nDigite o lado 2 do triângulo" << endl;
    cin >> num2;

    cout <<"\nDigite o lado 3 do triângulo" << endl;
    cin >> num3;
    
    if ((num1 == num2) && ( num2 == num3))
    {  
    
    cout <<"\nO triângulo é equilátero" << endl;
    } 
   if ((num1 != num2) && ( num2 == num3))
   {  
    
    cout <<"\nO triângulo é isósceles" << endl;
   } 
   if ((num1 == num2) && (num2 != num3))
   {  
    
    cout <<"\nO triângulo é isósceles" << endl;
   } 
   if ((num1 == num3) && (num3 != num2))
   {     
    
    cout <<"\nO triângulo é isósceles" << endl;
    } 

   if ((num1 != num2) && (num2 != num3) && (num1 != num3) && (num3 != num2))
   {  
    
    cout <<"\nO triângulo é escaleno" << endl;
    } 
   

    return 0;
}
   
