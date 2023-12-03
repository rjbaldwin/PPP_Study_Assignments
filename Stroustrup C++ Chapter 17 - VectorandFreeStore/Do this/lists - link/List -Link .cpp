
#include <iostream>
#include <string>

using std::string;


struct Link
{
	string value;
	Link* prev;
	Link* succ;
	Link(const string& v, Link* p = nullptr, Link* s= nullptr)
		: value{v},prev{p},succ{s}{}
};


// insert operation

Link* insert(Link* p, Link* n) // insert n before p (incomplete)
{
	if (n == nullptr) return p;
	if (p == nullptr) return n;
	n->succ = p;	// p comes after n
	if (p->prev)p->prev->succ = n;
	n->prev = p->prev;	// p's prev becomes n's prev
	p->prev = n;		// n becomes p's prev
	return n;

}


//Link* add(Link* p, Link* n) // insert n after p; return n
//{
//	// much like insert (see exercise 11)
//} 


Link* erase(Link* p) // remove *p from list; return p’s successor
{
	if (p == nullptr) return nullptr;
	if (p -> succ) p -> succ -> prev = p -> prev;
	if (p -> prev) p -> prev -> succ = p -> succ;
	return p -> succ;
} 


Link* find(Link* p, const string& s) // find s in list;
// return nullptr for “not found”
{
	while (p) {
		if (p -> value == s) return p;
		p = p -> succ;
	}
	return nullptr;
} 


Link* advance(Link* p, int n) // move n positions in list
// return nullptr for “not found”
// positive n moves forward, negative backward
{
	if (p == nullptr) return nullptr;
	if (0 < n) {
		while (n--) {
			if (p -> succ == nullptr) return nullptr; p = p -> succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p -> prev == nullptr) return nullptr;
			p = p -> prev;
		}
	}
	return p;
}



void print_all(Link* p)
{
	std::cout << "{ ";
	while (p) {
		std::cout << p -> value;
		if (p = p -> succ) std::cout << ", ";
	}
	std::cout << " }\n";
	
}



int main()
{

	
	Link* norse_gods = new Link("Thor");
	norse_gods = insert(norse_gods, new Link{ "Odin" });
	norse_gods = insert(norse_gods, new Link{ "Zeus" });
	norse_gods = insert(norse_gods, new Link{ "Freia" });


	Link* greek_gods = new Link("Hera");
	greek_gods = insert(greek_gods, new Link{ "Athena" });
	greek_gods = insert(greek_gods, new Link{ "Mars" });
	greek_gods = insert(greek_gods, new Link{ "Poseidon" });


	Link* p = find(norse_gods, "Zeus");
	if (p) {
		if (p == norse_gods) norse_gods = p -> succ;
		erase(p);
		greek_gods = insert(greek_gods, p);
	}


	print_all(norse_gods);
	std::cout << "\n";
	print_all(greek_gods);
	std::cout << "\n";

	
}

