#pragma once
#include "../recipe/recipe.h"

class RecipeEnumerator
{
    private:
        Recipe _current;

     public:    
        void First();
        void Next();
        bool End();
        Recipe Current();

};
