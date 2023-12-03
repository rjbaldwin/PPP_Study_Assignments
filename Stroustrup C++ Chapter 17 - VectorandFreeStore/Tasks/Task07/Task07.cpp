/*
7. Write a program that reads characters from cin into an array that you allocate on the free store. Read individual
characters until an exclamation mark (!) is entered. Do not use a std::string. Do not worry about memory exhaustion.
*/

#include <iostream>

int main() 
{
  
	const int size{10};
	char* charArray = new char[size] {}; // {} initialises with /0 null character.  This saves making a long intialiser list.
	
	
	std::cout << "Enter up to " << size << " characters.  ! to terminate: \n";
	
	for (int i = 0; i < size; ++i)
	{
		char input{};
		std::cin >> input;
		if (input == '!')
		{
			std::cout << "Input terminated.\n";
			break;
		}
		else
		{
			charArray[i] = input;
		}
	}

	std::cout << "Characters entred: \n";

	for (int i = 0; i < size; ++i)
	{
		std::cout << charArray[i] << ' ';
	}

	// don't worry about memory exaustion
	//delete[] charArray; // Free the allocated memory

}


