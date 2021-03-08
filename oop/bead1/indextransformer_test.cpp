//Author:    Koller Dávid Dániel
//Date:      2021.03.07.
//Title:     Checkerboard matrix

#include "indextransformer.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("How div works")
{
    CHECK(1/2 == 0);
    CHECK(3 / 2 == 1);
    CHECK(4 / 2 == 2);
    CHECK(23 / 11 == 2);

}


TEST_CASE("MatrixToVector 2x2")
{
    //                                     m n  i  j     vi
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

TEST_CASE("MatrixToVector 3x4")
{
    CHECK(IndexTransformer::matrixToVector(3,4, 0, 0) == 0);
    CHECK(IndexTransformer::matrixToVector(3,4, 0, 2) == 1);
    CHECK(IndexTransformer::matrixToVector(3,4, 1, 1) == 2);
    CHECK(IndexTransformer::matrixToVector(3,4, 1, 3) == 3);
    CHECK(IndexTransformer::matrixToVector(3,4, 2, 0) == 4);
    CHECK(IndexTransformer::matrixToVector(3,4, 2, 2) == 5);
}

//vectorToMatrix(int m, int n, int vi, int& i, int& j)
TEST_CASE("VectorToMatrix 3x4")
{
    int i = -1;
    int j = -1;
    int m = 3;
    int n = 4;
    IndexTransformer::vectorToMatrix(m, n, 0, i, j);
    CHECK(i == 0 && j == 0);
//    CHECK(IndexTransformer::matrixToVector(3,4, 0, 0) == 0);
//    CHECK(IndexTransformer::matrixToVector(3,4, 0, 2) == 1);
//    CHECK(IndexTransformer::matrixToVector(3,4, 1, 1) == 2);
//    CHECK(IndexTransformer::matrixToVector(3,4, 1, 3) == 3);
//    CHECK(IndexTransformer::matrixToVector(3,4, 2, 0) == 4);
//    CHECK(IndexTransformer::matrixToVector(3,4, 2, 2) == 5);
}
