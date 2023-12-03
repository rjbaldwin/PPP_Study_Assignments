#pragma once 
#include <memory>
using std::allocator;



template<typename T, typename A = allocator<T>>
class vector {
private:
    A alloc;
    int sz;
    T* elem;
    int space;
public:
    vector();                                        // default constructor
    explicit vector(int s);                          // constructor
    vector(const vector& arg);                       // copy constructor
    vector& operator=(const vector& a);              // copy assignment
    vector(vector&& a);                              // move constructor
    vector& operator=(vector&& a);                   // move assignment
    vector(std::initializer_list<T> lst);            // initializer-list constructor
    ~vector();                                       // destructor
    void reserve(int newalloc);                      // reserve memory
    int capacity() const;                            // obtain capacity
    void resize(int newsize, T def = T());           // resize vector
    void push_back(const T& d);                      // push element to back
    T& at(int n);                                   // checked access
    const T& at(int n) const;                       // checked access
    T& operator[](int n);                             // access element
    const T& operator[](int n) const;                // access element (const)
    int size() const;                                // obtain size
};










//**************************************************************
// template definitions - unless i put these in a .tpp file, 
// these must be included in the header file. 

// 19.2.1 Default constructor
template<typename T, typename A>
vector<T,A>::vector() :sz{ 0 }, elem{ nullptr }, space{ 0 } {};


// 17.4 Free store & pointers (needed for elem)
template<typename T, typename A>
vector<T,A>::vector(int s)                          // constructor
    : sz{ s }, elem{ new T[s] }, space{ s }
{
    for (int i = 0; i < sz; ++i)
        elem[i] = 0;
}

// 18.3.1 Copy constructors
template<typename T,typename A>
vector<T,A>::vector(const vector& arg)
    : sz{ arg.sz }, elem{ new T[arg.sz] }
{
    std::copy(arg.elem, arg.elem + sz, elem);
}


// 19.2.5 Copy assignments
template<typename T, typename A>
vector<T, A>& vector<T,A>::operator=(const vector& a)
{
    if (this == &a) return*this;               //self-assignment, no work needed

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
template<typename T, typename A>
vector<T,A>::vector(vector&& a)                      // move constructor
    : sz{ a.sz }, elem{ a.elem }        // copy a's elem and sz
{
    a.sz = 0;                           // make a the empty vector
    a.elem = nullptr;
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector&& a)           // move assignment
{                                       // move a to this vector
    delete[] elem;                      // deallocate old space
    elem = a.elem;                      // copy a's elem and sz
    sz = a.sz;
    a.elem = nullptr;                   // make a the empty vector
    a.sz = 0;
    return *this;                       // return a self-reference
}


// 18.2 Initializer list construction

template<typename T, typename A>
vector<T, A>::vector(std::initializer_list<T> lst)    // initializer-list constructor
    : sz{ lst.size() },
    elem{ new T[sz] }                   // uninitialized memory
{
    // copy from i_list begin to end into elem
    std::copy(lst.begin(), lst.end(), elem);
}


// 19.2.2 Reserve and Capacity

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc <= space) return;                  // never decrease allocation
    T* p = alloc.allocate(newalloc);    // allocate new space
    for (int i = 0; i < sz; ++i) alloc.construct(&p[i] , elem[i]);    // copy 
    for (int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);               // destroy
    alloc.deallocate(elem, space);                                  // deallocate old space
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
int vector<T, A>::capacity() const { return space; }              // obtain amount of free space


// 19.2.3 Resize

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T val)
// make the vector have newsize elements
// initialize each new element with the default value 0.0
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i) alloc.construct(&elem[i],val);     // construct
    for (int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);         // destroy
    sz = newsize;
}

// 19.2.4 push_back

template<typename T, typename A>
void vector<T,A>::push_back(const T& val)
// increase vector size by one; initalise the new element with d
{
    if (space == 0)
        reserve(8);                     //  start with space for 8 elements
    else if (sz == space)
        reserve(2 * space);             // get more space
    alloc.construct(&elem[sz],val);                       // add val at end
    ++sz;                               // increase the size (sz is the number of elements)
}

// range checking

template<typename T, typename A> T& vector<T, A>::at(int n)
{
    if (n < 0 || sz <= n) throw std::out_of_range();
    return elem[n];
}






// 17.5 Destructors
template<typename T, typename A>
vector<T,A>::~vector() { delete[] elem; }            // destructor

// 18.5 Access
template<typename T, typename A>
T& vector<T, A>::operator[](int n) { return elem[n]; }         // return element

template<typename T, typename A>
const T& vector<T, A>::operator[](int n) const
{
    return elem[n];
}

template<typename T, typename A>
int vector<T,A>::size() const { return sz; }                 // the current size