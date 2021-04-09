#include "baseEnor.h"
#include <fstream>
#include <sstream>

BaseEnor::BaseEnor(const std::string &str) throw (FileError)
{
    _f.open(str);
    if(_f.fail())throw MissingInputFile;
}

bool read(std::ifstream& f, struct record& currentValue, Status& st)
{
    std::string line;
    getline(f,line);
    st = Abnormal;
    if (!f.fail() && line!="")
    {
        std::stringstream lineStream(line);
        try
        {
            lineStream >> currentValue.randomAttribute;
            st=Normal;
        }
        catch(std::exception ex){}
    }
    return st == Normal;
}

void BaseEnor::next()
{
   read(_f, _current, _status);
}

struct record BaseEnor::current() const
{
    return _current;
}

void BaseEnor::first()
{
    next();
}

bool BaseEnor::end() const
{
    return _status != Normal;
}
