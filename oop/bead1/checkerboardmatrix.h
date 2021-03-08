//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#pragma once
#include <iostream>
#include <vector>
struct MatrixIndices
{
    int x;
    int y;
};
//Class of checkerboard matrixes
//Methods: add, multiply, write, read, refer to an element
//Representation: only the non-zero elements
class CheckerboardMatrix {
public:
    enum Exceptions{OVERINDEXED, NULLPART, DIFFERENT};

    CheckerboardMatrix(){ }
    CheckerboardMatrix(const int m, const int n): _v(m*n, 0), _m(m), _n(n) { }
    //CheckerboardMatrix(const int m, const int n, const std::vector<int> &v): _v(v), _m(m), _n(n) { }

    void reSize(int k) { _v.resize(k, 0); }

      int operator()(int i, int j) const;
//      int& operator()(int i, int j);

//    friend CheckerboardMatrix operator+ (const CheckerboardMatrix& a, const CheckerboardMatrix& b);
//    friend CheckerboardMatrix operator* (const CheckerboardMatrix& a, const CheckerboardMatrix& b);
//    friend std::istream& operator>> (std::istream& s, CheckerboardMatrix& a);
      friend std::ostream& operator<< (std::ostream& s, const CheckerboardMatrix& a);
private:
    int _m;
    int _n;
    std::vector<int> _v;
    int matrixIndicesToVectorIndex(MatrixIndices mi);
};
