// 6_3_1_ First Attempt.cpp : From page 179 of PPP - 08 Dec 2022 RJ Baldwin
//

#include <iostream>
#include "std_lib_facilities.h"

int main()
{
	cout << "Please enter expression (we can handle +, -, * and /):\n";
	cout << "add an x to end expression (e.g., 1+2*3x): ";
	int lval = 0;
	int rval = 0;
	
	cin >> lval;

	if (!cin) error("no first operand");
	for (char op; cin >> op;) {
		if (op != 'x') cin >> rval;
		if (!cin) error("no second operand");
		switch (op) {
		case'+':
			lval += rval;
			break;
		case'-':
			lval -= rval;
			break;
		case'*':
			lval *= rval;
			break;
		case'/':
			lval /= rval;
			break;
		default:
			cout << "Result: " << lval << '\n';
			keep_window_open();
			return 0;

		}
	}
	error("bad expression");
	
}

