#include <iostream>
#include <stdio.h>
using namespace std;



int main()
{
	int n = 0;
	int est[1000];
	int b[1000];
	int reggel;
	int db = 0;
	int atlag = 0;
	
	cin >> n;
	
	if (n > 1000 || n < 1)
	{
		return 1;
	}
	
	for (int i=0; i<n; i++)
	{
		cin >> reggel >> est[i];
	}
	

	for (int i=0; i<n; i++)
	{
		atlag = atlag + est[i];
	}
	
	atlag = atlag / n;
	
	for (int i=0; i<n; i++)
	{
		if (est[i] > atlag)
		{			
			b[db] = i;
			db++;
		}
	}
	
	cout << db;
	
	for (int i=0; i<db; i++)
	{
		cout << " " << b[i]+1;
	}
	
	cout << endl;
	
	
	
	return 0;
	
}