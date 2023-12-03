/*Read five names into a vector<string> name, 
then prompt the user for the ages of the people named and store the ages in a vector<double> age. 
Then print out the five (name[i],age[i]) pairs. Sort the names
(sort(name.begin(),name.end())) and print out the (name[i],age[i]) pairs. 

The tricky part here is to get the age vector in the correct order to match the sorted name vector. 

Hint: Before sorting name, take a copy and use that to
make a copy of age in the right order after sorting name. 

Then, do that exercise again but allowing an arbitrary number
of names.*/




#include <iostream>
#include <vector>
#include "std_lib_facilities.h"




void pairs(string, double) {

	vector<string>names;
	vector<double>ages;
	string nameIn = " ";
	int ageIn = 1;
	int noName = 1;

	cout << "Enter name and age pairs: \n";

	while (nameIn != "NoName" && ageIn != 0)
	{
		cout << "First Name?\n";
		cin >> nameIn;
		cout << "Age?\n";
		cin >> ageIn;
		names.push_back(nameIn);
		ages.push_back(ageIn);

	}

	cout << "How the data was input: \n";
	for (int i = 0; i < names.size() - 1; ++i) //excludes the termination word from the list
		cout << names[i] << " " << ages[i] << '\n';

	//------------------------------------------------------


	//copy the vectors

	vector<string>nameCopy = names;
	vector<double>ageCopy = ages;

	cout << "Copied pairs: \n";
	for (int i = 0; i < nameCopy.size(); ++i) {
		cout << nameCopy[i] << " " << ageCopy[i] << '\n';
	}
	//------------------------------------------------------

	// Sorted name

	sort(names.begin(), names.end());

	cout << "/************************************* \n";
	for (int i = 0; i < names.size(); ++i) {
		for (int j = 0; j < names.size(); ++j) {
			if (names[i] == nameCopy[j]) {
				ages[i] = ageCopy[j];
				break;
			}
		}

	}

	cout << "Correctly Sorted pairs: \n";
	for (int i = 0; i < names.size(); ++i) {
		if(names[i]!="Noname")
		cout << names[i] << " " << ages[i] << '\n';
	}


}


int main()
{
	string nameIn = " ";
	int ageIn = 1;
	
	cout << "Read five names and five ages into vector \n";

	pairs(nameIn, ageIn); //this function will execute everythin in the definition as thoug it were part of the main() loop instead


}


