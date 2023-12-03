#include<iostream>
#include<chrono>

using namespace std;


void do_something()
{
	
}

int main()
{
	int n{ 1000000000 };	// repeat do_something() n times

	auto t1 = chrono::system_clock::now();		// begin time

	for (int i = 0; i < n; ++i)
	{
		do_something();		// timing loop
	}

	auto t2 = chrono::system_clock::now();		// end time

	cout << "do_something() " << n << " times took " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << " milliseconds\n";


}