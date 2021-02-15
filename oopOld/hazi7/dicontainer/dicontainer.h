#pragma once
#include "../fileReader/fileReader.h"

//Container for Dependency Injection or various classes (currently just one)
class DIContainer
{
    private:
        FileReader _fileReaderInstance;

    public:
        DIContainer(FileReader fileReader)
        {
            _fileReaderInstance = fileReader;
        }

        FileReader GetFileReader()
        {
            return _fileReaderInstance;
        }
};