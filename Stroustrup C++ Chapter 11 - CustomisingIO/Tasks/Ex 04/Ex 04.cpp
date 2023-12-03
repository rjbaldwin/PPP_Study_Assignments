/*
4. Write a program called multi_input.cpp that prompts the user to enter several integers in any combination of octal,
decimal, or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; and converts them to decimal
form. Then your program should output the values in properly spaced columns like this:

0x43 hexadecimal converts to 67 decimal
0123 octal converts to 83 decimal
65 decimal converts to 65 decimal*/

#include <iostream>
#include "std_lib_facilities.h"




int main()
{
	int a{};
	int b{};
	int c{};
	

	cout << "Enter 3 integer values in either dec, oct, or hex: \n";
	

	cin.unsetf(ios::dec);
	cin.unsetf(ios::oct);
	cin.unsetf(ios::hex);


	cin >> a >> b >> c;

	cout << a << '\t' << "converts to\t" << a << " in decimal\n"
		<< b << '\t' << "converts to\t" << b << " in decimal\n"
		<< c << '\t' << "converts to\t" << c << " in decimal\n";
	





}