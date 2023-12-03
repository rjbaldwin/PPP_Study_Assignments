// fib v 2.cpp : This programme calculates the fibonacci sequence upto a given number of places - RJBaldwin 06 Dec 2022
//

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

int main()
try
{


    //0 1 1 2 3 5 8 13 21 . . . 


    vector<int>fib;     //vector for fib values

    int limit = 0;
    int sum = 0;
    int l = 0;      //left side index
    int r = 0;      //right side index


    cout << "**Fibonacci Sequence**\n";
    cout << "Enter number of places to show..(max val 45)\n";
    cin >> limit;
    cout << endl;
    if (limit > 45) error("Value too high.  Value must be less than 46 - try again!");


    fib.push_back(0);
    fib.push_back(1);

    while (limit >= fib.size()) {

        sum = fib[l] + fib[r + 1];

        fib.push_back(sum);
        ++l;
        ++r;
    }

    //outputs the vector results 
    cout << "Fibonacci sequence: \n";
    for (int i : fib)
        if (i > 0)        //excludes zero from the output list
            cout << i << '\n';

}

catch (runtime_error e) {	// this code is to produce error messages
    cout << e.what() << '\n';


    keep_window_open("~");	// For some Windows(tm) setups

}