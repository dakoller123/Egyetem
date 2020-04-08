#pragma once
#include <string>

class RecipeHandler
{
    public:
        bool EveryRecipeContainsSugar(std::string filePath, std::string sugarName) const;
};