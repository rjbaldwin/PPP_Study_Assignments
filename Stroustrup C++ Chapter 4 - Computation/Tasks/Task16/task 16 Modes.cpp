// 08 November - find the mode of values in a vector
//

#include <iostream>
#include<vector>
#include "std_lib_facilities.h"

using namespace std;

vector<int>input;
vector<int>modes;
int counter = 0;
int mode = 0;

int main()
{
    cout << "enter positive integer values into the vector and i'll display the mode(if any) \n";

    for (int userInput; cin >> userInput;)
        input.push_back(userInput);

    sort(input);

    for (int i = 0; i < input.size()-1; ++i)
    

        if (input[i] == input[i + 1])
        {
            ++counter;
    
            mode = input[i];
            
            
            
        }


    cout << "Lowest value = " << input[0] << '\n';
    cout << "Highest value = " << input[input.size() - 1] << '\n';
    if (counter == 0 || counter > 1)
    cout << "There are " << counter << " repeated integers \n";
    else
        cout << "There is " << counter << " repeated integer \n";



    cout << "Mode: " << mode << endl;
    
        
    
}