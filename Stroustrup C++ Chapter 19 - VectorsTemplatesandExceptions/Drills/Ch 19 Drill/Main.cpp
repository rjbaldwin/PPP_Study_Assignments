// Chapter 19 Drills
// Created by Robert J Baldwin 21/06/2023

/*
1. Define template<typename T> struct S { T val; };.
2. Add a constructor, so that you can initialize with a T.
3. Define variables of types S<int>, S<char>, S<double>, S<string>, and S<vector<int>>; initialize them with
values of your choice.
4. Read those values and print them.
5. Add a function template get() that returns a reference to val.
6. Put the definition of get() outside the class.
7. Make val private.
8. Do 4 again using get().
9. Add a set() function template so that you can change val.
10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than §19.2.5.
11. Provide const and non-const versions of get().
12. Define a function template<typename T> read_val(T& v) that reads from cin into v.
13. Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.
14. Bonus: Define input and output operators (>> and <<) for vector<T>s. For both input and output use a { val, val, val }
format. That will allow read_val() to also handle the S<vector<int>> variable.
Remember to test after each step.
*/

#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct RobStruct
{
private:
	T val;
public:
	RobStruct(T value) :val{ value } {};

	T& get();

	const T& get() const;

	//void set(T value);
	RobStruct<T>& operator=(const T& other);              // copy assignment



};



// get
template<typename T>
T& RobStruct<T>::get()
{
	return val;
}

template<typename T>
const T& RobStruct<T>::get() const
{
	return val;
}



template<typename T>
RobStruct<T>& RobStruct<T>::operator=(const T& other)
{
	val = other;
	return* this;
}


template<typename T> 
void read_val(T& v)
{
	std::cin >> v;
	
}


int main()
{

	RobStruct<int> obj1(123);
	RobStruct<char> obj2('x');
	RobStruct<double> obj3(456.571);
	RobStruct<std::string> obj4("Stolec");
	RobStruct<std::vector<int>> obj5({ 10,23,33,14,75,106,27 });

	

	// getter 
	std::cout << '\n';
	std::cout << obj1.get() << '\n';
	std::cout << obj2.get() << '\n';
	std::cout << obj3.get() << '\n';
	std::cout << obj4.get() << '\n';
	std::vector<int>& vecRef = obj5.get();
	std::cout << "Object 5: ";
	for (const auto& element : vecRef)
	{
		std::cout << element << ' ';

	};
	std::cout << '\n';

	std::cout << obj4.get() << '\n';

	RobStruct<int> obj6(12);
	RobStruct<int> obj7(134);

	obj6 = obj7 ;
	std::cout << obj6.get() << '\n';
	
	int val{ 0 };
	read_val(val);
	RobStruct<int>read(val);
	std::cout << read.get();

}