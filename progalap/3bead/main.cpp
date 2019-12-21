#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdio.h>
#include <limits>

using namespace std;

int findBiggestRoot(int source)
{
	if (source == 0)
	{
		return 0;
	}
	
	int result = 1;
	
	do{
		result++;
	} while (result*result <= source);
	
	return result-1;
}

int main()
{
	int input;
	cin >> input;
	// input = 72;
	int temp = input;
	// cout << findBiggestRoot(input);
	do {
		// cout << "temp: " <<temp;
		cout << findBiggestRoot(temp) << " ";
		temp = temp - findBiggestRoot(temp) * findBiggestRoot(temp);
		// cout << " temp : " << temp << endl;
	} while (temp != 0);
	cout << endl;
	
	return 0;
}

