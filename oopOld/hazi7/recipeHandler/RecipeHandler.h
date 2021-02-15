#pragma once
#include "../recipeEnumerator/recipeEnumerator.h"

class RecipeHandler
{
    private:
        RecipeEnumerator _recipes;
        bool everyRecipeContainsSugar;

    public:
        RecipeHandler();
        bool EveryRecipeContainsSugar() const;
};