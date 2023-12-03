#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>



struct Test
{
	std::string label{};
	int val{};
	std::vector<int> seq;
	bool res{};
};



std::istream& operator>>(std::istream& is, Test& t)	// use the described format
{

}



int test_all(std::istream& is)
{
	int error_count{ 0 };
	for (Test t; is >> t;)
	{
		bool r = std::binary_search(t.seq.begin(), t.seq.end(), t.val);

		if (r != t.res)
		{
			std::cout << "Failure: test " << t.label << " binary_search: " << t.seq.size() << " elements, val == " << t.val << " -> " << t.res << '\n';
			++error_count;
		}
	}
	return error_count;
}


int main()
{
	std::ifstream file{ "tests.txt" };
	int errors = test_all(file);
	std::cout << "number of errors: " << errors << '\n';

}