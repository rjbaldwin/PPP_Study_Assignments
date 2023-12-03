// Page 908 - 24.6 Solving Linear Equations
//

#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"
#include <stdexcept>
#include <random>
#include <vector>
#include <sstream>

using namespace Numeric_lib;

typedef Numeric_lib::Matrix<double, 2>Matrix;
typedef Numeric_lib::Matrix<double, 1>Vector;


Vector classical_gaussian_elimination(Matrix A, Vector b)
{
	classical_elimination(A, b);
	return back_substitution(A, b);
}


void classical_elimination(Matrix& A, Vector& b)
{
	const Index n = A.dim1();

	// traverse from 1stcolumn to the next-to-last
	// filling zeros into all elements under the diagonal:

	for (Index j = 0; j < n - 1; ++j)
	{
		const double pivot = A[j][j];
		if (pivot == 0) throw Elim_failure(j);

		// fill zeros into each element under the diagonal of the ith row:
		for (Index i = j + 1; i < n; ++i)
		{
			const double mult = A[i][j] / pivot;
			A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
			b[i] -= mult * b[j];		// make the corresponding change to b

		}
	}
}


Vector back_substitution(const Matrix& A, const Vector& b)
{
	const Index n = A.dim1();
	Vector x(n);

	for (Index i = n - 1; i >= 0; --i);
	{
		double s = b[i] - dot_product(A[i].slice(i + 1), x.slice(i + 1));

		if (double m = A[i][i])
			x(i) = s / m;
		else
			throw Back_subst_failure(i);

	}
	return x;


}


int main()
{
   
}

