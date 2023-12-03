// Chapter 10 Drill
//
// Created by Robert J Baldwin 14/03/2023

/*
DONE 1. Start a program to work with points, discussed in §10.4. Begin by defining the data type Point that has two coordinate members x and y.
DONE 2. Using the code and discussion in §10.4, prompt the user to input seven (x,y) pairs. As the data is entered, store it in a
vector of Points called original_points.
DONE 3. Print the data in original_points to see what it looks like.

DONE 4. Open an ofstream and output each point to a file named mydata.txt. On Windows, we suggest the .txt suffix to make
it easier to look at the data with an ordinary text editor (such as WordPad).

DONE 5. Close the ofstream and then open an ifstream for mydata.txt. Read the data from mydata.txt and store it in a new
vector called processed_points.

DONE 6. Print the data elements from both vectors.

7. Compare the two vectors and print Something's wrong! if the number of elements or the values of elements differ.
*/


#include <iostream>
#include "std_lib_facilities.h"


struct Point
{
	double mX{};
	double mY{};
	Point() = default;
	// constructor  
	Point(double x, double y):mX{ x },mY{ y }{}

};


// to provide cout << for Point class
 ostream& operator<<(ostream& os, const Point& p)
{
	os << "(" << p.mX << "," << p.mY << ")";
	return os;
}

// to provide cin >> for Point class
istream& operator>>(istream& is, Point& p)
{
	// Read in the x and y values and discard the parentheses and commas
	char ch1, ch2, ch3;
	double x, y;
	if (is >> ch1 >> x >> ch2 >> y >> ch3 && ch1 == '(' && ch2 == ',' && ch3 == ')') {
		p = Point(x, y);
	}
	else {
		is.clear(ios_base::failbit);
	}
	return is;
}








int main()
{

	// enter points
	vector<Point>original_points;
	cout << "Enter seven (x,y) pairs: \n";


	while (original_points.size() < 7)
	{
		Point points;
		cout << "Pair " << original_points.size() + 1 << '>';
		cin >> points;

		// check for wrong input
		if (cin.fail() || points.mX < 0 || points.mY < 0) // check for non double or negative input
		{
			cout << "Invalid input. Not a double, or negative values entered: Please try again.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignor rest of line 
		}
		else
		{
			original_points.push_back(points);
		}
	}

	// creating the file and ouputting vector contents to file

	string oname{ "mydata.txt" };
	cout << "file " << oname << " created: \n ";

	ofstream ost{ oname };		// ost is an output stream for a file named oname 
	if (!ost) error("cant open output file ", oname);

	cout << "Coordinate pairs\n";

	for (Point p : original_points)
	{
		cout << p << '\n';
		ost << p << '\n';  // outputs to file
	}
	ost.close();	// close the output stream 


	// open the file called mydata.txt


	string iname{ "mydata.txt" };
	cout << "Reading data from " << iname << " :\n";

	ifstream ifs;
	ifs.open(iname, ios_base::in);
	if (!ifs) error("cant open output file ", iname);


	vector<Point>processed_points;

	for (Point p; ifs >> p;){


		if (ifs.fail()) {
			cout << "Failed to read a point from file\n";
			break;
		}
	processed_points.push_back(p);
}
	cout << "Number of points read from file: " << processed_points.size() << '\n';

	for (const Point p : processed_points)
		cout << p << '\n';
	ifs.close();
	
	

	
	

}
