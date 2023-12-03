/*

10 Write a program that takes an operation followed by two operands and outputs the result. For example:
+ 100 3.14
* 4 5
Read the operation into a string called operation and use an if-statement to figure out which operation the user wants,
for example, if (operation=="+"). Read the operands into variables of type double. Implement this for operations
called +, –, *, /, plus, minus, mul, and div with their obvious meanings.

*/

#include<iostream>
#include<string>

using std::string;




void calc(string& operation, double& x, double& y)
{
	if (operation == "+")
	{
		double result = x + y;
		std::cout << result << '\n';
	}
	else if (operation == "-")
	{
		double result = x - y;
		std::cout << result << '\n';
	}
	else if (operation == "*")
	{
		double result = x * y;
		std::cout << result << '\n';
	}
	else if (operation == "/")
	{
		double result = x / y;
		std::cout << result << '\n';
	}


}


int main()
{

	std::cout << "Enter an operand, followed by 2 numbers:\n";
	string operation{};
	double x{};
	double y{};
	std::cin >> operation >> x >> y;

	calc(operation, x, y);

}