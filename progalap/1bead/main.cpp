#include <iostream>
#include <cstdlib>

using namespace std;

const int numberOfRaces = 5;
const int maximumNumberOfAthletes = 100;
struct inputStruct
{
	int numberOfAthletes;
	int raceResults[numberOfRaces][maximumNumberOfAthletes];
};

inputStruct readInputs()
{
	inputStruct result;
	int unusedK;
	cin >> result.numberOfAthletes >> unusedK;

	for (int i=0; i< result.numberOfAthletes; i++)
	{
		for (int j=0; j < numberOfRaces; j++)
		{
			cin >> result.raceResults[j][i];
		}
	}
	return result;
}
	

int main()
{
	inputStruct input = readInputs();
	
	//simply count the amount of nonzeros in each race (row in the matrix)
	for (int i=0; i<numberOfRaces; i++)
	{
		int amountOfAthetesWhoPlayed = 0;
		for (int j=0; j< input.numberOfAthletes; j++){
			if (input.raceResults[i][j] != 0)
			{
				amountOfAthetesWhoPlayed++;
			}
		}
		cout << amountOfAthetesWhoPlayed;
		
		//toss a space between the results if they aren't the last one
		if (i < numberOfRaces -1) 
		{
			cout << " ";
		}
	}
	return 0;
}