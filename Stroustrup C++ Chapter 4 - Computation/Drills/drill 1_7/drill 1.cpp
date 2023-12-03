

#include <iostream>
#include <vector>

#include "std_lib_facilities.h"

using namespace std;




int main()
{
        
    double value = 0;
    string unit = " ";
    double temp = 0;

    //1 inch == 2.54 cm
    //1 foot == 12 inches
    //1 meter == 100 cm


    
    vector<double> values;
    vector<string> units;

    cout << "Please enter a value followed by a unit of measure: cm, in, ft, or m \n";
     
    while (cin >> value >> unit)

    {
        double temp = value;
        string tempUnit = unit;
        
        if (unit == "m") {}
        else if (unit == "cm")
            temp /= 100.00;
        else if (unit == "ft")
            temp /= 3.281;
        else if (unit == "in")
            temp /= 39.37;
        else {
            cout << "The value entered is not a valid unit \n";
        }
    }



    {
        values.push_back(temp);
        units.push_back(unit);
        sort(values);
        cout << "You entered " << value << unit <<'\n';
        cout << "The smallest value is " << values[0] << '\n';
        cout << "The largest value is " << values[values.size() - 1] << '\n';
    }
    
   
   
    keep_window_open();

    return 0;
    
    
}
