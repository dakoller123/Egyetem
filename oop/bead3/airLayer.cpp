#include "airLayer.h"
#include "weather.h"

AirLayer* Oxigen::affect(Weather* weather)
{
    return weather->affect(this);
};

AirLayer* Ozone::affect(Weather* weather)
{
    return weather->affect(this);
};

AirLayer* CarbonDioxide::affect(Weather* weather)
{
    return weather->affect(this);
};
