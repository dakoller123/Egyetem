#include "adoptionEnor.h"
#include <fstream>
#include <sstream>

//AdoptionEnor::AdoptionEnor(std::stringstream &stream)
//{
//    _f.open(str);
//    if(_f.fail())throw MissingInputFile;
//}
//
//bool read(std::ifstream& f, struct record& currentValue, Status& st)
//{
//    std::string line;
//    getline(f,line);
//    st = Abnormal;
//    if (!f.fail() && line!="")
//    {
//        std::stringstream lineStream(line);
//        try
//        {
//            lineStream >> currentValue.randomAttribute;
//            st=Normal;
//        }
//        catch(std::exception ex){}
//    }
//    return st == Normal;
//}

void AdoptionEnor::next()
{
   //read(_f, _current, _status);
}

struct adoption AdoptionEnor::current() const
{
    return _current;
}

void AdoptionEnor::first()
{
    next();
}

bool AdoptionEnor::end() const
{
    return _status != Normal;
}
