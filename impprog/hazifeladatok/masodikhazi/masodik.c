#include <stdio.h>
#include <math.h>
int orderOfMaginute (int source){
	int result = 0;
	int divisionValue;
	int orderOfTen;
	do {
		result = result +1;
		orderOfTen = pow (10, result);
		divisionValue = source /  orderOfTen;
		printf("result: %d divValue : %d 10^result: %d \n", result, divisionValue, orderOfTen);
	} while ( divisionValue != 0);
	
	return result -1;
}

// Todo: rewrite to use for cycle only ints, no casting
int intPow(int x, int y){
	return (int)(pow (x, y) + 0.5);
}

// int intPowSecond(int x, int y){
	// int i;
	// if (x == 0){return 0}
	// if (y == 0){return 1}
	// int result = 1;
	// for (i = 1; i<=y; i++){
		// result = result * x;
	// }
	// return result;
// }

int reverseNumber (int source, int magnitudeOfSource){
	int trunkatedOriginal = source;
	int i;
	int result = 0;
	int modResult;
	int powerOfI;
	int partial;
	for (i=magnitudeOfSource; i>=0; i--){
		powerOfI = intPow(10, i);
		modResult = trunkatedOriginal / powerOfI;
		trunkatedOriginal = trunkatedOriginal - modResult * powerOfI;
		partial = modResult * (intPow (10, magnitudeOfSource - i));
		result = result + partial;
		printf("i:%d result:%d magnit:%d, mod:%d powerOfI: %d partial : %d trunkatedOriginal:%d\n " , i, result , magnitudeOfSource, modResult, powerOfI, partial, trunkatedOriginal);
	}
	return result;
}

int main()
{
	int originalNumber;
	int orderOfOriginal;
	int reverse;
	
	printf("Please enter the number: ");
	scanf("%d", &originalNumber); 
    printf("Input value read : a = %d\n", originalNumber); 
	
	if (originalNumber < 10){
		reverse = originalNumber;
		printf("The reverse is: %d \n", reverse);
		return 0;
	}
	orderOfOriginal = orderOfMaginute(originalNumber);
	printf("orderOfOriginal :  %d \n", orderOfOriginal);
	
	reverse = reverseNumber(originalNumber, orderOfOriginal);
	printf("reverse :  %d \n", reverse);
	return 0;
}