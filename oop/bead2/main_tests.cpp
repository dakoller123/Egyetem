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

TEST_CASE("firstSolution, multiple entry, enough paper, first student")
{
    StudentEnor e("inputfiles/testfile_1_multi_lot_first.txt");
    struct student firstSolutionStudent;
    bool firstSolutionFound =  firstSolution(e, firstSolutionStudent);
    CHECK(firstSolutionFound == true);
    CHECK(firstSolutionStudent.sumWeight == 33.2f);
}


TEST_CASE("firstSolution, multiple entry, enough paper, last student")
{

    StudentEnor e("inputfiles/testfile_1_multi_lot_last.txt");
    struct student firstSolutionStudent;
    bool firstSolutionFound =  firstSolution(e, firstSolutionStudent);
    CHECK(firstSolutionFound == true);
    CHECK(firstSolutionStudent.sumWeight == 20.0f);
}


TEST_CASE("firstSolution, multiple entry, enough paper, multiple students")
{
    StudentEnor e("inputfiles/testfile_1_multi_lot_multi.txt");
    struct student firstSolutionStudent;
    bool firstSolutionFound =  firstSolution(e, firstSolutionStudent);
    CHECK(firstSolutionFound == true);
    CHECK(firstSolutionStudent.sumWeight == 33.2f);
}

TEST_CASE("secondSolution, single entry")
{
    StudentEnor e("inputfiles/testfile_1_single.txt");
    ClassEnor classEnor(e);
    struct classResult bestClass;
    bool fileNotEmpty = secondSolution(classEnor, bestClass);
    CHECK(fileNotEmpty == true);
    CHECK(bestClass.classId == "4c");
    CHECK(bestClass.sumWeight == 13.2f);
}

TEST_CASE("secondSolution, multiple entry, first is best")
{
    StudentEnor e("inputfiles/testfile_2_first.txt");
    ClassEnor classEnor(e);
    struct classResult bestClass;
    bool fileNotEmpty = secondSolution(classEnor, bestClass);
    CHECK(fileNotEmpty == true);
    CHECK(bestClass.classId == "4c");
    CHECK(bestClass.sumWeight == 66.4f);
}

TEST_CASE("secondSolution, multiple entry, last is best")
{
    StudentEnor e("inputfiles/testfile_2_last.txt");
    ClassEnor classEnor(e);
    struct classResult bestClass;
    bool fileNotEmpty = secondSolution(classEnor, bestClass);
    CHECK(fileNotEmpty == true);
    CHECK(bestClass.classId == "4b");
    CHECK(bestClass.sumWeight == 67.0f);
}
