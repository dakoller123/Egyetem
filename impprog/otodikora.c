#include <stdio.h>
#include <string.h>	


double max(double *p, int n)
{
	double ret = p [0];
	
	for (int i= 1; i<n; i++)
	{
		if (p[i] > ret)
		{
			ret = p[i];
		}		 
	}
	
	return ret;
}

int countWord(char *sentence)
{	
	int sentenceLength = strlen (sentence);
	int countedWords = 0;
	if (sentenceLength == 0)
	{
		return 0;
	}
	if (sentenceLength < 3)
	{
		return 1;
	}

	for (int i=1; i<sentenceLength-1; i++)
	{
		if (sentence[i] == ' ')
		{
			countedWords++;
		}
	}
}

void fun(int x)
{
	x = 30;
}


int main() 
{
	// char example[] = "En a kis tehen";
	// char secondExample[] = "labamat logatom en, en a kis tehen";;
	
	// printf("%d ", countWord(example));
	// printf("%d", countWord(secondExample));
	
	int x = 20;
	
	fun (x);
	
	printf("%d", x);

	funtwo(&x);
	
	printf("%d", &x);
	
	return 0;
}