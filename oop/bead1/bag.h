//Todo:
//Comments
//separate header from cpp (copy paste)
//documentation
//More tests

#include <vector> 
#include "countedInteger.h"
#include <string>

class Bag
{
	private:
		std::vector<CountedInteger> content;
		int biggestNumberIndex;
		
	public:
		bool IsEmpty() const;
		
		int BiggestNumber() const;
		
		std::string ToString() const;		
		
		Bag();
		
		int Add(int value);
		
		int GetCount(int value)
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
		
		int Remove(int value)
		{
			for (int i=0; i<content.size(); i++)
			{
				if (content[i].Value == value)
				{
					if (content[i].Count == 0)
					{
						content.erase(content.begin()+i);
						return 0;
					}
					content[i].Count--;
					return content[i].Count;
				}
			}
			return 0;		
		}
};