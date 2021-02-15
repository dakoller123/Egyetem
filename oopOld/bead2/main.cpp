#include <string>
#include "raceHandler.h"
#include <iostream>
using namespace std;
int main()
{
    RaceHandler raceHandler = RaceHandler();
    SmallestCarpCaughtResult smallestCatch = raceHandler.SmallestCarpCaught("input.txt", "carp");
    
    if (smallestCatch.anyCarpCaught)
    {
        cout << smallestCatch.raceId << " " << smallestCatch.participantName << " " << smallestCatch.smallestCaughtSize << endl;
    }
    else
    {
        cout << "No carp has been caught by anybody" << endl;
    }
    
    bool everyParticipantCaughtAtLeastTwoCarps = raceHandler.EveryParticipantCaughtAtLeastTwoCarps("input.txt", "carp");

    if (everyParticipantCaughtAtLeastTwoCarps)
    {
        cout << "Every participant had 2 contests at least where they caught at least one carp" << endl;
    }
    else
    {
        cout << "Not every participant had 2 contests at least where they caught at least one carp" << endl;
    }

    return 0;
}