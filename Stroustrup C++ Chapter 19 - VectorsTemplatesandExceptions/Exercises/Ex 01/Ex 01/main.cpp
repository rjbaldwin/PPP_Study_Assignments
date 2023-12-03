// Chapter 19 Ex 01 - Created by Robert J Baldwin 22/06/2023
/*
Write a template function f() that adds the elements of one vector<T> to the elements of another; for example, f(v1,v2)
should do v1[i]+=v2[i] for each element of v1.
*/


#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

template<typename T>

vector<T> f(vector<T>v1, vector<T>v2)
{
	for (int i = 0; i < v2.size(); ++i)
	{
		v1[i] += v2[i];
	}
	return v1;

}

int main()

{
	vector<int>v1{1, 2, 3, 4, 5157};
	vector<int>v2{6, 7, 8, 9, 1045};



	v1 = f(v1, v2);

	for (const auto& element : v1)
	{
		cout << element << ' ';
	}


}