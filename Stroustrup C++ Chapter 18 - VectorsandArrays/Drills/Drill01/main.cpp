//  Chapter 18 Drills
//  Created by Robert J Baldwin 31/05/2023


//  01. Define a global int array ga of ten ints initialised to 1,2,4,8,16, etc.
 
//  02. Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.

/*  03. In f() :
a.Define a local int array la of ten ints.
b.Copy the values from ga into la.
c.Print out the elements of la.
d.Define a pointer p to int and initialize it with an array allocated on the free store with the same number of
elements as the argument array.
e.Copy the values from the argument array into the free - store array.
f.Print out the elements of the free - store array.
g.Deallocate the free - store array.

	04. In main():
a. Call f() with ga as its argument.
b. Define an array aa with ten elements, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1,etc.).
c. Call f() with aa as its argument

*/

  

#include <iostream>

													// 01. Global int array
const int max{ 10 };
const int ga[max]{ 1,2,4,8,16,32,64,128,256,512 };





													// 02. Define function f()
void f(const int ga[], int n)
{
													// 03 a. Define local int array la of ten ints
	int la[10]{};

	std::cout << "Stack array contents:\n";
													// 03 b & c. Copy values from ga to la and print.
	for (int i = 0; i < 10; ++i)
	{
		la[i] = ga[i];
		std::cout << la[i] << ' ';
	}
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "*************************************\n";

													// 03 d. Define a pointer p to int
	int* p = new int[n];

													// 03 e. Copy the values from the argument array into the free - store array.
	std::cout << "Free-store array contents:\n";
	for (int i = 0; i < n; ++i)
	{
		p[i] = ga[i];
													// 03 f. Print out the elements of the free - store array.
		std::cout << p[i] << ' ';
	}
	std::cout << '\n';
	std::cout << '\n';
										// 03 g. Deallocate the free - store array.
	delete[] p;
	std::cout << "*************************************\n";
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
	f(ga, max);

													// 04 b. Define an array aa with ten elements, and initialize it with 
													// the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1,etc.).
	int aa[10]{fac(1), fac(2),fac(3), fac(4), fac(5), fac(6), fac(7), fac(8), fac(9), fac(10)};

	f(aa, max);
}