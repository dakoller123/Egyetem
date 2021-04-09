#include <iostream>
#include "studentEnor.h"

int main()
{
    std::string filename;
    std::cout<<"Enter the name of the input file, please:";
    std::cin>>filename;

    try{
        StudentEnor e = StudentEnor(filename);
        e.first();

        if (e.end())
        {
            std::cout << "Empty File" << std::endl;
        }
        else
        {
            struct student bestStudent = e.current();
            while (!e.end())
            {
                if (e.current().sumWeight > bestStudent.sumWeight)
                {
                    bestStudent = e.current();
                }
                e.next();
            }

             std::cout<< "Best Student is: " << bestStudent.name << "sumWeight: " << bestStudent.sumWeight << std::endl;
        }
    }
    catch(StudentEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< filename << std::endl;
    }

    return 0;
}
