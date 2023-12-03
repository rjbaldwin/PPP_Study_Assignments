// displays how many squares i'll need on a chessboard for a given amount of rice grains 
//R J Baldwin 24th october 2022

#include <iostream>

using namespace std;

int main()
{
    int multiplier = 2, targetGrains = 0, start = 1, sum = 0, counter = 1, squareInput = 0, temp = 2;
    double x = 2, y = 2, input = 0, i = 1;

    cout << "Enter number of grains of rice: \n";
    cin >> targetGrains;

    while (targetGrains > sum) {
        sum = (start = (start * multiplier));
        
        ++counter;
      
    }
    cout << "Number of squares required for " << targetGrains << " grains of rice = " << counter << " squares\n\n";

    // provides squares for grains
    cout << "Enter number of squares and I'll tell you how many grains of rice are needed \n \n";
    
    cin >> input;
    cout << '\n';

    while (i < input - 1) {

        x = x * y;
        ++i;
        //cout << x <<  "\n";
    }
        cout << x <<" grains  \n";
  
    return(0);
    }