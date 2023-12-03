/*

9 Write a program that converts spelled-out numbers such as “zero” and “two” into digits, such as 0 and 2. When the user
inputs a number, the program should print out the corresponding digit. Do it for the values 0, 1, 2, 3, and 4 and write out
not a number I know if the user enters something that doesn’t correspond, such as stupid computer!.

*/


#include<iostream>
#include<string>

using std::string;


void num_convert(string s)
{
	if (s == "zero")
	{
		std::cout << 0 << '\n';
	}
	else if (s == "one")
	{
		std::cout << 1 << '\n';
	}
	else if (s == "two")
	{
		std::cout << 2 << '\n';
	}
	else if (s == "three")
	{
		std::cout << 3 << '\n';
	}
	else if (s == "four")
	{
		std::cout << 4 << '\n';
	}
	else
	{
		std::cout << "Not a number I know\n";
	}
}


int main()
{
	std::cout << "Enter 0,1,2,3, or 4 as string names:\n ";
	
	string s{};
	std::cin >> s;
	num_convert(s);

}