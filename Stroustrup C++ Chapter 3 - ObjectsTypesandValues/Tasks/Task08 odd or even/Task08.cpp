/*
8 Write a program to test an integer value to determine if it is odd or even. As always, make sure your output is clear and
complete. In other words, don’t just output yes or no. Your output should stand alone, like The value 4 is an even
number. Hint: See the remainder (modulo) operator in §3.4.

*/


#include<iostream>

void odd_or_even(int x)
{
	if (x % 2 == 0)
	{
		std::cout << "Number " << x << " is even.\n";
	}
	else
	{
		std::cout << "Number " << x << " is odd.\n";
	}
}

int main()
{
	std::cout << "Enter a number \n";
	int x{};
	std::cin >> x;
	odd_or_even(x);

}