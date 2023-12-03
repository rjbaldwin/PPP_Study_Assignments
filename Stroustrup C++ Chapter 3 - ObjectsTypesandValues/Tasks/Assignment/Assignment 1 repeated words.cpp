// Assignment 1 repeated words.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

int main()
{
    int number_of_words = 0;
    string previous = "";       //previous word; initialised to "not a word"
    string current;         //current word
    while (cin >> current) {            //read a stream of words
        ++number_of_words;
        if (previous == current)        //check if the word is the same as last
            cout << "word number " << number_of_words
            << " repeated: " << current << '\n';
        previous = current;

    }
}

