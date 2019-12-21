#include <stdio.h>
#include <string.h>

int main() {
	int i;
	int length;
	char name[] = "abcdef";
	length = strlen(name);
	char mirror[length];
	char c;
	for (i = 0; i < length / 2; i++)
	{
		c = name[i];
		name [i] = name [ length -1 -i ];
		name[length -1 -i ] = c;
	}
	
	printf("%s\n", name);
	
	printf("\n");
	return 0;
}