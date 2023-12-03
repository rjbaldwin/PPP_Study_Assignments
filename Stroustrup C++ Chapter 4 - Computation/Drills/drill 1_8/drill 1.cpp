//-----My first programme actually using pseudocode to work the problem out.  I was fucking chuffed when I started understanding this task
//-----R J Baldwin October 2022
//
#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

int main()
{   
    double value = 0, tempValue = 0;
    string unit = " ";
    vector<double> v;       //for storing initial values
    vector<double> vMeters; //for storing values that have been converted to meters
    cout << "**-----------------------------------------------------------**\n";
    cout << "Please enter a number followed by a unit 'cm' 'm' 'in' or 'ft' \n";
     
    while (cin >> value >> unit)
    {
        v.push_back(value);
        sort(v);
        
        if (unit == "cm")
        {
            cout << "You entered " << value << unit << '\n';

            tempValue = value / 100;                        //convert unit to meters and assign to tempValue
            vMeters.push_back(tempValue);                   //input tempValue to vMeters vector
            
        }

        else if (unit == "m")
        {
            cout << "You entered " << value << unit << '\n';

            tempValue = value / 1;                        //convert unit to meters and assign to tempValue
            vMeters.push_back(tempValue);                   //input tempValue to vMeters vector
            
        }
        else if (unit == "in")
        {
            cout << "You entered " << value << unit << '\n';

            tempValue = value / 39.37;                        //convert unit to meters and assign to tempValue
            vMeters.push_back(tempValue);                   //input tempValue to vMeters vector
            
        }
        else if (unit == "ft")
        {
            cout << "You entered " << value << unit << '\n';

            tempValue = value / 3.281;                        //convert unit to meters and assign to tempValue
            vMeters.push_back(tempValue);                   //input tempValue to vMeters vector
           
        }
        else
            cout << "Incorrect Unit \n";
            cout << "The smallest value is " << v[0] << '\n';
            cout << "The largest value is " << v[v.size() - 1] << '\n';
         
            cout << "//-----------------------------------------------------------//\n";
            cout << "Number of values entered = "<<vMeters.size() << '\n';
            cout << "//-----------------------------------------------------------//\n";
            cout << '\t' << "Elements in vMeters vector (shown in Meters)\n";

            sort(vMeters);          //sort vMeters for final total output
 
            for (int i = 0; i < vMeters.size(); ++i) {

                cout << '\t' << vMeters[i] << '\n';

            }
            cout << "//-----------------------------------------------------------//\n";
            double sum = 0;
            for (double x : vMeters) sum += x; {                                            //totals up the elements of the vector and places into sum
                cout << "Total Meters = " << sum<<"m" << '\n'<<'\n';
                
                cout << "**-----------------------------------------------------------**\n\n\n";
                cout << "Please enter a number followed by a unit 'cm' 'm' 'in' or 'ft' \n";
            }                   
         }
    
    keep_window_open();

    return 0;
}
