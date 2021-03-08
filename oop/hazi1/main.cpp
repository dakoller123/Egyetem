//Koller Dávid Dániel - IDJJQ2
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<int>> readFile(std::string filePath)
{
    std::vector<std::vector <int>> lotteryResults;
    std::ifstream f(filePath);
    
    if(f.fail())
    {
        std::cout <<   "File open error!" << std::endl;
        throw; 
    }

    int countOfWeeks = -1; 
    
    f >> countOfWeeks;
    
    if(countOfWeeks<1)
    {
        std::cout <<  "Count of weeks is invalid" << std::endl;
        throw;
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

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main(int argc, char *argv[])
{
    if (argc > 1) 
    {
       std::string filepath(argv[1]);
       solve(readFile(filepath));
    }
    else   
    {
       std::cout << "No filepath specified!" << std::endl;
       throw;
    }   
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("empty")
{
    REQUIRE_THROWS(solve(readFile("ures.txt")));    
}

TEST_CASE("everyweek")
{
    std::vector<int> result = solve(readFile("t1.txt"));
    REQUIRE(result.size()==2); 
    REQUIRE(result[0] == 0);     
    REQUIRE(result[1] == 2);
}

TEST_CASE("no such week")
{
    std::vector<int> result = solve(readFile("t2.txt"));
    REQUIRE(result.size()==0); 
}

TEST_CASE("lots of data")
{
    std::vector<int> result = solve(readFile("t3.txt"));
    REQUIRE(result.size()==20); 
    REQUIRE(result[0] == 92);     
    REQUIRE(result[1] == 101);
    REQUIRE(result[19] == 919);
}
#endif

