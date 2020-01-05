/*   
    Szerzo: Koller David Daniel 
	Neptun: IDJJQ2   
	E-mail: david.daniel.koller@gmail.com
	Feladat: "Legmelegebb telepulesek"
*/ 

#include <iostream>
#include<limits>

using namespace std;

/*
------------------ Config params ------------------
*/

//These define the possible min and max values for each input parameters
const short minCountOfCities = 1;
const short maxCountOfCities = 1000;
const short minCountOfDays = 1;
const short maxCountOfDays = 1000;
const short minSampleValue = -50;
const short maxSampleValue = 50;

//If this is enabled, requests and responses towards the user are printed out
const bool verboseMode = false;

//If this is enabled, input validation is mostly skipped. Shortens runtime.
const bool skipInputValidation = true;

/*
------------------ End of config params ---------------
*/


//structure that holds together everything the user will provide
struct inputStruct
{
	short countOfCities;
	short countOfDays;
	signed char samples[maxCountOfCities][maxCountOfDays];
};

//structure that holds together everything that will be printed out as the solution
struct outputStruct
{
	short maxTempCitiesCount;
	short maxTempCities[maxCountOfCities];
};

//simple function that uses the verboseMode global variable to decided whether to print or not
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

//reads a number from console, does simple validation, unless overwritten by the skipInputValidation global parameter
short readNumber(short minValue, short maxValue, string repeatText = "")
{
	short number;

	//skips the entire function and just acts as a wrapper for cin
	if (skipInputValidation)
	{
		cin >> number;
		return number;
	}
	
	if (repeatText != ""){printVerbose(repeatText, false);}
	while (true)
	{
		cin >> number;
		
		if (cin.fail())
		{
			printVerbose("Error! Input is not an integer!");
			cin.clear();
			
			//purge the cin buffer
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

//the method that grabs all the required data from the user and puts them into one record
inputStruct readInput()
{
	inputStruct input;
	
	printVerbose("Please Type in the number of the cities the temp. samples have been made in: ", false);
	input.countOfCities = readNumber(minCountOfCities, maxCountOfCities);

	printVerbose("Please Type in the number of the days when temp. samples have been made: ", false);
	input.countOfDays = readNumber(minCountOfDays, maxCountOfDays);
	
	for (short i=0; i<input.countOfCities; i++)
	{
		printVerbose("Now it's time to read the temperature samples for city #" + to_string(i+1));
		for (short j=0; j<input.countOfDays; j++)
		{
			string sampleInputText = "";
			if (verboseMode)
			{
				//Note: calculation is performance heavy due to lot of casting, hence the check for verboseMode, where its only ever used
				sampleInputText=  "City #" + to_string(i+1) + " Sample #" + to_string(j+1) + ": ";
			}
			
			input.samples[i][j] = (signed char)readNumber(minSampleValue, maxSampleValue, sampleInputText);
		}
	}
	return input;
}

//enumerates across every temperature sample and outputs the highest value seen
short getMaxTemp(inputStruct inputData)
{
	short maxTempValue;
	for (short i=0; i<inputData.countOfCities; i++)
	{
		for (short j=0; j<inputData.countOfDays; j++)
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

//counts the cities where the max temp has been measured and also stores their indexes
outputStruct getCitiesWithMaxTemp(inputStruct inputData, short maxTempValue)
{
	outputStruct result;
	result.maxTempCitiesCount = 0;
	//calculate how many cities there are which contain the maxtemp
	for (short i=0; i<inputData.countOfCities; i++)
	{
		bool cityIsInMax = false;
		
		short j= 0;
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

//prints the solution to the output, with some verbose text if verboseMode global var is set that way
void printOutput(outputStruct outputData)
{
	printVerbose("The number of cities with the highest temperatures measured: ", false);
	cout << outputData.maxTempCitiesCount;
	if (verboseMode){cout << endl;}
	
	printVerbose("The list of the cities:", false);
	
	for (short i=0; i<outputData.maxTempCitiesCount; i++)
	{
		cout << " " << outputData.maxTempCities[i]+1;
	}
	
	cout << endl;	
}

//main method grabs the input, calculated the max. temperature value that has been measured
// then solves and prints out the solution
int main()
{	
	inputStruct inputData = readInput();	
	short maxTempValue = getMaxTemp(inputData);
	outputStruct outputData = getCitiesWithMaxTemp(inputData, maxTempValue);
	printOutput(outputData);
		
	return 0;
}