
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

struct RobClass
{
	int val{};

	void out(const string& s, int nv)
	{
		std::cout <<"Memory address: " << this << " -> " << s << ": val= " << val << " nv = (" << nv << ")\n";
	}

	// default constructor
	RobClass() { 
		out("**RobClass() - default constructor called** ", 0); 
		val = 0; 
	}

	RobClass(int v) { 
		val = v; 
		out("**RobClass(int) - constructor called** ", v); 
	}

	// copy constructor
	RobClass(const RobClass& x) { 
		val = x.val; 
		out("**RobClass(RobClass&) - copy constructor called** ", x.val); 
	}

	RobClass& operator=(const RobClass& a)	// copy assignment
	{
		out("**RobClass::operator=() - copy assignment called** ", a.val);
		val = a.val;
		return *this;
	}

	~RobClass() {							// destructor
		out("**~RobClass() - destructor called** ", 0); 
	} 
};



//RobClass global{156};		// global variable

RobClass copy(RobClass a) { return a; }

RobClass copy2(RobClass a) { RobClass aa = a; return aa; }

RobClass& ref_to(RobClass& a) { return a; }

RobClass* make(int i) { RobClass a(i); return new RobClass(a); }



struct XX
{
	RobClass a; RobClass b;
};


int main()
{
	RobClass loc{ 4 };				// local variable
	RobClass loc2{ loc };			// copy construction
	loc = RobClass{ 5 };			// copy assignment
	loc2 = copy(loc);		// call by value and return
	loc2 = copy2(loc);	
	RobClass loc3{ 6 };
	RobClass& r = ref_to(loc);		// call by reference and return
	delete make(7);
	delete make(8);
	vector<RobClass> v(4);			// default values
	XX loc4;
	RobClass* p = new RobClass{ 9 };		// an X on the free store
	delete p;
	RobClass* pp = new RobClass[5];		// an array of Xs on the free store
	delete[] pp;

}


