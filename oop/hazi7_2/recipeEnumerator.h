#pragma once
#include <fstream>
#include <string>

class RecipeEnumerator
{
    private:
        std::ifstream _fileStream;     
        bool _currentSugar;
        std::string _currentRecipeName;
        bool _end;

    public:
        void First();
        void Next();
        bool End();
        bool Current() const;
        RecipeEnumerator(std::string path);
};