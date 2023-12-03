// Page 900 of ppp using cpp
// rj baldwin 01/08/2023
// quick demo of Matrix.h

#include <iostream>
#include "Matrix.h"


using namespace Numeric_lib;


void init(Matrix<int, 2>& a) // initialise each element to a characteristic value
{
    for (int i = 0; i < a.dim1(); ++i)
        for (int j = 0; j < a.dim2(); ++j)
            a[i][j] = 10 * i + j;
}

void print(const Matrix<int, 2>& a)      // print the elements row by row
{
    for (int i = 0; i < a.dim1(); ++i)  // dim1() is number of elements in first dimension
    {
        for (int j = 0; j < a.dim2(); ++j)  // dim2() is number of elements in second dimension
            std::cout << a[i][j] << '\t';
        std::cout << '\n';

    }
}


int main()
{
    const int n1{ 4 }; // rows
    const int n2{ 4 }; // colums

    // matrix of type double, with two dimensions, set at n1 by n1 rowns and columns
    Matrix<int, 2> a1(n1,n2);

    init(a1);
    print(a1);


}


