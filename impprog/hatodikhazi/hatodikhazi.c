#include <string.h>
#include <stdio.h>
void s( char* p )
{
  int i = 0;
  int len = strlen( p );
  for( ; i < len; ++i )
  {
    p[ i ] = 'a' + i;
  }
}

int acc( int* a, int s )
{
  int ret = 0;
  int i = 0;
  for( ; i < s; ++i )
  {
    ret += a[ i ];
  }
  return ret;
}


int main()
{
	char arrayOne[] = "1\0";
	int arrayTwo[] = {1,2,3};
	int arrayTwoLength = sizeof(arrayTwo) / sizeof(arrayTwo[0]);
	int resultOfAcc;
	
	s(arrayOne);
	
	resultOfAcc = acc(arrayTwo, arrayTwoLength);
	printf("s has been altereted and it is now:  %s \n", s);
	printf("result of Acc function call, %d", resultOfAcc);
	return 0;
}