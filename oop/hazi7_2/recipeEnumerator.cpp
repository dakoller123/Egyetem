#include "recipeEnumerator.h"
#include <iostream>
#include <fstream>

RecipeEnumerator::RecipeEnumerator(std::string path)
{
    _fileStream = std::ifstream(path);
}

void RecipeEnumerator::First()
{
    Next();
}

void RecipeEnumerator::Next()
{
    std::string recipeName;
    std::string componentName;
    int count;
    std::string unit; 

    _fileStream >> recipeName >> componentName >> count >> unit;
    _currentSugar = (componentName == "cukor" && count > 0);
    _currentRecipeName = recipeName;
    
    while (_currentRecipeName == recipeName && !(_fileStream.eof()))
    {
        _fileStream >> recipeName >> componentName >> count >> unit;
        _currentSugar = _currentSugar || (componentName == "cukor" && count > 0);
    }
}


bool RecipeEnumerator::Current() const
{
    return _currentSugar;
}


bool RecipeEnumerator::End()
{
    return _fileStream.eof();
}