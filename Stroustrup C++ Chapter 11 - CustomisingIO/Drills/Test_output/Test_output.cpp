/*
*1. Start a program called Test_output.cpp. Declare an integer birth_year and assign it the year you were born.
*2. Output your birth_year in decimal, hexadecimal, and octal form.
*3. Label each value with the name of the base used.
*4. Did you line up your output in columns using the tab character? If not, do it.
*5. Now output your age.
*6. Was there a problem? What happened? Fix your output to decimal.
*7. Go back to 2 and cause your output to show the base for each output.
*8. Try reading as octal, hexadecimal, etc.:

*cin >> a >>oct >> b >> hex >> c >> d;
*cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;

*Run this code with the input
*1234 1234 1234 1234Explain the results.

9. Write some code to print the number 1234567.89 three times, first using defaultfloat, then fixed, then scientific
forms. Which output form presents the user with the most accurate representation? Explain why.
10. Make a simple table including last name, first name, telephone number, and email address for yourself and at least five
of your friends. Experiment with different field widths until you are satisfied that the table is well presented.*/

// Created by Robert J Baldwin 22/03/2023

#include <iostream>
#include "std_lib_facilities.h"


int main()
{
    
    int birthYear{ 1982 };
    int age{ 40 };

    cout <<showbase << birthYear << "\t(decimal)"
        << hex << "\t" << birthYear << "\t(hexadecimal)"
        << oct << "\t" << birthYear << "\t(octal)"
        << dec << '\t' <<"Age: " << age;


    int a{}, b{}, c{}, d{};
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

}

