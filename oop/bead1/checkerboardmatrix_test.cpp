//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include "checkerboardmatrix.h"

#include "catch.hpp"


TEST_CASE("CheckerboardMatrix Setter and Getter")
{
    int n = 10;
    int m = 11;
    CheckerboardMatrix matrix = CheckerboardMatrix(m, n);
//    matrix(4,4) = 5;
//    matrix(3,9) = 7;
//
//    CHECK(matrix(4,4) == 5);
//    CHECK(matrix(4,5) == 0);
//    CHECK(matrix(3,9) == 7);
//    CHECK(matrix(3,6) == 0);
//    CHECK(matrix(3,7) == 0);

    matrix.setElement(4,4,5);
    matrix.setElement(3,9,7);
    CHECK(matrix.getElement(4,4) == 5);
    CHECK(matrix.getElement(3,9) == 7);
    CHECK(matrix.getElement(3,6) == 0);
    CHECK(matrix.getElement(3,7) == 0);
    CHECK(matrix.getElement(4,5) == 0);
}




