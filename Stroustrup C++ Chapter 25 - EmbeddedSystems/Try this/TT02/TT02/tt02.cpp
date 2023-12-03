#include<iostream>
#include <bitset>



int main()
{
	for (unsigned int i; std::cin >> i;)
		std::cout << std::dec << i << " == " << std::hex << " 0x " << i << " == "
		<< std::bitset<8 * sizeof(unsigned int)>{i} << '\n';
	

}