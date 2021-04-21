#define CATCH_CONFIG_MAIN
#include "catch.hpp"




TEST_CASE("FirstProblem, empty file")
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
