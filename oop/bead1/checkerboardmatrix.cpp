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
    if (a._width != b._width || a._height != b._height)
    {
        throw CheckerboardMatrix::IncompatibleMatrixException();
    }

    CheckerboardMatrix c = CheckerboardMatrix(a._height, a._width);
    std::transform (a._v.begin(), a._v.end(), b._v.begin(), c._v.begin(), std::plus<int>());
    return c;
}

CheckerboardMatrix operator*(const CheckerboardMatrix& a ,const CheckerboardMatrix& b)
{
    if(a._width!=b._height)
    {
        throw CheckerboardMatrix::IncompatibleMatrixException();
    }

    CheckerboardMatrix c(a._height, b._width);

    for (int i=0; i<c._height; i++)
    {
        for (int j = 0; j<c._width; j++)
        {
            int value = 0;
            for (int k = 0; k<a._width; k++)
            {
                value += a.getElement(i, k) * b.getElement(k,j);
            }
            c.setElement(i, j, value);
        }

    }
    return c;
}

std::string CheckerboardMatrix::toString() const
{
    std::string result = "";
    for(int i=0; i<_height; i++)
    {
        for(int j=0; j<_width; j++)
        {
            if (j>0)
            {
                result = result + " ";
            }

            result += std::to_string(getElement(i, j));
        }

        if (i < _height-1)
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
    if ((i >= _height) || (j >= _width) || (i < 0) || (j < 0))
    {
        throw OverIndexedException();
    }

    if (IndexTransformer::isNullElement(i, j))
    {
        throw NullElementException();
    }

    _v[IndexTransformer::matrixToVector(_width, _height, i,j)] = value;
}

int CheckerboardMatrix::getElement(int i, int j) const
{
    if ((i >= _height) || (j >= _width) || (i < 0) || (j < 0))
    {
        throw OverIndexedException();
    }

    if (IndexTransformer::isNullElement(i, j))
    {
        return 0;
    }

    return _v[IndexTransformer::matrixToVector(_width, _height, i,j)];
}
