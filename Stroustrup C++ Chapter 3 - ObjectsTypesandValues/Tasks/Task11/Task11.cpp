/*

11 Write a program that prompts the user to enter some number of pennies (1-cent coins), nickels (5-cent coins), dimes (10-
cent coins), quarters (25-cent coins), half dollars (50-cent coins), and one-dollar coins (100-cent coins). 
Query the user separately for the number of each size coin, e.g., “How many pennies do you have?” 
Then your program should print out something like this:

You have 23 pennies.
You have 17 nickels.
You have 14 dimes.
You have 7 quarters.
You have 3 half dollars.
The value of all of your coins is 573 cents.

Make some improvements: if only one of a coin is reported, make the output grammatically correct, e.g., 14 dimes and 1
dime (not 1 dimes). Also, report the sum in dollars and cents, i.e., $5.73 instead of 573 cents.

*/

#include<iostream>
#include<string>


int main()
{
	int pennies{};
	int nickels{};
	int dimes{};
	int quarters{};
	int half{};
	int dollar{};

	double total{};

	std::cout << "How many pennies do you have? \n";
	std::cin >> pennies;
	total += pennies * 0.01;

	std::cout << "How many nickels do you have? \n";
	std::cin >> nickels;
	total += nickels * 0.05;

	std::cout << "How many dimes do you have? \n";
	std::cin >> dimes;
	total += dimes * 0.1;

	std::cout << "How many quarters do you have? \n";
	std::cin >> quarters;
	total += quarters * 0.25;

	std::cout << "How many half-dollars do you have? \n";
	std::cin >> half;
	total += half * 0.5;

	std::cout << "How many dollars do you have? \n";
	std::cin >> dollar;
	total += dollar * 1.0;

	if (pennies == 1)
	{
		std::cout << "You have " << pennies << " penny\n";
	}
	else if (pennies < 1 || pennies > 1)
	{
		std::cout << "You have " << pennies << " pennies\n";
	}


	if (nickels == 1)
	{
		std::cout << "You have " << nickels << " nickel\n";
	}
	else if (nickels < 1 || nickels > 1)
	{
		std::cout << "You have " << nickels << " nickels\n";
	}
	

	if (dimes == 1)
	{
		std::cout << "You have " << dimes << " dime\n";
	}
	else if (dimes < 1 || dimes > 1)
	{
		std::cout << "You have " << dimes << " dimes\n";
	}

	
	if (quarters == 1)
	{
		std::cout << "You have " << quarters << " quarter\n";
	}
	else if (quarters < 1 || quarters > 1)
	{
		std::cout << "You have " << quarters << " quarters\n";
	}

	
	if (half == 1)
	{
		std::cout << "You have " << half << " half-dollar\n";
	}
	else if (half < 1 || half > 1)
	{
		std::cout << "You have " << half << " half-dollars\n";
	}

	
	if (dollar == 1)
	{
		std::cout << "You have " << dollar << " dollar\n";
	}
	else if (dollar < 1 || dollar > 1)
	{
		std::cout << "You have " << dollar << " dollars\n";
	}
	

	std::cout << "The value of all of your coins is $" << total <<  '\n';


}