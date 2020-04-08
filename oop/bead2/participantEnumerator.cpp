#include "participantEnumerator.h"
#include <string>
#include "raceEnumerator.h"

ParticipantEnumerator::ParticipantEnumerator(std::string filePath, std::string carpName)
{
    _raceEnumerator = RaceEnumerator(filePath, carpName);
}

void ParticipantEnumerator::First()
{
    Next();
}


void ParticipantEnumerator::Next()
{
    _currentParticipantName = _raceEnumerator.Current().participantName;
    _currentParticipantCarpsCounter = 0;
    
    if (_raceEnumerator.Current().anyCarpCaught)
    {
        _currentParticipantCarpsCounter = _currentParticipantCarpsCounter + 1;
    }

    while (!_raceEnumerator.End() && _raceEnumerator.Current().participantName == _currentParticipantName)
    {
        if (_raceEnumerator.Current().anyCarpCaught)
        {
            _currentParticipantCarpsCounter = _currentParticipantCarpsCounter + 1;
        }
        _raceEnumerator.Next();
    }
}

bool ParticipantEnumerator::End()
{
    return _raceEnumerator.End();
}

int ParticipantEnumerator::Current() const
{
    return _currentParticipantCarpsCounter;
}