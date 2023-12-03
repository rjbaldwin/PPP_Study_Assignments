// Input.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	cout << "Enter the name of the person you wish to write to:\n";
	string first_name;		//first_name is a variable of type string
	string friend_name = "Tony";		//second friends name
	char friend_sex = (0);
	int age = (0);
	
	cin >> first_name;		//read characters into first_name
	cout << "Dear " << first_name << ",\n" << "	have you got a bog roll please?!\n";
	cout << "Also, have you seen " << friend_name << "?\n";
	cout << "Enter m for male or f for female\n";
	cin >> friend_sex;

	if (friend_sex == 'm')
	{
		cout << "If you have seen " << friend_name << "," << "ask him to call me please?\n";
	}

	if (friend_sex == 'f')
	{
		cout << "If you have seen " << friend_name << "," << "ask her to call me please?\n";
	}

	cout << first_name << "  what is your age?\n";
	cin >> age;
	

	if (age <= 0 || age >110)						// || = logical or
	{
		cout << "Your're kidding me!\n";
	} 
	else { cout << "I hear you just had a birthday and you are " << age << " years old\n"; }

	if (age <= 12)
	{
		cout << "Next year you will be " << age +1 << "\n";
	}
	if (age ==17)
	{
		cout << "Next year you will be able to vote\n";
	}
	if (age >= 70)
	{
		cout << "I hope you are enjoying retirement?\n";
	}

	cout << "Yours sincerely,\n\n";
	cout << "Franco Bollo\n";
}