#include <iostream>
#include <cstdlib>

using namespace std;


struct inputStruct
{
	int sizeOfNumbers;
	int endIndex;
	int numbers[100];
};

inputStruct readInput()
{
	inputStruct result;
	cin >> result.sizeOfNumbers;
	cin >> result.endIndex;
	for (int i=0; i<result.sizeOfNumbers; i++)
	{
		cin >> result.numbers[i];
	}
	
	return result;
}

bool isThereASimilarNumber(inputStruct input, int indexOfNumberThatIsChecked)
{
		
	if (indexOfNumberThatIsChecked == input.sizeOfNumbers-1)
	{
		return false;
	}
	
	if (indexOfNumberThatIsChecked + input.endIndex >= input.sizeOfNumbers)
	{
		return false;
	}
	
	int checkedValue = input.numbers[indexOfNumberThatIsChecked];
	
	for (int i=indexOfNumberThatIsChecked+1; i<input.endIndex+indexOfNumberThatIsChecked+1; i++)
	{
		if (checkedValue == input.numbers[i])
		{
			return true;
		}
	}
	
	return false;
}	

int main()
{
	inputStruct input = readInput();

	int result = 0;
	
	for (int i=0; i<input.sizeOfNumbers; i++)
	{
		if (isThereASimilarNumber(input, i))
		{
			result++;
		}
	}
	
	cout << result;
	
	return 0;
}