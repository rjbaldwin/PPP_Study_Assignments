// EX02.cpp : Created by Robert J Baldwin 19/03/2023
//
/*2. Write a program that creates a file of data in the form of the temperature 
Reading type defined in §10.5. 
For testing, fill the file with at least 50 “temperature readings.” 
Call this program store_temps.cpp and the file it creates
raw_temps.txt.*/

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

struct Reading 
{       // a temperature reading
    int hour;                       // hour after midnight [0:23]
    double temperature;             // in Fahrenheit
    
    Reading(int, double);
    Reading() = default;

    friend void operator<< (ostream& os, const Reading& data);
};



Reading::Reading(int hour, double temperature)
    :hour{ hour },
    temperature{ temperature } {};



void getInfo()
{
    vector<Reading> temps;      //store the readings here
    int hour{};
    double temperature{};
    string fileName{ "data.txt" };
    ifstream ist{ fileName };
    if (!ist) error("Can't open input file", fileName);

    while (ist >> hour >> temperature) {
        if (hour < 0 || 23 < hour) error("Hour out of range");
        temps.push_back(Reading{ hour,temperature });
    }

    // output file called raw_temps.txt
    
    string oFile{ "raw_temps.txt" };
    ofstream fileOut{ oFile };

    if (!fileOut) error("Can't open output file", oFile);

    // print info to see if the data/code works 
    for (Reading r : temps)
    {
        cout << r;
        fileOut << r;
    }
}




void operator<< (ostream& os, const Reading& data)
{
    os << data.hour <<' ';
    os << data.temperature <<'\n';
}



int main()
{
    
    getInfo();


}


