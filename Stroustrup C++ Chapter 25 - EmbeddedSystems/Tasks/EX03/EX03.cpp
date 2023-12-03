#include<iostream>
#include <bitset>

using std::cout;

template<typename T>
void print(T& value)
{
	std::cout << std::dec << "Dec: " << value << std::hex << " Hex: " << value <<  " Bin: " << std::bitset<sizeof(T) * 4>(value) << '\n';
}


int main()
{
	cout << "Signed ints\n";
	// bitset patterns signed int
	int allZero{ 0x0 };
	print(allZero);

	int allOnes{ 0xffff };
	print(allOnes);

	int alternating1010{ 0x5555 };
	print(alternating1010);

	int alternating0101{ 0xaaaa };
	print(alternating0101);

	int repeating1100{ 0xcccc };
	print(repeating1100);

	int repeating0011{ 0x3333 };
	print(repeating0011);

	int alternate10{ 0x0f0f };
	print(alternate10);

	int alternate01{ 0xf0f0 };
	print(alternate01);

	cout << "unsigned ints\n";

	// bitset patterns unsigned int
	uint32_t allZeroU{ 0x0 };
	print(allZeroU);

	uint32_t allOnesU{ 0xffff };
	print(allOnesU);

	uint32_t alternating1010U{ 0x5555 };
	print(alternating1010U);

	uint32_t alternating0101U{ 0xaaaa };
	print(alternating0101U);

	uint32_t repeating1100U{ 0xcccc };
	print(repeating1100U);

	uint32_t repeating0011u{ 0x3333 };
	print(repeating0011u);

	uint32_t alternate10u{ 0x0f0f };
	print(alternate10u);

	uint32_t alternate01u{ 0xf0f0 };
	print(alternate01u);



}