//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include "checkerboardmatrix.h"
#include "indextransformer.h"
#include <iostream>
#include <iomanip>
#include  <algorithm>
CheckerboardMatrix operator+(const CheckerboardMatrix& a, const CheckerboardMatrix& b)
{
    if (a._n != b._n || a._m != b._m)
    {
        throw CheckerboardMatrix::IncompatibleMatrixException();
    }

    CheckerboardMatrix c = CheckerboardMatrix(a._m, a._n);
    std::transform (a._v.begin(), a._v.end(), b._v.begin(), c._v.begin(), std::plus<int>());
    return c;
}

////Task: 	multiplying
////Input:    CheckerboardMatrix a    - matrix
////          CheckerboardMatrix b    - matrix
////Output:   CheckerboardMatrix      - result matrix
////Activity: multiplies the elements of the diagonals of the matrices
//CheckerboardMatrix operator*(const CheckerboardMatrix& a ,const CheckerboardMatrix& b)
//{
//    if(a._v.size()!=b._v.size()) throw CheckerboardMatrix::DIFFERENT;
//
//    CheckerboardMatrix c(a._v.size());
//
//    for(unsigned int i=0; i<c._v.size(); ++i) c._v[i] = a._v[i] * b._v[i];
//    return c;
//}
//


std::string CheckerboardMatrix::toString() const
{
    std::string result = "";
    for(int i=0; i<_m; i++)
    {
        for(int j=0; j<_n; j++)
        {
            if (j>0)
            {
                result = result + " ";
            }

            result += std::to_string(getElement(i, j));
        }

        if (i < _m-1)
        {
           result += "\n";
        }

    }
    return result;
}


std::ostream &operator <<(std::ostream& s, const CheckerboardMatrix& a)
{
    s << a.toString();
    return s;
}

void CheckerboardMatrix::setElement(int i, int j, int value)
{
    if ((i >= _n) || (j >= _m) || (i < 0) || (j < 0))
    {
        throw OverIndexedException();
    }

    if (IndexTransformer::isNullElement(i, j))
    {
        throw NullElementException();
    }

    _v[IndexTransformer::matrixToVector(_m, _n, i,j)] = value;
}


int CheckerboardMatrix::getElement(int i, int j) const
{
    if ((i >= _m) || (j >= _n) || (i < 0) || (j < 0))
    {
        throw OverIndexedException();
    }

    if (IndexTransformer::isNullElement(i, j))
    {
        return 0;
    }

    return _v[IndexTransformer::matrixToVector(_m, _n, i,j)];
}
