#include<iostream>
#include<bitset>
#include<limits>
#include<vector>
#include<iomanip>

using std::cout;
using std::vector;
using std::bitset;

void print_bits(const vector<short unsigned int>& v)
{
	for (auto e : v)
	{
		cout << std::setw(10) << std::left << std::dec << "Dec: " << e
			<< std::setw(15) << std::left << std::hex << '\t' << "Hex 0x" << e
			<< std::setw(15) << std::left << ' ' << "Bin: " << bitset<8 * sizeof(short unsigned int)>{e} << '\n';

	}

}




int main()
{
	

	const vector<short unsigned int>v{
			0xffff, // a. every bit set
			0x0001,	// b. the lowest (least significant bit) set
			0x8000,	// c. the highest (most significant bit) set
			0x00ff,	// d. the lowest byte set
			0xff00,	// e. the highest byte set
			0xAAAA,	// f. every second bit set (and the lowest bit 1)
			0x5555,	// g. every second bit set (and the lowest bit 0)
	};



	print_bits(v);

	// ex 05

	short unsigned int a{ static_cast<unsigned short int>(0x1) };
	cout << std::dec << a << ' ' << bitset<8 * sizeof(short unsigned int)>{a} << '\n';
	short unsigned int b{ static_cast<unsigned short int>(~0x1) };
	cout << std::dec << b << ' ' << bitset<8 * sizeof(short unsigned int)>{b} << '\n';
	short unsigned int c{ static_cast<unsigned short int>(1<<15) };
	cout << std::dec << c << ' ' << bitset<8 * sizeof(short unsigned int)>{c} << '\n';
	short unsigned int d{ static_cast<unsigned short int>(1 >> 15) };
	cout << std::dec << d << ' ' << bitset<8 * sizeof(short unsigned int)>{d} << '\n';


}