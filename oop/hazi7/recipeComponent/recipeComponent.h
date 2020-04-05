#pragma once

#include <string>

class RecipeComponent
{
    private:



    public:
    
        RecipeComponent(std::string recipeName, std::string componentName, int count, std::string unit);
        std::string RecipeName;
        std::string ComponentName;
        int Count;
        std::string Unit; 
};