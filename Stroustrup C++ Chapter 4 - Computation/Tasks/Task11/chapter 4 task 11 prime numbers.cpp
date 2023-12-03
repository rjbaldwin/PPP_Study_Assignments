// chapter 4 task 11 prime numbers.cpp : Sunday 30th Oct 2022
//

#include <iostream>
#include <vector>
using namespace std;


int primes(int userInput) {
    
    int r = 0;
    int yesPrime = 0;
    int notPrime = 0;

    vector<int>primes(25);
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;
    primes[3] = 7;
    primes[4] = 11;
    primes[5] = 13;
    primes[6] = 17;
    primes[7] = 19;
    primes[8] = 23;
    primes[9] = 29;
    primes[10] = 31;
    primes[11] = 37;
    primes[12] = 41;
    primes[13] = 43;
    primes[14] = 47;
    primes[15] = 53;
    primes[16] = 59;
    primes[17] = 61;
    primes[18] = 67;
    primes[19] = 71;
    primes[20] = 73;
    primes[21] = 79;
    primes[22] = 83;
    primes[23] = 89;
    primes[24] = 97;

    

    for (int i = 0; i < primes.size(); ++i)

        if (userInput == primes[i]) {

            yesPrime = userInput;
            cout << yesPrime << " is a prime number\n";
            
        }
        else if (userInput != 2 && userInput % 2 == 0) {
            notPrime = userInput;
            cout << notPrime << " is not a prime number\n";
        }

    return r;
}

int main()

{
    
    int input = 0;

    cout << "Enter a number\n";
    cin >> input;
        
    primes(input);


}

