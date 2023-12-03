// 1. Write a program that reads a text file and converts its input to all lower case, producing a new file.
// tolower(c)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


void tolower(std::string& s)
{
    for (char& x : s) x = tolower(x);

};


                                                                                                                                                                                                 

int main()
{
    std::vector<std::string>words;

    // open the input file
    std::string filename{ "words.txt" };
    std::ifstream in{ filename };
    if (!in) std::cerr << "Can't open file";

    // create the output file
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file!" << std::endl;
        return 1;
    }

    // Read each line from the input file and write to the output file

    std::string line;

    while (getline(in, line)) {
        // Convert the line to lower case
        for (auto& c : line) {
            c = std::tolower(c);
        }
        // Write the line to the output file
        outputFile << line << std::endl;
    }
}

