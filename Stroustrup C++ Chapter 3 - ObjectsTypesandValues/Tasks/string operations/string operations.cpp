// Operations and Operators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

int main()
{
	cout << "please enter your first and second names\n";
	string first;
	string second;
	cin >> first >> second;
	string name = first + ' ' + second;
	cout << "hello, " << name << '\n';

}
