// Drill 9 7 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "E:\06_Programming Work\Stroustrup C++ Chapter Exercises\PPP-chapter-tasks\std_lib_facilities.h"




enum class Month {
	jan = 1,
	feb,
	mar,
	apr,
	may,
	jun,
	jul,
	aug,
	sep,
	oct,
	nov,
	dec
};

//------------------------------------


class Date {
public:
	class Invalid {};	// to be used as exception

	// constructor
	Date(int yy, Month mm, int dd);

	
	
	int year() const { 
		return y; 
	}

	Month month() const { 
		return m; 
	};

	int day() const {
		return d; 
	}

	void add_day(int n);		// non-const member: can modify the object
	void add_month(int n);		// non-const member: can modify the object
	void add_year(int n);		// non-const member: can modify the object


private:
	int y;
	Month m;
	int d;
	bool is_valid();		// return true if date is valid
};

//------------------------------------




Date::Date(int yy, Month mm, int dd) //constructor
	:y{ yy },
	m{ mm },
	d{ dd }
{
	if (!is_valid()) throw Invalid{};
}



//------------------------------------

bool Date::is_valid()			// return true if date is valid
{
	if (d <1 || d>31) return false;
	if (m<Month::jan || m>Month::dec) return false;

	return true;
}

//------------------------------------

void Date::add_day(int n) {
	d += n;
	if (d > 31) d %= 31;
}

//------------------------------------


void Date::add_month(int n) {
	// add n to month

	int nextMonth = 0;

	if ((nextMonth = int(m) + n) > 12) {  // int(m) is typecasting so date enum can add number to nextMonth
		m = Month::jan;
	}
	else {
		m = Month(nextMonth);
	}
}


//------------------------------------

	void Date::add_year(int n) {
		// add n to year
		y += n;

	}

//------------------------------------

ostream& operator<<(ostream& os, Date& d);
//------------------------------------

ostream& operator<<(ostream& os, Date& d) {

	os << '(' << d.year()
		<< ',' << int(d.month())

		<< ',' << d.day() << ')';

	return os;


}


int main()
try {
	// 1. The version from �9.7.4


	Date today(1998,Month::jan,10);

	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << "Today:    " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

}
catch (runtime_error& e) {
	cerr << "Runtime error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}


