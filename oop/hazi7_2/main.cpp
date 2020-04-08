#include "recipeHandler.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    if (RecipeHandler().EveryRecipeContainsSugar("input.txt", "cukor"))
    {
        cout << "every recipe has sugar";
    }
    else
    {
        cout << "not every recipe has sugar";
    }


    return 0;
}