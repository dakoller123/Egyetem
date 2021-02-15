#include <string>
#include "ordermanager.h"
#include <stdexcept>

void OrderManager::setMostToLast()
{
	mostProfitableFoodTotalProfit = lastAddedFoodTotalProfit;
	mostProfitableFoodName = lastAddedFoodName;
}

void OrderManager::setLast(Order order)
{
	lastAddedFoodName = order.FoodName;
	lastAddedFoodTotalProfit = order.TotalPrice();
}

OrderManager::OrderManager()
{
	isEmpty = true;
}

void OrderManager::AddOrder(Order order)
{
	if (isEmpty)
	{
		isEmpty = false;		
		setLast(order);
		setMostToLast();
	}
	else
	{
		if (order.FoodName == lastAddedFoodName)
		{
			lastAddedFoodTotalProfit += order.TotalPrice();
		}
		else
		{
			setLast(order);
		}
		
		if (lastAddedFoodTotalProfit > mostProfitableFoodTotalProfit)
		{
			setMostToLast();				
		}
	}
}

std::string OrderManager::MostProfitableFood() const
{
	if (isEmpty)
	{
		throw std::domain_error("No order has been added, so nothing is profitable");
	}
	else
	{
		return mostProfitableFoodName;
	}
}