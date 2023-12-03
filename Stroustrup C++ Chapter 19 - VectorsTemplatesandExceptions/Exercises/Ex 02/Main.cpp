// Chapter 19 Ex 02 - Created by Robert J Baldwin 23/06/2023
/*
Write a template function that takes a vector<T> vt and a vector<U> vu as arguments and returns the sum of all
vt[i]*vu[i]s.
*/

#include<iostream>
#include<vector>
using std::vector;


template<typename T, typename U> 

vector<T> func(vector<T>vt, vector<U>vu)
{
	for (int i = 0; i < vu.size(); ++i)
	{
		vt[i] *= vu[i];
	}
	return vt;
}


int main()
{
	vector<int>vt{5, 2, 3, 4, 2};
	vector<int>vu{5, 7, 8, 9, 10};



	vt = func(vt, vu);

	for (const auto& element : vt)
	{
		std::cout << element << ' ';
	}
}