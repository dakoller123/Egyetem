#include <iostream>
#include <cstdlib>

using namespace std;


struct inputStruct
{
	int n;
	int b[10000];
};

inputStruct readInput()
{
	inputStruct result;
	cin >> result.n;
	
	for (int i=0; i<result.n; i++)
	{
		cin >> result.b[i];
	}
	
	return result;
}

int main()
{
	inputStruct input = readInput();
	
	
	if (input.n == 1)
	{
		if (input.b[0] == 0)
		{
			cout << "1";
			return 0;
		}
		else
		{
			cout << "0";
			return 0;
		}
	}
	
	int result = 1;
	for (int i=1; i<input.n; i++)
	{
		if (input.b[i] != input.b[i-1])
		{
			result++;
		}
	}
	
	cout << result;
	
	return 0;
}