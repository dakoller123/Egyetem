#include "numberEnor.h"
#include <fstream>
#include <sstream>
NumberEnor::NumberEnor(const std::string &str) throw (FileError)
{
    _f.open(str);
    if(_f.fail())throw MissingInputFile;
}

bool read(std::ifstream& f, int& currentValue, Status& st)
{
    std::string line;
    getline(f,line);
    st = Abnormal;
    if (!f.fail() && line!="")
    {
        std::stringstream lineStream(line);
        try
        {
            lineStream >> currentValue;
            st=Normal;
        }
        catch(std::exception ex){}
    }
    return st == Normal;
}

void NumberEnor::next()
{
   read(_f, _current, _status);
}

int NumberEnor::current() const
{
    return _current;
}

void NumberEnor::first()
{
    next();
}

bool NumberEnor::end() const
{
    return _status != Normal;
}
