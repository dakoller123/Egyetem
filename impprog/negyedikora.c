#include <stdio.h>


//this is the function that was asked to be implemented
double min(double elso, double masodik)
{
	if (masodik > elso)
	{
		return elso;
	}
	else
	{
		return masodik;
	}
}

int main() 
{
	//just to test the function out
	printf("%f", min(6.0, 6.0));
	return 0;
}