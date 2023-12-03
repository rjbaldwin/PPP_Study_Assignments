/*This drill simply involves getting the sequence of versions of Date to work.
For each version define a Date called today initialized to June 25, 1978.
Then, define a Date called tomorrow and give it a value by copying today into it and
increasing its day by one using add_day().
Finally, output today and tomorrow using a << defined as in �9.8.
Your check for a valid date may be very simple. Feel free to ignore leap years. However, don�t accept a month that is not in
the [1,12] range or day of the month that is not in the [1,31] range.
Test each version with at least one invalid date (e.g., 2004,
13, �5).

2. The version from �9.4.2
3. The version from �9.4.3
4. The version from �9.7.1
5. The version from �9.7.4*/





#include <iostream>
#include "std_lib_facilities.h"

// 1. The version from �9.4.2

struct Date {
    int y, m, d;        // year, month, day
    Date(int y, int m, int d);  // check for valid date and initialise
    void add_day(int n);        // increase the Date by n days
    

};

// member function definition for Date (outside of class)
Date::Date(int yy, int mm, int dd) 
   
    :y{ yy }, m{ mm }, d{ dd } {    
    /*is the same as{
    y = yy;
    m = mm;
    d = dd;
    }
    */
}

// member function definition for add_day (outside of class)
void Date::add_day(int n) {
    d += n;
    if (d > 31) d %= 31;
}





// this is an output operator function definition to print out 
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

int main()
try {
    // 1. The version from �9.4.2
    Date today(1978, 6, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << "Today:    " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

}
catch (runtime_error& e) {
    cerr << "Runtime error motherfucker: " << e.what() << '\n';
    keep_window_open();
    return 1;
}

