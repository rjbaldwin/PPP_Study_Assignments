#include <iostream>


// this function iterates through a char array looking for upper case letters.  It then adds 32 (the difference between upper and lower asci values) to the value and assigns this to the array.
// this action changes to lower case. 

void to_lower(char* s) // the char pointer allows to modify the original string directly
{
	if (s == NULL) return; // checks for the null pointer

	int asci{ 'a' - 'A' }; // the difference between asci values of upper case and lower case letters = 32

	for (int i = 0; s[i] != '\0'; ++i) // if not null, do the search until null termination.
	{

		if (s[i] >= 'A' && s[i] <= 'Z') // search for upper case chars between A to Z.  If there are any, add and assign 32
		{
			s[i] = s[i] + asci;
		}
	}
}


int main()
{

	char myString[]{ "Robert J Baldwin" };

	to_lower(myString);

	std::cout << myString;
}