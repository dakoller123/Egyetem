#include <string>
#include "integerBag.h"
#include <stdexcept>
bool IntegerBag::IsEmpty() const
{
	return content.size() == 0;
}

int IntegerBag::BiggestNumber() const
{
	if (IsEmpty())
	{
		throw std::invalid_argument("Bag is empty, there is no max");
	}
	else
	{
		return content[biggestNumberIndex].Value;
	}
}

std::string IntegerBag::ToString() const
{
	std::string result = "";
	
	for (int i=0; i<content.size(); i++)
	{
		result =  result + " " + content[i].ToString();
	}
	
	return "{" + result + " }";
}

IntegerBag::IntegerBag()
{
	content = std::vector<CountedInteger>{};
	biggestNumberIndex = 0;
}

int IntegerBag::Add(int value)
{
	for (int i=0; i<content.size(); i++)
	{
		if (content[i].Value ==  value)
		{
			content[i].Count++;
			return content[i].Count;
		}
	}

	if (IsEmpty())
	{
		biggestNumberIndex = 0;
	}
	else
	{
		if (content[biggestNumberIndex].Value < value)
		{
			biggestNumberIndex = content.size();
		}
	}
	
	content.push_back(CountedInteger(value, 1));
	return 1;
}

int IntegerBag::GetCount(int value) const
{
	for (int i=0; i<content.size(); i++)
	{
		if (content[i].Value == value)
		{
			return content[i].Count;
		}
	}
	return 0;
}

int IntegerBag::Remove(int value)
{
	//linserch for the value
	for (int i=0; i<content.size(); i++)
	{
		if (content[i].Value == value)
		{
			if (content[i].Count == 1)
			{
				//only one left; remove
				content.erase(content.begin()+i);
				if (biggestNumberIndex == i && !IsEmpty())
				{
					biggestNumberIndex = 0;
					//recalc biggestNumberIndex with maxSearch
					for (int j=1; j<content.size(); j++)
					{
						if (content[biggestNumberIndex].Value < content[j].Value)
						{
							biggestNumberIndex = j;
						}
					}
				}
				return 0;
			}
			content[i].Count--;
			return content[i].Count;
		}
	}
	
	//value not found
	return 0;		
}