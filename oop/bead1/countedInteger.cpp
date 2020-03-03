#include <string>
#include <string>
#include "countedInteger.h"
CountedInteger::CountedInteger(int value, int count)
{
	Value = value;
	Count = count;
}

std::string CountedInteger::ToString() const
{
	return "(" + std::to_string(Value) + "," + std::to_string(Count) + ")";
}