#include <stdio.h>

// segédfüggvény, visszaadja hogy egy szám hányszor szerepel egy tömbben
// megszámlálás tétele van alkalmazva
int gyakorisagszamlalo(int elem, int tomb[], int hossz)
{
	int db = 0;
	for (int i=0; i<hossz; i++)
	{
		if (tomb[i] == elem)
		{
			db++;
		}
	}
	
	return db;
}

// megvizsgálja, melyik (az első) olyan szám ami a legtöbbször szerepel
// maximum ÉRTÉK kiválasztásának tétele
int mostCommon(int tomb[], int hossz)
{

	int maxertek = tomb[0];
	for (int i=1; i < hossz; i++)
	{
		// itt van a rendezés ami alapján a maximum kiválasztás működik
		// normál esetben itt magát a két tömbelemet hasonlítod össze
		// itt viszont a megszámlálós függvény eredményeit hasonlítod össze
		   
		//       hányszor fordult elő az eddigi max   <   hányszor fordult elő a vizsgált elem
		if ((gyakorisagszamlalo(maxertek, tomb, hossz)) < (gyakorisagszamlalo(tomb[i], tomb, hossz)))
		{
			maxertek = tomb[i];
		}
	}
	return maxertek;
}

int main()
{
	//this is just a test
	// int tomb[] = {1, 3, 4, 4, 4, 4, 6, 6, 6, 8, 8, 6, 6};
	// int hossz = sizeof(tomb) / sizeof(tomb[0]);
	// int result = mostCommon(tomb, hossz);
	// printf("%d", result);
	return 0;
}

