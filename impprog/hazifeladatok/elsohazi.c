//Vegy�k a [-20,120] intervallumot, 10-es l�p�sk�zzel menj�nk v�gig ezeken az �rt�keken, majd �rjuk ki �ket, mint Fahrenheit �s ennek a h�m�rs�kletnek megfelel� Celsius �rt�ket is.

#include <stdio.h>

/*

Takes in the temperature in fahrenheit and returns the same temperature in Celsius
*/
float fahrenDegreeInCelcius(float fahrenDegree){
    return (fahrenDegree-32.0) * 5 / 9;
}

/*
Prints out temps between -20 and 120 fahrenheit in both fahrenheit and celcius, with a 10FH increment.
*/
int main()
{
    float fahrenDegree;
    for (fahrenDegree = -20; fahrenDegree <= 120; fahrenDegree=fahrenDegree+10)
    {
        printf("%f Fahrenheit %f Celsius \n", fahrenDegree, fahrenDegreeInCelcius(fahrenDegree));
    }
    return 0;


}

