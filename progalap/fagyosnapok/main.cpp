#include <iostream>
#include <stdio.h>
using namespace std;



int main()
{
	int n;
	int h[50];
	int db;
	
	cin >> n;	
		
	for (int i=0; i<n; i++)
	{
		cin >> h[i];
	}
	
	if (h[0] > 0)
	{
		db = 0;
	}
	else
	{
		db = 1;
	}
	
	
	for (int i=0; i<n-1; i++)
	{
		if (h[i] =< 0 && h[i+1] > 0)
		{
			db++;
		}
	}
	
	cout << db << endl;
	
	return 0;
	
}