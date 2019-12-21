#include <string>
#include <iostream>
using namespace std;

int powInt(int base, int exponent)
{
	if (exponent == 1)
	{
		return base;
	}
	return (powInt(base, exponent-1)) * base;
}

int str2int0(string input)
{
	int result = 0;
	for (int i=input.length()-1; i>1; i--)
	{
		int charTurnedToInt = input[i]-48;
		cout << "result : " << result << " i: " << i << " charTurnedToInt : " << charTurnedToInt << endl;
		result += (charTurnedToInt-48)*powInt(10, i);
	}
	
	return result;
}

int main()
{
	string testOne = "1313";
	int resultOne = str2int0(testOne);
	cout << resultOne;
	
	cout << powInt(10, 2);
	return 0;
}