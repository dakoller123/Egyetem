#include <iostream>
#include <iomanip>

#include "studentEnor.h"
#include "classEnor.h"

bool firstSolution(StudentEnor& e, struct student& firstHardworkingStudent)
{
    bool hardworkingStudentFound = false;
    firstHardworkingStudent = e.current();
    while (!hardworkingStudentFound && !e.end())
    {
        if (e.current().sumWeight > 20.0f)
        {
            hardworkingStudentFound = true;
            firstHardworkingStudent = e.current();
        }
        e.next();
    }

    return hardworkingStudentFound;
};


bool solveFirstProblem(std::string fileName)
{
  try{
        StudentEnor e = StudentEnor(fileName);
        e.first();

        if (e.end())
        {
            std::cerr << "Empty File" << std::endl;
            return false;
        }
        else
        {
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
    }
    catch(StudentEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< fileName << std::endl;
        return false;
    }
};

struct classResult secondSolution(ClassEnor& classEnor)
{
    struct classResult bestClass = classEnor.current();
    while (!classEnor.end())
    {
        if (classEnor.current().sumWeight > bestClass.sumWeight)
        {
            bestClass = classEnor.current();
        }
        classEnor.next();
    }
    return bestClass;
};

bool solveSecondProblem(std::string fileName)
{
  try{
        StudentEnor studentEnor = StudentEnor(fileName);
        ClassEnor classEnor = ClassEnor(studentEnor);
        classEnor.first();

        if (classEnor.isEmpty())
        {
            std::cerr << "Empty File" << std::endl;
            return false;
        }
        else
        {
            struct classResult bestClass = secondSolution(classEnor);
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
