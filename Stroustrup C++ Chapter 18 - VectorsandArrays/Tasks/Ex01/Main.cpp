// Chapter 18 Ex 01
// Created by R J Baldwin 01/06/2023

// 1. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on the free store. 
//    Do not use any standard library functions.Do not use subscripting; use the dereference operator * instead.

#include <iostream>

char* Robstrdup(const char* str)
{
    // Find the length of the input string
    int size = 0;
    const char* p = str;
    while (*p != '\0') {
        size++;
        p++;
    }


    // Allocate memory for the new string (including the null terminator)
    char* heapArray = new char[size + 1];

    // Copy the characters from str to heapArray
    const char* p1 = str;
    char* p2 = heapArray;
    while (*p1 != '\0') {
        *p2 = *p1;
        p1++;
        p2++;
    }
    *p2 = '\0'; // Add the null terminator to the end

    return heapArray;
}

int main()
{
    const char str[]{ "Stolec!" };
    char* copiedStr = Robstrdup(str);
    std::cout << copiedStr << '\n';

    delete[] copiedStr; // Free the memory

    return 0;
}



