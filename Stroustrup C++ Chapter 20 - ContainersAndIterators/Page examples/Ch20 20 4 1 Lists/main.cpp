// Chapter 20.4.1 List operations

#include<iostream>


template<typename Elem>
class List
{
	// representation and implementation 
public:
	class iterator;		// member type: iterator

	iterator begin();	// iterator to first element
	iterator end();		// iterator to one beyond last element

	iterator insert(iterator p, const Elem& v);		// insert v into list after p
	iterator erase(iterator p);						// remove p from the list

	void push_back(const Elem& v);					// insert v at end
	void push_front(const Elem& v);					// insert v at front
	void pop_front();								// remove the first element 
	void pop_back();								// remove the last element

	Elem& front();									// the first element
	Elem& back();									// the last element 

	//...



private:

};


template<typename Elem>			//  requires Element<Elem>() (19.3.3)
class List<Elem>::iterator
{
	Link<Elem>* curr;			// current link
public:
	iterator(Link<Elem>* p) : curr{p} {}

	iterator& operator++() { curr = curr->succ; return *this }		// forward
	iterator& operator--() { curr = curr->prev; return *this }		// backward
	Elem& operator*() { return curr->val; }							// get value (dereference)

	bool operator==(const iterator& b) const { return curr == b.curr; }
	bool operator!=(const iterator& b) const { return curr != b.curr; }

};


int main()
{

}