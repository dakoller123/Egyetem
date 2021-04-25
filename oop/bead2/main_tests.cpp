#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "solutions.h"
#include "studentEnor.h"

TEST_CASE("solveFirstProblem, no file found")
{
    CHECK((solveFirstProblem("inputfiles/nosuchfile.txt")) == false);
}

TEST_CASE("solveFirstProblem, empty file")
{
    CHECK((solveFirstProblem("inputfiles/testfile_empty.txt")) == true);
}

TEST_CASE("solveFirstProblem, single entry")
{
    CHECK((solveFirstProblem("inputfiles/testfile_1_single.txt")) == true);
}

TEST_CASE("solveSecondProblem, no file found")
{
    CHECK((solveSecondProblem("inputfiles/nosuchfile.txt")) == false);
}

TEST_CASE("solveSecondProblem, empty file")
{
    CHECK((solveSecondProblem("inputfiles/testfile_empty.txt")) == false);
}

TEST_CASE("solveSecondProblem, single entry")
{
    CHECK((solveSecondProblem("inputfiles/testfile_1_single.txt")) == true);
}

TEST_CASE("firstSolution, single entry, not enough paper")
{
    StudentEnor e("inputfiles/testfile_1_single.txt");
    struct student firstSolutionStudent;
    bool firstSolutionFound =  firstSolution(e, firstSolutionStudent);
    CHECK(firstSolutionFound == false);
}

TEST_CASE("firstSolution, single entry, enough paper")
{
    StudentEnor e("inputfiles/testfile_1_single_lot.txt");
    struct student firstSolutionStudent;
    bool firstSolutionFound =  firstSolution(e, firstSolutionStudent);
    CHECK(firstSolutionFound == true);
    CHECK(firstSolutionStudent.sumWeight == 33.2f);
}
