#pragma once

#include <fstream>
#include "../recipeComponent/recipeComponent.h"

class FileReader
{
    private:
        std::ifstream _fileStream;        
    public:
        FileReader();
        RecipeComponent GetLine();
        bool End();
};