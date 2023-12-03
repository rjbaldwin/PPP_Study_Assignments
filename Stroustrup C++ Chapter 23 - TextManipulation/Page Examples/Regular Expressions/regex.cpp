#include<regex>
#include<iostream>
#include<string>
#include<fstream>

using std::string;
using std::regex;
using std::fstream;
using std::ifstream;


int main()
{
	ifstream in{ "file.txt" };		//input file
	if (!in) std::cerr << "no file\n";

	regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"};		// postal code pattern

	int lineno{ 0 };
	for (string line; getline(in, line); )	// read input line into input buffer
	{
		++lineno;
		std::smatch matches;		// matched string go here
		if (regex_search(line, matches, pat))
			std::cout << lineno << ": " << matches[0] << '\n'; // whole match
		if (1 < matches.size() && matches[1].matched)
			std::cout << "\t: " << matches[1] << '\n';	// sub-match
	}
}