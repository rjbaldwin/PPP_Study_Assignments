// chapter 17 Drills
// robert j baldwin
// 1. Allocate an array of ten ints on the free store using new.
// 
// 2. Print the values of the ten ints to cout.
// 
// 3. Deallocate the array (using delete[]).
// 
// 4. Write a function print_array10(ostream& os, int* a) that prints out
// the values of a (assumed to have ten elements) to os.
//
// 5. allocate an array of ten ints on the free store; initialise it with the values 100,101,102,
// etc.; and print out its values.

// 6. allocate an array of 11 ints on the free store; initialise it with the values 100,101,102,
// etc.; and print out its values.

// 7. write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements) to os.


// Drills part 2

// 1. Allocate an int, initialise it to 7, and assign its address to a variable p1.
// 2. Print out the value of p1 and of the int it points to.
// 3. Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
// 4.
// 5. Declare an int* called p3 and initialize it with p2
// 10. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.

#include <iostream>
#include <vector>

using std::vector;

//  a function print_array10(ostream& os, int* a) that prints out
// the values of a (assumed to have ten elements) to os.

void print_array10(std::ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)		
		os << a[i] << '\n';
}

// write a function print_array(ostream& os, int* a, int n) that prints out the values of a(assumed to have n elements) to os.

void print_array(std::ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
		os << a[i] << '\n';
}


void print_vector(std::ostream& os, vector<int>* v)
{
	for (int i = 0; i < v->size(); ++i)
		os << (*v)[i] << '\n';
}


int main()
{
	std::cout << "Begin \n";
	
	int* a = new int[10] {};  // an array of 10 ints on the heap
	std::cout << "array of 10 \n";
	print_array10(std::cout, a);

	//for(int x = 0; x < 10;++x)	// Print the values of the ten ints to cout
	//std::cout << a[x] << '\n';

	delete[] a; // 3. Deallocate the array (using delete[]).

	//==============================================================================================================

	// allocate an array of ten ints on the free store; initialise it with the values 100, 101, 102,
		// etc.; and print out its values.

	int* a2 = new int[10] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	std::cout << "array of 10 \n";
	print_array10(std::cout, a2);

	delete[] a2;

	//==============================================================================================================


	const int arrayAmount{ 11 };
	std::cout << "array of 11 - auto initialised \n";
	int* a3 = new int[arrayAmount] {};
	int x{ 100 };
	for (int i = 0; i < 11; ++i)
	{
		a3[i] = x;
		++x;
	}

	std::cout << "array of 11 but only 10 outputting \n";
	print_array10(std::cout, a3); // this function wont print the last value as the iterator only loops for 10.

	std::cout << "array of 11 using correct function \n";
	print_array(std::cout, a3, arrayAmount); // this function requires n (number of array elements) as an argument.

	delete[] a3;

	//==============================================================================================================


	int* a4 = new int[20] {100, 101, 102, 103, 104, 105, 106, 107, 108, 
							109, 110,111,112,113,114,115,116,117,118,119};
	std::cout << "array of 20 \n";
	print_array(std::cout, a4, 20);
	delete[] a4;

	//==============================================================================================================


	vector<int>* v1 = new vector<int>{1,2,3,4,5,6,7,8,9,10};
	std::cout << "vector v1 \n";
	print_vector(std::cout, v1);

	delete v1;
	std::cout << "vector v2 \n";

	vector<int>* v2 = new vector<int>{ 1,2,3,4,5,6,7,8,9,10,11 };

	print_vector(std::cout, v2);

	delete v2;


	//========================================================================================
	// part two

	// 1. Allocate an int, initialise it to 7, and assign its address to a variable p1.

	int i{ 7 };
	int* p1 = &i;

	// 2. Print out the value of p1 and of the int it points to.

	std::cout << "address pointed to by *p1 = " << p1 << '\n';
	std::cout << "value pointed to by p1 = " << *p1 << '\n';
	std::cout << "address of i = " << &i << '\n';
	std::cout << "value of i = " << i << '\n';

	// 3. Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.

	int* p2 = new int[7] {};

	int x2{ 1 };
	for (int i = 0; i < 7; ++i)
	{
		p2[i] = x2;
		x2 *= 2;
	}

	print_array(std::cout, p2,7);

	// 5. Declare an int* called p3 and initialize it with p2

	int* p3 = p2;
	
	p2 = p1;
	p2 = p3;

	std::cout << "p1's value is: " << *p1 << '\n';
	std::cout << "p1 points to: " << p1 << '\n';
	std::cout << "p2's value is: " << *p2 << '\n';
	std::cout << "p2 points to: " << p2 << '\n';

	
	delete[] p3;
	p2 = nullptr;
	p1 = nullptr;
	

	// 10. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
	
	int array01[10]{}; // not on the heap

	int x3{ 1 };
	for (int i = 0; i < 10; ++i)
	{
		array01[i] = x3;
		x3 *= 2;
	}

	print_array(std::cout, array01,10);

}