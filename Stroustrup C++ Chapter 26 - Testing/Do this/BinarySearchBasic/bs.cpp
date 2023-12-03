// basic binary search method, created by r j baldwin 11/08/2023
// in response to page 990 of ppp using cpp


#include<iostream>
#include<vector>
#include<algorithm>




// binary search function

int binary_search(std::vector<int>& v, int target)
{
	
	
	// algorithm
	size_t l{ 0 };				// initial left hand index
	size_t r{ v.size() - 1 };	// initial right hand index
	int t{target};

	

	while (l <= r)
	{
		size_t m{ (l + r) / 2 };	// the middle value

		if (v[m] == t)
		{
			return m;	// return index where target is found
		}

		if (v[m] < t)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
		
	}

	return - 1; // value not found
	

}




int main()
{

	std::vector<int>v{ 1,5,6,7,9,10,11,15,27 };
	
	
	// sort the contents

	std::sort(v.begin(), v.end());

	int target{ 9 };		//target value

	int result{binary_search(v,target)};

	if (result != -1)
	{
		std::cout << "Target " << target << " found at index " << result << '\n';
	}
	else
	{
		std::cout << "Target " << target << " not found!\n";
	}
	


}