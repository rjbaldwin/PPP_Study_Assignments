

#include <iostream>
#include <vector>

#include "std_lib_facilities.h"

using namespace std;




int main()
{
    double a = 0;
    double b = 0;

    double bigger=0, smaller=0;

    constexpr double tolerance = 1.0 / 100;


    while (cin >> a )//>> b)

    
        {
            if (a < b)
            {
                cout << "The smaller value is " << a << '\t' << "The bigger value is " << b << '\n';
                smaller = a;
                bigger = b;
            }

            else if (a > b)
            {
                cout << "The bigger value is " << a << '\t' << "The smaller value is " << b << '\n';
                bigger = a;
                smaller = b;

            }

            if (a == b)
            {
                cout << "The numbers " << a << " and " << b << " are the same" << '\n';
            }

            else if

                ((bigger - smaller) < tolerance)
            {
                cout << "The numbers are almost the same" << endl;
            }

            
        }
    
}
