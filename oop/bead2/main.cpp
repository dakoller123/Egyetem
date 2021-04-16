#include <iostream>
#include <iomanip>

#include "studentEnor.h"
#include "classEnor.h"

void firstSolution(std::string fileName)
{
  try{
        StudentEnor e = StudentEnor(fileName);
        e.first();

        if (e.end())
        {
            std::cout << "Empty File" << std::endl;
        }
        else
        {
            bool hardworkingStudentFound = false;
            struct student firstHardworkingStudent = e.current();
            while (!hardworkingStudentFound && !e.end())
            {
                if (e.current().sumWeight > 20.0f)
                {
                    hardworkingStudentFound = true;
                    firstHardworkingStudent = e.current();
                }
                e.next();
            }

            if (hardworkingStudentFound)
            {
                std::cout<< "First student more than 20kg of paper collected: " << firstHardworkingStudent.name << " sumWeight: " << firstHardworkingStudent.sumWeight << std::endl;
            }
            else
            {
                std::cout << "None of the students collected more than 20 kg of paper!" << std::endl;
            }

        }
    }
    catch(StudentEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< fileName << std::endl;
    }
};

void secondSolution(std::string fileName)
{
  try{
        StudentEnor studentEnor = StudentEnor(fileName);
        ClassEnor classEnor = ClassEnor(studentEnor);
        classEnor.first();

        if (classEnor.end())
        {
            std::cout << "Empty File" << std::endl;
        }
        else
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

            std::cout<< "Best Class is: " << bestClass.classId << " sumWeight: " <<  bestClass.sumWeight << std::endl;
        }
    }
    catch(StudentEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< fileName << std::endl;
    }
};

int main()
{
//    std::string fileName;
//    std::cout<<"Enter the name of the input file, please:";
//    std::cin>>fileName;
    std::string fileName = "input.txt";
    firstSolution(fileName);
    secondSolution(fileName);

    return 0;
}
