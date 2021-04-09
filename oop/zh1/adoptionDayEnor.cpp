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

            AdoptionEnor adE = AdoptionEnor(&lineStream);
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
