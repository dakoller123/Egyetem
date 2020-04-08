#pragma once
#include <string>

struct SmallestCarpCaughtResult
{
    float smallestCaughtSize;
    std::string raceId;
    std::string participantName;
    bool anyCaught;
}

class RaceHandler
{
    public:
        bool EveryParticipantCaughtAtLeastTwoCarps(std::string filePath, std::string carpName);
        SmallestCarpCaughtResult SmallestCarpCaught(std::string filePath, std::string carpName);
};