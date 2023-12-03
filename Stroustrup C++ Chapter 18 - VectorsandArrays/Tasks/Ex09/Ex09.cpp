/*
9. Consider the memory layout in §17.4. Write a program that tells the order in which static storage, the stack, and the free
store are laid out in memory. In which direction does the stack grow: upward toward higher addresses or downward
toward lower addresses? In an array on the free store, are elements with higher indices allocated at higher or lower
addresses?

Code
Static Data
Free store
Stack


Created by Robert J Baldwin 06/06/2023

*/

#include<iostream>
using std::cout;


// Data storage
int data[5] = { 1, 2, 3, 4, 5 };


// static storage
static int a{ 0 };
static int b{ 0 };
static int c{ 0 };
static int d{ 0 };
static int e{ 0 };



int main()
{
	// data storage

	cout << "Data storage addresses and values:\n";

	for (int i = 0; i < 5; ++i) {
		cout << "&data[" << i << "]: " << (int)&data[i] << ", data[" << i << "]: " << data[i] << "\n";
	}


	// static storage

	int* ap = &a;
	int* bp = &b;
	int* cp = &c;
	int* dp = &d;
	int* ep = &e;

	cout << "Static storage addresses: \n";
	cout <<"a " << (int)ap << '\n' <<"b " << (int)bp << '\n' <<"c " << (int)cp << '\n' <<"d "<< (int)dp << '\n' <<"e " << (int)ep << '\n';


	// free-store

	int* ha = new int[5];


	cout << "Heap storage addresses: \n";
	cout <<"[0] " << (int)&ha[0] << '\n' <<"[1] " << (int)&ha[1] << '\n' <<"[2] " << (int)&ha[2] << '\n' <<"[3] " << (int)&ha[3] << '\n' <<"[4] " << (int)&ha[4] << '\n';


	// stack storage

	char chara{ 'a' };
	char charb{ 'a' };
	char charc{ 'a' };
	char chard{ 'a' };
	char chare{ 'a' };


	cout << "Stack storage addresses: \n";
	cout << "a " << (int)&chara << '\n' << "b " << (int)&charb << '\n' << "c " << (int)&charc << '\n' << "d " << (int)&chard << '\n' <<"e "<< (int)&chare << '\n';

	return 0;
	
}