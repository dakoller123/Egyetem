//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include "checkerboardmatrix.h"

#include "catch.hpp"


TEST_CASE("CheckerboardMatrix Setter, Getter")
{
    int width = 10;
    int height = 11;
    int otherWidth = 30;
    int otherHeight = 40;
    CheckerboardMatrix matrix = CheckerboardMatrix(height, width);
    CheckerboardMatrix other = CheckerboardMatrix(otherWidth, otherHeight);

    matrix.setElement(4,4,5);
    other.setElement(4,4,10);
    other.setElement(8,12,7);
    matrix.setElement(3,9,7);

    CHECK(matrix.getElement(4,4) == 5);
    CHECK(matrix.getElement(3,9) == 7);
    CHECK(other.getElement(4,4) == 10);
    CHECK(other.getElement(8,12) == 7);
    CHECK(matrix.getElement(3,6) == 0);
    CHECK(matrix.getElement(3,7) == 0);
    CHECK(matrix.getElement(4,5) == 0);

    CHECK_THROWS_WITH(matrix.getElement(13,1), CheckerboardMatrix::OverIndexedException() );
    CHECK_THROWS_WITH(matrix.getElement(5,42), CheckerboardMatrix::OverIndexedException() );
    CHECK_THROWS_WITH(matrix.setElement(0,1, 12), CheckerboardMatrix::NullElementException() );
}

TEST_CASE("CheckerboardMatrix Setter, Getter, last element")
{
    int width = 3;
    int height = 5;

    CheckerboardMatrix matrix = CheckerboardMatrix(height, width);
    matrix.setElement(4,2,31);
    CHECK(matrix.getElement(4,1) == 0);
    CHECK(matrix.getElement(4,2) == 31);

    width = 3;
    height = 6;

    matrix = CheckerboardMatrix(height, width);
    matrix.setElement(5,1,26);
    CHECK(matrix.getElement(5,1) == 26);
    CHECK(matrix.getElement(5,2) == 0);
}


TEST_CASE("CheckerboardMatrix toString")
{
    int width = 2;
    int height = 3;
    CheckerboardMatrix matrix = CheckerboardMatrix(height, width);
    CHECK(matrix.toString() == "0 0\n0 0\n0 0");
    matrix.setElement(0,0,9);
    matrix.setElement(1,1,5);
    matrix.setElement(2,0,3);
    CHECK(matrix.toString() == "9 0\n0 5\n3 0");
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

TEST_CASE("CheckerboardMatrix addition operator, exception handling")
{
    CheckerboardMatrix matrixA = CheckerboardMatrix(10,4);
    CheckerboardMatrix matrixB = CheckerboardMatrix(10,4);
    CHECK_NOTHROW((matrixA+matrixB));

    matrixA = CheckerboardMatrix(10,4);
    matrixB = CheckerboardMatrix(11,4);
    CHECK_THROWS_WITH(matrixA+matrixB, CheckerboardMatrix::IncompatibleMatrixException() );

    matrixA = CheckerboardMatrix(10,4);
    matrixB = CheckerboardMatrix(10,5);
    CHECK_THROWS_WITH(matrixA+matrixB, CheckerboardMatrix::IncompatibleMatrixException() );
}
//
//
//TEST_CASE("CheckerboardMatrix multiplication operator, incompatible matrices")
//{
//    CheckerboardMatrix matrixA = CheckerboardMatrix(10,4);
//    CheckerboardMatrix matrixB = CheckerboardMatrix(10,4);
//    CHECK_THROWS_WITH(matrixA*matrixB, CheckerboardMatrix::IncompatibleMatrixException() );
//}





