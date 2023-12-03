// Chapter 18 drill part 2 - vector
// Created by Robert J Baldwin 31/5/2023

/*
Standard library vector drill:
1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16, etc.
2. Define a function f() taking a vector<int> argument.

3. In f():
a. Define a local vector<int> lv with the same number of elements as the argument vector.
b. Copy the values from gv into lv.
c. Print out the elements of lv.
d. Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
e. Print out the elements of lv2.
4. In main():
a. Call f() with gv as its argument.
b. Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
c. Call f() with vv as its argument.
*/

#include <iostream>
#include <vector>

																	
std::vector<int> gv{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};		// 1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16, etc.

														// 2. Define a function f() taking a vector<int> argument.
void f(const std::vector<int> v)
{
	std::vector<int> lv(10);							// 3 a. Define a local vector<int> lv with the same number of elements as the argument vector.
	std::cout << "Local vector lv: \n";
														// 3 b & c. Copy the values from gv into lv.
	for (int i = 0; i < 10; ++i)
	{
		lv[i] = v[i];
		std::cout << lv[i] << ' ';
		
		
	}
	std::cout << '\n';
	std::cout << '\n';

	std::cout << "Local vector lv2: \n";
																				
	std::vector<int> lv2 = v;							// 3 d. Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
	for (int i : lv2)									// 3 e. Print out the elements of lv2.
	{
		std::cout << i << ' ';
	}			
	
	std::cout << '\n';
	std::cout << '\n';

}


// factorial function
int fac(int n)
{
	int r = 1;
	while (n > 1) {
		r *= n;
		--n;
	}
	return r;
}



int main()
{
	f(gv);												// 4 a. Call f() with gv as its argument.
														// 4 b. Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
	std::vector<int> vv{fac(1), fac(2), fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9), fac(10), };

														// 4 c. Call f() with vv as its argument.
	f(vv);

}