// try this pg 153.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

//void error(string s)
//{
//	throw runtime_error(s);
//}

int main()
try {
	vector<int> v;
	for (int i; cin >> i;)
		v.push_back(i);
	for(int i = 0; i<=v.size(); ++i)
		cout<<"v["<<i<<"] == "<<v[i]<<'\n';
}
catch (out_of_range) {
	cerr << "Oops! Range error\n";
	return 1;

}
catch (...) {
	cerr << "Exception: The proverbial hit the fan!\n";
	return 2;
}

