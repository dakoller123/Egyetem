#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "solutions.h"

TEST_CASE("FirstProblem, no file found")
{
    CHECK((solveFirstProblem("inputfiles/nosuchfile.txt")) == false);
}

TEST_CASE("FirstProblem, empty file")
{
    CHECK((solveFirstProblem("inputfiles/testfile_empty.txt")) == false);
}

TEST_CASE("FirstProblem, single entry")
{
    CHECK((solveFirstProblem("inputfiles/testfile_1_single.txt")) == true);
}

TEST_CASE("SecondProblem, no file found")
{
    CHECK((solveSecondProblem("inputfiles/nosuchfile.txt")) == false);
}

TEST_CASE("SecondProblem, empty file")
{
    CHECK((solveSecondProblem("inputfiles/testfile_empty.txt")) == false);
}

TEST_CASE("SecondProblem, single entry")
{
    CHECK((solveSecondProblem("inputfiles/testfile_1_single.txt")) == true);
}

