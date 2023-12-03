#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <array>
#include <string>


template<typename ln, typename T>
ln find1(ln first, ln last, const T& val)
{
	while (first != last && *first != val) ++first;
	return first;
}


template<typename ln, typename T>
ln find2(ln first, ln last, const T& val)
{
	for (ln p = first; p != last; ++p)
		if (*p == val) return p;
	return last;
}

// works for vector
void fVect(std::vector<int>& v, int x)
{
	std::vector<int>::iterator p = find1(v.begin(), v.end(), x);
	if (p != v.end())
	{
		std::cout << "fvect result: " << x << '\n';
	}
}

// works for list
void flist(std::list<std::string>& v, std::string x)
{
	std::list<std::string>::iterator p = find1(v.begin(), v.end(), x);
	if (p != v.end())
	{
		std::cout << "flist result: " << x << '\n';
	}
}

int main()
{
	const int val{ 3 };
	const std::string val2{"piersi"};


	std::vector<int> nums = { 1, 2, 3, 4, 5 };

	auto result1 = find1(nums.begin(), nums.end(), val);
	auto result2 = find2(nums.begin(), nums.end(), val);

	std::cout << "find1 result: " << *result1 << '\n';
	std::cout << "find2 result: " << *result2 << '\n';

	fVect(nums, val);

	std::list<std::string>str = { "Odchody", "Kal", "piersi", "Stolec" };

	flist(str, val2);

}