// Chapter 20 page 722 Try This
// Created by Robert J Baldwin 27/06/2023

/*
Write a function void copy(int* f1, int* e1, int* f2) that copies the elements of an array of ints defined by
[f1:e1) into another [f2:f2+(e1–f1)). Use only the iterator operations mentioned above (not subscripting).
*/

#include <iostream>
#include <vector>


using std::vector;
using std::cout;


void copy(int* f1, int* e1, int* f2)
{
	while (*f1 != *e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}
}


int main()
{
	int firstArray[]{ 5,2,300,4456,51 };
	int secondArray[5];

	copy(std::begin(firstArray), std::end(firstArray), std::begin(secondArray));

	for (int i = 0; i < 5; ++i)
	{
		std::cout << secondArray[i] << ' ';
	}
}