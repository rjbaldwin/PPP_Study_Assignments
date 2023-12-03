/*2. Write a program that given a file name and a word outputs each line that contains that word together with the line
number. Hint: getline().*/


/* NOTES

open and read a file (into a stringstream?) getline() will read the entire line, then search for a word in the line.   

*/


#include "std_lib_facilities.h"


int main()
{

	// open the input file
    std::string filename{ "data.txt" };
    std::ifstream in{ filename };
    if (!in) std::cerr << "Can't open file";

    // create the output file
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file!" << std::endl;
        return 1;
    }

    string search{};
    cout << "What word would you like to srearch for? \n";
    cin >> search;

    //===========================================


	string line{};
	getline(cin, line);  // get the entire line 
	cout << line << '\n';








	istringstream ss(line);  // read entire line into a stringstream ss

	vector<string>vs;

	for (string word; ss >> word;)		// push the ntire line into a vector of strings
		vs.push_back(word);

	cout << "Altered stringstream output: \n";

	for (string word : vs)
		cout << word << '\n';

}