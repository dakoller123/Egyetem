#pragma once
#include 'recipeComponent.h'

class RecipeComponentEnumerator()
{
    private 
        std::string _recipeName;
        FileReader _fileReader;
        RecipeComponent current;

     public:    
        void First();
        void Next();
        bool End();
        RecipeComponent Current() const;
        RecipeComponentEnumerator(FileReader FileReader);
}
