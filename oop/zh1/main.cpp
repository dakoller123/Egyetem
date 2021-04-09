#include <iostream>
#include "adoptionEnor.h"
#include "adoptionDayEnor.h"

int main()
{
    std::string filename;
    std::cout<<"Enter the name of the input file, please:";
    std::cin>>filename;

    //std::string filename = "input.txt";

    try{
        AdoptionDayEnor adoptionDayEnor = AdoptionDayEnor(filename);

        adoptionDayEnor.first();

        if (adoptionDayEnor.end())
        {
            std::cout << "Empty File" << std::endl;
        }
        else
        {
            bool foundSolution = false;
            while (!adoptionDayEnor.end() && !foundSolution)
            {
                bool everyLabradorIsOld = true;
                AdoptionEnor* adoptions = adoptionDayEnor.current().adoptions;
                adoptions->first();
                while (everyLabradorIsOld && (!adoptions->end()))
                {
                    std::cout << adoptions->current().dogName << std::endl;
                    if (adoptions->current().dogType == "labrador")
                    {
                        everyLabradorIsOld = (adoptions->current().dogAge >= 2);
                    }

                    adoptions->next();
                }

                if (everyLabradorIsOld)
                {
                    foundSolution = true;
                }
                else
                {
                    adoptionDayEnor.next();
                }

            }

            if (foundSolution)
            {
                std::cout<< "A day when every labrador adopted was at least 2 years old: " << adoptionDayEnor.current().date << std::endl;
            }
            else
            {
                std::cout<< "There wasn't any day when every labrador adopted that day were at least 2 years old" << std::endl;
            }
        }
    }
    catch(AdoptionDayEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< filename << std::endl;
    }

    return 0;
}
