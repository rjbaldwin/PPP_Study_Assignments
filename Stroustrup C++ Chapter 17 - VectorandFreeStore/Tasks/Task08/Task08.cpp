/*
8. Do exercise 7 again, but this time read into a std::string rather than to memory you put on the free store (string knows
how to use the free store for you).
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;



int main()
{

	
	string stringInput{};


	std::cout << "Enter a string.\n";

	cin >> stringInput;

	


	std::cout << "Characters entred: \n";

	
		std::cout << stringInput << ' ';
	

	// don't worry about memory exaustion
	//delete[] charArray; // Free the allocated memory

}