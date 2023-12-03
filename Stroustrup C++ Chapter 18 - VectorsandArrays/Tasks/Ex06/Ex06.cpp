/*

6. Modify cat_dot() from the previous exercise to take a string to be used as the separator (rather than dot) as its third
argument

Created by Robert J Baldwin 06/06/2023

*/

#include <iostream>
#include <string>
using std::string;
using std::cout;


string cat_dot(const string& s1,const string& space, const string& s2)
{
	string combo = s1 + space + s2;

	return combo;

}



int main()

{
	/*const string s1{ "Robert" };
	const string s2{ "Baldwin" };*/

	string newCombo = cat_dot("Robert"," ", "Baldwin");

	cout << newCombo;


}