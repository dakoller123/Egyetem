#include <iostream>

using namespace std;

int main()
{
	int countOfCities;
	int countOfDays;
	int *samples[1000];
	
	int maxTempValue;
	int maxTempCities[10];
	int maxTempCitiesCount = 0;
	
	cin >> countOfCities >> countOfDays;

	//allocate memory for the samples
	for (int i=0; i<countOfCities; i++)
	{
		samples[i]=new int[1000];	
	}
	
	//read the samples and get the max temp value
	for (int i=0; i<countOfCities; i++)
	{
		for (int j=0; j<countOfDays; j++)
		{
			cin >> samples[i][j];
			
			if (i==0&&j==0)
			{
				maxTempValue = samples[i][j];
			}
			
			if (samples[i][j] > maxTempValue)
			{
				maxTempValue = samples[i][j];
			} 
			
		}
	}
	
	//calculate how many cities there are which contain the maxtemp
	for (int i=0; i<countOfCities; i++)
	{
		bool cityIsInMax = false;
		
		int j= 0;
		while(j<countOfDays && cityIsInMax==false)
		{
			if (samples[i][j] == maxTempValue)
			{
				cityIsInMax = true;
			}
			else{
				j++;
			}
		}
		
		if (cityIsInMax)
		{
			maxTempCities[maxTempCitiesCount] = i;
			maxTempCitiesCount++;
		}
	}
	
	cout << maxTempCitiesCount;
	for (int i=0; i<maxTempCitiesCount; i++)
	{
		cout << " " << maxTempCities[i]+1;
	}
	cout << endl;
	
	for (int i=0; i<countOfCities; i++)
	{
		delete[] samples[i];
	}
	
	return 0;
}