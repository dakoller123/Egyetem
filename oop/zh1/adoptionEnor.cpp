#include "adoptionEnor.h"
#include <sstream>
#include <iostream>
void AdoptionEnor::next()
{
    _status = Abnormal;

    _stream >> _current.firstName;
    _stream >> _current.lastName;
    _stream >> _current.dogType;
    _stream >> _current.dogName;
    _stream >> _current.dogAge;

    _status= _stream.fail() ? Abnormal : Normal;

}

struct adoption AdoptionEnor::current() const
{
    return _current;
}

void AdoptionEnor::first()
{
    std::string tmpDate;
    _stream >> tmpDate;
    next();
}

bool AdoptionEnor::end() const
{
    return _status != Normal;
}
