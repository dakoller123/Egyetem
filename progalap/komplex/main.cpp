#include <iostream>
#include<limits>

using namespace std;

const short minCountOfCities = 1;
const short maxCountOfCities = 1000;

const short minCountOfDays = 1;
const short maxCountOfDays = 1000;

const short minSampleValue = -50;
const short maxSampleValue = 50;

const bool verboseMode = false;
const bool skipInputValidation = true;

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

void printVerbose(string text, bool endline=true)
{
	if (verboseMode)
	{
		cout << text;
		if (endline)
		{
			cout << endl;
		}
	}
}

int readNumber(int minValue, short maxValue, string repeatText = "")
{
	int number;	
	
	if (repeatText != ""){printVerbose(repeatText, false);}
	while (true)
	{
		cin >> number;
		
		if (cin.fail())
		{
			printVerbose("Failed to read number from the screen, please try again!");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			if (repeatText != ""){printVerbose(repeatText, false);}
		}
		else
		{
			if (number < minValue)
			{
				printVerbose("Error! value is too low, min. possible value: " + to_string(minValue));
				if (repeatText != ""){printVerbose(repeatText, false);}
			}
			else
			{
				if (number > maxValue)
				{
					printVerbose("Error! value is too high, max. possible value: " + to_string(maxValue));	
					if (repeatText != ""){printVerbose(repeatText, false);}					
				}
				else
				{
					break;
				}
			}
		}
	}
	
	return number;
}


inputStruct readInput()
{
	inputStruct input;
	
	printVerbose("Please Type in the number of the cities the temp. samples have been made in: ", false);
	input.countOfCities = readNumber(minCountOfCities, maxCountOfCities);

	printVerbose("Please Type in the number of the days when temp. samples have been made: ", false);
	input.countOfDays = readNumber(minCountOfDays, maxCountOfDays);
	
	for (int i=0; i<input.countOfCities; i++)
	{
		printVerbose("Now it's time to read the temperature samples for city #" + to_string(i+1));
		for (int j=0; j<input.countOfDays; j++)
		{
			if (skipInputValidation)
			{
				int number;
				cin >> number;
				input.samples[i][j] = (signed char) number;
			}
			else
			{			
				string sampleInputText =  "City #" + to_string(i+1) + " Sample #" + to_string(j+1) + ": ";
				input.samples[i][j] = (signed char)readNumber(minSampleValue, maxSampleValue, sampleInputText);
			}
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

outputStruct getCitiesWithMaxTemp(inputStruct inputData, short maxTempValue)
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
	printVerbose("The number of cities with the highest temperatures measured: ", false);
	cout << outputData.maxTempCitiesCount;
	if (verboseMode){cout << endl;}
	
	printVerbose("The list of the cities:", false);
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