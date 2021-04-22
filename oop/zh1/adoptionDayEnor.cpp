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
                //Valahogy nem tudom �tadni az adoptionEnornak vagy a lineStream(re mutat� pointert) vagy mag�t a line stringet �gy
                //Hogy ut�na az AdoptionEnor l�ssa a d�tum n�lk�li marad�k r�sz�t a sornak
                //Vagy ak�r az eg�sz sort �s akkor a first() m?veletn�l kiszedn�m a d�tumot megint
                //Pr�b�lkoztam stringstream referenci�val, pointerrel, most itt �pp mag�val stringgel is

            AdoptionEnor* adE = new AdoptionEnor(line);
            currentValue.adoptions = adE;
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
