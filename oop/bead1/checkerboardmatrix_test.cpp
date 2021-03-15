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

TEST_CASE("CheckerboardMatrix, setter, getter, last element in row and next element")
{
                                                    //height: 3  width: 4
    CheckerboardMatrix matrixB = CheckerboardMatrix(3, 4);
    matrixB.setElement(1,3,7);
    matrixB.setElement(2,0,5);
    CHECK(matrixB.getElement(1,3) == 7);
    CHECK(matrixB.getElement(2,0) == 5);
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

    CheckerboardMatrix matrixB = CheckerboardMatrix(height, width);
    matrixB.setElement(5,1,26);
    CHECK(matrixB.getElement(5,1) == 26);
    CHECK(matrixB.getElement(5,2) == 0);
}


TEST_CASE("CheckerboardMatrix toString")
{
    int height = 3;
    int width = 2;
    CheckerboardMatrix matrix = CheckerboardMatrix(height, width);
    CHECK(matrix.toString() == "0 0\n0 0\n0 0");
    matrix.setElement(0,0,9);
    matrix.setElement(1,1,5);
    matrix.setElement(2,0,3);
    CHECK(matrix.toString() == "9 0\n0 5\n3 0");

    CheckerboardMatrix matrixB = CheckerboardMatrix(3, 4);
    matrixB.setElement(0,0,8);
    matrixB.setElement(0,2,7);
    matrixB.setElement(1,1,9);
    matrixB.setElement(1,3,2);
    matrixB.setElement(2,0,5);
    matrixB.setElement(2,2,1);
    CHECK(matrixB.getElement(1,3) == 2);
    CHECK(matrixB.toString() == "8 0 7 0\n0 9 0 2\n5 0 1 0");

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

    CHECK(matrixC.getHeight() == 5);
    CHECK(matrixC.getWidth() == 5);

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
    CHECK_NOTHROW((CheckerboardMatrix(10,4)+CheckerboardMatrix(10,4)));

    CHECK_THROWS_WITH(CheckerboardMatrix(10,4)+CheckerboardMatrix(11,4), CheckerboardMatrix::IncompatibleMatrixException() );

    CHECK_THROWS_WITH(CheckerboardMatrix(10,4)+CheckerboardMatrix(10,5), CheckerboardMatrix::IncompatibleMatrixException() );
}


TEST_CASE("CheckerboardMatrix multiplication operator, exception handling")
{
    CHECK_NOTHROW((CheckerboardMatrix(10,4)*CheckerboardMatrix(4,8)));

    CHECK_THROWS_WITH(CheckerboardMatrix(10,4)*CheckerboardMatrix(5,10), CheckerboardMatrix::IncompatibleMatrixException() );

    CHECK_THROWS_WITH(CheckerboardMatrix(10,4)*CheckerboardMatrix(3,10), CheckerboardMatrix::IncompatibleMatrixException() );
}

TEST_CASE("CheckerboardMatrix multiplication operator")
{
    CheckerboardMatrix matrixA = CheckerboardMatrix(2, 3);
    CheckerboardMatrix matrixB = CheckerboardMatrix(3, 4);

    matrixA.setElement(0,0,3);
    matrixA.setElement(0,2,1);
    matrixA.setElement(1,1,2);

    matrixB.setElement(0,0,8);
    matrixB.setElement(0,2,7);
    matrixB.setElement(1,1,9);
    matrixB.setElement(1,3,2);
    matrixB.setElement(2,0,5);
    matrixB.setElement(2,2,1);


    CheckerboardMatrix matrixC = matrixA * matrixB;

    CHECK(matrixC.getHeight() == 2);
    CHECK(matrixC.getWidth() == 4);

    CHECK(matrixC.getElement(0,0) == 29);
    CHECK(matrixC.getElement(0,1) == 0);
    CHECK(matrixC.getElement(0,2) == 22);
    CHECK(matrixC.getElement(0,3) == 0);

    CHECK(matrixC.getElement(1,0) == 0);
    CHECK(matrixC.getElement(1,1) == 18);
    CHECK(matrixC.getElement(1,2) == 0);
    CHECK(matrixC.getElement(1,3) == 4);
}




