#include "studentEnor.h"
#include "classEnor.h"
#include <fstream>
#include <sstream>

void ClassEnor::next()
{
    _current.sumWeight = 0;
    _current.classId = _studentEnor.current().classId;
    while (!_studentEnor.end() && _current.classId == _studentEnor.current().classId)
    {
       _current.sumWeight += _studentEnor.current().sumWeight;
       _studentEnor.next();
    }
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
