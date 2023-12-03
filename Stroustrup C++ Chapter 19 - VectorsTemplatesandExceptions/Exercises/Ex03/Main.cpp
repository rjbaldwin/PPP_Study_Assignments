// Chapter 19 task 3 - Created by Robert J Baldwin 23/06/2023
/*
3. Write a template class Pair that can hold a pair of values of any type. Use this to implement a simple symbol table like
the one we used in the calculator (§7.8).
*/

#include <iostream>
#include<vector>
using std::vector;


template <typename T>
class Pair
{
public:
	Pair(T X, T Y) :x{ X }, y{ Y } {};
	T getX() const { return x; };
	T getY() const { return y; };

private:
	T x{};
	T y{};
};

template<typename T>
void pushBack(const Pair<T>& pair, vector<Pair<T>>& table)
{
	
	table.push_back(pair);
}

template <typename T>
void getSymbolTableInfo(const vector<Pair<T>>& table)
{
	for (const auto& pair : table)
	{
		std::cout << "x: " << pair.getX() << ", y: " << pair.getY() << '\n';
	}
}

int main()
{
	vector <Pair<int>> symbolTable;
	Pair<int> p1{ 10,20 };
	Pair<int> p2{ 123,54 };
	Pair<int> p3{ 13, 567 };

	pushBack(p1,symbolTable);
	pushBack(p2,symbolTable);
	pushBack(p3, symbolTable);
	
	getSymbolTableInfo(symbolTable);

	vector<Pair<char>> v2;
	Pair<char>cp1{'C', 'U'};
	Pair<char>cp2{'N', 'T'};
	Pair<char>cp3{'!', '#'};
	pushBack(cp1, v2);
	pushBack(cp2, v2);
	pushBack(cp3, v2);

	getSymbolTableInfo(v2);

}