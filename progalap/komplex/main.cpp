#include <iostream>

using namespace std;

const int maxCountOfCities = 1000;
const int maxCountOfDays = 1000;
const bool verboseMode = false;

struct inputStruct
{
	int countOfCities;
	int countOfDays;
	signed char samples[maxCountOfCities][maxCountOfDays];
};

struct outputStruct
{
	int maxTempCitiesCount;
	int maxTempCities[maxCountOfCities];
};

void printVerbose(string text)
{
	if (verboseMode){ cout << text << endl;}
}

void printVerbose(int text)
{
	if (verboseMode){ cout << text << endl;}
}


inputStruct readInput()
{
	inputStruct input;
	printVerbose("Please Type in the number of the cities the temp. samples have been made in:");
	cin >> input.countOfCities;

	printVerbose("Please Type in the number of the days when temp. samples have been made:");
	cin >> input.countOfDays;
	
	for (int i=0; i<input.countOfCities; i++)
	{
		printVerbose("Now it's time to read the " + i );
		for (int j=0; j<input.countOfDays; j++)
		{
			int number;
			cin >> number;
			input.samples[i][j] = (char)number;
		}
	}
	return input;
}

int getMaxTemp(inputStruct inputData)
{
	int maxTempValue;
	for (int i=0; i<inputData.countOfCities; i++)
	{
		for (int j=0; j<inputData.countOfDays; j++)
		{
			if (i==0&&j==0)
			{
				maxTempValue = inputData.samples[0][0];
			}
			
			if (inputData.samples[i][j] > maxTempValue)
			{
				maxTempValue = inputData.samples[i][j];
			} 
			
		}
	}
	
	return maxTempValue;
}

outputStruct getCitiesWithMaxTemp(inputStruct inputData, int maxTempValue)
{
	outputStruct result;
	result.maxTempCitiesCount = 0;
	//calculate how many cities there are which contain the maxtemp
	for (int i=0; i<inputData.countOfCities; i++)
	{
		bool cityIsInMax = false;
		
		int j= 0;
		while(j<inputData.countOfDays && cityIsInMax==false)
		{
			if (inputData.samples[i][j] == maxTempValue)
			{
				cityIsInMax = true;
			}
			else{
				j++;
			}
		}
		
		if (cityIsInMax)
		{
			result.maxTempCities[result.maxTempCitiesCount] = i;
			result.maxTempCitiesCount++;
		}
	}
	
	return result;
}

void printOutput(outputStruct outputData)
{
	cout << outputData.maxTempCitiesCount;
	for (int i=0; i<outputData.maxTempCitiesCount; i++)
	{
		cout << " " << outputData.maxTempCities[i]+1;
	}
	cout << endl;	
}

int main()
{	
	inputStruct inputData = readInput();	
	int maxTempValue = getMaxTemp(inputData);
	outputStruct outputData = getCitiesWithMaxTemp(inputData, maxTempValue);
	printOutput(outputData);
		
	return 0;
}