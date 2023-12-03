

#include <iostream>
#include "Matrix.h"


using namespace Numeric_lib;

void f(int n1, int n2, int n3)
{
	Matrix<double, 1> ad1(n1);	// elements are doubles; one dimension
	Matrix<int, 1>ai1(n1);		// elements are ints; one dimension
	ad1(7) = 0;					// subscript using () -- Fortran style
	ad1[7] = 8;					// [] also works -- C style

	Matrix<double, 2> ad2(n1, n2);	// 2-dimensional
	Matrix<double, 3> ad3(n1, n2, n3);	// 3-dimensional
	ad2(3, 4) = 7.5;					// true multidimentional subscripting
	ad3(3, 4, 5) = 9.2;


}



int main()
{

	

}


