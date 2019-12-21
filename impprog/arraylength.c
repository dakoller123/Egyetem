#include <stdio.h>


void f (int* p)
{
	*p = 5;
}

int main() {
	int s = 2;
	f(&s);
	printf("%d\n", s);
	return 0;
}