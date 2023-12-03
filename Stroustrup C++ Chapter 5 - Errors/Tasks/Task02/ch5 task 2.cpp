// ch5 task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;



double ctok(double c) // converts Celsius to Kelvin
{
	constexpr double kelvin = 273.15;
	constexpr double ab_zero = -273.15;

	double k = c + kelvin;
	if (c < ab_zero) 
		error("Input value is less than absolute zero");
	return k;		//return int		//error int instead of in name k - change int to double
										//missing colon
}

double ktoc(double kel) // converts K to C
{
	constexpr double kelvin = 273.15;
	constexpr double ab_zero = -273.15;

	double c2 = kel - kelvin;
	if (c2 < ab_zero)
		error("Input value is less than absolute zero");
	return c2;		
}



int main()

//Celsius to Kelvin
{
	double c = 0; // declare input variable

	cout << "**Celsius to Kelvin Conversion**\n";
	cout << "Enter C temperature: \n";
	cin >> c; // retrieve temperature to input variable
	

	double k = ctok(c); // convert temperature
	cout << k <<" Kelvin \n"; // print out temperature


//Kelvin to Celsius
	double kel = 0;	//declare kelvin input variable

	cout << "**Kelvin to Celsius Conversion**\n";
	cout << "Enter K temperature: \n";
	cin >> kel; // retrieve temperature to input variable

	double c2 = ktoc(kel);	//convert temperature
	cout << c2 << " Celsius \n"; // print out temperature

}