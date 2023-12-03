//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 follow through - vector design 16/06/2023
//

#include <iostream>
#include <initializer_list>    
#include <string>
#include "RobVector.h"

using std::string;


template<typename T>

class vector {
    int sz;             // the size
    T* elem;            // a pointer to the elements
    int space;          // number of elements plus "free space for new elements

public:
     // 19.2.1 Default constructor
    vector() :sz{ 0 }, elem{ nullptr }, space{ 0 } {}


    // 17.4 Free store & pointers (needed for elem)
    explicit vector(int s)                          // constructor
        : sz{ s }, elem{ new T[s] }, space{s}
    {
        for (int i = 0; i < sz; ++i) 
            elem[i] = 0;
    }

    // 18.3.1 Copy constructors
    vector(const vector& arg)
        : sz{ arg.sz }, elem{ new T[arg.sz] }
    {
        std::copy(arg.elem, arg.elem+sz, elem);
    }

    
    // 19.2.5 Copy assignments
    vector& operator=(const vector& a)
    {
        if (this == &a) return* this;               //self-assignment, no work needed

        if (a.sz <= space)                          // enough space, no need for new allocation
        {
            for (int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];     // copy elements
            sz = a.sz;
            return *this;
        }

        T* p = new T[a.sz];                                 // allocate new space
        
        for (int i = 0; i < a.sz; ++i) p[i] = a.elem[i];    // copy elements
        delete[] elem;                                      // deallocate old space
        space = sz = a.sz;                                  // set new size
        elem = p;                                           // set new elements
        
        return *this;                                       // return self reference
    }

    
    // 18.3.4 Moving
    vector(vector&& a)                      // move constructor
        : sz{ a.sz }, elem{ a.elem }        // copy a's elem and sz
    {
        a.sz = 0;                           // make a the empty vector
        a.elem = nullptr;
    }

    vector& operator=(vector&& a)           // move assignment
    {                                       // move a to this vector
        delete[] elem;                      // deallocate old space
        elem = a.elem;                      // copy a's elem and sz
        sz = a.sz;
        a.elem = nullptr;                   // make a the empty vector
        a.sz = 0;
        return *this;                       // return a self-reference
    }

    
    // 18.2 Initializer list construction
   
    vector(std::initializer_list<T> lst)    // initializer-list constructor
        : sz{ lst.size() },
        elem{ new T[sz] }                   // uninitialized memory
    {
        // copy from i_list begin to end into elem
        std::copy(lst.begin(), lst.end(), elem);
    }

    
    // 19.2.2 Reserve and Capacity
   
    void reserve(int newalloc)
    {
        if (newalloc <= space) return;                  // never decrease allocation
        T* p = new T[newalloc];                         // allocate new space
        for (int i = 0; i < sz; ++i) p[i] = elem[i];    // copy old elements
        delete[] elem;                                  // deallocate old space
        elem = p;           
        space = newalloc;
    }

    int capacity() const { return space; }              // obtain amount of free space

    
    // 19.2.3 Resize
  
     void resize(int newsize, T def = T())
        // make the vector have newsize elements
        // initialize each new element with the default value 0.0
    {
        reserve(newsize);
        for (int i = sz; i < newsize; ++i) elem[i] = 0;     // initialise new elements
        sz = newsize;
    }

    // 19.2.4 push_back

    void push_back(const T& d)
        // increase vector size by one; initalise the new element with d
    {
        if (space == 0)
            reserve(8);                     //  start with space for 8 elements
        else if (sz == space)
            reserve(2 * space);             // get more space
        elem[sz] = d;                       // add d at end
        ++sz;                               // increase the size (sz is the number of elements)
    }


    // 17.5 Destructors
    ~vector() { delete[] elem; }            // destructor

    // 18.5 Access

    T operator[](int n) { return elem[n]; }         // return element
    const T& operator[](int n) const { return elem[n]; }

    int size() const { return sz; }                 // the current size

};



int main()
 {
    
    vector<int>v;
    v.push_back(10);
    v.push_back(256);

    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';

    std::cout << '\n';

    vector<string>v2;
    v2.push_back("Stolec");
    v2.push_back("Odchody");

    for (int i = 0; i < v2.size(); ++i)
        std::cout << v2[i] << ' ';

}