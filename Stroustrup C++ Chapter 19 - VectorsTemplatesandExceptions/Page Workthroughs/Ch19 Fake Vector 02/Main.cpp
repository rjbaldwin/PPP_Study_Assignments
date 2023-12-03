//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 follow through - vector design 16/06/2023
//

#include <iostream>
#include <initializer_list>    
#include <string>
#include "RobVector.h"

using std::string;


int main()
 {
    
    vector<int>v;
    v.push_back(10);
    v.push_back(256);

    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';

    std::cout << '\n';

    vector<string>v2;
    v2.push_back("Stolec");
    v2.push_back("Odchody");
    v2.push_back("Kal");
    v2.push_back("Stanik");

    for (int i = 0; i < v2.size(); ++i)
        std::cout << v2[i] << ' ';

    std::cout << '\n';


    vector<char>v3;
    v3.push_back('%');

    for (int i = 0; i < v3.size(); ++i)
        std::cout << v3[i] << ' ';
   

}