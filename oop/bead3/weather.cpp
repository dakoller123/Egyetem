#include "airLayer.h"
#include "weather.h"

AirLayer* Sunny::affect(Oxigen* airlayer)
{
    float original = airlayer->getThickness();
    airlayer->setThickness(original*95/100);
    AirLayer* newLayer = new Ozone(original*5/100);
    newLayer->setNew();
    return newLayer;
}

AirLayer* Sunny::affect(Ozone* airlayer)
{
    return 0;
}

AirLayer* Sunny::affect(CarbonDioxide* airlayer)
{
    float original = airlayer->getThickness();
    airlayer->setThickness(original*95/100);
    AirLayer* newLayer = new Oxigen(original*5/100);
    newLayer->setNew();
    return newLayer;
}

AirLayer* Stormy::affect(Oxigen* airlayer)
{
    float original = airlayer->getThickness();
    airlayer->setThickness(original/2);
    AirLayer* newLayer = new Ozone(original/2);
    newLayer->setNew();
    return newLayer;
}

AirLayer* Stormy::affect(Ozone* airlayer)
{
    return 0;
}

AirLayer* Stormy::affect(CarbonDioxide* airlayer)
{
    return 0;
}


AirLayer* MiscWeather::affect(Ozone* airlayer)
{
    float original = airlayer->getThickness();
    airlayer->setThickness(original*95/100);
    AirLayer* newLayer = new Oxigen(original*5/100);
    newLayer->setNew();
    return newLayer;
}

AirLayer* MiscWeather::affect(Oxigen* airlayer)
{
    float original = airlayer->getThickness();
    airlayer->setThickness(original*90/100);
    AirLayer* newLayer = new CarbonDioxide(original*10/100);
    newLayer->setNew();
    return newLayer;
}

AirLayer* MiscWeather::affect(CarbonDioxide* airlayer)
{
    return 0;
}
