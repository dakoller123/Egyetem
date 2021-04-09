#include "adoptionDayEnor.h"
#include <fstream>
#include <sstream>
#include <iostream>

AdoptionDayEnor::AdoptionDayEnor(const std::string &str) throw (FileError)
{
    _f.open(str);
    if(_f.fail())throw MissingInputFile;
}

bool read(std::ifstream& f, struct adoptionDay& currentValue, Status& st)
{
    std::string line;
    getline(f,line);
    st = Abnormal;
    if (!f.fail() && line!="")
    {
        std::stringstream lineStream(line);
        try
        {
            lineStream >> currentValue.date;
            std::cout << "currentValue.date: " << currentValue.date << std::endl;
            std::cout << "Linestream: " << lineStream.str() << std::endl;

            //Itt a bug:
            //Valahogy nem tudom átadni az adoptionEnornak vagy a lineStream(re mutató pointert) vagy magát a line stringet úgy
            //Hogy utána az AdoptionEnor lássa a dátum nélküli maradék részét a sornak
            //Vagy akár az egész sort és akkor a first() műveletnél kiszedném a dátumot megint
            //Próbálkoztam stringstream referenciával, pointerrel, most itt épp magával stringgel is

            AdoptionEnor adE = AdoptionEnor(line);
            currentValue.adoptions = & adE;
            st=Normal;
        }
        catch(std::exception ex){}
    }
    return st == Normal;
}

void AdoptionDayEnor::next()
{
    read(_f, _current, _status);
}

struct adoptionDay AdoptionDayEnor::current() const
{
    return _current;
}

void AdoptionDayEnor::first()
{
    next();
}

bool AdoptionDayEnor::end() const
{
    return _status != Normal;
}
