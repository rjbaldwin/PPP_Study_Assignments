#include<iostream>
#include <bitset>




int main()
{
	unsigned int v{ 1 };
	std::cout << sizeof(v) << '\n';

	for (int i = 0; i < sizeof(v) * 8; ++i)
	{
		std::cout << v << ": " << std::bitset<sizeof(int) * 8>(v) << '\n';
		v <<= 1;
	}

}