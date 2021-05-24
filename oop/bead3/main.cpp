#include "weather.h"
#include "airLayer.h"
#include "simulation.h"
#include <iostream>
int main()
{
    std::string fileName = "input.txt";
    Simulation s = Simulation(fileName);

    int originalCount = s.getLayerCount();
    while (s.getLayerCount() > 3 && s.getLayerCount() < originalCount*3)
    {
        s.simulateRound();
    }
}
