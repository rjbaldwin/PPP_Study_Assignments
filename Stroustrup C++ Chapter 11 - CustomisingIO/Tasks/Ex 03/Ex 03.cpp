/*3. Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc
pn tm!. Surprisingly often, the result is still readable; try it on your friends.*/

#include <iostream>
#include "std_lib_facilities.h"


int main()
{
   



    // open the input file
    string filename{ "data.txt" };
    ifstream in{ filename };
    if (!in) std::cerr << "Can't open file";


    
    getline(in, filename); // read into line
    for (char& ch : filename) // replace each vowell  by a space
        switch (ch) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            ch = ' ';
        }
    stringstream ss(filename); // make an istream ss reading from line
    vector<string> vs;
    for (string word; ss >> word; ) // read words without vowells
        vs.push_back(word);

    for (string s : vs)
        cout << s << ' ';
    


}


