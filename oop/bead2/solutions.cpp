#include <iostream>
#include <iomanip>

#include "studentEnor.h"
#include "classEnor.h"
#include "solutions.h"

int main()
{
//    std::string fileName;
//    std::cout<<"Enter the name of the input file, please:";
//    std::cin>>fileName;
    std::string fileName = "input.txt";
    solveFirstProblem(fileName);
    solveSecondProblem(fileName);

    return 0;
}
