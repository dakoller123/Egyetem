//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include "checkerboardmatrix.h"
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
//Task: 	writing
//Input:    ostream s - target of writing
//          CheckerboardMatrix a    - matrix
//Output:   ostream s - target of writing
//Activity: writes the elements of the matrix
//std::ostream &operator <<(std::ostream& s, const CheckerboardMatrix& a)
//{
//    for(unsigned int i=0; i<a._v.size(); ++i)
//    {
//
//        s << std::endl;
//    }
//    return s;
//}

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







//Task: 	getting
//Input:    int i,j - indexes of element
//Output:   int     - the element of the matrix in ith row and jth column
//Activity: gets the given elements of the diagonal matrix
//int CheckerboardMatrix::operator()(int i, int j) const
//{
//    if ((i >= _n) || (j >= _m))
//    {
//        throw OVERINDEXED;
//    }
//
////    if (isNullElement(i, j))
////    {
////        return 0;
////    }
//
//    return _v[i];
//}

////Task: 	setting
////Input:    int i,j - indexes of element
////Output:   int     - the element of the matrix in ith row and jth column
////Activity: gives a reference to the given elements of the diagonal matrix
//int& Diag::operator()(int i, int j)
//{
//    if ((i>=int(_v.size()) || i<0 ) || (j>=int(_v.size()) || j<0 )) throw OVERINDEXED;
//    if (i!=j) throw NULLPART;
//    return _v[i];
//}
