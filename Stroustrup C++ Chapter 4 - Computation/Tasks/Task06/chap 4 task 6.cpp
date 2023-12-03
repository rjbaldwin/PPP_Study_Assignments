// chap 4 task 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string>v(10);
    v[0] = "zero";
    v[1] = "one";
    v[2] = "two";
    v[3] = "three";
    v[4] = "four";
    v[5] = "five";
    v[6] = "six";
    v[7] = "seven";
    v[8] = "eight";
    v[9] = "nine";

    vector<int>number(10);
    number[0] = 0;
    number[1] = 1;
    number[2] = 2;
    number[3] = 3;
    number[4] = 4;
    number[5] = 5;
    number[6] = 6;
    number[7] = 7;
    number[8] = 8;
    number[9] = 9;


 
    
    int num = 0;
    string spelling = " ";
    

    cout << "Enter number followed by enter\n";
    cin >> num;
    
    cout << v[num]<<'\n';
    cout << "enter spelling of number \n";

    cin >> spelling;

    if(spelling == "zero")

    cout << number[v.size()-10];

    else if (spelling == "one")
        cout << number[v.size() - 9];

    else if (spelling == "two")
        cout << number[v.size() - 8];

    else if (spelling == "three")
        cout << number[v.size() - 7];

    else if (spelling == "four")
        cout << number[v.size() - 6];

    else if (spelling == "five")
        cout << number[v.size() - 5];

    else if (spelling == "six")
        cout << number[v.size() - 4];

    else if (spelling == "seven")
        cout << number[v.size() - 3];

    else if (spelling == "eight")
        cout << number[v.size() - 2];

    else if (spelling == "nine")
        cout << number[v.size() - 1];




  

   
    return(0);


}

