// From page 883 of PPP using cpp
// RJ Baldwin 26/07/2023


#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>


using std::string;
using std::cout;
using std::cin;
using std::regex;
using std::fstream;
using std::ifstream;
using std::smatch;
using std::cerr;


inline void error(const string& s)
{
	throw std::runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s + s2);
}

inline void error(const string& s, int i)
{
	std::ostringstream os;
	os << s << ": " << i;
	error(os.str());
}

// from 23.2 page 853 

struct bad_from_string : std::bad_cast {
	const char* what() const override
	{
		return "bad cast from string";
	}
};


template<typename T> 
T from_string(const string& s)
{
	std::istringstream is {s};
	T t;
	if (!(is >> t)) throw bad_from_string{};
	return t;
}



int main()
{
	ifstream in{ "table.txt" };						// input file
	if (!in) error("no input file");

	string line;									// input buffer
	int lineno = 0;

	regex header{ R"(^[\w ]+( [\w ]+)*$)" };		// header line
	regex row{ R"(^[\w ]+( \d+)( \d+)( \d+)$)" };	// data line

	if (getline(in, line))							// check header line
	{							
		smatch matches;
		if (regex_match(line, matches, header)) {
			error("no header");
		}
	} 
	
	//column totals :
	int boys = 0;
	int girls = 0;

	while (getline(in, line)) 
	{
		++lineno;
		smatch matches;

		if (!regex_match(line, matches, row))
			cerr << "bad line: " << lineno << '\n';

		if (in.eof()) cout << "at eof\n";


		// check row:
		int curr_boy = from_string<int>(matches[2]);  //(implement this from 23.2
		int curr_girl = from_string<int>(matches[3]);
		int curr_total = from_string<int>(matches[4]);
		if (curr_boy + curr_girl != curr_total) error("bad row sum \n");

		if (matches[1] == "Alle klasser") { // last line
			if (curr_boy != boys) error("boys don't add up\n");
			if (curr_girl != girls) error("girls don't add up\n");
			if (!(in >> std::ws).eof()) error("characters after total line");
			return 0;
		} 
		
		//update totals: 
		boys += curr_boy;
		girls += curr_girl;
	} 
	error("didn't find total line");


}