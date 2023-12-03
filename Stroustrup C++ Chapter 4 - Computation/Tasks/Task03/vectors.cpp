

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

int main()
{
	vector<double>distances;

	cout << "Enter a number of distances - hit+| to terminate and print results: \n";

//input distances into vector 
	for (double distance; cin >> distance;)
		distances.push_back(distance);


//calculate and print total and mean distances
	double total = 0;
	for (int x : distances) total += x;
	cout << "Total distance covered: " << total << '\n';
	cout << "The mean distance covered: " << total / distances.size() << '\n';

//calculate smallest and greatest distances

	sort(distances);

	cout << "Smallest distance covered = " << distances[0] << '\n';
	cout <<"Greatest distance covered = " << distances[distances.size() - 1]<<'\n';
	
}


