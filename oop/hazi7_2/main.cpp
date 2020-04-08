#include "recipeEnumerator.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    std::string filePath = "input.txt";
    RecipeEnumerator recipes = RecipeEnumerator(filePath);

    bool everyRecipeContainsSugar = true;
    recipes.First();
    
    while (!recipes.End() && everyRecipeContainsSugar)
    {
        everyRecipeContainsSugar = everyRecipeContainsSugar && recipes.Current();
        recipes.Next();        
   }

    if (everyRecipeContainsSugar)
    {
        cout << "every recipe has sugar";
    }
    else
    {
        cout << "not every recipe has sugar";
    }
    return 0;
}