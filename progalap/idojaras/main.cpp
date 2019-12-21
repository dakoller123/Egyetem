#include <iostream>
#include <cstdlib>

using namespace std;

//this is a really ugly constanst
//Todo: use vectors or similar stacks instead of fixed-size arrays
const int maxNumberOfSamples = 200;

struct Sample
{
	int min;
	int max;
};

struct inputStruct 
{ 
	int numOfSamples; 
	Sample samples[maxNumberOfSamples]; 
};

struct taskFourStruct
{
	int numberOfMeltingAndFreezingDays;
	
	//store them as array indexes, starting from 0
	int indexes[maxNumberOfSamples];
};


inputStruct readInputs()
{
	inputStruct result;
	cin >> result.numOfSamples;
	for (int i=0; i< result.numOfSamples; i++)
	{
		cin >> result.samples[i].min >> result.samples[i].max;
	}
	return result;
}

int taskOne(inputStruct input)
{
	int numberOfColdDays = 0;
	
	for (int i=0; i<input.numOfSamples; i++)
	{
		if (input.samples[i].min <= 0)
		{
			numberOfColdDays = numberOfColdDays + 1;
		}
	}
	
	return numberOfColdDays;
}

int calculateDifferenceBetweenSamples(Sample sample)
{
	return sample.max-sample.min;
}

int taskTwo(inputStruct input){
	
	int indexOfFirstMaxDifference = 0;
	int currentMaxDifference = calculateDifferenceBetweenSamples(input.samples[0]);
	for (int i=1; i<input.numOfSamples; i++)
	{
		int diffThatIsChecked = calculateDifferenceBetweenSamples(input.samples[i]);
		if (diffThatIsChecked > currentMaxDifference)
		{
			currentMaxDifference = diffThatIsChecked;
			indexOfFirstMaxDifference = i;
		}
	}
	return indexOfFirstMaxDifference+1;
}

int taskThree(inputStruct input){
	// a simple validation, unnecessary for Biro
	if (input.numOfSamples < 2) 
	{
		return -1;
	}
	
	for (int i=1; i<input.numOfSamples; i++)
	{
		if (input.samples[i].max < input.samples[i-1].min)
		{	
			return i+1;
		}
	}
	return -1;
}

bool checkBothFreezingAndMelting(Sample sample)
{
	return (sample.min <=0 && sample.max > 0);
}

taskFourStruct taskFour(inputStruct input)
{
	taskFourStruct result;
	result.numberOfMeltingAndFreezingDays = 0;
	for (int i=0; i<input.numOfSamples; i++)
	{
		if (checkBothFreezingAndMelting(input.samples[i]))
		{
			result.indexes[result.numberOfMeltingAndFreezingDays] = i;
			result.numberOfMeltingAndFreezingDays++;
		}
	}
	return result;
}

void printOutTaskFourResult (taskFourStruct result)
{
	cout << result.numberOfMeltingAndFreezingDays;
	if (result.numberOfMeltingAndFreezingDays != 0)
	{
		cout << " ";
		for (int i = 0; i<result.numberOfMeltingAndFreezingDays; i++)
		{
			//indexes are stored as array indexes, need to add 1 to them
			cout << result.indexes[i]+1;
			if (i<result.numberOfMeltingAndFreezingDays-1)
			{
				cout << " ";
			}
		}		
	}
	cout << endl;
}

int main()
{
	inputStruct input = readInputs();
	cout << "#" << endl;
	cout << taskOne(input) << endl;
	cout << "#" << endl;
	cout << taskTwo(input) << endl;
	cout << "#" << endl;
	cout << taskThree(input) << endl;
	cout << "#" << endl;
	printOutTaskFourResult(taskFour(input));
}