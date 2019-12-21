#include <iostream>

using namespace std;

int main()
{
    int n=7;
    
    int ora[n]={11, 11, 12, 23, 23, 23, 23 };
    int perc[n]={10, 50, 10, 10, 11, 15, 20};
    int tranzakcio[n]={1, -2, -1, 1, -2, 1, 1,};
    int azonosito[n]={12345, 10000, 12345, 24680, 5000, 13579, 98765};
		
    int ido[n]={};
	int idoIndex = 0;
	
	for (int i=0; i<n; i++)
	{
		//itt csak a belepesre fokuszálunk
		if (tranzakcio[i] == 1)
		{
			
			int kilepettE = 1;
			
			for (int j=0; j<n; j++)
			{
				//itt csak a kilepesre
				if (tranzakcio[j] == -1)
				{
					if (azonosito[i] == azonosito[j] && i!=j)
					{
						//jelezzuk hogy kilepett a tag és nem rugták ki 24 orakor
						kilepettE = 0;
						
						ido[idoIndex] = (ora[j]-ora[i]) * 60 + perc[j] - perc[i]; 
						idoIndex++;
					}
				}
			}
			
			//nem lepett ki, kirugtak a nap vegen
			if (kilepettE == 1)
			{
				ido[idoIndex] = (24-ora[i]) * 60 - perc[i];
				idoIndex++;
			}
		}
	}

	
	int maxIndex = 0;
	int maxErtek = ido[maxIndex];
	for (int i=1; i<=idoIndex; i++)
	{
		if (ido[i] > maxErtek)
		{
			maxIndex = i;
			maxErtek = ido[i];
		}
	}
	
	cout << maxErtek;
	
	return 0;
}