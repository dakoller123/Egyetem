#include <string>
#include "raceHandler.h"

int main()
{
    RaceHandler raceHandler = RaceHandler();
    int smallestCatch = raceHandler.SmallestCarpCaught("input.txt", "carp");
    bool everyParticipantCaughtAtLeastTwoCarps = raceHandler.EveryParticipantCaughtAtLeastTwoCarps("input.txt", "carp");
    return 0;
}