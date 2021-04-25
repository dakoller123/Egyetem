#include "studentEnor.h"
#include "classEnor.h"
#include <fstream>
#include <sstream>
#include <iostream>

void ClassEnor::next()
{
    _current.sumWeight = 0;
    _current.classId = _studentEnor.current().classId;
    std::cout << "Current classId: " << _current.classId << "Current sum: ";
    while (!_studentEnor.end() && _current.classId == _studentEnor.current().classId)
    {
       _current.sumWeight += _studentEnor.current().sumWeight;
        std::cout << _current.sumWeight << " ";
       _studentEnor.next();
    }
    std::cout << std::endl;
}

struct classResult ClassEnor::current() const
{
    return _current;
}

void ClassEnor::first()
{
    _studentEnor.first();

    if (!_studentEnor.end())
    {
       _isEmpty = false;
       next();
    }
}

bool ClassEnor::end() const
{
    return _studentEnor.end();
}

bool ClassEnor::isEmpty() const
{
    return _isEmpty;
}
