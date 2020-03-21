#pragma once
#include <string>

class CountedInteger
{
	public:
		int Value;
		int Count;
		CountedInteger(int value, int count);
		
		/// <summary>
		/// Represents the class instance as a string
		/// </summary>
		/// <returns>String representation of the integer</returns>	
		std::string ToString() const;
};