// Ex 03.cpp : 05/02/2023 RJ Baldwin

// Create a vector of Fibonacci numbers and print them using the function from exercise 2.
 
// To create the vector, write a function, fibonacci(x,y,v,n), where integers x and y are ints, v is an empty vector<int>, and
// n is the number of elements to put into v; v[0] will be x and v[1] will be y.

// A Fibonacci number is one that is part of a sequence where each element is the sum of the two previous ones.
// For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . . .

// Your fibonacci() function should make such a sequence starting with its x and y arguments.

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

void print(const string& label, vector<int>& v) {

    cout << label << "Fiboncacci numbers: ";

    for (int i : v) {
        cout << i << ", ";
    }
}

void fibonacci(int x, int y, vector<int>& v, int n) {
    
    
   
    // first deal with low values of n:
    if (n < 1) return;
    if (1 <= n) v.push_back(x);
    if (1 <= 2) v.push_back(y);

    // here comes the real generation of a series:
    for (int i = 2; i < n; ++i) {	// why start at 2? because initially v[0]==x and v[1]==y
        int z = x + y;	// next element
        v.push_back(z);
        x = y;	// move the sequence on
        y = z;
    }
}



int main()

try
{
    
    int x = 0;
    int y = 0;
    vector<int>v;
    int n = 0;

    cout << "Enter first number in fibonacci sequence: \n";
    cin >> x;
    cout << "Enter second number in fibonacci sequence: \n";
    cin >> y;
    cout << "Enter number of elements in fibonacci sequence: \n";
    cin >> n;
    fibonacci(x, y, v, n);

    string label = "The Sequence is:  ";

    print(label, v);
}
catch (runtime_error e) {
    cout << e.what() << '\n';
    keep_window_open("~");
}

catch (...) {
    cout << "exiting\n";
    keep_window_open("~");
}

