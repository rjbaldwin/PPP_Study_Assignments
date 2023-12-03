/*

7. Write versions of the cat_dot()s from the previous exercises to take C-style strings as arguments and return a free-store allocated C-style string as the result. 
Do not use standard library functions or types in the implementation. 
Test these functions with several strings. Be sure to free (using delete) all the memory you allocated from free store (using new).
Compare the effort involved in this exercise with the effort involved for exercises 5 and 6.

Created by Robert J Baldwin 06/06/2023

*/

#include <iostream>
#include <string>
using std::string;
using std::cout;




 char* cat_dot2(const char* s1, const char* space, const char* s2)
{
	 int len_s1{ 0 };
	 int len_separator{ 0 };
	 int len_s2{ 0 };

	 // calculate lengths of input strings - iterate through the index numbers until null

	 while (s1[len_s1] != '\0')
		 len_s1++;

	 while (space[len_separator] != '\0')
		 len_separator++;

	 while (s2[len_s2] != '\0')
		 len_s2++;



	 int totalLength{ len_s1 + len_separator + len_s2 + 1 }; // +1 for the null terminator - add the lengths up to find total length for concatenation

	 char* result = new char[totalLength+1]; // aplies how many chars we need based on total length 

	 int i{ 0 };

	 // copy s1 to result
	 while (s1[i] != '\0')
	 {
		 result[i] = s1[i];
		 i++;
	 }

	 // copy seperator to result

	 int j{ 0 };

	 while (space[j] != '\0')
	 {
		 result[i] = space[j];
		 i++;
		 j++;
	 }
	 
	 // copy s2 to result

	 int k{ 0 };

	 while (s2[k] != '\0')
	 {
		 result[i] = s2[k];
		 i++;
		 k++;
	 }

	 // add null character at the end
	 result[i] = '\0';

	 return result;
}



int main()

{
	
	

	char* result = cat_dot2("Robert", " ", "Baldwin");
	char* ptr = result;

	while (*ptr != '\0')
	{
		cout << *ptr;
		ptr++;
	}
	

	delete[] result; // Free the memory allocated by new[]

	return 0;

}