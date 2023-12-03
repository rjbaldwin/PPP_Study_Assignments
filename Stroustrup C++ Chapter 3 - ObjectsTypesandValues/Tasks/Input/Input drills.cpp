// Input.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you wish to write to:\n";
	string first_name;		//first_name is a variable of type string
	string friend_name = "Tony" ;		//second friends name
	char friend_sex = (0);
	cin >> first_name;		//read characters into first_name
	cout << "Dear " << first_name <<",\n" << "	have you got a light please?!\n";
	cout << "Also, have you seen " << friend_name<<"?\n";
	cout << "Enter m for male or f for female\n";
	cin >> friend_sex;

	if (friend_sex == 'm')
		cout << "If you see" << friend_name << "ask him to call me please?"; 

	if (friend_sex == 'f')
	    cout << "If you see" << friend_name << "ask her to call me please?";
		 

	

}
