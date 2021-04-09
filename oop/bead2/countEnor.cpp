#include "countEnor.h"
#include "numberEnor.h"

void CountEnor::next()
{
   _current.Count = 0;
   _current.Value = _numberEnor.current();
   while ((!_numberEnor.end()) && (_current.Value == _numberEnor.current()))
   {
       _current.Count++;
       _numberEnor.next();
   }
}

ValueCountPair CountEnor::current() const
{
      return _current;
}

void CountEnor::first()
{
    _numberEnor.first();
    if (!_numberEnor.end())
    {
       next();
    }
}

bool CountEnor::end() const
{
    return _numberEnor.end();
}
