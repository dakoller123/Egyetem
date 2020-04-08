#include "raceHandler.h"
#include <string>
#include "raceEnumerator"

bool RaceHandler::EveryParticipantCaughtAtLeastTwoCarps(std::string filePath, std::string carpName)
{
    return false;
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
            if (anyCarpCaughtTotal == false)
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
    }

}