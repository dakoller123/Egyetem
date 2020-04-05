#pragma once
#include 'recipeComponentEnumerator.h'

class Recipe
{
    private:
        RecipeComponentEnumerator _components;
        std::string recipeName;
        bool _containsSugar;
        void calcSugarContainment();

    public:
        Recipe(RecipeComponentEnumerator components);
        bool ContainsSugar() const;
};