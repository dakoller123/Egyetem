#include "participantEnumerator.h"
#include <string>
#include "raceEnumerator.h"
#include <iostream>

void ParticipantEnumerator::First()
{
    _raceEnumerator.First();
    Next();
}

void ParticipantEnumerator::Next()
{
    std::cout << "ParticipantEnumerator::Next() invoked" << std::endl;

    if (_raceEnumerator.End())
    {
        if (_raceEnumerator.Current().participantName == _currentParticipantName)
        {
            _currentParticipantCarpsCounter = _currentParticipantCarpsCounter + 1;
            std::cout << _currentParticipantName << " " << _currentParticipantCarpsCounter << std::endl;
        }
        else
        {
            _currentParticipantName = _raceEnumerator.Current().participantName;
            _currentParticipantCarpsCounter = 0;
            std::cout << _currentParticipantName << " " << _currentParticipantCarpsCounter << std::endl;
            if (_raceEnumerator.Current().anyCarpCaught)
            {
                _currentParticipantCarpsCounter = _currentParticipantCarpsCounter + 1;
                std::cout << _currentParticipantName << " " << _currentParticipantCarpsCounter << std::endl;
            }
        }

        _end = true;
    }
    else
    {
        _currentParticipantName = _raceEnumerator.Current().participantName;
        _currentParticipantCarpsCounter = 0;
        std::cout << _currentParticipantName << " " << _currentParticipantCarpsCounter << std::endl;

        while (!_raceEnumerator.End() && _raceEnumerator.Current().participantName == _currentParticipantName)
        {
            if (_raceEnumerator.Current().anyCarpCaught)
            {
                _currentParticipantCarpsCounter = _currentParticipantCarpsCounter + 1;
                std::cout << _currentParticipantName << " " << _currentParticipantCarpsCounter << std::endl;
            }
            _raceEnumerator.Next();
        }
    } 
}

bool ParticipantEnumerator::End()
{
    return _end;
}

int ParticipantEnumerator::Current() const
{
    return _currentParticipantCarpsCounter;
}