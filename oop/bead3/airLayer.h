#pragma once
#include "weather.h"
#include <string>

class Weather;

class AirLayer
{
    private:
        bool _new;
    protected:
        float _thickness;
    public:
        AirLayer(float thickness) : _new(false), _thickness(thickness)  {}
        bool isTooThin() {return _thickness < 0.5;}
        void setThickness(float thickness) {_thickness = thickness;}
        float getThickness()
        {
            return _thickness;
        }
        virtual AirLayer* affect(Weather* weather) = 0;
        virtual ~AirLayer(){}
        virtual std::string toString() = 0;
        void setNew(){_new = true;}
        void setOld(){_new = false;}
        bool isNew(){return _new;}
        virtual int getType() const = 0;
};

class Oxigen: public AirLayer
{
    public :
        Oxigen(float thickness): AirLayer(thickness){};
        AirLayer* affect(Weather* weather) override;
        std::string toString() override
        {
            return "(Oxigen," + std::to_string(_thickness) + ")";
        }
        int getType() const override  {return 1;}
};

class Ozone: public AirLayer
{
    public :
        Ozone(float thickness): AirLayer(thickness){};
        AirLayer* affect(Weather* weather) override;
        std::string toString() override
        {
            return "(Ozone," + std::to_string(_thickness) + ")";
        }
        int getType() const override  {return 2;}
};

class CarbonDioxide: public AirLayer
{
    public :
        CarbonDioxide(float thickness): AirLayer(thickness){};
        AirLayer* affect(Weather* weather) override;
        std::string toString() override
        {
            return "(CarbonDioxide," + std::to_string(_thickness) + ")";
        }
        int getType() const override  {return 3;}
};
