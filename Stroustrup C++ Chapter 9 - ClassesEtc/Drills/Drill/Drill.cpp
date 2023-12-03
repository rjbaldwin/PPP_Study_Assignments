/*This drill simply involves getting the sequence of versions of Date to work. 
For each version define a Date called today initialized to June 25, 1978. 
Then, define a Date called tomorrow and give it a value by copying today into it and
increasing its day by one using add_day(). 
Finally, output today and tomorrow using a << defined as in §9.8.
Your check for a valid date may be very simple. Feel free to ignore leap years. However, don’t accept a month that is not in
the [1,12] range or day of the month that is not in the [1,31] range. 
Test each version with at least one invalid date (e.g., 2004,
13, –5).
1. The version from §9.4.1
2. The version from §9.4.2
3. The version from §9.4.3
4. The version from §9.7.1
5. The version from §9.7.4*/





#include <iostream>
#include "std_lib_facilities.h"

// 1. The version from §9.4.1

struct Date {
    int y ;
    int m ;
    int d ;

};

// helper functions:
void init_day(Date& dd, int y, int m, int d) {
    if (m < 1 || m > 12) error("Invalid month! ");
    if (d < 1 || d > 31) error("Invalid day! ");
    
    dd.y = y;
    dd.m = m;
    dd.d = d;
    
}

void add_day(Date& dd, int n) {
    dd.d += n; // increase dd by n days
    if (dd.d > 31)
        dd.d %= 31;   // check this
}

// this is an output operator function definition to print out 
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

int main()
try {
    // 1. The version from §9.4.1
    Date today;
    init_day(today, 1978, 06, 25);

    cout << today << endl;

    Date tomorrow = today;
    add_day(tomorrow, 1);

    cout << tomorrow << endl;

}
catch (runtime_error& e) {
    cerr << "Runtime error motherfucker: " << e.what() << '\n';
    keep_window_open();
    return 1;	
}
