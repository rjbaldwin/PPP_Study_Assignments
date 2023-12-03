/*
6 Write a program that prompts the user to enter three integer values, and then outputs the values in numerical sequence
separated by commas. So, if the user enters the values 10 4 6, the output should be 4, 6, 10. If two values are the same,
they should just be ordered together. So, the input 4 5 4 should give 4, 4, 5.

7 Do exercise 6, but with three string values. So, if the user enters the values Steinbeck, Hemingway, Fitzgerald, the
output should be Fitzgerald, Hemingway, Steinbeck.

*/

#include<iostream>
#include<string>

using std::string;


void sort_string(string& x, string& y, string& z)
{

	
	if (x > y)
	{
		string temp{ y };
		y = x;
		x = temp;
	}

	if (y > z)
	{
		string temp{ z };
		z = y;
		y = temp;
	}

	if (x > y)
	{
		string temp{ y };
		y = x;
		x = temp;
	}
	std::cout << x << ',' << y << ',' << z << '\n';

}


int main()
{
	std::cout << "Enter three strings: ";
	
	string x{};
	string y{};
	string z{};

	std::cin >> x >> y >> z;

	
	sort_string(x, y, z);

}