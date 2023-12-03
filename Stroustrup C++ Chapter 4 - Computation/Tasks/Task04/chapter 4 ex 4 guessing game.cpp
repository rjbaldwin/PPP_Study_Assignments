//let's play a guessing game 

#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;


int main()

{
	char response = ' ';
	int guess = 50;
	int counter = 0;
	
	vector<int>guesses(6);
	guesses[0] = 25;
	guesses[1] = 13;
	guesses[2] = 6;
	guesses[3] = 3;
	guesses[4] = 2;
	guesses[5] = 1;




	cout << "Think of a number between 1 and 100 but don't tell me..\n";
	cout << "Answer the following questions with (h)igher, (l)ower, (c)orrect\n\n";
	
	

	while (response != 'c')
	{
		cout << "My guess is:"<<guess<<"?\n";

		++counter;

		cout << "Is this (c)orrect, or is your number (l)ower or (h)igher? \n";
		cin >> response;

		switch (response) {
		case 'c':
			//this will break the loop
			break;
		case 'h':
			//increase by next vector index or 1
			if (counter <= guesses.size())
				guess += guesses[counter - 1];
			else ++guess;
			break;

		case 'l':
			//decrease by next vector index or 1
			if (counter <= guesses.size())
				guess -= guesses[counter - 1];
			else --guess;
			break;

		default:
			//invalid answer.  Reduce the counter becuase the guess does not count
			cout << "This is an invalid answer.  Use 'h' 'l' or 'c' \n";
			--counter;
			break;
		}
	}




	//handles out of range numbers
	if (guess > 100 || guess < 1) {
		cout << "Your number should be between 1 and 100 motherfucker!\n ";
		return 0;
	}
	// displays the amount of attempts using counter in with attempts string (changes to plural) 
	string attempts = " ";
	if (counter == 1) //singular, attempt
		attempts = " attempt ";
	else
		attempts = " attempts "; //plural, attempts

	cout << "It took me " << counter << attempts << "to find your number, " << guess << '\n';

}





