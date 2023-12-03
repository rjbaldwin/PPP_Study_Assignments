// Chapter 21 Drills - r j baldwin 18/07/2023

// After each operation (as defined by a line of this drill) print the vector.
// 1. Define a struct Item { string name; int iid; double value; /* . . . */ }; , 
// make a vector<Item>, vi, and fill it with ten items from a file.
// 2. Sort vi by name.
// 3. Sort vi by iid.
// 4. Sort vi by value; print it in order of decreasing value(i.e., largest value first).
// 5. Insert Item("horse shoe", 99, 12.34) and Item("Canon S400", 9988, 499.95).
// 6. Remove(erase) two Items identified by name from vi.
// 7. Remove(erase) two Items identified by iid from vi.
// 8. Repeat the exercise with a list<Item> rather than a vector<Item>.

// Now try a map :
// 1. Define a map<string, int> called msi.
// 2. Insert ten(name, value) pairs into it, e.g., msi["lecture"] = 21.
// 3. Output the(name, value) pairs to cout in some format of your choice.
// 4. Erase the(name, value) pairs from msi.
// 5. Write a function that reads value pairs from cin and places them in msi.
// 6. Read ten pairs from input and enter them into msi.
// 7. Write the elements of msi to cout.
// 8. Output the sum of the(integer) values in msi.
// 9. Define a map<int, string> called mis.
// 10. Enter the values from msi into mis; that is, if msi has an element("lecture", 21), mis should have an element
// (21, "lecture").
// 11. Output the elements of mis to cout.
// More vector use :
// 1. Read some floating - point values(at least 16 values) from a file into a vector<double> called vd.
// 2. Output vd to cout.
// 3. Make a vector vi of type vector<int> with the same number of elements as vd; copy the elements from vd into vi.
// 4. Output the pairs of(vd[i], vi[i]) to cout, one pair per line.
// 5. Output the sum of the elements of vd.
// 6. Output the difference between the sum of the elements of vd and the sum of the elements of vi.
// 7. There is a standard library algorithm called reverse that takes a sequence(pair of iterators) as arguments; reverse vd, and output vd to cout.
// 8. Compute the mean value of the elements in vd; output it.
// 9. Make a new vector<double> called vd2 and copy all elements of vd with values lower than(less than) the mean into
// vd2.
// 10. Sort vd; output it again.






#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>


using std::vector;
using std::cout;
using std::string;
using std::ostream;
using std::istream;
using std::ifstream;



// 1. Define a struct Item { string name; int iid; double value; /* . . . */ }; , 
// make a vector<Item>, vi, and fill it with ten items from a file.

struct Item
{
	Item() = default;
	Item(string n, int i, double v) :name{ n }, iid{ i }, value{ v } {};

	string name{};
	int iid{};
	double value{};


	Item& operator=( const Item& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		name = rhs.name;
		iid = rhs.iid;
		value = rhs.value;
		return *this;
	}
	
};


ostream& operator<<(ostream& os, const Item& it)
{
	os	<< std::setw(20)<< it.name << '\t'		// set column width 
		<< it.iid << '\t'
		<< it.value << '\t';

	return os;
}

istream& operator>>(istream& is, Item& item)
{
	is >> item.name >> item.iid >> item.value;
	return is;
}

// sort by name ascending
bool sortByName(const Item& item1, const Item& item2)
{
	return item1.name < item2.name;
}

// sort by ID ascending
bool sortByID(const Item& item1, const Item& item2)
{
	return item1.iid < item2.iid;
}

// sort by value descending 
bool sortByValue(const Item& item1, const Item& item2)
{
	return item1.value > item2.value;
}


// print helper

void printInfo(const vector<Item>& v)
{
	for (const auto& item : v)
	{
		cout << item << '\n';
	}
}



int main()
{
	

	ifstream inputFile("text.txt");		// open the input file called text.txt

	if (!inputFile)
	{
		std::cerr << "Failed to open the file. \n";
		return 1;
	}

	vector<Item> vi;	// Create a vector to store the items

	// read values from the file into the vector

	Item item1;
	while (inputFile >> item1)
	{
		vi.push_back(item1);
	}

	// close the file

	inputFile.close();

	// print default info
	printInfo(vi);
	cout << '\n';

	// sort by name
	cout << "Sort by name: \n";
	std::sort(vi.begin(), vi.end(), sortByName);
	printInfo(vi);
	cout << '\n';

	// sort by id
	cout << "Sort by ID: \n";
	std::sort(vi.begin(), vi.end(), sortByID);
	printInfo(vi);
	cout << '\n';

	// sort by value
	cout << "Sort by value - descending: \n";
	std::sort(vi.begin(), vi.end(), sortByValue);
	printInfo(vi);

	// insert
	cout << "Inserting \n";
	item1 = { "horse shoe", 99,12.34 };
	vi.push_back(item1);
	item1 = { "Canon S400", 9988,499.95 };
	vi.push_back(item1);
	printInfo(vi);
	cout << '\n';

	// 6. Remove(erase) two Items identified by name from vi.


	/*
	
	 std::remove_if is an algorithm from the <algorithm> library. 
	 It takes a range defined by two iterators (vi.begin() and vi.end()) 
	 and a predicate (a lambda function or a function object) to specify the condition for removal.

    The lambda function [&](const Item& item) { return item.name == delVal; } is used as the predicate. 
	It takes an Item object as input (captured by reference with [&]) and compares its name member with the delVal string.

    The std::remove_if algorithm moves the elements in the vector that satisfy 
	the predicate (i.e., those with a matching name) to the end of the vector, while 
	preserving the relative order of the remaining elements. This effectively partitions the vector 
	into two parts: the elements to be removed at the end and the elements to keep at the beginning.

    The std::remove_if algorithm returns an iterator pointing to the start of the removed elements, which 
	are now at the end of the vector. This iterator represents the new logical end of the vector after removal.

    The vi.erase() function is called, providing the returned iterator from 
	std::remove_if as the first argument and vi.end() as the second argument. 
	This erases the elements from the vector starting from the iterator position up to the end. 
	In other words, it removes the elements that were moved to the end by std::remove_if.
	
	*/
	cout << "Remove name items from list. \n";

	string delName1{ "Odchody" }, delName2{ "Kal" };
	vi.erase(std::remove_if(vi.begin(), vi.end(), [&](const Item& item) {return item.name == delName1;}), vi.end());
	vi.erase(std::remove_if(vi.begin(), vi.end(), [&](const Item& item) {return item.name == delName2; }), vi.end());
	
	printInfo(vi);
	cout << '\n';

	// 7. Remove(erase) two Items identified by iid from vi.

	cout << "Remove iid items from list. \n";
	
	int delIID{ 99 };
	vi.erase(std::remove_if(vi.begin(), vi.end(), [&](const Item& item) {return item.iid == delIID; }), vi.end());
	delIID = 9988;
	vi.erase(std::remove_if(vi.begin(), vi.end(), [&](const Item& item) {return item.iid == delIID; }), vi.end());

	printInfo(vi);
	cout << '\n';
}
