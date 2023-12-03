// 
//

#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int>notPrimes;
	vector<int>primes;
	



	for (int i = 0; i <= 100; ++i)
		//fills notPrimes with values that correspond to index numbers
		if (i < 2)
			notPrimes.push_back(0);			//this line 'zeros' 0 and 1 so they dont get carried over to the 'primes' vector later on
		else
			notPrimes.push_back(i);




	for (int i = 2; i < 100; ++i)

		if (notPrimes[i] != 0) {
			primes.push_back(i);


			if (i * i < 100)
				for (int j = i; j < 100; j += i)
					notPrimes[j] = 0;
		}



	for (int i : primes)
		cout << i << endl;

}


