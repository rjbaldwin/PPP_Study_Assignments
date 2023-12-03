/*

5. Write a function, string cat_dot(const string& s1, const string& s2), that concatenates two strings with a dot in
between. For example, cat_dot("Niels", "Bohr") will return a string containing Niels.Bohr.

Created by Robert J Baldwin 06/06/2023

*/

#include <iostream>
#include <string>
using std::string;
using std::cout;


string cat_dot(const string& s1, const string& s2)
{

	string left{s1};
	string right{ s2 };
	string combo = left + '.' + right;

	return combo;

}



int main()

{
	/*const string s1{ "Robert" };
	const string s2{ "Baldwin" };*/

	string newCombo = cat_dot("Robert", "Baldwin");

	cout << newCombo;


}