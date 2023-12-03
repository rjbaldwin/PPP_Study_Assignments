// ch 5 task 8.cpp : compute sum of first N integers - rjbaldwin 04 12 22
//

#include <iostream>
#include "std_lib_facilities.h"
#include <vector>
#include <numeric>
using namespace std;

int main()
try 
{
        int N = 0;
        int input = 0;
        int sum = 0;

        vector<int>vect;
      
        cout << "Enter N number of values one wishes to calculate\n";
        cin >> N;
        cout << "Enter some integer values (press '|' to stop): \n";
        for (int input; cin >> input;)
            vect.push_back(input);


        N = N - 1;  //calculates correct index value offset 

        for (int i = 0; i <= N; ++i)
            sum += vect[i];
        if (vect.size() < N) error("too few numbers; we need ", N);
        
        else

            cout << sum <<'\n';
    }
    catch (exception& e) {
        cerr << "N greater than number of elements\n" << e.what() << '\n';
        keep_window_open();
        
        return 1;
        
    }


