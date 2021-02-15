#include "raceHandler.h"
#include <string>
#include "raceEnumerator.h"
#include "participantEnumerator.h"

bool RaceHandler::EveryParticipantCaughtAtLeastTwoCarps(std::string filePath, std::string carpName)
{
    ParticipantEnumerator participantEnumerator = ParticipantEnumerator(filePath, carpName);
    
    participantEnumerator.First();

    bool result = (participantEnumerator.Current() > 1);

    while (!participantEnumerator.End())
    {
        result = result && (participantEnumerator.Current() > 1);
        participantEnumerator.Next();
    }

    return result;
}



SmallestCarpCaughtResult RaceHandler::SmallestCarpCaught(std::string filePath, std::string carpName)
{
    RaceEnumerator raceEnumerator = RaceEnumerator(filePath, carpName);
    
    SmallestCarpCaughtResult result;

    raceEnumerator.First();

    result.anyCarpCaught = (raceEnumerator.Current().anyCarpCaught);
    if (result.anyCarpCaught)
    {
        result.smallestCaughtSize  = raceEnumerator.Current().smallestCarpCaught;
        result.raceId = raceEnumerator.Current().raceId;
        result.participantName= raceEnumerator.Current().participantName;
    }
    
    raceEnumerator.Next();

    while (!raceEnumerator.End())
    {
        if (raceEnumerator.Current().anyCarpCaught)
        {
            if (result.anyCarpCaught == false)
            {
                result.smallestCaughtSize  = raceEnumerator.Current().smallestCarpCaught;
                result.raceId = raceEnumerator.Current().raceId;
                result.participantName= raceEnumerator.Current().participantName;
            }
            else
            {
                if (raceEnumerator.Current().smallestCarpCaught < result.smallestCaughtSize)
                {
                    result.smallestCaughtSize  = raceEnumerator.Current().smallestCarpCaught;
                    result.raceId = raceEnumerator.Current().raceId;
                    result.participantName= raceEnumerator.Current().participantName;                  
                }
            }
        }

        raceEnumerator.Next();
    }

    return result;
}