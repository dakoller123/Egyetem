#include "order.h"

Order::Order(std::string foodName, int tableId, std::string timeOfOrder, int count, int unitPrice)
{
	FoodName = foodName;
	TableId = tableId;
	TimeOfOrder = timeOfOrder;
	Count = count;
	UnitPrice = unitPrice;
}

Order::Order(std::string foodName, int count, int unitPrice)
{
	FoodName = foodName;
	Count = count;
	UnitPrice = unitPrice;
}

Order::TotalPrice() const
{
	return Count * UnitPrice;
}