// chapter 4 task 10 rock paper scissors.cpp 
//

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int incDec(int index) {
    int r;
    if (index < 5) {
        ++index;
    }
    else if (index == 5) {
        index = 0;
    }

    r = index;
    return r;
}

int main()
{
    vector<char>nextValue(6);
    nextValue[0] = 'r';
    nextValue[1] = 'p';
    nextValue[2] = 's';
    nextValue[3] = 'r';
    nextValue[4] = 'p';
    nextValue[5] = 's';

    char humanPlayer = ' ', hal = ' ', ans = ' ', c = ' ';        
    int i = 0, playerScore = 0, halScore = 0, fromFunc = 0, z = 0;
    
    cout << "Wanna play Rock Paper Scissors - y/n?\n";
    cin >> ans;

    while (ans == 'y'|| ans=='n') {         //while loop to continue or terminate the programme

        if (ans == 'n') {
            cout << "No?  OK, goodbye then :(\n";

            break;
        }
        else

        cout << "Enter (r)ock, (p)aper, or (s)cissors\n";
        cin >> humanPlayer;
     
        //------------------------switch statement for human player choices
        switch (humanPlayer) {
        case 'r':
            

            hal = nextValue[fromFunc];
            if (hal == 'p') {
                cout << "Paper - I win\n\n";
                ++halScore;
                cout << "Hal has won " << halScore << " round \n\n";
                
                fromFunc = incDec(fromFunc);
                
            }
     
            else if (hal == 's') {
                cout << "Scissors, fuck - I lost\n\n";
                ++playerScore;
                cout << "You have won " << playerScore << " round \n\n";
                fromFunc = incDec(fromFunc);
                
                
            }

            else if (hal == 'r')
                
                cout << "Rock, a bloody tie!\n\n";
            fromFunc = incDec(fromFunc);
            
            
            
            break;

        case 'p':
            hal = nextValue[fromFunc];
            if (hal == 'r') {
                cout << "Rock, bastard - I lost\n\n";
                ++playerScore;
                cout << "You have won " << playerScore << " round \n\n";
                fromFunc = incDec(i);
                
                
            }


            else if (hal == 's') {
                cout << "Scissors - I win\n";
                ++halScore;
                cout << "Hal has won " << halScore << " round \n\n";
                fromFunc = incDec(fromFunc);
                
                
            }

            else if (hal == 'p')
                cout << "Paper, a tie!\n\n";
            fromFunc = incDec(fromFunc);
            
            
            break;

        case 's':
            hal = nextValue[fromFunc];
            if (hal == 'r') {
                cout << "Rock - I win motherfucker!\n\n";
                ++halScore;
                cout << "Hal has won " << halScore << " round \n\n";
                fromFunc = incDec(fromFunc);
                
                
            }
            else if (hal == 'p') {
                cout << "Paper, you twat - I lost that one\n\n";
                ++playerScore;
                cout << "You have won " << playerScore << " round \n\n";
                fromFunc = incDec(fromFunc);
                
                
            }


            else if (hal == 's')
                cout << "Scissors, a tie!\n\n";
            fromFunc = incDec(fromFunc);
            
            
            break;
        default:
            cout << "Illegal input\n\n";

            break;

        }

    }
       
}

