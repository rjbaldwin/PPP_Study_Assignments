// 5_7 logical errors page154.cpp : 
//

#include <iostream>
#include<vector>
#include "std_lib_facilities.h"

using namespace std;

// this commented design has logical flaws - 
//int main()
//{
//	vector<double>temps;
//	for (double temp; cin >> temp;)
//		temps.push_back(temp);
//
//	double sum = 0;
//	double high_temp = 0;
//	double low_temp = 0;
//
//	for (int x : temps)
//	{
//		if (x > high_temp) high_temp = x;
//		if (x < low_temp) low_temp = x;
//		sum += x;
//	}
//	cout << "High temperature: " << high_temp << '\n';
//	cout << "Low temperature: " << low_temp << '\n';
//	cout << "Avarage temperature: " << sum/temps.size() << '\n';
//}

//this is the corrected design from page 156


/*136 F was the highest recored temp in Libyan desert.  
the lowest was -126f vostok station */


int main()
{
	
	double sum = 0;
	double high_temp = -1000;		//inititalize to impossibly low;
	double low_temp = 1000;			//inititalize to impossibly high;
	int no_of_temps = 0;


	for (double temp; cin>>temp;)	//read temp
	{
		++no_of_temps;				//count temperatures
		sum += temp;
		if (temp > high_temp) high_temp = temp;	//find high
		if (temp < low_temp) low_temp = temp;	//find low
	}

	cout << "High temperature: " << high_temp << '\n';
	cout << "Low temperature: " << low_temp << '\n';
	cout << "Avarage temperature: " << sum / no_of_temps << '\n';
}


