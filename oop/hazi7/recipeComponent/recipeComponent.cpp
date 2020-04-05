#include "recipeComponent.h"

RecipeComponent::RecipeComponent(std::string recipeName, std::string componentName, int count, std::string unit)
{
    RecipeName = recipeName;
    ComponentName = componentName;
    Count = count;
    Unit = unit;
}