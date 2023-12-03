

#include <iostream>


// a very simplified vector of doubles

class Vector
{
    int sz;                                     // the size
    double* elem;                               // a pointer to the elements 

public:
    Vector(int s):sz{s},elem{new double[s]}{}   // constructor
    ~Vector(){delete[] elem;}                   // destructor

    int size() const { return sz; }             // the current size

    double get(int n) const { return elem[n]; } // access: read
    void set(int n, double v) { elem[n] = v; }  //access: write

    Vector& operator=(const Vector&);           //copy assignment

};

Vector& Vector::operator=(const Vector& a)
// make this vector a copy of a
{
    
}



int main()
{
   

    

}
