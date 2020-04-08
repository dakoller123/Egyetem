#pragma once
#include <fstream>

struct Race
{
    std::string raceId;
    std::string participantName;
    bool anyCarpCaught;
    float smallestCarpCaught;
};

class RaceEnumerator
{
    private:
        std::ifstream _fileStream; 
        Race _current;
        std::string _carpName;
        bool _end;
    
    public:
        void First();
        bool End();
        Race Current() const;
        void Next();
        RaceEnumerator(std::string path, std::string carpName);
               
};