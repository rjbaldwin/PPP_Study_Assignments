// Try This from page 879-880 of PPP using cpp
// RJ Baldwin 26/07/2023


#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>


using std::string;
using std::cout;
using std::cin;
using std::regex;
using std::fstream;

// accept a pattern and a set of lines from input
// check the pattern snd search for lines with that pattern


int main()
{
	regex pattern;

	string pat;
	cout << "Enter pattern: ";
	getline(cin, pat);			// read pattern

	try
	{
		pattern = pat;		// this checks pat
		cout << "pattern: " << pat << '\n';
	}

	catch (std::regex_error)
	{
		cout << pat << " is not a valid regular expression\n";
		exit(1);
	}

	cout << "now enter lines:\n";
	int lineno{ 0 };

	for (string line; getline(cin, line);)
	{
		++lineno;
		std::smatch matches;

		if (regex_search(line, matches, pattern))
		{
			cout << "line" << lineno << ": " << line << '\n';
			for (int i = 0; i < matches.size(); ++i)
				cout << "\tmatches[" << i << "]: "
				<< matches[i] << '\n';
		}
		else
			cout << "didn't match\n";
	}

}

