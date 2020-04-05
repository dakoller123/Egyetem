#pragma once
#include 'RecipeHandler.h'

RecipeHandler::EveryRecipeContainsSugar() const
{
    result = false;
    _recipes.First();
    
    while (!_recipes.End())
    {
        result = result || _recipes.Current().ContainsSugar();
        _recipes.Next();        
   }

    return result;  
};