#include "participantEnumerator.h"
#include <string>
#include "raceEnumerator.h"

void ParticipantEnumerator::First()
{
    _raceEnumerator.First();
    Next();
}

void ParticipantEnumerator::Next()
{
    _end = _raceEnumerator.End();

    if (!_end)
    {
        _currentParticipantName = _raceEnumerator.Current().participantName;
        _currentParticipantCarpsCounter = 0;

        while (!_raceEnumerator.End() && _raceEnumerator.Current().participantName == _currentParticipantName)
        {
            if (_raceEnumerator.Current().anyCarpCaught)
            {
                _currentParticipantCarpsCounter = _currentParticipantCarpsCounter + 1;
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