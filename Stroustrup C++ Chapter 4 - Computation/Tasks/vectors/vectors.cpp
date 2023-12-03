

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

int main()
{
	vector<double>temps;
	double evenMedian = 0, sumMedian = 0;


	for (double temp; cin >> temp;)
		temps.push_back(temp);

	double sum = 0;
	for (int x : temps) sum += x;
	cout << "Avarage temperature: " << sum / temps.size() << '\n';

	//Calculates median index value using standard formula (n+1)/2
	sort(temps);
	evenMedian = temps.size() + 1;
	sumMedian = evenMedian / 2;
	cout << "median temperature: " << sumMedian << '\n'; 				


}


