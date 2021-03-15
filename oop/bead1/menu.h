//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include <iostream>
#include "checkerboardmatrix.h"
#include "read.hpp"


class Menu
{
    public:
        Menu() : a(1,1), b(1,1) { }
        void run();
    private:
        CheckerboardMatrix a, b;
        void menuWrite();
        void getElement() const;
        void setElement();
        void writeMatrix();
        void sum();
        void mul();
        void resizeMatrix();
};
