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

    matrix.setElement(4,4,5);
    matrix.setElement(3,9,7);
    CHECK(matrix.getElement(4,4) == 5);
    CHECK(matrix.getElement(3,9) == 7);
    CHECK(matrix.getElement(3,6) == 0);
    CHECK(matrix.getElement(3,7) == 0);
    CHECK(matrix.getElement(4,5) == 0);

    CHECK_THROWS_WITH(matrix.getElement(13,1), CheckerboardMatrix::OverIndexedException() );
    CHECK_THROWS_WITH(matrix.getElement(5,42), CheckerboardMatrix::OverIndexedException() );
    CHECK_THROWS_WITH(matrix.setElement(0,1, 12), CheckerboardMatrix::NullElementException() );
}




