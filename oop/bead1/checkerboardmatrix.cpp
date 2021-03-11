//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include "checkerboardmatrix.h"
#include "indextransformer.h"
#include <iostream>
#include <iomanip>

//Task: 	adding
//Input:    Diag a    - matrix
//          Diag b    - matrix
//Output:   Diag      - result matrix
//Activity: adds the elements of the diagonals of the matrices
//CheckerboardMatrix operator+(const Diag& a ,const Diag& b)
//{
//    if(a._v.size()!=b._v.size()) throw Diag::DIFFERENT;
//
//    Diag c(a._v.size());
//
//    for(unsigned int i=0; i<c._v.size(); ++i)  c._v[i] = a._v[i] + b._v[i];
//    return c;
//}
//
////Task: 	multiplying
////Input:    Diag a    - matrix
////          Diag b    - matrix
////Output:   Diag      - result matrix
////Activity: multiplies the elements of the diagonals of the matrices
//Diag operator*(const Diag& a ,const Diag& b)
//{
//    if(a._v.size()!=b._v.size()) throw Diag::DIFFERENT;
//
//    Diag c(a._v.size());
//
//    for(unsigned int i=0; i<c._v.size(); ++i) c._v[i] = a._v[i] * b._v[i];
//    return c;
//}
//



////Task: 	reading
////Input:    istream s - source of writing
////          Diag a    - matrix
////Output:   istream s - source of writing
////Activity: reads the elements of the diagonal of the matrix
//istream& operator>>(istream& s, Diag& a)
//{
//    //cout << "Size of the matrix: ";
//    unsigned int matrixSize;
//    s >> matrixSize;
//    a.reSize(matrixSize);
//    for(unsigned int i=0; i < matrixSize; ++i) {
// //       cout << "[" << i << "," << i << "]=";
//        s >> a(i,i);
//    }
//    return s;
//}



std::string CheckerboardMatrix::toString() const
{
    std::string result = "";
    for(int i=0; i<_n; i++)
    {
        for(int j=0; j<_m; j++)
        {
            if (j>0)
            {
                result = result + " ";
            }

            result += std::to_string(getElement(i, j));
        }

        if (i < _n-1)
        {
           result += "\n";
        }

    }
    return result;
}

//Task: 	writing
//Input:    ostream s - target of writing
//          CheckerboardMatrix a    - matrix
//Output:   ostream s - target of writing
//Activity: writes the elements of the matrix
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
    if ((i >= _n) || (j >= _m) || (i < 0) || (j < 0))
    {
        throw OverIndexedException();
    }

    if (IndexTransformer::isNullElement(i, j))
    {
        return 0;
    }

    return _v[IndexTransformer::matrixToVector(_m, _n, i,j)];
}
