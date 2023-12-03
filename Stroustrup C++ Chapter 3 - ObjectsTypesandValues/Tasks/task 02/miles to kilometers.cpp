// miles to kilometers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

int main()
{
    double miles;
    cout << "enter the amount of miles\n";
    cin >> miles;
    double km = 1.609;
    double answer = miles * km;
    cout << miles << " miles = " << answer;
}


