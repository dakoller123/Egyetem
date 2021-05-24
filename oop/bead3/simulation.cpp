#include "airLayer.h"
#include "weather.h"
#include "simulation.h"
#include <fstream>
#include <list>
#include <stdexcept>
#include <deque>
#include <iostream>
Simulation::Simulation(std::string& fileName)
{
    std::ifstream ifs (fileName, std::ifstream::in);

    _airLayers = std::vector<AirLayer*>{};
    int airLayerCount;
    ifs >> airLayerCount;
    for (int i=0; i<airLayerCount; i++)
    {
        char airLayerType;
        float thickness;
        ifs >> airLayerType >> thickness;

        AirLayer* newLayer;

        switch(airLayerType)
        {
            case 'z':
                newLayer = new Ozone(thickness);
                break;
            case 'x':
                newLayer = new Oxigen(thickness);
                break;
            case 's':
                newLayer = new CarbonDioxide(thickness);
                break;
            default:
                throw std::logic_error("Switch case not yet implemented");
        }

        _airLayers.push_back(newLayer);
    }
    _weathers = std::queue<Weather*>();
    char weatherType;

    while (ifs>>weatherType)
    {
        switch(weatherType)
        {
            case 'm':
                _weathers.push(MiscWeather::GetInstance());
                break;
            case 'n':
                _weathers.push(Sunny::GetInstance());
                break;
            case 'z':
                _weathers.push(Stormy::GetInstance());
                break;
            default:
                throw std::logic_error("Switch case not yet implemented");
        }
    }

    ifs.close();
}

Simulation::~Simulation()
{
    for (AirLayer* layer : _airLayers)
    {
        delete layer;
    }
}

int Simulation::getLayerCount()
{
    return _airLayers.size();
}

std::string Simulation::getState()
{
    std::string result = "";

    for (AirLayer* layer : _airLayers)
    {
        result += (" " + layer->toString());
    }

    return result;
}

void Simulation::simulateRound()
{
    std::cout<< "----------------------------------------------------------------------------------------------------" << std::endl;

    Weather* currentWeather = _weathers.front();
    _weathers.pop();
    _weathers.push(currentWeather);

    std::cout<<"Current weather: " << currentWeather->toString() << std::endl;

    std::cout<<"AirLayers before weather affected them: " << getState() << std::endl;

    for (int i=0; i<_airLayers.size(); i++)
    {
        AirLayer* newLayer = _airLayers[i]->affect(currentWeather);
        if (newLayer != 0)
        {
            _airLayers.insert(_airLayers.begin()+i, newLayer);
            i++;
        }
    }

    std::cout<<"AirLayers after weather affected them: " << getState() << std::endl;

    for (int i=0; i<_airLayers.size(); i++)
    {
        AirLayer* currentAirLayer = _airLayers[i];
        if (currentAirLayer->isNew() || currentAirLayer->isTooThin())
        {

            bool found = false;

            for (int j=i+1; j<_airLayers.size(); j++)
            {
                if (currentAirLayer->getType() == _airLayers[j]->getType())
                {
                    found = true;
                    _airLayers[j]->setThickness(_airLayers[j]->getThickness() + currentAirLayer->getThickness());
                }
            }

            _airLayers.erase(_airLayers.begin() + i);

            if (!found && currentAirLayer->isNew())
            {
                _airLayers.push_back(currentAirLayer);
                currentAirLayer->setOld();
            }
            else
            {
                delete currentAirLayer;
            }
        }
    }

    std::cout<<"AirLayers after evaporation: " << getState() << std::endl;

}
