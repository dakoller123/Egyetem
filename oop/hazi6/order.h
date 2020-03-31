#pragma once
#include <string>

class Order
{
	private:

	public:
		std::string FoodName;
		
		int Count;
		int UnitPrice;
		int TotalPrice() const;
		Order(std::string foodName, int count, int unitPrice);
		
		//Unused stuff
		Order(std::string foodName, int tableId, std::string timeOfOrder, int count, int unitPrice);
		int TableId;
		std::string TimeOfOrder;
		
};