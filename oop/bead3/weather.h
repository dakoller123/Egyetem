#pragma once
#include "airLayer.h"
#include <string>
class AirLayer;
class Oxigen;
class Ozone;
class CarbonDioxide;

class Weather
{
    public:
        virtual AirLayer* affect(Oxigen* airlayer) = 0;
        virtual AirLayer* affect(Ozone* airlayer) = 0;
        virtual AirLayer* affect(CarbonDioxide* airlayer) = 0;
        static void destroy();
        virtual std::string toString() const = 0;
};


class Sunny: public Weather
{
    public:
        AirLayer* affect(Oxigen* airlayer) override;
        AirLayer* affect(Ozone* airlayer) override;
        AirLayer* affect(CarbonDioxide* airlayer) override;
        static Weather* GetInstance()
        {
            static Sunny instance;
            return (Weather*)&instance;
        }

        std::string toString() const override {return "Sunny";};
};


class Stormy: public Weather
{
    public:
        AirLayer* affect(Oxigen* airlayer) override;
        AirLayer* affect(Ozone* airlayer) override;
        AirLayer* affect(CarbonDioxide* airlayer) override;
        static Weather* GetInstance()
        {
            static Stormy instance;
            return (Weather*)&instance;
        }
        std::string toString() const override {return "Stormy";};
};

class MiscWeather: public Weather
{
    public:
        AirLayer* affect(Oxigen* airlayer) override;
        AirLayer* affect(Ozone* airlayer) override;
        AirLayer* affect(CarbonDioxide* airlayer) override;
        static Weather* GetInstance()
        {
            static MiscWeather instance;
            return (Weather*)&instance;
        }
        std::string toString() const override {return "MiscWeather";};
};

