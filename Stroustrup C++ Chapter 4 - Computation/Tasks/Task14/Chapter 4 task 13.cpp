// tast 14 is a modified version of task 13.  this allows user to input a maximum search value 
//

#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int>notPrimes;
	vector<int>primes;

	int maxVal = 0;

	cout << "Input a maxumum value an I will display all the prime numbers below that value \n";
	cin >> maxVal; 
	cout <<"/***PRIMES***/" << '\n';
	

	for (int i = 0; i <= maxVal; ++i)
											//fills notPrimes with values that correspond to index numbers
		if (i < 2)
			notPrimes.push_back(0);			//this line 'zeros' 0 and 1 so they dont get carried over to the 'primes' vector later on
		else
			notPrimes.push_back(i);


	for (int i = 2; i < maxVal; ++i)

		if (notPrimes[i] != 0) {
			primes.push_back(i);


			if (i * i < maxVal)
				for (int j = i; j < maxVal; j += i)
					notPrimes[j] = 0;
		}

	for (int i : primes)
		cout << i << endl;

}


