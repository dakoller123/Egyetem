#include <string>
#include "ordermanager.h"
#include <stdexcept>

void OrderManager::switchMostToCurrent()
{
	mostProfitableFoodTotalProfit = lastAddedFoodTotalProfit;
	mostProfitableFoodName = lastAddedFoodName;
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
		
		lastAddedFoodName = order.FoodName;
		lastAddedFoodTotalProfit = order.TotalPrice();
		
		switchMostToCurrent();
	}
	else
	{
		if (order.FoodName == lastAddedFoodName)
		{
			lastAddedFoodTotalProfit += order.TotalPrice();
		}
		else
		{
			lastAddedFoodName = order.FoodName;
			lastAddedFoodTotalProfit = order.TotalPrice();			
		}
		
		if (lastAddedFoodTotalProfit > mostProfitableFoodTotalProfit)
		{
			switchMostToCurrent();				
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