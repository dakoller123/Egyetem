#include <string>

class CountedInteger
{
	public:
		int Value;
		int Count;
		CountedInteger(int value, int count)
		{
			Value = value;
			Count = count;
		}
		std::string ToString() const
		{
			return "(" + std::to_string(Value) + "," + std::to_string(Count) + ")";
		}
};