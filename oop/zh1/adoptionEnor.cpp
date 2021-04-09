#include "adoptionEnor.h"
#include <sstream>
#include <iostream>
void AdoptionEnor::next()
{
    _status = Abnormal;

    try
    {
        _stream >> _current.firstName;
        _stream >> _current.lastName;
        _stream >> _current.dogType;
        _stream >> _current.dogName;
        _stream >> _current.dogAge;
        _status=Normal;
    }
    catch(std::exception ex){}

}

struct adoption AdoptionEnor::current() const
{
    return _current;
}

void AdoptionEnor::first()
{
    //ez csak az�rt van itt mert m�r azzal is pr�b�lkoztam hogy az eredeti sor stringj�t adom �t �s �jra kiszedem a d�tumot...
//    std::string tmpDate;
//    _stream >> tmpDate;
    next();
}

bool AdoptionEnor::end() const
{
    return _status != Normal;
}
