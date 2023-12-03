// Ex 06.cpp : Write versions of the functions from exercise 5, but with a vector<string>.
//

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"


// reverse function 01
void reverse01(vector<string>& v) {

	vector<string>v2;
	int i = v.size() - 1;

	while (i >= 0) {
		v2.push_back(v[i]);
		--i;
	}

	for (string s : v2) {
		cout << s << ", ";
	}
}


// reverse function 02
void reverse02(vector<string>& v) {

	int i = 0;


	while (i < v.size() - 1 - i) {

		int x = 0;

		swap(v[i], v[v.size() - 1 - i]);
		++i;
	}

	for (string s : v) {
		cout << s << ", ";
	}

}


int main()
{
	cout << "Original values: \n";

	vector<string>strings = { "One","Two","Three","Four"};

	for (string s : strings) {		//print original vector values
		cout << s << ", ";
	}
	cout << '\n';

	//---------------------------------------------------------------------------------------------------------------
	cout << "Reverse 01 Function: \n";

	reverse01(strings);		//reverse01 reverses values and prints in reversed order
	cout << '\n';
	//---------------------------------------------------------------------------------------------------------------

	cout << "Original values after function call: \n";

	for (string s : strings) {		//print original vector values to see if they have been altered
		cout << s << ", ";
	}
	cout << '\n';
	//---------------------------------------------------------------------------------------------------------------
	cout << "Reverse 02 Function: \n";

	reverse02(strings);
	cout << '\n';



}

