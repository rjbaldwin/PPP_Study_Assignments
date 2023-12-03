

#include <iostream>
#include <vector>

#include "std_lib_facilities.h"

using namespace std;




int main()
{
        
    double value = 0;
    
    vector<double> v;

    cout << "Please enter a value \n";
     
    while (cin >> value)
    {
        v.push_back(value);
        sort(v);
        cout << "You entered " << value <<'\n';
        cout << "The smallest value is " << v[0] << '\n';
        cout << "The largest value is " << v[v.size() - 1] << '\n';
    }
    
   
   
    keep_window_open();

    return 0;
    
    
}
