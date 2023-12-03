// chap 3 task 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

int main()
{
    double var1 = (0);
    double var2 = (0);
    cout << "Please enter floating-point value 1\n";
    cin >> var1;
    cout << "Please enter floating-point value 2\n";
    cin >> var2;
    if (var1 < var2)
    {
        cout << "value 1" << "(" << var1 << ")" << " is less than value 2" << "(" << var2 << ")\n";
    }
    if(var1 > var2)
    {
        cout << "value 1" << "(" << var1 << ")" << " is greater than value 2" << "(" << var2 << ")\n";
    }
    if (var1 == var2)
    {
        cout << "value 1" << "(" << var1 << ")" << " is equal to value 2" << "(" << var2 << ")\n";
    }
    
    cout <<"Sum total = " << var1 + var2 <<"\n";
    cout << "Sum difference = " << var1 - var2 << "\n";
    cout << "Sum product = " << var1 * var2 << "\n";
    cout << "Sum division = " << var1 / var2 << "\n";                                                    //"." << var1 % var2 << "\n";         this was for remainder of division for int rather than double (modulo)

}


