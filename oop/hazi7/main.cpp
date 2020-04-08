#include "recipeHandler/recipeHandler.h"

FileReader g_fileReader;

int main()
{
    g_fileReader = FileReader("path_goes_here")
    RecipeHander recipeHandler = RecipeHandler();
    bool result = recipeHandler.EveryRecipeContainsSugar();
    return 0;
}