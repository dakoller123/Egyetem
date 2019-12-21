#include <iostream>

using namespace std;

int main()
{
	int numberOfStudents;
	cin >> numberOfStudents;
	int marks[100];
	for (int i=0; i<numberOfStudents; i++)
	{
		cin >> marks[i];
	}
	
	int resultIndex = -1;
	int resultMark;
	
	for (int i=0; i<numberOfStudents; i++)
	{
		if (marks[i] >= 3){
			if (resultIndex == -1)
			{
				resultIndex = i;
				resultMark = marks[i];
			}
			else{
				if (marks[i] < resultMark)
				{
					resultIndex = i;
					resultMark = marks[i];
				}	
			}
			
		}
	}
	
	if (resultIndex != -1)
	{
		cout << resultIndex+1 << " " << resultMark << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	
	
	return 0;
}