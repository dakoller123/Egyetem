//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include "indextransformer.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("IsNullElement")
{
    CHECK(IndexTransformer::isNullElement(0, 1));
    CHECK(IndexTransformer::isNullElement(6, 7));
    CHECK(IndexTransformer::isNullElement(2, 7));
    CHECK(IndexTransformer::isNullElement(4, 5));
    CHECK(!(IndexTransformer::isNullElement(4, 4)));
    CHECK(!(IndexTransformer::isNullElement(5, 11)));
    CHECK(!(IndexTransformer::isNullElement(2, 10)));
    CHECK(!(IndexTransformer::isNullElement(6, 2)));;
}

TEST_CASE("MatrixToVector 2x2")
{
    //                                     width height i j vi
    CHECK(IndexTransformer::matrixToVector(2,2, 0, 0) == 0);
    CHECK(IndexTransformer::matrixToVector(2,2, 1, 1) == 1);

}

TEST_CASE("MatrixToVector 3x3")
{

    CHECK(IndexTransformer::matrixToVector(3,3, 0, 0) == 0);
    CHECK(IndexTransformer::matrixToVector(3,3, 2, 0) == 3);
    CHECK(IndexTransformer::matrixToVector(3,3, 1, 1) == 2);
    CHECK(IndexTransformer::matrixToVector(3,3, 0, 2) == 1);
    CHECK(IndexTransformer::matrixToVector(3,3, 2, 2) == 4);
}

TEST_CASE("MatrixToVector 4x3")
{
    //static int matrixToVector(int w   , int height, int i, int j)
    // static int matrixToVector(int width, int height, int i, int j)
    CHECK(IndexTransformer::matrixToVector(3,4, 0, 0) == 0);
    CHECK(IndexTransformer::matrixToVector(3,4, 0, 2) == 1);
    CHECK(IndexTransformer::matrixToVector(3,4, 1, 1) == 2);
    CHECK(IndexTransformer::matrixToVector(3,4, 1, 3) == 3);
    CHECK(IndexTransformer::matrixToVector(3,4, 2, 0) == 4);
    CHECK(IndexTransformer::matrixToVector(3,4, 2, 2) == 5);
}


TEST_CASE("MatrixToVector 5x5")
{
    CHECK(IndexTransformer::matrixToVector(5,5, 4, 4) == 12);

}

TEST_CASE("VectorToMatrix 3x4")
{
    Coord c;

    c = IndexTransformer::vectorToMatrix(3, 4, 0);
    CHECK(c.i == 0);
    CHECK(c.j == 0);

    c = IndexTransformer::vectorToMatrix(3, 4, 1);
    CHECK(c.i == 0);
    CHECK(c.j == 2);

    c = IndexTransformer::vectorToMatrix(3, 4, 4);
    CHECK(c.i == 2);
    CHECK(c.j == 0);

    c = IndexTransformer::vectorToMatrix(3, 4, 5);
    CHECK(c.i == 2);
    CHECK(c.j == 2);

    c = IndexTransformer::vectorToMatrix(3, 4, 3);
    CHECK(c.i == 1);
    CHECK(c.j == 3);
}

TEST_CASE("VectorToMatrix 3x3")
{
    int m = 3;
    int n = 3;
    Coord c;

    c = IndexTransformer::vectorToMatrix(m, n, 0);
    CHECK(c.i == 0);
    CHECK(c.j == 0);

    c = IndexTransformer::vectorToMatrix(m, n, 4);
    CHECK(c.i == 2);
    CHECK(c.j == 2);

    c = IndexTransformer::vectorToMatrix(m, n, 2);
    CHECK(c.i == 1);
    CHECK(c.j == 1);

    c = IndexTransformer::vectorToMatrix(m, n, 3);
    CHECK(c.i == 2);
    CHECK(c.j == 0);
}

TEST_CASE("VectorToMatrix 5x5")
{
    int m = 5;
    int n = 5;
    Coord c;

    c = IndexTransformer::vectorToMatrix(m, n, 9);
    CHECK(c.i == 3);
    CHECK(c.j == 3);

    c = IndexTransformer::vectorToMatrix(m, n, 12);
    CHECK(c.i == 4);
    CHECK(c.j == 4);

    c = IndexTransformer::vectorToMatrix(m, n, 8);
    CHECK(c.i == 3);
    CHECK(c.j == 1);

    c = IndexTransformer::vectorToMatrix(m, n, 3);
    CHECK(c.i == 1);
    CHECK(c.j == 1);

}

TEST_CASE("getNextCoord")
{
    Coord current, next;
    current.i = 4;
    current.j = 3;
    next = IndexTransformer::getNextCoord(5, current);
    CHECK(next.i == 4);
    CHECK(next.j == 4);
    next = IndexTransformer::getNextCoord(5, next);
    CHECK(next.i == 5);
    CHECK(next.j == 0);
    next = IndexTransformer::getNextCoord(5, next);
    CHECK(next.i == 5);
    CHECK(next.j == 1);
    next = IndexTransformer::getNextCoord(5, next);
    CHECK(next.i == 5);
    CHECK(next.j == 2);
}



