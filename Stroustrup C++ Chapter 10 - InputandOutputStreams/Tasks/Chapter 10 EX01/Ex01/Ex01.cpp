// Chapter 10 Task 01
// Created by Robert J Baldwin 19 March 2023

//1. Write a program that produces the sum of all the numbers in a file of 
// whitespace-separated integers.


#include <iostream>

#include "std_lib_facilities.h"
#include <vector>

void readInts(vector<int>& data, const string& name)
{
	cout << "Opening data.txt\n";
	string fileName{ "data.txt" };
	ifstream ist{ fileName };
	if (!ist) error("Can't open file ", fileName);
	for (int p; ist >> p;)
		data.push_back(p);
}

int getSum(const vector<int>& data)
{
	int sum{};
	for (int i{ 0 }; i < data.size(); ++i) {

		sum += data[i];
	}
	return sum;
}

int main()
{
	string fileName{};
	vector<int>data;

	readInts(data, fileName);

	int sum = getSum(data);

	cout << "Sum: " << sum;

}


