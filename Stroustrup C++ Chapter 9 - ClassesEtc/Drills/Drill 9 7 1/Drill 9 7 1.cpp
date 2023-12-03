// Drill 9 7 1.cpp : 

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

	void add_day(int n);
	Month month() { return m; };
	int day() { return d; }
	int year() { return y; }

private:
	int y;
	Month m;
	int d;
	//bool is_valid();		// return true if date is valid
};

//------------------------------------




Date::Date(int yy, Month mm, int dd) //constructor
	:y{ yy},
	m{mm },
	d{ dd }
{
	//if (!is_valid()) throw Invalid{};
}



//------------------------------------

//bool Date::is_valid()			// return true if date is valid
//{
//	if (m <1 || 12>m) return false;
//	//...
//}

//------------------------------------

void Date::add_day(int n) {
	d += n;
	if (d > 31) d %= 31;
}

//------------------------------------

ostream& operator<<(ostream& os,  Date& d);
//------------------------------------

ostream& operator<<(ostream& os,  Date& d) {
	
	os << '(' << d.year()
		<< ',' << int(d.month())

		<< ',' << d.day() << ')';

	return os;

	
}


int main()
try {
	// 1. The version from �9.4.3
	Date today(1982, Month::nov, 14);
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
