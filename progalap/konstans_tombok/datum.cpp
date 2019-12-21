#include <iostream>
#include <cstdlib>

using namespace std;

const string DaysInAWeek[] = {"hetfo", "kedd", "szerda", "csutortok", "pentek", "szombat", "vasarnap"};


//unused in mester
bool validateInput(int inputYear)
{
	return ((inputYear > 1901)&&(inputYear < 10000));
}

bool checkDivison(int target, int div)
{
	return ((target/div) * div == target);
}

bool isSkippingYear(int year)
{
	if (checkDivison(year, 400))
	{
		return true;
	}
	
	if (checkDivison(year, 100))
	{
		return false;
	}
	
	if (checkDivison(year, 4))
	{
		return true;
	}
	
	return false;
}

int increaseDay( int sourceDay)
{
	
	if (sourceDay == 6)
	{
		return 0;
	}
	return (sourceDay+1);
}

int main()
{
	
	
	
	int startYear = 1901;
	int startDay = 1;
	int resultDay = 1;
	int inputYear;
	
	cin >> inputYear;
	
	int currentYear = startYear+1;
	do 
	{
		resultDay = increaseDay(resultDay);
		if (isSkippingYear(currentYear-1))
		{
			resultDay = increaseDay(resultDay);
		}
		
		currentYear++;
			
	} while (currentYear < inputYear+1);

	cout << DaysInAWeek[resultDay] << endl;


	return 0;
}