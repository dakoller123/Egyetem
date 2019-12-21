// Egy vállalat tárolja dolgozói életkorát és fizetését. Írj programot, amely megadja
// a) a legidősebb dolgozó sorszámát (ha több megoldás van, akkor közülük a
// legkisebb sorszámút); 1
// b) a 40 év felettiek közül hánynak van 200.000 forintnál kisebb fizetése; 2
// c) hányféle életkorú ember van; 3
// d) a 30 évnél fiatalabbak számát és sorszámait (a sorszámokat növekvő
// sorrendben) egy-egy szóközzel elválasztva! 1+3
// A standard bemenet első sorában az emberek száma, alatta soronként egy-egy ember kora és a
// fizetése (egész számok). A standard kimenetre kell kiírni a fenti kérdésekre, feladatokra adott
// válaszokat. 


#include <iostream>
#include <cstdlib>

using namespace std;

//this is a really ugly constanst
//Todo: use vectors or similar stacks instead of fixed-size arrays
const int maxCompanySize = 200;

struct CompanyMember
{
	int age;
	long income;
};

struct inputStruct 
{ 
	int companySize; 
	CompanyMember members[maxCompanySize]; 
};

struct taskDStruct
{
	int youngMemberCount;
	int indexes[maxCompanySize];
};

inputStruct readInputs()
{
	inputStruct result;
	cin >> result.companySize;
	for (int i=0; i< result.companySize; i++)
	{
		cin >> result.members[i].age >> result.members[i].income;
	}
	return result;
}

int taskA (inputStruct input)
{
	int indexOfOldestMember = 0;
	
	for (int i=1; i<input.companySize; i++)
	{
		if (input.members[i].age > input.members[indexOfOldestMember].age)
		{
			indexOfOldestMember = i;
		}
	}
	
	return indexOfOldestMember+1;
}

int taskB (inputStruct input, int minAge, long maxIncome)
{
	int amountOfPoorOldMembers = 0;
	
	for (int i=0; i<input.companySize; i++)
	{
		if ((input.members[i].age >  minAge) && (input.members[i].income <  maxIncome))
		{
			amountOfPoorOldMembers++;
		}
	}
	
	return amountOfPoorOldMembers;
}

int taskC (inputStruct input)
{
	if (input.companySize == 0)
	{
		return 0;
	}
	int result	= 0;
	
	for (int i=0; i<input.companySize; i++)
	{
		bool isRepeating = false;
		for (int j=0; j<i; j++)
		{
			if (input.members[i].age == input.members[j].age)
			{
				isRepeating = true;
				break;
			}
		}
		
		if (isRepeating == false)
		{
			result++;		
		}
	}	
	
	return result;
	
}

taskDStruct taskD(inputStruct input, int maxAge)
{
	taskDStruct result;
	result.youngMemberCount = 0;
	
	if (input.companySize == 0)
	{
		return result;
	}
	
	for (int i=0; i< input.companySize; i++)
	{
		if (input.members[i].age < maxAge)
		{
			result.indexes[result.youngMemberCount] = i;
			result.youngMemberCount++;
		}
	}
	
	return result;
}

void printTaskDResult (taskDStruct result)
{
	if (result.youngMemberCount == 0)
	{
		cout << result.youngMemberCount;	
	}
	else if (result.youngMemberCount == 1)
	{
		cout << result.youngMemberCount << " " << result.indexes[0];	
	}
	else
	{
		cout << result.youngMemberCount;
		
		for (int i=0; i<result.youngMemberCount; i++)
		{
			cout << " " <<result.indexes[i]+1;
		}
	}
	cout << endl;
}

int main()
{
	inputStruct input = readInputs();
	cout << taskA(input) << endl;
	cout << taskB(input, 40, 200000L) << endl;
	cout << taskC(input) << endl;
	printTaskDResult(taskD(input, 30));
}