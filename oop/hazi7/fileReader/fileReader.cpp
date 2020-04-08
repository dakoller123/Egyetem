import 'fileReader.h'
#include <iostream>

FileReader::FileReader(std::string path)
{

    _fileStream = ifstream(path);
}

RecipeComponent FileReader::GetLine()
{
    std::string recipeName;
    std::string componentName;
    int count;
    std::string unit; 

    _fileStream >> recipeName >> componentName >> count >> unit;
}


bool FileReader::End()
{
    return _fileStream.eof();
}