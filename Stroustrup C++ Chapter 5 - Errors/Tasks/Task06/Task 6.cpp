// Task 6.cpp : Convert from celsius to farenheit to celsius.  29 nov 2022 rjbaldwin
//

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

double CtoF(double c)	//converts celcius to farenheit
{
	double f = (c * 9 / 5) + 32;
	return f;			//return double
}	

double FtoC(double f2)	//converts F to C
{
	double c2 = (f2-32) * 5/9;
	return c2;			//return double
}



int main()
{
	//Celsius conversion programme

	double c = 0;	//declare input variable for Celsius
	double f2 = 0;	//declare input variable for Farenheit
	
	cout << "**Celsius to Farenheit to Celsius Converion**\n";
	cout << "Enter temperature in Celsius: \n";
	cin >> c;
	double f = CtoF(c); //conversion function assigns to variable
	cout << f << " Farenheit\n";

	//Farenheit conversion programme
	cout << "Enter temperature in Farenheit: \n";
	cin >> f2;

	double c2 = FtoC(f2); //conversion function assigns to variable
	cout << c2 << " Celsius\n";
}


