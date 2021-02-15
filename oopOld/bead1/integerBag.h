#pragma once

#include <vector> 
#include <string>
#include "countedInteger.h"
/// <summary>
/// A container where one can insert integers multiple times and one can retrieve the highest of those.
/// </summary>
class IntegerBag
{
	private:
		std::vector<CountedInteger> content;
		int biggestNumberIndex;
		
	public:
		/// <summary>
		/// Checks whether bag is empty or not
		/// </summary>
		/// <returns>True if the bag contains no elements. False otherwise</returns>
		bool IsEmpty() const;	
		
		/// <summary>
		/// Returns the highest number the bag contains
		/// </summary>
		/// <remarks>
		/// Throws error when the function is invoked on an empty bag.
		/// </remarks>
		/// <returns>The highest value</returns>		
		int BiggestNumber() const;
		
		/// <summary>
		/// Represents the bag's content as a string.
		/// </summary>
		/// <returns>String representation of the bag</returns>	
		std::string ToString() const;
	
		/// <summary>
		/// Standard Ctor
		/// </summary>
		/// <returns>An empty bag</returns>		
		IntegerBag();
		
		/// <summary>
		/// Adds an integer to the bag
		/// </summary>
		/// <param name="value">The integer to be added to the bag</param>
		/// <returns>The number of times the bag contains the integer</returns>		
		int Add(int value);
		
		/// <summary>
		/// Gets the number of times an integer is part of the bag
		/// </summary>
		/// <param name="value">The integer to be checked</param>
		/// <returns>The number of times the bag contains the integer. 0 if the bag does not contain it at all</returns>			
		int GetCount(int value) const;
		
		/// <summary>
		/// Removes an integer from the bag once.
		/// </summary>
		/// <remarks>
		/// If the integer is part of the bag more than once, it will still be, just -1 times.
		/// </remarks>
		/// <param name="value">The integer to be removed</param>
		/// <returns>The number of times the bag contains the integer. 0 if the bag didn't contain the integer before or after the method invocation</returns>			
		int Remove(int value);
};