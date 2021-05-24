#pragma once
#include "airLayer.h"
#include <vector>
#include <queue>
#include <string>
class Simulation
{
    private:
        std::vector<AirLayer*> _airLayers;
        std::queue<Weather*> _weathers;
        std::string getState();
    public:
        int getLayerCount();
        Simulation(std::string& fileName);
        void simulateRound();
        ~Simulation();
};
