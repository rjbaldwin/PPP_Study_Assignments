// simple calculator v2 using switch-case statements to select operand : 18 october 2022 r j baldwin v2 23 oct 2022
// this is in response to task 7 from page 129 of C++.  Changed double to int to accept only single digits

#include <iostream>
#include <vector>

using namespace std;

int main()

{
	vector<string> numberWords{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> numbers{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	int number(0), val1(0), val2(0);
	char q(' '), operation;
	string word, s_val1, s_val2;

	while (q != 'y')
	{
		cout << "Operation>> "; cin >> operation;
		cout << "Value 1>> "; cin >> s_val1;
		cout << "Value 2>> "; cin >> s_val2;

		for (int i = 0; i < numberWords.size(); ++i)
		{
			if (s_val1 == numberWords[i] || s_val1 == numbers[i])
				val1 = i;

			if (s_val2 == numberWords[i] || s_val2 == numbers[i])
				val2 = i;
		}

		switch (operation)
		{
		case '+':
			cout << val1 << " + " << val2 << " = " << val1 + val2 << endl;
			break;
		case '-':
			cout << val1 << " - " << val2 << " = " << val1 - val2 << endl;
			break;
		case '/':
			if (val1 <= 0)
				cout << "Whoopsie! Cannot divide by 0/minus." << endl;
			else
				cout << val1 << " / " << val2 << " = " << val1 / val2 << endl;
			break;
		case '*':
			cout << val1 << " * " << val2 << " = " << val1 * val2 << endl;
			break;
		default:
			cout << "Sorry, don't know that one." << endl;
			break;
		}

		cout << "Quit? (y/n) >> "; cin >> q;
		val1 = val2 = 0;
	}

	return 0;
}