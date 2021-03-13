//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include "checkerboardmatrix.h"

#include "catch.hpp"


TEST_CASE("CheckerboardMatrix Setter, Getter")
{
    int n = 10;
    int m = 11;
    int on = 30;
    int om = 40;
    CheckerboardMatrix matrix = CheckerboardMatrix(m, n);
    CheckerboardMatrix other = CheckerboardMatrix(om, on);

    matrix.setElement(4,4,5);
    other.setElement(4,4,10);
    other.setElement(8,12,7);
    matrix.setElement(3,9,7);

    //last element
    other.setElement(om-1,on-1, 54);
    matrix.setElement(m-1,n-2, 26);

    CHECK(matrix.getElement(4,4) == 5);
    CHECK(matrix.getElement(3,9) == 7);
    CHECK(other.getElement(4,4) == 10);
    CHECK(other.getElement(8,12) == 7);
    CHECK(matrix.getElement(3,6) == 0);
    CHECK(matrix.getElement(3,7) == 0);
    CHECK(matrix.getElement(4,5) == 0);

    CHECK(other.getElement(om-1,on-1 == 54));
    CHECK(matrix.getElement(m-1,n-2 == 26));

    CHECK_THROWS_WITH(matrix.getElement(13,1), CheckerboardMatrix::OverIndexedException() );
    CHECK_THROWS_WITH(matrix.getElement(5,42), CheckerboardMatrix::OverIndexedException() );
    CHECK_THROWS_WITH(matrix.setElement(0,1, 12), CheckerboardMatrix::NullElementException() );
}


TEST_CASE("CheckerboardMatrix toString")
{
    CheckerboardMatrix matrix = CheckerboardMatrix(2, 2);
    CHECK(matrix.toString() == "0 0\n0 0");
}

TEST_CASE("CheckerboardMatrix addition operator")
{
    CheckerboardMatrix matrixA = CheckerboardMatrix(5, 5);
    CheckerboardMatrix matrixB = CheckerboardMatrix(5, 5);

    matrixA.setElement(0,0,5);
    matrixA.setElement(3,1,10);
    matrixA.setElement(4,4,8);

    matrixB.setElement(0,2,6);
    matrixB.setElement(3,1,20);
    matrixB.setElement(4,4,-2);

    CheckerboardMatrix matrixC = matrixA + matrixB;

    CHECK(matrixC.getElement(0,0) == 5);
    CHECK(matrixC.getElement(3,1) == 30);
    CHECK(matrixC.getElement(4,4) == 6);
    CHECK(matrixC.getElement(0,2) == 6);

    CHECK(matrixA.getElement(0,0) == 5);
    CHECK(matrixA.getElement(3,1) == 10);
    CHECK(matrixA.getElement(4,4) == 8);
    CHECK(matrixA.getElement(0,2) == 0);

    CHECK(matrixB.getElement(0,2) == 6);
    CHECK(matrixB.getElement(3,1) == 20);
    CHECK(matrixB.getElement(4,4) == -2);
    CHECK(matrixB.getElement(0,0) == 0);
}



