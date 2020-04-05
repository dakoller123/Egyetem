#pragma once

int FileReaderEndException = 68;

class FileReader
{
    public:
        FileReader(std::string path);
        RecipeComponent GetLine();
        bool End();
}