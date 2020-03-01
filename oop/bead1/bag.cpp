#include "bag.h"
#include <string>
bool Bag::IsEmpty() const
{
	return content.size() == 0;
}

int Bag::BiggestNumber() const
{
	if (IsEmpty())
	{
		//Todo: ErrorHandling
		exit(1);
	}
	else
	{
		return content[biggestNumberIndex].Value;
	}
}

std::string Bag::ToString() const
{
	std::string result = "";
	
	for (int i=0; i<content.size(); i++)
	{
		result =  result + " " + content[i].ToString();
	}
	
	return result;
}

Bag::Bag()
{
	content = std::vector<CountedInteger>{};
	biggestNumberIndex = 0;
}

int Bag::Add(int value)
{
	for (int i=0; i<content.size(); i++)
	{
		if (content[i].Value ==  value)
		{
			content[i].Count++;
			return content[i].Count;
		}
	} 
	content.push_back(CountedInteger(value, 1));
	return 1;
}