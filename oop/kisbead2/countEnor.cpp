#include "countEnor.h"
#include "numberEnor.h"

//CountEnor::CountEnor(const std::string& str)
//{
//   _numberEnor = NumberEnor(str);
//}


void CountEnor::next()
{
   _currentCount = 0;
   _currentValue = _numberEnor.current();
   while ((!_numberEnor.end()) && (_currentValue == _numberEnor.current()))
   {
       _numberEnor.next();
       _currentCount += _currentValue;
   }
}

int CountEnor::current() const
{
    return _currentCount;
}

void CountEnor::first()
{
    next();
}

bool CountEnor::end() const
{
    return _numberEnor.end();
}
