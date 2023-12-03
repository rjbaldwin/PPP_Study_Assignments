// Task 6.cpp : Convert from celsius to fahrenheit to celsius.  29 nov 2022 rjbaldwin - Version 2
//

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

double CtoF(double temp)	//converts celcius to fahrenheit
{
	double f = (temp * 9 / 5) + 32;
	return f;			//return double
}

double FtoC(double temp)	//converts F to C
{
	double c = (temp - 32) * 5 / 9;
	return c;			//return double
}



int main()
{

	//v2 code

	double f = 0;
	double c = 0;
	char unit = ' ';
	double temp = 0;
	double sum = 0;

	cout << "**Temperature Conversion V2.0**\n";
	cout << "Enter temperature followed by unit required - (c)elsius or (f)ahrenheit: \n";
	cin >> temp >> unit;

	switch (unit) {
	case 'c':
		sum = FtoC(temp);
		cout << sum << " Celsius\n";
		break;
	
	case 'f':
		sum = CtoF(temp);
		cout << sum << " Fahrenheit\n";
		break;

	default:
		cout << "Invalid unit\n";
	}
	

}


