#include "studentEnor.h"
#include <fstream>
#include <sstream>
#include <iostream>
StudentEnor::StudentEnor(const std::string &str) throw (FileError)
{
    _f.open(str);
    if(_f.fail())throw MissingInputFile;
}

bool read(std::ifstream& f, struct student& currentValue, Status& st)
{
    std::string line;
    getline(f,line);
    st = Abnormal;
    if (!f.fail() && line!="")
    {
        std::stringstream lineStream(line);

        try
        {
            lineStream >> currentValue.name;

            std::string nextWord;
            lineStream >> nextWord;
            while (nextWord.length() > 2)
            {
                lineStream >> nextWord;
            }

            currentValue.classId = nextWord;

            currentValue.sumWeight = 0;
            float tmpWeight = 0;
            std::string tmpDate;
            while (lineStream >> tmpDate >> tmpWeight)
            {
                currentValue.sumWeight += tmpWeight;
            }
            st=Normal;
        }
        catch(std::exception ex){}
    }
    return st == Normal;
}

void StudentEnor::next()
{
   read(_f, _current, _status);
}

struct student StudentEnor::current() const
{
    return _current;
}

void StudentEnor::first()
{
    next();
}

bool StudentEnor::end() const
{
    return _status != Normal;
}