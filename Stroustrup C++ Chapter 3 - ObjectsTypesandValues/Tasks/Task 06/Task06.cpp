/*
6 Write a program that prompts the user to enter three integer values, and then outputs the values in numerical sequence
separated by commas. So, if the user enters the values 10 4 6, the output should be 4, 6, 10. If two values are the same,
they should just be ordered together. So, the input 4 5 4 should give 4, 4, 5.

*/

#include<iostream>

// to do.  enter three ints
// to do. output in numerical order, separated by commas



void sort_int(int& x, int& y, int& z)
{

	
	if (x > y)
	{
		int temp{ y };
		y = x;
		x = temp;
	}

	if (y > z)
	{
		int temp{ z };
		z = y;
		y = temp;
	}

	if (x > y)
	{
		int temp{ y };
		y = x;
		x = temp;
	}
	std::cout << x << ',' << y << ',' << z << '\n';

}


int main()
{
	std::cout << "Enter 3 ints: ";
	
	int x{};
	int y{};
	int z{};

	std::cin >> x >> y >> z;

	
	sort_int(x, y, z);

}