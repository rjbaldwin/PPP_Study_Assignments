//
// Stroustrup - Programming Principles & Practice
//
// Chapter 19 follow through - vector design 16/06/2023
//
// implementation file

#pragma once
#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <string>
#include "RobVector.h"

using std::string;



    // 19.2.1 Default constructor
template<typename T>
    vector<T>::vector() :sz{ 0 }, elem{ nullptr }, space{ 0 } {};


    // 17.4 Free store & pointers (needed for elem)
template<typename T>
    vector<T>::vector(int s)                          // constructor
        : sz{ s }, elem{ new T[s] }, space{ s }
    {
        for (int i = 0; i < sz; ++i)
            elem[i] = 0;
    }

    // 18.3.1 Copy constructors
template<typename T>
    vector<T>::vector(const vector& arg)
        : sz{ arg.sz }, elem{ new T[arg.sz] }
    {
        std::copy(arg.elem, arg.elem + sz, elem);
    }


    // 19.2.5 Copy assignments
    template<typename T>
    vector<T>& vector<T>::operator=(const vector& a)
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
    template<typename T>
    vector<T>::vector(vector&& a)                      // move constructor
        : sz{ a.sz }, elem{ a.elem }        // copy a's elem and sz
    {
        a.sz = 0;                           // make a the empty vector
        a.elem = nullptr;
    }

    template<typename T>
    vector<T>& vector<T>::operator=(vector&& a)           // move assignment
    {                                       // move a to this vector
        delete[] elem;                      // deallocate old space
        elem = a.elem;                      // copy a's elem and sz
        sz = a.sz;
        a.elem = nullptr;                   // make a the empty vector
        a.sz = 0;
        return *this;                       // return a self-reference
    }


    // 18.2 Initializer list construction

    template<typename T>
    vector<T>::vector(std::initializer_list<T> lst)    // initializer-list constructor
        : sz{ lst.size() },
        elem{ new T[sz] }                   // uninitialized memory
    {
        // copy from i_list begin to end into elem
        std::copy(lst.begin(), lst.end(), elem);
    }


    // 19.2.2 Reserve and Capacity

    template<typename T>
    void vector<T>::reserve(int newalloc)
    {
        if (newalloc <= space) return;                  // never decrease allocation
        T* p = new T[newalloc];                         // allocate new space
        for (int i = 0; i < sz; ++i) p[i] = elem[i];    // copy old elements
        delete[] elem;                                  // deallocate old space
        elem = p;
        space = newalloc;
    }

    template<typename T>
    int vector<T>::capacity() const { return space; }              // obtain amount of free space


    // 19.2.3 Resize

    template<typename T> 
    void vector<T>::resize(int newsize, T def)
        // make the vector have newsize elements
        // initialize each new element with the default value 0.0
    {
        reserve(newsize);
        for (int i = sz; i < newsize; ++i) elem[i] = 0;     // initialise new elements
        sz = newsize;
    }

    // 19.2.4 push_back

    template<typename T>
    void vector<T>::push_back(const T& d)
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
    template<typename T>
    vector<T>::~vector() { delete[] elem; }            // destructor

    // 18.5 Access
    template<typename T>
    T vector<T>::operator[](int n) { return elem[n]; }         // return element

    template<typename T>
    const T& vector<T>::operator[](int n) const 
    { 
        return elem[n]; 
    }

    template<typename T>
    int vector<T>::size() const { return sz; }                 // the current size




