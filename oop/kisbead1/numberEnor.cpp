#include "temperatureEnor.h"
#include <fstream>
#include <sstream>
TemperatureEnor::TemperatureEnor(const std::string &str) throw (FileError)
{
    _f.open(str);
    if(_f.fail())throw MissingInputFile;
}

float read(std::ifstream& f, float& currentTemp, Status& st)
{
    std::string line;
    getline(f,line);
    st = Abnormal;
    if (!f.fail() && line!="")
    {
        std::stringstream lineStream(line);
        try
        {
            lineStream >> currentTemp;
            st=Normal;
        }
        catch(std::exception ex){}
    }
    return st == Normal;
}

void TemperatureEnor::next()
{
   read(_f, _current, _status);
}

float TemperatureEnor::current() const
{
    return _current;
}

void TemperatureEnor::first()
{
    next();
}

bool TemperatureEnor::end() const
{
    return _status != Normal;
}
