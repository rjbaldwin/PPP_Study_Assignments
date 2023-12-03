// temp_stats.cpp : Created by Robert J Baldwin 21/03/2023

/*3. Write a program that reads the data from raw_temps.txt created in exercise 2 into a vector and then calculates the
mean and median temperatures in your data set. Call this program temp_stats.cpp.*/

#include <iostream>
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


void operator<< (ostream& os, const Reading& data)
{
    os << data.hour << ' ';
    os << data.temperature << '\n';
}



int main()
{

    vector<Reading> temps;      //store the readings here
    int hour{};
    double temperature{};
    string fileName{ "raw_temps.txt" };
    ifstream ist{ fileName };
    if (!ist) error("Can't open input file", fileName);

    while (ist >> hour >> temperature) {
        if (hour < 0 || 23 < hour) error("Hour out of range");
        temps.push_back(Reading{ hour,temperature });
    }


    // copy temperature readings from vector into another vector 
    vector<double> temperature_values;

    for (const Reading& reading : temps) {
        temperature_values.push_back(reading.temperature);
    }

    // mean calculation 

    double sum{};
    double lval{};
    double mean{};
    for (double d : temperature_values)
    {
        sum += d;
    }

    cout << "Avarage temperature: " << sum / temps.size() << '\n';

    //Calculates median index value using standard formula (n+1)/2
    sort(temperature_values);
    double evenMedian{}, sumMedian{};
    evenMedian = temperature_values.size() + 1;
    sumMedian = evenMedian / 2;
    cout << "Median temperature: " << sumMedian << '\n';



}
    


   



   




