#pragma once
#include <string>

class Order
{
	private:

	public:
		std::string FoodName;
		int TableId;
		std::string TimeOfOrder;
		int Count;
		int UnitPrice;
		Order(std::string foodName, int tableId, std::string timeOfOrder, int count, int unitPrice);
};