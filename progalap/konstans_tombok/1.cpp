#include <iostream>
#include <cstdlib>

using namespace std;

const int CardsInHungarianDeck = 8;
const string Cards[CardsInHungarianDeck] = {"VII", "VIII", "IX", "X", "Also", "Felso", "Kiraly", "Asz"};
const int Values[CardsInHungarianDeck] = {7,8,9,10,2,3,4,11};

bool validateCard(string cardToBeValidated)
{
	for (int i=0; i<CardsInHungarianDeck; i++)
	{
		if (Cards[i] == cardToBeValidated)
		{
			return true;
		}
	}
	
	return false;
}

string ReadInputAndValidate()
{
	string inputCard;
	do 
	{		
		string inputCard;
		cin >> inputCard;
	} while (!(validateCard(inputCard)));
	return inputCard;
}

int main()
{
	string inputCard;
	cin >> inputCard;
	cout << validateCard(inputCard);
	return 0;
}