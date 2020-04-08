#include "recipeEnumerator.h"
#include "recipeHandler.h"

bool RecipeHandler::EveryRecipeContainsSugar(std::string filePath, std::string sugarName) const
{
    RecipeEnumerator recipes = RecipeEnumerator(filePath, sugarName);

    bool everyRecipeContainsSugar = true;
    recipes.First();
    
    while (!recipes.End() && everyRecipeContainsSugar)
    {
        everyRecipeContainsSugar = everyRecipeContainsSugar && recipes.Current();
        recipes.Next();        
   }

   return everyRecipeContainsSugar;
}