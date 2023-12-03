// task 6 chapter 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h""

int main()
{
    int a;
    int b;
    int c;

    cout << "enter int a, b, and c\n";
    cin >> a >> b >> c;
    if (a > b && b > c) cout << c << b << a << "\n";
    if (a < b && b < c) cout << a << b << c << "\n";
    if (b > a && a < c) cout << c << a << b << "\n";
    if (b < a && a < c) cout << c << a << b << "\n";
    if (c > b && b > a) cout << a << b << c << "\n";
    if (c < b && b < a) cout << a << b << c << "\n";
}


