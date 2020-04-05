#pragma once
#include 'FileReader.h';


const int FileReaderNotInitializedException = 98;

//Container for Dependency Injection
class DIContainer
{
    private:
        bool _fileReaderInitialized;
        FileReader _fileReaderInstance;

    public:
        AddFileReader(FileReader fileReader)
        {
            _fileReader = fileReader;
        }

        GetFileReader()
        {
            if (_fileReaderInitialized)
            {
                return _fileReaderInstance;
            }
            else
            {
                throw FileReaderNotInitializedException;
            }
        }
};