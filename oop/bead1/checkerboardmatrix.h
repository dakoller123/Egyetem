//Author:    Koller D�vid D�niel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#pragma once
#include <iostream>
#include <vector>

//Class of checkerboard matrixes
//Methods: add, multiply, write, read, refer to an element
//Representation: only the non-zero elements
class CheckerboardMatrix {

    public:
        static std::string OverIndexedException() {return "OverIndexed";}
        static std::string NullElementException() {return "NullElementException";}
        static std::string IncompatibleMatrixException() {return "IncompatibleMatrixException";}

        CheckerboardMatrix(const int m, const int n):  _m(m), _n(n), _v(m*n/2, 0) { }

    //
    //    int operator()(int i, int j) const;
    //    int& operator()(int i, int j);

        int getElement (int i, int j) const;
        void setElement (int i, int j, int value);

        friend CheckerboardMatrix operator+ (const CheckerboardMatrix& a, const CheckerboardMatrix& b);
    //    friend CheckerboardMatrix operator* (const CheckerboardMatrix& a, const CheckerboardMatrix& b);
         //friend std::istream& operator>> (std::istream& s, CheckerboardMatrix& a);

         std::string toString() const;

        friend std::ostream& operator<< (std::ostream& s, const CheckerboardMatrix& a);

    private:

        int _m;
        int _n;
        std::vector<int> _v;

};
