#include "studentEnor.h"
#include <fstream>
#include <sstream>
#include <iostream>
StudentEnor::StudentEnor(const std::string &str) throw (FileError)
{
    _f.open(str);
    if(_f.fail())throw MissingInputFile;
}

void StudentEnor::next()
{
    std::string line;
    getline(_f,line);
    _end = true;
    if (!_f.fail() && line!="")
    {
        std::stringstream lineStream(line);
        lineStream >> _current.name;
        std::string nextWord;
        lineStream >> nextWord;

        while (nextWord.length() > 2)
        {
            lineStream >> nextWord;
        }

        _current.classId = nextWord;
        _current.sumWeight = 0;
        float tmpWeight = 0;
        std::string tmpDate;

        while (lineStream >> tmpDate >> tmpWeight)
        {
            _current.sumWeight += tmpWeight;
        }

        _end = false;
    }
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
    return _end;
}
