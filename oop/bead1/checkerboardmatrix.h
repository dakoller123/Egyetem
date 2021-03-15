//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#pragma once
#include <iostream>
#include <vector>

class CheckerboardMatrix {

    public:
        static std::string OverIndexedException() { return "OverIndexed"; }
        static std::string NullElementException() { return "NullElementException"; }
        static std::string IncompatibleMatrixException() { return "IncompatibleMatrixException"; }
        static std::string InvalidMatrixDimensionException() { return "InvalidMatrixDimensionException"; }

        CheckerboardMatrix(const int height, const int width):  _height(height), _width(width), _v((height*width/2)+1, 0)
        {
            if (_height  < 1 || _width < 1 )
            {
                throw InvalidMatrixDimensionException();
            }
        }

        int getElement (int i, int j) const;
        void setElement (int i, int j, int value);

        friend CheckerboardMatrix operator+ (const CheckerboardMatrix& a, const CheckerboardMatrix& b);
        friend CheckerboardMatrix operator* (const CheckerboardMatrix& a, const CheckerboardMatrix& b);

        std::string toString() const;

        friend std::ostream& operator<< (std::ostream& s, const CheckerboardMatrix& a);

        int getWidth() const { return _width; }
        int getHeight() const { return _height; }

    private:

        int _height;
        int _width;
        std::vector<int> _v;

};
