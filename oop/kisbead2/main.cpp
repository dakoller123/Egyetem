#include <iostream>
#include "countEnor.h"

int main()
{
    std::string filename;
    std::cout<<"Enter the name of the input file, please:";
    std::cin>>filename;

    try{
        CountEnor e = CountEnor(filename);
        e.first();

        if (e.end())
        {
            std::cout << "Empty File" << std::endl;
        }
        else
        {
            int mostCommonValue = 0;
            int mostCommonCount = 0;
            int currentValue = 0;

            while (!e.end())
            {
                if (e.current().Count > mostCommonCount)
                {
                    mostCommonCount = e.current().Count;
                    mostCommonValue = e.current().Value;
                }
                e.next();
            }

             std::cout<< "Most common number in the list: " << mostCommonValue << " Count: " << mostCommonCount << std::endl;
        }
    }
    catch(NumberEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< filename << std::endl;
    }

    return 0;
}
