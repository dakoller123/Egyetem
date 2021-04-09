#include "adoptionEnor.h"
#include <fstream>
#include <sstream>

void AdoptionEnor::next()
{
    _status = Abnormal;
    if (_stream >> _current.firstName &&
        _stream >> _current.lastName &&
        _stream >> _current.dogType &&
        _stream >> _current.dogName &&
        _stream >> _current.dogAge)
    {
        _status=Normal;
    }
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
