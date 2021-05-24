#include "weather.h"
#include "airLayer.h"
#include "simulation.h"
#include <iostream>

//#define NORMAL_MODE
#ifdef NORMAL_MODE

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


#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("sim test")
{
    std::string fileName = "input.txt";
    Simulation s = Simulation(fileName);
    s.simulateRound();
    CHECK(s.getLayerCount() == 4);
}

TEST_CASE("Weather and Air")
{
    AirLayer* oxigen = new Oxigen(6.0);
    AirLayer * newLayer = oxigen->affect(Stormy::GetInstance());
    CHECK(oxigen->getThickness() == 3.0);
    CHECK(newLayer->getThickness() == 3.0);
    CHECK(newLayer->getType() == 2.0);
    delete newLayer;
    delete oxigen;
}
#endif // NORMAL_MODE
