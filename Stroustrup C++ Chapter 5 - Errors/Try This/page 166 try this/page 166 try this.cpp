// page 166 try this.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

int area(int length, int width)
//calculate are of a rectangle
//pre-conditions: Length and width are positive
//post-condition: Returns a positive value that is the area
{
	if (length <= 0 || width <= 0) error("area() pre-condition");
	int a = length * width;
	if (a <= 0) error("area() post-condition");
	return a;
}

int main()
try {
	int length = 0;
	int width = 0;
	cin >> length >> width;

	area(length, width);

	cout << area(length, width)<<endl;
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "fuck: " << e.what() << '\n';
	keep_window_open();
	return 1;
}


