/*Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.
The first reverse function should produce a new vector with the reversed sequence, leaving its original vector
unchanged. The other reverse function should reverse the elements of its vector without using any other vectors 
(hint:swap).*/


#include <iostream>
#include <vector>
#include "std_lib_facilities.h"


// reverse function 01
void reverse01(vector<int>& v){

	vector<int>v2;
	int i = v.size() - 1;

	while (i >= 0) {
		v2.push_back(v[i]);
		--i;
	}

	for (int i : v2) {
		cout << i << ", ";
	}
}


// reverse function 02
void reverse02(vector<int>& v) {
	
	int i = 0;
	

	while (i < v.size() - 1 - i) {
		
		int x = 0;
		
		swap(v[i], v[v.size()-1-i]);
		++i;
	}

	for (int i : v) {
		cout << i << ", ";
	}

}


int main()
{
	cout << "Original values: \n";

	vector<int>values = { 9,10,11,12 };

	for (int i : values) {		//print original vector values
		cout << i << ", ";
	}
	cout << '\n';

	//---------------------------------------------------------------------------------------------------------------
	cout << "Reverse 01 Function: \n";

	reverse01(values);		//reverse01 reverses values and prints in reversed order
	cout << '\n';
	//---------------------------------------------------------------------------------------------------------------

	cout << "Original values after function call: \n";

	for (int i : values) {		//print original vector values to see if they have been altered
		cout << i << ", ";
	}
	cout << '\n';
	//---------------------------------------------------------------------------------------------------------------
	cout << "Reverse 02 Function: \n";

	reverse02(values);		
	cout << '\n';



}
	