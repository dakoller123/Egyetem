#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdio.h>
#include <limits>

using namespace std;


const int maxLengthOfEventName = 100;
const int maxCountOfEvents = 100;
const int maxCountOfCategories = 10;
const int maxLengthOfCategoryName = 100;

struct eventStruct
{
	int year;
	int category;
	string eventName;
};

struct inputStruct
{
	int countOfEvents;
	int countOfCategories;
	eventStruct events[maxCountOfEvents];
	string categories[maxCountOfCategories];
};

inputStruct readInput()
{

	inputStruct result;

	cin >> result.countOfEvents;
	cin >> result.countOfCategories;

	for (int i=0; i<result.countOfEvents; i++)
	{
		cin >> result.events[i].year;
		cin >> result.events[i].category;
		// cout << result.events[i].category;
		result.events[i].category--;
		// cout << " " << result.events[i].category << endl;
		
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin,result.events[i].eventName);
		// cout <<result.events[i].year<< " " << result.events[i].category << " " << result.events[i].eventName << endl;
	}
	
	int start, end;
	// cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin >> start >> end;
	// cout << "start: " << start << " end: " <<end <<endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int j=0; j<result.countOfCategories; j++)
	{

		getline(cin,result.categories[j]);
		// cout << j << " : " <<result.categories[j] << endl;
	}

	return result;
}


int main()
{
	inputStruct input = readInput();
	int categoriesUsageMatrix[input.countOfCategories];
	for (int i=0; i<input.countOfCategories; i++)
	{
		categoriesUsageMatrix[i] = 0;
	}

	int countOfUnusedCategories = 0;

	for (int i=0; i<input.countOfEvents; i++)
	{
		categoriesUsageMatrix[input.events[i].category]++;
	}


	for (int i=0; i<input.countOfCategories; i++)
	{
		if (categoriesUsageMatrix[i] == 0)
		{
			countOfUnusedCategories++;
		}
	}

	cout << countOfUnusedCategories;

	for (int i=0; i<input.countOfCategories; i++)
	{
		if (categoriesUsageMatrix[i] == 0)
		{
			
			 cout << " " << input.categories[i];
		}
	}

	cout << endl;
	return 0;
}

