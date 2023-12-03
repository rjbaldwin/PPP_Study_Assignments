
/*

3. Write a function, int strcmp(const char* s1, const char* s2), that compares C-style strings. Let it return a negative
number if s1 is lexicographically before s2, zero if s1 equals s2, and a positive number if s1 is lexicographically after
s2. Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead.


	Created by Robert J Baldwin 05/06/2023
*/

#include <iostream>


int strcmp(const char* s1, const char* s2)
{

	if (*s1 < *s2) return -1;		// if s1 comes before s2
	if (*s1 == *s2) return 0;		// if s1 is the same as s2
	if (*s1 > *s2) return 1;		// if s1 comes after s2;
	
}


int main()

{
	const char* s1 = "Danjo";
	const char* s2 = "Wanjo";

	int result = strcmp(s1, s2);

	std::cout << result;

	

}