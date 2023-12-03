
#include <iostream>

#include <vector>
#include "std_lib_facilities.h"
using namespace std;

int main()
{
    string disliked1 = "bastard";
    string disliked2 = "shit";
    vector<string> words;

    cout << "Input words into vector ""\n";

    for (string input; cin >> input;)   //read words into input
        words.push_back(input);         //put into vector

    
    for (int i = 0; i < words.size(); ++i)  //increments vector index for output printing

        if (words[i] == disliked1 || words[i] == disliked2)

            cout <<" BLEEP - is not a nice word" << "\n";

        else (cout << words[i]<<"\n");                        //prints output of vector index
                                                                    

}

