#pragma once
#include "RecipeHandler.h"

RecipeHandler::RecipeHandler()
{
    _everyRecipeContainsSugar = false;
    _recipes.First();
    
    while (!_recipes.End())
    {
        _everyRecipeContainsSugar = _everyRecipeContainsSugar || _recipes.Current().ContainsSugar();
        _recipes.Next();        
   }

}


RecipeHandler::EveryRecipeContainsSugar() const
{
    return _everyRecipeContainsSugar;  
};