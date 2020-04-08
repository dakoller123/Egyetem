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
        cout << "No carp has been caught by anybody";
    }
    
    cout << smallestCatch.anyCarpCaught;
    bool everyParticipantCaughtAtLeastTwoCarps = raceHandler.EveryParticipantCaughtAtLeastTwoCarps("input.txt", "carp");
    return 0;
}