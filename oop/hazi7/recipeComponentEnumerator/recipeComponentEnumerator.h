#pragma once
#include "../recipeComponent/recipeComponent.h"
#include "../fileReader/fileReader.h"

class RecipeComponentEnumerator
{
    private: 
        std::string _recipeName;
        RecipeComponent _current;

     public:    
        void First();
        void Next();
        bool End();
        RecipeComponent Current() const;
        // RecipeComponentEnumerator(FileReader FileReader);
};
