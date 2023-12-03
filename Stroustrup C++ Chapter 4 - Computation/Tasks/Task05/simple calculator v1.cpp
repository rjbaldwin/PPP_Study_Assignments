// simple calculator v1 using switch-case statements to select operand : 18 october 2022 r j baldwin

#include <iostream>

using namespace std;

int main()

{
	//initialised variables
	double num1 = 0, num2 = 0;
	double sum = 0;
	char operand = ' ';
	
	cout << "**Simple Calculator v1**\n\n";
	cout << "Enter first value, followed by operand '+', '-', '*', or '/', followed by second value...\n";

	
	cin >> num1 >> operand >> num2; cout << "=\n";

	switch (operand) {
	case '+':
		 sum = (num1 + num2);
		 cout << sum << '\n';
			break;
	case '-':
		sum = (num1 - num2);
		cout << sum << '\n';
		break;
	case '*':
		sum = (num1 * num2);
		cout << sum << '\n';
		break;
	case '/':
		sum = (num1 / num2);
		cout << sum << '\n';
		break;

	default:
		cout << "Incorrect operand \n";

	}







}