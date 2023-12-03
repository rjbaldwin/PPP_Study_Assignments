/*
02. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in
s. Do not use any standard library functions. Do not use subscripting; use the dereference operator * instead.

Robert J Baldwin 05/06/2023


** NOTES **

compare 2 c style strings for matching characters, eg hello world, world.
write function char* findx(const char* s, const char* x)
find x in s
in main(), create two c-style strings, s[]{world}
and x[]{hello world}
call the findx() function and pass s & x
the function shoult RETURN

inside the function:
const char* p1 = *x
const char* p2 = *s
find size of s

for any matches, copy to new c-style string
increase the counter each time and output the value at the first char match.


*/

#include <iostream>

const char* findx(const char* s, const char* x) {
    if (*x == '\0') // If x is an empty string, return s
        return s;

    while (*s) {
        const char* p1 = s;
        const char* p2 = x;

        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (*p2 == '\0') // All characters in x matched
            return s;

        s++;
    }

    return nullptr; // x not found in s
}

int main() {
    const char* s = "hello world";
    const char* x = "world";

    const char* result = findx(s, x);
    if (result)
        std::cout << "Match found at index " << result - s << std::endl;
    else
        std::cout << "No match found." << std::endl;


    return 0;
}
