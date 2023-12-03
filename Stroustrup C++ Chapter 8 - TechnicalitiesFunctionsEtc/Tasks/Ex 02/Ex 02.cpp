/* Chapter 8 task 2 - 05 / 02 / 2023 RJ Baldwin :

Write a function print() that prints a vector of ints to cout.  
Give it two arguments: a string for “labeling” the output and a vector. */

#include <iostream>
#include "std_lib_facilities.h"
#include <vector>

void print(const string& label,vector<int>& v ) {
    
    cout<< label<<": ";

    for (int i : v) {
        cout << i << ", ";
    }

}

int main()
{
    vector<int>v = { 10,20,30,40,50 };
    print("V Values ", v);

    return 0;
}


