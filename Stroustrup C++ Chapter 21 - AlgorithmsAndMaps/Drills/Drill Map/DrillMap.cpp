// chapter 21 Drills - created by rj baldwin 18/07/2023
/*
1. Define a map<string,int> called msi. *
2. Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21. *
3. Output the (name,value) pairs to cout in some format of your choice. *
4. Erase the (name,value) pairs from msi. *
5. Write a function that reads value pairs from cin and places them in msi.
6. Read ten pairs from input and enter them into msi.
7. Write the elements of msi to cout.
8. Output the sum of the (integer) values in msi.
9. Define a map<int,string> called mis.
10. Enter the values from msi into mis; that is, if msi has an element ("lecture",21), mis should have an element
	(21,"lecture").
11. Output the elements of mis to cout.

*/



#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>

using std::map;
using std::cout;
using std::cin;
using std::string;

// print helper
template<typename T1, typename T2>
void print(const map<T1, T2>& m)
{
	cout<<"\t*** MAP CONTENTS *** \n";

	if (m.empty()) 
	{
		std::cout << "Map empty\n";
	}
	else 
	{
		for (auto& val : m)
		{
			cout << val.first << " : " << val.second << '\n';
		}
	}
}


// 5. Write a function that reads value pairs from cin and places them in msi.
// 
// data entry function (V1)

void dataEntryV1(map<string, int>& msi)
{
	cout << "Enter a string value: \n";
	string key{};
	cin >> key;
	

	cout << "Enter an int value: \n";
	int value{};
	cin >> value;

	msi[key] = value;

}

// 6. Read ten pairs from input and enter them into msi.
// 
// data entry function (V2)

void dataEntryV2(map<string, int>& msi)
{
	
	
	for (int counter = 10; counter > 0; --counter)
	{
		cout << "Enter " << counter << " string:int pairs.\n";
		string key{};
		int value{};

		cin >> key >> value;

		msi[key] = value;
	}

}

// 8. Output the sum of the (integer) values in msi.
//
// total values function

void valTotal(map<string, int>& msi)
{
	int sum{ 0 };
	for (const auto& pair : msi)
	{
		sum += pair.second;
	}
	cout << "Sum of values: " << sum << '\n';
}

// 8. As above - Using accumulate()

void valTotal2(map<string, int>& msi)
{
	int sum = accumulate(msi.begin(), msi.end(), 0,
		[](int currentSum, const std::pair<std::string, int>& pair) {
			return currentSum + pair.second;
		});

	std::cout << "Sum of values: " << sum << '\n';
}


// 10. Enter the values from msi into mis; that is, if msi has an element ("lecture",21), mis should have an element
//     (21, "lecture").


void copyMap(map<int, string>& lhs, map<string, int> rhs)
{
	for (auto& val : rhs)
	{
		lhs[val.second] = val.first;
	}
}





int main()
{
	// 1. Define a map<string,int> called msi.
	map<string, int> msi;

	// 2. Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21.
	msi["Odchody"] = 101;
	msi["Stolec"] = 4502;
	msi["Cipa"] = 603;
	msi["Sromowe"] = 54304;
	msi["Wargi"] = 505;
	msi["Kal"] = 716;
	msi["Lechtaczka"] = 75;
	msi["Kleks"] = 908;
	msi["AleUrwal"] = 10;
	msi["Kurwa"] = 310;

	// 3. Output the (name,value) pairs to cout in some format of your choice.

	print(msi);

	cout << '\n';
	// 4. Erase the (name,value) pairs from msi.

	msi.clear();
	print(msi);
	cout << '\n';
	cout << '\n';

	// 5. Write a function that reads value pairs from cin and places them in msi.
	dataEntryV1(msi);
	print(msi);
	cout << '\n';
	cout << '\n';
	// 6. Read ten pairs from input and enter them into msi.
	cout << "Read ten pairs from input and enter them into msi.\n";
	dataEntryV2(msi);
	print(msi);
	cout << '\n';


	// 8. Output the sum of the (integer) values in msi.
	valTotal(msi);
	valTotal2(msi);

	// 9. Define a map<int,string> called mis.
	cout << "Copying from msi to mis \n";


	// 10. Enter the values from msi into mis; that is, if msi has an element ("lecture",21), mis should have an element
	//	   (21, "lecture").

	map<int, string> mis;
	copyMap(mis, msi);
	print(mis);

	
	
}