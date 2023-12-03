// ch 4 tsk19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdbool.h>

using namespace std;

int main()
{
	vector<string>names;
	vector<int>scores;
	string namesIn = " ";
	int scoresIn = 1;
	int noName = 1;

	cout << "Enter name and score: \n";

	while (namesIn != "NoName" && scoresIn != 0)
	{
		cout << "First Name?\n";
		cin >> namesIn; 
		cout << "Score?\n";
		cin >> scoresIn;
		names.push_back(namesIn);
		scores.push_back(scoresIn);

	}




	for (int i = 0; i < names.size()-1; ++i) //excludes the termination word from the list

		

		cout << names[i] << " " << scores[i] << '\n';





}
