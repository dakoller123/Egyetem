#include <iostream>
#include "temperatureEnor.h"

float getAverageBeforeNegative(TemperatureEnor& e)
{
    float sumBeforeNegative = 0;
    int countBeforeNegative = 0;

    e.first();
    while (!e.end() && e.current() >= 0)
    {
        sumBeforeNegative += e.current();
        countBeforeNegative++;
        e.next();
    }

    return (sumBeforeNegative/countBeforeNegative);
}

float getAverageAfterNegative(TemperatureEnor& e)
{
    float sumAfterNegative = 0.0;
    int countAfterNegative = 0;
    while (!e.end())
    {
        sumAfterNegative += e.current();
        countAfterNegative++;
        e.next();
    }

    return (sumAfterNegative/countAfterNegative);
}

int main()
{
    std::string filename;
    std::cout<<"Enter the name of the input file, please:";
    std::cin>>filename;

    try{
        TemperatureEnor e = TemperatureEnor(filename);
        std::cout<< "Average of temps before first negative value: " << getAverageBeforeNegative(e) << std::endl;
        std::cout<< "Average of temps after first negative value: " << getAverageAfterNegative(e) << std::endl;
    }
    catch(TemperatureEnor::FileError err)
    {
        std::cerr<<"Can't find the input file:"<< filename << std::endl;
    }

    return 0;
}
