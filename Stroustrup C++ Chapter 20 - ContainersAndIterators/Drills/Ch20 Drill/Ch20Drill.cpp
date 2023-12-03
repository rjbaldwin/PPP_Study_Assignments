#include <iostream>
#include <list>
#include <vector>
#include <array>

using std::vector;
using std::list;
using std::array;





/*
6. Write a simple copy() operation,

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);

that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just
like the standard library copy function. Note that if
f1==e1 the sequence is empty, so that there is nothing to copy.

	*/


// copy 
template<typename inputIterator, typename outputIterator>

outputIterator Copy(inputIterator first1, inputIterator end1, outputIterator first2)
{
	while (first1 != end1)
	{
		*first2 = *first1;
		++first1;
		++first2;
	}
	return first2;

};



// Helper functions

// printing
template<typename T>
void print(T& a3)
{
	for (auto& e : a3)
	{
		std::cout << e << ' ';
	}
	std::cout << '\n';
};

// locating 

template<typename Container>
void locate(Container& container, Container& cont, const int value)
{

	auto vPosition = std::find(container.begin(), container.end(), value);
	if (vPosition != container.end())
	{
		std::cout << "Value " << value << " found at position : " << std::distance(container.begin(), vPosition) << '\n';
	}
	else
	{
		std::cout << "Value " << value << " was not found in the vector.\n";
	}


};


int main()
{

	constexpr int contSize = 10;

	int a1[contSize]{ 0,1,2,3,4,5,6,7,8,9 };

	vector<int>v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	list<int>l1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


	// copy a1 to a2
	
	array<int, contSize> arrayCopy01;

	for (int i = 0; i < 10; ++i)
	{
		arrayCopy01[i] = a1[i];
	};

	


	vector<int>v2 = v1;
	list<int>l2 = l1;

	/* 05: increase the value of each element
		in the array by 2; increase the value of each element
		in the vector by 3; and list elements by 5.
	*/




	// increase array values by 2
	std::cout << "Increase array values by 2: \n";
	for (int i = 0; i < 10; ++i)
	{
		arrayCopy01[i] += 2;
		std::cout << arrayCopy01[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "Increase vector values by 3: \n";
	
	// increase vector values by 3
	for (int i : v2)
	{
		i += 3;
		std::cout << i << ' ';
	}
	std::cout << '\n';

	// increase list values by 5
	std::cout << "Increase list values by 5: \n";

	for (int i : l2)
	{
		i += 5;
		
		std::cout << i << ' ';
	}
	std::cout << '\n';


	// testing the copy function 
	std::cout << "Copy function test: \n";

	vector<int>v3(v2.size());
	Copy(begin(v2), end(v2), begin(v3));

	print(v3);

	std::cout << '\n';



	// 07 copy array into vector, and copy list into array
	std::cout << "07 copy array into vector: \n";
	vector<int>array2vect(v2.size());

	Copy(begin(arrayCopy01), end(arrayCopy01), begin(array2vect));

	print(array2vect);
	std::cout << '\n';
	std::cout << "Copy list into array: \n";

	array<int, contSize> a3;
	Copy(begin(l1), end(l1), begin(a3));
	print(a3);

	/* 8. Use the standard library find() to see if the vector contains the 
		value 3 and print out its position if it does; use find() to
		see if the list contains the value 27 and print out its position 
		if it does. The “position” of the first element is 0, the
		position of the second element is 1, etc.
		Note that if find() returns the end of the sequence, the value wasn’t found.
	*/

	
	// 08 use find()

	locate(v2, v2, 3);
	locate(v2, v2, 27);

}