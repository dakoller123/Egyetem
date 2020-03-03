#pragma once
#include <string>

class CountedInteger
{
	public:
		int Value;
		int Count;
		CountedInteger(int value, int count);
		std::string ToString() const;
};