#pragma once
#include 'recipeComponentEnumerator.h'

class RecipeHandler
{
    private:
        FileReader _fileReader;
        RecipeEnumerator _recipes;

    public:
        RecipeHandler(FileReader fileReader);
        bool EveryRecipeContainsSugar() const;
};