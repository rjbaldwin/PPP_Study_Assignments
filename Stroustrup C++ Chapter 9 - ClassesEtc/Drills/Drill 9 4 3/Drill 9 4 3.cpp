// Drill 9 4 3.cpp 


#include <iostream>
#include "E:\06_Programming Work\Stroustrup C++ Chapter Exercises\PPP-chapter-tasks\std_lib_facilities.h"



    // simple Date (control access)
    class Date
    {

    public:
        // constructor
        Date(int y, int m, int d);

        void add_day(int n);
        int month() { return m; }
        int day() { return d; }
        int year() { return y; }

    private:
        int y, m, d;        //year, month, date

    };

    ostream& operator<<(ostream& os, Date& d)
    {
        return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day() << ')';
    }






    // member function definition for Date (outside of class)
    Date::Date(int yy, int mm, int dd)

        :y{ yy }, m{ mm }, d{ dd } {

    }

    // member function definition for add_day (outside of class)
    void Date::add_day(int n) {
        d += n;
        if (d > 31) d %= 31;
    }

//******************************************

int main()
try {
    // 1. The version from �9.4.3
    Date today(1978, 6, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << "Today:    " << today << endl;
    cout << "Tomorrow: " << tomorrow << endl;

}
catch (runtime_error& e) {
    cerr << "Runtime error : " << e.what() << '\n';
    keep_window_open();
    return 1;
}
