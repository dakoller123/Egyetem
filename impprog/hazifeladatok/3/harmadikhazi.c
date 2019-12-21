#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
int main()
{
	char fullName[] = "Koller Daniel";
	int fullNameLength = strlen(fullName);
	char firstName[fullNameLength];
	char lastName[fullNameLength];
	int firstNameLength = 0;
	int lastNameLength = 0; 
	bool spaceFound = false;
	for (int i=0; i<fullNameLength; i++)
	{
		if (spaceFound)
		{
			lastName[i-firstNameLength-1] = fullName[i];
			lastNameLength++;
		}
		else
		{
			if (fullName[i] == ' ')
			{
				spaceFound = true;
			}	
			else
			{
				firstName[i] = fullName[i];
				firstNameLength++;
			}
		}
	}
	
	
	if (firstNameLength == lastNameLength)
	{
		for (int k=0; k<firstNameLength; k++)
		{
			printf("%c", firstName[k]);
		}
		printf(" ");
		for (int l=0; l<lastNameLength; l++)
		{
			printf("%c", lastName[l]);
		}		
	}
	else
	{
		if (firstNameLength > lastNameLength)
		{
			for (int k=0; k<firstNameLength; k++)
			{
				printf("%c", firstName[k]);
			}		
		}
		else
		{
			for (int l=0; l<lastNameLength; l++)
			{
				printf("%c", lastName[l]);
			}				
		}
	}
	

	return 0;
}