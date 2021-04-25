#include <iostream>
#include <iomanip>

#include "studentEnor.h"
#include "classEnor.h"

bool firstSolution(StudentEnor& e, struct student& firstHardworkingStudent)
{
    e.first();
    bool hardworkingStudentFound = false;
    firstHardworkingStudent = e.current();
    while (!hardworkingStudentFound && !e.end())
    {
        if (e.current().sumWeight >= 20.0f)
        {
            hardworkingStudentFound = true;
            firstHardworkingStudent = e.current();
        }
        else
        {
            e.next();
        }
    }

    return hardworkingStudentFound;
};

//returns false upon fileerror
bool solveFirstProblem(std::string fileName)
{
  try{
        StudentEnor e = StudentEnor(fileName);

        struct student firstHardworkingStudent;

        bool hardworkingStudentFound = firstSolution(e, firstHardworkingStudent);

        if (hardworkingStudentFound)
        {
            std::cout<< "First student more than 20kg of paper collected: " << firstHardworkingStudent.name << " sumWeight: " << firstHardworkingStudent.sumWeight << std::endl;
        }
        else
        {
            std::cout << "None of the students collected more than 20 kg of paper!" << std::endl;
        }

        return true;

    }
    catch(StudentEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< fileName << std::endl;
        return false;
    }
};

//false if file is empty, true otherwise
bool secondSolution(ClassEnor& classEnor, struct classResult& bestClass)
{
    classEnor.first();
    if (classEnor.isEmpty())
    {
        return false;
    }
    bestClass = classEnor.current();
    while (!classEnor.end())
    {
        std::cout << "Current: " << classEnor.current().sumWeight << " Best: " << bestClass.sumWeight <<std::endl;
        if (classEnor.current().sumWeight > bestClass.sumWeight)
        {
            std::cout << "New best found! " <<std::endl;
            bestClass = classEnor.current();
        }
        classEnor.next();
    }

    if (classEnor.current().sumWeight > bestClass.sumWeight)
    {
        std::cout << "New best found! " <<std::endl;
        bestClass = classEnor.current();
    }
    return true;
};

//returns false upon fileerror or empty file
bool solveSecondProblem(std::string fileName)
{
  try{
        StudentEnor studentEnor = StudentEnor(fileName);
        ClassEnor classEnor = ClassEnor(studentEnor);
        struct classResult bestClass;

        bool validInput = secondSolution(classEnor, bestClass);

        if (!validInput)
        {
            std::cerr << "Empty File" << std::endl;
            return false;
        }
        else
        {
            std::cout<< "Best Class is: " << bestClass.classId << " sumWeight: " <<  bestClass.sumWeight << std::endl;
            return true;
        }
    }
    catch(StudentEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< fileName << std::endl;
        return false;
    }
};
