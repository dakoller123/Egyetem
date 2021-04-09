#include "baseEnor.h"
#include "secondEnor.h"

void SecondEnor::next()
{
    _baseEnor.next();
   _current = _baseEnor.current().randomAttribute;
}

int SecondEnor::current() const
{
    return _current;
}

void SecondEnor::first()
{
    next();
}

bool SecondEnor::end() const
{
    return _status != Normal;
}
