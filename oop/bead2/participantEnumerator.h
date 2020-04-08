#pragma once
#include <string>
#include "raceEnumerator.h"
class ParticipantEnumerator
{
    private:
        int _currentParticipantCarpsCounter;
        std::string _currentParticipantName;
        RaceEnumerator _raceEnumerator;

    public:
        void Next();
        int Current() const;
        bool End();
        void First();
        ParticipantEnumerator(std::string filePath, std::string carpName);
};