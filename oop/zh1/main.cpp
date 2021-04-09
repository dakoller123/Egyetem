#include <iostream>
#include "baseEnor.h"
#include "secondEnor.h"

int firstTask(BaseEnor& e)
{
    return 0;
}

int secondTask(SecondEnor& e)
{
    return 0;
}


int main()
{
    std::string filename;
    std::cout<<"Enter the name of the input file, please:";
    std::cin>>filename;

    try{
        BaseEnor e = BaseEnor(filename);
        std::cout<< "Result for the first task is:" << firstTask(e) << std::endl;

        SecondEnor se = SecondEnor(filename);
        std::cout<< "Result for the second task is:" << secondTask(se) << std::endl;

//
//        if (e.end())
//        {
//            std::cout << "Empty File" << std::endl;
//        }
//        else
//        {
//            struct student bestStudent = e.current();
//            while (!e.end())
//            {
//                if (e.current().sumWeight > bestStudent.sumWeight)
//                {
//                    bestStudent = e.current();
//                }
//                e.next();
//            }
//
//             std::cout<< "Best Student is: " << bestStudent.name << "sumWeight: " << bestStudent.sumWeight << std::endl;
//        }
    }
    catch(BaseEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< filename << std::endl;
    }

    return 0;
}
