#include <fstream>
#include <string>
#include "raceEnumerator.h"
#include <sstream>
RaceEnumerator::RaceEnumerator(std::string path, std::string carpName)
{
    _fileStream = std::ifstream(path);
    _carpName = carpName;
}

Race RaceEnumerator::Current() const
{
    return _current;
}

bool RaceEnumerator::End()
{
    return _end;
}

void RaceEnumerator::First()
{
    Next();
}

void RaceEnumerator::Next()
{
    std::string line;
    std::getline(_fileStream , line);
    _end = _fileStream.fail();
    if(!_end){
        std::istringstream stringStream = std::istringstream(line);
        stringStream >> _current.participantName >> _current.raceId;
        
        _current.anyCarpCaught = false;
        std::string fishName;
        float fishSize;

        for( stringStream >> fishName >> fishSize ; !stringStream.fail(); stringStream >> fishName >> fishSize )
        {
            if(fishName == _carpName)
            {
                if (!_current.anyCarpCaught)
                {
                    _current.smallestCarpCaught = fishSize;
                }
                else
                {
                    if (_current.smallestCarpCaught > fishSize)
                    {
                        _current.smallestCarpCaught = fishSize;
                    }
                }
                _current.anyCarpCaught = true;                
            }
        }
    }
}