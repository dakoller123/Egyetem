//Koller Dávid Dániel - IDJJQ2
#include <iostream>
#include <fstream>
#include <vector>

#define NORMAL_MODE
#ifdef NORMAL_MODE

struct solutionStruct
{
    int countOfSmallWeeks;
    std::vector<int> weeksWithSmallNumbers;
};

std::vector<std::vector<int>> readFile(std::string filePath)
{
    std::vector<std::vector <int>> lotteryResults;
    std::ifstream f(filePath);
    
    if(f.fail())
    {
        throw  "File open error!";
    }

    int countOfWeeks; 
    
    f >> countOfWeeks;
    
    if(countOfWeeks<1)
    {
        throw  "Count of weeks is invalid";
    }
    else
    {
        std::cout << "Number of weeks in input file: " << countOfWeeks << std::endl;     
    }
    
    
    for (int i = 0; i < countOfWeeks; i++) 
    {        
        std::cout << "LotteryNumber for week nr. "<< i+1 << ": ";
        std::vector <int> resultsOfThisWeek;
        
        int previousLotteryNumber = 0;

        for (int j = 0; j < 5; j++)
        {
            int lotteryNumber;
            f >> lotteryNumber;
            
            if (lotteryNumber < 1 || lotteryNumber > 90 || lotteryNumber < previousLotteryNumber)
            {
                //std::cout << "LotteryNumber is invalid. Week: " << i+1 << " number: " << lotteryNumber << std::endl;
                throw  "LotteryNumber is invalid";
            }
            else
            {
                std::cout << ", " << lotteryNumber;
                previousLotteryNumber = lotteryNumber;
                resultsOfThisWeek.push_back(lotteryNumber); 
            }             
        }
        
        lotteryResults.push_back(resultsOfThisWeek); 
        std::cout << std::endl;
    }   
    
    return lotteryResults;
}

std::vector<int> solve(std::vector<std::vector<int>> lotteryResults)
{
    int high_lottery_number = 45;
    
   
    int countOfSmallWeeks = 0;
    std::vector<int> weeksWithSmallNumbers;
    unsigned int i = 0;
    while (i < lotteryResults.size())
    {
        if (lotteryResults[i][4] < high_lottery_number)
        {
            countOfSmallWeeks++;
            weeksWithSmallNumbers.push_back(i);            
        }
        i++;
    }
    
    std::cout << "number of weeks where all the numbers pulled where below " << high_lottery_number << ": "  << countOfSmallWeeks << std::endl;
    std::cout << "Indices of said weeks in order:";
    for (int i = 0; i < countOfSmallWeeks; i++) 
    {
        std::cout << " " << weeksWithSmallNumbers[i]+1;
    }
    
    std::cout << std::endl;
    
    return weeksWithSmallNumbers;
}

int main()
{
    solve(readFile("input.txt"));
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "bag_test.h"

TEST_CASE("empty")
{
    var x = solve(readFile("ures.txt"));
    REQUIRE(m>=0);    
}

#endif

