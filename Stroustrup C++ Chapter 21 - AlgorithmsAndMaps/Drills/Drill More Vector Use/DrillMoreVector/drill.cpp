// More Vector Use - Chapter 21 Drills 
// Created by RJ Baldwin

/*
More vector use:
1. Read some floating-point values (at least 16 values) from a file into a vector<double> called vd.
2. Output vd to cout.
3. Make a vector vi of type vector<int> with the same number of elements as vd; copy the elements from vd into vi.
4. Output the pairs of (vd[i],vi[i]) to cout, one pair per line.
5. Output the sum of the elements of vd.
6. Output the difference between the sum of the elements of vd and the sum of the elements of vi.
7. There is a standard library algorithm called reverse that takes a sequence (pair of iterators) as arguments; reverse vd,and output vd to cout.
8. Compute the mean value of the elements in vd; output it.
9. Make a new vector<double> called vd2 and copy all elements of vd with values lower than (less than) the mean into
   vd2.
10. Sort vd; output it again.

*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::vector;
using std::ifstream;
using std::string;
using std::ofstream;


// logic encapsulation helper functions: 


// Read file

ifstream open(const string& fileName)
{
	ifstream fileIn{ fileName };
	if (!fileIn) { std::cerr << "File error! \n";}

	return fileIn;
}


// print 
template<typename T>
void printData(const vector<T>& v)
{
	cout << "Vector contents: \n";
	cout << "----------------\n";
	for (auto results : v)
	{
		cout << results << '\n';
	}
}


// fill container 
template<typename T, typename Val>
void fillContainer(vector<T>& boxOfData, Val& dataIn)
{
	boxOfData.push_back(dataIn);
}


// output sum
template<typename T>
void containerTotal(const vector<T>& v)
{
	T sum{ 0 };
	for (auto& val : v)
	{
		sum += val;
	}
	cout << "Sum of values: " << sum << '\n';
}

// difference
template<typename T1, typename T2>
void difference(const vector<T1>& vlhs, const vector<T2>& vrhs)
{
	T1 sumlhs{ 0 };
	for (auto& val : vlhs)
	{
		sumlhs += val;
	}
	T2 sumrhs{ 0 };
	for (auto& val : vrhs)
	{
		sumrhs += val;
	}

	auto result{ sumlhs - sumrhs };

	cout << "Difference = " << result << '\n';
}

// mean
template<typename T>
T meanTotal(const vector<T>& v)
{
	T sum{ 0 };
	
	for (auto& val : v)
	{
		sum += val;
	}
	return sum/v.size();
}

int main()

{
	// 1. Read some floating-point values (at least 16 values) from a file into a vector<double> called vd.

	ifstream fileIn = open("data.txt");

	vector<double> vd;

	double data{};
	while (fileIn >> data)
	{
		fillContainer(vd, data);
	}

	// 2. Output vd to cout.
	printData(vd);
	cout << '\n';

	// close the file
	fileIn.close();


	// 3. Make a vector vi of type vector<int> with the same number of elements as vd; copy the elements from vd into vi.
	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());

	printData(vi);
	cout << '\n';

	// 5. Output the sum of the elements of vd.
	cout << "Output the sum of the elements of vd.\n";
	containerTotal(vd);
	cout << '\n';

	// 6. Output the difference between the sum of the elements of vd and the sum of the elements of vi.
	cout << "Output the difference between the sum of vd and vi. \n";
	difference(vd, vi);
	cout << '\n';

	// 7. There is a standard library algorithm called reverse that takes a sequence 
	//    (pair of iterators) as arguments; reverse vd,and output vd to cout.

	cout << "Reverse vd,and output vd to cout.\n";
	std::reverse(vd.begin(), vd.end());
	printData(vd);
	cout << '\n';

	// 8. Compute the mean value of the elements in vd; output it.
	auto mean{ meanTotal(vd) };
	cout <<"Mean total: " << mean << '\n';
	cout << '\n';

	// 9. Make a new vector<double> called vd2 and copy all elements of vd with values lower than (less than) the mean into
	//    vd2.
	cout << "Make a new vector<double> called vd2 and copy all elements of vd with values lower than (less than) the mean\n";

	vector<double> vd2;
	
	auto lessThanMean = [mean](double value) { return value < mean; };  // returns bool for predicate. 


	copy_if(vd.begin(), vd.end(), std::back_inserter(vd2), lessThanMean);
	printData(vd2);
	cout << '\n';

	// 10. Sort vd; output it again.

	cout << "VD sorted: \n";
	sort(begin(vd), end(vd));
	printData(vd);
	


} 