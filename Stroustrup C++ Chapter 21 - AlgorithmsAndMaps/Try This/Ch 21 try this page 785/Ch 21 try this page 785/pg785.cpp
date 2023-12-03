// Chapter 21.6 Try this - ppp using cpp
// created by rj baldwin 17/07/2023

#include <iostream>
#include <string>
#include <map>
#include <numeric>
#include <functional>

using std::map;
using std::string;
using std::cout;
using std::pair;

double weighted_value(const pair<string, double>& a, const pair<string, double>& b)	// extract values and multiply
{
	return a.second* b.second;
}

int main()
{										 
	
	// Dow Jones industrial index (symbol, price)
	map<string, double> dow_price =
	{
		{"MMM", 81.86},
		{"AA", 34.69},
		{"MO", 54.45},
		{"BA", 332.80},
		{"INTC", 43.95},
		{"AAPL", 190.69}
	};

	// Dow (symbol, weight)
	map<string, double> dow_weight =
	{
		{"MMM", 5.8549},
		{"AA", 2.4808},
		{"MO", 3.8940},
		{"BA", 1.7182},
		{"INTC", 2.8783},
		{"AAPL", 2.8}
	};

	// Dow (symbol, name)
	map<string, string> dow_name =
	{
		{"MMM", "3M Co."},
		{"AA", "Alcoa Inc."},
		{"MO", "Altria Group Inc"},
		{"BA", "Boesing Inc."},
		{"INTC", "Intel Inc."},
		{"AAPL", "Apple Inc."}
	};


	// read values from a map

	double alcoa_price = dow_price["AA"];
	double boeing_price = dow_price["BA"];

	if (dow_price.find("INTC") != dow_price.end())		// find an entry in a map
		cout << "Intel is in the Dow\n";

	// write price for each company in the Dow index:

	for (const auto& p : dow_price)
	{
		const string& symbol = p.first;		// the "ticker" symbol
		cout << symbol << '\t'
			<< p.second << '\t'
			<< dow_name[symbol] << '\n';
	}


	double dji_index = inner_product(dow_price.begin(), dow_price.end(), // all companies
		dow_weight.begin(),						// their weights
		0.0,									// initial value
		std::plus<double>(),							// add (as usual)
		weighted_value);						// extract values and weights and multiply

	std::cout << "Dow Jones Industrial Index: " << dji_index << '\n';
	
}